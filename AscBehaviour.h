/*-----------------------------------------------------------------*/
/* AscBehaviour class template                                     */
/*                                                                 */
/* Entity object representing comparison behaviour for sorting     */
/* elements of type T in ascending order.                          */
/*-----------------------------------------------------------------*/

#ifndef ASCBEHAVIOUR_H
#define ASCBEHAVIOUR_H

#include "CompareBehaviour.h"
using namespace std;

template <class T>
class AscBehaviour : public CompareBehaviour<T> {
    public:
        AscBehaviour();
        virtual bool compare(T, T);
};

template <class T>
AscBehaviour<T>::AscBehaviour() : CompareBehaviour<T>() {}

template <class T>
bool AscBehaviour<T>::compare(T newT, T oldT) {
    return (newT < oldT);
}

#endif /* end of include guard: ASCBEHAVIOUR_H */
