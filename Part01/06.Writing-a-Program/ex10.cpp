/*
    A permutation is an ordered subset of a set. For example, say you wanted to pick a
    combination to a vault. There are 60 possible numbers, and you need three different
    numbers for the combination. There are P(60, 3) permutations for the combination, 
    where P is defined by the formula P(a,b) = a! / (a - b)! where ! is used as a suffix
    factorial operator. For example, 4! is 4*3*2*1.
    Combinations are similar to permutations, except that the order of the objects doesn't
    matter. For example, if you were making a "banana split" sundae and wished to use three
    different flavors of ice cream out of five that you had, you wouldn't care if you used
    a scoop of vanilla at the beginning or the end; you would still have used vanilla. The
    formula for combination is C(a,b) = P(a,b) / b!.
    Design a program that asks users for two numbers, asks them whether they want to calculate
    permutations or combinations, and prints out the result. This will have several parts. Do an
    analysis of the above requirements. Write exactly what the program will have to do. Then, go
    into the design phase. Write the pseudo code for the program, and break it into sub-components.
    This program should have error checking. Make sure that all errorneous inputs will generate
    good error messages.
*/
#include "../std_lib_facilities.h"

int factorial(int n, int spoint);
int factorial(int n) { return factorial(n, 0); };
int permutation(int a, int b);
int combination(int a, int b);

int main()
{
    try {
        int a, b, result = 0;
        char type;
        cout << "Enter two numbers separated by blank spaces, for example: 10 3" << endl;
        cin >> a >> b;
        if (!cin) error("An error occurred!");
        if (a < b) error("B value cannot be greater than A value");
        cout << "Type 'p' (for calculate permutations) or 'c' (for calculate combinations)" << endl;
        cin >> type;
        switch (type)
        {
        case 'P': case 'p': //for permutaions
            result = permutation(a, b);
            cout << "P(";
            break;
        case 'C': case 'c': //for combinations
            result = combination(a, b);
            cout << "C(";
            break;
        }
        cout << a << "," << b << ") is " << result << endl;

    } catch (exception& e) {
        cerr << e.what() << endl;
    }

    return 0;
}

int factorial(int n, int spoint)
{
    if (n < 0) 
        error("factorial cannot be negative");
    else if(n == 0)
        return 1;

    int sum = 1;
    for (int i = n; i > spoint; --i) sum *= i;

    if (sum <= 0) error("number too large!");
    return sum;
}

int permutation(int a, int b)
{
    return factorial(a,  a - b);
}

int combination(int a, int b)
{
    return permutation(a, b) / factorial(b);
}