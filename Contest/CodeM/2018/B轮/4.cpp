//
// Created by icebeetle on 18-6-23.
//

#include <bits/stdc++.h>

using namespace std;

struct point_t {
    double x, y;

    explicit point_t(double xx = 0, double yy = 0) : x(xx), y(yy) {};
};

typedef point_t vector_t;

vector_t operator-(vector_t a, vector_t b) { return point_t(a.x - b.x, a.y - b.y); }

vector_t operator*(vector_t a, double t) { return point_t(a.x * t, a.y * t); }

vector_t operator/(vector_t a, double t) { return point_t(a.x / t, a.y / t); }

vector_t operator+(vector_t a, vector_t b) { return point_t(a.x + b.x, a.y + b.y); }


inline double Point2Point(point_t const &a, point_t const &b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

int main() {
    double r;
    while (scanf("%lf", &r) != EOF) {
        point_t p1, p2, p0(0, 0);
        scanf("%lf%lf%lf%lf", &p1.x, &p1.y, &p2.x, &p2.y);
        double ans1 = Point2Point(p1, p2);

        vector_t v1 = (p1 - p0) / Point2Point(p1, p0) * -1;
        point_t pt1 = p0 + v1 * r;
        double ans2 = r - Point2Point(p1, p0) + Point2Point(pt1, p2);;

        vector_t v2 = (p2 - p0) / Point2Point(p2, p0) * -1;
        point_t pt2 = p0 + v2 * r;
        double ans3 = r - Point2Point(p2, p0) + Point2Point(pt2, p1);

        printf("%.13f\n", min(min(ans1, ans2), ans3));
    }
    return 0;
}