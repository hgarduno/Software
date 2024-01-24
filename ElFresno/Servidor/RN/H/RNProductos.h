#ifndef __RNPRODUCTOS_H__
#define __RNPRODUCTOS_H__
#include <FuncionesComunes.h>
#define RN_Productos_Clave			1
#define RN_Productos_Descripcion		2
#define RN_Productos_Unidad			3
#define RN_Productos_Familia		 	4
#define RN_Productos_EdoRegistroProducto 	5

const char *ObtenClave(char **);
const char *ObtenDescripcion(char **);
const char *ObtenUnidades(char **);
const char *ObtenFamilia(char **);
const char *ObtenEdoRegistroProducto(char **);

StcLtaRegComSISCOM *RegistraProductos(int , const char *, StcLtaRegComSISCOM *, int *);
StcLtaRegComSISCOM *ConsultaClavesYDescripciones(int , const char *, StcLtaRegComSISCOM *, int *);
/*StcLtaRegComSISCOM *ConsultaUnidades(int,const char *,StcLtaRegComSISCOM *,int *); */
StcLtaRegComSISCOM *GeneraRespuestaProductos(int *);
void AnexaRegistroProducto(char **,int,int *,StcLtaRegComSISCOM **,StcLtaRegComSISCOM **);
#endif
