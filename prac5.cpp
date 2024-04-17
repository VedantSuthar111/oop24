#include<iostream>
#define pi 3.148
using namespace std;
class circle
{
   float radius;
   static int c;
   public:
   circle()
    {
        radius=1;
        c++;
    }
    circle(float a)
    {
        radius=a;
        c++;
    }
    circle(circle &f)
    {
        radius=f.radius;
        c++;
    }
    void totalobject()
    {
        cout<<"Total active object :"<<c<<endl;
    }
    void Display()
    {
        float area;
        area=pi*radius*radius;
        cout<<"Circle with radius"<<radius<<"has area ="<<area<<endl;
    }
    ~circle()
    {
        cout<<"one object is deleted"<<endl;
        c--;
        totalobject();
    }
};
int circle :: c = 0;
int main()
{
    circle c1;
    circle c2(20.00);
    circle c3(c1);
    c1.Display();
    c2.Display();
    c3.Display();
    return 0;
}
