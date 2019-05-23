#include <iostream>
#include <fstream>
#include <boost/program_options.hpp>
#include "Percolate.h"

using namespace std;

int Percolate::Size(){
  return N;
}

int main(int argc,char **argv){

  if(argc!=2){
    cout << "Usage: ./UF input_file" << '\n';
    exit(1);
  }

  int N, p = 1 ,q = 1;
  fstream F;
  F.open(argv[1]);
  if(!F){
    cout<<"Unable to open file\n";
    exit(1);
  }

  F>>N;
  Percolate P(N);

  while(F>>p>>q){
    if(p==-1 || q==-1) break;
    if(p>N or q>N){
      cout<<"Input(s) out of range. Try again!"<<endl;
      continue;
    }
    P.Open(p,q);
  }
  // cout<<"Grid:\n";
  // P.Display();
  cout<<(P.Connected(0,N*N+1)?"Connected":"Not Connected")<<endl;
  return 0;
}
