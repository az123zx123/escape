#ifndef POINT_H
#define POINT_H
#include "edge.h"
#include "deque"
#include <algorithm>
#include "piece.h"

using namespace std;

class point
{
    int x;
    int y;
    int index;
    int edge_number;
    deque<edge> connected;  //connected points represented by edge
public:
    piece* piece;
    point() = default;
    point(int x, int y, int index);
    void addEdge(edge);
    int get_x() const;
    int get_y() const;
    int get_index() const;
    int get_edge_number() const;
    deque<edge>::iterator start();
    deque<edge>::iterator end();
    int priority;

    friend bool operator <(point node1,point node2)
    {
        return node1.priority>node2.priority;
    }
    friend bool operator == (const point &lhs, const point &rhs)
        {
            if (lhs.index == rhs.index) return true;
            return false;
        }

};

#endif // POINT_H
