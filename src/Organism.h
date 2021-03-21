#ifndef __ORGANISM_H__
#define __ORGANISM_H__


class Organism {
protected:
    int x;
    int y;
public:
    Organism();
    ~Organism();
    
    int getX();
    int getY();

    void MoveUp();
    void MoveDown();
    void MoveLeft();
    void MoveRight();
};

#endif