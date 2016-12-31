// #include <algorithm>
#include <iostream>

using namespace std;


int main(){
 long long n;
  cin>>n;

  long long s[n],e[n+1];

  for(long long i=0;i<n;i++)
      cin>>s[i]>>e[i];

  for(int i=0;i<n;i++){
    for(int j=i;j<n;j++){
      if(e[j]<e[i]){
        long long temp1=e[i];
        e[i]=e[j];
        e[j]=temp1;
        temp1 = s[i];
        s[i] = s[j];
        s[j] = temp1;
      }
    }
  }

  e[n]=-2;

  long long m=0;

  int j=0,k[n+1];
  while(e[j]!=-2){

    // cout<<e[j]<<" ";

    k[j]=e[j];
  if(e[j]!=-1)
      for(int i=0;i<n;i++)
          if(s[i]<=k[j])
             s[i]=e[i]=-1;
    
    j++;
  }
  for(int i=0;i<n;i++)
    if(k[i]>0)
      m++;

    cout<<endl<<m<<endl;

  for(int i=0;i<n;i++)
    if(k[i]>0)
      cout<<k[i]<<" ";
}

// #include <climits>
// #include <vector>

// using std::vector;

// struct Segment {
//   int start, end;
// };

// vector<int> optimal_points(vector<Segment> &segments) {
//   vector<int> points;
//   //write your code here
//   for (size_t i = 0; i < segments.size(); ++i) {
//     points.push_back(segments[i].start);
//     points.push_back(segments[i].end);
//   }
//   return points;
// }

// int main() {
//   int n;
//   std::cin >> n;
//   vector<Segment> segments(n);
//   for (size_t i = 0; i < segments.size(); ++i) {
//     std::cin >> segments[i].start >> segments[i].end;
//   }
//   vector<int> points = optimal_points(segments);
//   std::cout << points.size() << "\n";
//   for (size_t i = 0; i < points.size(); ++i) {
//     std::cout << points[i] << " ";
//   }
// }

// for(long long i=1;i<n;i++){
  //   if(e[m]!=-1)
  //   {
  //     if(s[i]>e[m])
  //        { m++;
  //         i++;}
  //       else
  //         s[i]=-1;
  //       e[i]=-1;
  //       }
  // }
  // m++;
//   cout<<m<<endl;
//   for(long long i=0;i<n;i++)
//       if(e[i]!=-1)
//       cout<<e[i]<<" ";
// }



// void merge(long long e[],long long s[], long long low, long long mid, long long high){
//   long long i,m,l,t1[high];
//   long long t2[high];
//   l=low;
//   i=low;
//   m=mid+1;

//   while((l<=mid)&&(m<=high)) { 
//     if(e[l]<=e[m]) {
//        t1[i] = e[l];
//        t2[i] = s[l];
//        l++;
//     }
//     else{ 
//        t1[i] = e[m];
//        t2[i] = s[m];
//        m++;
//     }
//     i++;
//   }
//   while(l<=mid){
//        t1[i] = e[l];
//        t2[i] = s[l];
//        l++;
//        i++;
//   }
//   while(m<=high){
//        t1[i] = e[m];
//        t2[i] = s[m];
//       m++;
//         i++;
//   }

//   for(long long p=low;p<=high;p++){
//     e[p]=t1[p];
//     s[p]=t2[p];
//   }
// }

// void mergesort(long long e[], long long s[],long long low,long long high){
//    long long mid;
//    if(low<high){
//     mid=(low+high)/2;
//     mergesort(e,s,low, mid);
//     mergesort(e,s,mid+1, high);
//     merge(e,s,low, mid, high);
//    }
// }
