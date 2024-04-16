// StepMotorProject.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "modbus.h"
#include "modbus_dev.h"
#include "StepMotor.h"

using namespace std;

int main()
{
    cout << "Step motor operations!" << endl;
    StepMotor motor1{};
    if (motor1.connect() == -1) {
        cout << " Failed to connect " << endl;
        return -1;
    }
    cout << "Connected to relay and relay controls the motor" << endl;
    /*if (motor1.forward()) {
        cout << "Motor rotating forward" << endl;
    }*/
    char choice{};
    do {
        cout << "1. Forward motion" << endl;
        cout << "2. Reverse motion" << endl;
        cout << "3. Stop" << endl;
        int option{};
        cin >> option;
        switch (option) {
        case 1: {
               
            
            if (motor1.forward())
            {
                cout << "Forward motion" << endl;
                break;
            }
            else {
                cout << "Failed" << endl;
                break;
            }
        }
        case 2:
        {
            if (motor1.reverse()) {
                cout << "Reverse motion" << endl;
                break;
            }
            else {
                cout << "Failed" << endl;
                break;
            }

        }
        case 3:
        {
            if (motor1.stop()) {
                cout << "Stopped" << endl;
                break;
            }
            else {
                cout << "Couldn't stop" << endl;
                break;
            }
        }
        default: {
            cout << "Invalid choice try again" << endl;
            break;
        }
        }
        cout << "Enter q to quit" << endl;
        cin >> choice;
    

    } while (choice!='q'&&choice!='Q');
    if (motor1.stop())
        cout << "Stopping operation" << endl;
    else
        cout << "Something is wrong disconnect power" << endl;
    
    return 0;
}

