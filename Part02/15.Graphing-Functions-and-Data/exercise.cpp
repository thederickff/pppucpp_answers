#include "Simple_window.h"
#include "Graph.h"

double one(double x) { return 1; }
double slope(double x) { return x / 2; }
double square(double x) { return x * x; }

int main()
{
    constexpr int win_width = 600; // window size
    constexpr int win_height = 400;

    constexpr int x_orig = win_width / 2;   // position of (0, 0) is center of window (translate)
    constexpr int y_orig = win_height / 2;
    Point orig(x_orig, y_orig);

    constexpr int r_min = -10;  // range [-10:11]
    constexpr int r_max = 11;

    constexpr int n_points = 400; // number of points used in range
    constexpr int x_scale = 30;   // scaling factors
    constexpr int y_scale = 30;



    Simple_window win(Point{250, 60}, win_width, win_height, "Function Graphing");

    try 
    {
        Function s{one, r_min, r_max, orig, n_points, x_scale, y_scale};
        Function s2 {slope, r_min, r_max, orig, n_points, x_scale, y_scale};
        Function s3 {square, r_min, r_max, orig, n_points, x_scale, y_scale};

        win.attach(s);
        win.attach(s2);
        win.attach(s3);
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