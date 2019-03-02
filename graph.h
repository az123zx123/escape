#ifndef GRAPH_H
#define GRAPH_H
#include "point.h"
#include "edge.h"
#include <algorithm>
#include "deque"

using namespace::std;

class graph
{
    int V; //number of vertices
    int E; //number of edges
    deque<point> adj;
public:
    graph(int v);
    graph(int width, int height);
    int get_vertices() const;
    int get_edges_number() const;
    point& get_point(int index);
    point& get_point(int x, int y);
    void add_point(int x, int y);
    void add_edge(edge e);
    void add_edge(int from_index, int to_index, int weight);
    void add_edge(point from, point to, int weight);
    deque<point>::iterator start();
    deque<point>::iterator end();
};

#endif // GRAPH_H
