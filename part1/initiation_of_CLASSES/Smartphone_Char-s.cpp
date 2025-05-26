#include "Smartphone_Char-s.h"

SmSpec::SmSpec() {
	manufacturer = UNDEFM;
	display = 1;
	storage = 1;
	os = UNDEFO;
	color = UNDEFC;
	ram = 1;
	cpu = UNDEFM;
	protection = UNDEFP;
	ncams = 0;
}

SmSpec::SmSpec(Manufacturer m, Color c, short r, short st, 
	Manufacturer cp, Os o, float d, short nc, Protection p) {
	manufacturer = m;
	color = c;
	ram = r;
	storage = st;
	cpu = cp;
	os = o;
	display = d;
	ncams = nc;
	protection = p;
}

void SmSpec::setSpecs(Manufacturer m, Color c, short r, short st,
	Manufacturer cp, Os o, float d, short nc, Protection p) {
	manufacturer = m;
	color = c;
	ram = r;
	storage = st;
	cpu = cp;
	os = o;
	display = d;
	ncams = nc;
	protection = p;
}

void SmSpec::setSpecs(SmSpec& spec) {
	manufacturer = spec.getManufacturer();
	color = spec.getColor();
	ram = spec.getRAM();
	storage = spec.getStorage();
	cpu = spec.getCPU();
	os = spec.getOS();
	display = spec.getDisplay();
	ncams = spec.getNCams();
	protection = spec.getProtection();
}

SmSpec& SmSpec::operator=(const SmSpec& sp) {
	if (this != &sp) {
		this->manufacturer = sp.manufacturer;
		this->color = sp.color;
		this->ram = sp.ram;
		this->storage = sp.storage;
		this->cpu = sp.cpu;
		this->os = sp.os;
		this->display = sp.display;
		this->ncams = sp.ncams;
		this->protection = sp.protection;
	}
	return *this;
}

Color SmSpec::getColor() const {
	return color;
}

Manufacturer SmSpec::getCPU() const {
	return cpu; 
} 

float SmSpec::getDisplay() const {
	return display;
}

Manufacturer SmSpec::getManufacturer() const {
	return manufacturer;
}

Os SmSpec::getOS() const {
	return os;
}

short SmSpec::getRAM() const {
	return ram;
}

short SmSpec::getStorage() const {
	return storage;
}

Protection SmSpec::getProtection() const {
	return protection;
}

short SmSpec::getNCams() const {
	return ncams;
}

void SmSpec::print() const {
	std::cout << ManufacturerNames[manufacturer] << std::endl;
	std::cout << "Color: " << ColorNames[color] << std::endl;
	std::cout << "Display: " << display << std::endl;
	std::cout << "OS: " << OsNames[os] << std::endl;
	std::cout << ram << "Gb RAM, " << storage << " GB storage" << std::endl;
	std::cout << "CPU: " << ManufacturerNames[cpu] << std::endl;
	std::cout << "Protection: " << ProtHave[protection] << std::endl;
	std::cout << "Number of Cameras: " << ncams << std::endl;
}
