/*-----------------------------------------------------------------*/
/* View Class                                                      */
/*                                                                 */
/* Boundary object to control the UI within the Control object     */
/*-----------------------------------------------------------------*/

#ifndef VIEW_H
#define VIEW_H

#include <iostream>
#include <string>
using namespace std;


class View
{
  public:
    void showMenu(int&);
    void printStr(string);
    void readInt(int&);
    void readStr(string&);
};

#endif
