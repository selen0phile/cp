struct vectr {
    double x,y,z;
    vectr(double a,double b,double c):x(a),y(b),z(c){}
    vectr(){}
    double abs() {
        return sqrt(x*x+y*y+z*z);
    }
    vectr operator+(vectr v) {
        return vectr(x+v.x,y+v.y,z+v.z);
    }
    vectr operator-(vectr v) {
        return vectr(x-v.x,y-v.y,z-v.z);
    }
    vectr operator*(double v) {
        return vectr(x*v,y*v,z*v);
    }
    vectr operator/(double v) {
        return vectr(x/v,y/v,z/v);
    }
    vectr unit() {
        return vectr(x,y,z)/abs();
    }
    double dot(vectr v) {
        return x*v.x+y*v.y+z*v.z;
    }
    double angle(vectr v) {
        if(dot(v)==0) return acos(-1.0)/2.0;
        return acos(dot(v)/(abs()*v.abs()));
    }
};
