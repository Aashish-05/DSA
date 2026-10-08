class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans = "";
        int open = 0,close=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                open++;
                if(open>1){
                    ans+='(';
                }
            }
            else{
                close++;
                if(close<open) ans+=')';
                if(close==open){
                    close=0;
                    open=0;
                }
            }
        }
        return ans;
    }
};