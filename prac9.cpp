#include<iostream>
using namespace std;

class CM;

class MM{
    float cm,mm;
public:
    float get_cm(){
        return cm;
    }
    MM(){
        cm=0;
    }
    MM(float a){
        cm=a/10.0;
    }
    MM(CM &k);
    void display(){
        cout<<"Measurement in mm:"<<mm;
    }
};

class CM{
    float mm,cm;
public:
    CM(float a){
        mm=a*10;
    }
    float get_mm(){
        return mm;
    }
    CM(MM &y);
    void display(){
        cout<<"Measurement in cm:"<<cm;
    }
};

MM::MM(CM &k){
    mm=k.get_mm();
}

CM::CM(MM &y){
    cm=y.get_cm();
}

int main(){
    int y;
    cout<<"Enter 1: mm to cm converter"<<endl;
    cout<<"Enter 2: cm to mm converter"<<endl;
    cin>>y;
    switch(y){
        case 1:{
            float v;
            cout<<"Enter the mm:"<<endl;
            cin>>v;
            MM mm1(v);
           CM  cm1(mm1);
            cm1.display();
            break;
        }
        case 2:{
            cout<<"Enter the cm:"<<endl;
            float u;
            cin>>u;
           CM cm2(u);
          MM mm2(cm2);
            mm2.display();
        }
    }
}
