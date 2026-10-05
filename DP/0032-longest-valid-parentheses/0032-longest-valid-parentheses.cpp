class Solution {
public:
    int longestValidParentheses(string s) {
        // stack<char> stk;
        // int ans = 0;
        // for (int i = 0; i < s.size(); i++) {
        //     if (s[i] == '(')
        //         stk.push(s[i]);
        //     if (s[i] == ')') {
        //         if (stk.empty())  continue;
        //         if ((s[i] == ')' && stk.top() == '(')) {
        //             ans+=2;
        //             stk.pop();
        //         } else continue;
        //     }
        // }
        // return ans;
        int open = 0, close = 0;
        int ans = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                open++;
            }
            if (s[i] == ')') {
                close++;
                if(close>open){
                    close=0;
                    open=0;
                    continue;
                }
            }
            if (close==open) {
                ans=max(ans,close+open);
            }
        }
        int c = 0,o=0,a=0;
        for (int i = s.size()-1; i >= 0; i--) {
            if (s[i] == ')') {
                c++;
            }
            if (s[i] == '(') {
                o++;
                if(c<o){
                    c=0;
                    o=0;
                    continue;
                }
            }
            if (c==o) {
                a = max(a,c+o);
            }
        }
        return max(a,ans);
    }
};