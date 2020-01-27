#include "library.h"

const double pi = acos(-1.0);

void draw_cirle(double r, int deg) {
	if (deg <= 360) {
		turn_right_by_degrees(1);
		draw_distance(r * 2 * pi / 360);
		draw_cirle(r, deg + 1);
	}
}

void circle(double x, double y, double r) {
	set_pen_color(color::black);
	set_pen_width(2);
	move_to(x, y - r);
	set_heading_degrees(90);
	draw_cirle(r, 0);
}

void draw_star2(const int x, const int y, const int length)
{
	set_pen_color(color::white);
	start_shape();
	move_to(x, y);
	set_heading_degrees(0);
	turn_left_by_degrees(162);
	draw_distance(length);
	note_position();
	turn_left_by_degrees(144);
	draw_distance(length);
	note_position();
	turn_left_by_degrees(144);
	draw_distance(length);
	note_position();
	turn_left_by_degrees(144);
	draw_distance(length);
	note_position();
	turn_left_by_degrees(144);
	draw_distance(length);
	note_position();
	fill_shape();
}


void draw_star(const int x, const int y, const int length)
{
	move_to(x, y);
	set_pen_color(color::white);
	start_shape();
	draw_distance(length);
	note_position();
	turn_left_by_degrees(72);
	draw_distance(length);
	note_position();
	turn_right_by_degrees(144);
	draw_distance(length);
	note_position();
	turn_left_by_degrees(72);
	draw_distance(length);
	note_position();
	turn_right_by_degrees(144);
	draw_distance(length);
	note_position();
	turn_left_by_degrees(72);
	draw_distance(length);
	note_position();
	turn_right_by_degrees(144);
	draw_distance(length);
	note_position();
	turn_left_by_degrees(72);
	draw_distance(length);
	note_position();
	turn_right_by_degrees(144);
	draw_distance(length);
	note_position();
	turn_left_by_degrees(72);
	draw_distance(length);
	note_position();
	fill_shape();
	turn_right_by_degrees(144);
}



void draw_rectangle()
{
	set_pen_color(color::blue);
	fill_rectangle(0, 0, 370, 280);
	set_pen_color(color::red);
	fill_rectangle(370, 0, 600, 40);
	fill_rectangle(370, 80, 600, 40);
	fill_rectangle(370, 160, 600, 40);
	fill_rectangle(370, 240, 600, 40);
	fill_rectangle(0, 320, 900, 40);
	fill_rectangle(0, 400, 900, 40);
	fill_rectangle(0, 480, 900, 40);
}

void draw_row_of_six_stars(const int x, const int y, const int distance)
{
	draw_star(x, y, 10);
	draw_star(x + distance, y, 10);
	draw_star(x + (2 * distance), y, 10);
	draw_star(x + (3 * distance), y, 10);
	draw_star(x + (4 * distance), y, 10);
	draw_star(x + (5 * distance), y, 10);
}

void draw_row_of_five_stars(const int x, const int y, const int distance)
{
	draw_star(x, y, 10);
	draw_star(x + distance, y, 10);
	draw_star(x + (2 * distance), y, 10);
	draw_star(x + (3 * distance), y, 10);
	draw_star(x + (4 * distance), y, 10);
}

void draw_row_of_six_stars2(const int x, const int y, const int distance)
{
	draw_star2(x, y, 27);
	draw_star2(x + distance, y, 27);
	draw_star2(x + (2 * distance), y, 27);
	draw_star2(x + (3 * distance), y, 27);
	draw_star2(x + (4 * distance), y, 27);
	draw_star2(x + (5 * distance), y, 27);
}

void draw_row_of_five_stars2(const int x, const int y, const int distance)
{
	draw_star2(x, y, 27);
	draw_star2(x + distance, y, 27);
	draw_star2(x + (2 * distance), y, 27);
	draw_star2(x + (3 * distance), y, 27);
	draw_star2(x + (4 * distance), y, 27);
}




void draw_texas_flag()
{
	make_window(1200, 500);
	set_pen_color(color::blue);
	fill_rectangle(0, 0, 400, 500);
	set_pen_color(color::red);
	fill_rectangle(400, 250, 1200, 250);
}


void main() {
	make_window(600, 500);
	set_pen_width(5);
	move_to(200, 200);
	set_heading_degrees(0);
	turn_left_by_degrees(162);
	draw_distance(100);
	turn_left_by_degrees(144);
	draw_distance(100);
	turn_left_by_degrees(144);
	draw_distance(100);
	turn_left_by_degrees(144);
	draw_distance(100);
	turn_left_by_degrees(144);
	draw_distance(100);

	move_to(400, 200);
	set_heading_degrees(0);
	turn_left_by_degrees(150);
	draw_distance(100);
	turn_left_by_degrees(120);
	draw_distance(100);
	turn_left_by_degrees(120);
	draw_distance(100);
	move_to(350, 230);
	set_heading_degrees(0);
	turn_right_by_degrees(90);
	draw_distance(100);
	turn_right_by_degrees(120);
	draw_distance(100);
	turn_right_by_degrees(120);
	draw_distance(100);

	make_window(600, 600);
	set_pen_width(100);
	set_pen_color(color::black);
	draw_point(300, 100);
	set_pen_width(80);
	set_pen_color(color::white);
	draw_point(300, 100);


	make_window(600, 600);
	circle(200, 400, 50);

	draw_texas_flag();
	draw_star2(200, 100, 200);

	//
	make_window(900, 520);
	set_pen_color(color::black);
	set_pen_width(5);
	set_heading_degrees(162);
	draw_rectangle();
	draw_row_of_six_stars2(25, 5, 65);
	draw_row_of_five_stars2(57, 35, 65);
	draw_row_of_six_stars2(25, 65, 65);
	draw_row_of_five_stars2(57, 95, 65);
	draw_row_of_six_stars2(25, 125, 65);
	draw_row_of_five_stars2(57, 155, 65);
	draw_row_of_six_stars2(25, 185, 65);
	draw_row_of_five_stars2(57, 215, 65);
	draw_row_of_six_stars2(25, 245, 65);

}