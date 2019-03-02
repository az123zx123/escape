#include "a_star.h"
#include <iostream>

using namespace std;

using namespace std;

A_star::A_star(graph map):map(map)
{

}

int A_star::heuristic(point start, point end){
    int x_difference = (start.get_x()-end.get_x()>0)?(start.get_x()-end.get_x()):(end.get_x()-start.get_x());
    int y_difference = (start.get_y()-end.get_y()>0)?(start.get_y()-end.get_y()):(end.get_y()-start.get_y());
    return x_difference+y_difference;
}

int A_star::distance(point start, point end){
    priority_queue<point, vector<point>> openSet;     //The set of currently discovered nodes that are not evaluated yet
    deque<point> openSet_for_interator;
    deque<point> closeSet;    //The set of nodes already evaluated
    deque<int>  comeFrom;   // contain the most efficient path, store the previous point index
    openSet.push(start);
    deque<int> path = deque<int>(map.get_vertices());  //distance list
    for(int i=0;i<path.size();i++){
        path[i]=9999;
        comeFrom[i]=-1;
    }
    path[start.get_index()] = 0;
    while(!openSet.empty()){
        point current = openSet.top();
        if(current.get_index()==end.get_index())
            break;
        closeSet.push_back(current);
        openSet.pop();
    for(deque<edge>::iterator find_p = current.start();find_p!=current.end();++find_p){
        edge e = *find_p;
        deque<point>::iterator position = find(closeSet.begin(),closeSet.end(),map.get_point(e.to()));
        if(position!=closeSet.end())
        continue;   //Ignore the neighbor which is already evaluated.
    int tentative_distance = path[e.from()]+e.getWeight();   // The distance from start to a neighbor
    if(find(openSet_for_interator.begin(),openSet_for_interator.end(),map.get_point(e.to()))!=openSet_for_interator.end()){
        openSet_for_interator.push_back(map.get_point(e.to())); // Discover a new node
    }
    else if(tentative_distance>=path[e.to()])
        continue;// This is not a better path.
                // This path is the best until now. Record it!
        comeFrom[e.to()]=e.from();
        path[e.to()]=tentative_distance;
        int priority = path[e.to()]+heuristic(map.get_point(e.to()),end);
        map.get_point(e.to()).priority = priority;
        openSet.push(map.get_point(e.to()));
    }
    }
    return path[end.get_index()];
}

deque<int> A_star::lane(point start, point end){
    priority_queue<point, vector<point>> openSet;     //The set of currently discovered nodes that are not evaluated yet
    deque<point> openSet_for_interator;
    deque<point> closeSet;    //The set of nodes already evaluated
    deque<int>  comeFrom = deque<int>(map.get_vertices());   // contain the most efficient path, store the previous point index
    openSet.push(start);
    deque<int> path = deque<int>(map.get_vertices());  //distance list
    for(int i=0;i<path.size();i++){
        path[i]=9999;
        comeFrom[i]=-1;
    }
    path[start.get_index()] = 0;
    while(!openSet.empty()){
        point current = openSet.top();
        if(current.get_index()==end.get_index())
            break;
        closeSet.push_back(current);
        openSet.pop();
    for(deque<edge>::iterator find_p = current.start();find_p!=current.end();++find_p){
        edge e = *find_p;
        deque<point>::iterator position = find(closeSet.begin(),closeSet.end(),map.get_point(e.to()));
        if(position!=closeSet.end())
        continue;   //Ignore the neighbor which is already evaluated.
    int tentative_distance = path[e.from()]+e.getWeight();   // The distance from start to a neighbor
    if(find(openSet_for_interator.begin(),openSet_for_interator.end(),map.get_point(e.to()))!=openSet_for_interator.end()){
        openSet_for_interator.push_back(map.get_point(e.to())); // Discover a new node
    }
    else if(tentative_distance>=path[e.to()])
        continue;// This is not a better path.
                // This path is the best until now. Record it!
        comeFrom[e.to()]=e.from();
        path[e.to()]=tentative_distance;
        int priority = path[e.to()]+heuristic(map.get_point(e.to()),end);
        map.get_point(e.to()).priority = priority;
        openSet.push(map.get_point(e.to()));
    }
    }
    deque<int> way;
    way.push_front(end.get_index());
    int previous = comeFrom[end.get_index()];
    while(previous!=-1){
        way.push_front(previous);
        previous = comeFrom[previous];
    }
    return way;
}
