/*
 * Array.h
 *
 *  Created on: 23/09/2011
 *      Author: carlos
 */

#define SZ 10000000L

#ifndef ARRAY_H_
#define ARRAY_H_

/**   \brief Clase sólo para testing
*/
class Array {
public:
	Array() {
		for (int i = 0; i < SZ; ++i)
			v[i] = 0;
	}
	virtual ~Array() {
	}
	int v[SZ];
};

#endif /* ARRAY_H_ */
