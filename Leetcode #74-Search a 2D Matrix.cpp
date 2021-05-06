class Solution {
public:
    bool searchMatrix(vector<vector<int>>& arr, int target) {
    	
    	//this would work fine for both problems gfg as well as leetcode
        int i=0;
        int j=arr[0].size()-1;
        while(i<arr.size() && j>=0){
            if(arr[i][j]==target){
                return true;
            }
            
            else if(target>arr[i][j]){
                i++;
            }
            
            else{
                j--;
            }
            
        }
        return false;
        
        //it is given in the leetcode every The first integer of each row is greater than the last integer of the previous row.
        //so we'll use the binary search inplace
        
        
        if(arr.size()==0)
            return 0;
        int start=0;
        int end=(arr[0].size()*arr.size())-1;
        
        while(start<=end){
            int mid=(start+end)/2;
            int i=mid/arr[0].size();
            int j=mid%arr[0].size();
            if(arr[i][j]==target){
                return true;
            }
            
            else if(arr[i][j]>target){
                end=mid-1;
            }
            else{
                start=mid+1;
            }
        }
        return false;
    }
    }
};
