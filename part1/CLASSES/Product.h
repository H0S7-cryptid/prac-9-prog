#ifndef PRICE_AND_AVAIL
#define PRICE_AND_AVAIL

#include "Price.h"
#include "Smartphone.h"

class Product {
private:
	Smartphone& founded;
	Price price;
	ProdAvail PA;

	void Init(Price p, ProdAvail pa, Smartphone& f);
	void Init(double p, Mtype cur, ProdAvail pa, Smartphone& f);
public:
	// Конструктор (с параметрами и значениями по умолчанию)
	Product(Smartphone& f);
	Product(Price price, ProdAvail prodavail, Smartphone& founded);
	Product(double price, Mtype cur, ProdAvail prodavail, Smartphone& f);

	// Оператор присваивания
	Product& operator=(const Product& other);

	// Геттеры (получение данных о цене, наличии и, при наличии смартфона)
	Price getPrice() const;
	ProdAvail getAvail() const;
	Smartphone& getSmartphone() const;

	// Метод вывода полей класса
	void print() const;

	// Метод ввода значений для полей
	void setPrice(Price price);
	void setAvail(ProdAvail pa);
};

#endif 
