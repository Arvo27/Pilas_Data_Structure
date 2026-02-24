/**
 * @file main.cpp
 * @brief Menu-driven test program for the Stacks template class.
 * * This program validates the functionality of the Stacks class with 
 * different data types, including integers, strings, and custom Vectors.
 */

#include <iostream>
#include <string>
#include "Stacks.hpp"
#include "Vector.hpp"

using namespace std;

/**
 * @brief Displays the interactive menu options to the user.
 */
void displayMenu() {
    cout << "\n--- Dynamic Stack Test Menu ---" << endl;
    cout << "1. Push element" << endl;
    cout << "2. Pop element" << endl;
    cout << "3. Show top element" << endl;
    cout << "4. Get current size" << endl;
    cout << "5. Get current capacity" << endl;
    cout << "6. Clear stack" << endl;
    cout << "7. Print stack (method)" << endl;
    cout << "8. Print stack (operator<<)" << endl;
    cout << "9. Run Multi-Type Test (int, string, Vector)" << endl;
    cout << "0. Exit" << endl;
    cout << "Choice: ";
}

/**
 * @brief Main execution loop.
 * * Manages an int-based stack via user input and performs a multi-type 
 * validation to ensure template robustness with complex objects like Vector.
 *
 */
int main() {
    Stacks<int> intStack;
    int choice, value;

    do {
        displayMenu();
        if (!(cin >> choice)) break;

        try {
            switch (choice) {
                case 1:
                    cout << "Enter integer to push: ";
                    cin >> value;
                    intStack.push(value);
                    cout << "Element pushed." << endl;
                    break;
                case 2:
                    intStack.pop();
                    cout << "Element popped." << endl;
                    break;
                case 3:
                    cout << "Top element: " << intStack.top() << endl;
                    break;
                case 4:
                    cout << "Stack size: " << intStack.size() << endl;
                    break;
                case 5:
                    cout << "Current capacity: " << intStack.getCapacity() << endl;
                    break;
                case 6:
                    intStack.clear();
                    cout << "Stack cleared." << endl;
                    break;
                case 7:
                    intStack.print();
                    break;
                case 8:
                    cout << intStack;
                    break;
                case 9: {
                    cout << "\n--- Multi-Type Validation ---" << endl;
                    
                    // Type 1: string validation
                    Stacks<string> sStack;
                    sStack.push("Hello");
                    sStack.push("World");
                    cout << "String Stack: " << sStack;

                    // Type 2: Vector validation
                    // Requires Vector copy constructor and assignment operator.
                    //
                    Stacks<Vector> vStack;
                    vStack.push(Vector(3, 1.5));
                    vStack.push(Vector(2, 9.0));
                    cout << "Vector Stack:\n" << vStack;
                    
                    cout << "Multi-type test completed successfully." << endl;
                    break;
                }
                case 0:
                    cout << "Exiting..." << endl;
                    break;
                default:
                    cout << "Invalid choice." << endl;
            }
        } 
        /**
         * @note Exception handling for empty stack operations.
         */
        catch (const Stacks<int>::StackEmpty& e) {
            cerr << e.whats() << endl;
        } catch (const char* msg) {
            cerr << "Runtime Error: " << msg << endl;
        } catch (...) {
            cerr << "An unexpected error occurred." << endl;
        }
    } while (choice != 0);

    return 0;
}