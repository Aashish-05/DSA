class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();
        vector<bool>check(n,true);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(fruits[i]<=baskets[j] && check[j]==true){
                    check[j]=false;
                    break;
                }
            }
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            if(check[i]==true) ans++;
        }
        return ans;
    }
};