void simple_circle(const int x, const int y, const int redius) {
set_pen_width(3.0);
draw_point(x, y);

double min_circle = 2 * acos(-1.0)*redius / 360;
move_to(x, y + redius);
set_heading_degrees(270);
set_pen_color(color::black);
set_pen_width(1.0);
draw_pritial_circle(min_circle, 360);
}

void draw_main_canon_body(int xp, int yp, double L1, double L2, double redius, double a, double b, double w1, double w2, int *xe, int *ye){
double ninty_degree_red = acos(-1.0) / 2;
set_pen_width(1.0);
move_to(xp, yp);
set_heading_radians(0);
turn_right_by_radians(a);
turn_left_by_radians(b);
draw_distance(L1 - redius);
move_to(xp, yp);
set_heading_radians(0);
turn_right_by_radians(a);
turn_left_by_radians(ninty_degree_red);
draw_distance(w1);
turn_right_by_radians(ninty_degree_red + b);
draw_distance(L1 + L2);
turn_right_by_radians(ninty_degree_red - b);
draw_distance(w2 / 2);
get_position(*xe, *ye);
draw_distance(w2 / 2);
turn_right_by_radians(ninty_degree_red - b);
draw_distance(L2 - redius);
}

void simple_canon(const int xg, const int yg, const int degree,int *xe,int *ye) {
int redius = 15;
double w1 = 30, w2 = 20, L1 = 25, L2 = 80;
double a = (acos(-1.0)*degree) / 180;
int xc = xg;
int yc = yg - redius;
double b = asin((w1 - w2) / 2.0 / (L1 + L2));
double xp = xc - L1* sin(a - b);
double yp = yc + L1 * cos(a - b);

//draw circle and center of the circle
simple_circle(xc, yc, redius);

//cannon body
draw_main_canon_body(xp, yp, L1, L2, redius, a, b, w1, w2, xe, ye);
}
