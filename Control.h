/*-----------------------------------------------------------------*/
/* Control class                                                   */
/*                                                                 */
/* Control object in charge of managing 3 ReportGenerator objects  */
/* and controlling the main flow of the program                    */
/*-----------------------------------------------------------------*/

#ifndef CONTROL_H
#define CONTROL_H

#include <vector>
#include "ReportGenerator.h"
#include "View.h"

class Control {
    public:
        Control();
        ~Control();
        void launch();
    private:
        View view;
        vector<ReportGenerator*> repGens;
        //functions used in launch
};

#endif /* end of include guard: CONTROL_H */
