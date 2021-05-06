class Solution {
public:
    int majorityElement(vector<int>& arr) {
        int count=0;
        int ele=0;
        for(int i=0;i<arr.size();i++){
            if(count==0){
                ele=arr[i];
            }
            if(ele==arr[i]){
                count++;
            }
            else{
                count--;
            }
        }
        return ele;
    }
};
