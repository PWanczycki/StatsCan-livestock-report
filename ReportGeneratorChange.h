/*-----------------------------------------------------------------*/
/* ReportGeneratorChange class                                     */
/*                                                                 */
/* Control object derived from ReportData in charge of computing   */
/* reports on the changes of animal percentages in Canada          */
/*-----------------------------------------------------------------*/

#ifndef REPORTGENERATORCHANGE_H
#define REPORTGENERATORCHANGE_H

#include "ReportGenerator.h"
#include "CompareBehaviour.h"
#include "ReportData.h"

class ReportGeneratorChange : public ReportGenerator {
    public:
        ReportGeneratorChange();
        ~ReportGeneratorChange();
        virtual void compute();

    private:
        ReportData<float>* results;
        void formatData(string, float, float, float);
        void printReport();
        void resetResults();
};

#endif /* end of include guard: REPORTGENERATORCHANGE_H */
