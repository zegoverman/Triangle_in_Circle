/*
A program to find which verticies of a triangle are contained within the area of a circle. An algorithm is defined in triangle_in_circle.h in order to 
find this information. A GUI has then been created in GUI_in_openGL.h in order to graphically display the circle and triangle
*/

#include <iostream>
#include <cctype>
#include <cstring>

using namespace std;

#include "triangle_in_circle.h"

triangle t1 = triangle(-0.3, 0.3, 0.5, 0.5, 0.7, -0.4); //Meaning of these numbers can be interperted by looking at the triangle_in_circle.h. 
//But they're basically the co-ordinates of the triangle verticies
triangle *pointert1 = &t1;
circle c1 = circle(0, 1, 1); //First 2 digits are circle centre co-ordinate, third is it's radius. See triangle_in_circle.h
circle *pointerc1 = &c1;

#include "GUI_in_openGL.h"

int main(int argc, char **argv){
	
	int window_height = 300, window_width = 300;
	//this is where the stuff I have now made global origonally went. Had to be put in Global scope to be accessed to make the GUI
	triangle_in_circle(pointerc1, pointert1);

	//now display using openGL from here
	glutInit(&argc, argv); //initalize the window
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); //specifies the display mode (single buffer window) and (default colour mode) RGB=red,green,blue
	glutInitWindowPosition(window_width, window_height); //position of window onscreen. (x,y) -1=default value, otherwise choose something that will fit onscreen 
	glutInitWindowSize(300, 300); //chooses the size of the window to be initalized
	glutCreateWindow("GUI"); //this now creates the window, the string dictates the title
	
	//now need to tell GLUT a function that is responsible for rendering.
	shapes *drawing;
	shapes object_drawing;
	drawing = &object_drawing;

	//add initilisation here
	drawing->initilisation();
	glutDisplayFunc(drawing->draw_triangle_and_circle); 
	
	glutMainLoop(); //Tells program you have finished initalising and you can now start rendering

	cout << endl << "input a number to end" << endl;
	int a;
	cin >> a;
	return 0;
}

