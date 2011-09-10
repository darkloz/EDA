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

void generatePrimes(  int max , V(int)& primes ){

	V(bool) isprime( max +1 , true ) ;

	for( int i = 2, M = sqrt(max) ; i <= M  ;   ++i ){
		if( isprime[i ] ){
			for (int j = i*i; j < max ; j+= i )
				isprime[j] = false;
		}
	}
	for( int i = 2 ; i < isprime.size( ) ; ++i )
		if( isprime[i] )
			primes.push_back( i );
}

int main() {


	int MAX = 52*20;
	V(int) primes;
	generatePrimes(  MAX , primes );

	string buff;

	while( cin >> buff ){
		int n = 0;
		FOR(i , 0 , buff.size() ){
			if( isupper(buff[i] ) ){
				n+= 27 + buff[i]-'A';
			}else{
				n+= 1 + buff[i]-'a';
			}
		}
		bool f = false;
		for( int i = 0  , M = sqrt(n); primes[i] <= M ; ++i  ){
			if( n%primes[i] == 0 ){
				puts("It is not a prime word.");
				f = true;
				break;
			}
		}

		if( !f )
			puts("It is a prime word.");

	}

	return 0;
}
