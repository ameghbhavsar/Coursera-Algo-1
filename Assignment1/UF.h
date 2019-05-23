#ifndef _UF_
#define _UF_

class UF{
    int *id;
    int *sz;
  public:
    UF(int);
    ~UF();
    void Union(int , int );
    bool Connected(int, int);
    int root(int);
    int count();
    void Display(int );
};

#endif
