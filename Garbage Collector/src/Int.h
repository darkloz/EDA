/*
 * Int.h
 *
 *  Created on: 23/09/2011
 *      Author: carlos
 */

#ifndef INT_H_
#define INT_H_

#include <iostream>
using namespace std;
/**   \brief Clase sólo para testing
*/
class Int {
public:
	Int( int a):v(a){
	}
	virtual ~Int(){
	}
	void print(){
		cout << v << endl;
	}
private:
	int v;
};

#endif /* INT_H_ */
