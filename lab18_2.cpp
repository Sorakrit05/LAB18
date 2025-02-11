#include<iostream>
using namespace std;

struct Rect{
	double x,y,w,h;
};

double overlap(Rect* R1, Rect* R2){
    
    double R1_x_right = R1->x + R1->w;
    double R1_y_bottom = R1->y - R1->h;
    double R2_x_right = R2->x + R2->w;
    double R2_y_bottom = R2->y - R2->h;
    
    double x_left, x_right, y_top, y_bottom;


    if (R1->x > R2->x) x_left = R1->x;
    else x_left = R2->x;

    
    if (R1_x_right < R2_x_right) x_right = R1_x_right;
    else x_right = R2_x_right;

    
    if (R1->y < R2->y) y_top = R1->y;
    else y_top = R2->y;

    
    if (R1_y_bottom > R2_y_bottom) y_bottom = R1_y_bottom;
    else y_bottom = R2_y_bottom;

    
    if (x_left < x_right && y_bottom < y_top) {
        double x_overlap = x_right - x_left;
        double y_overlap = y_top - y_bottom;
        return x_overlap * y_overlap;
    } else {
        return 0.0;
    }



}