#include <string>
#include <iostream>
#include "IsKPeriodic.h"
#include "badCharHeuristic.h"
# define NO_OF_CHARS 256  
using namespace std;


void  IsKPeriodic(string txt, string pat)
{
    int m = pat.size();
    int n = txt.size();

    int badchar[NO_OF_CHARS];

    badCharHeuristic(pat, m, badchar);

    int s = 0;
    int pat_len(0);
    int txt_len(0);
    pat_len = pat.length();
    txt_len = txt.length();
    int remainder(0);
    int counter(0);
    remainder = txt_len % pat_len;
    int quotient(0);
    quotient = txt_len / pat_len;

    while (s <= (n - m))
    {
        int j = m - 1;

        while (j >= 0 && pat[j] == txt[s + j])
            j--;

        if (j < 0)
        {
            if ((counter * s) % pat_len == 0 && remainder == 0) {

                counter++;
            }
            cout << "pattern occurs at shift = " << s << endl;

            s += (s + m < n) ? m - badchar[txt[s + m]] : 1;

        }
        else
        {
            int bc = badchar[txt[s + j]];
            s += max(1, j - bc);
        }

    }
    if (counter == quotient) {
        cout << "The line is multiple to K = " << pat_len;
    }
    else cout << "The line is not multiple to K = " << pat_len;
}