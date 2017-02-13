#include <algorithm>
#include <iostream>
#include <vector>
#include <limits>
#include <iomanip>
#include <math.h>

using namespace std;

#define __DBL_MAX std::numeric_limits<double>::max()

struct Point
{
    int x, y;

    double dist(const Point b) const
    {
        return sqrt((x - b.x)*(x - b.x) +
                    (y - b.y)*(y - b.y));
    }
};

// typedef std::vector<Point> Points;

double closestDist(const Point v[], int n, double min = __DBL_MAX)
{
    // std::vector<Point>::iterator it1,it2;
    int it1,it2;
    for (it1 = 0; it1 <n ; ++it1)
        for (it2 = it1 + 1; it2 <n && abs(v[it2].y - v[it1].y) < min; ++it2)
            min = std::min(v[it1].dist(v[it2]), min);

    return min;
}

double bruteforce(const Point p[], int n){
double min= __DBL_MAX;
for(int i=0;i<n;i++)
  for(int j=i+1;j<n; j++)
    if(p[i].dist(p[j])<min)
      min = p[i].dist(p[j]);
return min;
}

int comparey(const Point a, const Point b) { return (a.y == b.y) ? (a.x < b.x) : (a.y < b.y); }

double closestDivAndConq(const Point px[],const Point py[], int n)
{
    if (n <= 3)
        return bruteforce(px,n);

    int mid = n / 2;

    Point pl[mid+1];
    Point pr[n-mid-1];
     int li=0; int ri=0;
Point midpoint = px[mid];

  for(int i=0;i<n;i++){
    if(py[i].x <= midpoint.x)
      pl[li++] = py[i];
    else
        pr[ri++] = py[i];  
  }

    double dl = closestDivAndConq(px,pl,mid);
    double dr = closestDivAndConq(px+mid,pr,n-mid);

    double d = std::min(dl, dr);

    Point strip[n];

    
    // std::vector<Point>::iterator p;
    // for (p : v)
    for (int p = 0;p <n; ++p)
        if (abs(midpoint.x - py[p].x) < d)
            strip[p]=py[p];

    

    return std::min(d, closestDist(strip,n, d));
}
 
int comparex(const Point a, const Point b) { return (a.x == b.x) ? (a.y < b.y) : (a.x < b.x); }
double closest(Point v[], int n)
{
    Point px[n];
  Point py[n];
  for(int i=0;i<n;i++){
    px[i] = v[i];
    py[i] = v[i];
  }
    std::sort(px, px+n, comparex);
    std::sort(py, py+n, comparey);
    // for(int i=0;i<n;i++)
    //     cout<<v[i].x<<" "<<v[i].y<<endl;

    return closestDivAndConq(px, py, n);
}

int main()
{
    int n;
    cin>>n;
    Point v[n];
    // Point v({ { 2, 3 },{ 12, 30 },{ 40, 50 },{ 5, 1 },{ 12, 10 },{ 3, 4 } });
    for(int i=0;i<n;i++)
        cin>>v[i].x>>v[i].y;
    if(n==1)
        cout<<0.0;
    else
   { 
    double ret = closest(v,n);
       if (ret == __DBL_MAX)
           return -1;
       std::cout << std::fixed;
       std::cout << std::setprecision(9) << ret << std::endl;}

    return 0;
}