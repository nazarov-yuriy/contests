#include <iostream>
#include <set>

using namespace std;

bool check(int *heights, int n, bool asc) {
    bool sorted = true;
    for (int i = 0; i < n - 1; i++) {
        if (asc) {
            if (heights[i] > heights[i + 1]) {
                sorted = false;
            }
        } else {
            if (heights[i + 1] > heights[i]) {
                sorted = false;
            }
        }
    }
    return sorted;
}

int main() {
    int n;
    cin >> n;
    int heights[n];
    for (int i = 0; i < n; i++) {
        cin >> heights[i];
    }
    set<int> cand_asc;
    set<int> cand_desc;
    for (int i = 0; i < n - 1; i++) {
        if (heights[i] > heights[i + 1]) {
            cand_asc.insert(i);
            cand_asc.insert(i + 1);
        }
        if (heights[i + 1] > heights[i]) {
            cand_desc.insert(i);
            cand_desc.insert(i + 1);
        }
    }
    if ((cand_asc.size() == 0) || (cand_desc.size() == 0)) {
        cout << "Nothing to do here" << endl;
    } else {
        set<int> cand;
        cand = cand_asc;
        if (cand.size() <= 6) {
            // 1. swap with other candidate
            for (auto it1 = cand.begin(); it1 != cand.end(); ++it1) {
                for (auto it2 = cand.begin(); it2 != cand.end(); ++it2) {
                    if (*it1 < *it2) {
                        swap(heights[*it1], heights[*it2]);
                        if (check(heights, n, true)) {
                            cout << "Yes" << endl << *it1 + 1 << " " << *it2 + 1 << endl;
                            return 0;
                        }
                        swap(heights[*it1], heights[*it2]);
                    }
                }
            }
            // 2. swap with suitable element
            for (auto it1 = cand.begin(); it1 != cand.end(); ++it1) {
                for (int i = 0; i < n; i++) {
                    if (
                            (i == 0) || (i == n - 1) ||
                            ((heights[i - 1] <= heights[*it1]) &&
                             (heights[*it1] <= heights[i + 1]) &&
                             (heights[i - 1] != heights[i + 1]))
                            ) {
                        swap(heights[*it1], heights[i]);
                        if (check(heights, n, true)) {
                            cout << "Yes" << endl << min(*it1, i) + 1 << " " << max(*it1, i) + 1 << endl;
                            return 0;
                        }
                        swap(heights[*it1], heights[i]);
                    }

                }
            }
        }
        cand = cand_desc;
        if (cand.size() <= 6) {
            // 1. swap with other candidate
            for (auto it1 = cand.begin(); it1 != cand.end(); ++it1) {
                for (auto it2 = cand.begin(); it2 != cand.end(); ++it2) {
                    if (*it1 < *it2) {
                        swap(heights[*it1], heights[*it2]);
                        if (check(heights, n, false)) {
                            cout << "Yes" << endl << *it1 + 1 << " " << *it2 + 1 << endl;
                            return 0;
                        }
                        swap(heights[*it1], heights[*it2]);
                    }
                }
            }
            // 2. swap with suitable element
            for (auto it1 = cand.begin(); it1 != cand.end(); ++it1) {
                for (int i = 0; i < n; i++) {
                    if (
                            (i == 0) || (i == n - 1) ||
                            ((heights[i - 1] >= heights[*it1]) &&
                             (heights[*it1] >= heights[i + 1]) &&
                             (heights[i - 1] != heights[i + 1]))
                            ) {
                        swap(heights[*it1], heights[i]);
                        if (check(heights, n, false)) {
                            cout << "Yes" << endl << min(*it1, i) + 1 << " " << max(*it1, i) + 1 << endl;
                            return 0;
                        }
                        swap(heights[*it1], heights[i]);
                    }

                }
            }
        }
        cout << "No hope" << endl;
    }
    return 0;
}