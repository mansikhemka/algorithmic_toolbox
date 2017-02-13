#include <iostream>
#include <vector>

using std::vector;

using namespace std;

long long merge(vector<long long> &a, size_t left,size_t ave, size_t right){
  int i,j,k,temp[right];
  long long number_of_inversions=0;
  i=left; j=ave;
  k=left;
  
  while(i<ave && j<right){
    if(a[i]<=a[j]){
      temp[k]=a[i]; 
      i++;
    }
    else{
      // p=p+1;
      // if(p==1)
      number_of_inversions+=ave-i;
      temp[k]=a[j];
      j++;
    }
    k++;
  }
  while(i<ave){
    temp[k]=a[i];
    i++;
    k++;
  }
  while(j<right){
    temp[k]=a[j];
    j++;
    k++;
  }

  for(int i=left;i<right;i++)
    a[i]=temp[i];

  return number_of_inversions;
}

long long get_number_of_inversions(vector<long long> &a, size_t left, size_t right) {
  long long number_of_inversions = 0;
  if (right <= left + 1) return number_of_inversions;
  size_t ave = left + (right - left) / 2;
  number_of_inversions += get_number_of_inversions(a, left, ave);
  number_of_inversions += get_number_of_inversions(a, ave, right);
  //write your code here
  number_of_inversions += merge(a, left, ave, right);
  

  return number_of_inversions;
}

int main() {
  int n;
  std::cin >> n;
  vector<long long> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  // vector<int> b(a.size());

  long long j=get_number_of_inversions(a, 0, a.size());
  // if(j!=0) j=j-1; 
 // for (size_t i = 0; i < a.size(); i++) {
 //    std::cout << a[i];
 //  }
 //  std::cout<<endl;
  std::cout <<j<< '\n';
}


