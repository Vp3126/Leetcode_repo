class Solution {
public:
    vector<string> ans;
    int N;

    void dfs(string &curr) {
        if (curr.size() == N) {
            ans.push_back(curr);
            return;
        }

        // Always allowed to add '1'
        curr.push_back('1');
        dfs(curr);
        curr.pop_back();

        // Add '0' only if last char is not '0'
        if (curr.back() == '1') {
            curr.push_back('0');
            dfs(curr);
            curr.pop_back();
        }
    }

    vector<string> validStrings(int n) {
        N = n;

        // Base case for n = 1
        if (n == 1) return {"0", "1"};

        string curr;

        // Start with '0'
        curr = "0";
        dfs(curr);

        // Start with '1'
        curr = "1";
        dfs(curr);

        return ans;
    }
};
