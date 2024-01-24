#ifndef __RNPRECIOS_H__
#define __RNPRECIOS_H__
#include <FuncionesComunes.h>
#include <RNComunFresno.h>
#define RN_Precios_Producto		1
#define RN_Precios_IdPersona		2
#define RN_Precios_IdEmpresa		3
#define RN_Precios_Precio		4
#define RN_Precios_NmbTipoPrecio	5 
#define RN_Precios_EdoRegistroPrecio    6
#define RN_Precios_IdPrecioPrecio	7
const char *ObtenProducto(char **);
const char *ObtenIdPersonaPrecios(char **);
const char *ObtenIdEmpresa(char **);
const char *ObtenPrecio(char **);
const char *ObtenNmbTipoPrecio(char **);
const char *ObtenEdoRegistroPrecio(char **);
const char *ObtenIdPrecio(char **);

StcLtaRegComSISCOM *RegistraPreciosDelProducto(int , const char *, StcLtaRegComSISCOM *, int *);
StcLtaRegComSISCOM *ConsultaPrecios(int , const char *, StcLtaRegComSISCOM *, int *);
StcLtaRegComSISCOM *GeneraRespuestaPrecios(int *);

StcLtaRegComSISCOM *OperacionesPrecios(int , const char *, StcLtaRegComSISCOM *, int *);
int EsPreciosDelProducto(char **,char *,StcLtaRegComSISCOM *,StcLtaRegComSISCOM **);
void PreciosDelProducto(int,
			const char *,
			const char *,
			StcLtaRegComSISCOM *,
			StcLtaRegComSISCOM **,
			int *);
void RespuestaPreciosDelProducto(int,
				 const char *,
				 int,
				 StcLtaRegComSISCOM *,
				 StcLtaRegComSISCOM **,	
				 int *);
int EsAsignarTiposPreciosAProductosGen(char **,char *,StcLtaRegComSISCOM *,StcLtaRegComSISCOM **);
void AsignarTiposPreciosAProductosGen(int,
			const char *,
			const char *,
			StcLtaRegComSISCOM *,
			StcLtaRegComSISCOM **,
			int *);
void RespuestaAsignarTiposPreciosAProductosGen(int,
				 const char *,
				 int,
				 StcLtaRegComSISCOM *,
				 StcLtaRegComSISCOM **,	
				 int *);

int EsAsignarTiposPreciosAProductosClienteDeGen(char **,char *,StcLtaRegComSISCOM *,StcLtaRegComSISCOM **);
void AsignarTiposPreciosAProductosCLienteDeGen(int,
			const char *,
			const char *,
			StcLtaRegComSISCOM *,
			StcLtaRegComSISCOM **,
			int *);
void RespuestaAsignarTiposPreciosAProductosCLienteDeGen(int,
				 const char *,
				 int,
				 StcLtaRegComSISCOM *,
				 StcLtaRegComSISCOM **,	
				 int *);
int EsActualizaPrecio(char **,char *,StcLtaRegComSISCOM *,StcLtaRegComSISCOM **);
void ActualizaPrecio(int,
			const char *,
			const char *,
			StcLtaRegComSISCOM *,
			StcLtaRegComSISCOM **,
			int *);
void RespuestaActualizaPrecio(int,
				 const char *,
				 int,
				 StcLtaRegComSISCOM *,
				 StcLtaRegComSISCOM **,	
				 int *);


#endif


