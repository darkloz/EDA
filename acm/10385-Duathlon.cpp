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
#define INF numeric_limits<double>::infinity()
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

struct recta{
	double m;
	double b;
	recta( double _m , double _b ):b(_b),m(_m){}

	double y( double x ){ return x*m + b; }
};

const double e = 0.001;
const bool op  = 1; // 1 maximo - 0 minimo

double ternarySearch( double (*f)(double)  , double l , double r ){ // e error

	if( r - l  < e )
		return (r+l)/2;

	double lt = ( 2*l + r )/3 ;
	double rt = ( l + 2*r )/3 ;

	if( ( f(lt) > f(rt) ) ^ op )
		return ternarySearch( f , lt , r  );
	return ternarySearch( f , l , rt );

}

vector<recta> v;

double f( double x ){
	int f = v.size()-1;
	double r  = INF ;
	for( int i = 0 ; i < f; ++i ){
		if(  v[i].y(x) < r )
			r = v[i].y(x);
	}
	return r-v[f].y(x);
}



int main() {

//	cout << ternarySearch( power2 , -100 , 100  ) << endl;

	double d ,  r , c ;
	int n;
	while( cin >> d ){
		cin >> n;
		for( int i = 0 ; i < n ; ++i  ){
			cin >> r >> c;
			v.push_back( recta( (c-r)/(c*r) , d/c ) );
		}

		double dx = ternarySearch( f , 0 ,d );
		double fx = f(dx);
		if( fx > -eps )
			printf("The cheater can win by %.0lf seconds with r = %.2lfkm and k = %.2lfkm.\n", (fabs(fx)*3600) , dx , d-dx );
		else
			puts("The cheater cannot win.");
		v.clear();
	}
	return 0;
}


/*
 10
 3
 3 1
 2 4
 3 2

 */

