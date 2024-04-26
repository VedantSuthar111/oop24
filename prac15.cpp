#include <iostream>
#include <string>
#include<iomanip>
using namespace std;
class product
{
protected:
    int id;
    string name;
    string manufacturer;
    float price;

public:
    product(int id, string name, string manufacturer, float price)
    {
        this-> id = id;
        this-> name = name;
        this-> manufacturer = manufacturer;
        this-> price = price;
    }
    virtual void putdata() = 0;
};
class Smartwatch : public product
{
protected:
    float dial_size;

public:
    Smartwatch(int id, string name, string manufacturer, float price, float dial_size) : product(id, name, manufacturer, price)
    {
       this-> dial_size = dial_size;
    }
    void putdata()
    {
        cout << "ID " << ": " << id << endl;
        cout << "NAME " << ": " << name << endl;
        cout << "MANUFACTURER " << ": " << manufacturer << endl;
        cout << "PRICE " << ": " << price << endl;
        cout << "DIAL SIZE " << ": " << dial_size << endl;
    }
};
class Bedsheet : public product
{
protected:
    float width, height;

public:
    Bedsheet(int id, string name, string manufacturer, float price, float width, float height) : product(id, name,manufacturer, price)
    {
        this-> width = width;
        this-> height = height;
    }
    void putdata()
    {
        cout << "ID " << ": " << id << endl;
        cout << "NAME " << ": " << name << endl;
        cout << "MANUFACTURER " << ": " << manufacturer << endl;
        cout << "PRICE " << ": " << price << endl;
        cout << "WIDTH " << ": " << width << endl;
        cout << "HEIGHT " << ": " << height << endl;
    }
};
int main()
{
    int n;
    long int id;
    string name;
    string manufacturer;
    float price;
    float dial_size;
    float width, height;
    cout << "enter 1 for Smartwatch menu" << endl;
    cout << "enter 2 for Bedsheet menu" << endl;
    cin >> n;
    switch (n)
    {
    case 1:
    cout<<"------Enter Smartwatch data------";
        cout << "enter product id : ";
        cin >> id;
        cout << "enter product name : ";

        getline(cin, name);
        cout << "enter product manufacturer : ";

        getline(cin, manufacturer);
        cout << "enter product price : ";
        cin >> price;
        cout << "enter product dail size : ";
        cin >> dial_size;
        Smartwatch *p;
        p = new Smartwatch(id, name, manufacturer, price, dial_size);
        p->putdata();
        break;
    case 2:
    cout<<"------Enter Bedsheet data------";
        cout << "enter product id : ";
        cin >> id;
        cout << "enter product name : ";

        getline(cin, name);
        cout << "enter product manufacturer : ";

        getline(cin, manufacturer);
        cout << "enter product price : ";
        cin >> price;
        cout << "enter product width : ";
        cin >> width;
        cout << "enter product height : ";
        cin >> height;
        Bedsheet *b;
        b = new Bedsheet(id, name, manufacturer, price, width, height);
        b->putdata();
        break;
    }

    return 0;
}
