#include "cola.h"

Cola::Cola( int mx_sz  ):mx_size( mx_sz ){
  empty.lock();
}

int Cola::pop(){
  op_pop.lock();

  bool flg = true;
  while( cola.empty() ){
    if(flg){
      cout << "COLA VACIA- ESPERANDO POP" << endl;
      flg = false;
    }
  }
  int t = cola.front();
  cout << "pop : " << t << endl;
  cola.pop();
  /*empty.lock();
  int t = cola.front();
  cola.pop();
  cout << "pop : " << t << endl;
  if( !full.try_lock() )
    full.unlock();
  if( !cola.empty() )
    empty.unlock();
  else{
    if( empty.try_lock() )
      empty.lock();
    cout << "COLA VACIA" << endl;
    }
  */
  op_pop.unlock();
  return t;
}

void Cola::push( int v ){
  op_push.lock() ;
  bool flg = true;
  while( cola.size() ==  mx_size ){
    if(flg){
      cout << "COLA LLENA - ESPERANDO PUSH" << endl;
      flg = false;
    }
  }
  cola.push(v);
  cout << "push : " << v << endl;
/*
  full.lock();
  cola.push(v );
  cout << "push: " << v <<  endl;
  if( !empty.try_lock() ) 
    empty.unlock();
  if( cola.size() < mx_size ) 
    full.unlock();
  else{
    if( full.try_lock() )
      full.lock();
    cout << "COLA LLENA" << endl;
  }
*/
  op_push.unlock();
}

int Cola::front(){
  int t;
  op_pop.lock();
  bool flg = true;
  while( cola.empty() ){
    if(flg){
      cout << "COLA VACIA- ESPERANDO FRONT" << endl;
      flg = false;
    }
  }
  t =  cola.front();
  op_pop.unlock();
  return t;
}

