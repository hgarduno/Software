#ifndef __SISCOMFIRMAS_H__
#define __SISCOMFIRMAS_H__
#include <SiscomDesarrollo2.h>
/*
 *
 * Para utilizar las funciones de este modulo
 * se requiere que en el Campo LCSiscomPro2Dat
 * de la estructura de argumentos contenga los
 * siguiente campos
 *
 * Firma
 * Password
 * RePassword
 * IdPerfil
 * IdAplicacion
 * IdPersona
 *
 */
/*
 * Se encarga de revisar si el campo Password
 * y el campo RePassword son iguales
 *
 * Si no son iguales se genera el codigo de
 * retorno 3
 *
 */
void SiscomVerificaPassword(SArgsSiscom *);

/* Verifica que la informacion en los campos
 * del password no sea vacio
 *
 */
void SiscomPasswordVacio(SArgsSiscom *);

#endif
