#include <iostream>
#include <vector>

using std::vector;

using namespace std;

void merge(vector<long long> & starts, int low, int mid, int high){
  int i,j,k;
  long long temp1[high+1];
  i=low; j=mid+1; k=low;
  while(i<=mid && j<=high){
    if(starts[i]<=starts[j]){
      temp1[k]=starts[i];
      i++;
    }
    else{
      temp1[k]=starts[j];
      j++;
    }
    k++;
  }
  while(i<=mid){
      temp1[k]=starts[i];
      i++;
      k++;
  }
  while(j<=high){
    temp1[k]=starts[j];
      j++;
      k++;
  }
  for(i=low;i<=high;i++){
    starts[i]=temp1[i];
  }
}

void mergesort(vector<long long> & starts, int low, int high){ 
  if(low<high){
    int mid=(low+high)/2;
    mergesort(starts,low,mid);
    mergesort(starts,mid+1,high);
    merge(starts,low,mid,high);
  }
}

int search(vector<long long> & s, int val){
     int l,r,m;
     l=0;
     r=s.size()-1;
     
     while(l<=r){
      m=(l+r)/2;
     if(val==s[m])
      {
        while(val==s[m-1])
          m--;
        return m;
      }
    else if(val<s[m])
      r=m-1;
    else
      l=m+1;
     }
     return l;
}
int search1(vector<long long> & s, int val){
     int l,r,m;
     l=0;
     r=s.size()-1;
     
     while(l<=r){
      m=(l+r)/2;
     if(val==s[m])
      {
        while(val==s[m+1])
          m++;
        return m+1;
      }
    else if(val<s[m])
      r=m-1;
    else
      l=m+1;
     }
     return l;
}

vector<long long> fast_count_segments(vector<long long> starts, vector<long long> ends, vector<long long> points) {
  vector<long long> cnt(points.size());
  //write your code here
  mergesort(starts, 0, starts.size()-1);
  mergesort(ends, 0, ends.size()-1);

for(int i=0;i<points.size();i++){
  cnt[i] = search1(starts,points[i])-search(ends, points[i]); 
} 
  
  return cnt;
}

vector<int> naive_count_segments(vector<int> starts, vector<int> ends, vector<int> points) {
  vector<int> cnt(points.size());
  for (size_t i = 0; i < points.size(); i++) {
    for (size_t j = 0; j < starts.size(); j++) {
      cnt[i] += starts[j] <= points[i] && points[i] <= ends[j];
    }
  }
  return cnt;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<long long> starts(n), ends(n);
  for (size_t i = 0; i < starts.size(); i++) {
    std::cin >> starts[i] >> ends[i];
  }
  vector<long long> points(m);
  for (size_t i = 0; i < points.size(); i++) {
    std::cin >> points[i];
  }
  // fast_count_segments
  vector<long long> cnt = fast_count_segments(starts, ends, points);
  for (size_t i = 0; i < cnt.size(); i++) {
    std::cout << cnt[i] << ' ';
  }
}
