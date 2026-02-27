class Solution {
public:
    int minOperations(string s, int k) {
        int n = s.size();
        int ones = 0;

        for (char c : s)
            if (c == '1')
                ones++;

        if (ones == n)
            return 0;

        int zeros = n - ones;

        if (k % 2 == 0 && zeros % 2 == 1)
            return -1;

        return (zeros + k - 1) / k;
    }
};