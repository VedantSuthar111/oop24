#include<iostream>

using namespace std;

class Employee
{
    float a;
    int year,months;

public:

    Employee()
    {
        a=0;

    }
    Employee(float x)
    {

       year=x;
        months=(x-year)*12;
    }
    void putdata()
    {


        cout<<"Experience is "<<year<<" and "<<months<<" Months"<<endl;

    }


};

int main()
{
    Employee e1;
    float a;
    cout<<"Enter input:"<<endl;
    cin>>a;
    e1=a;
    e1.putdata();
    return 0;

}
