class Solution {
public:
    int numSub(string s) {
        const int MOD = 1e9 + 7;
        long long count = 0, result = 0;

        for (char c : s) {
            if (c == '1') {
                count++;
                result = (result + count) % MOD;
            } else {
                count = 0;
            }
        }

        return static_cast<int>(result);
    }
};