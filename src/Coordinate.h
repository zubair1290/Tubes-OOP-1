#ifndef __COORDINATE_H__
#define __COORDINATE_H__


class Coordinate {
public:
    int x;
    int y;

    Coordinate();
    Coordinate(int x, int y);

    bool operator== (const Coordinate &coordinate) const;
    Coordinate operator+ (const Coordinate &coordinate) const;
    Coordinate& operator= (const Coordinate &coordinate);

    static Coordinate make(int x, int y);
};

#endif