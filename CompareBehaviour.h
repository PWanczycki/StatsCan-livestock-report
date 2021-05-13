/*-----------------------------------------------------------------*/
/* CompareBehaviour class template                                 */
/*                                                                 */
/* Abstract entity object representing comparison behaviour for    */
/* elements of type T.                                             */
/*-----------------------------------------------------------------*/

#ifndef COMPAREBEHAVIOUR_H
#define COMPAREBEHAVIOUR_H

template <class T>
class CompareBehaviour {
    public:
        CompareBehaviour();
        virtual bool compare(T, T)=0;   //T needs to overload < operator
};

template <class T>
CompareBehaviour<T>::CompareBehaviour() {};

#endif /* end of include guard: COMPAREBEHAVIOUR_H */
