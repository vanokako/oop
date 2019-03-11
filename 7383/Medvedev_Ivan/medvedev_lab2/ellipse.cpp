#include "ellipse.h"
#include <math.h>

Ellipse::Ellipse() : Shape ()
{

    radius1 = rand() % 10;
    radius2 = rand() % 15;
    points.push_back(Point(point.x + radius1,point.y));
    points.push_back(Point(point.x - radius1, point.y));
    points.push_back(Point(point.x, point.y + radius2));
    points.push_back(Point(point.x, point.y - radius2));
}

Ellipse::Ellipse(const Point O, double a, double b, const RGB _colour) : Shape(0, _colour, O), radius1(a), radius2(b)
{
    points.push_back(Point(point.x + radius1,point.y));
    points.push_back(Point(point.x - radius1, point.y));
    points.push_back(Point(point.x, point.y + radius2));
    points.push_back(Point(point.x, point.y - radius2));
}

void Ellipse::move(const Point p)
{
    double delta = p.x - point.x;
    double eps = p.y - point.y;
    point.x += delta;
    point.y += eps;
    for(auto& pnt : points){
        pnt.x += delta;
        pnt.y += eps;
    }
}

void Ellipse::rotate(int _angle)
{
    angle += _angle;
    _angle %= 360;
    double rad = _angle*M_PI/180;
    double x, y;
    for(auto& pnt : points){
        x = pnt.x;
        y = pnt.y;
        pnt.x =(x - point.x) * cos(rad) - (y - point.y) * sin(rad) + point.x;
        pnt.y = (x - point.x) * sin(rad) - (y - point.y) * cos(rad) + point.y;
    }

}

void Ellipse::scale(int k){
    points.clear();
    radius1 *= k;
    radius2 *= k;
    points[0] = Point(point.x + radius1,point.y);
    points[1] = Point(point.x - radius1, point.y);
    points[2] = Point(point.x, point.y + radius2);
    points[3] = Point(point.x, point.y - radius2);

}

double Ellipse::get_radius1(){
    return radius1;
}

double Ellipse::get_radius2(){
    return radius2;
}

double Ellipse::area(){
    double area = M_PI*radius1*radius2;
    return area;

}

std::ostream& operator<<(std::ostream& out, Ellipse& ellipse){
    out << "Ellipse" << std::endl;
    out<< "================================="<<std::endl;
    out << (Shape&)ellipse;
    out << "Points:"<<std::endl <<"("<< ellipse.points[0].x << ", " << ellipse.points[0].y << ")" << std::endl;
    out << "(" << ellipse.points[1].x << ", " << ellipse.points[1].y << ")" << std::endl;
    out << "(" << ellipse.points[2].x << ", " << ellipse.points[2].y << ")" << std::endl;
    out << "(" << ellipse.points[3].x << ", " << ellipse.points[3].y << ")" << std::endl;
    out << "Radiuses: R1 = " << ellipse.get_radius1() << " R2 = " << ellipse.get_radius2() << std::endl;
    out << "=========================="<<std::endl;
    return out;
}
