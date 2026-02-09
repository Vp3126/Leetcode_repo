class Solution {
public:
    string frequencySort(string s) {
        int freq[256] = {0};
        
        for (char c : s) {
            freq[c]++;
        }

        vector<pair<int, char>> vec;
        for (int i = 0; i < 256; i++) {
            if (freq[i] > 0) {
                vec.push_back({freq[i], (char)i});
            }
        }

        sort(vec.begin(), vec.end(), [](pair<int, char> a, pair<int, char> b) {
            if (a.first != b.first)
                return a.first > b.first;
            return a.second < b.second;
        });

        string result = "";
        for (auto p : vec) {
            result.append(p.first, p.second);
        }

        return result;
    }
};
