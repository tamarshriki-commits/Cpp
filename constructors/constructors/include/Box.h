#pragma once
#include <String>
#include <iostream>

class Box
{
public:
	Box() = default;
	Box(int weight, const std::string& name);
	int getWeight() const { return weight_; }
	std::string getName() const { return name_; }
	void setWeight(int weight) { weight_ = weight; }
	void setName(const std::string& name) { name_ = name; }
private:
	int weight_;
	std::string name_;
};

