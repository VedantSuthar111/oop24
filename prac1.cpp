#include <iostream>
#include <iomanip>
#include <string>
using namespace std;


string convertToGrade(int );
int convertToGradePoints(int );
float calculateSGPA();
struct det
{
    int th_marks[3],pr_marks[3];
    string subject[3];
    int th_cred[3],pr_cred[3];
}s1;
int main() {
    char ID[8], Name[20];
    int Sem;
    float SGPA;

    cout << "Enter Student ID: ";
    cin >> ID;
    cout << "Enter Name: ";
    cin >> Name;
    cout << "Enter Semester: ";
    cin >> Sem;

    SGPA = calculateSGPA();


    cout.width(15);
    cout << left << "Student ID" << ": " << ID << "\n";
    cout.width(15);
    cout << left << "Student Name" << ": " << Name << "\n";
    cout.width(15);
    cout << left << "Semester" << ": " << Sem << "\n\n\n";
     cout << endl;
    cout.width(25);
    cout << left << "Subject";
    cout << setw(10) << "Theory"<< "Practical" << endl;

    for (int i = 0; i < 3; i++)
    {
        cout << left << setw(25) << s1.subject[i];
        cout << setw(10) << convertToGrade(s1.th_marks[i]) << setw(10) << convertToGrade(s1.pr_marks[i]);
        cout << endl;
    }
    cout<<endl<<"SGPA:"<<setprecision(2)<<SGPA;

    return 0;
}


string convertToGrade(int mark) {
    if (mark >= 80) return "AA";
    else if (mark >= 73) return "AB";
    else if (mark >= 66) return "BB";
    else if (mark >= 60) return "BC";
    else if (mark >= 55) return "CC";
    else if (mark >= 50) return "CD";
    else if (mark >= 45) return "DD";
    else return "FF";
}

int convertToGradePoints(int mark) {
    if (mark >= 80) return 10;
    else if (mark >= 73) return 9;
    else if (mark >= 66) return 8;
    else if (mark >= 60) return 7;
    else if (mark >= 55) return 6;
    else if (mark >= 50) return 5;
    else if (mark >= 45) return 4;
    else return 0;
}

float calculateSGPA() {
    int sum1 = 0, sum2 = 0, credit_sum = 0;

    for(int i=0;i<3;i++)
    {
        cout<< "Enter Subject["<<i+1<<"] -(Name,Theory Credits and Practical credits) ->";
        cin>>s1.subject[i]>>s1.th_cred[i]>>s1.pr_cred[i];
    }
    for (int i = 0; i < 3; i++) {
        cout << "Enter Theory Marks of Subject - " << s1.subject[i] << ": ";
        cin >> s1.th_marks[i];

        cout << "Enter Practical Marks of Subject - " << s1.subject[i] << ": ";
        cin >> s1.pr_marks[i];

        sum1 += convertToGradePoints(s1.th_marks[i]) * s1.th_cred[i];
        sum2 += convertToGradePoints(s1.pr_marks[i]) * s1.pr_cred[i];
        credit_sum += s1.th_cred[i] + s1.pr_cred[i];
    }

    return (float)(sum1 + sum2) /credit_sum ;
}
