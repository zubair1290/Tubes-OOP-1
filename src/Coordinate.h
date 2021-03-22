#ifndef __COORDINATE_H__
#define __COORDINATE_H__


class Coordinate {
public:
    int x;
    int y;
    // int getX() const;
    // int getY() const;

    Coordinate();
    Coordinate(int x, int y);

    bool operator== (const Coordinate &coordinate) const;
};

#endif