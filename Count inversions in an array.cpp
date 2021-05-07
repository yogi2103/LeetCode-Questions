#include<iostream>
using namespace std;


int merge(int arr[],int temp[],int low,int mid,int high){
	int i,j,k;
	int inv_count=0;
	i=low;
	j=mid;
	k=low;
	
	while(i<=mid-1 && j<=high){
		if(arr[i]<arr[j]){
			temp[k++]=arr[i++];
		}
		else{
			temp[k++]=arr[j++];
			inv_count+=(mid-i);
		}
	}
	
	while(i<=mid-1){
		temp[k++]=arr[i++];
	}
	
	while(j<=high){
		temp[k++]=arr[j++];
	}
	
	for(i=low;i<=high;i++){
		arr[i]=temp[i];
	}
	return inv_count;
}

int mergeSort(int arr[],int temp[],int low,int high){
	int mid,count_inv=0;
	if(high>low){
		mid=(low+high)/2;
		count_inv+=mergeSort(arr,temp,low,mid);
		count_inv+=mergeSort(arr,temp,mid+1,high);
		count_inv+=merge(arr,temp,low,mid+1,high);
	}
	return count_inv;
}

int main(){
	int arr[]={5,3,2,4,1};
	int n=sizeof(arr)/sizeof(arr[0]);
	int temp[n];
	int ans=mergeSort(arr,temp,0,n-1);
	cout<<ans;
}
