class Solution {
public:
    string makeLargestSpecial(string s) {
        if(s.size() <= 2) return s;
        
        vector<string> specialStrings;
        int balance = 0, start = 0;
        
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '1') balance++;
            else balance--;
            
            if(balance == 0) {
                string inner = s.substr(start + 1, i - start - 1);
                specialStrings.push_back("1" + makeLargestSpecial(inner) + "0");
                start = i + 1;
            }
        }
        
        sort(specialStrings.begin(), specialStrings.end(), greater<string>());
        
        string result = "";
        for(string &str : specialStrings) {
            result += str;
        }
        
        return result;
    }
};