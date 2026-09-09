class Solution {
public:
    // bool shouldSwap(vector<int>&nums,int curr,int idx){
    //     for(int i=idx;i<curr;i++){
    //         if(nums[i]==nums[curr]) return false;
    //     }
    //     return true;
    // }
    // bool check = true;
    // void solve(vector<int>&nums,int idx){
    //     if(idx==nums.size() && check == false){
    //         return;
    //     }
    //     for(int i=idx;i<nums.size();i++){
    //         if(!shouldSwap(nums,i,idx)) continue;
    //         swap(nums[i],nums[idx]);
    //         check = false;
    //         solve(nums,i+1);
    //         swap(nums[i],nums[idx]);
    //     }
    // }
    // void nextPermutation(vector<int>& nums) {
    //     solve(nums,0);
    // }

    void nextPermutation(vector<int>& nums) {
        int gola_index = -1;
        int n = nums.size();
        for (int i = n - 1; i > 0; i--) {
            if (nums[i - 1] < nums[i]) {
                gola_index = i - 1;
                break;
            }
        }
        if (gola_index == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }
        int swap_index = -1;
        for (int i = n - 1; i > gola_index; i--) {
            if (nums[i] > nums[gola_index]) {
                swap_index = i;
                break;
            }
        }
        swap(nums[gola_index], nums[swap_index]);
        reverse(nums.begin()+gola_index+1, nums.end());
    }
};