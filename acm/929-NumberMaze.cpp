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
#define FOR(a,i,f) for( unsigned int a = i ; a < f ; ++a )
#define mp(a , b ) make_pair( a , b )
#define V(x) vector<x>
#define VV(x) vector< V(x) >
//const double PI = acos(-1);

using namespace std;

typedef unsigned int uint;

typedef pair<uint,uint> edge; // (w ,to)
typedef priority_queue< edge , deque<edge > , greater<edge> >  PQ;

int dijkstra( VV( edge )& g , uint s , uint end ){ // source , end

	uint d[ g.size() ];
	memset( d , 255 , sizeof(uint)*g.size() );
	d[s] = 0;

	PQ q;
	q.push( mp(s,0 ) );

	uint node , dist ;
	while( !q.empty() ){
		dist = q.top().first;
		node = q.top().second ;
		q.pop();

		if( node == end ) return dist;

		if( dist > d[node]  ) continue;

		d[node] = dist;

		uint n , ew;
		FOR( i , 0 , g[node].size()  ){
			n = g[node][i].second; ew = g[node][i].first;
			if(  d[n] > dist+ ew ){
				d[n] = dist + ew;
				q.push( mp( d[n] , n) );
			}

		}

	}
}


int main(){


	int n;
	int r , c;
	VV(uint) maze ( 1000, V(uint)(1000));
	for( cin >> n ; n ; --n ){

		cin >> r >> c;
		FOR(i ,0  , r)
			FOR(j ,0 ,c)
				cin >> maze[i][j]  ;


		VV( edge ) g( r*c );

		uint q = 0 , p ;
		FOR(i ,0 , r){
			FOR(j ,0 ,c ){
				if( i > 0 ){
					p = (i-1)*c+j;
					g[q].push_back( mp(maze[i-1][j] , p ) ) ;
				}
				if( i < r-1 ){
					p = (i+1)*c+j;
					g[q].push_back( mp(maze[i+1][j] ,p ) ) ;
				}
				if( j > 0 ){
					p = i*c+(j-1);
					g[q].push_back( mp(maze[i][j-1] ,p ) ) ;
				}
				if( j < c-1 ){
					p = i*c+(j+1);
					g[q].push_back( mp(maze[i][j+1] ,p ) ) ;
				}
				++q;
			}
		}

		--q;
		cout <<  dijkstra( g , 0 , q ) << endl;



	}


	return 0;
}
