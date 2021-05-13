#include <vector>
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
using namespace std;

#include "ReportGeneratorHorse.h"
#include "DescBehaviour.h"

ReportGeneratorHorse::ReportGeneratorHorse()
: results(new ReportData<int>(new DescBehaviour<int>())) {}

ReportGeneratorHorse::~ReportGeneratorHorse() {
    delete results;
}

void ReportGeneratorHorse::compute() {
    try {
        vector<Record*>& horseRecs = animalMap["Horses-Ponies"];

        vector<string>* regions;
        regionMap.getKeys(regions);

        for (int i = 0; i < regions->size(); ++i) {
            string highestSubRegion;
            int highest = -1;

            for (int j = 0; j < horseRecs.size(); ++j) {
                Record* currRec = horseRecs.at(j);
                if (currRec->getRegion() != regions->at(i) || currRec->getSubRegion() == "All"
                    || currRec->getYear() != 2016) {
                    continue;
                }
                if (currRec->getNumAnimals() > highest) {
                    highest = currRec->getNumAnimals();
                    highestSubRegion = currRec->getSubRegion();
                }
            }

            if (highest > -1)
                formatData(regions->at(i), highestSubRegion, highest);
        }
    }
    catch(const char* error) {
        cout << "ERROR: " << error << endl;
        return;
    }

    printReport();
    resetResults();
}

void ReportGeneratorHorse::formatData(string region, string subRegion, int numHorses) {
    stringstream ss;
    ss << setw(4) << region << setw(32) << subRegion << setw(8) << numHorses;

    results->add(numHorses, ss.str());
}

void ReportGeneratorHorse::printReport() {
    cout << *results << endl;

    ofstream outfile("2.3_horses_report.txt", ios::out);
    if (!outfile) {
        cout << "ERROR: could not open file" << endl;
        return;
    }

    outfile << *results << endl;
}

void ReportGeneratorHorse::resetResults() {
    // maybe cleanup() in ReportData
    delete results;
    results = new ReportData<int>(new DescBehaviour<int>());
}
