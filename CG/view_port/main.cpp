#include <windows.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <bits/stdc++.h>

#define SCREEN_WIDTH 1080
#define SCREEN_HEIGHT 720

using namespace std;

void draw_border(int x1, int y1, int x2, int y2){

    int sep = 20;
    x1 += sep;
    y1 += sep;
    x2 -= sep;
    y2 -= sep;

    cout<<"In draw_border"<<endl;
    glColor3d(1, 0, 0);
    glBegin(GL_LINE_STRIP);
        glVertex2d(x1, y1);
        glVertex2d(x1, y1+y2);
        glVertex2d(x1+x2, y1+y2);
        glVertex2d(x1+x2, y1);
        glVertex2d(x1, y1);
    glEnd();
}

static void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    draw_border(0, 0, SCREEN_WIDTH/2, SCREEN_HEIGHT/2);
    draw_border(0, SCREEN_HEIGHT/2, SCREEN_WIDTH/2, SCREEN_HEIGHT/2);
    draw_border(SCREEN_WIDTH/2, 0, SCREEN_WIDTH/2, SCREEN_HEIGHT/2);
    draw_border(SCREEN_WIDTH/2, SCREEN_HEIGHT/2, SCREEN_WIDTH/2, SCREEN_HEIGHT/2);

    glFlush();
}

void log(int x, int y, int u, int v){
    cout<<" | "<<x<<", "<<y<<", "<<u<<", "<<v<<endl;
}

void view_port(int x, int y){

    cout<<"vp1";
    //log(0, 0, SCREEN_WIDTH/2, SCREEN_HEIGHT/2);
    glViewport(0, 0, SCREEN_WIDTH/2, SCREEN_HEIGHT/2);
    glColor3d(1, 0, 0);
    glPointSize(5);
    glBegin(GL_POINTS);
        glVertex2d(x, y);
    glEnd();
    glFlush();

    cout<<"vp2";
    //log(SCREEN_WIDTH/2, 0, SCREEN_WIDTH/2, SCREEN_HEIGHT/2);
    glViewport(SCREEN_WIDTH/2, 0, SCREEN_WIDTH/2, SCREEN_HEIGHT/2);
    glColor3d(0, 1, 0);
    glPointSize(5);
    glBegin(GL_POINTS);
        glVertex2d(x, y);
    glEnd();
    glFlush();

    cout<<"vp3";
    //log(0, 0, SCREEN_WIDTH/2, SCREEN_HEIGHT/2);
    glViewport(0, 0, SCREEN_WIDTH/2, SCREEN_HEIGHT/2);
    glColor3d(0, 0, 1);
    glPointSize(5);
    glBegin(GL_POINTS);
        glVertex2d(x, y);
    glEnd();
    glFlush();

    cout<<"vp4";
    //log(SCREEN_WIDTH/2, SCREEN_HEIGHT/2, SCREEN_WIDTH/2, SCREEN_HEIGHT/2);
    glViewport(SCREEN_WIDTH/2, SCREEN_HEIGHT/2, SCREEN_WIDTH/2, SCREEN_HEIGHT/2);
    glColor3d(1, 0, 1);
    glPointSize(5);
    glBegin(GL_POINTS);
        glVertex2d(x, y);
    glEnd();
    glFlush();
}


static void mouse(int button, int status, int x, int y){

    if(button==GLUT_LEFT_BUTTON && status==GLUT_DOWN){
        y = SCREEN_HEIGHT - y;
        cout<<"Point: "<<x<<","<<y<<endl;
        view_port(x, y);
    }
    else if(button==GLUT_RIGHT_BUTTON && status==GLUT_DOWN){
        glutPostRedisplay();
        cout<<"Clearing screen..."<<endl;
    }
}

static void init(){

    glClearColor(0,0,0,0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 1080, 0, 720);
}

int main(int argc, char *argv[]){

    glutInit(&argc, argv);
    glutInitWindowSize(1080, 720);
    glutInitWindowPosition(0, 0);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);

    glutCreateWindow("View ports");
    init();

    glutDisplayFunc(display);

    glutMouseFunc(mouse);
    glutMainLoop();

    return EXIT_SUCCESS;
}
