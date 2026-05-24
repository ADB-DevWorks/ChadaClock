/*
    Adam Brawley
    CS-210 Project One: Chada Clock
    05/22/2026
    Discription: A twelve and twenty-four hour clock
                 User can add time from a menu and
                 Both clocks are displayed side-by-side
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std; // Allows use of the standard libary

// Function declaritions to keep logic listed after main
void DisplayClock(vector<int>& currentTime, bool& shouldExit);
void UserMenu(vector<int>& currentTime, bool& shouldExit);
void IncrementTime(vector<int>& currentTime, int userChoice, bool& shouldExit);
void SetClock(vector<int>& currentTime);
string TwelveHourDisplay(vector<int>& currentTime);
string TwentyFourHourDisplay(vector<int>& currentTime);
string TwoDigit(int time);
vector<string> SplitLines(const string& displayText);

int main()
{
  
    vector<int> currentTime; // Vector to hold hour, minutes, and seconds
    bool shouldExit = false; // Checks if program should end

    SetClock(currentTime); // Sets the initial time of the clock

    while (!shouldExit) {  // Program loop
        DisplayClock(currentTime, shouldExit);
    }
    
}

// Function to set the initial time
void SetClock(vector<int>& currentTime) {  
    int hour;
    int minutes;
    int seconds;

    // Loop to validate input
    while (true) {
        cout << "Please set the clocks time." << endl;
        cout << "Enter the hour." << endl;
        cin >> hour;
        
        //Uses push_back to add values into empty vector
        if (hour >= 0 && hour <= 23) {
            currentTime.push_back(hour);
        }
        else {
            cout << "That time is invalid. Try again" << endl;
            continue;
        }
        cout << "Enter the minutes." << endl;
        cin >> minutes;
        if (minutes >= 0 && minutes < 60) {
            currentTime.push_back(minutes);
        }
        else {
            cout << "That time is invalid. Try again" << endl;
            continue;
        }
        cout << "Enter the seconds" << endl;
        cin >> seconds;
        if (seconds >= 0 && seconds < 60) {
            currentTime.push_back(seconds);
        }
        else {
            // If input is out of range continues to top of loop
            cout << "That time is invalid. Try again" << endl;
            continue;
        }
        break; // Exits loop once clock is set
    }
}

// Function that isolates the 12 hour clock display
// I choose to return a string to use later for formatting
string TwelveHourDisplay(vector<int>& currentTime) {

    int convertToTwelve = currentTime.at(0);
    string timeOfDay = "AM";

    // Conditional to handel rooling ours and "AM/PM"
    if (currentTime.at(0) == 0) {
        convertToTwelve = 12; 
    }

    if (currentTime.at(0) > 12) {
        convertToTwelve = currentTime.at(0) - 12;
    }

    if (currentTime.at(0) >= 12) {
        timeOfDay = "PM";
    }
    

    // Uses a string constructor found on Cplusplus to generate the asterisk boarder
    // TwoDigit function adds a zero in single digit display
    return string(25, '*') + "\n" + "*" 
        + string(3, ' ') + "Twelve Hour Clock" + string(3,' ') + "*" + "\n"
        + "*" + string(7, ' ') + TwoDigit(convertToTwelve) + ":" + TwoDigit(currentTime.at(1)) 
        + ":" + TwoDigit(currentTime.at(2)) + " " + timeOfDay + string(5, ' ') + "*" + "\n"
        + string(25,'*');
        
}

// Returns a string used in display formatting
string TwentyFourHourDisplay(vector<int>& currentTime) {

    return string(25, '*') + "\n" + "*"
        + string(3, ' ') + "24-Hour Clock" + string(3, ' ') + "*" + "\n"
        + "*" + string(7, ' ') + TwoDigit(currentTime.at(0)) + ":" + TwoDigit(currentTime.at(1))
        + ":" + TwoDigit(currentTime.at(2)) + string(8, ' ') + "*" + "\n"
        + string(25, '*');
}

// Helper function to add zero to single digits
string TwoDigit(int time) {
    if (time < 10) {
        return "0" + to_string(time);
    }
    return to_string(time);
}

// Main clock display
void DisplayClock(vector<int>& currentTime, bool& shouldExit) {

    // Assigns functions to string variable for splitting
    string leftDisplay = TwelveHourDisplay(currentTime);
    string rightDisplay = TwentyFourHourDisplay(currentTime);

   // Uses SplitLines to put display strings in a vector for side-by-side displays
    vector<string> leftLines = SplitLines(leftDisplay);
    vector<string> rightLines = SplitLines(rightDisplay);

    // Iterates through vector to output both clocks side-by-side
    for (int i = 0; i < leftLines.size(); i++) {
        cout << leftLines[i]
            << string(6, ' ')
            << rightLines[i]
            << endl;
    }

    UserMenu(currentTime, shouldExit); // Return to menu
}

// Splits display string into individual lines to enable side-by-side display
vector<string> SplitLines(const string& displayText) {

    vector<string> lines;
    string current = ""; // Stores each charactor to form a full line

    // Stores a completed line once a line break is found
    for (char c : displayText) {
        if (c == '\n') {
            lines.push_back(current);
            current = ""; // Reset for next line
        }
        else {
            current += c;
        }
    }

    // Adds final line if the string did not end with a new line
    if (!current.empty()) {
        lines.push_back(current);
    }

    return lines;
}

// Displays menu and takes input options
void UserMenu(vector<int>& currentTime, bool& shouldExit) {
    int userChoice;

    cout << string(25, '*') << endl; 
    cout << "*  " << "1-Add One Hour" << "       *" << endl;
    cout << "*  " << "2-Add One Minute" << "     *" << endl;
    cout << "*  " << "3-Add One Second" << "     *" << endl;
    cout << "*  " << "4-Exit Program" << "       *" << endl;
    cout << string(25, '*') << endl;

    while (true) { // Validates input
        cin >> userChoice;
        if (userChoice < 1 || userChoice > 4) {
            cout << "Invalid option" << endl;
            continue;
        }
        else {
            break;
        }
 
    }

    IncrementTime(currentTime, userChoice, shouldExit);

}

// Uses input from the menu to increment the clock
void IncrementTime(vector<int>& currentTime, int userChoice, bool& shouldExit) {

    if (userChoice == 1) {
        if (currentTime.at(0) == 23) { // Hour roll over from 23 to 0
            currentTime.at(0) = 0;
        }
        else {
            currentTime.at(0)++; // Adds one hour
        }
    }
    else if (userChoice == 2) {
        if (currentTime.at(1) == 59) { // Minute roll over
            currentTime.at(1) = 0;
            currentTime.at(0)++; // Increments hour after max minutes
        }
        else {
            currentTime.at(1)++; // Adds on minute
        }
    }
    else if (userChoice == 3) {
        if (currentTime.at(2) == 59) { // Seconds roll over
            currentTime.at(2) = 0;
            currentTime.at(1)++; // Increments minutes after max seconds
        }
        else {
            currentTime.at(2)++;
        }
    }
    // Returns back to main with shouldExit to end program loop
    else if (userChoice == 4) {
        shouldExit = true;
        cout << "Thank you for using Chada Clock!" << endl;
        return;
    }

}



