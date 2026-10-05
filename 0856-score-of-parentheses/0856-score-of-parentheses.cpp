class Solution {
public:
    int scoreOfParentheses(string s) {
        // stack<int>stk;
        // int score = 0;
        // for(int i=0;i<s.size();i++){
        //     if(s[i]=='('){
        //         stk.push(score);
        //         score = 0;
        //     }
        //     else{
        //         if(s[i-1]=='('){ // '()'
        //             score = stk.top()+1;
        //         }
        //         else{  // '(('
        //             score = stk.top() + 2*score; 
        //         }
        //         stk.pop();
        //     }
        // }
        // return score;

        int score=0,depth=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                depth++;
            }
            else{
                depth--;
                if(s[i-1]=='('){
                    score+= (1<<depth);
                }
            }
        }
        return score;
    }
};