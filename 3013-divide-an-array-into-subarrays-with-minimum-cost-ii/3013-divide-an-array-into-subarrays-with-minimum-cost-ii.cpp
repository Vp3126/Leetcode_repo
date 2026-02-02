class Solution {
public:
    long long minimumCost(vector<int>& nums, int k, int dist) {
        multiset<int> lo, hi;
        long long sumLo = 0;
        int need = k - 1;

        auto balance = [&]() {
            while ((int)lo.size() > need) {
                auto it = prev(lo.end());
                hi.insert(*it);
                sumLo -= *it;
                lo.erase(it);
            }
            while ((int)lo.size() < need && !hi.empty()) {
                auto it = hi.begin();
                lo.insert(*it);
                sumLo += *it;
                hi.erase(it);
            }
        };

        auto add = [&](int x) {
            if (!lo.empty() && x <= *prev(lo.end())) {
                lo.insert(x);
                sumLo += x;
            } else {
                hi.insert(x);
            }
            balance();
        };

        auto remove = [&](int x) {
            if (lo.find(x) != lo.end()) {
                lo.erase(lo.find(x));
                sumLo -= x;
            } else {
                hi.erase(hi.find(x));
            }
            balance();
        };

        // initial window
        for (int i = 1; i <= dist + 1; i++) {
            add(nums[i]);
        }

        long long ans = nums[0] + sumLo;

        // sliding window
        for (int i = dist + 2; i < nums.size(); i++) {
            add(nums[i]);
            remove(nums[i - (dist + 1)]);
            ans = min(ans, nums[0] + sumLo);
        }

        return ans;
    }
};
