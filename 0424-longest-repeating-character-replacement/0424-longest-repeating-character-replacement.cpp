class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int>mp;
        int i=0,j=0,ans=0;
        int mx = 0;
        while(j<s.size()){
            mp[s[j]]++;
            mx=max(mx,mp[s[j]]);
            while((j-i+1)-mx>k){
                mp[s[i]]--;
                i++;
            }
            ans = max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};