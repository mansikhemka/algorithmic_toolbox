#include<iostream>

using namespace std;

int main(){
	int n,k;

	cin>>n;
	long long a[n];
	for(int i=0;i<n;i++)
		cin>>a[i];

	cin>>k;
	long long b[k];
	for(int i=0;i<k;i++)
		cin>>b[i];
    
    int in[k];

    for(int i=0;i<k;i++){
    	int s=b[i];
    	in[i]=-1;
        int low=0;
        int high=n-1;
    	while(low<=high){
    		int mid=(low+high)/2;
    		if(s==a[mid])
    		{
                in[i]=mid;
                break;
    		}
    		else if(s<mid)
    			high=mid-1;
    		else
    			low=mid+1;
    	} 
    }
    for(int i=0;i<k;i++)
    	cout<<in[i]<<" ";
}