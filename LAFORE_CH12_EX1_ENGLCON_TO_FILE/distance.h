#ifndef DISTANCE_H
#define DISTANCE_H


class Distance
{
private:
    int feet;
    float inches;
public:
    Distance();
    Distance(int ft, float in);
    void getdist();
    void showdist();
    void add_dist(Distance, Distance);

};

#endif // DISTANCE_H
