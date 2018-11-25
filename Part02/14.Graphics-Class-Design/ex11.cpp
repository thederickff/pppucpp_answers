/*
    Define a Binary_tree class derived from Shape. Give the number of level
    as a parameter (levels==0 means no nodes, levels==1 means one node,
    levels==2 means one top node with two sub-nodes, levels==3 means one
    top node with two sub-nodes each with two sub-nodes, etc.). Let a node
    be represented by a small circle. Connect the nodes by line (as is 
    conventional). P.S. In computer science, trees grow downward from a top
    node (amusingly, but logically, often called the root).
*/
#include "Custom_objects.h"

int main()
{
    Simple_window win(Point{250, 60}, win_width, win_height, "Exercise 10 - Chapter 14: Graphics Class Design");

    try
    {
        Binary_tree binary(Point{400, 130}, 7);
        binary.constructNodes();

        win.attach(binary);
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