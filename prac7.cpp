#include<iostream>

using namespace std;

class Complex
{
    float r,i;

public:
    void getdata()
    {
    cout<<"Enter Data"<<endl;
    cout<<"Enter Real Part:";
    cin>>r;
    cout<<"\n";
    cout<<"Enter Imaginary Part:";
    cin>>i;
    }
    void PutData()
    {
        cout<<"Your Complex Number after Operation Is:"<<endl;

        cout<<r<<"+("<<i<<")i"<<endl;

    }

   Complex operator+(Complex &c1)
   {
       Complex temp;
       temp.r=r+c1.r;
       temp.i=i+c1.i;
       return temp;
   }
   Complex operator-(Complex &c2)
   {
       Complex temp;
       temp.r=r-c2.r;
       temp.i=i-c2.i;
       return temp;

   }
   Complex operator*(Complex &c3)
   {
       Complex temp;
       temp.r=(r*c3.r)-(i*c3.i);
       temp.i=(r*c3.i)+(i+c3.r);

       return temp;

   }
   Complex operator/(Complex &c4)
   {
       Complex temp;
       temp.r=((r*c4.r)+(i*c4.i))/((c4.r*c4.r)+(c4.i*c4.i));
       temp.i=((i*c4.r)-(r*c4.i))/((c4.r*c4.r)+(c4.i*c4.i));
       return temp;

   }
    void operator!()
   {

       r=(-1)*r;
       i=(-1)*i;
     cout<<r<<"+("<<i<<")i"<<endl;
   }


};
int main()
{

    Complex a,b,c;
    char op;

    a.getdata();
    b.getdata();

    cout<<"Enter Operator "<<endl;
    cout<<"(+)ADDITION"<<endl;
    cout<<"(-)SUBTRACTION"<<endl;
    cout<<"(*)MULTIPLICATION"<<endl;
    cout<<"(/) DIVISION"<<endl;
    cout<<"(!)NEGATION"<<endl;

    cin>>op;

    switch(op)
    {
    case '+':
        c=a+b;
        c.PutData();
        break;
    case '-':
        c=a-b;
        c.PutData();
        break;
    case '*':
        c=a*b;
        c.PutData();
        break;
    case '/':
        c=a/b;
        c.PutData();
        break;
    case '!':

        !a;
        !b;

        break;

    default:
        cout<<"Invalid Input"<<endl;
    }
}
