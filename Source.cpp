#include <string>
#include <iostream>
#include "badCharHeuristic.h"
#include "IsKPeriodic.h"
using namespace std;
# define NO_OF_CHARS 256  


int main() {
    int K(5);

    string str = "hellohellohello";
    string substr = str.substr(0, K);
 
    IsKPeriodic(str, substr);
    return 0;
};