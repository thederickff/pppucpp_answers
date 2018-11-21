/*
    Define a Group to be a container of Shapes with suitable operations applied to
    the various members of the Group. Hint: Vector_ref. Use a Group to define checkers
    (draughts) board where pieces can be moved under program control.
*/
#include "Custom_objects.h"

int main()
{
    Simple_window win(Point{250, 50}, win_width, win_height, "Exercise 09 - Chapter 14: Graphics Class Design");

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