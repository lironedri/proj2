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

};


#endif //PROJ2_POINT_H
