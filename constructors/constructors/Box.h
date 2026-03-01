#pragma once
#include <String>
#include <iostream>

class Box
{
public:
	Box() = default;
	Box(int weight, const std::string& name);
	int getWeight() const;
	const std::string& getName() const;
	void setWeight(int weight);
	void setName(const std::string& name);
private:
	int weight_;
	std::string name_;
};

