#include <iostream>
#include <string>
#include <iomanip>
#include<stdlib.h>
using namespace std;

class Car {
    float mileage, Tank_cap;
    int seating, Tran_op, air_op;
    string transmission;
    string ModelName;
    string Fuel_type;
    float Show_price;
    string Airbag;
    int FuelChoice;

public:
    string GetModelName() {
        return ModelName;
    }

    string GetFuelType() {
        return Fuel_type;
    }

    float GetShowPrice() {
        return Show_price;
    }

    string GetAirbag() {
        return Airbag;
    }

    int GetFuelChoice() {
        return FuelChoice;
    }

    void GetData() {
        cout << "Enter ModelName of Car:";
        cin >> ModelName;

        cout << "Enter your preferred fuel:" << endl;
        cout << "(1) Petrol" << endl << "(2) Diesel" << endl << "(3) CNG" << endl << "(4) Electric" << endl;
        cin >> FuelChoice;
        while (FuelChoice < 1 || FuelChoice > 4)

            {
            cout << "Invalid Input. Please enter a valid fuel choice:" << endl;
            cin >> FuelChoice;
        }
        switch (FuelChoice) {
            case 1: Fuel_type = "Petrol"; break;
            case 2: Fuel_type = "Diesel"; break;
            case 3: Fuel_type = "CNG"; break;
            case 4: Fuel_type = "Electric"; break;
        }

        cout << "Transmission Type:" << endl;
        cout << "(1) Manual Transmission" << endl << "(2) Automatic Transmission" << endl;
        cin >> Tran_op;
        while (Tran_op < 1 || Tran_op > 2) {
            cout << "Invalid Input. Please enter a valid transmission type:" << endl;
            cin >> Tran_op;
        }
        switch (Tran_op) {
            case 1: transmission = "Manual"; break;
            case 2: transmission = "Automatic"; break;
        }

        cout << "Enter Tank Capacity:";
        cin >> Tank_cap;

        cout << "Enter Seating:";
        cin >> seating;
        cout << "Enter Mileage:";
        cin >> mileage;

        cout << "Enter ShowRoom Price Of car:";
        cin >> Show_price;

        cout << "Enter if car has Airbags" << endl;
        cout << "(1) Yes" << endl << "(2) No"<<endl;
        cin >> air_op;
        while (air_op < 1 || air_op > 2) {
            cout << "Invalid Input. Please enter a valid option for airbags:" << endl;
            cin >> air_op;
        }
        switch (air_op) {
            case 1: Airbag = "YES"; break;
            case 2: Airbag = "NO"; break;
        }
    }

    void Upperpart() {
        cout << left << setw(9) << "Model" << right << setw(8) << "Fuel" << right << setw(8) << "Price" << right << setw(11) << "Mileage" << right << setw(15)
            << "Transmission" << right << setw(16) << "Tank capacity" << right << setw(11) << "Seating" << right << setw(11) << "Airbags\n";
        cout << right << setw(26) << "(Lakhs)" << right << setw(9) << "(km/L)" << right << setw(29) << "(Liters)" << right << setw(15)
            << "Capacity\n";
    }

    void putdata() {
        cout << left << setw(9) << ModelName << right << setw(9) << Fuel_type << right << setw(5) << Show_price << right << setw(9) << mileage << right
            << setw(14) << transmission << right << setw(13) << Tank_cap << right << setw(14) << seating << right << setw(11) << Airbag;
    }

    void Model() {
        cout << ModelName;
    }
};

int main() {
    int no, i;
    int p_choice, Model_Option, Fuel_op;
    float price_range;
    char a;

    cout << "Enter No of Cars:";
    cin >> no;
    Car c[7];

    for (i = 0; i < no; i++) {
        c[i].GetData();
    }

    system("CLS");

    do {
        cout << "Enter your Preferred choice:" << endl;
        cout << "(1) Model Name" << endl << "(2) Fuel Type" << endl << "(3) Price" << endl;
        cin >> p_choice;

        switch (p_choice) {
            case 1:
                cout << "List of Tata Cars" << endl;
                cout << "***********************************************************************************************************************" << endl;
                for (i = 0; i < no; i++) {
                    cout << i + 1 << ".";
                    c[i].Model();
                    cout << "\n";
                }
                cout << "Enter Your Car For Details:";
                cin >> Model_Option;
                for (i = 0; i < no; i++) {
                    if (Model_Option == i + 1) {
                        c[i].Upperpart();
                        c[i].putdata();
                    }
                }
                break;
            case 2:
                cout << "AS PER FUEL OPTIONS\n";
                cout << "(1) Petrol (2) Diesel (3) CNG (4) Electric\n";
                cout << "ENTER YOUR FUEL PREFERENCE :";
                cin >> Fuel_op;
                for (i = 0; i < no; i++) {
                    if (Fuel_op == c[i].GetFuelChoice()) {
                        c[i].Upperpart();
                        c[i].putdata();
                    }
                    cout << "\n";
                }
                break;
            case 3:
                cout << "Enter your Budget Price :\n";
                cin >> price_range;
                for (i = 0; i < no; i++) {
                    if (c[i].GetShowPrice() <= price_range) {
                        c[i].Upperpart();
                        c[i].putdata();
                    }
                }
                break;
            default:
                cout << "Please enter a valid choice" << endl;
        }

        cout << "\n\n";
        cout << "Enter Y for Return to Main Menu and N for Exit:" << endl;
        cin >> a;
    } while (a == 'Y' || a == 'y');

    cout << "Thank you for visiting. Goodbye!" << endl;

    return 0;
}
