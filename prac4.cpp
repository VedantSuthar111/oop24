#include <iostream>
#include <cmath>
using namespace std;

double area(double radius)
{
    double pi=3.14;
    return pi * radius * radius;
}

double area(double length, double width)
{
    return length * width;
}


double area(double length, double width, double height)
{
    return 2 * (length * width + length * height + width * height);
}

int main() {
double r,lr,wr,lc,wc,hc;
cout<<"Enter Radius of circle"<<endl;
cin>>r;

    double circleArea = area(r);
    cout << "Area of circle: " << circleArea << endl;
    cout<<"Enter Length and Breadth of rectangle:";
    cin>>lr>>wr;
     double rectangleArea = area(lr,wr);
    cout << "Area of rectangle: " << rectangleArea << endl;

   cout<<"Enter Length,breadth and Height of cuboid:";
   cin>>lc>>wc>>hc;

    double cuboidArea = area(lc,wc,hc);



    cout << "Surface area of cuboid: " << cuboidArea << endl;

    return 0;
}
