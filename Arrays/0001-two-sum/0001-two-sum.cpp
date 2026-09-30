class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
         map<int,int>mpp;
    for(int i=0;i<n;i++){
        int remaining = target-nums[i];
        if(mpp.find(remaining) != mpp.end()){ 
            // mpp.end() If find(complement) returns anything other than mpp.end(), it means the complement was found. If it returns mpp.end(), the complement doesn’t exist in the map.
            return{mpp[remaining],i};
        }
        mpp[nums[i]]=i;
    }
    return {};
    }
};