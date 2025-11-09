class Solution {
public:
    int minimizeMax(vector<int>& nums, int p) {
        if (p == 0) return 0; // No pairs needed
        
        sort(nums.begin(), nums.end());
        
        int low = 0;
        int high = nums.back() - nums.front();
        int ans = high;
        
        auto canForm = [&](int maxDiff) {
            int count = 0;
            for (int i = 1; i < nums.size(); i++) {
                if (nums[i] - nums[i - 1] <= maxDiff) {
                    count++;
                    i++; // Skip next index, both used in a pair
                }
            }
            return count >= p;
        };
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (canForm(mid)) {
                ans = mid;
                high = mid - 1; // Try smaller max difference
            } else {
                low = mid + 1;  // Need larger difference
            }
        }
        
        return ans;
    }
};