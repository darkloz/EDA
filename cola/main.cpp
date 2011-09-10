#include "cola.h"

int sz = 10; 
Cola x (sz);
void fpush(){

  for( int i = sz*5  ; true  ; --i  ){
    sleep(2);
    x.push(i);
  }

  puts( "TERMINARON LOS PUSHES" );

}

void fpop(){
  for( int i = sz*5  ; true  ; --i  ){
    sleep(2);
    x.pop();
  }
  puts( "TERMINARON LOS POPS" );
  
}

void ffront( ){
  for( int i = sz*10  ; true  ; --i  ){
    sleep(2);
    cout << "front : " <<  x.front() << endl;  
  }
  puts( "TERMINARON LOS FRONTS" );

}

void est(){
  int c = 0;
  while( c < 5){
    //    sleep();
    cout << "locked?:\n";
    cout << "op_pop : " << !x.op_pop.try_lock()  << endl;
    cout << "op_push : " << !x.op_push.try_lock()  << endl;
    cout << "empty : " << !x.empty.try_lock()  << endl;
    cout << "full : " << !x.full.try_lock()  << endl;
    ++c;
  }

}
int main(){
  /* spin_mutex m ; 
  m.lock();
  cout <<   m.try_lock() << endl;*/

  
  tbb_thread pop1( fpop );
  tbb_thread pop2( fpop );
  tbb_thread push1( fpush );
  tbb_thread push2( fpush );
  tbb_thread front( ffront );
  // tbb_thread estado( est  );
  pop1.join();
  pop2.join();
  push1.join();
  push2.join();
  //  front.join();
  //estado.join();
  
  return 0 ;
}
