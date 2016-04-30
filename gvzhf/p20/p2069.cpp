#include <iostream>

using namespace std;

int main() {
    int n, m;
    int n_max = 0, n_first = 0, n_last = 0;
    int m_max = 0, m_first = 0, m_last = 0;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        if (t > n_max) n_max = t;
        if (i == 0) n_first = t;
        if (i == n - 1) n_last = t;

    }
    for (int i = 0; i < m; i++) {
        int t;
        cin >> t;
        if (t > m_max) m_max = t;
        if (i == 0) m_first = t;
        if (i == m - 1) m_last = t;
    }
    int mf_nl = min(m_first, n_last);
    int nf_ml = min(n_first, m_last);
    int mf_nm_ml = min(n_max, min(m_first, m_last));
    int nf_mm_nl = min(m_max, min(n_first, n_last));
    cout << max(max(mf_nl, nf_ml), max(mf_nm_ml, nf_mm_nl));
    return 0;
}