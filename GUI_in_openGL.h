#include <glut.h>
#include <cmath> // for the pi, cos and sin
#define PI 3.141592653589793238

class shapes{
public:
	static void draw_triangle_and_circle() //necessary for it to be static to prevent the this pointer being passes as open gl is an C API that can't handle this
	{
		//First draw the triangle
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //clears buffers to preset values

		glMatrixMode(GL_MODELVIEW); //so we are operating on the modelview matrix
		glLoadIdentity(); //ensure the modelview matrix is at the default

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
//reshape function - for when the display window is resized
void reshape(int width, int height)
{
	if (height == 0) (height = 1); //to prevent a divide by zero in the next statment

	float ratio = 1.0 * width / height; //ratio of width to height
	// Use the Projection Matrix
	glMatrixMode(GL_PROJECTION);

	// Reset Matrix
	glLoadIdentity();

	// Set the viewport to be the entire window
	glViewport(0, 0, width, height);

	// Set the correct perspective.
	gluPerspective(45, ratio, 1, 1000); //establishes perspective parameters (1,2,3,4)
	//1=field of view angle in the yz plane. 2=defines relation between width and height of the viewport. last 2 define near and far clipping planes.
	//anything closer than near or further than far will be clipped from the image

	// Get Back to the Modelview
	glMatrixMode(GL_MODELVIEW);
}