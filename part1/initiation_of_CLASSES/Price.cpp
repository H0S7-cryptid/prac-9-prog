#include "Price.h"

Price::Price() : price{ 0.0 }, currency{ RUB } {}

Price::Price(double a = 0.0, const Mtype& c = RUB) : price(a), currency(c) {
	setPrice(a);
}

Price& Price::operator=(const Price& other) {
	if (this != &other) {
		this->price = other.price;
		this->currency = other.currency;
	}
	return *this;
}

void Price::doPrice(double price) {
	if (this->currency == RUB && (price > 4000000 || price < 0)) throw std::exception("Incorrect price value!");
	if (this->currency == USD && (price > 1000 || price < 0)) throw std::exception("Incorrect price value!");
	if (this->currency == EUR && (price > 900 || price < 0)) throw std::exception("Incorrect price value!");
	this->price = price;
}

void Price::setPrice(double price) {
	try {
		doPrice(price);
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
		this->price = 1;
		return;
	}
	this->price = price;
}

void Price::tryCurrency(Mtype setter) {
	if ((int)setter < 0 || (int)setter > 2) throw std::exception("Incorrect money type value!");
	currency = setter;
}

void Price::setCurrency(Mtype mtype) {
	try {
		tryCurrency(mtype);
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
		currency = RUB;
	}
}

double Price::getAmount() const {
	return price;
}

Mtype Price::getCurrency() const {
	return currency;
}

Price Price::convertTo(const Mtype& newCurrency, double exchangeRate) const {
	return Price(price * exchangeRate, newCurrency);
}

void Price::print() const {
	std::cout << price << " " << MtypeName[currency] << std::endl;
}
