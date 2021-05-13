/*-----------------------------------------------------------------*/
/* ReportData class template                                       */
/*                                                                 */
/* Entity object representing a report made up of strings each     */
/* sorted by a key of type T                                       */
/* Constructor Parameters: comparison behaviour                    */
/*-----------------------------------------------------------------*/

#ifndef REPORTDATA_H
#define REPORTDATA_H

#include <vector>
#include <iostream>
using namespace std;
#include "CompareBehaviour.h"

template <class T>
class ReportData {
    template <class V>
    friend ostream& operator<<(ostream&, const ReportData<V>&);

    public:
        ReportData(CompareBehaviour<T>* =NULL);
        ~ReportData();
        void add(T, string);
    private:
        template <class V>
        class ReportRow {
            public:
                ReportRow(V k, string r) : key(k), row(r) {}
                V key;
                string row;
        };
        vector<ReportRow<T>> rows;
        CompareBehaviour<T>* compBhvr;
};

template <class T>
ostream& operator<<(ostream& output, const ReportData<T>& data) {
    for (int i = 0; i < data.rows.size(); ++i) {
        output << data.rows.at(i).row << endl;
    }
    return output;
}

template <class T>
ReportData<T>::ReportData(CompareBehaviour<T>* bhvr) : compBhvr(bhvr) {}

template <class T>
ReportData<T>::~ReportData() {
    delete compBhvr;
}

template <class T>
void ReportData<T>::add(T key, string row) {
    typename vector<ReportRow<T>>::iterator itr;
    // itr = rows.begin();
    // while (compBhvr->compare(key, itr->key) && itr != rows.end()) {
    //     ++itr;
    // }
    for (itr = rows.begin(); itr != rows.end(); ++itr) {
        if (compBhvr->compare(key, itr->key)) {
            break;
        }
    }
    ReportRow<T> newRow(key, row);
    rows.insert(itr, newRow);
}

#endif /* end of include guard: REPORTDATA_H */
