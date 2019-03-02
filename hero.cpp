#include "hero.h"
#include <QTimer>
#include <iostream>

hero::hero(int x, int y, terrain* (*pieceBoard)[8][8], character* (*locationBoard)[8][8]):character(x,y,"hero"){
    this->pieceBoard=pieceBoard;
    this->locationBoard=locationBoard;
}

void hero::potentialMove(bool potentialMove[8][8]){
    int target_x=get_x()+1;
    int target_y=get_y();
    if(target_x<8&&target_y<8&&target_x>=0&&target_y>=0){
        potentialMove[target_x][target_y]=true;
    }
    target_x=get_x()-1;
    if(target_x<8&&target_y<8&&target_x>=0&&target_y>=0){
        potentialMove[target_x][target_y]=true;
    }
    target_x=get_x();
    target_y=get_y()-1;
    if(target_x<8&&target_y<8&&target_x>=0&&target_y>=0){
        potentialMove[target_x][target_y]=true;
    }
    target_y=get_y()+1;
    if(target_x<8&&target_y<8&&target_x>=0&&target_y>=0){
        potentialMove[target_x][target_y]=true;
    }
}

piece* hero::move(int x, int y){
    bool check[8][8];
    for(int i=0;i<64;++i){
        check[i/8][i%8]=false;
    }
    potentialMove(check);
    if(check[x][y]){
        if((*locationBoard)[x][y]!=nullptr&&(*locationBoard)[x][y]->getImage()=="monster")
            return nullptr;
        (*locationBoard)[get_x()][get_y()]=nullptr;
        set_x(x);
        set_y(y);
        time=time+(*pieceBoard)[x][y]->get_cost();
        return (*locationBoard)[x][y];
    }
    return nullptr;
}


int hero::get_time(){
    return time;
}

std::string hero::getImage() const{
    return "hero";
}
