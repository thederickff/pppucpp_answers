#include "../std_lib_facilities.h"

int main()
{
    cout << "Please enter expression (we can handler + and -): ";

    int lval = 0;
    int rval;
    char op;
    int res;
    cin>>lval>>op>>rval; // read something like 1 + 3

    if (op=='+')
        res = lval + rval;
    else if (op=='-')
        res = lval - rval;

    cout << "Result: " << res << '\n';

    return 0;
}