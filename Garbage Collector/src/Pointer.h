/*
 * Ptr.h
 *
 *  Created on: 23/09/2011
 *      Author: carlos
 */

#ifndef Ptr_H_
#define Ptr_H_

#include <map>
#include <iterator>
#include <exception>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <fstream>
using namespace std;

void handler(int x) {
	throw 1;
}

/**   \brief Smart Pointer
*
* Esta clase encapsula el comportamiento de un
* puntero cualquiera con ello no hay que preocuparse
* de liberar memoria ya que inteligentemente este
* objeto se encarga de realizarlo por el cliente y
* de forma muy eficiente, por ello el cliente puede
* obviar las cuestiones de complejidad extra del programa.
* Es importante tener en cuenta que si se enplea esta libreria
* no se haga uso de punteros nativos de c++ para evitar comportamientos
* indeseados.
*/
template<class T>
class Ptr {
public:
	Ptr();
	/**   \brief Constructor
	*	\param ptr El puntero el cual va a ser encapsulado por la clase
	*	Podría tenerse asignaciones del tipo Ptr<T> p( new T() );
	*/
	Ptr(T* ptr);
	/**   \brief Constructor con puntero
	*	\param ptr El puntero el cual va a ser encapsulado por la clase
	*	Podría tenerse asignaciones del tipo Ptr<T> p = new T();
	*/
	T* operator =(T* ptr);
	/**   \brief Asignacion puntero
	*	\param ptr Es el objeto cuya referencia será copiada en el objeto de asignacion
	*/
	Ptr& operator =(Ptr& ptr);
	/**
	*	\param i Posicion del elemento de un array al que se desea acceder
	*	Retorna el i-ésimo elemento de un arreglo en caso se trate de un puntero
	*	que referencia a un array
	*/
	T& operator[](unsigned int i);
	/**
		*	Retorna el objeto al que hace referencia
	*/
	T& operator*();
	/**
		*	Accede a los metodos del objeto referenciado
	*/
	T* operator->();
	/**  Referencia a variable
		*	Permite realizar las referencias a objetos, del mismo modo que lo haria
		*	un puntero nativo al asignarle un valor de la forma: &variable
	*/
	void referece( T& a);
	~Ptr();
private:
	void set(T* nw, bool is_ref);
	void remove_ptr();
	void delete_array();
	void delete_one();
	T* pointer;
	bool ref;
	static map<T*, int> count;

};

//////////////////////////////////////////////////////////////


template<class T>
map<T*, int> Ptr<T>::count;

template<class T>
Ptr<T>::Ptr() :
	pointer(NULL), ref(false) {
}

template<class T>
Ptr<T>::Ptr(T* ptr):pointer(ptr){
	++count[pointer];
}

template<class T>
void Ptr<T>::set(T* nw, bool is_ref) {
	if (!ref)
		remove_ptr();
	pointer = nw;
	if (!is_ref)
		++count[pointer];

	ref = is_ref;
}

template<class T>
void Ptr<T>::referece(T& a) {
	set(&a, true);
}

template<class T>
void Ptr<T>::delete_array() {
	delete[] pointer;
}

template<class T>
void Ptr<T>::delete_one() {
	delete pointer;
}

template<class T>
void Ptr<T>::remove_ptr() {
	if( pointer != NULL && !ref ){
		typename map<T*, int>::iterator it = count.find(pointer);
		if (it->second == 1 ) {
			signal( SIGSEGV, handler );
			try {
				delete_array();
			} catch (int ) {
				try {
					delete_one();
				} catch (int ) {
					cerr << "Fallo en manejo de memoria" << endl;
				}
			}
			count.erase( it );
		} else
			--it->second;
	}
}

template<class T>
T* Ptr<T>::operator =(T* ptr) {
	set(ptr, false);
	return pointer;

}

template<class T>
T& Ptr<T>::operator[](unsigned int i) {
	return pointer[i];
}

template<class T>
Ptr<T>& Ptr<T>::operator =(Ptr& ptr) {
	set(ptr.pointer, false);
	return ptr;
}

template<class T>
T* Ptr<T>::operator->() {
	return pointer;
}

template<class T>
T& Ptr<T>::operator*() {
	return *pointer;
}

template<class T>
Ptr<T>::~Ptr() {
	remove_ptr();
}

#endif /* Ptr_H_ */
