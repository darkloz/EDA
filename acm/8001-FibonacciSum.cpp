//============================================================================
// Author      :  Carlos Eduardo Guillen Davila
//============================================================================

#include <iostream>
#include <cstdio>
#include <vector>
#include <list>
#include <set>
#include <bitset>
#include <map>
#include <stack>
#include <queue>
#include <iterator>
#include <algorithm>
#include <cmath>
#include <string>
#include <sstream>
#include <cstring>
#include <limits>
#include <cctype>
#define eps 1e-7
#define INF numeric_limits<double>::infinity
#define feq(a,b) fabs( a-b ) < eps
#define iread( a ) scanf("%d",&a)
#define lread( a ) scanf("%lld",&a)
#define fread( a ) scanf("%f",&a)
#define dread( a ) scanf("%lf",&a)
#define cread( a ) scanf("%c",&a)
#define all(c) c.begin() , c.end()
#define FOREACH(c,int) for(typeof((c).begin()) it=(c).begin();it!=(c).end();++it)
#define FOR(a,i,f) for( int a = i ; a < f ; ++a )
#define V(x) vector<x>
#define VV(x) V( V(x) )
//const double PI = acos(-1);


using namespace std;

const long long mod = 1000000007 ;

template< class T >
struct matrix {
	VV(T) m ;
	matrix( int f , int c, T v): m( f, V(T)(c,v) ){}
	matrix( int n ):m( n, V(T)(n) ){ // identidad
		for( int i = 0 ; i < n ; m[i][i] = 1 , ++i ) ;
	}

	int row(){ return m.size(); }
	int col(){ return m[0].size(); }

	matrix operator * ( matrix & b ){
		matrix temp( row() , b.col() , 0 );
		FOR( i,0, row() )
			FOR( j , 0 , b.col() ){
				FOR( k ,0  , col()  ){
					temp.m[i][j] += (m[i][k]*b.m[k][j])%mod ;
				}
				temp.m[i][j]%= mod;
			}
		return temp;
	}
};



matrix<long long> fibo ( 2 , 1 , 0);

long long fibonacci( int n ){ // n  <= 10^9

	matrix<long long> r(2);
	matrix<long long> b(2,2,1);
	b.m[1][1] = 0;


	for( int e = n-1 ; e  ; e >>= 1  ){
		if( e & 1 )
			r = r*b;
		b= b*b;
	}

	r = r*fibo;
	return r.m[0][0];
}

int main(){

	fibo.m[0][0] = 1;

	int t;
	int n , m;
	for( cin >> t ; t  ;  --t ){
		cin >> n >> m;
		long long aux = fibonacci(m+2) - fibonacci(n+1);
		cout << ((aux > 0 )? aux :(mod+aux)) << endl ;
	}


}
