#include<iostream>
#include<float.h>
#include<stdlib.h>
#include<math.h>

using namespace std;

struct point{
	long long x,y;
};

long long comparex(const void* a,const void* b){
	point *p1=(point*)a, *p2=(point*)b;
	return (p1->x-p2->x);
}

long long comparey(const void * a, const void* b){
	point *p1=(point*)a; point *p2=(point*)p2;
	return (p1->y-p2->y);
}

float dist(point p1, point p2){
	return sqrt((p1.x-p2.x)(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
}

float bruteforce(point p[], int n){
float min=FLT_MAX;
for(int i=0;i<n;i++)
	for(int j=i+1;j<n; j++)
		if(dist(p[i],p[j])<min)
			min = dist(p[i],p[j]);
return min;
}

float min(float x,float y){
	return min(x<y)?x:y;
}

float stripClosest(point strip[], int j, float d){
	float min = d;

	for(int i=0;i<j;i++)
		for(int k=i+1; k<j && strip[k].y-strip[i].y<min; k++)
			if(dist(strip[i],strip[k])<min)
				min = dist(strip[i], strip[k]);
			return min;
}

float closeutil(point px[], point py[], int n){
	if(n<=3) return bruteforce(px, n);

	int mid = n/2;
	point midpoint = px[mid];

	point pyl[mid+1];
	point pyr[n-mid-1];
	int li=0; int ri=0;

	for(int i=0;i<n;i++){
		if(py[i].y <= midpoint.y)
			pyl[li++] = py[i];
		else
		    py[ri++] = py[i];	 
	}

	float d1 = closeutil(px, pyl, mid);
	float d2 = closeutil(px+mid, pyr, n-mid);

	float d = min(d1, d2);

	point strip[n];
	int j=0;

	for(int i=0;i<n;i++){
		if(abs(py[i].x-midpoint.x)<d)
			strip[j] = py[i], j++;
	}
	return min(d, stripClosest(strip, j, d));
}

float closest(point p[], int n){
	point px[n];
	point py[n];
	for(int i=0;i<n;i++){
		px[i] = p[i];
		py[i] = p[i];
	}
	qsort(px, n, sizeof(point), comparex);
	qsort(py, n, sizeof(point), comparey);

	return closeutil(px, py, n);
}

int main(){
	int n;
    point p[n];
    for(int i=0;i<n;i++)
    	cin>>p[i].x>>p[i].y;
}