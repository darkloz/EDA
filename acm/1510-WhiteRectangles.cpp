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

int main() {

	int n , N = 101;
	char buf;
	VV(bool) m( N ,V(bool)(N));
	VV(int) counting( N , V(int)(N) );

	while( scanf( "%d",  &n ) != EOF ){
		N = n+1 ;

		scanf("%*[^\n]") ; scanf("%*c");
		FOR( i , 1 , N ){
			FOR( j ,1  , N ){
				cread( buf );
				m[i][j] = (buf== '.')?true :false;
			}
			scanf("%*[^\n]") ; scanf("%*c");
		}

		FOR(i,1,N){
			FOR(j,1,N){
				counting[i][j] = counting[i][j-1]+ counting[i-1][j] -counting[i-1][j-1] + m[i][j];
			}
		}

		int count = 0;
		int sz , mnt;
		FOR( r1 , 1 , N ){
			FOR( c1 , 1 , N ){
				FOR( r2 , r1 , N ){
					FOR( c2,c1 , N ){
						mnt =  counting[r2][c2] +  counting[r1-1][c1-1] - counting[r1-1][c2] - counting[r2][c1-1];
						sz = (r2-r1+1)*(c2-c1+1);
						if( mnt == sz )
							++count;
						else{
							break;
						}
					}
				}
			}
		}

		printf( "%d\n" , count);

	}

	return 0;
}


//============================================================================
// Author      :  Carlos Eduardo Guillen Davila
//============================================================================
/*
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

int main() {

	int r , c , N = 101, R ,C;
	VV(bool) m( N ,V(bool)(N));
	VV(int) counting( N , V(int)(N) );

	while( scanf( "%d",  &r ) , r ){
		scanf( "%d",  &c );
		R = r+1 ;
		C = c+1;
		char buf ;
		scanf("%*[^\n]") ; scanf("%*c");
		FOR( i , 1 , R ){
			FOR( j ,1  , C ){
				cread( buf);
				m[i][j] = (buf== '1')?true :false;
			}
			scanf("%*[^\n]"); scanf("%*c");
		}

		FOR(i,1,R){
			FOR(j,1,C){
				counting[i][j] = counting[i][j-1]+ counting[i-1][j] -counting[i-1][j-1] + m[i][j];
			}
		}

		int count = 0;
		int sz , mnt;
		FOR( r1 , 1 , R ){
			FOR( c1 , 1 , C ){
				FOR( r2 , r1 , R ){
					FOR( c2,c1 , C ){
						mnt =  counting[r2][c2] +  counting[r1-1][c1-1] - counting[r1-1][c2] - counting[r2][c1-1];
						sz = (r2-r1+1)*(c2-c1+1);
						if( mnt == sz )
							++count;
					}
				}
			}
		}

		printf( "%d\n" , count);

	}

	return 0;
}*/

