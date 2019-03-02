#include "graph.h"


graph::graph(int v):V(v),E(0)
{
    adj = deque<point>();
}

graph::graph(int width, int height):V(width*height),E(0){
    adj = deque<point>();
}

int graph::get_edges_number()const{
    return E;
}

int graph::get_vertices() const{
    return V;
}

point& graph::get_point(int index){
    return adj[index];
}

point& graph::get_point(int x, int y){
    for(deque<point>::iterator find_p = adj.begin();find_p!=adj.end();++find_p){
        point p = *find_p;
        if(p.get_x()==x&&p.get_y()==y)
            return *find_p;
    }
}

void graph::add_point(int x, int y){
adj.push_back(point(x,y,adj.size()));
}

void graph::add_edge(edge e){
    int v = e.from();
    adj[v].addEdge(e);
}

void graph::add_edge(int from_index, int to_index, int weight){
    if(adj.size()-1<from_index)
        return;
    edge e = edge(from_index, to_index, weight);
    adj[from_index].addEdge(e);
}

void graph::add_edge(point from, point to, int weight){
    edge e = edge(from.get_index(), to.get_index(),weight);
    adj[from.get_index()].addEdge(e);
}

deque<point>::iterator graph::start(){
    return adj.begin();
}

deque<point>::iterator graph::end(){
    return adj.end();
}
