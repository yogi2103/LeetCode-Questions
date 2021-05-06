class Solution {
public:
    int missingNumber(vector<int>& arr) {
        long long int maxi=arr.size();
        long int Sum=(maxi*(maxi+1))/2;
        long int Sum_sq=(maxi)*(maxi+1)*(2*maxi+1)/6;
        for(int i=0;i<maxi;i++){
            Sum-=(long long int) arr[i];
            Sum_sq-=(long long int) arr[i]*(long long int) arr[i];
        }
        long int missingNumber;
        if(Sum==0){
            missingNumber = (Sum + Sum_sq)/2;
        }
        else{
            missingNumber = (Sum + Sum_sq/Sum)/2;
        }
        long int repeating= missingNumber - Sum;
        return missingNumber;
    }
};
