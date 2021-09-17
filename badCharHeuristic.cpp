#include <string>
#include <iostream>
#include "badCharHeuristic.h"
# define NO_OF_CHARS 256  
using namespace std;


void badCharHeuristic(string str, int size, int badchar[NO_OF_CHARS])
{
    int i;

    for (i = 0; i < NO_OF_CHARS; i++)
        badchar[i] = -1;

    for (i = 0; i < size; i++)
        badchar[(int)str[i]] = i;
}
