#include <vector>
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
using namespace std;

#include "ReportGeneratorFarms.h"
#include "DescBehaviour.h"

ReportGeneratorFarms::ReportGeneratorFarms()
: results(new ReportData<float>(new DescBehaviour<float>())) {}

ReportGeneratorFarms::~ReportGeneratorFarms() {
    delete results;
}

void ReportGeneratorFarms::compute() {
    vector<string>* animals;
    animalMap.getKeys(animals);
    float totalFarmsPerAnimal[animals->size()];
    float totalFarms = 0;

    vector<string>* regions;
    regionMap.getKeys(regions);
    for (int i = 0; i < regions->size(); ++i) {
        if (regions->at(i) == "CAN")
            continue;
        try {
            vector<Record*>& recs = regionMap[regions->at(i)];

            for (int j = 0; j < recs.size(); ++j) {
                if (recs.at(j)->getSubRegion() != "All" || recs.at(j)->getYear() != 2016)
                    continue;
                for (int k = 0; k < animals->size(); ++k) {
                    if (recs.at(j)->getAnimalType() == animals->at(k)) {
                        totalFarmsPerAnimal[k] += recs.at(j)->getNumFarms();
                        break;
                    }
                }
                totalFarms += recs.at(j)->getNumFarms();
            }
        }
        catch(const char* error) {
            cout << "ERROR: " << error << endl;
            continue;
        }
    }

    for (int i = 0; i < regions->size(); ++i) {
        if (regions->at(i) == "CAN")
            continue;
        try {
            vector<Record*>& recs = regionMap[regions->at(i)];

            vector<float> data(animals->size(), 0.0f);
            float regionFarms = 0;

            for (int j = 0; j < recs.size(); ++j) {
                if (recs.at(j)->getSubRegion() != "All" || recs.at(j)->getYear() != 2016)
                    continue;
                for (int k = 0; k < animals->size(); ++k) {
                    if (recs.at(j)->getAnimalType() == animals->at(k)) {
                        data.at(k) = (float)(recs.at(j)->getNumFarms())/totalFarmsPerAnimal[k];
                        break;
                    }
                }
                regionFarms += recs.at(j)->getNumFarms();
            }

            data.push_back(regionFarms/totalFarms);
            formatData(regions->at(i), data);
        }
        catch(const char* error) {
            cout << "ERROR: " << error << endl;
            continue;
        }
    }

    printReport();
    resetResults();
}

void ReportGeneratorFarms::formatData(string region, vector<float>& data) {
    stringstream ss;
    ss << setw(4) << region;
    for (int i = 0; i < data.size(); ++i) {
        ss << setw(8) << fixed << setprecision(1) << data.at(i);
    }
    results->add(data.back(), ss.str());
}

void ReportGeneratorFarms::printReport() {
    cout << *results << endl;

    ofstream outfile("2.1_farms_report.txt", ios::out);
    if (!outfile) {
        cout << "ERROR: could not open file" << endl;
        return;
    }

    outfile << *results << endl;
}

void ReportGeneratorFarms::resetResults() {
    // maybe cleanup() in ReportData
    delete results;
    results = new ReportData<float>(new DescBehaviour<float>());
}
