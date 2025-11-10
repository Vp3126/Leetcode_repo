class Solution {
public:
    bool solve(int idx, long long p1, long long p2, vector<int>& nums, long long target) {
        if (idx == nums.size()) return (p1 == target && p2 == target);
        if (p1 > target || p2 > target) return false;
        return solve(idx + 1, p1 * nums[idx], p2, nums, target) ||
               solve(idx + 1, p1, p2 * nums[idx], nums, target);
    }
    bool checkEqualPartitions(vector<int>& nums, long long target) {
        return solve(0, 1, 1, nums, target);
    }
};
