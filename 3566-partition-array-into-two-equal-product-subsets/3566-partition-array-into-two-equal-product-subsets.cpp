

class Solution {
public:
    bool checkEqualPartitions(vector<int>& nums, long long target) {
        __int128 total = 1;
        for (int x : nums) total *= x;

        __int128 square = (__int128)target * target;
        if (total != square) return false;

        return helper(nums, 0, 1, target);
    }

private:
    bool helper(vector<int>& nums, int index, __int128 currProd, long long target) {
        if (index >= nums.size()) return false;
        if (currProd == target) return true;
        if (currProd > target) return false;

        if (nums[index] != 0 && currProd > target / nums[index])
            return helper(nums, index + 1, currProd, target);

        if (helper(nums, index + 1, currProd * nums[index], target))
            return true;

        return helper(nums, index + 1, currProd, target);
    }
};
