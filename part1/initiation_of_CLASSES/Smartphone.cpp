#include "Smartphone.h"

Smartphone::Smartphone() {
	model = "";
	specs = SmSpec{};
	price.setPrice(0);
	price.setCurrency(RUB);
}

Smartphone::Smartphone(string model, double price, SmSpec spec, Mtype currency) {
	this->model = model;
	this->specs = spec;
	this->price.setPrice(price);
	this->price.setCurrency(currency);
}

Smartphone& Smartphone::operator=(const Smartphone& other) {
	if (this != &other) {
		model = other.model;
		price = other.price;
		specs = other.specs;
	}
	return *this;
}

string Smartphone::getModel() const {
	return model;
}

Price Smartphone::getPrice() const {
	return price;
}

SmSpec Smartphone::getSpec() const {
	return specs;
}

void Smartphone::setPrice(double c, Mtype def) {
	price.setPrice(c);
	price.setCurrency(def);
}

void Smartphone::Print() const {
	cout << model << endl;
	cout << "Price: " << price.getAmount() << " " << MtypeName[price.getCurrency()] << endl;
	specs.print();
	cout << endl;
}
