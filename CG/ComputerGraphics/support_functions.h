#include <bits/stdc++.h>

using namespace std;

struct point{
    int x;
    int y;
};

template<typename T>
void print_vec(vector<T> v){

    for(int i=0;i<v.size();i++){
        cout<<v[i]<<", ";
    }
    cout<<endl;
}

template<typename T>
void print_vec(vector< pair<T, T> > v){

    for(int i=0;i<v.size();i++){
        cout<<"("<<v[i].first<<", "<<v[i].second<<"), ";
    }
    cout<<endl;
}

void set_pixel(int x, int y, int r=1, int g=0, int b=0){

    glColor3d(r, g, b);
    glBegin(GL_POINTS);
        glVertex2f(x, y);
    glEnd();
    glFlush();
}

float get_slope(point p1, point p2){

    return (p2.y - p1.y)*1.0/(p2.x - p1.x);
}
