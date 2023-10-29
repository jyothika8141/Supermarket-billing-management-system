#include <iostream>
#include <fstream>

using namespace std;

class shopping
{
    private:
        int pcode;
        float price;
        float dis;
        string pname;

    public:
        void menu();
        void administrator();
        void buyer();
        void add();
        void edit();
        void rem();
        void list();
        void receipt();

};

void shopping :: menu(){

    int choice;
    string email;
    string password;

    while (1){
        cout << "\t\t\t----------------------------------------------\n";
        cout << "\t\t\t               Supermarket Main Menu          \n";
        cout << "\t\t\t----------------------------------------------\n";
        cout << "\t\t\t\n";
        cout << "\t\t\t  1. Administrator" << endl;
        cout << "\t\t\t  2. Customer" << endl;
        cout << "\t\t\t  3. Exit" << endl;
        cout << "\t\t\t\n";
        cout << "\t\t\t Please Select an option[1-3]: ";
        cin >> choice;

        
        switch (choice) {
            case 1: 
                cout << "\t\t\t Please Login " << endl;
                cout << "\t\t\t Enter Email: ";
                cin >> email;
                cout << "\t\t\t Enter Password: ";
                cin >> password;

                if (email=="test@email.com" && password=="admin"){
                    administrator();
                }
                else{
                    cout << "Invalid Email/Password" << endl;
                }
            case 2:
                buyer();
            case 3:
                exit(0);
            default:
                cout << "\t\t\t Please enter a correct input" << endl;
        }

    }


}



void shopping :: administrator(){
    int choice;
    
    //this should also be inside a while loop
    cout << "\t\t\t----------------------------------------------\n";
    cout << "\t\t\t               Administrator Menu             \n";
    cout << "\t\t\t----------------------------------------------\n";
    cout << "\t\t\t\n";
    cout << "\t\t\t  1. Add the product" << endl;
    cout << "\t\t\t  2. Modify the product" << endl;
    cout << "\t\t\t  3. Delete the product" << endl;
    cout << "\t\t\t  4. Back to main menu" << endl;
    cout << "\t\t\t\n";
    cout << "\t\t\t Please Select an option[1-4]: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        add();
        break;
    case 2:
        edit();
        break;
    case 3:
        rem();
        break;

    case 4:
        menu();
        break;

    default:
        cout << "\t\t\t Invalid Choice \n"; 
        break;
    }
}


void shopping :: buyer(){
    int choice;
    cout << "\t\t\t BUYER \n";
    cout << "\t\t\t 1. Buy product " << endl;
    cout << "\t\t\t 2. Go back to main menu" << endl;
    cout << "\t\t\t Please enter an option[1-2]: " << endl;
    cin >> choice;

   switch (choice)
   {
   case 1:
        receipt();
        break;
   case 2:
        menu();
        break;
   default:
        cout << "\t\t\t Invalid Choice" << endl;
        break;
   }  
}


void shopping :: add() {
    fstream data;
    int c;
    int token = 0;
    float p;
    float d;
    string n;

    cout << "\t\t\t Add a new product " << endl;
    cout << "\t\t\t Enter product code: ";
    cin >> pcode;
    cout << "\t\t\t Enter name of product: ";
    cin >> pname;
    cout << "\t\t\t Enter the price of the product: ";
    cin >> price;
    cout << "\t\t\t Discount on the product: ";
    cin >> dis;

    data.open("database.txt", ios :: in);
    if (!data) {
        //if file exists we write into the file
        data.open("database.txt", ios::app|ios::out);
        data << " " << pcode << " " << pname << " " << price << " " << dis << "\n";
        data.close();
    } else {
        // else read from the file
        data >> c >> n >> p >> d;

        while (!data.eof()){
            if (c == pcode){
                token++;
            }
            data >> c >> n >> p >> d; 
        }
        data.close();
    }

    if (token == 1){
        //goto m;
        cout << "Do something";
    }
    else {
        data.open("database.txt", ios::app|ios::out);
        data << " " << pcode << " " << pname << " " << price << " " << dis << "\n";
        data.close();
    }
    cout << "\t\t\t Record inserted " << endl;
}

