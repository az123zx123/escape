#include "monster.h"
#include "iostream"

monster::monster(int x, int y, terrain* (*pieceBoard)[8][8], character* (*locationBoard)[8][8]):character(x,y,"monster"){
    this->pieceBoard=pieceBoard;
    this->locationBoard=locationBoard;
}

void monster::potentialMove(bool potentialMove[8][8]){
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

bool monster::move(int x, int y){
    if(x<0||y<0||x>7||y>7)
        return false;
    bool check[8][8];
    for(int i=0;i<64;++i){
        check[i/8][i%8]=false;
    }
//    potentialMove(check);
//    if(check[x][y]){
        if((*locationBoard)[x][y]!=nullptr&&(*locationBoard)[x][y]->getImage()=="treasure")
            return false;
        if((*locationBoard)[x][y]!=nullptr&&(*locationBoard)[x][y]->getImage()=="hero")
            return false;
        if((*locationBoard)[x][y]!=nullptr&&(*locationBoard)[x][y]->getImage()=="monster")
            return false;
        (*locationBoard)[get_x()][get_y()]=nullptr;
        set_x(x);
        set_y(y);
        (*locationBoard)[x][y] = this;
        return true;
//    }
//    return false;
}

void monster::start_move(){

}

std::string monster::getImage() const{
    return "monster";
}
