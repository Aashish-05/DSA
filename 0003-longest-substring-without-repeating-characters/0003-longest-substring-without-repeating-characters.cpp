class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        int i = 0;
        unordered_set<int> st;
        for (int j = 0; j < s.size(); j++) {
            while(st.find(s[j]) != st.end()){
                st.erase(s[i]);
                i++;
            }
            st.insert(s[j]);
            ans = max(ans,j-i+1);
        }
        return ans;
    }
};