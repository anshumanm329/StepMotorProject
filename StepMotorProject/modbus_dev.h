#pragma once
#include <iostream>
#include "modbus.h"
class modbus_dev
{
	private:
		modbus_t* ctx{ nullptr };//A modbus device
	public:
		int connect();//Connect the device
		virtual int write_register(int addr, uint16_t val);//Write to a register
		virtual int write_bit(int addr, int val);//Write to a bit
		virtual int read_holding_register(int addr); //Read a holding register
		virtual int read_input_register(int addr); //Read an input register
		virtual ~modbus_dev() {
			modbus_free(ctx);
		}
};

