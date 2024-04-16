#include "StepMotor.h"
#include <iostream>

using namespace std;

bool StepMotor::stop()
{
    int rc = StepMotor::write_register(512, 0);
    int rc2 = StepMotor::write_register(513, 0);
    if (rc == -1||rc2==-1)
        return false;
    return true;
}
bool StepMotor::forward()
{
    if (StepMotor::read_holding_register(514) != 1) {
        cout << "Shielding is not open, going forward" << endl;
        do {
            int rc = StepMotor::write_register(512, 1);
            int rc2 = StepMotor::write_register(513, 0);
            if (rc == -1 || rc2 == -1)
                return false;
            return true;
        } while (StepMotor::read_holding_register(514) != 1);
        StepMotor::stop();
        
    }
    else {
        cout << "Shielding is open can't move forward" << endl;
        if (StepMotor::stop()) {
            cout << "Stopping movement" << endl;
        }
        else {
            cout << "Program can't stop step motor, disconnect power supply" << endl;
        }
        return false;
    }
}
bool StepMotor::reverse()
{
    
    if (StepMotor::read_holding_register(515) != 1) {
        
         cout << "Shielding is not closed, going reverse" << endl;
         int rc = StepMotor::write_register(512, 0);
         int rc2 = StepMotor::write_register(513, 1);
         if (rc == -1 || rc2 == -1)
             return false;           
        
       
        return true;
    }
    else {
        cout << "Shielding is closed, can't reverse!" << endl;
        if (StepMotor::stop()) {
            cout << "Stopping movement" << endl;
        }
        else {
            cout << "Can't stop movement, please disconnect power supply to motor" << endl;
        }
        return false;
    }
    
}
