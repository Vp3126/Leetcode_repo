class Solution {
public:
    int maxDiff(int num) {
        string s = to_string(num);
        
        // ---------- Get Maximum ----------
        string maxStr = s;
        char toReplaceMax = 0;
        for (char c : s) {
            if (c != '9') {
                toReplaceMax = c;
                break;
            }
        }
        if (toReplaceMax) {
            for (char &c : maxStr) {
                if (c == toReplaceMax) c = '9';
            }
        }
        
        // ---------- Get Minimum ----------
        string minStr = s;
        char toReplaceMin = 0;
        if (s[0] != '1') {
            toReplaceMin = s[0];
            for (char &c : minStr) {
                if (c == toReplaceMin) c = '1';
            }
        } else {
            for (int i = 1; i < s.size(); ++i) {
                if (s[i] != '0' && s[i] != '1') {
                    toReplaceMin = s[i];
                    break;
                }
            }
            if (toReplaceMin) {
                for (char &c : minStr) {
                    if (c == toReplaceMin) c = '0';
                }
            }
        }
        
        int maxNum = stoi(maxStr);
        int minNum = stoi(minStr);
        
        return maxNum - minNum;
    }
};