#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using namespace std;

int min(int a, int b){
  if(a<b)
    return a;
  else return b;
}

void req_seq(int n, int arr[]){
  
  arr[0] = 0;
  arr[1] = 0;
  for(int i=2;i<=n;i++)
  {
    arr[i] = 1 +arr[i-1];

    if(i%2==0)
    arr[i] = min(arr[i],1+arr[i/2]);

    if(i%3==0)
      arr[i] = min(arr[i],1+arr[i/3]); 
  }

}

vector<int> optimal_sequence(int n) {
  std::vector<int> sequence;
  while (n >= 1) {
    sequence.push_back(n);
    if (n % 3 == 0) {
      n /= 3;
    } else if (n % 2 == 0) {
      n /= 2;
    } else {
      n = n - 1;
    }
  }
  reverse(sequence.begin(), sequence.end());
  return sequence;
}

int main() {
  int n;
  std::cin >> n;

  // int arr[n+1];
  // req_seq(n, arr);

  // for(int i=0;i<=n;i++)
  //   cout<<i<<" "<<arr[i]<<endl;
  int t=0;
  int y=n;
  int arr[n+1];
  req_seq(n,arr);
  std::vector<int> sequence;
  int c;
  while(n!=1)
  {
    c=n;
if(c%3==0 && arr[c] == 1+arr[c/3]){
      sequence.push_back(n/3);
      n=n/3;
    }
else if(c%2==0 && arr[c] == 1+arr[c/2]){
      sequence.push_back(n/2);
      n=n/2;
    }

    else if(arr[c]==1+arr[c-1])
      {
        sequence.push_back(n-1);
        n=n-1;}
   t++;
      
  }
  reverse(sequence.begin(), sequence.end());

  std::cout << t<< std::endl;
  for (size_t i = 0; i < sequence.size(); ++i) {
    std::cout << sequence[i] << " ";
  }
  std::cout<<y;
}
