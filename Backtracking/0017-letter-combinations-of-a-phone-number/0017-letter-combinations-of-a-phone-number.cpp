class Solution {
public:
void solve(string digits,unordered_map<char,string>&mp,string temp,int i,vector<string>&ans){
    if(i==digits.size()){
        ans.push_back(temp);
        return;
    }
    string letters = mp[digits[i]];
    for(char ch : letters){
        temp.push_back(ch);
        solve(digits,mp,temp,i+1,ans);
        temp.pop_back();
    }
}
    vector<string> letterCombinations(string digits) {
        
        unordered_map<char,string>mp={
            {'2',"abc"},{'3',"def"},{'4',"ghi"},{'5',"jkl"},{'6',"mno"},{'7',"pqrs"},{'8',"tuv"},{'9',"wxyz"}
        };
        vector<string>ans;
        string temp="";
        solve(digits,mp,temp,0,ans);
        return ans;
    }
};