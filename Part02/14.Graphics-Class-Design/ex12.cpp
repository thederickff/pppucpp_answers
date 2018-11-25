/*
    Modify Binary_tree to draw its nodes using a virtual function. 
    Then, derive a new class from Binary_tree that overrides that 
    virtual function to use a different representation for a node
    (e.g., a triangle).
*/
#include "Custom_objects.h"

int main()
{
    Simple_window win(Point{250, 60}, win_width, win_height, "Exercise 12 - Chapter 14: Graphics Class Design");

    try
    {
        

        win.wait_for_button();
    }
    catch (const exception &e)
    {
        Text em(Point{150, 200}, "Exception caught: ");
        Text emd(Point{280, 200}, e.what());
        win.attach(em);
        win.attach(emd);
        win.wait_for_button();
    }
    catch (...)
    {
        Text em(Point{150, 200}, "Unknown exception caught!");
        win.attach(em);
        win.wait_for_button();
    }

    return 0;
}