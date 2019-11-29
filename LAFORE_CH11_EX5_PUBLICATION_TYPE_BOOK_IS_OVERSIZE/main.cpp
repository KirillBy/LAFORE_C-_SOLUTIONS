#include <iostream>
#include <string>

class publication
{
protected:
    std::string name;
    float price;
public:
    publication() : name("0"), price(0) {}
   virtual  bool IsOveersize() const = 0;
    virtual ~publication() {}
   virtual void getdata()
    {

        std::cout << "Enter name of the book: ";
        getline(std::cin, name);
        std::cout << "Enter price of the book, $: "; std::cin >> price;


    }
   virtual void showdata() const
    {
        std::cout << "Book " << "\"" << name << "\"" << " cost " << price << " $. ";
    }
};
//////////////////////////////////////////////
class book : public publication
{
private:
    int page;
public:
    book() : publication(), page(0) {}
    bool IsOveersize() const override
    {
        return page > 800 ? true   : false;
    }
    void getdata() override
    {
        publication::getdata();
        std::cout << "Enter a number of pages: "; std::cin >> page;
        std::cin.ignore();
    }
    void showdata() const override
    {
        publication::showdata();
        std::cout << "It has " << page << " pages." << std::endl;
        if(this->IsOveersize())
        std::cout<<"Oversized!!!"<< std::endl;
    }
};
//////////////////////////////////////////////////
class type : public publication
{
private:
    float minutes;
public:
    type() : publication(), minutes(0.0) {}
    bool IsOveersize() const override
    {
        return minutes > 90 ? (true)  : false;
    }
    void getdata() override
    {
        publication::getdata();
        std::cout << "Enter the lenth of audiobook(min): "; std::cin >> minutes;
        std::cin.ignore();
    }
    void showdata() const override
    {

        publication::showdata();
        std::cout << "It's " << minutes << " minutes." << std::endl;
        if(this->IsOveersize())
        std::cout<<"Oversized!!!"<< std::endl;
    }
};
int main()
{
    publication* maspubl[100];
    char choice;
    int n = 0;
    do
    {
        std::cout << "Book or type ? (b/t): ";
        std::cin >> choice;
        std::cin.ignore();
        switch (choice)
        {
        case('b'):
            maspubl[n] = new book;
            maspubl[n]->getdata();

            break;
        case('t'):
            maspubl[n] = new type;
            maspubl[n]->getdata();

            break;
        default:
            std::cout << "Incorrect choice!!!"; std::cin >> choice; exit(1);

        }
        std::cout << "One more choice? (y/n)"; std::cin >> choice;
        n++;
    } while (choice != 'n');

    for (int i = 0; i < n; i++)
    {
        maspubl[i]->showdata();
        std::cout << std::endl << "**************************" << std::endl;
    }

    return 0;
}
