class Solution {
public:
    int minInsertions(string s) {
        int i=0;
        int ans = 0;
        int count=0;
        int n = s.size();
        while(i<n){
            if(s[i]=='('){
                count++;
                i++;
            }
            else{  // ')'
                if(count>0){
                   count--;
                }
                else{
                    ans++; // adding '('
                }
                if(i+1<n && s[i+1]==')'){
                    i+=2;
                }
                else{
                    ans++;
                    i++; // adding a ')'
                }
            }
        }
        return ans+(count*2);
    }
};