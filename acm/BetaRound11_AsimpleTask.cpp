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
#define INFD numeric_limits<double>::infinity()
#define INFI numeric_limits<int>::max()
#define feq(a,b) fabs( a-b ) < eps
#define FOREACH(it,c) for(typeof((c).begin()) it=(c).begin();it!=(c).end();++it)
#define FOR(a,i,f) for( int a = i ; a < f ; ++a )
#define mp(a , b ) make_pair( a , b )
#define V(x) vector<x>
#define VV(x) vector< V(x) >
#define P( a, b ) pair<a,b>
typedef unsigned int uint;
//const double PI = acos(-1);


using namespace std;

inline
int first( int x ){
	return x&(~x+1);
}

inline
int pos_first( int x ){
	int i = x&(~x+1);
	int c = -1;
	while(i){
		++c;
		i >>= 1;
	}
	return c;
}

inline
int bit ( int i , int mask ){
	return ( 1 << i ) & mask;
}

inline
int remove( int i , int mask ){
	return (1 << i)^mask;
}

inline
int count( int mask ){
	int c = 0;
	while( mask ){
		++c;
		mask&=(mask-1);
	}
	return c;
}

long long solve( VV(int)& g ){

	int sz  = 1 << g.size() ;

	VV(long long) dp( sz , V(long long)( g.size() ) );



	for( int mask = 1 ;  mask < dp.size() ; ++mask){
		for( int  i = 0 ; i < g.size() ; ++i  ){
			int id = (1 << i) ;
			if( id  == bit( i, mask )   ){

				if(  count( mask ) == 1 )
						dp[mask][i] = 1;
				else{
					if( id != first(mask) ){
						int prev = remove( i , mask );
						for( int  j  = 0 ; j < g[i].size() ; ++j ){
							dp[mask][i]+= dp[prev][ g[i][j] ] ;
						}
					}
				}
			}

		}
	}

	long long rpta = 0;
	for( int mask = 1 ;  mask  < dp.size() ; ++mask  ){
		if( count(mask) >= 3 ){
			int  j = pos_first( mask );
			for( int i = 0 ; i < g.size() ; ++i  ){
				if( dp[mask][i] == 0 ) continue;
				for( int k = 0 ; k < g[i].size(); ++k  )
					if( g[i][k] == j )
						rpta += dp[mask][i];
			}
		}
	}

	return rpta/2;
}


int main() {


	int n , m;

	/*int a = 30 ;
	int b  = 8 ;
	cout << pos_first( 2 ) << endl;*/

	while( cin >> n >> m ){
		VV( int ) gr ( n ) ;

		int f, t;
		FOR( i ,0  , m){
			cin >> f >> t;
			gr[f-1].push_back( t-1 ) ;
			gr[t-1].push_back( f-1 ) ;
		}

		cout << solve( gr ) << endl;

	}

	return 0;
}

/*
 5 5
 1 2
 2 3
 3 4
 4 5
 5 1

 */
