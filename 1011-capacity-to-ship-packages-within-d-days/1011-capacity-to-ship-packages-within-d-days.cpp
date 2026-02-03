class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low=0;
        int high=0;
        for(int w: weights){
            low=max(low,w);
            high+=w;
        }    
        while(low<high){
            int mid=low+(high-low)/2;
            int usedDay = 1;
            int currLoad=0;
            for(int w:weights){
                if(currLoad+w>mid){
                    usedDay++;
                    currLoad=w;
                }else{
                    currLoad+=w;
                }
            }
            if(usedDay<=days){
                high=mid;

            }else{
                low=mid+1;
            }
        }
        return low;
    }
};