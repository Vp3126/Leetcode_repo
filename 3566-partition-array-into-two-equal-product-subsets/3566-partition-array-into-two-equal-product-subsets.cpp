class Solution {
public:
    bool checkEqualPartitions(vector<int>& nums, long long target) {
        long long total = 1;
        for (int x : nums) total *= x;

        // total must be equal to target^2
        if (total != target * target) return false;

        return helper(nums, 0, 1, target);

        
    }
private:
    bool helper(vector<int>&nums,int index,long long currProd,long long target){
        if (index >= nums.size()) return false;

        // ✅ If we already reached target
        if (currProd == target) return true;

        // ✅ Prune branches that exceed target
        if (currProd > target) return false;

        // ✅ Safe multiplication check before multiplying
        if (nums[index] != 0 && currProd > target / nums[index])
            return helper(nums, index + 1, currProd, target); // skip current number

        // Option 1: include current element
        if (helper(nums, index + 1, currProd * nums[index], target))
            return true;

        // Option 2: exclude current element
        return helper(nums, index + 1, currProd, target);


    }
};