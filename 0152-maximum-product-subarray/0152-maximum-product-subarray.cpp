class Solution {
public:
    int maxProduct(vector<int>& arr) {
        int prefix = 1;
        int suffix=1;
        int n = arr.size();
        int ans = INT_MIN;
        for(int  i=0;i<arr.size();i++){
            if(prefix==0) prefix =1;
            if(suffix==0) suffix=1;
            prefix = prefix*arr[i];
            suffix = suffix*arr[n-i-1];
            ans = max(ans,max(prefix,suffix));
        }
        return ans;
    }
};