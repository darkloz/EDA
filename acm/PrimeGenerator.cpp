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
// O( nlogn(loglogn) )
void generatePrimes( int max  , deque<int>& primes){

	V(bool) v(max+1,true);
	v[0] = v[1] = false;
	for( int i = 2 , m =  sqrt(max);  i <= m; ++i ){
		if( v[i] ){
			for( int j = i*i ;j <= max ; j+=i )
				v[j] = false;
		}
	}
	for( int i = 0 ; i <= max ;  ++i ){
		if( v[i] ) primes.push_back(i);
	}

}

int main(){

	int max = 1000000000;
	deque<int> primes;
	generatePrimes( sqrt(max) , primes );

	int t ;
	int n , m;

	bool flg = false;
	for( cin >> t ; t ;  --t ){
		if( flg ) puts("");
		else flg = true;
		cin >> n  >> m ;
		V(bool) isprime (m-n+1, true);
		if( n == 1 ) isprime[0] = false;
		for( int i = 0 , lim = sqrt(m) ;  i < primes.size() && primes[i] <= lim  ; ++i ){
		//	cout << primes[i] << endl;
			int j;
			if( n <= primes[i] )
				j = 2*primes[i]-n;
			else{
				j = n%primes[i];
				if( j !=0 ) j = primes[i]-j;
			}

			for( ; j < isprime.size() ; j+=primes[i] ){
				isprime[j] = false;
			}
		}

		for( int i  = 0 ;  i< isprime.size() ;  ++i ){
			if( isprime[i] )
				cout << n+i << endl;
		}

	}


	return 0;
}


/*
1
999900000 1000000000

 */

