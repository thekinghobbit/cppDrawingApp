#include "head.h"

bool keyStates[256]; 
const float DEG2RAD = M_PI/180.0;
int R = 0, G = 0, B = 0;// color values the pencil
float drawSize = .02;// pencil size
void myDisplay(void){

    glClearColor(1, 1, 1, 1);   
    glClear(GL_COLOR_BUFFER_BIT); 

    drawEasyCircle(0,0);// circle ar origin

     
    glFlush();
}
void drawCircle(double r, double x, double y, double R, double G, double B){// just a corcle making funtion
    // cout <<"inside draw circle\n";
    glBegin(GL_POLYGON);  
    // cout <<"inside deeper draw circle\n";

    glColor3f(R, G, B);
    double incr = 0.5; 
    for(double i = 0; i*M_PI/180 < 2*M_PI; i += incr){  
        glVertex3f(x, y, 0);
        glVertex3f(x + r * cos(i * M_PI / 180), y + r * sin(i * M_PI / 180), 0);
        glVertex3f(x + r * cos((incr + i) * M_PI / 180), y + r * sin((incr + i) * M_PI / 180), 0);
    }
    glEnd();  
    
}
void drawEasyCircle(float x, float y){// the same as the last circle but with some presets

    //cout << "Inside Draw Easy Circle" << endl;
    drawCircle(drawSize, x, y, R,G,B);
}
void movePlayer(float distanceX, float distanceY,float distanceZ){// the drawing funciton just makes another circle where ever it is moved
    // glClearColor(0,1,1,0);
    glTranslatef(distanceX,distanceY,distanceZ);
    drawEasyCircle(0,0);
}
void keyPressed (unsigned char key, int x, int y) { 
   
    cout << x << endl;
    keyStates[key] = true; // Set the state of the current key to true/pressed

    if (key == 'w'){ 
        movePlayer(0,.01,.0);
        //cout << "w!\n";
    }
    else if (key == 's'){ 
        movePlayer(0,-.01,.0);
        //cout << "s!\n";
    }   
    else if (key == 'd'){ 
        movePlayer(.01,0,.0);
        //cout << "d!\n";
    }  
    else if (key == 'a'){ 
        movePlayer(-.01,0,.0);
        //cout << "a!\n";
    } 
    else if (key == 'r'){ 
        R = 1, G = 0, B = 0;
        //cout << "r!\n";
    }
    else if (key == 'g'){ 
        R = 0, G = 1, B = 0;
        //cout << "g!\n";
    }
    else if (key == 'b'){ 
        R = 0, G = 0, B = 1;
        //cout << "b!\n";
    } 
    else if (key == 'c'){ 
        R = 0, G = 0, B = 0;
        //cout << "c!\n";
    }
    else if(key == 'f'){
        glClear(GL_COLOR_BUFFER_BIT);// "eraser"
    }
    else if(key == 'p'){
        drawSize += .01;// p and m are pensize 
    }
    else if(key == 'm'){
    drawSize -= .01;
    }
    else if(key =='x'){// leaves program
        exit (0);
    }
    else{
        cout << "error\n";
    }
    glFlush();
}  


void keyUp (unsigned char key, int x, int y) {  
    keyStates[key] = false; // Set the state of the current key to false/not pressed  
} 


void myGlutInit(int argc, char* argv[]){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(800, 800);   // **experiment with different window sizes by changing these arguments
    glutInitWindowPosition(600, 600);   // **experiment with different window locations by changing these arguments
    glutCreateWindow("Rainbow Etch eh sketchy");   // **try  putting different text in your window display
    glutDisplayFunc(myDisplay);
    glutKeyboardFunc(keyPressed);  // specifies which function to call if there is a key down event
    glutKeyboardUpFunc(keyUp);   // specifies which function to call if there is a key up event        

    glutMainLoop();
}