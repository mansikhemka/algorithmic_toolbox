#include <iostream>
#include <vector>
#include <cstdlib>

using std::vector;
using std::swap;

int partition2(vector<int> &a, int l, int r) {
  int x = a[l];
  int j = l;
  for (int i = l + 1; i <= r; i++) {
    if (a[i] <= x) {
      j++;
      swap(a[i], a[j]);
    }
  }
  swap(a[l], a[j]);
  return j;
}

void partition1(vector<int> &a, int l, int r, int m[]){
  int x=a[l];
  int m1=l-1;
  int m2=l;
  for(int i=l+1; i<=r; i++){
     if(a[i]==x){
      m2++;
      swap(a[m2],a[i]);
    }
    else if(a[i]<x){
      m1++;
      m2++;
      swap(a[m1],a[m2]);
      if(i!=m2)
      swap(a[m1],a[i]);
    }
  }
  m[0]=m1;
  m[1]=m2;
}

void randomized_quick_sort(vector<int> &a, int l, int r) {
  if (l >= r) {
    return;
  }

  int k = l + rand() % (r - l + 1);
  swap(a[l], a[k]);
  int m[2];
  partition1(a, l, r,m);

  randomized_quick_sort(a, l, m[0]);
  randomized_quick_sort(a, m[1]+1, r);
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  randomized_quick_sort(a, 0, a.size() - 1);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cout << a[i] << ' ';
  }
}
