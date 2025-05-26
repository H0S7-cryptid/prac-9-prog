#include"Catalog.h"
using namespace std;

Catalog InitializeCatalog() {
	Catalog catalog;

	SmSpec spec1{ Apple, White, (short)6, (short)128, Apple, iOS, 6.0, 3, YES};
	Smartphone samePhoneToSearch{ "Apple 12 pro", 74999.99, spec1, RUB };
	catalog.addSmartphone(samePhoneToSearch);

	SmSpec spec2{ Apple, Black, (short)4, (short)64, Apple, iOS, 3.0, 2, NO };
	catalog.addSmartphone("Apple 10 pro", 29999.99, spec2, RUB);

	return catalog;
}

int main(int argc, char* argv[]) {
	Catalog catalog = InitializeCatalog();

	SmSpec whatBuyerLikes_spec{Apple, (Color)0, (short)0, (short)0, (Manufacturer)0, (Os)0, 0.0, 0, (Protection)0};
	Smartphone whatBuyerLikes{ "Apple 12 Pro", 0, whatBuyerLikes_spec, (Mtype)2 };

	vector<Smartphone> Selected;

	Selected = catalog.search(whatBuyerLikes);

	if (!Selected.empty())
	{
		cout << "You might like theese: " << endl;
		for (const Smartphone& item : Selected) {
			item.Print();
		}
	}
	return 0;
}
