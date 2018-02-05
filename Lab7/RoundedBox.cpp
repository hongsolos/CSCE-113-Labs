//------------------------------------------------------
//*  Rounded Box        By Han Hong      Lab 7         |        
//*  CSCE 113 - 501                                    |
//*  UIN: 824000237                                    |                                          
//------------------------------------------------------

#include <Simple_window.h>

Simple_window win(Point(100,100), 600,400, "semi-ellipse");
struct Box: Shape{
    Box(Point p, int ww, int hh): w(ww), h(hh) { add(Point(p.x+ww,p.y+hh));  }

    void draw_lines() const
    {
        fl_line(475,200,175,200);
		fl_line(175,500,475,500);
		fl_line(100,250,100,450);
		fl_line(550,250,550,450);
		fl_arc(100, 200,w,h,90,180);
		fl_arc(400, 200,w,h,0,90);
		fl_arc(100, 400,w,h,180,270);
		fl_arc(400, 400,w,h,270,360);
    }

	private:
		int w;
		int h;
	};

int main() {
    using namespace Graph_lib; 

    Box b(Point(100,100),100,50);
    win.attach(b);
    win.wait_for_button();
}