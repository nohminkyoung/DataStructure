#include <stdio.h>
#include "Point.h"


void SetPointPos(Point * point, int xpos, int ypos){

    point->xpos = xpos;
    point->ypos = ypos;
    
}

int PointComp(Point * point1, Point * point2){

    if(point1->xpos==point2->xpos && point1->ypos==point2->ypos){
        return 0;
    }
    else if(point1->xpos == point2->xpos){
        return 1;
    }
    else if(point1->ypos == point2->ypos){
        return 2;
    }
    else {
        return -1;
    }
}
void ShowPoint(Point * point){
    printf("[ %d, %d ]\n", point->xpos, point->ypos);
}