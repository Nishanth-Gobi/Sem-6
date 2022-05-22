#include<windows.h>
#include<GL/glut.h>
#include<stdlib.h>
#include<bits/stdc++.h>

using namespace std;

#define SCREEN_WIDTH 1080
#define SCREEN_HEIGHT 720

// Font creating using bitmap, rectangular filling algo, YX algo

void init()
{
    glClearColor(0,0,0,0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, SCREEN_WIDTH, 0, SCREEN_HEIGHT);
}

static void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glFlush();
}

void set_pixel(int x, int y){
    glBegin(GL_POINTS);
        glVertex2f(x, y);
    glEnd();
    glFlush();
}

void display_window(vector< vector<int> > points, int r, int g, int b){

    // Clipping Window
    glColor3d(r, g, b);
    glBegin(GL_LINE_LOOP);
        glVertex2f(points[0][0], points[0][1]);
        glVertex2f(points[1][0], points[0][1]);
        glVertex2f(points[1][0], points[1][1]);
        glVertex2f(points[0][0], points[1][1]);
    glEnd();
    glFlush();
}

void display_driver(vector< vector<int> > points, int r, int g, int b){

    // Displaying Polygon
    glColor3d(r, g, b);
    glBegin(GL_LINE_LOOP);
    for(int i=0;i<points.size();i++){

        glVertex2f(points[i][0], points[i][1]);
    }
    glEnd();
    glFlush();
}

int get_type(vector<int> p1, vector<int> p2, int clipper, int bound){

    int pos = 0;
    if (clipper == 2 || clipper==3){
        bound *=-1;
        pos = 1;
    }

    if(p1[pos]<bound && p2[pos]<bound){ // Out-Out
            return 0;
    }
    if(p1[pos]<bound && p2[pos]>bound){ // Out-In
            return 1;
    }
    if(p1[pos]>bound && p2[pos]>bound){ // In-In
            return 2;
    }
    if(p1[pos]>bound && p2[pos]<bound){ // In-Out
            return 3;
    }
}

void print_points(vector< vector<int> > vec){
    for(int i=0;i<vec.size();i++){
        cout<<"Point "<<i<<": "<<vec[i][0]<<", "<<vec[i][1]<<endl;
    }
}

point intersection(vector<point> line1, vector<point> line2){

    float m1 = (line1[1].y - line1[0].y)/(line1[1].x - line1[0].x);

    // Represent the line in ax+by+c form
    float a1 = m1
    float b1 = -1;
    float c1 = line1[0].y - m1*line1[0].x;

    float m2 = (line2[1].y - line2[0].y)/(line2[1].x - line2[0].x);

    // Represent the line in ax+by+c form
    float a2 = m2
    float b2 = -1;
    float c2 = line2[0].y - m2*line2[0].x;

    float inter_x = (b1*c2 - b2*c1)/(a1*b2 - a2*b1);
    float inter_y = (a2*c1 - a1*c2)/(a1*b2 - a2*b1);

    point inter;
    inter.x = inter_x;
    inter.y = inter_y;

    return
}

void sutherland_hodgeman(vector< vector<int> > window, vector< vector<int> > polygon){

    int left_x = window[0][0];
    int bottom_y = window[0][1];
    int right_x = window[1][0];
    int top_y = window[1][1];

    cout<<"Window: "<<endl;
    print_points(window);
    cout<<"Polygon: "<<endl;
    print_points(polygon);

    char type[][8] = {"Out-Out", "Out-In", "In-In", "In-Out"};
    int t;
    int ps = polygon.size();

    // Left Clipper
    for(int i=0;i<ps;i++){
        t = get_type(polygon[i], polygon[(i+1)%ps], 0, left_x);
        cout<<"LC: Points "<<i<<" & "<<(i+1)%ps<<": "<<type[t]<<endl;
    }
    cout<<endl;
    // Bottom Clipper
    for(int i=0;i<polygon.size();i++){
        t = get_type(polygon[i], polygon[(i+1)%ps], 1, bottom_y);
        cout<<"BC: Points "<<i<<" & "<<(i+1)%ps<<": "<<type[t]<<endl;
    }
    cout<<endl;
    // Right Clipper
    for(int i=0;i<polygon.size();i++){
        t = get_type(polygon[i], polygon[(i+1)%ps], 2, right_x);
        cout<<"RC: Points "<<i<<" & "<<(i+1)%ps<<": "<<type[t]<<endl;
    }
    cout<<endl;
    // Top Clipper
    for(int i=0;i<polygon.size();i++){
        t = get_type(polygon[i], polygon[(i+1)%ps], 3, top_y);
        cout<<"TC: Points "<<i<<" & "<<(i+1)%ps<<": "<<type[t]<<endl;
    }
}

static void mouse(int button, int status, int x, int y){

    static int flag = 0;
    static vector< vector<int> > window;
    static vector< vector<int> > polygon;

    if(x==-1 && y==-1){
        flag = -1;
    }

    if(button==GLUT_LEFT_BUTTON && status==GLUT_DOWN){
        y = SCREEN_HEIGHT - y;

        set_pixel(x, y);
        cout<<"Point: "<<x<<" , "<<y<<" | flag: "<<flag<<endl;

        vector<int> point;
        point.push_back(x);
        point.push_back(y);

        if(flag<0){
            cout<<"Display..."<<endl;
            display_window(window, 1, 0, 0);
            display_driver(polygon, 1, 1, 0);
            cout<<"Clipping..."<<endl;
            sutherland_hodgeman(window, polygon);
        }
        else if(flag<2){
            cout<<"Window co-ord"<<endl;
            window.push_back(point);
            flag++;
        }
        else{
            cout<<"Polygon co-ord"<<endl;
            polygon.push_back(point);
        }
    }
    else if(button==GLUT_RIGHT_BUTTON && status==GLUT_DOWN){
        cout<<"Clearing screen..."<<endl;
        for(int i=0;i<window.size();i++){
            window.pop_back();
        }
        for(int i=0;i<polygon.size();i++){
            polygon.pop_back();
        }
        glutPostRedisplay();
        flag=0;
    }
}

static void key(unsigned char key, int x, int y)
{
    if(key=='d'){
        mouse(GLUT_LEFT_BUTTON, GLUT_DOWN, -1, -1);
    }
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT);
    glutInitWindowPosition(0,0);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);

    glutCreateWindow("GLUT Shapes");
    init();

    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutKeyboardFunc(key);

    glutMainLoop();

    return EXIT_SUCCESS;
}
