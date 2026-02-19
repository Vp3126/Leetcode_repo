class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int last= -1, secondLast=-1;
        int lastCount=0;
        int currMax=0;
        int maxLen=0;
        for(int fruit:fruits){
            if(fruit==last||fruit==secondLast){
                currMax++;

            }else{
                currMax=lastCount+1;

            }
            if(fruit==last){
                lastCount++;

            }else{
                lastCount=1;
                secondLast=last;
                last=fruit;

            }
            maxLen=max(maxLen,currMax);
        }
        return maxLen;
        
    }
};