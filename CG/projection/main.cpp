#include <windows.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <bits/stdc++.h>

using namespace std;

GLfloat ex = 0.0, ey = 0.0, ez = -3.0;

void init(){

    glEnable(GL_DEPTH_TEST);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    gluLookAt(ex, ey, ez, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
}

static void key(unsigned char key, int x, int y){

    switch(key){

    case 27:
    case 'q':
        exit(0);
        break;
    case '+':
        cout<<"+ Pressed...";
        ez += 0.5;
        break;
    case '-':
        cout<<"- Pressed...";
        ez -= 0.5;
        break;
    }
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(ex, ey, ez, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
    glutPostRedisplay();
}

static void arrowKey(int key, int x, int y){

    cout<<key<<"pressed"<<endl;
    switch(key){

    case GLUT_KEY_LEFT:
        cout<<"GLUT_KEY_LEFT pressed...";
        ex -= 0.5;
        break;

    case GLUT_KEY_RIGHT:
        ex += 0.5;
        break;

    case GLUT_KEY_UP:
        ey -= 0.5;
        break;

    case GLUT_KEY_DOWN:
        ey += 0.5;
        break;
    }
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(ex, ey, ez, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
    glutPostRedisplay();
}

static void mouse(int button, int status, int x, int y){

}


GLfloat vertices[8][3] = {
                            {-1.0, -1.0, -1.0}, {-1.0, 1.0, 1.0},
                            {1.0, 1.0, 1.0}, {1.0, -1.0, 1.0},
                            {-1.0, -1.0, -1.0}, {-1.0, 1.0, -1.0},
                            {1.0, 1.0, -1.0}, {1.0, -1.0, -1.0}
                        };

GLfloat colors[8][3] = {
                        {0.0, 0.0, 0.0}, {1.0, 0.0, 0.0},
                        {1.0, 1.0, 0.0}, {0.0, 1.0, 0.0},
                        {1.0, 1.0, 1.0}, {0.0, 0.0, 1.0},
                        {1.0, 0.0, 0.0}, {0.0, 1.0, 0.0}
                    };

void quad(int a, int b, int c, int d){

    glBegin(GL_QUADS);
        glVertex3fv(vertices[a]);
        glVertex3fv(vertices[b]);
        glVertex3fv(vertices[c]);
        glVertex3fv(vertices[d]);
    glEnd();
}

void triangle(int a, int b, int c){

    glBegin(GL_QUADS);
        glVertex3fv(vertices[a]);
        glVertex3fv(vertices[b]);
        glVertex3fv(vertices[c]);
    glEnd();
}

void mydraw(){

    glColor3f(1.0, 0.0, 0.0);
    glColor3fv(colors[0]);
    quad(0, 3, 2, 1);
    //triangle(0, 3, 2);
    glColor3fv(colors[1]);
    quad(2, 3, 7, 6);
    //triangle(2, 3, 7);
    glColor3fv(colors[2]);
    quad(0, 4, 7, 3);
    //triangle(0, 4, 7);
    glColor3fv(colors[3]);
    quad(1, 2, 6, 5);
    //triangle(1, 2, 6);
    glColor3fv(colors[4]);
    quad(4, 5, 6, 7);
    //triangle(4, 5, 6);
}

void drawObject(){

    glColor3f(0.7, 0.0, 0.5);
    glutWireDodecahedron();
    glColor3f(0.0, 1.0, 1.0);
    //glTranslatef(-2.0, 1.0, 1.0);
    mydraw();
    //glutWireCube(2.0);
}

void resize(int width, int height){

    double aspect;
    glViewport(0, 0, width, height);
    aspect = (double) width/ (double) height;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    cout<< "Aspect ratio: "<<aspect;

    if (aspect<1.0){
        glOrtho(-4., 4. ,-4./aspect, 4./aspect, 1., 100.);
    }
    else{
        glOrtho(-4.*aspect, 4.*aspect, -4., 4., 1., 100.);
    }
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0., 0., 5., 0., 0., 0., 0., 1., 0.);
}

static void display(void)
{
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    drawObject();
    glutSwapBuffers();
}

static void idle(void){
    glutPostRedisplay();
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(1080,720);
    glutInitWindowPosition(0,0);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

    glutCreateWindow("3D Projection");

    glutReshapeFunc(resize);
    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutKeyboardFunc(key);
    glutSpecialFunc(arrowKey);

    init();

    glutMainLoop();

    return EXIT_SUCCESS;
}
