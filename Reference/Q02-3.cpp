#include <iostream>

using std::cout;
using std::endl;

typedef struct __Point
{
    int xpos;
    int ypos;
} Point;

Point &PntAdder(const Point &p1, const Point &p2);

int main()
{
    Point *p1 = new Point;
    p1->xpos = 1;
    p1->ypos = 2;
    Point *p2 = new Point;
    p2->xpos = -3;
    p2->ypos = -10;

    Point &newp = PntAdder(*p1, *p2);

    cout << "X: " << newp.xpos << endl;
    cout << "Y: " << newp.ypos << endl;

    delete p1;
    delete p2;
    delete &newp;
}

Point &PntAdder(const Point &p1, const Point &p2)
{
    Point *newp = new Point;
    newp->xpos = p1.xpos + p2.xpos;
    newp->ypos = p1.ypos + p2.ypos;

    return *newp;
}