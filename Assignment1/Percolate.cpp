#include <iostream>
#include "UF.h"
#include "Percolate.h"

using namespace std;

Percolate::Percolate(int N): UF(N*N+2){
  this->N = N;
  isOpen = new bool[N*N+2];
  for(int i=1; i<=N*N; i++){
    isOpen[i] = 0;
  }
  isOpen[0] = 1;
  isOpen[N*N+1] = 1;
  for(int i = 1; i<=N; i++){
    Union(0, i);
    Union(N*N+1, N*N-i+1);
  }
}

Percolate::~Percolate(){
  delete isOpen;
}

void Percolate::Open(int i, int j){
  int p = (i-1)*N+j, q, a ,b;
  if(isOpen[p]) return;
  int index[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
  isOpen[p] = 1;
  for(int m = 0; m<4; m++){
    a = i+index[m][0];
    b = j+index[m][1];
    if(!(a<=0 || b<=0 || a>N || b>N)){
      q = (a-1)*N + b;
      if(isOpen[q]) Union(p, q);
    }
  }
}

void Percolate::Display(){
  for(int i = 1; i<=N; i++){
    for(int j = 1; j<=N; j++){
      cout<<isOpen[(i-1)*N+j]<<"  ";
    }
    cout<<endl;
  }
  cout<<endl;
  UF::Display(N);
}
