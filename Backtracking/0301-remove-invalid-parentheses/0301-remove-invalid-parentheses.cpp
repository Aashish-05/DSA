class Solution {
public:
    void solve(unordered_set<string>& st, string &temp, int i, string &s,int &mx,int open) {
        if(open<0) return;
        if (i == s.size()) {
            if(open==0){
                if(temp.size()>mx){
                    st.clear();
                    mx=temp.size();
                }
                if(mx==temp.size()) st.insert(temp);
            }
            return;
        }
        // Character hai -> skip nahi karna
            if (s[i] >= 'a' && s[i] <= 'z') {
                temp.push_back(s[i]);
                solve(st, temp, i + 1, s,mx,open);
                temp.pop_back();
            }
            else {
            // Parenthesis -> take
                temp.push_back(s[i]);
                solve(st, temp, i + 1, s,mx,open+((s[i]=='(') ?1:-1));

            // Parenthesis -> skip/remove
                temp.pop_back();
                solve(st, temp, i + 1, s,mx,open);
            }
    }
    vector<string> removeInvalidParentheses(string s) {
        unordered_set<string> st;
        int mx = 0;
        string temp="";
        solve(st, temp, 0, s,mx,0);
        return vector<string>(st.begin(),st.end());
    }
};