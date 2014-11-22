#include <glut.h>
#include <cmath> // for the pi, cos and sin
#define PI 3.141592653589793238

class shapes{
public:
	void initilisation(){
		glClearColor(0.0, 0.0, 0.0, 0.0);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		//find the maximum co-ordinate so we initiliase the display window to be the right size
		float complete_max_value;
		if (pointert1->max_coordinate() > pointerc1->max_coordinate()) complete_max_value = pointert1->max_coordinate();
		else complete_max_value = pointerc1->max_coordinate();
		glOrtho(-complete_max_value, complete_max_value, -complete_max_value, complete_max_value, -complete_max_value, complete_max_value); //now works as expected
	}
	static void draw_triangle_and_circle() //necessary for it to be static to prevent the this pointer being passes as open gl is an C API that can't handle this
	{
		glClear(GL_COLOR_BUFFER_BIT);

		glBegin(GL_TRIANGLES); //define what kind of shape I'm drawing - a triangle
		glColor3f(0, 1, 1); // (red amount, green amount, blue amount) 0=no internsity, 1=full intensity. (011) = cyan
		glVertex3f(pointert1->point[0][0], pointert1->point[0][1], 0); // (x1,y1,0) from triangle class. co-ordinates defined in glvortex as (x,y,z)
		glVertex3f(pointert1->point[1][0], pointert1->point[1][1], 0); // (x2,y2,0)
		glVertex3f(pointert1->point[2][0], pointert1->point[2][1], 0); // (x3,y3,0)
		glEnd();
		
		//Now draw the circle
		glBegin(GL_LINE_LOOP); //define shape - loads of interconnected lines
		glColor3f(1, 0, 0); //red
		float i, segments = 300;
		float angle;
		float x, y;
		for (i = 0; i < segments; i++){
			angle = 2 * PI * (i / segments);
			x = (pointerc1->radius) * cos(angle); //cos and sin are in radians mode
			y = (pointerc1->radius) * sin(angle);
			//now use these co-ordinates to draw each point
			glVertex2f((pointerc1->centre[0][0] + x), (pointerc1->centre[0][1] + y)); //output the vertex
		}
		
		glEnd();
		glFlush(); //empties all the implementation buffers (e.g network buffer, graphics accelerator) so ensures drawing commands are actually implemented
				   //not just stored in a buffer
	}
};
