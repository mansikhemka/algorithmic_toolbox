

#include <algorithm>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;

using namespace std;

// bool compare(string a, string b){
//   string c,d;
//   c=a+b;
//   d=b+a;
//   cout<<stoi(c)<<endl;
//   if(stoi(c)>=stoi(d))
//     return false;
//   else return true;
// }

string largest_number(vector<string> a) {
  //write your code here
  // int p[n];
  for (size_t i = 0; i < a.size(); i++)
    {
      for(size_t j = i; j < a.size(); j++){
        
        if(stoi(a[i]+a[j])<stoi(a[j]+a[i])){
          string temp = a[i];
          a[i] = a[j];
          a[j]=temp;
        }
      }
    }
  std::stringstream ret;
  for (size_t i = 0; i < a.size(); i++) {
    ret << a[i];
  }
  string result;
  ret >> result;
  return result;
}

int main() {
  int n;
  std::cin >> n;
  vector<string> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  std::cout << largest_number(a);
}