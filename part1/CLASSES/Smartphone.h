#ifndef SMARTPHONE
#define SMARTPHONE

#include "Smartphone_Char-s.h"

using namespace std;

class Smartphone {
private:
	string model;
	SmSpec specs;
public:
	// Конструкторы класса
	Smartphone();
	Smartphone(string model, SmSpec spec);

	// Оператор присваивания
	Smartphone& operator=(const Smartphone& other);

	// Геттеры
	string getModel() const;
	SmSpec getSpec() const;

	// Вывод информации о телефоне в поток
	void Print() const;
};

#endif
