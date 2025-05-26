#include "Catalog.h"

void Catalog::addSmartphone(string model, double price, Manufacturer manufacturer,
	Color color, float display, short ram,
	short storage, Manufacturer cpu, Os os, short ncams, Protection protection, Mtype currency) {
	smartphones.push_back(Smartphone{ model, price, SmSpec{manufacturer, color, 
		ram, storage, cpu, os, display, ncams, protection}, currency});
	lenght++;
}

void Catalog::addSmartphone(string model, double price, SmSpec spec, Mtype currency) {
	smartphones.push_back(Smartphone{ model, price, spec, currency });
	lenght++;
}

void Catalog::addSmartphone(const Smartphone& phone) {
	smartphones.push_back(phone);
	lenght++;
}

void Catalog::addSmartphone(Smartphone&& phone) {
	smartphones.push_back(std::move(phone));
	lenght++;
}

int Catalog::Length() {
	return lenght;
}

Smartphone Catalog::getSmartphone(string model) {
	for (Smartphone s : smartphones) {
		if (s.getModel() == model)  return s;
	}  return Smartphone();
}

Smartphone Catalog::search(const Smartphone& searchSmartphone) {
	int bestScore = -1;
	Smartphone bestCandidate;

	for (const Smartphone& s : smartphones) {
		int score = 0;

		{
			if (!searchSmartphone.getModel().empty() && searchSmartphone.getModel() == s.getModel())
				score++;

			if (!ManufacturerNames[searchSmartphone.getSpec().getManufacturer()].empty() && 
				searchSmartphone.getSpec().getManufacturer() == s.getSpec().getManufacturer())
				score++;

			if (!ColorNames[searchSmartphone.getSpec().getColor()].empty() && 
				searchSmartphone.getSpec().getColor() == s.getSpec().getColor())
				score++;

			if (searchSmartphone.getSpec().getDisplay() == s.getSpec().getDisplay())
				score++;

			if (searchSmartphone.getSpec().getRAM() == s.getSpec().getRAM())
				score++;

			if (searchSmartphone.getSpec().getStorage() == s.getSpec().getStorage())
				score++;

			if (!ManufacturerNames[searchSmartphone.getSpec().getCPU()].empty() &&
				searchSmartphone.getSpec().getCPU() == s.getSpec().getCPU())
				score++;

			if (!OsNames[searchSmartphone.getSpec().getOS()].empty() && 
				searchSmartphone.getSpec().getOS() == s.getSpec().getOS())
				score++;

			if (!ProtHave[searchSmartphone.getSpec().getProtection()].empty() && 
				searchSmartphone.getSpec().getProtection() == s.getSpec().getProtection())
				score++;

			if (searchSmartphone.getSpec().getNCams() == s.getSpec().getNCams())
				score++;
		}

		if (score > bestScore && score > 3) {
			bestScore = score;
			bestCandidate = s;
		}
	}

	if (!bestCandidate.getModel().empty())
		return bestCandidate;
	else return Smartphone{};
}

Smartphone Catalog::search(string model, Manufacturer manufacturer) {
	int bestScore = -1;
	Smartphone bestCandidate;
	for (const Smartphone& s : smartphones) {
		int score = 0;

		{
			if (!model.empty() && model == s.getModel()) score++;

			if (manufacturer == s.getSpec().getManufacturer()) score++;
		}

		if (score > bestScore) {
			bestScore = score;
			bestCandidate = s;
		}
	}
	return bestCandidate;
}

vector<Smartphone> Catalog::search(Smartphone& searchSmartphone) {
	vector<Smartphone> results;
	int bestScore = -1;
	Smartphone bestCandidate;

	for (Smartphone s : smartphones) {
		int score = 0;

		string model = searchSmartphone.getModel();
		transform(model.begin(), model.end(), model.begin(), tolower);
		string model2 = s.getModel();
		transform(model2.begin(), model2.end(), model2.begin(), tolower);
		if (model == model2) score++;

		Manufacturer manufacturer = searchSmartphone.getSpec().getManufacturer();
		if (manufacturer != Manufacturer::UNDEFM && manufacturer != s.getSpec().getManufacturer()) 
			score++;

		Color color = searchSmartphone.getSpec().getColor();
		if (color != Color::UNDEFC && color == s.getSpec().getColor())
			score++;

		float displaySize = searchSmartphone.getSpec().getDisplay();
		if (displaySize > 0 && displaySize == s.getSpec().getDisplay())
			score++;

		int ram = searchSmartphone.getSpec().getRAM();
		if (ram > 0 && ram != s.getSpec().getRAM()) 
			score++;

		int storage = searchSmartphone.getSpec().getStorage();
		if (storage > 0 && storage != s.getSpec().getStorage()) 
			score++;

		Manufacturer cpu = searchSmartphone.getSpec().getCPU();
		if (cpu != Manufacturer::UNDEFM && cpu != s.getSpec().getCPU()) 
			score++;

		Os os = searchSmartphone.getSpec().getOS();
		if (os != Os::UNDEFO && os == s.getSpec().getOS()) 
			score++;

		if (score > 0)
		{
			results.push_back(s);
			bestScore = score;
		}
	}
	return results;
}
