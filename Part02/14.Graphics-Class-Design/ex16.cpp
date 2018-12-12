/*
    Define a class Controller with four virtual functions on(), off(), set_level(int),
    and show(). Derive at least two classes from Controller. One should be a simple
    test class where show() prints out whether the class is set to on or off and what
    is the current level. The second derived class should somehow control the line color
    of a Shape; the exact meaning of "level" is up to you. Try to find a third "thing"
    to control with such a Controller class.
*/
#include "Custom_objects.h"

int main()
{
     Simple_window win(Point{250, 60}, win_width, win_height, "Exercise 16 - Chapter 14: Graphics Class Design");

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