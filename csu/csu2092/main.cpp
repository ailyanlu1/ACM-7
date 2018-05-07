//
// Created by bitwater on 18-5-7.
//

#include"../../headers.h"

int x[1111];
int y[1111];
double const g = 1;

int main() {
    double D, b;
    int n;
    while (cin >> D >> n >> b) {
        for (int i = 0; i < n; ++i)cin >> x[i] >> y[i];
        double minV = 1e15;
        for (int i = 0; i <= b; ++i) {
            bool isok = 1;
            double maxH = 0;
            double d = D / (i + 1);
            for (int j = 0; j < n; ++j) {
                double x0 = x[j] - (int) (x[j] / d) * d;
                double y0 = y[j];
                if (x0 == 0) {
                    isok = 0;
                    break;
                }
                double H = d * d * y0 / 4 / (d * x0 - x0 * x0);
                maxH = max(maxH, H);
            }
            if (isok == 0) continue;

            double th = d / 4;

            double t = sqrt(2 * maxH / g);

            double vy = g * t;
            double vx = d / 2 / t;
            double V = sqrt(vx * vx + vy * vy);
            if (th > maxH) V = sqrt(d);

            minV = min(minV, V);
        }
        printf("%.5f\n", minV);
    }
}


