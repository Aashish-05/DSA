class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char,int>mp;
        for(auto it:s) mp[it]++;
        int maxfreq=0;
        char ch;
        for(auto it : mp){
            if(it.second>maxfreq){
                maxfreq=it.second;
                ch=it.first;
            }
        }
        if(maxfreq>(s.size()+1)/2) return "";
        string ans(s.size(),' ');
        for(int i=0;i<maxfreq;i++){
            ans[i*2]=ch;
            mp[ch]--;
        }
        int idx=2*maxfreq;
        if(idx>=s.size()) idx=1;
        for(auto&it:mp){
            while(it.second>0){
                ans[idx]=it.first;
                idx+=2;
                if(idx>=s.size()) idx=1;
                it.second--;
            }
        }
        return ans;

    }
};