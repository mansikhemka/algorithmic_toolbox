#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;
using namespace std;

void merge(vector<long long> &a, int low, int mid, int high){
  int i,j,k;
  long long t[high];
  i=low;
  k=low;
  j=mid+1;

  while(i<=mid && j<=high){
    if(a[i]<a[j]){
      t[k]=a[i];
      i++;
    }
    else{
      t[k]=a[j];
      j++;
    }
    k++;
  }
  while(i<=mid){
    t[k]=a[i];
    i++;
    k++;
  }
  while(j<=high){
    t[k]=a[j];
    j++;
    k++;
  }
  for(i=low;i<=high;i++)
    a[i]=t[i];
}

void mergesort(vector<long long> &a, int low, int high){
  if(low<high){
    int mid=(low+high)/2;
    mergesort(a, low, mid);
    mergesort(a, mid+1, high);
    merge(a, low, mid, high);
  }
}

int get_majority_element(vector<long long> &a, int left, int right) {
  if (left == right) return -1;
  if (left + 1 == right) return a[left];
  //write your code here
  mergesort(a,0,right-1);
  int count;
  int n=right;
  long long p=a[0];
  for(int i=0;i<n;i++){
     count=0;
       p=a[i];
     while(a[i]==p){
      count++;
      i++;
     }
     i=i-1;
     // cout<<count<<endl;
     if(count>n/2)
      return 1;
   

  }
  return -1;
}

int main() {
  int n;
  std::cin >> n;
  vector<long long> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  // get_majority_element(a, 0, a.size());
  std::cout << (get_majority_element(a, 0, a.size()) != -1) << '\n';
}
