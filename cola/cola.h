#include<tbb/tbb.h>
#include<tbb/spin_mutex.h>
#include<queue>
#include<iostream>
#include<stdio.h>
#include <unistd.h>

using namespace tbb;
using namespace std;

class Cola{
 public:
  Cola( int mx_sz  );
  int pop();
  void push( int v );
  int front();

  queue<int> cola;
  int mx_size ; 
  spin_mutex op_pop;
  spin_mutex op_push;
  //  spin_mutex empty; // lock : cola vacia
  // spin_mutex full;  // lock : cola llena 
};