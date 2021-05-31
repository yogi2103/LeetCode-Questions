class Solution {
public:
    int change(int tar, vector<int>& arr) {
        int n=arr.size();
        int dp[tar+1];
        for(int i=0;i<=tar;i++){
            dp[i]=0;
        }
        dp[0]=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<=tar;j++){
                if(j>=arr[i]){
                    dp[j]+=dp[j-arr[i]];
                }
            }
        }
        return dp[tar];
    }
};
