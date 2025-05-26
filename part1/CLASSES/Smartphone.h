#ifndef SMARTPHONE_CHARS
#define SMARTPHONE_CHARS

#include "NEEDED_LIB.h"

class SmSpec {
private:
	Manufacturer manufacturer; Color color;
	Manufacturer cpu; Os os; Protection protection;
	short ram;
	short storage;
	float display;
	short ncams;
public:
	// Конструкторы
	SmSpec();
	SmSpec(Manufacturer m, Color c, short r, short st, 
		Manufacturer cp, Os o, float d, short nc, Protection p);

	// Геттеры
	Color getColor() const;
	Manufacturer getCPU() const;
	Manufacturer getManufacturer() const;
	Protection getProtection() const;
	Os getOS() const;
	float getDisplay() const;
	short getRAM() const;
	short getStorage() const;
	short getNCams() const;

	// оператор присваивания
	SmSpec& operator=(const SmSpec& sp);

	// метод установки значений
	void setSpecs(Manufacturer m, Color c, short r, short st,
		Manufacturer cp, Os o, float d, short nc, Protection p);
	void setSpecs(SmSpec& spec);

	// Метод вывода полей класса
	void print() const;
};

#endif
