#include<iostream>
#include<float.h>
#include<stdlib.h>
#include<math.h>
#include <algorithm>
#include <sstream>
#include <vector>
#include <iomanip>
#include <string>
#include <cmath>

using namespace std;

struct point{
  long long x,y;
};

int comparex(const void* a, const void * b){
  point *p1=(point*)a; point *p2=(point*)b;
  return (p1->x-p2->x);
}

int comparey(const void* a, const void * b){
  point *p1=(point*)a; point *p2=(point*)b;
  return (p1->y-p2->y);
}

double dist(point p1, point p2){
  return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
}

double bruteforce(point p[], int n){
double min=DBL_MAX;
for(int i=0;i<n;i++)
  for(int j=i+1;j<n; j++)
    if(dist(p[i],p[j])<min)
      min = dist(p[i],p[j]);
return min;
}

double min(double x,double y){
  return (x<y)?x:y;
}

double stripClosest(point strip[], int j, double d){
  double mini = d;

  for(int i=0;i<j;i++)
    for(int k=i+1; k<j && strip[k].y-strip[i].y<min; k++)
      if(dist(strip[i],strip[k])<mini)
        mini = dist(strip[i], strip[k]);
      return mini;
}

double closeutil(point px[], point py[], int n){
  if(n<=3) return bruteforce(px, n);

  int mid = n/2;
  point midpoint = px[mid];

  point pyl[mid+1];
  point pyr[n-mid-1];
  int li=0; int ri=0;

  for(int i=0;i<n;i++){
    if(py[i].x <= midpoint.x)
      pyl[li++] = py[i];
    else
        pyr[ri++] = py[i];  
  }

  double d1 = closeutil(px, pyl, mid);
  double d2 = closeutil(px+mid, pyr, n-mid);

  double d = min(d1, d2);

  point strip[n];
  int j=0;

  for(int i=0;i<n;i++){
    if(abs(py[i].x-midpoint.x)<d)
      strip[j] = py[i], j++;
  }
  return min(d, stripClosest(strip, j, d));
}

double closest(point p[], int n){
  point px[n];
  point py[n];
  for(int i=0;i<n;i++){
    px[i] = p[i];
    py[i] = p[i];
  }
  qsort(px, n, sizeof(point), comparex);
  qsort(py, n, sizeof(point), comparey);
  // return -1;
  return closeutil(px, py, n);
}

int main(){
  int n;
    point p[n];
    for(int i=0;i<n;i++)
      cin>>p[i].x>>p[i].y;
    if(n==1)
      cout<<0;
    else
   { std::cout << std::fixed;
       std::cout << std::setprecision(9) << closest(p, n) << "\n";}
}



// #include <algorithm>
// #include <iostream>
// #include <sstream>
// #include <iomanip>
// #include <vector>
// #include <string>
// #include <cmath>

// using std::vector;
// using std::string;
// using std::pair;
// using std::min;


// double minimal_distance(vector<int> x, vector<int> y) {
//   //write your code here
//   return 0.;
// }

// int main() {
//   size_t n;
//   std::cin >> n;
//   vector<int> x(n);
//   vector<int> y(n);
//   for (size_t i = 0; i < n; i++) {
//     std::cin >> x[i] >> y[i];
//   }
//   std::cout << std::fixed;
//   std::cout << std::setprecision(9) << minimal_distance(x, y) << "\n";
// }
