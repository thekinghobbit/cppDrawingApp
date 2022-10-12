#include "head.h"
/*
Leif Forrest
december 6th 2021
this is a drawing program that was origenall gonna be an animated face then it was going to be a maze game and none of that worked out
you can change the brush size and color and clear the screen and whatnot. Its pretty fun to mess around with. Also the name of the program is a play on the 
etch i'sketch etch e'sketch? not super sure.

*/
int main(int argc, char* argv[]){


    cout <<" use wasd to draw, r g b c change colors of pen\n f erases the board and p m change the brush size and press x to exit\n";
    myGlutInit(argc, argv);
    glutMainLoop();

    return 0;
}
