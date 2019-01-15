#ifndef PROJ2_POINT_H
#define PROJ2_POINT_H

class Point {
    double m_x;
    double m_y;
public:

    Point(double x, double y){
        this->m_x = x;
        this->m_y = y;
    }

    double getX(){
        return this->m_x;
    }

    double getY(){
        return this->m_y;
    }

    bool operator==(Point p) {
        return (this->m_x == p.getX() && this->m_y == p.getY());
    }


    Point(){}
};


#endif //PROJ2_POINT_H
