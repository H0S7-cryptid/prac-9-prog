#ifndef ENUMS
#define ENUMS

// Константы для поля price
enum Mtype { USD = 0, EUR, RUB };

// Константы для определения полей смартфона
enum Manufacturer { Apple = 0, Samsung, Xiaomi, Oppo, Honor, Huawei, UNDEFM = -1 };
enum Color { Black = 0, White, Red, Violet, Gray, LightPink, Pink, UNDEFC = -1 };
enum Os { iOS = 0, Android, UNDEFO = -1 };
enum Protection { YES = 1, NO = -1, UNDEFP = 0 };


#endif // ENUMS
