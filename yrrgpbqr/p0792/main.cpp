class Solution {
public:
    int isMatch(const string &needle, const string &haystack) {
        int pos = 0;
        for (const char &c : needle) {
            pos = haystack.find(c, pos);
            if (pos == string::npos) {
                return 0;
            }
            pos++;
        }
        return 1;
    }

    int numMatchingSubseq(string S, vector<string> &words) {
        int res = 0;
        for (auto const &word : words) {
            res += isMatch(word, S);
        }
        return res;
    }
};