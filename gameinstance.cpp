#include <iostream>
#include "gameinstance.h"

gameinstance::gameinstance():game_window(new GameWindow(nullptr, this)),map(new graph(8, 8))
{
    cout<<"loading"<<endl;
    for(int i=0;i<64;++i){
        pieceBoard[i/8][i%8] = nullptr;
        locationBoard[i/8][i%8] = nullptr;
    }
    musicList = new QMediaPlaylist();
    musicList->addMedia(QUrl("qrc:/music/during.mp3"));
    musicList->setPlaybackMode(QMediaPlaylist::Loop);
    player = new QMediaPlayer();
    player->setPlaylist(musicList);
    player->setVolume(30);
    player->play();
    pieceBoard[0][0] = new start(0, 0);
    pieceBoard[7][7] = new end_point(7,7);
    srand(static_cast<unsigned int>((time(nullptr))));
    cout<<"generating world"<<endl;
    for(int i=1;i<63;++i){
        int r = rand()%4;
        switch(r){
        case 0:pieceBoard[i/8][i%8] = new grass(i/8,i%8);break;
        case 1:pieceBoard[i/8][i%8] = new forest(i/8,i%8);break;
        case 2:pieceBoard[i/8][i%8] = new moor(i/8,i%8);break;
        case 3:pieceBoard[i/8][i%8] = new mountain(i/8,i%8);break;
        default:pieceBoard[i/8][i%8] = new grass(i/8,i%8);
        }
    }
    hero_p = new hero(0, 0, &pieceBoard, &locationBoard);
    locationBoard[0][0] = hero_p;
    monster_p = new monster(7, 0, &pieceBoard, &locationBoard);
    additional_monster = new monster(0,7,&pieceBoard, &locationBoard);
    locationBoard[7][0] = monster_p;
    locationBoard[0][7] = additional_monster;
    cout<<"generating characters"<<endl;
    cout<<"welcome hero"<<endl;
    random_map();
predict = new A_star(*map);
predict_way(least_time_way);
for(int i=0;i<2;){
    srand(static_cast<unsigned int>((time(nullptr))));
    int x = rand()%3+1+3*i;
        for(int y=0;y<8;++y){
    if(locationBoard[x][y]!=nullptr||!least_time_way[x][y])
        continue;
    locationBoard[x][y] = new treasure(x,y,10,&pieceBoard,&locationBoard);
    break;
        }
    ++i;
}
for(int i=0;i<64;++i){
    reset_icon(i%8,i/8);
}
emit game_start();
routine_timer = new QTimer(this);
for(int i=0;i<64;++i){
    connect(game_window->get_square(i/8,i%8), SIGNAL(clicked_with_pos(int, int)), this, SLOT(processUserInput(int, int)));
}
connect(routine_timer,SIGNAL(timeout()),this,SLOT(main_thread()));
connect(game_window,SIGNAL(closed()),this,SLOT(game_close()));
routine_timer->start(200);
minimum_cost = predict->distance(map->get_point(0,0),map->get_point(7,7));
cout<<"enjoy your journey"<<endl;
}

gameinstance::~gameinstance(){
    player->stop();
    for(int i=0;i<64;++i){
        if(pieceBoard[i/8][i%8]!=nullptr)delete pieceBoard[i/8][i%8];
        if(locationBoard[i/8][i%8]!=nullptr)delete locationBoard[i/8][i%8];
        pieceBoard[i/8][i%8] = nullptr;
        locationBoard[i/8][i%8] = nullptr;
    }
    delete game_window;
    delete map;
}

void gameinstance::random_map(){
    for(int i=0;i<64;++i){
        map->add_point(i/8,i%8);
        (pieceBoard)[i/8][i%8]->set_index(i);
    }
    for(int i=0;i<64;++i){
        if(i%8!=0)
        map->add_edge(i,i-1,pieceBoard[i/8][i%8-1]->get_cost());
        if(i%8!=7)
        map->add_edge(i,i+1,pieceBoard[i/8][i%8+1]->get_cost());
        if(i/8!=0)
        map->add_edge(i,i-8,pieceBoard[i/8-1][i%8]->get_cost());
        if(i/8!=7)
        map->add_edge(i,i+8,pieceBoard[i/8+1][i%8]->get_cost());
    }
}

void gameinstance::predict_way(bool least_time_way[8][8]){
// predict least_time_way
    for(int i=0;i<64;++i)
        least_time_way[i/8][i%8]=false;
    deque<int> least_time_lane = predict->lane(map->get_point(0,0),map->get_point(7,7));
    while(!least_time_lane.empty()){
        int temporary_index = least_time_lane.front();
        least_time_way[temporary_index/8][temporary_index%8] = true;
        least_time_lane.pop_front();
    }
}

