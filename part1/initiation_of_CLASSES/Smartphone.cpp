#include "Smartphone.h"

Smartphone::Smartphone() {
	model = "";
	specs = SmSpec{};
}

Smartphone::Smartphone(string model, SmSpec spec) {
	this->model = model;
	this->specs = spec;
}

Smartphone& Smartphone::operator=(const Smartphone& other) {
	if (this != &other) {
		model = other.model;
		specs = other.specs;
	}
	return *this;
}

string Smartphone::getModel() const {
	return model;
}

SmSpec Smartphone::getSpec() const {
	return specs;
}

void Smartphone::Print() const {
	cout << model << endl;
	specs.print();
}
