#include<iostream>

#include<iomanip>
#include<iomanip>

using namespace std;

class Litreture
{
 string title;
 long int id;

 public :
     void getdata()
     {

         cout<<"Enter Id :"<<endl;
         cin>>id;
         cout<<"Enter Title:"<<endl;
         cin>>title;

     }
    void putdata()
    {
    cout<<setw(5)<<"id"<<setw(2)<<":"<<id;
    cout<<setw(5)<<"Title"<<setw(2)<<":"<<title;


    }
};
class E_lit : public virtual Litreture
{
    string doi;

public:
    void Getdoi()
    {
        getdata();
        cout<<"Enter DOI if E-book:"<<endl;
    cin>>doi;

    }
    void putdoi()
    {
        putdata();
        cout<<setw(5)<<"Doi"<<setw(2)<<":"<<doi;

    }

};
class HardBound : virtual public Litreture
{
    int no_copies;
public:
    void No_Of_Copies()
    {
        getdata();
        cout<<"Enter No of Copies"<<endl;
        cin>>no_copies;

    }
    void putcop()
    {
        putdata();

        cout<<setw(5)<<"No of Copies"<<setw(2)<<":"<<no_copies;

    }

};
class Book: public E_lit,public HardBound
{
int isbn;
char a;
char choice;
public:
    void GetBook()
    {


        cout<<"Enter Isbn:"<<endl;
        cin>>isbn;
        cout<<"(E)copy or (H)copy"<<endl;
        cin>>choice;
        if(choice=='E' || choice=='e')
        {
          Getdoi();

        }
         else if(choice=='H' || choice=='h')
        {
          No_Of_Copies();

        }


    }
    void putBook()
    {
 if(choice=='E' || choice=='e')
        {
          putdoi();

        }
         else if(choice=='H' || choice=='h')
        {
          putcop();

        }

    }
};
class magazine: public E_lit,public HardBound
{
int issn;
  char choice;
public:
    void GetMag()
    {

        cout<<"Enter Issn:"<<endl;
        cin>>issn;
        cout<<"(E)copy or (H)copy"<<endl;
        cin>>choice;
        if(choice=='E' || choice=='e')
        {
          Getdoi();

        }
         else if(choice=='H' || choice=='h')
        {
          No_Of_Copies();

        }

    }
    void putMag()
    {
        if(choice=='E' || choice=='e')
        {
          putdoi();

        }
         else if(choice=='H' || choice=='h')
        {
          putcop();

        }


    }
};
int main()
{
    Book b[20];
    magazine m[20];
    int choice1,bcount=0,mcount=0;
    char menu;
    do{
    cout<<"Enter 1:Add Book Data\nEnter 2: Add Magazine Data\n Enter 3: List all Books\nEnter 4:List all Magazine"<<endl;
    cout<<"Enter Your Choice:";

    cin>>choice1;





   switch(choice1)
   {
   case 1:
       char select;
      do{
        b[bcount].GetBook();
        bcount++;
        cout<<"Enter Y for enter More Books or N:";
        cin>>select;
      }while(select=='y'|| select=='Y');
      break;
   case 2:
    char select1;
      do{
        m[mcount].GetMag();
        mcount++;
        cout<<"Enter Y for enter More Books or N:";
        cin>>select1;
      }while(select=='y'|| select=='Y');
      break;
   case 3:
       for(int i=0;i<bcount;i++)
       {

           b[i].putBook();
           cout<<"\n";
       }
       break;
   case 4:
       for(int i=0;i<mcount;i++)
       {

           m[i].putMag();
           cout<<"\n";
       }
    break;
    default:cout<<"Wrong Choice"<<endl;

   }
   cout<<"\nEnter Y For Continue or N For Exit:"<<endl;
   cin>>menu;
    }while(menu=='y'|| menu=='Y');

}
