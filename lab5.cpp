#include "library.h"
const double pi = acos(-1.0);
const int xc = 250;
const int yc = 300;
const int r = 150;

int print_in_four(int n)
{
	if (n < 1000)
		print(" ");
	if (n < 100)
		print(" ");
	if (n < 10)
		print(" ");
	print(n);
	return (n);
}

void draw_circle(double xc, double yc, double r, double alpha)
{
	/*
  // use your own circle code
  */
}

void countup(int from, int to, int step)
{
	if (from >= to)
		return;
	else
	{
		move_to(xc, yc);
		set_heading_degrees(from);
		move_distance(r - 10);
		draw_distance(8);
		countup(from + step, to, step);
	}
}

void clock_face()
{
	set_pen_color(color::black);
	set_pen_width(2);
	draw_circle(xc, yc, r, 0);
	countup(0, 359, 30);
}

void second_hand(int second)
{
	move_to(xc, yc);
	set_heading_degrees(second * 6);
	set_pen_width(2);
	draw_distance(140);
}

void minute_hand(int minute, int second)
{
	move_to(xc, yc);
	set_heading_degrees(minute * 6 + second / 10.0);   // 360 degree = 60 mins, so 6 degree 1 min, second / 60 * 6 -> second degree
	set_pen_width(5);
	draw_distance(125);
}

void hour_hand(int hour, int minute)
{
	move_to(xc, yc);
	set_heading_degrees(hour * 30 + minute / 2.0);  // 360 degree = 12 hour, so 30 degree per hr, minute / 60 * 30 -> minute degree
	set_pen_width(7);
	draw_distance(95);
}

void side_bars()
{
	move_to(40, 570);
	set_heading_degrees(0);
	set_pen_color(color::grey);
	set_pen_width(30);
	draw_distance(540);
	move_to(460, 570);
	set_heading_degrees(0);
	set_pen_color(color::grey);

	set_pen_width(30);
	draw_distance(540);
}

void time_and_date()
{
	while (true)
	{
		clock_face();
		const int time = get_clock_time();
		const int date = get_calendar_date();
		int year = date / 10000;
		int month = date % 10000 / 100;
		int day = date % 100;
		int hour = time / 10000;
		int minute = time / 100 % 100;
		int second = time % 100;
		minute_hand(minute);
		second_hand(second);
		hour_hand(hour, minute);
		move_to(160, 100);
		set_font_size(60);
		write_string(hour - 12);
		write_string(":");
		if (minute < 10)
		{
			write_string(0);
			write_string(minute);
		}
		else
			write_string(minute);
		if (hour < 12)
			write_string(" a.m.");
		else
			write_string(" p.m.");
		set_font_size(40);
		move_to(140, 510);
		write_string(day);
		write_string("th of ");
		if (month == 1)
			write_string("January");
		else if (month == 2)
			write_string("February");
		else if (month == 3)
			write_string("March");
		else if (month == 4)
			write_string("April");
		else if (month == 5)
			write_string("May");
		else if (month == 6)
			write_string("June");
		else if (month == 7)
			write_string("July");
		else if (month == 8)
			write_string("August");
		else if (month == 9)
			write_string("September");
		else if (month == 10)
			write_string("October");
		else if (month == 11)
			write_string("November");
		else
			write_string("December");
		move_to(215, 560);
		write_string(year);
		move_to(40, 570);
		set_heading_degrees(0);
		set_pen_color(color::blue);
		set_pen_width(30);
		draw_distance(540 * minute / 60);
		move_to(460, 570);
		set_heading_degrees(0);
		set_pen_color(color::blue);
		set_pen_width(30);
		draw_distance(540 * second / 60);
		wait(.5);  // WAIT IMPORTANT
		side_bars();
		set_pen_color(color::white);
		minute_hand(minute);
		second_hand(second);
		hour_hand(hour, minute);
		move_to(160, 100);
		set_font_size(60);
		write_string(hour - 12);
		write_string(":");
		if (minute < 10)
		{
			write_string(0);
			write_string(minute);
		}
		else
			write_string(minute);
		if (hour < 12)
			write_string(" a.m.");
		else
			write_string(" p.m.");
	}
}

void main()
{
	make_window(500, 600);
	side_bars();
	time_and_date();
}
