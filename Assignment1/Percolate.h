#ifndef __PERCOLATE__
#define __PERCOLATE__

#include "UF.h"

class Percolate: public UF{
    int N;
    bool *isOpen;
  public:
    Percolate(int );
    ~Percolate();
  int Size();
  void Open(int , int);
  void Display();
};

#endif
