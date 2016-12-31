// #include <algorithm>
#include <iostream>
// #include <vector>

// using std::vector;

// long long max_dot_product(vector<int> a, vector<int> b) {
//   // write your code here
//   long long result = 0;
//   for (size_t i = 0; i < a.size(); i++) {
//     result += ((long long) a[i]) * b[i];
//   }
//   return result;
// }

// int main() {
//   size_t n;
//   std::cin >> n;
//   vector<int> a(n), b(n);
//   for (size_t i = 0; i < n; i++) {
//     std::cin >> a[i];
//   }
//   for (size_t i = 0; i < n; i++) {
//     std::cin >> b[i];
//   }
//   std::cout << max_dot_product(a, b) << std::endl;
// }

using namespace std;

void merge(long long k[], long long low, long long mid, long long high){
  long long i,m,l,t1[high];
  l=low;
  i=low;
  m=mid+1;

  while((l<=mid)&&(m<=high)) { 
    if(k[l]<=k[m]) {
       t1[i] = k[l];
       l++;
    }
    else{ 
       t1[i] = k[m];
       m++;
    }
    i++;
  }
  while(l<=mid){
       t1[i] = k[l];
       l++;
       i++;
  }
  while(m<=high){
       t1[i] = k[m];
      m++;
        i++;
  }

  for(long long p=low;p<=high;p++){
    k[p]=t1[p];
  }
}

void mergesort(long long k[],long long low,long long high){
   long long mid;
   if(low<high){
    mid=(low+high)/2;
    mergesort(k,low, mid);
    mergesort(k,mid+1, high);
    merge(k,low, mid, high);
   }
}


//   return s;
// }

int main(){
  long long n;
  cin>>n;
  long long a[n];
  long long b[n];

  for(long long i=0;i<n;i++)
    cin>>a[i];
  

  for(long long i=0;i<n;i++)
    cin>>b[i];

  mergesort(a, 0 , n-1);
  mergesort(b, 0, n-1);

  // int max_product(int a[], int b[], int n){
  long long s=0;
  for(long long i=0;i<n;i++){
    // if(a[i]*b[i]>0)
    s=s+a[i]*b[i];
  }

  cout<<s<<endl;
}