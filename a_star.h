#ifndef A_STAR_H
#define A_STAR_H
#include "graph.h"
#include <algorithm>
#include "deque"
#include "queue"
#include <stdlib.h>

class A_star
{
    graph map;
public:
    A_star(graph map);
    int heuristic(point start, point end);//the manhattan distance between two points
    int distance(point start, point end);
    deque<int> lane(point start, point end);
};

#endif // A_STAR_H
