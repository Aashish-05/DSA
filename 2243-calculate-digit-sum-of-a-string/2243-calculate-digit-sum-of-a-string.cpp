class Solution {
public:
    string digitSum(string s, int k) {
        int n = s.size();
        while(s.size()>k){
            int len = ceil((double)n/k);
            string dup = "";
            int i=0;
            while(len--){
                int sum = 0;
                for(int j=i;j<min(i+k,n);j++){
                    sum+=(s[j]-'0');
                }
                dup+=to_string(sum);
                i+=k;
            }
            s=dup;
            n=s.size();
        }
        return s;
    }
};