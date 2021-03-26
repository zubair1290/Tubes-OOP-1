#ifndef __COORDINATE_H__
#define __COORDINATE_H__


class Coordinate {
private:
    int x;
    int y;

public:
    Coordinate();
    Coordinate(int x, int y);

    bool operator== (const Coordinate &coordinate) const;
    Coordinate operator+ (const Coordinate &coordinate) const;
    Coordinate operator- (const Coordinate &coordinate) const;
    void operator+= (const Coordinate &coordinate);
    void operator-= (const Coordinate &coordinate);
    Coordinate& operator= (const Coordinate &coordinate);

    static Coordinate make(int x, int y);

    int getX() const;
    int getY() const;
};

#endif