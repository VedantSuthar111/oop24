#include<iostream>
#include<string>
#include<iomanip>
#include<stdlib.h>
using namespace std;
class result;
class student
{
    string stu_id;
    string stu_name;
    int semester;
    public :
    void getdata();
    void putdata();
    void getresult(result &r);
    void sgparesult(result &r);
    void putresult(result &r);

};
void student :: getdata()
    {
        cout<<"Enter student  id :";
        cin>>stu_id;

        cout<<"Enter student name :";
        cin>>stu_name;

        cout<<"Enter semester :";
        cin>>semester;

    }
void student :: putdata()
    {
        cout<<"Studen id"<<setw(14)<<": "<<stu_id<<endl;
        cout<<"Studen name"<<setw(12)<<": "<<stu_name<<endl;
        cout<<"Semester"<<setw(15)<<": "<<semester<<endl;
    }
class result
{
   int credit_sum=0,i,j,gradep[3],gradet[3],credit_theory[3],credit_practical[3];
   string sub1,sub2,sub3;
   string sub[3];
   int Theory_marks[3];
   int practical_marks[3];
   string Theory[3],Practical[3];
   float theory_sum,practical_sum, sgpa=0;
   friend class student;
};

   void student :: getresult(result &r)
   {
    cout<<"Subject 1:";
    getline(cin,r.sub1);

    cout<<"Sbuject 2:";
    getline(cin,r.sub2);

    cout<<"Subject 3:";
    getline(cin,r.sub3);

    cout<<"Credit for theory"<<endl;
    for(int i=0;i<3;i++)
    {
        cout<<"Theory Credit for sub"<<i+1<<":";
        cin>>r.credit_theory[i];
    }
    cout<<"Credit for pracitcal"<<endl;
    for(int i=0;i<3;i++)
    {
        cout<<"Practical Credit for sub"<<i+1<<":";
        cin>>r.credit_practical[i];
    }


    for(int i=0;i<3;i++)
    {
        cout<<"Enter practical marks "<<i+1<<":";
        cin>>r.practical_marks[i];

    }
    for(int i=0;i<3;i++)
    {
        cout<<"Enter theory marks "<<i+1<<":";
        cin>>r.Theory_marks[i];
    }

    for (int  j = 0; j < 3; j++)
    {

            if (r.Theory_marks[j]>=80)
            {
                r.gradet[j]=10;
                r.Theory[j]="AA";
            }
            else if (r.Theory_marks[j]>=73 && r.Theory_marks[j]<80)
            {
                r.gradet[j]=9;
                r.Theory[j]="AB";
            }
            else if (r.Theory_marks[j]>=66 && r.Theory_marks[j]<73)
            {
                r.gradet[j]=8;
                r.Theory[j]="BB";
            }
            else if (r.Theory_marks[j]>=60 && r.Theory_marks[j]<66)
            {
                r.gradet[j]=7;
                r.Theory[j]="BC";
            }
            else if (r.Theory_marks[j]>=55 && r. Theory_marks[j]<60)
            {
                r.gradet[j]=6;
                r.Theory[j]="CC";
            }
            else if (r.Theory_marks[j]>=50 && r.Theory_marks[j]<55)
            {
                r.gradet[j]=5;
                r.Theory[j]="CD";
            }

             else if (r.Theory_marks[j]>=45 && r.Theory_marks[j]<50)
            {
                r.gradet[j]=4;
                r.Theory[j]="DD";
            }
            else
            {
                r.gradet[j]=0;
                r.Theory[j]="FF";
            }
        }
         for ( int i = 0; i < 3; i++)
        {
            if (r.practical_marks[i]>=80)
            {
                r.gradep[i]=10;
                r.Practical[i]="AA";
            }
            else if (r.practical_marks[i]>=73 && r.practical_marks[i]<80)
            {
                 r.gradep[i]=9;
                r.Practical[i]="AB";
            }
            else if (r.practical_marks[i]>=66 && r.practical_marks[i]<73)
            {
                 r.gradep[i]=8;
                r.Practical[i]="BB";
            }
            else if (r.practical_marks[i]>=60 && r.practical_marks[i]<66)
            {
                 r.gradep[i]=7;
                r.Practical[i]="BC";
            }
            else if (r.practical_marks[i]>=55 && r.practical_marks[i]<60)
            {
                 r.gradep[i]=6;
                r.Practical[i]="CC";
            }
            else if (r.practical_marks[i]>=50 && r.practical_marks[i]<55)
            {
                 r.gradep[i]=5;
                r.Practical[i]="CD";
            }
             else if (r.practical_marks[i]>=45 && r.practical_marks[i]<50)
            {
                 r.gradep[i]=4;
                r.Practical[i]="DD";
            }
            else
            {
                 r.gradep[i]=0;
               r.Practical[i]="FF";
            }
        }
   }
   void student ::sgparesult(result &r){
     for ( int i = 0; i < 3; i++)
    {
        r.theory_sum=r.theory_sum+ (float)r.gradet[i]*r.credit_theory[i];
        r.practical_sum=r.practical_sum+(float)r.gradep[i]*r.credit_practical[i];
        r.credit_sum=r.credit_sum+r.credit_theory[i]+r.credit_practical[i];

    }
    r.sgpa=(float)(r.theory_sum+r.practical_sum)/r.credit_sum;
   }
   void student :: putresult(result &r)
   {
   sgparesult(r);
   cout<<setw(45)<<"Thoery" <<setw(13) <<"Practcal"<<endl;
   cout<<left<<setw(30)<<r.sub1<<right<<setw(13)<<r.Theory[0]<<right<<setw(13)<<r.Practical[0]<<endl;
   cout<<left<<setw(30)<<r.sub2<<right<<setw(13)<<r.Theory[1]<<right<<setw(13)<<r.Practical[1]<<endl;
   cout<<left<<setw(30)<<r.sub3<<right<<setw(13)<<r.Theory[2]<<right<<setw(13)<<r.Practical[2]<<endl;
   cout<<"SGPA"<<setw(16)<<":   "<<setprecision(3)<<r.sgpa;
   }



int main()
{
    student s;
    result r;
    s.getdata();
    s.getresult(r);
    s.putdata();
    s.putresult(r);

}

