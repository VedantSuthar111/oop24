#include<iostream>
#include<stdlib.h>
#include<iomanip>
#include<string>
using namespace std;
class employee
{
    int employee_id;
    string employee_name;
    string qualification;
    float experience;
    long int contact_no;
    static  int count;
    static float average_ex;
    public:
    void getdata()
    {
    cout << "Enter Employee id :";
    cin >> employee_id;


    cout << "Enter Employee Name :";
     getline(cin,employee_name);


    cout << "Enter Qualification :";
    getline(cin,qualification);


    cout << "Enter Experience :";
    cin >> experience;

    cout << "Enter Contact :";
    cin >> contact_no;

     count ++;
     average_ex = average_ex + experience;
    }
    void putdata()
    {
    cout << "---------------------------------"<<endl;
    cout <<left<<setw(20)<< "Employee Name " << ":"<<employee_name << endl;
    cout <<left<<setw(20)<< "Qualification " << ":"<<qualification << endl;
    cout <<left<<setw(20)<< "Experience " << ":"<<experience << endl;
    cout <<left<<setw(20)<< "Contact Number " <<":"<< contact_no << endl;
    cout << "---------------------------------"<<endl;
    }
    int emplyoeeid()
    {
        return employee_id;
    }
    static void average_experience()
    {
        cout<<"Average experience is "<<average_ex/count;
    }
};
int employee :: count=0;
float employee :: average_ex=0;

int main()
{
    employee e[1000];
    int i,n,flag=0;
    char choice;
    cout << "Enter no of Employee :";
    cin >> n;

    for(i=0 ; i<n ; i++)
    {
        e[i].getdata();

    }

    do {
        int e_id;
        cout << "Enter an employee id: ";
        cin >> e_id;
        for (i = 0; i < n; i++)
        {
            if (e[i].emplyoeeid() == e_id)
            {
                e[i].putdata();
                flag=1;
                break;
            }
        }
        if(flag==0)  {
                cout << "*"<<endl;
                cout << "Error: Enterd employee id does not exist" << endl;
                cout << "*"<<endl;
            }

        cout << "Press Y to get another employee detail, press N to exit: ";

        cin >> choice;
        flag=0;
    } while (choice == 'Y' || choice == 'y');
    employee :: average_experience();
}
