class Solution {
public:
    bool isValid(string s) {
        stack<char>stk;
        for(int ch:s){
            if(ch=='('){
                stk.push(')');
            }
            else if(ch=='{'){
                stk.push('}');
            }
            else if(ch=='['){
                stk.push(']');
            }
            else{
                if(stk.empty()||stk.top()!=ch){
                    return false;
                }
                stk.pop();
            }
            


        }
        return stk.empty();

        
    }
};