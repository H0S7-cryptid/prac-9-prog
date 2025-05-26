#ifndef MAPS
#define MAPS

#include <map>
#include <string>
#include "ENUMS_.h"

// Ассоциативные массивы для работы с перечислениями
extern std::map <Mtype, std::string> MtypeName;
extern std::map <Manufacturer, std::string> ManufacturerNames;
extern std::map <Color, std::string> ColorNames;
extern std::map <Os, std::string> OsNames;
extern std::map <Protection, std::string> ProtHave;

#endif
