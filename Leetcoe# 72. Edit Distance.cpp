int minDistance(string s1, string s2) {
        int m=s1.size();
        int n=s2.size();
        int** output=new int*[m+1];
        for(int i=0;i<=m;i++){
            output[i]=new int[n+1];
            for(int j=0;j<=n;j++){
                output[i][j]=0;
            }
        }

        //for filling the first row
        for(int i=0;i<=m;i++){
            output[i][0]=i;
        }

        //for fillinf the first column
        for(int i=0;i<=n;i++){
            output[0][i]=i;
        }

        //for filling the rest
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(s1[m-i]==s2[n-j]){
                    output[i][j]=output[i-1][j-1];
                }
                else{
                    output[i][j]=1+min(output[i][j-1],min(output[i-1][j],output[i-1][j-1]));
                }
            }
        }
        return output[m][n];
    }
};
