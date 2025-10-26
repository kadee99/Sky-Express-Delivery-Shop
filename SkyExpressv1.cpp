#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <windows.h>
using namespace std;

// Function to set console text color
void setColor(int color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

// Function to clear screen
void clearScreen()
{
    system("cls");
}

// Function to print shop header
void printShopHeader()
{
    setColor(14);
    cout << "\n  ===========================================" << endl;
    cout << "          SKY EXPRESS DELIVERY SHOP" << endl;
    cout << "     Fast, Smart, Automated Deliveries!" << endl;
    cout << "  ===========================================\n" << endl;
    setColor(7);
}

// Function to print the drone battery bar
void printBattery(int battery)
{
    cout << "\n  Battery: [";

     // number of "bars" to show in the progress bar (20 bars total)
    int bars = battery / 5;
// color the bar depending on battery level
    if (battery > 60) setColor(10);// green
    else if (battery > 30) setColor(14);// yellow
    else setColor(12);// red
    // filled portion
    for (int i = 0; i < bars; i++)
    {
        cout << "=";
    }
    setColor(7);
     // empty portion
    for (int i = bars; i < 20; i++)
    {
        cout << " ";
    }

    cout << "] " << battery << "%";
     // text status next to the battery in numbers
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
void printDrone()
{
    setColor(11);
    cout << "\n     ___" << endl;
    cout << "    /   \\" << endl;
    cout << "   | ^_^ |  <- DRONE X-2000" << endl;
    cout << "    \\___/" << endl;
    cout << "   O  O  O" << endl;
    setColor(7);
}

// Function to print flying drone animation
// The frame parameter toggles small differences to simulate motion.
void printFlyingDrone(int frame)
{
    setColor(11);
    if (frame % 2 == 0) {
        cout << "   O  O  O" << endl;
        cout << "     ___" << endl;
        cout << "    /   \\" << endl;
        cout << "   | ^_^ |  ~~ Flying ~~" << endl;
        cout << "    \\___/" << endl;
    }
    else
    {
        cout << "     O O O" << endl;
        cout << "     ___" << endl;
        cout << "    /   \\" << endl;
        cout << "   | ^_^ |  ~~ Flying ~~" << endl;
        cout << "    \\___/" << endl;
    }
    setColor(7);
}

// Function to show shop menu
void showShopMenu()
{
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

// Function to get item details
void getItemDetails(int choice, string& itemName, string& emoji, int& price) {
    if (choice == 1)
    {
        itemName = "Pizza";
        emoji = "";
        price = 15;
    }
    else if (choice == 2)
    {
        itemName = "Burger Meal";
        emoji = "";
        price = 12;
    }
    else if (choice == 3)
    {
        itemName = "Medicine";
        emoji = "";
        price = 25;
    }
    else if (choice == 4)
    {
        itemName = "Books";
        emoji = "";
        price = 20;
    }
    else if (choice == 5)
    {
        itemName = "Electronics";
        emoji = "";
        price = 50;
    }
    else if (choice == 6)
    {
        itemName = "Gift Package";
        emoji = "";
        price = 30;
    }
    else if (choice == 7)
    {
        itemName = "Tacos";
        emoji = "";
        price = 10;
    }
    else if (choice == 8)
    {
        itemName = "Coffee & Snacks";
        emoji = "";
        price = 8;
    }
}

// Function to generate random weather
string getRandomWeather()
{
    int roll = rand() % 100;
    if (roll < 20) return "RAIN";
    else if (roll < 40) return "WINDY";
    else if (roll < 50) return "FOGGY";
    else if (roll < 60) return "STORMY";
    else return "CLEAR";
}

// Return a randomized time-of-day string
string getTimeOfDay()
{
    int hour = rand() % 24;
    if (hour >= 5 && hour < 12) return "Morning";
    else if (hour >= 12 && hour < 17) return "Afternoon";
    else if (hour >= 17 && hour < 21) return "Evening";
    else return "Night";
}
// Function to calculate distance between 1 and 5 km
int calculateDistance() {
    return 1 + (rand() % 5);
}

int main() {
    srand(time(0));
    int battery = 100;
    int totalOrders = 0;
    int successfulDeliveries = 0;
    int delayedDeliveries = 0;
    int totalEarnings = 0;
    bool running = true;

    clearScreen();
    printShopHeader();
    cout << "\n  Welcome to Sky Express Delivery!" << endl;// Welcome screen
    cout << "  Press Enter to start...";
    cin.ignore();// wait for Enter(consumes a newline)
    Sleep(1000);

    // runs while "running" is true
    while (running) {
        clearScreen();
        printShopHeader();

        printDrone();
        printBattery(battery);
        //stats
    cout << "\n  BUSINESS STATISTICS" << endl;
    cout << "  -------------------------------------------" << endl;
    cout << "  Total Orders: " << totalOrders << endl;
    cout << "  Successful: " << successfulDeliveries << " | Delayed: " << delayedDeliveries << endl;
    cout << "  Total Earnings: $" << totalEarnings << endl;
    cout << "  -------------------------------------------" << endl;

        showShopMenu();

        cout << "\n  9. Recharge Drone" << endl;
        cout << "  0. Exit Shop" << endl;
        cout << "\n  Choose an option (0-9): ";
        int choice;
        cin >> choice;
        cin.ignore();// consume newline before getline usage later
        // if user chose an item (1-8) we will continue to order processing,
        // otherwise handle recharge/exit/invalid at that ppoint.
        if (choice >= 1 && choice <= 8) {
        }
        else if (choice == 9) {
    //Recharge branch
    clearScreen();
    printShopHeader();
    printDrone();

    cout << "\n  RECHARGE STATION" << endl;
    cout << "  -------------------------------------------" << endl;
    cout << "  Current battery: " << battery << "%" << endl;

    if (battery >= 90) {
        cout << "\n  Battery is already high!" << endl;
    }
    else {
        cout << "\n  Charging..." << endl;
        int rechargeAmount = 100 - battery;
         // simple simulated recharge animation
        for (int i = 0; i < 5; i++) {
            battery += rechargeAmount / 5;
            if (battery > 100) battery = 100;
            cout << "  Battery: " << battery << "%" << endl;
            Sleep(800);
        }
        cout << "\n  Drone fully recharged!" << endl;
        battery = 100;
    }
    Sleep(2000);

        // RECHARGE finished loop restarts
        }
        else if (choice == 0) {
        // Exit the program cleanly so final report prints
        running = false;
        }
        else {
        cout << "\n  Invalid choice! Press Enter to try again...";
        cin.ignore();
        }

        

        string itemName, emoji;
        int price = 0;
        getItemDetails(choice, itemName, emoji, price);

        string customerName, address;
        cout << "\nEnter your name: ";
        getline(cin, customerName);
        cout << "Enter your address: ";
        getline(cin, address);
        cout << "Any special instructions? (or press Enter): ";
        string instructions;
        getline(cin, instructions);
        //parameters for delivery
        int distance = calculateDistance();
        string timeOfDay = getTimeOfDay();

        clearScreen();
        printShopHeader();

        setColor(14);
        cout << "\n  ORDER DETAILS" << endl;
        setColor(7);
        cout << "  -------------------------------------------" << endl;
        cout << "  Item: " << itemName << endl;
        cout << "  Price: $" << price << endl;
        cout << "  Customer: " << customerName << endl;
        cout << "  Address: " << address << endl;
        cout << "  Distance: " << distance << " km" << endl;
        cout << "  Time: " << timeOfDay << endl;
        cout << "  -------------------------------------------" << endl;
        // preparing and loading animation
        cout << "\n  Preparing order..." << endl;
        Sleep(1000);
        cout << "  Packing item securely..." << endl;
        Sleep(1000);
        cout << "  Loading onto drone..." << endl;
        Sleep(1500);

        printDrone();

        setColor(10);
        cout << "\n  Drone loaded and ready!" << endl;
        setColor(7);
        Sleep(1500);
        // Check weather & decide if delivery will proceed or not
        string weather = getRandomWeather();
        clearScreen();
        printShopHeader();
        cout << "\n  WEATHER CHECK" << endl;
        cout << "  -------------------------------------------" << endl;
        cout << "  Current weather: " << weather << endl;

        bool deliveryCanceled = false;

        if (weather == "RAIN")
        {
            cout << "\n  Heavy rain detected!" << endl;
            cout << "  Delivery delayed due to unsafe flying conditions." << endl;
            cout << "  Refund issued: $" << price << endl;
            deliveryCanceled = true;
            Sleep(3000);
        }
        else if (weather == "STORMY")
        {
            cout << "\n  Storm warning! Delivery canceled." << endl;
            cout << "  Full refund: $" << price << endl;
            deliveryCanceled = true;
            Sleep(3000);
        }
        else if (weather == "WINDY")
        {
            if (battery < 40)
            {
                cout << "\n  Battery too low for windy conditions!" << endl;
                cout << "  Emergency landing and recharge..." << endl;
                battery += 15;
                if (battery > 100) battery = 100;
                cout << "\n  Drone recharged to " << battery << "%" << endl;
                cout << "  Delivery delayed. Please try again later." << endl;
                deliveryCanceled = true;
                Sleep(3000);
            }
            else
            {
                cout << "\n  Strong winds detected. Proceeding with caution..." << endl;
            }
        }
        else if (weather == "FOGGY")
        {
            cout << "\n  Low visibility detected. Activating sensors..." << endl;
            Sleep(2000);
            cout << "  Safe to proceed." << endl;
        }
        else
        {
            cout << "\n  Perfect flying conditions!" << endl;
        }

        Sleep(2000);

        if (deliveryCanceled) {
        totalOrders++;
        delayedDeliveries++;
        cout << "\n  Press Enter to continue...";
        cin.ignore();
        continue;//go back to menu loop
        }

        // Simulate obstacles and battery usage
        bool hasObstacle = (rand() % 100) < 30;
        int batteryUsed = 0;

        clearScreen();
        printShopHeader();
        cout << "\n  DELIVERY IN PROGRESS" << endl;
        cout << "  -------------------------------------------" << endl;
        cout << "  Destination: " << address << endl;
        cout << "  Distance remaining: " << distance << " km" << endl;
        cout << "  -------------------------------------------\n" << endl;

        printFlyingDrone(0);
        Sleep(1000);

        if (hasObstacle)
        {
            cout << "\n  OBSTACLE ALERT!" << endl;
            int obstacleType = rand() % 3;
            if (obstacleType == 0) cout << "  Obstacle: Building" << endl;
            else if (obstacleType == 1) cout << "  Obstacle: Bird flock" << endl;
            else cout << "  Obstacle: Tree" << endl;
            Sleep(1500);
            cout << "  Rerouting... (Extra 5% battery used)" << endl;
            battery -= 5;
            batteryUsed = 5;
        }
        // Delivery progress in stages, showing progress bar each stage
        int stages = 4;
        for (int i = 1; i <= stages; i++)
        {
            clearScreen();
            printShopHeader();
            cout << "\n  DELIVERY IN PROGRESS" << endl;
            cout << "  -------------------------------------------" << endl;

            int progress = (i * 100) / stages;
            cout << "  Progress: [";

            int bars = progress / 5;
            setColor(10);
            for (int j = 0; j < bars; j++) cout << "#";
            setColor(8);
            for (int j = bars; j < 20; j++) cout << "-";
            setColor(7);
            cout << "] " << progress << "%" << endl;

            cout << "  Distance remaining: " << (distance * (stages - i)) / stages << " km" << endl;
            cout << "  -------------------------------------------\n" << endl;

            printFlyingDrone(i);
            if (i == 1) cout << "\n  Status: Taking off..." << endl;
            else if (i == 2) cout << "\n  Status: Cruising..." << endl;
            else if (i == 3) cout << "\n  Status: Approaching destination..." << endl;
            else cout << "\n  Status: Landing..." << endl;

            Sleep(1500);
        }
         // Battery consumption calculation and update
        int extraBattery = (distance * 3) + (10 + rand() % 11);
        battery -= extraBattery;
        batteryUsed += extraBattery;
        if (battery < 0) 
            battery = 0;
    // Show delivery success with details
    clearScreen();
    printShopHeader();

    cout << "\n  DELIVERY SUCCESSFUL!" << endl;
    cout << "\n  Package delivered successfully." << endl;
    cout << "  -------------------------------------------" << endl;
    cout << "  Customer: " << customerName << endl;
    cout << "  Item: " << itemName << endl;
    cout << "  Location: " << address << endl;
    cout << "  Distance: " << distance << " km" << endl;
    cout << "  Battery used: " << batteryUsed << "%" << endl;
    cout << "  Time: " << timeOfDay << endl;
    cout << "  Weather: " << weather << endl;
    cout << "  -------------------------------------------" << endl;

    printBattery(battery);
    totalEarnings += price;

    cout << "\n  Earnings: +$" << price << endl;
    cout << "  Customer satisfaction: " << (80 + rand() % 21) << "%" << endl;

    totalOrders++;
    successfulDeliveries++;
    Sleep(4000);

    cout << "\n  Press Enter to continue...";
    cin.ignore();

    }
    if (battery <= 10)
        cout << "battery is too low to start another delivery";

    clearScreen();
    printShopHeader();
    cout << "\n  FINAL BUSINESS REPORT" << endl;
    cout << "  -------------------------------------------" << endl;
    cout << "  Total Orders: " << totalOrders << endl;
    cout << "  Successful Deliveries: " << successfulDeliveries << endl;
    cout << "  Delayed/Canceled: " << delayedDeliveries << endl;
    if (totalOrders > 0) {
        cout << "  Success Rate: " << (successfulDeliveries * 100) / totalOrders << "%" << endl;
    }
    cout << "  Total Revenue: $" << totalEarnings << endl;
    cout << "  Final Drone Battery: " << battery << "%" << endl;
    cout << "  -------------------------------------------" << endl;

    cout << "\n  Thank you for using Sky Express Delivery!" << endl;
    cout << "  Goodbye!" << endl;

    Sleep(3000);
    return 0;

    return 0;
}

