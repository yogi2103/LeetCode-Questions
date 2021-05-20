#include<iostream>
using namespace std;

int uniquePaths(int m, int n) {
	int dp[m][n];
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			dp[i][j]=0;
		}
	}
	int row=m;
	int col=n;
    //for filling the column with 1
	for(int i=row-2;i>=0;i--){
		dp[i][col-1]=1;
	}
	
	//for filling the row with 1
	for(int i=0;i<col-1;i++){
		dp[row-1][i]=1;
	}
	
	//for filling the rest elements
	for(int i=col-2;i>=0;i--){
		for(int j=row-2;j>=0;j--){
			dp[j][i]=dp[j+1][i]+dp[j][i+1];
		}
	}
	for(int i=0;i<row;i++){
		for(int j=0;j<col;j++){
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}
	return dp[0][0];
}

int main(){
	cout<<uniquePaths(3,3);
}
