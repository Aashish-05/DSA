class Solution {
private:
long long totalhours(vector<int> &piles,int h){
    long long total=0;
    int n = piles.size();
    for(int i=0;i<n;i++){
        total+=(piles[i]+h-1)/h;
    }
    return total;
}
int maximum(vector<int>&piles){
    int maxi=INT_MIN;
    for(int i=0;i<piles.size();i++){
        if(piles[i]>maxi){
            maxi=piles[i];
        }
    }
    return maxi;
}
public:
    int minEatingSpeed(vector<int>& piles, int h) {
      int i=1;
      int j=maximum(piles);
      while(i<=j){
        int mid = (i+j)/2;
        long long totalH=totalhours(piles,mid);
        if(totalH<=h){
            j=mid-1;
        }
        else{
            i=mid+1;
        }
      }
      return i;
        
    }
};