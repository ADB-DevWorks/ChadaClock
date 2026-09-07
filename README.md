# ChadaClock — Project One

A simple C++ console application that displays the current time in both 12‑hour and 24‑hour formats. This project was created as part of an introductory programming assignment focused on modular design, user input handling, and formatted console output.

---

## Program Overview

The ChadaClock program displays two synchronized clocks:

### 12‑Hour Clock  
Shows hours, minutes, seconds, and AM/PM.

### 24‑Hour Clock  
Shows hours, minutes, and seconds in military time.

The user interacts with the program through a menu that allows:

1. Add one hour  
2. Add one minute  
3. Add one second  
4. Exit the program  

Each action updates both clocks simultaneously.

---

## How to Run

### Prerequisites
- Visual Studio (recommended)  
- A C++ compiler (MSVC, Clang, or GCC)

### Steps
1. Clone the repository:
   ```bash
   git clone https://github.com/ADB-DevWorks/ChadaClock.git
   ```
2. Open the solution file:
   ```
   ProjectOne_ChadaClock.slnx
   ```
3. Build and run the project in Visual Studio.

---

## Learning Objectives

This project demonstrates:

- Modular C++ program structure  
- Time manipulation using arithmetic  
- Console formatting  
- Basic user input validation  
- Loop‑driven menu systems  

---

## Future Improvements

Potential enhancements include:

- Real‑time ticking using `std::chrono`  
- Digital clock UI using ASCII art  
- Alarm or timer functionality  
- Refactoring into classes (`Clock`, `Time`, `Menu`)  

---

## License

This project is part of coursework and is provided for educational use.

