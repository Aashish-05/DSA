class Solution {
public:
    set<int>st;
    void solve(vector<int>&digits,int curr,int num,vector<int>&used){
        if(curr==3){
            if(num%2==0) st.insert(num);
            return;
        }
        for(int i=0;i<digits.size();i++){
            if(used[i]==1) continue;
            if(curr==0 && digits[i]==0) continue;
            used[i]=1;
            solve(digits,curr+1,num*10+digits[i],used);
            used[i]=0;
        }

    }
    int totalNumbers(vector<int>& digits) {
        vector<int>used(digits.size(),0);
        solve(digits,0,0,used);
        return st.size();
    }
};