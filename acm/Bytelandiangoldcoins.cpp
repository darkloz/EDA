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
#define FOREACH(it,c) for(typeof((c).begin()) it=(c).begin();it!=(c).end();++it)
#define FOR(a,i,f) for( int a = i ; a < f ; ++a )
#define V(x) vector<x>
#define VV(x) vector< V(x) >
//const double PI = acos(-1);

using namespace std;


map<int,int> dp ;

long long sol( long long n ){

	if( n == 0 ) return 0;

	long long  r  = dp[n];

	if( r == 0 ){
		r = max( n , sol(n/2) + sol(n/3) + sol(n/4) );
		dp[n] = r;
	}
	return r;
}
using namespace std;

int main(){
	long long n;
	while( cin >> n ){
		cout << sol(n) << endl;
	}

}

//  1000000000