void shopping :: edit(){
    fstream data, data1;
    int token = 0;
    int pkey;
    int c;
    float p;
    float d;
    string n;

    cout << "\t\t\t Modify the record " << endl;
    cout << "\t\t\t Product code: ";
    cin >> pkey;

    data.open("database.txt", ios::in);
    if (!data)
    {
        cout << "\t\t\t file doesn't exist" << endl;
    }
    else {
        data1.open("datbase1.txt", ios::app|ios::out);

        data >> pcode >> pname >> price >> dis;
        while (!data.eof()){
            if (pkey == pcode) {
                cout << "\t\t\t Enter new product code: ";
                cin >> c;
                cout << "\t\t\t Enter new name of product: ";
                cin >> n;
                cout << "\t\t\t Enter new price of product: ";
                cin >> p;
                cout << "\t\t\t Enter new discount on product: ";
                cin >> d;
                data1 << " " << c << " " << n << " " << p << " " << d << "\n";
                cout  << "\t\t\t Record modified " << endl;
                token++;
            }
            else {
                data1 << " " << pcode << " " << pname << " " << price << " " << dis << "\n";
            }
            data >> pcode >> pname >> price >> dis;

        }
        data.close();
        data1.close();

        remove("database.txt");
        rename("database1.txt", "database.txt");

        if (token == 0) {
            cout << "\t\t\t Record not found " << endl;
        }

    }
}

void shopping :: rem(){
    fstream data, data1;
    int pkey;
    int token = 0;
    cout << "\t\t\t Delete the record " << endl;
    cout << "\t\t\t Enter the product code: ";
    cin >> pkey;
    data.open("database.txt", ios::in);
    if (!data){
        cout << "\t\t\t File doesn't exist " << endl;
    }
    else {
        data1.open("database1.txt", ios::app|ios::out);
        data >> pcode >> pname >> price >> dis;
        //it is a little differenct from here
        while (!data.eof()){
            if (pkey != pcode){
                data1 << " " << pcode << " " << pname << " " << price << " " << dis << "\n";
            }
            else {
                cout << "\t\t\t Record deleted " << endl;
                token++;
            }
            data >> pcode >> pname >> price >> dis;
        }
        data.close();
        data1.close();

        remove("database.txt");
        rename("database1.txt", "database.txt");

        if (token == 0){
            cout << "\t\t\t Record not found " << endl;
        }
    }
}

void shopping ::list(){
    fstream data;
    data.open("database.txt", ios::in);
    cout << "\t\t\t Product code \t\t Name \t\t Price \t\t Discount \n";
    data >> pcode >> pname >> price >> dis;
    while (!data.eof()){
        cout << "\t\t\t " << pcode << " \t\t " << pname << " \t\t " << price << " \t\t " << dis << "\n";
        data >> pcode >> pname >> price >> dis;
    }
    data.close();

}

void shopping :: receipt(){
    fstream data;

    int arrc[100];
    int arrq[100];
    char choice;
    int c = 0;
    float amout = 0;
    float dis = 0;
    float netamt = 0;

    cout << "\t\t\t RECEIPT" << endl;
    data.open("database.txt", ios::in);
    if (!data) {
        cout << "\t\t\t The database is empty" << endl;
    }
    else {
        data.close();

        list();
        cout << "\t\t\t---------------------------" << endl;
        cout << "\t\t\t Please place your order " << endl;
        cout << "\t\t\t---------------------------" << endl;
        cout << "\t\t\t Enter the product code: ";
        cin >> arrc[c];
        cout << "\t\t\t Enter the quantity: ";
        cin >> arrq[c];
        for (int i = 0; i < c; i++){
            if (arrc[c] == arrc[i]){
                cout << "\t\t\t Product code already entered " << endl;
                // goto m
            }
            c++;
            cout << "\n\n Do you want to place another order [y/n]: ";
            cin >> choice;

        }
        while (choice == 'y' || choice == 'Y'){
            cout << "\t\t\t Enter the product code: ";
            cin >> arrc[c];
            cout << "\t\t\t Enter the quantity: ";
            cin >> arrq[c];
            for (int i = 0; i < c; i++){
                if (arrc[c] == arrc[i]){
                    cout << "\t\t\t Product code already entered " << endl;
                    // goto m
                }
                c++;
                cout << "\n\n Do you want to place another order [y/n]: ";
                cin >> choice;
            }
        }
        cout << "\t\t\t---------------------------" << endl;
        cout << "\t\t\t Supermarket Receipt " << endl;
        cout << "\t\t\t---------------------------" << endl;
        cout << "\t\t\t Product code \t\t Quantity \t\t Price \t\t Amount \n";
        data.open("database.txt", ios::in);
        data >> pcode >> pname >> price >> dis;
        while (!data.eof()){
            for (int i = 0; i < c; i++){
                if (pcode == arrc[i]){
                    amout = price * arrq[i];
                    netamt = netamt + amout;
                    cout << "\t\t\t " << pcode << " \t\t " << arrq[i] << " \t\t " << price << " \t\t " << amout << "\n";
                }
            }
            data >> pcode >> pname >> price >> dis;
        }
        data.close();
        cout << "\t\t\t---------------------------" << endl;
        cout << "\t\t\t Net Amount \t\t " << netamt << endl;
        cout << "\t\t\t---------------------------" << endl;
    }

}

int main(){
    shopping s;
    s.menu();
    return 0;
}