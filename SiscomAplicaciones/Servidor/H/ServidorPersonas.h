#ifndef __SISCOMPERSONAS_H__
#define __SISCOMPERSONAS_H__
#include <SiscomDesarrollo2.h>

void SiscomNormalizaPersona(SArgsSiscom *);
/*
 * Esta funcion creara argumentos temporales 
 * es decir que solo se deberan emplear para
 * el manejo de las funciones para el registro
 * de personas
 * Al final se debera contar con una ultima 
 * funcion que regrese la informacion almacena
 * da en los argumentos, a una estructura 
 * que se debera definir ya en el contexto 
 * de la aplicacion en la que se emplee 
 * la funcionalidad de esta biblioteca.
 *
 */

/* 
 * Como convencion para la utilizacion de 
 * los argumentos de las funciones que aqui 
 * se desarrollen, se debera incluir como 
 * parte del nombre el prefijo SisXXXX
 * esto nos indicara que es un argumento 
 * dentro del contexto de las funciones
 * de soporte para las aplicaciones y
 * no de la aplicacion a desarrollar
 *
 */
void SiscomArgumentosPersona(SArgsSicom *);

void SiscomValidaNombre(SArgsSiscom *);
#endif
