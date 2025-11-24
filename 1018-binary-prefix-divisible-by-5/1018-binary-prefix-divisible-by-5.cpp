class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        vector<bool> ans(nums.size());
        int current = 0;

        for(int i = 0; i < nums.size(); i++) {
            current = (current * 2 + nums[i]) % 5; 
            ans[i] = (current == 0);
        }

        return ans;
    }
};

