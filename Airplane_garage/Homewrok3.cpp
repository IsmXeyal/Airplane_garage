#include <iostream>
#include <string>
#include <cassert>

using namespace std;

#include"Airplane.h"
#include"Garage.h"

int main() {

	Airplane* c1 = new Airplane("Model_1", Colors::Red,  5.3, 235);
	Airplane* c2 = new Airplane("Model_2", Colors::Black, 7.3, 190);
	Airplane* c3 = new Airplane("Model_3", Colors::White, 6.2, 150);
	Airplane* c4 = new Airplane("Model_4", Colors::Green, 8.4, 456);
	Airplane* c5 = new Airplane("Model_5", Colors::White, 5.4, 126);

	Airplane** airplanes = new Airplane* [5] {c1,c2, c3, c4, c5};

    Garage garage("Turkish Airlines", "123 Main St", airplanes, 5);

    garage.print();

	//cout << "\tGet_Airplanes_Capacity_Greater_Than_num" << endl;
	//Airplane** capacityGreaterThan180 = garage.getAirplanesCapacityGreaterThan(180);
	//for (int i = 0; i < garage.GetCount(); ++i) {
	//	capacityGreaterThan180[i]->print();
	//}
	//delete[] capacityGreaterThan180;


	Airplane** airplanesByColor = garage.getAirplanesByColor(Colors::White);
	if (airplanesByColor != nullptr) {
		cout << "\tGet_Airplanes_By_Color" << endl;
		for (size_t i = 0; airplanesByColor[i] != nullptr; i++) {
			airplanesByColor[i]->print();
		}
	}
	else
		cout << "No airplanes found with the given COLOR!" << endl;


	return 0;
}