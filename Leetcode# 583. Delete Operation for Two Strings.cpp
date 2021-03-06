class Solution {
public:
    int minDistance(string word1, string word2) {
        
        int m=word1.size();
        int n=word2.size();
        int** output=new int*[m+1];
        for(int i=0;i<=m;i++){
            output[i]=new int[n+1];
            for(int j=0;j<=n;j++){
                output[i][j]=-1;
            }
        }
        
        //for row
        for(int i=0;i<=m;i++){
            output[i][0]=i;
        }
        
        //for column
        for(int i=0;i<=n;i++){
            output[0][i]=i;
        }
        
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(word1[m-i]==word2[n-j]){
                    output[i][j]=output[i-1][j-1];
                }
                else{
                    output[i][j]=1+min(output[i-1][j],output[i][j-1]);
                }
            }
        }
        return output[m][n];
    }
};
