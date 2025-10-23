#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

int main(){
    srand(time(0));

    int battery = 100;
    int totalOrders = 0;
    int successfulDeliveries = 0;
    int totalEarnings = 0;
    bool running = true; //controls main loop

    cout << "=== SKY EXPRESS DELIVERY ===\n\n";

  //loop runs till 
    while (battery>=10){
        cout << "\nBattery: " << battery << "%\n";
        cout << "Total Orders: " << totalOrders << " | Success: " << successfulDeliveries << "\n";
        cout << "Total Earnings: $" << totalEarnings << "\n";
        cout << "\nAvailable Items:\n";
        cout << "1. Pizza - $15\n2. Burger - $12\n3. Medicine - $25\n0. Exit\n";
        cout << "Choose an item: ";

        int choice;
        cin >> choice;
        if (choice == 0) 
            break;//exit

        string item;
        int price = 0;
        if(choice == 1)
        { 
            item = "Pizza";
            price = 15;
        }
        else if(choice == 2)
        {
        item = "Burger";
        price = 12;
        }
        else if(choice == 3)
        { 
            item = "Medicine";
            price = 25;
        }
        else 
        {
            cout << "Invalid choice.\n";
            continue;//skip and re run loop if choice is invalid
        }
        //get customer details
        string name, address;
        cout << "\nEnter your name: ";
        cin.ignore();
        getline(cin, name); //allows names with spaces
        cout << "Enter your address: ";
        getline(cin, address);

        cout << "\nDelivering " << item << " to " << name << "...\n";
        //start delivery: choosing a random distance(1 to 5)
        int distance = 1 + rand() % 5;
        int batteryUse = distance * 5 + 10;//formula adds a base 10% drain + 5% per distance unit
        battery -= batteryUse;
      
        cout << "Delivery completed successfully!\n";
        totalOrders++;
        successfulDeliveries++;
        totalEarnings += price;

        if (battery < 30) 
          cout << "Battery low! Please recharge soon.\n";
    }
    if (battery<=10)
      cout<<"battery is too low to start another delivery";
//Display Final Report of deliveries
    cout << "\n=== Final Report ===\n";
    cout << "Orders: " << totalOrders << " | Success: " << successfulDeliveries << endl;
    cout << "Earnings: $" << totalEarnings << endl;
    cout << "Remaining Battery: " << battery << "%\n";
    cout << "Goodbye!\n";

    return 0;
}
