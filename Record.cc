#include <string>
using namespace std;

#include "Record.h"

Record::Record(int yr, string rgn, string sRgn, string anml, int frms, int numAnml)
: year(yr), region(rgn), subRegion(sRgn), animalType(anml), numFarms(frms), numAnimals(numAnml) {
    validateInts(year, numFarms, numAnimals);
}

void Record::validateInts(int& yr, int& frms, int& numAnml) {
    if (yr <= 0) yr = 2021;
    if (frms < 0) frms = 0;
    if (numAnml < 0) numAnml = 0;
}

int Record::getYear() const { return year; }

string Record::getRegion() const { return region; }

string Record::getSubRegion() const { return subRegion; }

string Record::getAnimalType() const { return animalType; }

int Record::getNumFarms() const { return numFarms; }

int Record::getNumAnimals() const { return numAnimals; }
