#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <windows.h>
using namespace std;

// Function to set console text color
void setColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

// Function to clear screen
void clearScreen() 
{
    system("cls");
}

// Function to print the drone battery bar
void printBattery(int battery)
{
    cout << "\n  Battery: [";

    int bars = battery / 5;

    if (battery > 60) setColor(10);
    else if (battery > 30) setColor(14);
    else setColor(12);

    for (int i = 0; i < bars; i++)
    {
        cout << "=";
    }
    setColor(7);
    for (int i = bars; i < 20; i++) 
    {
        cout << " ";
    }

    cout << "] " << battery << "%";

    if (battery > 80)
    {
        setColor(10);
        cout << " (Excellent)";
    }
    else if (battery > 60) 
    {
        setColor(10);
        cout << " (Good)";
    }
    else if (battery > 40) 
    {
        setColor(14);
        cout << " (Fair)";
    }
    else if (battery > 20) 
    {
        setColor(12);
        cout << " (Low - Recharge Soon)";
    }
    else 
    {
        setColor(12);
        cout << " (CRITICAL!)";
    }
    setColor(7);
    cout << endl;
}

// Function to print animated drone
void printDrone() {
    setColor(11);
    cout << "\n     ___" << endl;
    cout << "    /   \\" << endl;
    cout << "   | ^_^ |  <- DRONE X-2000" << endl;
    cout << "    \\___/" << endl;
    cout << "   O  O  O" << endl;
    setColor(7);
}
// Function to show shop menu
void showShopMenu() {
    setColor(11);
    cout << "  Available Items:\n" << endl;
    setColor(7);

    cout << "  1. Pizza           - $15  (Hot & Fresh)" << endl;
    cout << "  2. Burger Meal     - $12  (Combo with Fries)" << endl;
    cout << "  3. Medicine        - $25  (Urgent Care Package)" << endl;
    cout << "  4. Books           - $20  (Educational Bundle)" << endl;
    cout << "  5. Electronics     - $50  (Tech Gadgets)" << endl;
    cout << "  6. Gift Package    - $30  (Special Occasion)" << endl;
    cout << "  7. Tacos           - $10  (Mexican Fiesta)" << endl;
    cout << "  8. Coffee & Snacks - $8   (Energy Boost)" << endl;
}
int main(){
    srand(time(0));
    int battery = 100;
    int totalOrders = 0;
    int successfulDeliveries = 0;
    int totalEarnings = 0;
    bool running = true; //controls main loop
    
    clearScreen();
    setColor(14); // Yellow
    cout << "=== SKY EXPRESS DELIVERY ===\n\n";
    setColor(7); // White
    
  //loop runs till 
    while (battery>=10){
        clearScreen();
        setColor(14);
        cout << "=== SKY EXPRESS DELIVERY ===\n\n";
        setColor(7);
        
        printDrone();
        printBattery(battery);
        cout << "Total Orders: " << totalOrders << " | Success: " << successfulDeliveries << "\n";
        cout << "Total Earnings: $" << totalEarnings << "\n";
        showShopMenu();
        cout << "\n  0. Exit\n";
        cout << "Choose an item: ";
        int choice;
        cin >> choice;
        if (choice == 0) 
            break;//exit
        string item;
        int price = 0;
       if (choice == 1)
       {
        item = "Pizza";
        price = 15;
       }
       else if (choice == 2)
       {
        item = "Burger Meal";
        price = 12;
       }
       else if (choice == 3)
       {
       item = "Medicine";
        price = 25;
        }
      else if (choice == 4)
       {
        item = "Books";
        price = 20;
       }
      else if (choice == 5)
       {
        item = "Electronics";
        price = 50;
       }
      else if (choice == 6)
       {
        item = "Gift Package";
        price = 30;
       }
      else if (choice == 7)
      {
       item = "Tacos";
       price = 10;
      }
      else if (choice == 8)
      {
       item = "Coffee & Snacks";
       price = 8;
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
        if(battery<0)
            battery=0;
    }
    if (battery<=10)
      cout<<"battery is too low to start another delivery";
//Display Final Report of deliveries
    clearScreen();
    cout << "\n=== Final Report ===\n";
    cout << "Orders: " << totalOrders << " | Success: " << successfulDeliveries << endl;
    cout << "Earnings: $" << totalEarnings << endl;
    cout << "Remaining Battery: " << battery << "%\n";
    cout << "Goodbye!\n";
    return 0;
}
