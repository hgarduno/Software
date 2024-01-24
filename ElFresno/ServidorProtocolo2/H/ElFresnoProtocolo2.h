#ifndef __ELFRESNOPROTOCOLO2_H__
#define __ELFRESNOPROTOCOLO2_H__
#include <SiscomDesarrollo2.h>
#include <RNCorteExistencias.h>


void OperacionesSistemaGeneral(SSiscomOperaciones **);

void ActualizaProveedor(int,int);
void AnexaDireccion(int,int);
void AnexaContacto(int,int);
void AnexaTelefono(int,int);

void ConsultaVehiculos(int,int);
void ModificaVehiculo(int,int);
void EliminaVehiculo(int,int);

void ModificaFamilia(int,int);

void ActualizaFamiliaSQL(int,
			 const char *,
			 const char *,
			 const char *,
			 LCamposSiscomPro2 *,
			 char *);


void ModificaUnidad(int,int);
void ActualizaUnidadSQL(int,
			const char *,
			const char *,
			const char *,
			LCamposSiscomPro2 *,
			char *);
void ModificaProducto(int,int);
void ActualizaProductoSQL(int,
			const char *,
			const char *,
			const char *,
			LCamposSiscomPro2 *,
			char *);
void ConsultaPersonas(int,int);

void AnalizaConsultaSolicitada(SiscomOperacionesServidor *);
void AnalizaConsultaSolicitadaPersonas(SiscomOperacionesServidor *);

void ConsultaFirmas(LCamposSiscomPro2 *,LCamposSiscomPro2 **);
void ConsultaDirecciones(char *,LCamposSiscomPro2 **);
void ConsultaTelefonos(char *,LCamposSiscomPro2 **);
void ConsultaCorreos(char *,LCamposSiscomPro2 **);
void GeneraCondicionConsultaDatosPersona(LCamposSiscomPro2 *,char **);
void GeneraRespuestaConsultaPersonas(LCamposSiscomPro2 *,
				     LCamposSiscomPro2 *,
				     LCamposSiscomPro2 *,
				     LCamposSiscomPro2 *,
				     LCamposSiscomPro2 *,
				     int *,
				     LCamposSiscomPro2 **);

void EjecutaConsultaGeneralABDElFresno(const char *,LCamposSiscomPro2 **);
void EliminaDireccionSQL(int,
			const char *,
			const char *,
			const char *,
			LCamposSiscomPro2 *,
			char *);

void EliminaDirecciones(int ,int);

void AsignaOperacionesVersion2(int ,
				int,
				SSiscomOperaciones2 **,
				SArgsSiscom *);
void SiscomErrorOperacion2(SArgsSiscom *pSAgsSisPtr);
#endif
