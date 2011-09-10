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

int main() {

	string* n = new string() ,* m  =new string();

	int t;

	for( cin >> t ; t  ; --t  ){
		cin >> *n >> *m;
		if( n->size() > m->size() )
			swap( m ,n );

		int carry = 0;
		for (int i = 0; i < n->size(); ++i) {
			(*m)[i] = ((*m)[i]-'0')+ ((*n)[i]-'0') +carry ;
			if( (*m)[i] > 9 ){
				(*m)[i] -= 10;
				carry = 1 ;
			}else
				carry = 0 ;
		}

		for( int i =  n->size() ; i < m->size() ;  ++i ){
			(*m)[i] = ((*m)[i]-'0')+carry ;
			if( (*m)[i] > 9 ){
				(*m)[i] -= 10;
				carry = 1 ;
			}else{
				carry = 0 ;
			}
		}


		int i  = 0;

		for(  ; (*m)[i] == 0;  ++i ) ;

		for( ; i < m->size() ; ++i ){
			cout << (int)(*m)[i];
		}
		if( carry )
			cout << carry;
		puts("");

	}

	return 0;
}


/*
 3
24 1
4358 754
305 794

5
999999999999 99999999999999999999999

4
24 1
1 24
23 4
4 23

 */


