#pragma once
#include <iostream>
#include "modbus.h"
#include "modbus_dev.h"
class StepMotor: public modbus_dev
{
	private:
		
	  
	public:
		//Functions 
		virtual bool forward();
		virtual bool reverse();
		virtual bool stop();
		virtual ~StepMotor() = default;

};

