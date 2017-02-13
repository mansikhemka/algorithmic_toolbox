// #include <iostream>
// #include <cassert>
// #include <vector>

// using std::vector;

// int binary_search(const vector<int> &a, int x) {
//   int left = 0, right = (int)a.size(); 
//   //write your code here
// }

// int linear_search(const vector<int> &a, int x) {
//   for (size_t i = 0; i < a.size(); ++i) {
//     if (a[i] == x) return i;
//   }
//   return -1;
// }

// int main() {
//   int n;
//   std::cin >> n;
//   vector<int> a(n);
//   for (size_t i = 0; i < a.size(); i++) {
//     std::cin >> a[i];
//   }
//   int m;
//   std::cin >> m;
//   vector<int> b(m);
//   for (int i = 0; i < m; ++i) {
//     std::cin >> b[i];
//   }
//   for (int i = 0; i < m; ++i) {
//     //replace with the call to binary_search when implemented
//     std::cout << linear_search(a, b[i]) << ' ';
//   }
// }
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
        else if(s<a[mid])
          high=mid-1;
        else
          low=mid+1;
      } 
    }
    for(int i=0;i<k;i++)
      cout<<in[i]<<" ";
}