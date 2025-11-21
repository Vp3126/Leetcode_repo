class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.size();
        int ans = 0;

        for(char ch = 'a'; ch <= 'z'; ch++) {
            int left = -1, right = -1;

            for(int i = 0; i < n; i++) {
                if(s[i] == ch) {
                    if(left == -1) left = i;
                    right = i;
                }
            }

            if(left == -1 || right == -1 || right - left < 2) continue;

            bool seen[26] = {false};

            for(int i = left + 1; i < right; i++) {
                seen[s[i] - 'a'] = true;
            }

            for(int i = 0; i < 26; i++) 
                if(seen[i]) ans++;
        }

        return ans;
    }
};
