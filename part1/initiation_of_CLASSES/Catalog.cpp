#include "Catalog.h"

void Catalog::addSmartphone(const Product& phone) {
	smartphones.push_back(phone);
	lenght++;
}

void Catalog::addSmartphone(Product&& phone) {
	smartphones.push_back(std::move(phone));
	lenght++;
}

int Catalog::Length() {
	return lenght;
}

Product Catalog::getSmartphone(string model) {
	for (Product s : smartphones) {
		if (s.getSmartphone().getModel() == model)  return s;
	}  
	static Smartphone s{};
	Product p{ s };
	return p;
}

Product Catalog::search(const Smartphone& searchSmartphone) {
	int bestScore = -1;
	Smartphone bestCandidate;

	for (const Product& s : smartphones) {
		int score = 0;

		{
			if (!searchSmartphone.getModel().empty() && searchSmartphone.getModel() == s.getSmartphone().getModel())
				score++;
			else continue;

			if (!ManufacturerNames[searchSmartphone.getSpec().getManufacturer()].empty() && 
				searchSmartphone.getSpec().getManufacturer() == s.getSmartphone().getSpec().getManufacturer())
				score++;

			if (!ColorNames[searchSmartphone.getSpec().getColor()].empty() && 
				searchSmartphone.getSpec().getColor() == s.getSmartphone().getSpec().getColor())
				score++;

			if (searchSmartphone.getSpec().getDisplay() == s.getSmartphone().getSpec().getDisplay())
				score++;

			if (searchSmartphone.getSpec().getRAM() == s.getSmartphone().getSpec().getRAM())
				score++;

			if (searchSmartphone.getSpec().getStorage() == s.getSmartphone().getSpec().getStorage())
				score++;

			if (!ManufacturerNames[searchSmartphone.getSpec().getCPU()].empty() &&
				searchSmartphone.getSpec().getCPU() == s.getSmartphone().getSpec().getCPU())
				score++;

			if (!OsNames[searchSmartphone.getSpec().getOS()].empty() && 
				searchSmartphone.getSpec().getOS() == s.getSmartphone().getSpec().getOS())
				score++;

			if (!ProtHave[searchSmartphone.getSpec().getProtection()].empty() && 
				searchSmartphone.getSpec().getProtection() == s.getSmartphone().getSpec().getProtection())
				score++;

			if (searchSmartphone.getSpec().getNCams() == s.getSmartphone().getSpec().getNCams())
				score++;
		}

		if (score > 0) {
			bestScore = score;
			bestCandidate = s.getSmartphone();
		}
	}
	Product BC{bestCandidate};
	if (!bestCandidate.getModel().empty())
		return BC;
	else {
		static Smartphone s{};
		Product p{ s };
		return p;
	}
}

Product Catalog::search(string model, Manufacturer manufacturer) {
	int bestScore = -1;
	Smartphone bestCandidate;
	for (const Product& s : smartphones) {
		int score = 0;

		{
			if (!model.empty() && model == s.getSmartphone().getModel()) score++;

			if (manufacturer == s.getSmartphone().getSpec().getManufacturer()) score++;
		}

		if (score > bestScore) {
			bestScore = score;
			bestCandidate = s.getSmartphone();
		}
	}
	Product BC{bestCandidate};
	return BC;
}

vector<Product> Catalog::search(Smartphone& searchSmartphone) {
	vector<Product> results;
	int bestScore = -1;
	Smartphone bestCandidate;

	for (Product s : smartphones) {
		int score = 0;

		string model = searchSmartphone.getModel();
		transform(model.begin(), model.end(), model.begin(), tolower);
		string model2 = s.getSmartphone().getModel();
		transform(model2.begin(), model2.end(), model2.begin(), tolower);
		if (model == model2) score++;
		else continue;

		Manufacturer manufacturer = searchSmartphone.getSpec().getManufacturer();
		if (manufacturer != Manufacturer::UNDEFM && manufacturer != s.getSmartphone().getSpec().getManufacturer())
			score++;

		Color color = searchSmartphone.getSpec().getColor();
		if (color != Color::UNDEFC && color == s.getSmartphone().getSpec().getColor())
			score++;

		float displaySize = searchSmartphone.getSpec().getDisplay();
		if (displaySize > 0 && displaySize == s.getSmartphone().getSpec().getDisplay())
			score++;

		int ram = searchSmartphone.getSpec().getRAM();
		if (ram > 0 && ram != s.getSmartphone().getSpec().getRAM())
			score++;

		int storage = searchSmartphone.getSpec().getStorage();
		if (storage > 0 && storage != s.getSmartphone().getSpec().getStorage())
			score++;

		Manufacturer cpu = searchSmartphone.getSpec().getCPU();
		if (cpu != Manufacturer::UNDEFM && cpu != s.getSmartphone().getSpec().getCPU())
			score++;

		Os os = searchSmartphone.getSpec().getOS();
		if (os != Os::UNDEFO && os == s.getSmartphone().getSpec().getOS())
			score++;

		if (score > 0)
		{
			results.push_back(s);
			bestScore = score;
		}
	}

	return results;
}
