#ifndef EDGE_H
#define EDGE_H


class edge
{
    int v;  //edge source
    int w;  //edge target
    int weight;  //edge weight
public:
    edge() = default;
    edge(int v, int w, int weight);
    int getWeight() const;
    int from() const;
    int to() const;
};

#endif // EDGE_H
