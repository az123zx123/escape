#include "point.h"
#include <iostream>
using namespace std;

point::point(int x, int y, int index):x(x), y(y),index(index), edge_number(0),priority(0),piece(nullptr)
{

}

void point::addEdge(edge e){
    connected.push_back(e);
    ++edge_number;
}

int point::get_x() const{
    return x;
}

int point::get_y() const{
    return y;
}

int point::get_index() const{
    return index;
}

int point::get_edge_number() const{
    return edge_number;
}

deque<edge>::iterator point::start(){
    return connected.begin();
}

deque<edge>::iterator point::end(){
    return connected.end();
}

