/*
    Define a class Pseudo_window that looks as much like a Window as
    can make it without heroic efforts. It should have rounded corners,
    a label, and control icons. Maybe you could add some fake "contents",
    such as an image. It need not actually do anything. It is acceptable
    (and indeed recommended) to have it appear within a Simple_window.
*/
#include "Custom_objects.h"

int main()
{
    Simple_window win(Point{250, 60}, win_width, win_height, "Exercise 10 - Chapter 14: Graphics Class Design");

    try
    {
        Pseudo_window pw(Point{20, 20}, 200, 200, "My Window");

        win.attach(pw);
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