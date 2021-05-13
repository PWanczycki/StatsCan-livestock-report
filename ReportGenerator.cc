#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

#include "ReportGenerator.h"
#include "Record.h"
#include "Map.h"

vector<Record*> ReportGenerator::records;
Map<int> ReportGenerator::yearMap;
Map<string> ReportGenerator::regionMap;
Map<string> ReportGenerator::animalMap;

ReportGenerator::ReportGenerator() {}

void ReportGenerator::loadData() {
    ifstream infile("farms.dat", ios::in);
    if (!infile) {
        cout << "ERROR: could not open file" << endl;
        return;
    }

    int year, numFarms, numAnimals;
    string region, subRegion, animalType;
    Record* rec;

    while (infile >> year >> region >> subRegion >> animalType >> numFarms >> numAnimals) {
        rec = new Record(year, region, subRegion, animalType, numFarms, numAnimals);
        records.push_back(rec);
        yearMap.add(year, rec);
        regionMap.add(region, rec);
        animalMap.add(animalType, rec);
    }
}

void ReportGenerator::cleanup() {
    for (int i = 0; i < records.size(); ++i) {
        delete records.at(i);
    }
}
