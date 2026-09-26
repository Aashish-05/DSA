class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        int n = s.size();
        unordered_map<string,string>mp;
        for(auto x : knowledge){
            mp[x[0]] = x[1];
        }
        string a ="";
        for(int i=0;i<n;i++){
            if(s[i] != '('){
                a+=s[i];
            }
            else{
                string key = "";
                i++;
                while(s[i] !=')'){
                    key+=s[i];
                    i++;
                }
                if(mp.find(key) !=mp.end()){
                    a+=mp[key];
                }
                else{
                    a+='?';
                }
            }
        }
        return a;
    }
};