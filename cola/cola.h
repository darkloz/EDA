#include<tbb/tbb.h>
#include<tbb/spin_mutex.h>
#include<queue>
#include<iostream>
#include<stdio.h>
#include <unistd.h>

using namespace tbb;
using namespace std;

/**   \brief Cola concurrente
*
*Esta cola ha sido desarrollada para poder soportar concurrencia
*es decir muchas threads pueden acceder a ella simultaneamente
* y realizar las operaciones de insercion borrado y consulta.
*
* Se utiliza como base la cola de la stl.
*/
class Cola{
 public:
  /** \brief Constructor
   *
   * \param mx_sz Representa el tamaño máximo que tendrá la cola
   *
   *Se inicializa la cola vacía. 
   */
  Cola( int mx_sz  );
  /** \brief Borrado
   *
   * Elima el ultimo elemento ingresado
   */
  int pop();

  /** \brief Inserción
   *
   * Inserta el elemento al final de la cola
   * \param v Elemento a ser insertado
   */

  void push( int v );

  /** \brief Consulta
   *
   * Extrae el primer elemento en la cola
   */
  int front();

 private:

  /** Cola STL empleada como contenedor */
  queue<int> cola; 
  /** Contine el tamaño máximo que la pila podrá usar */
  int mx_size ;
  /**Mutex que permite
   * bloquar las operaciones de borrado
   * de modo que solo una operacion de borrado
   * sea realizada en simultaneo
   */
  spin_mutex op_pop;
  /**Mutex que permite 
   * bloquar las operaciones de insercion
   * de modo que solo una operacion de insercion
   * sea realizada en simultaneo
   */
  spin_mutex op_push;
};
