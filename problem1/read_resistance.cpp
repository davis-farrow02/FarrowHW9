// code name: read_resistance.cpp
// code by: Davis Farrow
//
// CPE 422 HW 9 problem 1
// this code determines the resistance of the bottom resistor in a voltage divider. Use a 10kΩ 
// as the top resistor. The bottom resistor R should be in the range of 100Ω to 100kΩ. Usees 
// class AnalogIn. Application determines the value of R and prints out the resistance in Ohms 
// to the nearest Ohm. 
//
// how to invoke:
// debian@beaglebone:~$ ./read_resistance

#include<iostream>
#include "AnalogIn.h"
using namespace std;

int main() {
	AnalogIn AIN0(0);
	float R1 = 10000.0, Vref = 1.8;
        float R, Adc, Vout;

	cout << "Using AIN" << AIN0.getNumber() << " to read analog value." << endl;
	
	cout << "Measuring resistance ..." << endl;

	Adc = AIN0.readAdc();
	cout << "ADC value is: " << Adc << endl;
	cout << endl;
	
	// Voltage Divider Formula: Vin = 1.8V
	// Vout = Vin*(R2/(R1+R2))
	Vout = AIN0.Adc2Volt(Adc, Vref);
	R = R1*(Vout/Vref)/(1-(Vout/Vref));
	if (R >= 100000) {
		cout << "Bottom resistor out of range 100-100K Ohms" << endl;
	} else if (R <= 100) {
	       cout << "Bottom resistor out of range 100-100K Ohms" << endl;	       
	} else {
		if (R >= 1000.0) {
			cout << "Resistance: " << ((int)R)/1000 << "K Ohms" << endl;
		} else {
			cout << "Resistance: " << (int)R << " Ohms" << endl; 
		}
	}
}
