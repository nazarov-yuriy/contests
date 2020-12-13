#include <vector>

using namespace std;

class Solution {
public:
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();
        int sums[n+1];
        sums[0] = 0;
        for (int i = 0; i < n; i++) {
            sums[i + 1] = sums[i] + stoneValue[i];
        }
        int cache_val[n+1][n+1];
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= n; j++) {
                cache_val[i][j] = -1;
            }
        }
        std::function<int(int,int)> get_score = [&] (int l, int r) {
            if (r - l == 1) return 0;
            if (cache_val[l][r] == -1) {
                int res = 0;
                int sl = sums[l];
                int sr = sums[r];
                for (int i = l + 1; i < r; i++) {
                    int si = sums[i];
                    int score_left = si - sl;
                    int score_right = sr - si;
                    int score;
                    if (score_left == score_right) {
                        int next_left = cache_val[l][i] != -1 ? cache_val[l][i] : get_score(l, i);
                        int next_right = cache_val[i][r] != -1 ? cache_val[i][r] : get_score(i, r);
                        if (score_left + next_left > score_right + next_right){
                            score = score_left + next_left;
                        } else {
                            score = score_right + next_right;
                        }
                    } else if (score_left > score_right) {
                        int next_right = cache_val[i][r] != -1 ? cache_val[i][r] : get_score(i, r);
                        score = score_right + next_right;
                    } else {
                        int next_left = cache_val[l][i] != -1 ? cache_val[l][i] : get_score(l, i);
                        score = score_left + next_left;
                    }
                    res = max(res, score);
                }
                cache_val[l][r] = res;
            }
            return cache_val[l][r];
        };

        return get_score(0, n);
    }
};

#include <cassert>

int main() {
    vector<int> stones = {6, 2, 3, 4, 5, 5};
    assert(Solution().stoneGameV(stones) == 18);
    stones = {
            39994, 3, 4, 10000, 10000, 10000, 10000, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
            1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
            1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
            1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
            1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
            1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
            1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
            1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
            1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
            1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
            1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
            1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
            1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
            1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
            1, 1, 1000000
    };
    assert(Solution().stoneGameV(stones) == 150003);
    return 0;
}