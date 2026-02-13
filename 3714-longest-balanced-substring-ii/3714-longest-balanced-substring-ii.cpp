class Solution {
public:
    int longestBalanced(string s) {
        int n = s.size();
        int ans = 0;

        for (int target = 1; target <= 26; target++) {
            vector<int> freq(26, 0);
            int left = 0, right = 0;
            int distinct = 0;
            int maxFreq = 0;

            while (right < n) {
                int idx = s[right] - 'a';
                freq[idx]++;
                if (freq[idx] == 1) distinct++;
                maxFreq = max(maxFreq, freq[idx]);

                while (distinct > target) {
                    int lidx = s[left] - 'a';
                    freq[lidx]--;
                    if (freq[lidx] == 0) distinct--;
                    left++;
                }

                int len = right - left + 1;

                if (distinct == target && len == target * maxFreq) {
                    ans = max(ans, len);
                }

                right++;
            }
        }

        return ans;
    }
};

