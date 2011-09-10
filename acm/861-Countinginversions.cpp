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

int counter;

void mergeSort( V(int)& v, int i , int f ){ // [i-f]


	int sz = f-i+1;

	if( sz == 1 ) return ;

	int m  = (i+f)/2;

	mergeSort( v , i , m );	mergeSort(v, m+1 , f );

	V(int) aux( sz );

	for( int c = 0 , j = i , k = m+1  ; c < sz ; ++c){
		if( k > f || ( j <= m && v[j] <= v[k] ) )
			aux[c] = v[j++] ;
		else{
			counter += m-j+1; //swaps - inversiones

			aux[c] = v[k++] ;
		}
	}
	for( int j = 0 ; j < sz ; v[i++] = aux[j++] );
}


int update( V(int)& v , int p , int n  ){

	for( int  i = 0 ; i < p  ;)

}

int main(){

	int n ;
	cin >> n ;

	V(int) v(n);

	for( int i = 0 ; i< n ; cin>> v[i++] );

	counter  = 0 ;
	mergeSort( v, 0 , n-1 );

	cout << counter << endl;
	return 0;
}


