//============================================================================
// Author      :  Carlos Eduardo Guillen Davila
// link		   :  http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=2913
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

typedef P(int,int) edge;
typedef VV( edge ) graph;


typedef priority_queue< edge > PQ ;

void dijkstra(  graph& gr ,  int s , V(int)& d ){

	d.assign( gr.size() , INFI );
	d[s] = 0 ;
	PQ heap;
	heap.push( mp( s ,0 ) );
	while( !heap.empty() ){
		int v = heap.top().first;
		int pw = heap.top().second ;
		heap.pop();

		if( d[v] < pw )
			continue;

		int fv , fw;
		FOR( i , 0 , gr[v].size() ){
			fv = gr[v][i].first; fw = gr[v][i].second;
			if( d[ fv ] > d[v] + fw ){
				d[ fv ] = d[v] + fw;
				heap.push( mp( fv , d[fv] ) ) ;
			}
		}


	}

}


inline
bool bit(  int n ,  int i  ){
	return n&( 1 << i );
}

inline
int sum( int a, int b ){
	if( a == INFI  || b == INFI  )
		return INFI;
	return a+b;
}
int minCycle( VV(int) d ){

	int sz = 1 << d.size();
	VV(int) dp ( sz, V(int)(d.size() , INFI) ) ;

	for(int i = 0 , j= 1 ; i < d.size() ; ++i , j <<=1 )
		dp[1|j][i] = d[0][i];

	for( int mask = 1 ; mask < sz ; mask+=2 ){
		for( int i  = 1 ; i < d.size() ; ++i ){
			if( bit( mask, i ) ){
				int prev = mask^(1 << i)  ; // remove i from the mask
				int min  = dp[mask][i];
				for( int j = 1 ;  j < d.size() ; ++j ){
					if( bit( prev , j ) ){
						if( min > sum( dp[prev][j] ,  d[j][i] ) )
							min = dp[prev][j] + d[j][i];
					}
				}
				dp[mask][i] = min;
			}
		}
	}

	int min = INFI ;
	for( int i = 1 ; i < d.size() ; ++i  ){
		if( min > sum( dp[sz-1][i] , d[i][0] )  )
			min = dp[sz-1][i] + d[i][0];
	}
	return min;
}


int main() {

	int t;

	for( cin >> t ;  t ; --t  ){

		int nv, ne ;
		cin >> nv >> ne;

		graph gr( nv );

		int u ,v , w;
		FOR( i , 0 , ne ){
			cin >> u >> v >> w;
			gr[u].push_back( mp( v , w ) );
			gr[v].push_back( mp( u , w ) );
		}

		int ns , s; cin >> ns;

		V(int) places( ns+1 );

		places[0] = 0;
		FOR(i ,1 , places.size() ){
			cin >> s;
			places[i] = s;
		}

		VV(int) mtr( places.size() , V(int)( places.size() ) ) ;
		V(int) distances;
		FOR(i , 0 , places.size() ){
			dijkstra( gr, places[i], distances );
			FOR(j ,0 , places.size() )
				mtr[i][j] = distances[ places[j] ] ;
		}
		/*
		FOR(i, 0 , places.size() ){
			FOR(j , 0 , places.size() ){
				cout << mtr[i][j] << " ";
			}
			puts("");
		}
		*/
		cout << minCycle( mtr ) << endl;
	}


	return 0;
}

/*
 1
4 6
0 1 1 1
4 6
0 1 1
1 2 1
2 3 1
3 0 1
0 2 5
1 3 5
3
1
2
3
1 2 1
2 3 1
3 0 1
0 2 5
1 3 5
3
1
2
3

*/

