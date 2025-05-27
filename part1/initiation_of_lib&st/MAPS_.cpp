#include "MAPS_.h"

std::map <Mtype, std::string> MtypeName = {
	{USD, "USD"},
	{EUR, "EUR"},
	{RUB, "RUB"}
};

std::map <Manufacturer, std::string> ManufacturerNames = {
	{Apple, "Apple"},
	{Samsung, "Samsung"},
	{Xiaomi, "Xiaomi"},
	{Oppo, "Oppo"},
	{Honor, "Honor"},
	{Huawei, "Huawei"},
	{UNDEFM, "Unknown manufacturer"}
};

std::map <Color, std::string> ColorNames = {
	{Black, "Black"},
	{White, "White"},
	{Red, "Red"},
	{Violet, "Violet"},
	{Gray, "Gray"},
	{LightPink, "Light Pink"},
	{UNDEFC, "Undefined color"}
};

std::map <Os, std::string> OsNames = {
	{iOS, "iOS"},
	{Android, "Android"},
	{UNDEFO, "Unknown Operational System"}
};

std::map <Protection, std::string> ProtHave = {
	{YES, "Yes, there is a protective screen in complect"},
	{NO, "No, there is no protective screen in complect"}
};
