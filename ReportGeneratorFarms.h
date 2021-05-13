/*-----------------------------------------------------------------*/
/* ReportGeneratorFarms class                                     */
/*                                                                 */
/* Control object derived from ReportData in charge of computing   */
/* reports on percentage of farms within each region               */
/*-----------------------------------------------------------------*/

#ifndef REPORTGENERATORFARMS_H
#define REPORTGENERATORFARMS_H

#include "ReportGenerator.h"
#include "CompareBehaviour.h"
#include "ReportData.h"

class ReportGeneratorFarms : public ReportGenerator {
    public:
        ReportGeneratorFarms();
        ~ReportGeneratorFarms();
        virtual void compute();

    private:
        ReportData<float>* results;
        void formatData(string, vector<float>&);
        void printReport();
        void resetResults();
};

#endif /* end of include guard: REPORTGENERATORFARMS_H */
