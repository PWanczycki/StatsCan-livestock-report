#include <string>
#include <vector>
using namespace std;

#include "Control.h"
#include "ReportGeneratorFarms.h"
#include "ReportGeneratorChange.h"
#include "ReportGeneratorHorse.h"

Control::Control() {
    repGens.push_back(new ReportGeneratorFarms());
    repGens.push_back(new ReportGeneratorChange());
    repGens.push_back(new ReportGeneratorHorse());
}

Control::~Control() {
    for (int i = 0; i < repGens.size(); ++i) {
        delete repGens.at(i);
    }
    ReportGenerator::cleanup();
}

void Control::launch() {
    ReportGenerator::loadData();

    int choice;

    view.showMenu(choice);
    while (choice != 0) {
      view.printStr("\n");
      switch (choice) {
        case 1:
          view.printStr("Region\n\n");
          repGens.at(0)->compute();
          break;
        case 2:
          view.printStr("         Animal Type    2011    2016  Change\n\n");
          repGens.at(1)->compute();
          break;
        case 3:
          view.printStr("  Sub-regions with the most horses/ponies in 2016\n\n");
          repGens.at(2)->compute();
          break;
      }
      view.showMenu(choice);
    }
}
