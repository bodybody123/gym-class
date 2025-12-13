#include <iostream>
#include <string>

#include "../models/ClassSession.hpp"
#include "../Lists/ClassSessionList.hpp"


using namespace std;

string Menu[] = {
    "View All Available Classes",
    "View My Enrolled Classes",
    "Unroll from a Class",
    "Exit App"
};

void displayMainMenu() {
    cout << "=== Main Menu ===" << endl;
    for (size_t i = 0; i < sizeof(Menu)/sizeof(Menu[0]); ++i) {
        cout << i + 1 << ". " << Menu[i] << endl;
    }
    cout << "Please select an option: ";
}

void displayClassDetail(ClassSession* classSession) {
    printClassSessionDetails(classSession);
}

void startConsoleUI() {
    while (true)
    {
        displayMainMenu();
        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Displaying all available classes..." << endl;
                // Functionality to display all classes would go here
                break;
            case 2:
                cout << "Displaying my enrolled classes..." << endl;
                // Functionality to display enrolled classes would go here
                break;
            case 3:
                cout << "Unrolling from a class..." << endl;
                // Functionality to unroll from a class would go here
                break;
            case 4:
                cout << "Exiting the application. Goodbye!" << endl;
                return;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
    
}