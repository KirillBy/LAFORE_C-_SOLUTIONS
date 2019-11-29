#include <iostream>
#include <string>
using namespace std;
class publication
{
protected:
    string name;
    float price;
public:
    publication() : name("0"), price(0) {}

    void getdata()
    {

        cout << "Enter name of the book: ";
        getline(cin, name);
        cout << "Enter price of the book, $: "; cin >> price;


    }
    void showdata() const
    {
        cout << "Book " << "\"" << name << "\"" << " cost " << price << " $. ";
    }
};
class book : public publication
{
private:
    int page;
public:
    book() : publication(), page(0) {}
    void getdata()
    {
        publication::getdata();
        cout << "Enter a number of pages: "; cin >> page;
        cin.ignore();
    }
    void showdata() const
    {
        publication::showdata();
        cout << "It has " << page << " pages." << endl;
    }
};
class type : public publication
{
private:
    float minutes;
public:
    type() : publication(), minutes(0.0) {}
    void getdata()
    {
        publication::getdata();
        cout << "Enter the lenth of audiobook(min): "; cin >> minutes;
        cin.ignore();
    }
    void showdata() const
    {

        publication::showdata();
        cout << "It's " << minutes << " minutes." << endl;
    }
};
int main()
{
    publication* maspubl[100];
    char choice;
    int n = 0;
    do
    {
        cout << "Book or type ? (b/t): ";
        cin >> choice;
        cin.ignore();
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
            cout << "Incorrect choice!!!"; cin >> choice; exit(1);

        }
        cout << "One more choice? (y/n)"; cin >> choice;
        n++;
    } while (choice != 'n');

    for (int i = 0; i < n; i++)
    {
        maspubl[i]->showdata();
        cout << endl << "**************************" << endl;
    }

    return 0;
}
