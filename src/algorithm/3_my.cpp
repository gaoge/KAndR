#include<iostream>

int arrayMax(int *a,int n){
	int sum = 0;
	int maxSum = 0;
	int temp = a[0];
	for(int i=1;i<n;i++){
		if(a[i] > temp){
			temp = a[i];
		}
		
	}
	if(temp <= 0) return temp;
	for(int i=0;i<n;i++){
		if(sum <= 0){
			sum = a[i];
		}else{
			sum += a[i];
		}
		if(sum > maxSum){
			maxSum = sum;
		}
	}

	return maxSum;
}

main(){

	//int a[] = {3,-4,6,12,-9,5,-8,7};
	int a[] = {-3,-4,-6,-12,-9,-5,-8,-7};
	std::cout<<"Max sum is: "<<arrayMax(a,8)<<std::endl;
}
