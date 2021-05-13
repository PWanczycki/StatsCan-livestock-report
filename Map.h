/*-----------------------------------------------------------------*/
/* Map class template                                              */
/*                                                                 */
/* Collection object representing a map of keys and values.        */
/* Keys are elements of type T, while values are collections of    */
/* Record pointers.                                                */
/*-----------------------------------------------------------------*/

#ifndef MAP_H
#define MAP_H

#include <vector>
using namespace std;
#include "Record.h"

template <class T>
class Map {
    public:
        Map();
        void add(T, Record*);
        int getNumKeys();
        void getKeys(vector<T>*&);
        vector<Record*>& operator[](T);  //use EH

    private:
        vector<T> keys;
        vector<vector<Record*>> values;
        void findKey(T, int&);
        void addNewKey(T);
};

template <class T>
Map<T>::Map() {}

template <class T>
void Map<T>::add(T key, Record* rec) {
    int i = -1;
    for (int j = 0; j < keys.size(); ++j) {
        if (keys.at(j) == key) {
            i = j;
            break;
        }
    }
    if (i != -1) {
        values.at(i).push_back(rec);
    } else {
        addNewKey(key);
        values.back().push_back(rec);
    }
}

template <class T>
int Map<T>::getNumKeys() { return keys.size(); }

template <class T>
void Map<T>::getKeys(vector<T>*& vectPtr) { vectPtr = &keys; }

template <class T>
vector<Record*>& Map<T>::operator[](T key) {
    int index = -1;
    findKey(key, index);
    return values.at(index);
}

template <class T>
void Map<T>::findKey(T key, int& index) {
    for (int i = 0; i < keys.size(); ++i) {
        if (keys.at(i) == key) {
            index = i;
            return;
        }
    }
    throw "Key not found";
}

template <class T>
void Map<T>::addNewKey(T key) {
    keys.push_back(key);
    vector<Record*> value;
    values.push_back(value);
}

#endif /* end of include guard: MAP_H */
