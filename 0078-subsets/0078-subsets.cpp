
class Solution { 
    private: 
    void backtrack(int index, const std::vector<int>& nums, std::vector<int>& current_subset, std::vector<std::vector<int>>& result) { 
        result.push_back(current_subset); 
        for (int i = index; i < nums.size(); ++i) { 
            current_subset.push_back(nums[i]); 
            backtrack(i + 1, nums, current_subset, result); 
            current_subset.pop_back(); 
        } 
    } 
    public: 
    vector<vector<int>> subsets(vector<int>& nums) { 
        std::vector<std::vector<int>> result; 
        std::vector<int> current_subset; 
        backtrack(0, nums, current_subset, result); 
        return result; 
    } 
};
