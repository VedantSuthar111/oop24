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
    protected :
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
    cout <<left<<setw(20)<< "Employee Name " << ":"<<employee_name << endl;
    cout <<left<<setw(20)<< "Qualification " << ":"<<qualification << endl;
    cout <<left<<setw(20)<< "Experience " << ":"<<experience << endl;
    cout <<left<<setw(20)<< "Contact Number " <<":"<< contact_no << endl;
    }
    int searchid(int emp_id)

    {
        if(emp_id == employee_id)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    public :
    int emplyoeeid()
    {
        return employee_id;
    }
    static void average_experience()
    {
        cout<<"Average experience is "<<average_ex/count;
    }
};
class teaching_employee : public employee
{
    string Designation;
    string specializtion;
    string Pay_scale;
    public :
    void getdata()
    {
        employee ::getdata();
        cout<<"Enter designation :"<<endl;
        cin>>Designation;

        cout<<"Enter specializtion :"<<endl;
        getline(cin,specializtion);

        cout<<"Enter Pay Scale : "<<endl;
        getline(cin,Pay_scale);

    }
    void putdata()
    {
        cout << "---------------------------------"<<endl;
        employee ::putdata();
        cout <<left<<setw(20)<< "Designaton " << ":"<<Designation << endl;
        cout <<left<<setw(20)<< "Specialization " << ":"<<specializtion << endl;
        cout <<left<<setw(20)<< "Pay scale " << ":"<<Pay_scale << endl;
        cout << "---------------------------------"<<endl;
    }
    int searchid(int emp_id)
    {
        return employee ::searchid(emp_id);
    }

};
class nonteaching_employee : public employee
{
    int salary;
    public :
    void getdata()
    {
        employee :: getdata();
        cout<<"Enter Salary :";
        cin>>salary;
    }
    void putdata()
    {
        cout << "---------------------------------"<<endl;
        employee :: putdata();
        cout <<left<<setw(20)<< "Salary " << ":"<<salary << endl;
        cout << "---------------------------------"<<endl;
    }
    int searchid(int emp_id)
    {
        return employee :: searchid(emp_id);
    }
};
int employee :: count=0;
float employee :: average_ex=0;

int main()
{
    int n_t,n_nt,i,flag = 0;
    char choice;
    cout<<"Enter no of Teaching employee :";
    cin>>n_t;
    cout<<"Enter no of Non Teaching employee :";
    cin>>n_nt;
    teaching_employee e[n_t];
    nonteaching_employee f[n_nt];
    for(i=0;i<n_t;i++)
    {
        cout<<"Enter teaching employee data:"<<endl;
        e[i].getdata();
    }
    for(i=0;i<n_nt;i++)
    {
        cout<<"Enter non teaching employee data:"<<endl;
        f[i].getdata();
    }

     do {
        int e_id;
        cout << "Enter an employee id: ";
        cin >> e_id;
        for (i = 0; i < n_t; i++)
        {
            int search =e[i].searchid(e_id);
            if(search==1)
            {
                e[i].putdata();
                flag=1;
                break;
            }
        }
        for (i = 0; i < n_nt; i++)
        {
            int search = f[i].searchid(e_id);
            if(search==1)
            {
                f[i].putdata();
                flag=1;
                break;
            }
        }
        if(flag==0)  {
                cout << "*"<<endl;
                cout << "Error: Entered employee id does not exist" << endl;
                cout << "*"<<endl;
            }

        cout << "Press Y to get another employee detail, press N to exit: ";

        cin >> choice;
        flag=0;
    } while (choice == 'Y' || choice == 'y');
}
