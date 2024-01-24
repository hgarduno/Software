#ifndef __RNSISTEMAELFRESNO_H__
#define __RNSISTEMAELFRESNO_H__
#include <FuncionesComunes.h>
#include <RNPersonas.h>
#include <RNFamilias.h>
#include <RNUnidades.h>
#include <RNProductos.h>
#include <RNVarios.h>
#include <RNTiposPrecios.h>
#include <RNPrecios.h>
#include <RNCotizaciones.h>
#include <RNVentas.h>
#include <RNPedidos.h>
#include <RNVehiculos.h>
#include <RNChoferes.h>
#include <RNEmpresas.h>
#include <RNCompras.h>
#include <RNVentasExpendio.h>
#include <RNFacturacion.h>
#include <RNPersonas2.h>
int RNOperacionesElFresno(int ,int [],int ,char *);
StcLtaRegComSISCOM *EjecutaOperaciones(int ,const char *,StcLtaRegComSISCOM *,int *);

StcLtaRegComSISCOM *RegistraPersonas(int ,const char *,StcLtaRegComSISCOM *,int *);
StcLtaRegComSISCOM *ConsultarPersonas(int ,const char *,StcLtaRegComSISCOM *,int *);

int EsPorAPaterno(char **,char *);
int EsPorApodo(char **,char *);
int EsPorRFC(char **,char *);
int EsPorNombre(char **,char *);
int EsPorFirma(char **,char *);
int EsConsultaPorTipoPersona(char **,char *);

void CnsAPaterno(int,const char *,const char *,StcLtaRegComSISCOM **);
void CnsNombre(int,const char *,const char *,StcLtaRegComSISCOM **);
void CnsApodo(int,const char *,const char *,StcLtaRegComSISCOM **);
void CnsRFC(int,const char *,const char *,StcLtaRegComSISCOM **);


#endif
