#include "modbus_dev.h"
#include "modbus.h"
#include <iostream>

using namespace std;

int modbus_dev::connect()
{
    //Initialize a connection
    ctx = modbus_new_rtu("COM4", 115200, 'N', 8, 1);
    if (ctx == nullptr) {
        cout << "Failed to create instance" << endl;
        return -1;
    }
    modbus_set_slave(ctx, 3); //Set slave-id to 1
    if (modbus_connect(ctx) == -1) {
        cout << "Connection failed" << endl;
        modbus_free(ctx);
        return -1;

    }
    cout << "Connection status: Connected!" << endl;
    return 0;
}
int modbus_dev::write_register(int addr, uint16_t val) {

    //To write data
    // Assuming that user input has already been taken for this and address is also set
    if (modbus_write_register(ctx, addr, val) == -1) {
        cout << "Failed to write" << endl;
        return -1;
    }
    cout << "Value: " << val << " written to register " << addr << endl;
    return 0;
}
int modbus_dev::write_bit(int addr, int val) {
    //Here value can be either 0 or 1
    if (val != 0 && val != 1) {
        cout << "Bit can't be written with these values use either 0 or 1!" << endl;
        return -1;
    }
    if (modbus_write_bit(ctx, addr, val) == -1) {
        cout << "Failed to write bits" << endl;
        return -1;
    }
    cout << "Coil " << addr << " written to successfully" << endl;
    return 0;    
}
int modbus_dev::read_holding_register(int addr) {
    //Assuming that the register address has already been specified
    uint16_t readbacks[20]{};
    if (modbus_read_registers(ctx, addr, 1, readbacks) == -1) {
        cout << "Failed to read" << endl;
        return -1;
    }
    cout << "Read successfully" << endl;
    cout << "The data from register: " << addr << " is " << readbacks[0] << endl;
    return static_cast<int>(readbacks[0]);
}
int modbus_dev::read_input_register(int addr) {
    //Assuming the address has already been given
    uint16_t readbacks[20]{};
    if (modbus_read_input_registers(ctx, addr, 1, readbacks) == -1) {
        cout << "Failed to read" << endl;
        return -1;
    }
    cout << "Input register " << addr << " contains " << readbacks[0] << endl;
    return static_cast<int>(readbacks[0]);
}
