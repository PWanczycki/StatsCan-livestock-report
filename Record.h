/*-----------------------------------------------------------------*/
/* Record Class                                                    */
/*                                                                 */
/* Entity object representing a single record from a StatsCan      */
/* "Other livestock" census                                        */
/* Constructor Parameters: year, region, subRegion, animalType,    */
/*                         numFarms, numAnimals                    */
/*-----------------------------------------------------------------*/

#ifndef RECORD_H
#define RECORD_H

#include <string>
using namespace std;

class Record {
    public:
        Record(int=2021, string="CAN", string="All", string="Other", int=0, int=0);
        int getYear() const;
        string getRegion() const;
        string getSubRegion() const;
        string getAnimalType() const;
        int getNumFarms() const;
        int getNumAnimals() const;
    private:
        int year;
        string region;
        string subRegion;
        string animalType;
        int numFarms;
        int numAnimals;
        void validateInts(int&, int&, int&);
};

#endif /* end of include guard: RECORD_H */
