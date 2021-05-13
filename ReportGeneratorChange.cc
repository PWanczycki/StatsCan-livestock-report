#include <vector>
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
using namespace std;

#include "ReportGeneratorChange.h"
#include "AscBehaviour.h"

ReportGeneratorChange::ReportGeneratorChange()
: results(new ReportData<float>(new AscBehaviour<float>())) {}

ReportGeneratorChange::~ReportGeneratorChange() {
    delete results;
}

void ReportGeneratorChange::compute() {
    float total2011 = 0.0f;
    float total2016 = 0.0f;
    try {
        vector<Record*>& recs2011 = yearMap[2011];
        vector<Record*>& recs2016 = yearMap[2016];

        for (int i = 0; i < recs2011.size(); ++i) {
            if (recs2011.at(i)->getRegion() == "CAN") {
                total2011 += recs2011.at(i)->getNumAnimals();
            }
        }

        for (int i = 0; i < recs2016.size(); ++i) {
            if (recs2016.at(i)->getRegion() == "CAN") {
                total2016 += recs2016.at(i)->getNumAnimals();
            }
        }

        vector<string>* animals;
        animalMap.getKeys(animals);
        for (int i = 0; i < animals->size(); ++i) {
            float percentage2011;
            float percentage2016;

            for (int j = 0; j < recs2011.size(); ++j) {
                Record* currRecord = recs2011.at(j);
                if (currRecord->getRegion() == "CAN"
                    && currRecord->getAnimalType() == animals->at(i)) {
                    percentage2011 = (float)(currRecord->getNumAnimals())/total2011;
                }
            }

            for (int j = 0; j < recs2016.size(); ++j) {
                Record* currRecord = recs2016.at(j);
                if (currRecord->getRegion() == "CAN"
                    && currRecord->getAnimalType() == animals->at(i)) {
                    percentage2016 = (float)(currRecord->getNumAnimals())/total2016;
                }
            }

            formatData(animals->at(i), percentage2011, percentage2016, percentage2016-percentage2011);
        }
    }
    catch(const char* error) {
        cout << "ERROR: " << error << endl;
        return;
    }

    printReport();
    resetResults();
}

void ReportGeneratorChange::formatData(string animal, float percent1, float percent2, float change) {
    stringstream ss;
    ss << setw(20) << animal << setw(8) << fixed << setprecision(1) << percent1
       << setw(8) << fixed << setprecision(1) << percent2
       << setw(8) << fixed << setprecision(1) << showpos << change;

    results->add(change, ss.str());
}

void ReportGeneratorChange::printReport() {
    cout << *results << endl;

    ofstream outfile("2.2_change_report.txt", ios::out);
    if (!outfile) {
        cout << "ERROR: could not open file" << endl;
        return;
    }

    outfile << *results << endl;
}

void ReportGeneratorChange::resetResults() {
    // maybe cleanup() in ReportData
    delete results;
    results = new ReportData<float>(new AscBehaviour<float>());
}
