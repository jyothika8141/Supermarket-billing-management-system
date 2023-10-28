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
                // token++;
            }
            else {
                data1 << " " << pcode << " " << pname << " " << price << " " << dis << "\n";
            }
            data >> pcode >> pname >> price >> dis;

        }
        data.close();
        data1.close();
    }
}