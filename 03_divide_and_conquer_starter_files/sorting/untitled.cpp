#include<iostream>

using namespace std;

int main(){
	int t;
	cin>>t;

	while(t--){
		long long c,d,l;
		cin>>c>>d>>l;

		long long ds=l-d*4;
		if(ds>0){
			if(ds%4==0){
				long long cs=c-ds/4;
				if(cs>0){
					if(cs>2*d)
						cout<<"no";
					else
						cout<<"yes";
				}
				else{
					cout<<"no";
				}
			}
			else{
				cout<<"no";
			}
		}
		else{
			cout<<"no"<<endl;
		}
	}
}