/*
    Add an operation to Binary_tree that adds text to a node. You may
    have to modify the design of Binary_tree to implement this elegantly.
    Choose a way to identify a node; for example, you might give a string
    "lrrlr" for navigating left, right, right, left and right down a binary
    tree (the root node would match both an initial l and an initial r).
*/
#include "Custom_objects.h"

int main()
{
    Simple_window win(Point{250, 60}, win_width, win_height, "Exercise 14 - Chapter 14: Graphics Class Design");

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