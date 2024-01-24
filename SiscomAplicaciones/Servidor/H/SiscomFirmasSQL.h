#ifndef __SISCOMFIRMASSQL_H__
#define __SISCOMFIRMASSQL_H__
#include <SiscomDesarrollo2.h>


/*
 *
 * Se valida en la tabla de firmas si 
 * la firma que se pretende registrar 
 * ya ha sido usada
 *
 */


void SiscomFirmaYaRegistrada(SArgsSiscom *);


/* Registra en la tabla
 *
 * Usuarios
 *
 */
void SiscomRegistraUsuario(SArgsSiscom *);

/*
 *
 * Registra en Firma
 *
 */
void SiscomRegistraFirma(SArgsSiscom *);



#endif
