#include "Box.h"

Box::Box(int weight, const std::string& name) {
	weight_ = weight;
	name_ = std::string(name);
}

int Box::getWeight() const {
	return weight_;
}

const std::string& Box::getName() const {
	return name_;
}

void Box::setWeight(int weight) {
	weight_ = weight;
}

void Box::setName(const std::string& name) {
	name_ = name;
}