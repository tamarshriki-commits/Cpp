#include "Box.h"

int main(){
	int weight = 3;
	std::string name = "box";
	// test for default constructor, get and set
	Box box1;
	box1.setWeight(weight);
	box1.setName(name);
	if (box1.getWeight() == weight and box1.getName() == name) {
		std::cout << "default constructor, get and set methodes work!" << '\n';
	}
	else {
		std::cout << "default constructor, get and set methodes DONT work!" << '\n';
	}
	// test for second constructor
	Box box2 = Box(weight, name);
	if (box2.getWeight() == weight and box2.getName() == name) {
		std::cout << "second constructor work!";
	}
	else {
		std::cout << "second constructor DONT work!";
	}
	return 0;
}
