pair<int, int> get_intersection(pair<int, int> p1, pair<int, int> p2){

    float m = (p2.second - p1.second)*1.0/(p2.first - p1.first);
    float x1 = p1.first;
    float x2 = p2.first;
    float y1 = p1.second;
    float y2 = p2.second;

    // Find line equation in Ax + By + C given two point form

    float a = y1 - y2;
    float b = x2 - x1;
    float c = y1*x1 + y2*x2 - 2*y2*x1;

    float p_x = (b1*c2 - b2*c1)*1.0/(a1*b2 - a2*b1);
    float p_y = (c1*a2 - c2*a1)*1.0/(a1*b2 - a2*b1);
    return pair({p_x, p_y});
}
