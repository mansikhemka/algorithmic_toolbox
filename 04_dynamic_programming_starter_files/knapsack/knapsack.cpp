 #include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>

using std::vector;
using namespace std;

class Matrix{
  int cols;
  int rows;
public:
  int **value;
  Matrix(int rows, int cols){
    this->rows = rows;
    this->cols = cols;
    value = new int*[rows];
    for(int i=0;i<rows;i++)
      {value[i] = new int[cols];
          // memset(value[i], 0, cols*sizeof(int));
        }
  }
  void add(int row, int col, int val){
    value[row][col] = val;
  }
  int getVal(int row, int col){
    return value[row][col];
  }
};

int optimal_weight(int W, const vector<int> &w) {
  int current_weight = 0;
  for (size_t i = 0; i < w.size(); ++i) {
    if (current_weight + w[i] <= W) {
      current_weight += w[i];
    }
  }
  return current_weight;
}

int req_sol(int W, const vector<int> &w, int n){
   Matrix m(n+1,W+1);

  // int value[n+1][W+1];
  int val=0;

  for(int i=0;i<=W;i++)
    // value[0][i] = 0;
   m.add(0,i,0);



  for(int j=0;j<=n;j++)
    // value[j][0] = 0; 
     m.add(j,0,0);

  for(int i=1;i<=n;i++){
    for(int j=1;j<=W;j++){
      val=0;
      // value[i][j] = value[i-1][j];
      m.add(i,j,m.getVal(i-1,j));
      if(w[i-1]<=j)
        // val = value[i-1][j-w[i-1]]+w[i-1];
        val = m.getVal(i-1,j-w[i-1])+w[i-1];
      // if(value[i][j]<val)
      //   value[i][j]=val;
      if(m.getVal(i,j)<val)
        m.add(i,j,val);

    }
  }

  return m.getVal(n,W);
}

int main() {
  int n, W;
  std::cin >> W >> n;
  vector<int> w(n);
  for (int i = 0; i < n; i++) {
    std::cin >> w[i];
  }
  std::cout << req_sol(W, w, n) << '\n';
}
