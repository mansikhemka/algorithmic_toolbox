


#include <map>
#include <iostream>
using namespace std;

#define long long long // modulo
map<long, long> F;

long f(long n, long m) {
	if (F.count(n)) return F[n];
	long k=n/2;
	if (n%2==0) { // n=2*k
		return F[n] = (f(k,m)*f(k,m) + f(k-1,m)*f(k-1,m)) % m;
	} else { // n=2*k+1
		return F[n] = (f(k,m)*f(k+1,m) + f(k-1,m)*f(k,m)) % m;
	}
}

int main(){
	long n,m,p,q;
	F[0]=F[1]=1;
  cin>>n>>m;
	// while (cin >> n)
  if(n==m)
    {
      if(n==0)
      cout<<0;
      else
      cout<<f(n-1,10);
    }
else{

  if(n==0)
   p=0;
   else
   {
     long k=f(n,10);
     if(k==0)
     p=9;
     else p=k-1;
   }

   if(m==0)
    q=0;
    else
    {
      long k=f(m+1,10);
      if(k==0)
      q=9;
      else q=k-1;
    }


  // p=f(n,10);
  // cout<<p<<endl;
  // q=f(m+1,100);
  // cout<<q<<endl;
  int u=(q-p)%10;
  if(u>=0)
  cout<<u;
  else cout<<10+u;
}


	// cout <<m<< endl;
}
