#include<iostream>
#include<iomanip>
#include<stdlib.h>
#include<string>
using namespace std;
struct emp
{
 int employee_id;
    string emp_name;
    string quali;
    float exper;
    long int contact;

void GetData()
{
    cout<<"Enter Employee's ID:";
    cin>>employee_id;

    cout<<"Enter Employee's Name:";
    cin>>emp_name;
    cout<<"Enter Qualification:";
    cin>>quali;

    cout<<"Enter Experience:";
    cin>>exper;

    cout<<"Enter Contact no:";
    cin>>contact;

}
void Putdata()
{
cout << "*********************************"<<endl;
cout.width(20);cout <<left<< "Employee's Name is : " << ":"<<employee_name << endl;
cout.width(20);cout <<left<< "Qualification of Employee is  " << ":"<<qualification << endl;
cout.width(20);cout <<left<< "Experience of Employee " << ":"<<experience << endl;
cout.width(20);cout <<left<< "Contact Number of Employee " <<":"<<contact << endl;
cout << "*********************************"<<endl;

}


};
int main()
{
    struct emp s[500];
    int i,n,flag=0;
    char choice;
    cout<<"Enter no of Employees:";
    cin>>n;

    for(i=0;i<n;i++)
    {
        s[i].GetData();
    }
    system("CLS");
     do {
        int emp_id;
        cout << "Enter an employee id: ";
        cin >> emp_id;

        for (int i = 0; i < n; i++)
            {
            if (s[i].employee_id == emp_id)
            {
             s[i].Putdata();
             flag=1;
             break;
            }
            }
            if(flag==0)
            {
                cout << "*";
                cout << "ERROR Employee not exist" << endl;
                cout << "*"<<endl;
            }
            flag=0;
        cout << "Press Y to get another employee detail, press N to exit: ";
        cin >> choice;

    } while (choice == 'Y' || choice == 'y');


}


