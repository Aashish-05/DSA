class Solution {
private:
    int digits(int n){
        int rem=0,sum=0;;
        while(n>0){
            rem = n%10;
            sum+=rem;
            n=n/10;
        }
        return sum;
    }
public:
    int smallestIndex(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            int sum = digits(nums[i]);
            if(sum==i) return i;
        }
        return -1;
    }
};