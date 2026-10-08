class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();
        if (n < m) return "";

        unordered_map<char, int> mp;

        for (char x : t) mp[x]++;

        int i = 0;
        int start = 0, end = INT_MAX;
        int count = 0;
        for (int j = 0; j < n; j++) {
            if(mp.find(s[j]) != mp.end()) {
                mp[s[j]]--;
                if(mp[s[j]]>=0){
                    count++;
                }
            }
            while (count==m) {
                if (j - i < end - start || (end ==INT_MAX)) {
                    start = i;
                    end = j;
                }

                if (mp.find(s[i]) != mp.end()) {
                    mp[s[i]]++;
                    if(mp[s[i]]>0){
                        count--;
                    }
                }

                i++;
            }
        }
        if(end==INT_MAX) return "";
        return s.substr(start,end-start+1);
}
};