/*
A program to find which verticies of a triangle are contained within the area of a circle. An algorithm is defined in triangle_in_circle.h in order to 
find this information. A GUI has then been created in GUI_in_openGL.h in order to graphically display the circle and triangle

The algorithm works fine regardless of the numbers you put in. If you want to see the graphical respresentation then certain parameters have to be met
*/

#include <iostream>
#include <cctype>
#include <cstring>

using namespace std;

#include "problem1.h"
#include "problem2.h"
#include "reverse_string.h"
#include "test.h"
#include "triangle_in_circle.h"

//the co-ordinates of my default space for the GUI are -1 to +1 on the x and y axis
triangle t1 = triangle(-0.3, 0.3, 0.5, 0.5, 0.7, -0.4); //needs to be between -1 and 1. Plus it needs to be a legitimate triangle shape. Meaning of these numbers
//can be interperted by looking at the triangle_in_circle.h. But they're basically the co-ordinates of the triangle verticies
triangle *pointert1 = &t1;
circle c1 = circle(0, 0, 1); //radius can only seem to be 1 for the GUI. First 2 digits are circle centre co-ordinate, third is it's radius.
circle *pointerc1 = &c1;

/*
Note any numbers can be input above for the algorithm to work and to obtain the correct results via the command line, but only certain 
numbers are valid if you want to see them graphically represented in OpenGL
*/

#include "GUI_in_openGL.h"

int main(int argc, char **argv){
	//this is where the stuff I have now made global origonally went. Had to be put in Global scope to be accessed to make the GUI
	triangle_in_circle(pointerc1, pointert1);
	

	//now display using openGL from here
	glutInit(&argc, argv); //initalize the window
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); //specifies the display mode (single buffer window) and (default colour mode) RGB=red,green,blue
	glutInitWindowPosition(300,300); //position of window onscreen. (x,y) -1=default value, otherwise choose something that will fit onscreen 
	glutInitWindowSize(300, 300); //chooses the size of the window to be initalized
	glutCreateWindow("GUI"); //this now creates the window, the string dictates the title
	
	//now need to tell GLUT a function that is responsible for rendering.
	shapes *drawing;
	glutDisplayFunc(drawing->draw_triangle_and_circle); 
	//without parenthesis means it is a pointer to the function rather than the function itself (this is what Displayfunc requires)
	
	glutMainLoop(); //Tells program you have finished initalising and you can now start rendering

	cout << endl << "input a number to end" << endl;
	int a;
	cin >> a;
	return 0;
}

