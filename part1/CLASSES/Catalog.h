#pragma once
#include"Smartphone.h"
using namespace std;

class Catalog {
private:
    list<Smartphone> smartphones;
    int lenght = 0;
public:
    void addSmartphone(string model, double price, Manufacturer manufacturer,
        Color color, float display, short ram,
        short storage, Manufacturer cpu, Os os, short ncams, Protection protection, Mtype currency);
    void addSmartphone(string model, double price, SmSpec spec, Mtype currency);
    void addSmartphone(const Smartphone& phone);
    void addSmartphone(Smartphone&& phone);
    Smartphone getSmartphone(string model);
    int Length();
    Smartphone search(const Smartphone& searchSmartphone);
    Smartphone search(string model, Manufacturer manufacturer);
    vector<Smartphone> search(Smartphone& searchSmartphone);
};
