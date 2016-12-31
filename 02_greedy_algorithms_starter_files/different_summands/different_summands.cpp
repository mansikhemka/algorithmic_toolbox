#include <iostream>
// #include <vector>

// using std::vector;

// vector<int> optimal_summands(int n) {
//   vector<int> summands;

//   //write your code here
//   return summands;
// }

// int main() {
//   int n;
//   std::cin >> n;
//   vector<int> summands = optimal_summands(n);
//   std::cout << summands.size() << '\n';
//   for (size_t i = 0; i < summands.size(); ++i) {
//     std::cout << summands[i] << ' ';
//   }
// }

using namespace std;

int main(){
  int n,l;
  cin>>n;
 
  if(n==1 || n==2){
    cout<<"1"<<endl<<n;
  }
  else
  {
     l=n;
     int i;
    for(i=1;i<n;i++){
         if(i<=l){
          l=l-i;
         }
         else break;
    }
    cout<<i-1<<endl;
    int j;
    for(j=1;j<=i-2;j++){
       cout<<j<<" ";
    }
    cout<<j+l;}
}