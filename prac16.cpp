#include<iostream>
#include<stdlib.h>
#include<iomanip>
#include<string>
#include<fstream>
using namespace std;
class cardetail
{
    string model_name,fuel_type,transmission;
    float mileaga,tank_capacity;
    int seating,transmission_no,airbags_no;
    string airbags;

    public:
    int fuel_no;
    float showroom_price;
     void getdata(string model_name,string fuel_type,float price1,float mileage1,string trans,float tc1,int seating1,string airbag)
     {
        this-> model_name = model_name;
        this->fuel_type = fuel_type;
        showroom_price = price1;
        mileaga = mileage1;
        transmission = trans;
        tank_capacity = tc1;
        seating = seating1;
        airbags = airbag;

     }
     void format()
     {
    cout<<left<<setw(9)<<"Model"<<right<<setw(8)<<"Fuel"<<right<<setw(8)<<"Price"<<right<<setw(11)<<"Mileage"<<right<<setw(15)
    <<"Transmission"<<right<<setw(16)<<"Tank capacity"<<right<<setw(10)<<"Seating"<<right<<setw(11)<<"Airbags\n";
    cout<<right<<setw(26)<<"(Lakhs)"<<right<<setw(9)<<"(km/L)"<<right<<setw(29)<<"(Liters)"<<right<<setw(15)
    <<"Capacity\n";
     }
     void putdata()
    {

    cout<<left<<setw(9)<<model_name<<right<<setw(10)<<fuel_type<<right<<setw(5)<<showroom_price<<right<<setw(9)<<mileaga<<right
    <<setw(14)<<transmission<<right<<setw(13)<<tank_capacity<<right<<setw(14)<<seating<<right<<setw(11)<<airbags;
    }
    void carmodel()
    {
            cout<<model_name;
    }
    string fueltype()
    {
           return fuel_type;
    }
};

int main()
{
    cardetail a[100];
    int count1=0;
    ifstream inf("cardata.txt");

    if (!inf) {
		cout << "Unable to open file";
		return 1;
	}

	cout<<"File opened successfully\n";
	string model_name,fuel_type, trans, airbag;
	string price, mileage, tc;
	float price1, mileage1, tc1;
	string seating;
	int seating1;
	while(inf)
    {
        getline(inf,model_name,',');
        cout<<"model name = "<<model_name<<endl;
        getline(inf,fuel_type,',');
        cout<<"fuel Type = "<<fuel_type<<endl;
        getline(inf,price,',');
        price1 = stof(price);
        cout<<"Price = "<<price1<<endl;
        price1 = stof(price);
        getline(inf,mileage,',');
        mileage1 = stof(mileage);
        cout<<"mileage = "<<mileage1<<endl;
        getline(inf,trans,',');
        cout<<"Transmission = "<<trans<<endl;
        getline(inf,tc,',');
        tc1 = stof(tc);
        cout<<"Tank Capacity = "<<tc1<<endl;
        getline(inf,seating,',');
        seating1 = stod(seating);
        cout<<"Seating = "<<seating1<<endl;
        getline(inf,airbag,';');
        cout<<"Airbags = "<<airbag<<endl;
        a[count1++].getdata(model_name,fuel_type,price1,mileage1,trans,tc1,seating1,airbag);

    }

    inf.close();
    int car_option;
    string str;
    int price_range;


    cout<<"WELCOME TO TATA MOTORS\n"<<"GET THE CAR DETAILS AS PER YOUR PREFERENCE\n";
   int option,i;
    do{
    cout<<"\n(1)Model Name (2)Fuel Type (3)Price Range\n";
    cout<<"Enter your option :";
    cin>>option;
    switch(option)
    {
        case 1:
        cout <<"LIST OF TATA CARS\n";
        for(i=0;i<count1;i++)
        {
            cout<<"("<<i+1<<")";
            a[i].carmodel();
        }
        cout<<"\nCHOOSE YOUR CAR TO GET DETAILS :";
        cin>>car_option;
        for(i=0;i<count1;i++)
        {
            if(car_option==i+1)
            {
                 a[i].format();
                a[i].putdata();
            }
        }
        break;
        case 2:
        int choice;
        cout<<"TATA MOTORS ARE AVAILABLE WITH FUEL OPTIONS\n";
        cout<<"(1)Petrol (2)Diesel (3)CNG (4)Electric\n";
        cout<<"ENTER YOUR FUEL PREFERENCE :";
        cin>>choice;
        switch (choice)
        {
        case 1:
            str="Petrol";
            break;
        case 2:
            str="Diesel";
            break;
        case 3:
            str="CNG";
            break;
        case 4:
            str="Electric";
            break;


        default:
            cout<<"Wrong choice";
            break;
        }

        a[i].format();
        for(i=0;i<count1;i++)
        {
            if(str==a[i].fueltype())
            {
                a[i].putdata();
            }
            cout<<"\n";
        }
        break;
        case 3:
        cout<<"ENTER YOUR MAXIMUM AFFORDABLE RANGE IN LAKHS :\n";
        cin>>price_range;
        a[i].format();
        for(i=1;i<count1;i++)
        {
            if(a[i].showroom_price<=price_range)
            {
                a[i].putdata();
            }
            cout<<"\n";
        }
        break;
        default:
        cout<<"Invaild choice\n";
        break;
    }
    }while (option!=1 || option !=2 || option!=3);


}
