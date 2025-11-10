class Solution {
public:
    bool checkEqualPartitions(vector<int>& nums, long long target) {
        if (target < 0) return false; // assuming nums are non-negative in problem
        // Special case target == 0
        if (target == 0) {
            // total product must be 0 -> at least one zero in nums
            for (int x : nums) if (x == 0) return true;
            return false;
        }

        // 1) factorize target (long long)
        vector<long long> primes;
        vector<int> req; // exponents for target
        {
            long long t = target;
            for (long long p = 2; p * p <= t; ++p) {
                if (t % p == 0) {
                    int c = 0;
                    while (t % p == 0) { t /= p; ++c; }
                    primes.push_back(p);
                    req.push_back(c);
                }
            }
            if (t > 1) { primes.push_back(t); req.push_back(1); }
        }
        int m = primes.size();

        // 2) accumulate exponents across all nums and ensure no foreign primes appear
        vector<long long> totalCounts(m, 0);
        for (int x : nums) {
            long long v = x;
            if (v == 0) { // zero in nums makes total product zero, but target != 0 here -> impossible
                return false;
            }
            for (int j = 0; j < m; ++j) {
                while (v % primes[j] == 0) {
                    v /= primes[j];
                    ++totalCounts[j];
                }
            }
            if (v != 1) {
                // v has prime factor not in target -> product contains extraneous prime -> cannot equal target^2
                return false;
            }
        }

        // Required total exponent for target^2 is 2 * req
        for (int j = 0; j < m; ++j) {
            if (totalCounts[j] != 2LL * req[j]) return false;
        }

        // 3) build exponent-vector for each number (counts for primes)
        int n = nums.size();
        vector<vector<int>> cnts(n, vector<int>(m, 0));
        for (int i = 0; i < n; ++i) {
            long long v = nums[i];
            for (int j = 0; j < m; ++j) {
                while (v % primes[j] == 0) {
                    v /= primes[j];
                    ++cnts[i][j];
                }
            }
            // v must be 1 by previous check
        }

        // 4) target exponents (we need sum equal to these)
        vector<int> need(m);
        for (int j = 0; j < m; ++j) need[j] = req[j];

        // 5) DFS with memoization over index and current exponents
        unordered_set<string> seen;
        vector<int> cur(m, 0);

        function<bool(int)> dfs = [&](int idx)->bool {
            // check if cur equals need
            bool eq = true;
            for (int j = 0; j < m; ++j) if (cur[j] != need[j]) { eq = false; break; }
            if (eq) return true;
            if (idx == n) return false;

            // encode state
            // encode cur into string (safe and simple)
            string key;
            key.reserve(m * 3 + 10);
            key += to_string(idx);
            key.push_back('#');
            for (int j = 0; j < m; ++j) {
                key += to_string(cur[j]);
                key.push_back(',');
            }
            if (seen.count(key)) return false;
            seen.insert(key);

            // Option: include nums[idx] if it doesn't exceed need
            bool canInclude = true;
            for (int j = 0; j < m; ++j) {
                if (cur[j] + cnts[idx][j] > need[j]) { canInclude = false; break; }
            }
            if (canInclude) {
                for (int j = 0; j < m; ++j) cur[j] += cnts[idx][j];
                if (dfs(idx + 1)) return true;
                for (int j = 0; j < m; ++j) cur[j] -= cnts[idx][j];
            }

            // Option: exclude
            if (dfs(idx + 1)) return true;

            return false;
        };

        return dfs(0);
    }
};