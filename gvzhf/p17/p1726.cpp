// sort algorithm example
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct pnt {
	long long unsigned int x;
	long long unsigned int y;
};

bool byx(pnt i, pnt j) {
	return (i.x < j.x);
}
bool byy(pnt i, pnt j) {
	return (i.y < j.y);
}

int main() {
	long long unsigned int n;
	cin >> n;

	vector<pnt> vals(n);

	for (vector<pnt>::iterator it = vals.begin(); it != vals.end(); ++it)
		cin >> (*it).x >> (*it).y;

	sort(vals.begin(), vals.end(), byx);
	long long unsigned int x = 1;
	long long unsigned int prevx = (*vals.begin()).x;
	long long unsigned int sumx = 0;
	for (vector<pnt>::iterator it = vals.begin() + 1; it != vals.end(); ++it) {
		sumx += x * (n - x) * ((*it).x - prevx);
		x++;
		prevx = (*it).x;
	}

	sort(vals.begin(), vals.end(), byy);
	long long unsigned int y = 1;
	long long unsigned int prevy = (*vals.begin()).y;
	long long unsigned int sumy = 0;
	for (vector<pnt>::iterator it = vals.begin() + 1; it != vals.end(); ++it) {
		sumy += y * (n - y) * ((*it).y - prevy);
		y++;
		prevy = (*it).y;
	}

	cout << (sumx + sumy) / (n * (n - 1) / 2) << endl;

	return 0;
}

