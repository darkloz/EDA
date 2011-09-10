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
#include <climits>
#include <cctype>
#define eps 1e-7
#define feq(a,b) fabs( a-b ) < eps
#define iread( a ) scanf("%d",&a)
#define lread( a ) scanf("%lld",&a)
#define fread( a ) scanf("%f",&a)
#define dbread( a ) scanf("%lf",&a)
#define cread( a ) scanf("%c",&a)
#define FOREACH(it,c) for(typeof((c).begin()) it=(c).begin();it!=(c).end();++it)
#define FOR(a,i,f) for( int a = i ; a < f ; ++a )
#define V(x) vector<x>
#define VV(x) vector< V(x) >
//const double PI = acos(-1);


using namespace std;

bool equal(vector<string>& m1 ,  vector<string>& m2 ){

	FOR(i,0,m1.size())
		FOR( j, 0, m1.size() )
			if( m1[i][j] != m2[i][j] )
				return false;
	return true;
}
void rotate(  vector<string>& m ){
	vector<string> mt(m);
	for (int i = 0, c = m.size()-1; i < m.size(); ++i , --c ) {
		for (int j = 0 , r = 0; j < m.size(); ++j, ++r) {
				m[r][c] = mt[i][j];
		}
	}
}

void reflection(  vector<string>& m ){
	for(int i = 0 , d  = m.size()-1 ;  i  < d ;  ++i,--d )
		swap( m[i] , m[d] );
}

int main()
{
    /*.................. INPUT ..........................*/
    int  n;
    while( cin >> n , n ) {
        vector<string> m1( n ) ;
        vector<string> m2( n) ;
        for( int i = 0; i < n ;  ++i ){
            cin >> m1[i];
            cin >> m2[i];
        }

        /*.................. SOLVE ..........................*/


        if( equal(m1, m2) ){
        	puts("Preserved"); continue;
        }
        rotate( m1 );
        if( equal(m1, m2)  ){
        	puts("Rotated through 90 degrees"); continue;
        }
        rotate( m1 );
        if( equal(m1, m2) ){
        	puts("Rotated through 180 degrees"); continue;
        }
        rotate( m1 );
        if( equal(m1, m2) ){
              puts("Rotated through 270 degrees"); continue;
        }
        rotate( m1 );

        reflection(m1);

        if( equal(m1, m2) ){
			puts("Reflected"); continue;
		}
		rotate( m1 );
		if( equal(m1, m2)  ){
			puts("Reflected and rotated through 90 degrees"); continue;
		}
		rotate( m1 );
		if( equal(m1, m2) ){
			puts("Reflected and rotated through 180 degrees"); continue;
		}
		rotate( m1 );
		if( equal(m1, m2) ){
			  puts("Reflected and rotated through 270 degrees"); continue;
		}
		puts("Improper");
    }



    return 0;
}



