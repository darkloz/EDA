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
	#define dbg(x) cout<<#x<<" = "<<x<<endl;
	#define adbg(a,n) cout<<#a<<endl;  FOR(i,0,n) cout<<"["<<i<<"] = "<<a[i]<<endl;
	#define adbg2d(a,n,m) cout<<#a<<endl; FOR(i,0,n) { FOR(j,0,m) { cout<<a[i][j]<<" ";} cout<<endl;}
	#define vdbg(v) cout<<#v << endl; FORV(i,v){ cout<<"["<<i<<"] = " <<v[i]<<endl;}
	#define pass puts("PASO");
#endif

#define V(x) vector<x>
#define VV(x) vector< V(x) >
#define P(a,b) pair<a,b>

using namespace std;

typedef unsigned int uint;
//typedef P(int,int) edge;
//typedef VV( edge ) graph;

bool f( const  P(int,char)&  a, const P(int,char)& b){
	if( a.first < b.first )
		return true;
	if( a.first > b.first )
		return false;
	return a.second > b.second;
}

int main() {

	#ifdef IOFILE
	freopen (".in", "r", stdin);
	freopen (".out", "w", stdout);
	#endif

	string buff;
	bool fl = false;
	while( getline( cin , buff) ){
		map<int,int> dic;
		if( fl ) puts("");
		else	fl = true;

		FORV(i, buff ){
			++dic[buff[i]] ;
		}


		V( P( int,char) )  rpta ( dic.size() );

		int i = 0;
		FOREACH(it , dic){
			rpta[i].second  = it->first;rpta[i].first = it->second;
			++i;
		}

		sort( ALL(rpta) , f );

		FORV( i , rpta ){
			cout << (int)rpta[i].second << " " << rpta[i].first  << endl;
		}
	}

	#ifdef HOME
		fprintf(stderr , "Execution time %.4f s\n" , float(clock())/CLOCKS_PER_SEC );
	#endif
	return 0;
}
