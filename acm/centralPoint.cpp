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
#define IINF numeric_limits<int>::max()
#define DINF numeric_limits<double>::infinity()
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
#define P(a,b) pair<a,b>
#define mp( a ,b ) make_pair(a,b)
//const double PI = acos(-1);


using namespace std;

V( P(double,double) ) points ;
double Mx, My , mx ,my;

double dist( double x , double y ){
	double d = 0.;
	FOR( i , 0 , points.size() )
		d += sqrt( (points[i].first-x)*(points[i].first-x) + (points[i].second-y)*(points[i].second-y) );
	return  d;
}


double linearSearch( double px1 , double px2 , double y){
	if( px2-px1 < 0.01 ) return (px1+px2)/2;

	double lx= ( px1*2.+px2 )/3.;
	double rx= (px1+px2*2.)/3. ;

	if( dist(lx , y) > dist(rx,y)  )
		return  linearSearch( lx , px2 ,y ) ;
	return linearSearch( px1 , rx ,y);
}

P(double,double) planarSearch( double py1 , double py2 ){ // minimun
	if( py2  - py1 < 0.01 ) return mp( linearSearch( mx , Mx , (py1+py2)/2. ) , (py1+py2)/2. );

	double ly = ( py1*2. +py2)/3. ;
	double ry = ( py1 +py2*2.)/3. ;

	double lx = linearSearch(mx , Mx,ly ) , rx = linearSearch(mx , Mx,ry );

	if( dist( lx , ly) > dist(rx , ry )  )
		return planarSearch( ly , py2 );
	return planarSearch( py1 , ry );
}

int main(){

	int n ;
	for(cin >> n ; n ; cin >> n){
		points.assign( n , mp(0.,0.) );

		mx= my = DINF ; Mx = My = -DINF;
		for( int i = 0 ; i < n ; ++i){
			cin >> points[i].first >> points[i].second ;
			if( Mx < points[i].first ) Mx = points[i].first;
			if( mx > points[i].first ) mx = points[i].first;
			if( My < points[i].second ) My = points[i].second;
			if( my > points[i].second ) my = points[i].second;

		}

		P(double,double) rpta =  planarSearch( my ,My ) ;

		int ix = floor(rpta.first) , iy = floor(rpta.second), px = ix , py =iy;
		double rD = dist( px ,py ) , D;
		D = dist( ix+1,iy );
		if( D < rD ){ px = ix+1 ; py= iy ; rD = D; }
		D = dist( ix,iy+1);
		if( D < rD ){ px = ix ; py= iy+1 ; rD = D; }
		D = dist( ix+1,iy+1 );
		if( D < rD ){ px = ix+1;py= iy+1 ; rD = D; }


		printf("%.6lf\n" , rD );
	}

}

/*
3
1 1
2 2
3 3
5
1 4
2 3
5 2
3 5
4 1
0

 */
