#ifndef __POINT_H__
#define __POINT_H__

typedef struct 
{
    int xpos;
    int ypos;
}Point;

void SetPointPos(Point * point, int xpos, int ypos); //값 설정
int PointComp(Point * point1, Point * point2); //값 비교
void ShowPoint(Point * point); //값 출력




#endif