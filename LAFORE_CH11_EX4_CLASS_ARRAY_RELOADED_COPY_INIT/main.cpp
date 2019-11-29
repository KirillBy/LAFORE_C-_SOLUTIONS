#include <iostream>

///////////////////////////////////////////////////////////
class Array                  //моделирует обычный массив C++
{
private:
    int* ptr;                //указатель на содержимое Array
    int size;                //размер Array
public:
    Array(int s)             //конструктор с одним аргументом
    {
        size = s;              //аргумент – размер Array
        ptr = new int[s];      //выделить память под Array
    }
    Array(const Array &ar);
    ~Array()                 //деструктор
    {
        delete[] ptr;
    }
    int& operator [] (int j) //перегружаемая операция
                             //списка индексов
    {
        return *(ptr + j);
    }
    void operator = (const Array &ar);
};
///////////////////////////////////////////////////////////
int main()
{
    const int ASIZE = 10;      //размер массива
    Array arr(ASIZE);          //создать массив

    for (int j = 0; j < ASIZE; j++) //заполнить его j^2
        arr[j] = j * j;
    Array arr1(arr);


    for (int j = 0; j < ASIZE; j++)     //вывести его содержимое
        std::cout << arr1[j] << ' ';
    std::cout << std::endl;

    return 0;
}

Array::Array(const Array &ar)// iniciallization construction
{
    this-> size = ar.size;
     ptr = new int [size];
     for(int i = 0; i< size; i++)
     {
         this->ptr[i] = ar.ptr[i];
     }
}

void Array::operator =(const Array &ar) //constructor copy
{
if(size>ar.size)
{
    ptr = new int [ar.size];

}
    ptr = new int [size];
    if(size>ar.size)
    {
        for(int i = 0; i< ar.size; i++)
        {
            this->ptr[i] = ar.ptr[i];
        }
    }
    for(int i = 0; i< size; i++)
    {
        this->ptr[i] = ar.ptr[i];
    }
}
