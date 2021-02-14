#include "Simple_window.h"
#include "Graph.h"

using namespace Graph_lib;

int main()

try
{

	Point tl{ 100,100 };
	Simple_window win{ tl,600,400,"Canvas" };
	Graph_lib::Polygon poly;
	poly.add(Point{ 300,200 });
	poly.add(Point{ 350,100 });
	poly.add(Point{ 400,200 });
	poly.set_color(Color::red);
	poly.set_style(Line_style(Line_style::dash, 4));
	win.attach(poly);
	win.wait_for_button();

	Axis xa{ Axis::x,Point{20,300},280,10,"x axis" };
	//make an axis, axis is a kind of shape
	// x axis, means horizontal starting at (20,300), 280 pixals long
	//10 "notches, label it x axis
	win.attach(xa);
	win.set_label("Canvas #2");
	win.wait_for_button();

	Axis ya{ Axis::y,Point{20,300},280,10,"y axis" };
	ya.set_color(Color::cyan);
	// choose a color
	ya.label.set_color(Color::dark_red);
	// choose a color for the text
	win.attach(ya);
	win.set_label("Canvas #3");
	win.wait_for_button();

	Function sine{ sin,0,100,Point{20,150},1000,50,50 };
	//sine curve plot sin() in range [0:100] with (0,0)at (20,150)
	//using 1000 points; scale x values *50,scale y values *50
	win.attach(sine);
	win.set_label("Canvas #4");
	win.wait_for_button();

	Graph_lib::Rectangle r{ Point{200,200},100,50 };
	//top left corner,width,height
	r.set_fill_color(Color::yellow);
	win.attach(r);
	win.set_label("Canvas #6");
	win.wait_for_button();

	Closed_polyline poly_rect;
	poly_rect.add(Point{ 100,50 });
	poly_rect.add(Point{ 200,50 });
	poly_rect.add(Point{ 200,100 });
	poly_rect.add(Point{ 100,100 });
	poly_rect.add(Point{ 50,75 });
	poly_rect.set_fill_color(Color::green);
	win.attach(poly_rect);
	win.set_label("Canvas #7");
	win.wait_for_button();

	Text t{ Point{150,150},"Hello Graphical World!" };
	win.attach(t);
	win.set_label("Canvas #8");
	win.wait_for_button();

	t.set_font(Font::times_bold);
	t.set_font_size(20);
	win.set_label("Canvas #9");
	win.wait_for_button();

	Image ii{ Point{100,50},"image.jpg" };
	// 400*212-pixel jpg
	win.attach(ii);
	win.set_label("Canvas #10");
	win.wait_for_button();

}
catch (exception& e) {
	// error reporting
	return 1;
}
catch (...) {
	//more error reporting
	return 2;
}
