#include "Product.h"

Product::Product(Smartphone& f) : founded{f} {
	price = Price{};
	PA = UNDEFPA;
}

Product::Product(Price price, ProdAvail prodavail, Smartphone& founded)
	: price{ price }, PA{ prodavail }, founded{ founded } {
	try {
		Init(price, prodavail, founded);
	}
	catch (std::exception) {
		this->price.setPrice(0);
		this->price.setCurrency(RUB);
	}
}

Product::Product(double price, Mtype cur, ProdAvail prodavail, Smartphone& f)
	: price{ price, cur }, PA{ prodavail }, founded{ founded } {
	try {
		Init(price, cur, prodavail, founded);
	}
	catch (std::exception) {
		this->price.setPrice(0);
		this->price.setCurrency(RUB);
	}
}

Product& Product::operator=(const Product& other) {
	if (this != &other) {
		price = other.price;
		PA = other.PA;
		founded = other.founded;
	}
	return *this;
}

void Product::Init(Price p, ProdAvail pa, Smartphone& f) {
	if (pa == OutOfStock) throw std::exception();
	PA = pa;
	price = p;
	founded = f;
}

void Product::Init(double p, Mtype cur, ProdAvail pa, Smartphone& f) {
	if (pa == OutOfStock) throw std::exception();
	PA = pa;
	price.setPrice(p);
	price.setCurrency(cur);
	founded = f;
}

Price Product::getPrice() const {
	return price;
}

ProdAvail Product::getAvail() const {
	return PA;
}

Smartphone& Product::getSmartphone() const {
	return founded;
}

void Product::print() const {
	std::cout << "Characteristics:" << std::endl;
	founded.Print();
	std::cout << "Price: " << price.getAmount() << " " << MtypeName[price.getCurrency()] << std::endl;
	std::cout << ProdStrStatus[PA] << std::endl;
	std::cout << std::endl;
}

void Product::setPrice(Price price) {
	this->price = price;
}

void Product::setAvail(ProdAvail pa) {
	this->PA = pa;
}
