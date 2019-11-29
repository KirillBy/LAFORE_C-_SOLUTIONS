#include "NOD.h"

int NOD(int x, int y)
{
    if (y == 0) return x;
    return NOD(y, x % y);
}
