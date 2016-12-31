// #include <iostream>
// #include <vector>

// using std::vector;

// double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
//   double value = 0.0;

//   // write your code here

//   return value;
// }

// int main() {
//   int n;
//   int capacity;
//   std::cin >> n >> capacity;
//   vector<int> values(n);
//   vector<int> weights(n);
//   for (int i = 0; i < n; i++) {
//     std::cin >> values[i] >> weights[i];
//   }

//   double optimal_value = get_optimal_value(capacity, weights, values);

//   std::cout.precision(10);
//   std::cout << optimal_value << std::endl;
//   return 0;
// }




// void merge(double k[], int v[], int w[], int low, int mid, int high){
//   int i,m,l,t2[high];
//   int t3[high];
//   double t1[high];
//   l=low;
//   i=low;
//   m=mid+1;

//   while((l<=mid)&&(m<=high)) { 
//     if(k[l]<=k[m]) {
//        t1[i] = k[l];
//        t2[i] = v[l];
//        t3[i] = w[l];
//        l++;
//     }
//     else{ 
//        t1[i] = k[m];
//        t2[i] = v[m];
//        t3[i] = w[m];
//        m++;
//     }
//     i++;
//   }
//   while(l<=mid){
//        t1[i] = k[l];
//        t2[i] = v[l];
//        t3[i] = w[l];
//        l++;
//        i++;
//   }
//   while(m<=high){
//        t1[i] = k[m];
//        t2[i] = v[m];
//        t3[i] = w[m];
//        m++;
//         i++;
//   }

//   for(int p=low;p<=high;p++){
//     k[p]=t1[p];
//     v[p]=t2[p];
//     // cout<<"hey"<<t3[p];
//     w[p]=t3[p];
//   }
// }

// void mergesort(double k[],int v[], int w[], int low, int high){
//    int mid;
//    if(low<high){
//     mid=(low+high)/2;
//     mergesort(k, v, w, low, mid);
//     mergesort(k, v, w, mid+1, high);
//     merge(k, v, w, low, mid, high);
//    }
// }
#include<algorithm>
#include<iostream>

using namespace std;

int main(){
  int n;
  double W;
  cin>>n>>W;

  double v[n];
  double w[n];
  double k[n];
  for(int i=0;i<n;i++){
    cin>>v[i]>>w[i];
    // cout<<w[i]<<endl;
    k[i]=(double)v[i]/(double)w[i];
    // cout<<k[i]<<endl;
  }
  double val=0;

  // int t2,t3;

  for(int i=0;i<n;i++){
    for(int j=i;j<n;j++){
      if(k[j]<k[i]){
        double temp1=k[i];
        k[i]=k[j];
        k[j]=temp1;

        double temp = v[i];
        v[i]=v[j];
        v[j]=temp;
        temp=w[i];
        w[i]=w[j];
        w[j]=temp;
      }
    }
  }
  for(int i=n-1;i>=0;i--){
    if(w[i]<W){
         val=val+v[i];
         W=W-w[i];
         
    }
    else{
      // cout<<W<<"W";
      val = val +(double)W*k[i];
      break;
    }
  
  }
cout.precision(10);
cout<<val<<endl;

}