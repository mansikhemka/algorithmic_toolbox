#include <iostream>

using namespace std;

// long long get_fibonacci_huge_naive(long long n, long long m) {
//     if (n <= 1)
//         return n;

//     long long previous = 0;
//     long long current  = 1;

//     for (long long i = 0; i < n - 1; ++i) {
//         long long tmp_previous = previous;
//         previous = current;
//         current = tmp_previous + current;
//     }

//     return current % m;
// }

long long fibonacci(long long k){
    if(k<=1)
        return k;
    long long a,b;
    a=0;b=1;
    long long c;
    for(long long i=0;i<k-1;i++){
        c=a+b;
        a=b;
        b=c;
    }
    return c;
}

long long findperiod(long long m){
    long long a=0; long long b=1;
    long long l,n; l=0;n=0;
    long long c;
    if(m<=1)
        return 1;
    int t=0;
    while(l!=0 && n!=1){
            c=a+b;
            a=b;
            b=c;
            l=a%m;
            n=b%m;
            t++;

    }
    return t;
    cout<<t;
}

long long fibonacci_fast(long long n, long long m){
    long long p = findperiod(m);
    long long k = n%p;
    long long pi = fibonacci(k);
    return 0;
}

int main() {
    long long n, m;
    std::cin >> n >> m;
    std::cout << fibonacci_fast(n, m) << '\n';
}
