#include <cstdlib> //for rand()
#include <math.h> //for square root

class triangle{
public:
	int number_of_points = 3; //3 as it is a triangle
	float point[3][2]; // array of co-ordinates, [x][y] x3
	triangle(){
		point[0][0] = (float)rand() / (float)RAND_MAX; //this ensure the random number is between 0 and 1
		point[0][1] = (float)rand() / (float)RAND_MAX; //necessary for the GUI, not necessary for the algorithm
		point[1][0] = (float)rand() / (float)RAND_MAX; //needs casting as rand() default output is an integer
		point[1][1] = (float)rand() / (float)RAND_MAX;
		point[2][0] = (float)rand() / (float)RAND_MAX;
		point[2][1] = (float)rand() / (float)RAND_MAX;
	}
	triangle(float x1, float y1, float x2, float y2, float x3, float y3){
		point[0][0] = x1;
		point[0][1] = y1;
		point[1][0] = x2;
		point[1][1] = y2;
		point[2][0] = x3;
		point[2][1] = y3;
	}
};

class circle{
public:
	float radius;
	float centre[1][2];
	circle(){
		centre[0][0] = (float)rand() / (float)RAND_MAX;
		centre[0][1] = (float)rand() / (float)RAND_MAX;
		radius = (float)rand() / (float)RAND_MAX;
	}
	circle(int x, int y, int z){
		centre[0][0] = x;
		centre[0][1] = y;
		radius = z;
	}
};

float pyth(float x, float y){
	float hypot = sqrt(pow(x, 2) + pow(y, 2));
	//float hypot = sqrt(((x) ^ 2) + ((y) ^ 2));
	return hypot;
}

float find_difference(float one_point, float second_point){
	float difference = one_point - second_point;
	return difference;
}

void triangle_in_circle(circle* c, triangle* t){
	//function to determine if all three points in a triangle are within a circle
	bool is_it_inside = 1;
	int i, j=0;
	float diffx;
	float diffy;
	float distance;
	for (i = 0; i < 3; i++){
		diffx = find_difference(c->centre[0][j], t->point[i][j]); //find x difference
		diffy = find_difference(c->centre[0][j + 1], t->point[i][j + 1]); //find y difference
		distance = pyth(diffx, diffy); //find the actual distance from the centre point using pythagoras
		if (distance > c->radius){ //check to see if the point is within the radius of the circle
			is_it_inside = 0;
			cout << "point " << (i + 1) << " is not within the circle" << endl;
		}
	}
	if (is_it_inside == 1){
		cout << "it is inside the circle";
	}
}
