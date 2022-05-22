#include <windows.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <bits/stdc++.h>

#include "support_functions.h"

#define SCREEN_WIDTH 1080
#define SCREEN_HEIGHT 720

using namespace std;

vector<point> points;

#include "fill_polygon.h"

// Display Functions
static void display(void){

    glClear(GL_COLOR_BUFFER_BIT);

    glFlush();
}

// Keyboard & Mouse
static void keyboard(unsigned char key, int x, int y){

    if(key=='f'){
        cout<<"Pressed f..."<<endl;
        fill_keyboard();
    }
}

static void mouse(int button, int status, int x, int y){

    if(button==GLUT_LEFT_BUTTON && status==GLUT_DOWN){
        y = SCREEN_HEIGHT - y;

        set_pixel(x, y);
        cout<<"Clicked: "<<x<<", "<<y<<endl;
        points.push_back({x, y});
/*
        if(points.size()==2){
            glBegin(GL_LINE_LOOP);
                glVertex2f(points[0].x, points[0].y);
                glVertex2f(points[1].x, points[0].y);
                glVertex2f(points[1].x, points[1].y);
                glVertex2f(points[0].x, points[1].y);
            glEnd();
            glFlush();

            int min_x = min(points[0].x, points[1].x);
            int max_x = (min_x==points[0].x)? points[1].x: points[0].x;
            int min_y = min(points[0].y, points[1].y);
            int max_y = (min_y==points[0].y)? points[1].y: points[0].y;

            //simple_fill_polygon(min_x, max_x, min_y, max_y);
            //flood_fill_polygon(x, y);
        }
*/
    }
    else if(button==GLUT_RIGHT_BUTTON && status==GLUT_DOWN){

        cout<<"Clearing Screen..."<<endl<<endl;
        for (int i=0;i<points.size();i++){
            points.pop_back();
        }
        glutPostRedisplay();
    }
}

void init(){

    glClearColor(0,0,0,0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, SCREEN_WIDTH, 0, SCREEN_HEIGHT);
}

void menu(){

    cout<<"*** Computer Graphics ***"<<endl;
    int resp;
    cout<<"1. Line Drawing\n2.Line Clipping\n3.Polygon Clipping"<<endl;
    cout<<"(1/2/4)---> ";
    cin>>resp;

    if(resp==1){

    }
    else if(resp==2){

    }
    else{

    }
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT);
    glutInitWindowPosition(0,0);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);

    glutCreateWindow("Computer Graphics");
    init();

    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutKeyboardFunc(keyboard);

    glutMainLoop();

    return EXIT_SUCCESS;
}
