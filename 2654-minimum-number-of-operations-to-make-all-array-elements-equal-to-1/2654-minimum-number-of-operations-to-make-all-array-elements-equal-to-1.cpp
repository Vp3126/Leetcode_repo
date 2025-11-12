class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();

        // Step 1: If GCD of all elements > 1 => impossible
        int overall_gcd = nums[0];
        for (int i = 1; i < n; i++) {
            overall_gcd = gcd(overall_gcd, nums[i]);
        }
        if (overall_gcd > 1) return -1;

        // Step 2: If array already has 1s
        int ones = count(nums.begin(), nums.end(), 1);
        if (ones > 0) return n - ones;

        // Step 3: Find smallest subarray with GCD == 1
        int minLen = INT_MAX;
        for (int i = 0; i < n; i++) {
            int g = nums[i];
            for (int j = i + 1; j < n; j++) {
                g = gcd(g, nums[j]);
                if (g == 1) {
                    minLen = min(minLen, j - i + 1);
                    break;
                }
            }
        }

        // Step 4: Calculate total operations
        return (minLen - 1) + (n - 1);
    }
};