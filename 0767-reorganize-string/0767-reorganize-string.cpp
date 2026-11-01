class Solution {
public:
    string reorganizeString(string s) {
        // unordered_map<char,int>mp;
        // for(auto it:s) mp[it]++;
        // int maxfreq=0;
        // char ch;
        // for(auto it : mp){
        //     if(it.second>maxfreq){
        //         maxfreq=it.second;
        //         ch=it.first;
        //     }
        // }
        // if(maxfreq>(s.size()+1)/2) return "";
        // string ans(s.size(),' ');
        // for(int i=0;i<maxfreq;i++){
        //     ans[i*2]=ch;
        //     mp[ch]--;
        // }
        // int idx=2*maxfreq;
        // if(idx>=s.size()) idx=1;
        // for(auto&it:mp){
        //     while(it.second>0){
        //         ans[idx]=it.first;
        //         idx+=2;
        //         if(idx>=s.size()) idx=1;
        //         it.second--;
        //     }
        // }
        // return ans;








        /*-------------------using max heap(priority_queue)---------------------------*/
        int n=s.size();
        unordered_map<char,int>mp;
        for(auto it : s){
            mp[it]++;
        }
        priority_queue<pair<int,char>>pq;
        for(auto it:mp){
            pq.push({it.second,it.first});
        }
        string ans="";
        pair<int,char>prev={0,'#'};
        while(!pq.empty()){
            auto curr = pq.top();
            pq.pop();
            ans+=curr.second;
            curr.first--;
            if(prev.first>0){
                pq.push(prev);
            }
            prev=curr;
        }
        if(ans.size() != s.size()) return "";
        return ans;
    }
};