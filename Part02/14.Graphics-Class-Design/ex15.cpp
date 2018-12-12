/*
    Most class hierarchies have nothing to do with graphics. Define a class 
    Iterator with a pure virtual function next() that returns a double* (see
    Chapter 17). Now derive Vector_iterator and List_iterator from Iterator
    so that next() for Vector_iterator yields a pointer to the next element
    of a vector<double> and List_iterator does the same for a list<double>.
    You initialize a Vector_iterator with a vector<double> and the first call
    of next() yields a pointer to its first element, if any. If there is no
    next element, return 0. Test this by using a function void print(Iterator&)
    to print the elements of a vector<double> and list<double>.
*/
#include <iostream>
#include <vector>
#include <list>

using namespace std;

class Iterator
{
public:
    virtual double* next() = 0;
};

class Vector_iterator : public Iterator
{
public:
    Vector_iterator(vector<double>& vii);
    double* next();
private:
    vector<double> vi;
    int pos;
    double empty;
};

class List_iterator : public Iterator
{
public:
    List_iterator(list<double>& lii);
    double* next();
private:
    list<double> li;
    list<double>::iterator it;
    double empty;
};

void print(Iterator& iterator)
{
    double n = *iterator.next();
    while (n != 0) {
        cout << n << endl;
        n = *iterator.next();
    }
}

int main()
{
    vector<double> vi = {1.1,2.2,3.3,4.4,5.5,6.6,7.7};
    list<double> li = {7.7, 6.6, 5.5, 4.4, 3.3, 2.2, 1.1};
    Vector_iterator vector_iterator(vi);
    List_iterator list_iterator(li);

    cout << "Vector Iterator" << endl;
    print(vector_iterator);
    cout << "List Iterator" << endl;
    print(list_iterator);
    
    return 0;
}

Vector_iterator::Vector_iterator(vector<double>& vii)
: vi(vii), pos(0), empty(0)
{
}

double* Vector_iterator::next()
{
    if (pos >= vi.size()) {
        return &empty;
    }
    return &vi[pos++];
}

List_iterator::List_iterator(list<double>& lii)
: li(lii), it(li.begin()), empty(0)
{
}

double* List_iterator::next()
{
    if (it == li.end()) {
        return &empty;
    }
    return &(*it++);
}