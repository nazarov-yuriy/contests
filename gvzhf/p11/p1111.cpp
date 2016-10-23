#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

struct point {
    double x;
    double y;
};

struct square {
    point pt1;
    point pt2;
    point pt3;
    point pt4;
    int id;
};


point p;

double qd(point pt1, point pt2) {
    return (pt1.x - pt2.x) * (pt1.x - pt2.x) + (pt1.y - pt2.y) * (pt1.y - pt2.y);
}

double sd(point pt1, point pt2) {
    return sqrt(qd(pt1, pt2));
}

double inside(point a, point b, point p) {
    return (qd(a, p) <= qd(a, b) + qd(b, p)) && (qd(b, p) <= qd(a, b) + qd(a, p));
}

double heron(point a, point b, point c) {
    double da = sqrt(qd(b, c));
    double db = sqrt(qd(a, c));
    double dc = sqrt(qd(b, a));
    return sqrt((da + db + dc) * (da + db - dc) * (da - db + dc) * (db + dc - da)) / 4.0;
}

double distance(square s) {
    double e = 1e-14;
    if (qd(s.pt1, s.pt3) > e) {
        if (abs(heron(s.pt1, s.pt2, p) + heron(s.pt2, s.pt3, p) +
                heron(s.pt3, s.pt4, p) + heron(s.pt4, s.pt1, p) - qd(s.pt1, s.pt3) / 2.0) < e) {
            return 0;
        }
        if (inside(s.pt1, s.pt2, p)) {
            return min(
                    2.0 * heron(s.pt1, s.pt2, p) / sqrt(qd(s.pt1, s.pt2)),
                    2.0 * heron(s.pt3, s.pt4, p) / sqrt(qd(s.pt3, s.pt4))
            );
        }
        if (inside(s.pt2, s.pt3, p)) {
            return min(
                    2.0 * heron(s.pt2, s.pt3, p) / sqrt(qd(s.pt2, s.pt3)),
                    2.0 * heron(s.pt1, s.pt4, p) / sqrt(qd(s.pt1, s.pt4))
            );
        }
    }
    return min(
            min(sd(p, s.pt1), sd(p, s.pt2)),
            min(sd(p, s.pt3), sd(p, s.pt4))
    );
}

bool cmp(square s1, square s2) {
    double d1 = distance(s1);
    double d2 = distance(s2);
    return fabs(d1 - d2) <= 1e-8 ? s1.id < s2.id : d1 < d2;
}

int main() {
    int n;
    cin >> n;
    vector<square> sqs(n);
    for (int i = 0; i < n; i++) {
        double x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        sqs[i].pt1.x = x1;
        sqs[i].pt1.y = y1;
        sqs[i].pt2.x = (x1 + x2) / 2.0 + (y2 - y1) / 2.0;
        sqs[i].pt2.y = (y1 + y2) / 2.0 - (x2 - x1) / 2.0;
        sqs[i].pt3.x = x2;
        sqs[i].pt3.y = y2;
        sqs[i].pt4.x = (x1 + x2) / 2.0 - (y2 - y1) / 2.0;
        sqs[i].pt4.y = (y1 + y2) / 2.0 + (x2 - x1) / 2.0;
        sqs[i].id = i + 1;
    }
    cin >> p.x >> p.y;
    sort(sqs.begin(), sqs.end(), cmp);
    for (int i = 0; i < n; i++) {
        cout << sqs[i].id << ' ';
        //cout << distance(sqs[i]) << endl;
    }
    return 0;
}