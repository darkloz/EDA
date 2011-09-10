#include<iostream> 
#include<stdlib.h>
#include<vector>
#include<tbb/tbb.h>
#include <time.h>
#include<tbb/tick_count.h>

using namespace std;
using namespace tbb;

int fibo(int n){
    if( n < 2 ) return n;
    return fibo(n-1) + fibo(n-2);
}


class paralelo{
vector<int> * a   ;
public:
    void operator()(const blocked_range<size_t>&r) const{
        for( size_t i = r.begin() ; i!=r.end() ; ++i ){
            cout << (*a)[i] << endl;
            (*a)[i] = fibo( (*a)[i] );
        }
    }
    paralelo( vector<int>&  v ){
        a = &v;
    }
};


int main(){
    int sz = 10;
    vector<int> v(sz);
    for( int  i= 0 ; i < sz; ++i )
        v[i] =38;
    
    tick_count t1 = tick_count::now(); 
    for( int  i= 0 ; i < sz; ++i ){
        cout << v[i]<< endl;
        v[i] = fibo( v[i] );
    }


    //parallel_for( blocked_range<size_t>(0,sz), paralelo(v) );

    cout << ( tick_count::now() - t1 ).seconds() << endl;
    return 0;
}
