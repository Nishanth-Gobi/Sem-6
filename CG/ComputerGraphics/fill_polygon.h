// Polygon Fill Algorithms

void simple_fill_polygon(int min_x, int max_x, int min_y, int max_y){

    for(int i=min_x;i<max_x;i++){
        for(int j=min_y;j<max_y;j++){
            set_pixel(i, j);
        }
    }
}

void flood_fill_polygon(int x, int y){

    if(TRUE){
        return;
    }

}

struct node{

    point p1;
    point p2;
    node* next;
};

node get_edge_list(vector<point> points){

    node* ptr = new node;
    ptr->p1 = points[0];
    ptr->p2 = points[1];

    for(int i=1;i<points.size()-1;i++){

        node* n = new node;
        n->p1 = points[i];
        n->p2 = points[i+1];
        ptr->next = n;
        ptr = n;
    }


}

void active_edge_list(int min_x, int max_x, int min_y, int max_y, vector<point> points){

    int scan_line_y = min_y - 10;
    while(scan_line_y < max_y + 10){

        // Drawing the scan line
        glColor3d(0, 0, 1);
        glBegin(GL_LINES);
            glVertex2f(min_x - 10, scan_line_y);
            glVertex2f(max_x + 10, scan_line_y);
        glEnd();
        glFlush();

        // Highlighting the polygon fill area
        //edge_list = get_edge_list(points);

        scan_line_y += 1;
    }

/*
    float m = get_slope(p1, p2);
    float dx = 1/m;

    while(dy>0){

        x += dx;
        dy -= 1;
    }
*/
}


static void polygon_fill_mouse(int button, int status, int x, int y){

    if(button==GLUT_LEFT_BUTTON && status==GLUT_DOWN){
        y = SCREEN_HEIGHT - y;

        set_pixel(x, y);
        cout<<"Clicked: "<<x<<", "<<y<<endl;
        points.push_back({x, y});
    }
    else if(button==GLUT_RIGHT_BUTTON && status==GLUT_DOWN){

        cout<<"Clearing Screen..."<<endl<<endl;
        for (int i=0;i<points.size();i++){
            points.pop_back();
        }
        glutPostRedisplay();
    }
}

static void fill_keyboard(){

    int min_x = SCREEN_WIDTH + 1;
    int max_x = 0;
    int min_y = SCREEN_HEIGHT + 1;
    int max_y = 0;

    for(int i=0;i<points.size();i++){

        min_x = min(min_x, points[i].x);
        max_x = max(max_x, points[i].x);
        min_y = min(min_y, points[i].y);
        max_y = max(max_y, points[i].y);
    }

    cout<<"Min x: "<<min_x<<" | Max x: "<<max_x<<endl;
    cout<<"Min y: "<<min_y<<" | Max y: "<<max_y<<endl;

    cout<<"Calling edges list..."<<endl;
    active_edge_list(min_x, max_x, min_y, max_y, points);
}
