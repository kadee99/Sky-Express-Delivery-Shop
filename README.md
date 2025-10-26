# Sky-Express-Delivery-Shop


---

## Title and Team Information

**Project title:** Sky-Express-Delivery-Shop

**Team members and roles**

* **Member 1 :** Muhammad Musa Bin Mansha — Role: Programmer 2, documenter and Ui ideas
* **Member 2 :** Kareem Azam — Role: Programmer 1, Logic Designer
---

## Overview / Problem Description

**Short summary:**
This C++ console program simulates an automated drone delivery shop. Users select items to order, the simulator generates random environmental conditions (weather, distance, time of day), animates a drone delivery with battery usage and obstacle handling, and tracks simple business statistics (orders, successful deliveries, delays, earnings).

**Real-world relevancy:**

* Drone delivery is an emerging logistics technology; simulating it helps us in exploring operational limitations such as battery management, weather impacts on the drone delivery, etc.
* The simulator shows decision-making under uncertain conditions such as random weather, obstacles and demonstrates how automated systems can handle safety checks such as canceling or delaying the delivery in stormy weather as well as emergency recharging.

---

## Program Design / Logic

### Functions implemented

* `setColor(int color)` — set console text color (Windows API).
* `clearScreen()` — clear the console screen.
* `printShopHeader()` — prints the shop header and title.
* `printBattery(int battery)` — renders a battery progress bar and status text.
* `printDrone()` — prints a static drone ASCII art.
* `printFlyingDrone(int frame)` — prints small frame-differenced flying drone animation.
* `showShopMenu()` — displays the item menu.
* `getItemDetails(int choice, string &itemName, string &emoji, int &price)` — returns item metadata for menu choices.
* `getRandomWeather()` — returns randomized weather string (`CLEAR`, `RAIN`, `WINDY`, `FOGGY`, `STORMY`).
* `getTimeOfDay()` — returns a randomized time-of-day string (`Morning`, `Afternoon`, `Evening`, `Night`).
* `calculateDistance()` — returns a randomized integer distance between 1 and 5 km.
* `main()` — program entry point and controller for menu, order processing, delivery simulation, and final report.

### Logic flow (high level)

1. `main()` initializes random seed and business statistics.
2. Show welcome screen, then enter a main loop that:

   * Displays header, drone, battery, business statistics and menu (`showShopMenu()`).
   * Accepts user choice (item 1–8, recharge 9, exit 0).
   * If recharge chosen: simulate charging and set `battery = 100`.
   * If item chosen: collect customer name/address, generate `distance`, `timeOfDay`, and `weather`.
   * Perform pre-flight safety checks: if `weather == STORMY` or heavy `RAIN`, cancel and refund; if `WINDY` and battery low, delay and recharge.
   * If proceed: simulate delivery stages with `printFlyingDrone(frame)` and progress bars; check for obstacles and update battery accordingly.
   * Deduct battery usage, update statistics (`totalOrders`, `successfulDeliveries`, `delayedDeliveries`, `totalEarnings`).
   * Return to menu until user chooses Exit.
3. On exit, print final business report.

### How random environmental factors are simulated

* `srand(time(0))` seeds the RNG in `main()`.
* `getRandomWeather()` uses `rand() % 100` to return weather categories with different probabilities.
* `calculateDistance()` uses `1 + (rand() % 5)` for a uniform distance between 1 and 5 km.
* `getTimeOfDay()` picks an hour with `rand() % 24` and maps it to a time-of-day bucket.
* Obstacles: `hasObstacle` is determined by `(rand() % 100) < 30` (30% chance).
* Customer satisfaction is randomized as `(80 + rand() % 21)`.

---

## Execution Instructions

### Requirements / Assumptions

* **Platform:** Windows (the program uses `<windows.h>`, `SetConsoleTextAttribute`, and `Sleep()` — these are Windows-specific).
* **Compiler:** A Windows-based C++ compiler(e.g., MinGW `g++`, Microsoft Visual C++).
* **Assumptions:**

  * Console supports ANSI-like color via `SetConsoleTextAttribute`.
  * Program run in a console with enough width to display ASCII art and progress bars.
  * No file I/O or arrays are required for the current version.

