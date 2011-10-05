//============================================================================
// Name        : Garbage.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstdio>
#include <unistd.h>
#include "Pointer.h"
#include "Array.h"
#include "Int.h"
#define pass puts("paso");
using namespace std;

#define MAX 10000000L


void f1() {
	puts("----funcion----");
	Ptr<int> v;
	v = new int[MAX];
	for (int i = 0; i < MAX; ++i)
		v[i] = 0;
	puts("memoria seteada");
	sleep(5);

}

void f2( Ptr<int> & r) {
	puts("----funcion----");
	Ptr<int> v;
	v = new int[MAX];
	r = v;
	for (int i = 0; i < MAX; ++i)
		v[i] = 0;
	puts("memoria seteada");
	sleep(5);
}

void f3() {
	puts("----funcion----");
	Ptr<int> v;
	v = new int;
	*v = 123;
	puts("memoria seteada");
	//sleep(5);

}

void f4( Ptr<int> & r) {
	puts("----funcion----");
	Ptr<int> v;
	v = new int;
	r = v;
	*v = 123;
	puts("memoria seteada");
	//sleep(5);
}

void f5() {
	puts("----funcion----");
	Ptr<Array> v;
	v = new Array();
	puts("memoria seteada");
	sleep(5);

}

void f6( int& a ){
	Ptr<int> p;
	p.referece( a );
	cout << *p << endl;
}

int main() {


	puts("------inicia-----");

	/*
	Ptr<Int> p ;
	p = new Int(3);
	p->print();
	*/

	Ptr<int> p  ;

	//f1();

	//f2( p );

	//f3();

	//f4(p);

	//f5();

	//cout << *p << endl;


	int x = 5;
	f6(x);
	cout << x << endl;

	puts("-------main------");

	sleep(5);

	puts("-----termino-----");

	return 0;
}
