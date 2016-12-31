

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


// #include<iostream>
// #include<cmath>

// using namespace std;

// int count(int k){
//   int i=1;
//   while(k>9){
//     i++;
//     k=k/10;
//   }
//   return i;
// }

// int compare(int a, int b){
//   if(a==-1) return b;
//   if(a==b) return a;
//   int l,m,l10,m10,p,w,q;
//   l=count(a);
//   m=count(b);
//   if(l<m) p=l;
//   else p=m;
//   w=l10=pow(10,l-1);
//   q=m10=pow(10,m-1);
//   for(int i=1;i<=p;i++){
//     if(a/l10>b/m10)
//       return a;
//     else if(a/l10<b/m10)
//       return b;
//     else
//     {
//       l10=l10/10;
//       m10=m10/10;
//     }
//   }
//   if(l<m)
//     {
//        if(a/w<b/m10)
//         return a;
//       else return b;
//     }
//   else  {
//        if(a/q<b/l10)
//         return a;
//       else return b;
//     }

// }

// int main(){
// int n;
// cin>>n;
// int p[n],q[n];

// for(int i=0;i<n;i++)
//   cin>>p[i];

// int m=p[0]; int in=0;
// int e=0,r;
// while(e!=n)
//  { 
//   m=0;
//   for(int i=0;i<n;i++)
//    {
//      int l=m;
//      if(p[i]!=-1)
//       m=compare(m,p[i]);
//    else
//      continue;
//     if(m!=l)
//      in = i;
//    }
 
//    q[e]=m;
//    p[in]=-1;
//    e++;
//  }

//  for(int i=0;i<n;i++)
//    cout<<q[i];

//  cout<<endl;
// }




// // #include <algorithm>
// // #include <sstream>
// // #include <iostream>
// // #include <vector>
// // #include <string>

// // using std::vector;
// // using std::string;

// // string largest_number(vector<string> a) {
// //   //write your code here
// //   std::stringstream ret;
// //   for (size_t i = 0; i < a.size(); i++) {
// //     ret << a[i];
// //   }
// //   string result;
// //   ret >> result;
// //   return result;
// // }

// // int main() {
// //   int n;
// //   std::cin >> n;
// //   vector<string> a(n);
// //   for (size_t i = 0; i < a.size(); i++) {
// //     std::cin >> a[i];
// //   }
// //   std::cout << largest_number(a);
// // }
