class Solution {
public:
    int minAddToMakeValid(string s) {
        int a = 0;
        int n = s.size();
        int close = 0;
        int open = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                a++;
            } else {
                a--;
                if (a < 0) {
                    close++;
                    a++;
                }
            }
        }
        if(a>0) return a+close;
        return close;
    }
};