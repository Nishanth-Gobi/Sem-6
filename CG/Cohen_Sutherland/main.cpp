#include <windows.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <bits/stdc++.h>

using namespace std;

#define SCREEN_WIDTH 1080
#define SCREEN_HEIGHT 720

void init(){

    glClearColor(0,0,0,0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, SCREEN_WIDTH, 0, SCREEN_HEIGHT);
}

int cnt;
vector< vector<int> > window_coords;
vector< vector<int> > line_coords;

static void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    if(window_coords.size()==2){
        glColor3d(1, 0, 0);
        glBegin(GL_LINE_LOOP);
            glVertex2d(window_coords[0][0], window_coords[0][1]);
            glVertex2d(window_coords[1][0], window_coords[0][1]);
            glVertex2d(window_coords[1][0], window_coords[1][1]);
            glVertex2d(window_coords[0][0], window_coords[1][1]);
        glEnd();
        glFlush();
    }

    if(line_coords.size()==2){
        glColor3d(0, 1, 0);
        glBegin(GL_LINES);
            glVertex2d(line_coords[0][0], line_coords[0][1]);
            glVertex2d(line_coords[1][0], line_coords[1][1]);
        glEnd();
        glFlush();
    }

    glFlush();
}

vector<int> get_intersection(vector<int> a, vector<int> b, int x=0, int y=0){

    // ab is a line
    vector<int> intersection;

    float m1 = ((b[1]-a[1])*0.1)/((b[0]-a[0])*1.0);
    float c = a[1] - m1*a[0];
    if(x!=0){
        float yy = m1*x + c;
        intersection.push_back(x);
        intersection.push_back(yy);
    }
    else if(y!=0){
        float xx = (y - c)/(m1*1.0);
        intersection.push_back(xx);
        intersection.push_back(y);
    }

    cout<<endl;
    cout<<"In intersention:"<<endl;
    cout<<"\tm1 = "<<m1<<" | c = "<<c<<endl;
    cout<<endl;

    return intersection;
}

void print_vec(vector<int> v){
    cout<<endl;
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" | ";
    }
    cout<<endl;
}

void cohen_sutherland(){

    cout<<"\nIn cohen_sutherland"<<endl;

    vector<int> intersetion = get_intersection(line_coords[0], line_coords[1], 0, window_coords[0][1]);
    cout<<"2nd line: y = "<<window_coords[0][1]<<endl;
    cout<<"Intersection: ";
    print_vec(intersetion);

    glPointSize(5);
    glColor3d(0, 0, 1);
    glBegin(GL_POINTS);
        glVertex2d(intersetion[0], intersetion[1]);
    glEnd();
    glFlush();
}

static void mouse(int button, int status, int x, int y){
    if(button==GLUT_LEFT_BUTTON && status==GLUT_DOWN){

        y = SCREEN_HEIGHT - y;
        vector<int> point;
        point.push_back(x);
        point.push_back(y);

        glPointSize(5);
        glColor3d(1,1,1);
        glBegin(GL_POINTS);
            glVertex2d(x, y);
        glEnd();
        glFlush();

        if(cnt<2){
            cout<<"Window co-ord "<<cnt+1<<": "<<x<<", "<<y<<endl;
            window_coords.push_back(point);
            cnt++;
        }
        else if (cnt<4){
            cout<<"Line co-ord "<<cnt+1<<": "<<x<<", "<<y<<endl;
            line_coords.push_back(point);
            cnt++;
        }
        else if(cnt==4){
            glutPostRedisplay();
            cohen_sutherland();
        }
    }
    if(button==GLUT_RIGHT_BUTTON && status==GLUT_DOWN){
        cout<<"Clearing Screen..."<<endl;
        window_coords.pop_back();
        window_coords.pop_back();
        line_coords.pop_back();
        line_coords.pop_back();
        cnt = 0;
        glutPostRedisplay();
    }
}

static void keyboard(unsigned char key, int x, int y){}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT);
    glutInitWindowPosition(0,0);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);

    glutCreateWindow("Cohen Sutherland");
    init();

    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutKeyboardFunc(keyboard);

    glutMainLoop();

    return EXIT_SUCCESS;
}
