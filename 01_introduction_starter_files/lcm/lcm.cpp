#include <iostream>

using namespace std;

// long long lcm_naive(int a, int b) {
//   for (long l = 1; l <= (long long) a * b; ++l)
//     if (l % a == 0 && l % b == 0)
//       return l;

//   return (long long) a * b;
// }

long long gcd(long long a, long long b){
	if(b==0)
		return a;
	long long adash = a%b;
	return gcd(b, adash);
}

long long lcm(long a, long b){
	long long g=gcd(a,b);
	//cout<<g;
	long long l=(a*b)/g;
	return l;
}

int main() {
  long long a, b;
  std::cin >> a >> b;
  std::cout << lcm(a, b) << std::endl;
  return 0;
}
