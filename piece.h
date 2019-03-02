#ifndef PIECE_H
#define PIECE_H

#include "QObject"
#include "string"

class piece: public QObject
{
    int x;
    int y;
    std::string image;
public:
    piece(int x, int y,std::string image=" ");
    int get_x();
    int get_y();
    void set_x(int x);
    void set_y(int y);
    virtual ~piece()=default;
    virtual std::string getImage() const = 0;
};

#endif // PIECE_H
