// #include <iostream>
//
// using namespace std;
//
// // long long get_fibonacci_huge_naive(long long n, long long m) {
// //     if (n <= 1)
// //         return n;
//
// //     long long previous = 0;
// //     long long current  = 1;
//
// //     for (long long i = 0; i < n - 1; ++i) {
// //         long long tmp_previous = previous;
// //         previous = current;
// //         current = tmp_previous + current;
// //     }
//
// //     return current % m;
// // }
//
// unsigned long long fibonacci(unsigned long long k){
//     if(k<=1)
//         return k;
//     unsigned long long a,b;
//     a=0;b=1;
//     unsigned long long c;
//     for(unsigned long long i=0;i<k-1;i++){
//         c=a+b;
//         a=b;
//         b=c;
//     }
//     return c;
// }
//
// unsigned long long findperiod(unsigned long long m) {
//
//     if(m<=1)
//     return m;
//     unsigned long long a = 0, b = 1, c = a + b;
//     for (unsigned long long i = 0; i < m * m; i++) {
//         c = (a + b) % m;
//         a = b;
//         b = c;
//         if (a == 0 && b == 1) {
//           cout<<i+1<<endl;
//           return i + 1;}
//     }
//     return 0;
// }
//
// unsigned long long fibonacci_fast(unsigned long long n,unsigned long long m){
//
//     unsigned long long p = findperiod(m);
//     // cout<<p;
//     unsigned long long k = n%p;
//     cout<<k<<endl;
//     unsigned long long pi = fibonacci(k);
//     cout<<pi<<endl;
//     unsigned long long s=pi%m;
//     return s;
//     // return 10;
// }
//
// int main() {
//     unsigned long long n, m;
//     std::cin >> n >> m;
//     std::cout << fibonacci_fast(n, m) << '\n';
// }


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
	long n,m;
	F[0]=F[1]=1;
  cin>>n>>m;
	// while (cin >> n)
	cout << (n==0 ? 0 : f(n-1,m)) << endl;
}
