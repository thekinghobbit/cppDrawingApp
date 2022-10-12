#include <GL/glut.h>   //opengL library
#include <GL/freeglut.h>    //freeglut library
#include <math.h>   //cos, sin, M_PI
#include <unistd.h>  // sleep(), usleep()
#include <iostream>

using namespace std;

void myDisplay(void);
void drawCircle(double r, double x, double y, double R, double G, double B);// r = radius, x and y = location, RGB = color
void drawEasyCircle(float x, float y);// a presized circle at a point
void myGlutInit(int argc, char* argv[]);// idk if this need to be here
void keyPressed (unsigned char key, int x, int y);
void keyUp (unsigned char key, int x, int y);
void movePlayer(float distanceX, float distanceY,float distanceZ);// annoying movement function
