class Solution {
public:
    int canSplit(vector<int >&nums, int k, int maxSum){
        int count=1;
        int currentSum=0;
        for(int n:nums){
            if(currentSum+n<=maxSum){
                currentSum+=n;

            }else{
                count ++;
                currentSum=n;

            }
        }
        return count<=k;
        
    }
    int splitArray(vector<int>& nums, int k) {
        int low=*max_element(nums.begin(), nums.end());
        int high=0;
        for(int n :nums){
            high+=n;

        }
        int answer=high;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(canSplit(nums,k,mid)){
                answer=mid;
                high=mid-1;

            }else{
                low=mid+1;

            }
        }
        return answer;

        

        
    }
    
};