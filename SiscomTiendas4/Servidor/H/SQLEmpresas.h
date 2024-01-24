#ifndef __SQLEMPRESAS_H__
#define __SQLEMPRESAS_H__
#include <SiscomDesarrollo2.h>

void SQLConsultaEmpresaNormalizada(SArgsSiscom *);
void SQLEmpresasSimilares(SArgsSiscom *);
void SQLRegistraEmpresa(SArgsSiscom *);
void SQLRegistraEmpresaNormalizada(SArgsSiscom *);
void SQLRegistraContactoEnPersonas(SArgsSiscom *);
void SQLRegistraContactoEnNormalizadas(SArgsSiscom *);
void SQLRegistraContactoEnContactos(SArgsSiscom *);
void SQLRegistraEnClientes(SArgsSiscom *);
void SQLRegistraEnProveedores(SArgsSiscom *);
void SQLRegistraComunicacionEmpresa(SArgsSiscom *);
void SQLRegistraDireccion(SArgsSiscom *);

void SQLProveedores(SArgsSiscom *);
void SQLContactosProveedores(SArgsSiscom *);

void SqlContactosEmpresa(SArgsSiscom *);
void SqlDireccionesEmpresa(SArgsSiscom *);
void SqlMediosComunicacionEmpresa(SArgsSiscom *);

#endif
