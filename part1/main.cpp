#include"Catalog.h"
using namespace std;

Catalog InitializeCatalog() {
	Catalog catalog;

	SmSpec spec1{ Apple, White, (short)6, (short)128, Apple, iOS, 6.0, 3, YES};
	static Smartphone sm1{ "Apple 12 pro" , spec1 };
	Product samePhoneToSearch{ Price{79999.99, RUB} , InStock, sm1 };
	catalog.addSmartphone(samePhoneToSearch);

	SmSpec spec2{ Samsung, White, 8, 256, Samsung, Android, 8.0, 4, YES };
	static Smartphone sm2{ "Samsung Galaxy S24 Ultra", spec2,};
	Product samePhoneToSearch2{ Price{}, OutOfStock, sm2};
	catalog.addSmartphone(samePhoneToSearch2);

	SmSpec spec3{ Apple, Black, (short)4, (short)64, Apple, iOS, 3.0, 2, NO };
	static Smartphone sm3{ "Apple X", spec3 };
	Product samePhoneToSearch3{ Price{}, OutOfStock, sm3 };
	catalog.addSmartphone(samePhoneToSearch3);

	SmSpec whatBuyerLikes_spec{ Apple, UNDEFC, (short)0, (short)0, UNDEFM, UNDEFO, 0.0, 0, UNDEFP };
	static Smartphone whatBuyerLikes{ "Apple 12 Pro", whatBuyerLikes_spec };
	Product whatBuyerLikes_p{ Price{79999.99, RUB}, InStock, whatBuyerLikes };
	catalog.addSmartphone(whatBuyerLikes_p);

	return catalog;
}

int main(int argc, char* argv[]) {
	Catalog catalog = InitializeCatalog();

	SmSpec whatBuyerLikes_spec_w{Apple, UNDEFC, (short)0, (short)0, UNDEFM, UNDEFO, 0.0, 0, UNDEFP};
	Smartphone whatBuyerLikes_w{ "Apple 12 Pro", whatBuyerLikes_spec_w };
	Product whatBuyerLikes_P{ Price{}, UNDEFPA, whatBuyerLikes_w };

	vector<Product> Selected;

	Selected = catalog.search(whatBuyerLikes_w);

	if (!Selected.empty())
	{
		cout << "You might like theese: " << endl;
		for (const Product& item : Selected) {
			item.print();
		}
	}
	return 0;
}
