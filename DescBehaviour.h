/*-----------------------------------------------------------------*/
/* DescBehaviour class template                                    */
/*                                                                 */
/* Entity object representing comparison behaviour for sorting     */
/* elements of type T in descending order.                         */
/*-----------------------------------------------------------------*/

#ifndef DESCBEHAVIOUR_H
#define DESCBEHAVIOUR_H

#include "CompareBehaviour.h"
using namespace std;

template <class T>
class DescBehaviour : public CompareBehaviour<T> {
    public:
        DescBehaviour();
        virtual bool compare(T, T);
};

template <class T>
DescBehaviour<T>::DescBehaviour() : CompareBehaviour<T>() {}

template <class T>
bool DescBehaviour<T>::compare(T newT, T oldT) {
    return !(newT < oldT);
}

#endif /* end of include guard: DESCBEHAVIOUR_H */
