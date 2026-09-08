class Solution {
public:
    bool shouldSwap(vector<int>&nums,int idx,int curr){
        for(int i=idx;i<curr;i++){
            if(nums[i]==nums[curr]) return false;
        }
        return true;
    }
    void solve(vector<int>&nums,int idx,vector<vector<int>>&ans){
        if(idx==nums.size()){
            ans.push_back(nums);
            return;
        }
        for(int i=idx;i<nums.size();i++){
            // if(nums[idx]==nums[i]) continue; isse same ele skip ho ja rha hai like arr[1,1,2] to 0 index ka uske sath swap nhi ho pa rha whwn i=0 and idx=0;
            
            if(!shouldSwap(nums,idx,i)) continue;
            swap(nums[idx],nums[i]);
            solve(nums,idx+1,ans);
            swap(nums[idx],nums[i]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>>ans;
        solve(nums,0,ans);
        return ans;
    }
};