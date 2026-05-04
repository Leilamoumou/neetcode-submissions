class Solution {
public:
    bool isValid(string s) {
        //stack, think like PDAS
        
        //1. Create a stack to store opening brackets

         std::stack<char> stack;
         std::unordered_map<char, char> closeToOpen = {
            {')', '('},
            {']', '['},
            {'}', '{'}
        };

        //2. For each character c in the string:
        for (char c : s) {
            //If it is a closing bracket:
            //Check if the stack is not empty 
            //and its top matches the corresponding opening bracket.
            if (closeToOpen.count(c)) {
                if (!stack.empty() && stack.top() == closeToOpen[c]) {
                    //If yes, pop the stack. Now accounted for
                    stack.pop();
                }
                //Otherwise, return false.
             else {
                    return false;
                }
            } 
            //If it is an opening bracket, push it onto the stack.
                else {
                stack.push(c);
            }
        }
        //After processing all characters:
        //If the stack is empty (return stack.empty will return true), return true.
        //Otherwise, return false.
        return stack.empty();
    }

};
