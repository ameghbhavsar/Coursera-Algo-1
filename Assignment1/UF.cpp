#include "UF.h"
#include <iostream>

using namespace std;

UF::UF(int N){
  id = new int[N];
  sz = new int[N];
  for(int i=0; i<N; i++){
    id[i] = i;
    sz[i] = 1;
  }
}

UF::~UF(){
  delete id;
  delete sz;
}

void UF::Union(int p, int q){
  int pid = root(p);
  int qid = root(q);
  if(pid==qid) return;
  if(sz[pid]<sz[qid]){
    id[pid] = qid;
    sz[qid] += sz[pid];
  }
  else{
    id[qid] = pid;
    sz[pid] += sz[qid];
  }
}

bool UF::Connected(int p, int q){
  return root(p)==root(q);
}

int UF::root(int i){
  while(id[i]!=i)
    i = id[i];
  return id[i];
}

void UF::Display(int N){
    for(int i = 1; i<=N; i++){
      for(int j = 1; j<=N; j++){
        cout<<id[(i-1)*N+j]<<"  ";
      }
      cout<<endl;
    }
}
