class Solution {
public:
    int myAtoi(string s) {
        long long ans = 0;
        bool sign = true;
        int j=0;
        while(j<s.size() && s[j] ==' ') j++;
        if(j==s.size()) return 0;
        if((s[j]=='-' && s[j+1]=='+') || (s[j]=='+' && s[j+1]=='-')) return 0;
        if(s[j]=='-'){
            sign = false;
            j++;
        }
        if(s[j]=='+') j++;
        for(int i=j;i<s.size();i++){
            if(s[i]<'0' || s[i]>'9'){
                break;
            }
            else{
                ans=ans*10+(s[i]-'0');
                if(ans>INT_MAX && sign==false) return INT_MIN;
                if(ans==INT_MAX && sign==false) return -INT_MAX;
                if(ans>=INT_MAX) return INT_MAX;
                if(ans<=INT_MIN) return INT_MIN;
            }
            
        }
        return (sign==true ? ans :-ans);
    }
};