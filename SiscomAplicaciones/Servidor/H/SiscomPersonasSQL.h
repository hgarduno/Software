#ifndef __SISCOMPERSONASSQL_H__
#define __SISCOMPERSONASSQL_H__
#include <SiscomDesarrollo2.h>


/*! \file SiscomPersonasSQL.h
 * \brief SISCOM Electronica 2009 
 * Para poder utilizar la funciones de este archivo, se debera
 * enlazar la biblioteca libSiscomAplicacionesSvr.so,que se encuentra
 * en el directorio $DIRLIBSISCOM2.
 *
 * Ademas sera necesario considerar que la base de datos debera contener
 * las siguientes tablas:
 *
 * Personas 
 *
 * Con los siguientes campos:		
 * IdPersona
 * Nombre
 * APaterno
 * AMaterno
 *
 * PersonaNormalizada 
 * Con los siguientes campos:
 * IdPersona
 * Nombre
 * APaterno
 * AMaterno
 *
 *
 * SiscomRegistraPersona 
 *
 * Crea la sentencia SQL para la insercion en 
 * la tabla de personas 
 *
 */
void SiscomRegistraPersona(SArgsSiscom *);
void SiscomRegistraPersonaEnNormalizados(SArgsSiscom *);
void SiscomActualizaPersona(SArgsSiscom *pSAgsSiscom);
void SiscomActualizaPersonaNormalizada(SArgsSiscom *pSAgsSiscom);

void SQLSiscomBuscaNombreCompleto(SArgsSiscom *);
void SQLSiscomBuscaTodosNombreAPaterno(SArgsSiscom *);
void SQLSiscomBuscaTodosAPaterno(SArgsSiscom *);






#endif
