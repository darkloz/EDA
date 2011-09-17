//============================================================================
// Author      :  Carlos Eduardo Guillen Davila
//============================================================================
#define HOME
//#define IOFILE

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

#define ALL(c) c.begin(),c.end()
#define SZ(c) (int)c.size()
#define FOREACH(it,c) for(typeof((c).begin()) it=(c).begin();it!=(c).end();++it)
#define FOR(a,i,f) for( int a = i ; a < f ; ++a )
#define FORV(i,v) for( int i = 0 ; i < SZ(v) ; ++i  )
#define mp(a , b ) make_pair( a , b )

#define INFD numeric_limits<double>::infinity()
#define INFI numeric_limits<int>::max()
#define feq(a,b) fabs( a-b ) < eps
#define sqr(x) ((x)*(x))
#define eps 1e-7

#ifdef HOME
	#include <ctime>
	#define debug(x) cout<<#x<<" = "<<x<<endl;
	#define adebug(a,n) cout<<#a<<endl;  FOR(i,0,n) cout<<"["<<i<<"] = "<<a[i]<<endl;
	#define adebug2d(a,n,m) cout<<#a<<endl; FOR(i,0,n) { FOR(j,0,m) { cout<<a[i][j]<<" ";} cout<<endl;}
	#define vdebug(v) cout<<#v << endl; FORV(i,v){ cout<<"["<<i<<"] = " <<v[i]<<endl;}
	#define pass puts("PASO");
#endif

#define V(x) vector<x>
#define VV(x) vector< V(x) >
#define P(a,b) pair<a,b>

using namespace std;

typedef unsigned int uint;
//typedef P(int,int) edge;
//typedef VV( edge ) graph;

int main() {

	#ifdef IOFILE
	freopen (".in", "r", stdin);
	freopen (".out", "w", stdout);
	#endif

	int max ='z'+1;
	int l1[max];
	int l2[max];

	string b1 ,b2;
	while( getline( cin , b1 )  ){
		getline( cin , b2 );
		memset(  l1 , 0 , sizeof( l1 ) );
		memset(  l2 , 0 , sizeof( l2 ) );

		FORV(i,b1)
			++l1[ b1[i] ];
		FORV(i,b2)
			++l2[ b2[i] ];

		FOR( i , 'a' ,  max ){
			int r = min( l1[i], l2[i] );
			FOR(j,0,r)
				printf("%c",i);
		}
		puts("");
	}


	#ifdef HOME
		fprintf(stderr , "Execution time %.4f s\n" , float(clock())/CLOCKS_PER_SEC );
	#endif
	return 0;
}

/*
pretty
women
walking
down
the
street

thelineabovethisoneisblank
elementary
weatherreport

 */
