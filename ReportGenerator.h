/*-----------------------------------------------------------------*/
/* ReportGenerator class                                           */
/*                                                                 */
/* Abstract control object in charge of loading data from a file   */
/* and computing reports                                           */
/*-----------------------------------------------------------------*/

#ifndef REPORTGENERATOR_H
#define REPORTGENERATOR_H

#include <vector>
#include <string>
#include "Record.h"
#include "Map.h"

class ReportGenerator {
    public:
        ReportGenerator();
        static void loadData(); //fill records vector and populate maps
        static void cleanup();
        virtual void compute()=0;
    private:
        static vector<Record*> records;
    protected:
        static Map<int> yearMap;
        static Map<string> regionMap;
        static Map<string> animalMap;
};

#endif /* end of include guard: REPORTGENERATOR_H */