void gameinstance::show_least_time_way(){
    for(int i=0;i<64;++i){
        if(least_time_way[i/8][i%8]){
            game_window->set_highlighted(i/8,i%8,true,"red");
        }
    }
}

void gameinstance::monster_random(monster* monster_p){
    srand(static_cast<unsigned int>(time(nullptr)));
    int predict_number = rand()%10;
    int x{0};
    int y{0};
    if(predict_number<8){
        deque<int> least_time_lane = predict->lane(map->get_point(monster_p->get_x(),monster_p->get_y()),map->get_point(hero_p->get_x(),hero_p->get_y()));
        least_time_lane.pop_front();
        int index = least_time_lane.front();
        point next_point = map->get_point(index);
        x = next_point.get_x();
        y = next_point.get_y();
    }else{
        int random = rand()%4;
        switch (random) {
        case 0:x=monster_p->get_x()+1;
            y=monster_p->get_y();
            break;
        case 1:x=monster_p->get_x()-1;
            y=monster_p->get_y();
            break;
        case 2:x=monster_p->get_x();
            y=monster_p->get_y()+1;
            break;
        case 3:x=monster_p->get_x();
            y=monster_p->get_y()-1;
            break;
        }
    }
    monster_p->move(x,y);

}

void gameinstance::processUserInput(int row, int col){
    selected_x = row;
    selected_y = col;
}

void gameinstance::game_over(){
        routine_timer->stop();
    QMessageBox::information(game_window,tr("game over"),tr("you are captured by the monster"));
    if(QMessageBox::Yes==QMessageBox::question(game_window,"theoretical solution","do you want to see the theoretical optimal way?")){
        QMessageBox::information(game_window,"minimum",QString::number(minimum_cost));
        show_least_time_way();
    }else{
    game_window->close();
}
}

void gameinstance::reset_icon(int x,int y){
    if(pieceBoard[x][y]==nullptr)
        return;
    if(locationBoard[x][y]==nullptr){
    if((pieceBoard)[x][y]==nullptr)
        return;
    std::string path =":/images/"+(pieceBoard)[x][y]->getImage()+".png";
    game_window->set_icon(x,y,path);
    }else{
        if((pieceBoard)[x][y]==nullptr)
            return;
    std::string path =":/images/"+(pieceBoard)[x][y]->getImage()+"_"+(locationBoard)[x][y]->getImage()+".png";
    game_window->set_icon(x,y,path);
    }
}

void gameinstance::startGraphicUI(){
    game_window->show();
}

GameWindow* gameinstance::get_game_window() const{
    return game_window;
}

void gameinstance::routine(){
    time_remain = hero_p->get_time();
        bool potentialMove[8][8];
        for(int i=0;i<64;++i)
            potentialMove[i/8][i%8] = false;
        hero_p->potentialMove(potentialMove);
        if(potentialMove[selected_x][selected_y]){
        piece* capture = hero_p->move(selected_x, selected_y);
        if(capture!=nullptr&&capture->getImage()=="monster"){
            game_over();
            return;
        }
        else if(capture!=nullptr&&capture->getImage()=="treasure"){
            treasure_num+=10;
            delete capture;
    }
        locationBoard[selected_x][selected_y] = hero_p;
        hero_p->set_x(selected_x);
        hero_p->set_y(selected_y);}
    if(++monster_move_counter==8){
        monster_random(monster_p);
        monster_random(additional_monster);
        monster_move_counter = 0;
    }
}

void gameinstance::game_win(){
    routine_timer->stop();
    QMessageBox::information(game_window,("win"),("You really get it!"));
    if(QMessageBox::Yes==QMessageBox::question(game_window,"theoretical solution","do you want to see the theoretical optimal way?")){
        QMessageBox::information(game_window,"minimum",QString::number(minimum_cost));
        show_least_time_way();
    }else{
    game_window->close();
    }
}

void gameinstance::game_close(){
    player->stop();
    routine_timer->stop();
}

void gameinstance::main_thread(){
//check monster game_over
    bool potentialMove[8][8];
    for(int i=0;i<64;++i)
        potentialMove[i/8][i%8] = false;
    hero_p->potentialMove(potentialMove);
    if(hero_p->get_x()==7&&hero_p->get_y()==7){
    game_win();
}else if(monster_move_counter>=5&&(potentialMove[monster_p->get_x()][monster_p->get_y()]||potentialMove[additional_monster->get_x()][additional_monster->get_y()])){
        game_over();
        return;
    }else if(hero_p->get_x()==7&&hero_p->get_y()==7){
        game_win();
    }
    else{
        routine();
        for(int i=0;i<64;++i)
            reset_icon(i%8,i/8);
        game_window->set_lcd(1,time_remain);
        game_window->set_lcd(0,treasure_num);
        routine_timer->start(200);
    }
}