### How to compile (example)

Compile with Microsoft Visual Studio (create a Win32 Console project and add the `.cpp` file).

> Note: If using an environment without `<windows.h>`, color and `Sleep()` calls must be removed or replaced with cross-platform alternatives before compiling on Linux/macOS.

### How to run

From a command prompt:

```bash
DeliveryDroneSimulator.exe
```

### Demo input/output :

**Input:**
```
<img width="1044" height="744" alt="image" src="https://github.com/user-attachments/assets/950c2bba-2723-4c4b-a709-949993f6480e" />
```
**Output Screen 1:**
```
<img width="611" height="646" alt="Screenshot 2025-10-26 201223" src="https://github.com/user-attachments/assets/da98e36b-0661-422e-b9a4-f4bd28a49df6" />
```
**Output Screen 2:**
```
<img width="538" height="538" alt="Screenshot 2025-10-26 201229" src="https://github.com/user-attachments/assets/770ac4fd-bfd3-44b1-a3de-ccdd3923e0f8" />
```
**Output Screen 3:**
```
<img width="544" height="627" alt="Screenshot 2025-10-26 201238" src="https://github.com/user-attachments/assets/fabf26e0-c747-4df2-a6e3-f25968b6f809" />

```

## Team Collaboration Summary :

### Division of roles

* **Logic Designer/Programmer1:** Kareem Azam :
 Designed Logic and implemented functions; Created flowchart for maintaining the program with ease.
* **Documenter/Programmer2** Muhammad Musa Bin Mansha :
 Documented the program; Added commenting. Enhanced Ui and gave ideas for adding animations and improving interactibility.

### Evidence of Git usage

* **Branch names used :**

  *itsmusa33-patch-1
  *kadee99-patch-1
* **Key commits :**

* Commit history screenshot: `<img width="1545" height="862" alt="image" src="https://github.com/user-attachments/assets/2d7819f7-4622-4126-aa10-cf3c5bd11556" />`
* Branches listing screenshot: `<img width="1629" height="773" alt="image" src="https://github.com/user-attachments/assets/90e38785-6f02-46d1-8331-0594d11d1206" />
`

---

## AI Tool Reflection 

* **Tool used:**
  * ChatGPT
    
**What tasks it helped with:**  
-Helped to add colours in the program by telling about the windows api(`<windows.h>`)  
-Helped by telling about `System.cls` function which clears screen(this removed the need for scrolling in the program)  
-Gave idea for making the drone move by giving suggestion to add the `frame` variable  
-Gave the idea that adding a changing battery bar will make the program look more interactive  
-Helped with summarizing the functions used in the code  
-taught how to add headings/structure and images in the README.md file  
  

* **Brief reflection:**

  * What we learned from using AI tools:
    AI helped us by giving us the information we were not aware of; e.g. it told how to add colour to output.
    This shows that Ai can be used as a knowledge booster and that knowledge can be used to think about further solutions.
    Futhermore, it gave us some new ideas that we could work on; e.g. Battery Bar moving.
    It can save a lot of time and that saved time can be used for more productive tasks; for example,
    It saved time by listing the functions that were used in the program.
    Therefore, it can be a great tool if used wisely.
  * Limitations noticed:
    Sometimes, it can give wrong suggestions which can interfere with the program's usability and interactibility.
    Therefore, it is suggested to first research about Ai suggestions from credible resources before thinking about how to apply them.
    
    

---

## Future Improvements

**Improve System Interaction :**
In future updates, features such as drone maintenance logs, delivery history, or automated recharge management could also be explored to make the simulation more dynamic and lifelike.

**Add Data Persistence:**
Implement a file logging system to store order details, earnings, and statistics between sessions.
This would require learning how to use file input/output streams and basic data serialization techniques.

---
