 #include<iostream>
#include<iomanip>s
using namespace std;

class Employee
{
    float a;
   float temp,month;
    int year;

public:

    Employee()
    {
        a=0;

    }

  void getdata()
  {

    cout<<"Enter year:"<<endl;
    cin>>year;

    cout<<"Enter month:"<<endl;
    cin>>month;
    a=year+(month/12);
  }
  void putdata()
  {
     cout<<"Your Experiance is :"<<setprecision(4)<<a;
  }
operator float()
{
return a;
}


};

int main()
{
    Employee e1;
    e1.getdata();

    float m;
    m=e1;
    e1.putdata();
    return 0;

}

