#ifndef TIME_H
#define TIME_H


class TIME
{
private:
    unsigned int HOUR;
    unsigned int MINUTE;
    unsigned int SECOND;
public:
    TIME();
    int get_time();
    int put_time();
};

#endif // TIME_H
