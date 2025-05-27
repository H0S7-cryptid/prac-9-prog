#pragma once
#include"Product.h"
using namespace std;

class Catalog {
private:
	list<Product> smartphones;
	int lenght = 0;
public:
	void addSmartphone(const Product& phone);
	void addSmartphone(Product&& phone);
	Product getSmartphone(string model);
	int Length();
	Product search(const Smartphone& searchSmartphone);
	Product search(string model, Manufacturer manufacturer);
	vector<Product> search(Smartphone& searchSmartphone);
};
