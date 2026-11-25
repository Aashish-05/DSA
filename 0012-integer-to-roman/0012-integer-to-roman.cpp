class Solution {
public:
    string intToRoman(int num) {
       vector<pair<int, string>> valueMap = {
            {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
            {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"},
            {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}
        };
        string result = "";
        for(int i=0;i<valueMap.size();i++){
            while(num>=valueMap[i].first){
                result+=valueMap[i].second;
                num-=valueMap[i].first;
            }
        }
        return result;
    }
};