#include <iostream>

#include <string>

#include <fstream>

#include <sstream>

#include "library.h"

using namespace std;

void map()

{
    char file[] = "xxxx.txt";

    ifstream h(file);

    string line;

    while (getline(h, line))

    {
        istringstream iss(line);

        double x, y;

        set_pen_width(2);

        if (!(iss >> xxx >> x >> y))

        {
            string state(line);

            draw = true;

            set_pen_color(color::white);
        }

        else if (x != -1 && y != -1 && draw)

        {
            x = 1675 - x / 75;

            y = 675 - y / 75;

            cout << "(x,y) = (" << x << "," << y << " )\n";

            if (!init)

            {
                init = true;

                set_pen_color(color::white);

                move_to(x, y);
            }

            else

            {
                set_pen_color(color::black);

                draw_to(x, y);

                set_pen_color(color::white);
            }
        }

        else if (x == -1 && y == -1)

            init = false;
    }
}
