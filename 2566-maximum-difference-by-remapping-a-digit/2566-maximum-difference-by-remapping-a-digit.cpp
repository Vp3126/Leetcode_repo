class Solution {
public:
    int minMaxDifference(int num) {
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
        char toReplaceMin = s[0];
        for (char &c : minStr) {
            if (c == toReplaceMin) c = '0';
        }
        
        int maxNum = stoi(maxStr);
        int minNum = stoi(minStr);
        
        return maxNum - minNum;
    }
};