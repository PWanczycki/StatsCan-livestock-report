/*-----------------------------------------------------------------*/
/* ReportGeneratorHorse class                                      */
/*                                                                 */
/* Control object derived from ReportData in charge of computing   */
/* reports on the subregion with the most horses within each region*/
/*-----------------------------------------------------------------*/

#ifndef REPORTGENERATORHORSE_H
#define REPORTGENERATORHORSE_H

#include "ReportGenerator.h"
#include "CompareBehaviour.h"
#include "ReportData.h"

class ReportGeneratorHorse : public ReportGenerator {
    public:
        ReportGeneratorHorse();
        ~ReportGeneratorHorse();
        virtual void compute();

    private:
        ReportData<int>* results;
        void formatData(string, string, int);
        void printReport();
        void resetResults();
};

#endif /* end of include guard: REPORTGENERATORHORSE_H */
