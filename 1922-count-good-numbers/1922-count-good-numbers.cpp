class Solution {
public:
    static const long long MOD = 1000000007;

    long long power(long long base, long long exp) {
        long long result = 1;
        while (exp > 0) {
            if (exp & 1)
                result = (result * base) % MOD;
            base = (base * base) % MOD;
            exp >>= 1;
        }
        return result;
    }

    int countGoodNumbers(long long n) {
        long long evenCount = (n + 1) / 2;  // even indices
        long long oddCount  = n / 2;        // odd indices

        long long evenWays = power(5, evenCount);
        long long oddWays  = power(4, oddCount);

        return (evenWays * oddWays) % MOD;
    }
};
