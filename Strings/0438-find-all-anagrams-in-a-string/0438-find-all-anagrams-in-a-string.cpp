class Solution {
public:
bool allZero(unordered_map<char,int>&mp){
    for(auto it :mp){
        if(it.second !=0) return false;
    }
    return true;
}
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char, int> mp;
        for (auto it : p) {
            mp[it]++;
        }
        int n = s.size();
        int m = p.size();
        int count = 0;
        int j = 0, i = 0;
        vector<int> ans;
        while (j < n) {
            mp[s[j]]--;
            if (j - i + 1 == m) {
                if (allZero(mp)) {
                    ans.push_back(i);
                }
                mp[s[i]]++;
                i++;
            }
            j++;
        }
        return ans;
    }
};