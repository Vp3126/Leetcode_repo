class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        // Step 1: Sort by end asc, start desc
        sort(intervals.begin(), intervals.end(), [](auto &a, auto &b){
            if (a[1] == b[1]) return a[0] > b[0];
            return a[1] < b[1];
        });

        // last two chosen values
        int a = -1, b = -1; 
        int ans = 0;

        for (auto &in : intervals) {
            int start = in[0], end = in[1];

            bool aInside = (a >= start && a <= end);
            bool bInside = (b >= start && b <= end);

            if (aInside && bInside) {
                // already have 2 numbers
                continue;
            }
            else if (bInside) {
                // have 1 number → add 1 more
                ans += 1;
                a = b;
                b = end;  // choose the largest possible
            }
            else {
                // have 0 numbers → add 2 numbers
                ans += 2;
                a = end - 1;
                b = end;
            }
        }

        return ans;
    }
};
