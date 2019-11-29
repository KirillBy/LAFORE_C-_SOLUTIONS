#include <iostream>

///////////////////////////////////////////////////////////
class Distance                //Класс английских расстояний
{
private:
    int feet;
    double inches;
public:
    Distance()                //конструктор без аргументов
    {
        feet = 0; inches = 0.0;
    }
    Distance(double fltfeet) //конструктор (1 арг.)
    {    //Переводит double в Distance
        feet = int(fltfeet);    //feet – целая часть
        inches = 12 * (fltfeet - feet); //слева - дюймы
    }
    Distance(int ft, double in)    //конструктор (2 арг.)
    {
        feet = ft; inches = in;
    }
    void showdist()              //Вывести длину
    {
        std::cout << feet << "\'-" << inches << '\"';
    }
    friend Distance operator + (Distance, Distance); //дружественный
    friend Distance operator * (Distance, Distance); //дружественый
};
//---------------------------------------------------------
Distance operator * (Distance d1, Distance d2) // d1 * d2
{
    int f = d1.feet * d2.feet;       //* футы
    double i = static_cast<int>(d1.inches * d2.inches)*10; //* дюймы
    if (i >= 12.0)                    //если больше 12 дюймов,
    {
        i -= 12.0; f++;//уменьшить на 12 дюймов, //прибавить 1 фут
    }

    return Distance(f, i);
}
Distance operator + (Distance d1, Distance d2) // d1 + d2
{
    int f = d1.feet + d2.feet;       //+ футы
    double i =d1.inches + d2.inches; //+ дюймы
    if (i >= 12.0)                    //если больше 12 дюймов,
    {
        i -= 12.0; f++;//уменьшить на 12 дюймов,
                   //прибавить 1 фут
    }
    return Distance(f, i);            //Новая длина с суммой
}
//---------------------------------------------------------
int main()
{
    Distance d1 = 2.5;         //конструктор переводит
    Distance d2 = 1.25;        //double-feet в Distance
    Distance d3;
    std::cout << "\nd1 = "; d1.showdist();
    std::cout << "\nd2 = "; d2.showdist();

    d3 = d1 + 10.0;            //distance + double: OK
    std::cout << "\nd3 = "; d3.showdist();
    d3 = 10.0 + d1;            //double + Distance: OK
    std::cout << "\nd3 = "; d3.showdist();
    std::cout << std::endl;
    Distance d4 = 1.5;
    Distance d5 = 2.5;
    std::cout << "\nd4 = "; d4.showdist();
    std::cout << "\nd5 = "; d5.showdist();
    Distance d6 = 10.1 * d1;      // double * Distance
    std::cout << "\nd6 = "; d6.showdist();
    d6 = d2 * 10.2;         //Distance * double
    std::cout << "\nd6 = "; d6.showdist();

    return 0;
}
