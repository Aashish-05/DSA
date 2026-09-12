class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
         unordered_map<long long,vector<long long>>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]].push_back(i);
        }
        int ans = 0;
        for(auto it : mp){
            if(it.second.size()>=3){
                bool check = true;
                for(int i=0;i<it.second.size()-2;i++){
                    if(it.second[i+1]-it.second[i] != it.second[i+2]-it.second[i+1]){
                        check = false;
                        break;
                    }
                }
                if(check==true) ans++;
            }
        }
        return ans;
    }
};