/*
    Define a Group to be a container of Shapes with suitable operations applied to
    the various members of the Group. Hint: Vector_ref. Use a Group to define checkers
    (draughts) board where pieces can be moved under program control.
*/
#include "Custom_objects.h"

int main()
{
    Simple_window win(Point{250, 60}, win_width, win_height, "Exercise 09 - Chapter 14: Graphics Class Design");

    try
    {
        Group group;

        int squares = 8;
        
        int size = (win_height - 25) / squares;

        int color = 0;
        for (int i = 0; i < squares; ++i)
        {
            for (int j = 0; j < squares; ++j)
            {
                Shape* shape = new Rectangle(Point{i * size, j * size}, size, size);
                if (color % 2 == 0) {
                    shape->set_fill_color(Color::black);
                } else {
                    shape->set_fill_color(Color::white);
                }

                group.add(shape);
                
                color++;
            }
            color++;
        }

        group.attachTo(win);
        win.wait_for_button();
        group.move(110, 25);
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