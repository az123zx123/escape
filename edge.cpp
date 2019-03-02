#include "edge.h"

edge::edge(int v, int w, int weight):v(v), w(w), weight(weight)
{

}

int edge::getWeight() const{
    return weight;
}

int edge::from() const{
    return v;
}

int edge::to() const{
    return w;
}
