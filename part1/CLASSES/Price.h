#ifndef PRICE
#define PRICE

#include "NEEDED_LIB.h"

class Price {
private:
	double price;		// Цена 
	Mtype currency;		// Валюты
	void doPrice(double price);
	void tryCurrency(Mtype setter);
public:
	// Конструкторы класса - обычный (без параметров) и с параметрами
	Price();
	Price(double a, const Mtype& c);

	// Оператор присваивания (предусмотренный)
	Price& operator=(const Price& other);

	// Методы установки значений полей класса
	void setPrice(double price);
	void setCurrency(Mtype mtype);

	// Методы получения значений полей класса
	double getAmount() const;
	Mtype getCurrency() const;

	// Метод перевода валют из одной цены в другую
	Price convertTo(const Mtype& newCurrency, double exchangeRate) const;

	// Метод вывода значения полей класса
	void print() const;
};

#endif 
