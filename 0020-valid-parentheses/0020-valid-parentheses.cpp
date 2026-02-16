class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;

        for (char ch : s) {
            // If it's an opening bracket, push the corresponding closing bracket
            if (ch == '(') {
                stk.push(')');
            } else if (ch == '{') {
                stk.push('}');
            } else if (ch == '[') {
                stk.push(']');
            }
            // If it's a closing bracket, check if it matches the top of the stack
            else {
                if (stk.empty() || stk.top() != ch) {
                    return false;
                }
                stk.pop();
            }
        }

        // If stack is empty, all brackets matched
        return stk.empty();
    }
};
