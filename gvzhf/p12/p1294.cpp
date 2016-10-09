#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double ad, ac, bd, bc;
    cin >> ad >> ac >> bd >> bc;
    ad *= 1000;
    ac *= 1000;
    bd *= 1000;
    bc *= 1000;
    if (fabs(ad * ac - bd * bc) < 0.01) {
        cout << "Impossible.";
    } else {
        double res = sqrt(((ac * ac + ad * ad) * bc * bd - ac * ad * (bc * bc + bd * bd)) / (bc * bd - ac * ad));
        cout << "Distance is " << llround(res) << " km.";
    }
    return 0;
}