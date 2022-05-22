int get_sign(int n){
    if(n<0)
        return -1;
    else if(n>0)
        return 1;
    else
        return 0;
}

static void bresenham(vector<point> points){
    float x = points[0][0];
    float y = points[0][1];

    float del_y = abs(points[1][1] - y);
    float del_x = abs(points[1][0] - x);

    int s1 = get_sign(points[1][0] - x);
    int s2 = get_sign(points[1][1] - y);

    int interchange=0;
    if(del_y > del_x){

        float temp = del_x;
        del_x = del_y;
        del_y = temp;
        interchange = 1;
    }

    float p_k = 2*del_y - del_x;
    for(int i=1;i<del_x;i++){
        set_pixel(x, y);
        cout<<"pk: "<<p_k<<" | ";
        cout<<x<<","<<y<<endl;
        while(p_k>0){

            if (interchange==1){
                x = x+s1;
            }
            else{
                y = y+s2;
            }
            p_k = p_k - 2*del_x;
        }
        if (interchange==1){
            y = y+s2;
        }
        else{
            x = x+s1;
        }
        p_k = p_k + 2*del_y;
    }
    set_pixel(x, y);
}
