#ifndef __FACTURANDO4_H__
#define __FACTURANDO4_H__

#include <SiscomDesarrollo4/H/SiscomOperaciones.h>
#include <stdio.h>

typedef struct  ArchivoFacturando
{
	void (*Facturando[9])(SiscomOperaciones *pSiscomOpePtrDato,FILE *pFlePtrArchivo);

}SiscomArchivoFacturando;

void ReEnviaFactura(int pintSocket,
			     SiscomRegistroProL *pSiscomRegProLPtrPrim,
			     SiscomRegistroProL *pSiscomRegProLPtrAct);
void DatosParaReEnvioFactura(int pintSocket,
			     SiscomRegistroProL *pSiscomRegProLPtrPrim,
			     SiscomRegistroProL *pSiscomRegProLPtrAct);
void CalculaFactura(int pintSocket,
		SiscomRegistroProL *pSiscomRegProLPtrPrim,
		SiscomRegistroProL *pSiscomRegProLPtrAct);

void RegistraClienteFacturacion(int pintSocket,
		SiscomRegistroProL *pSiscomRegProLPtrPrim,
		SiscomRegistroProL *pSiscomRegProLPtrAct);

void RealizaFactura(int pintSocket,
		SiscomRegistroProL *pSiscomRegProLPtrPrim,
		SiscomRegistroProL *pSiscomRegProLPtrAct);

void ValidaRfcRegistrado(int pintSocket,
		SiscomRegistroProL *pSiscomRegProLPtrPrim,
		SiscomRegistroProL *pSiscomRegProLPtrAct);

void AgregaCorreoCliente(int pintSocket,
		SiscomRegistroProL *pSiscomRegProLPtrPrim,
		SiscomRegistroProL *pSiscomRegProLPtrAct);
int EnviaCalculoFactura(SiscomOperaciones *pSiscomOpePtrDato);
int RegistraCliente4(SiscomOperaciones *pSiscomOpePtrDato);

int AgregandoCorreoCliente(SiscomOperaciones *pSiscomOpePtrDato);

int ArgumentoRegistroCliente(SiscomOperaciones *pSiscomOpePtrDato);
int ArgumentoAmbienteFacturacionPhp(SiscomOperaciones *pSiscomOpePtrDato);
int ArgumentoRegistroFactura(SiscomOperaciones *pSiscomOpePtrDato);
int GeneraIdPersona4(SiscomOperaciones *pSiscomOpePtrDato);
int GeneraIdEmpresa4(SiscomOperaciones *pSiscomOpePtrDato);

int EnviaDatosReEnvioFactura(SiscomOperaciones *pSiscomOpePtrDato);
int ReEnviandoFactura(SiscomOperaciones *pSiscomOpePtrDato);

SiscomRegistroProL *CalculandoFacturaOrdenes(SiscomOperaciones *pSiscomOpePtrDato,float *pfltImporte);

SiscomRegistroProL *FormaRegistroCalculaFactura(SiscomRegistroProL *pSiscomRegProLPtrProductos);
void AgregaImportesMasIva(float pfltImporteTotal,float, SiscomRegistroProL *pSiscomRegProLPtrFactura);

int EsPersonaFisica(SiscomOperaciones *pSiscomOpePtrDato);


int RealizandoFactura(SiscomOperaciones *pSiscomOpePtrDato);
int ValidandoRfcRegistrado(SiscomOperaciones *pSiscomOpePtrDato);
int AsignaIdFactura(SiscomOperaciones *pSiscomOpePtrDato);
int AgregaFecha(SiscomOperaciones *pSiscomOpePtrDato);

SiscomRegistroProL *FormaRespuestaClienteRegistrado(
					   int pintPersonaFisica,
					   SiscomRegistroProL *pSiscomRegProLPtrPersona,
					   SiscomOperaciones *pSiscomOpePtrDato);

/* Tepotzotlan Mexico a 5 de Enero del 2018 
 * Con el cambio del SAT a la version 3.3 de la factura, se agrega
 * la estructura que contiene el arreglo de apuntadores a funciones 
 * que generan el archivo de datos para generar la factura, para 
 * poder cambiar al vuelo la version de facturacion
 */


void FacturandoDatosFactura(SiscomOperaciones *pSiscomOpePtrDato,FILE *pFlePtrArchivo);
void FacturandoDatosEmisor(SiscomOperaciones *pSiscomOpePtrDato, FILE *pFlePtrArchivo);
void FacturandoDatosClienteEmpresa(SiscomOperaciones *pSiscomOpePtrDato, FILE *pFlePtrArchivo);
void FacturandoDatosClienteFisica(SiscomOperaciones *pSiscomOpePtrDato, FILE *pFlePtrArchivo);
void FacturandoDireccion(SiscomOperaciones *pSiscomOpePtrDato, FILE *pFlePtrArchivo);
void FacturandoIva(SiscomOperaciones *pSiscomOpePtrDato, FILE *pFlePtrArchivo);
void FacturandoProductos(SiscomOperaciones *pSiscomOpePtrDato, FILE *pFlePtrArchivo);

void FacturandoDatosFactura_3_3(SiscomOperaciones *pSiscomOpePtrDato,FILE *pFlePtrArchivo);
void FacturandoDatosEmisor_3_3(SiscomOperaciones *pSiscomOpePtrDato, FILE *pFlePtrArchivo);
void FacturandoDatosClienteEmpresa_3_3(SiscomOperaciones *pSiscomOpePtrDato, FILE *pFlePtrArchivo);
void FacturandoDatosClienteFisica_3_3(SiscomOperaciones *pSiscomOpePtrDato, FILE *pFlePtrArchivo);
void FacturandoDireccion_3_3(SiscomOperaciones *pSiscomOpePtrDato, FILE *pFlePtrArchivo);
void FacturandoIva_3_3(SiscomOperaciones *pSiscomOpePtrDato, FILE *pFlePtrArchivo);
void FacturandoProductos_3_3(SiscomOperaciones *pSiscomOpePtrDato, FILE *pFlePtrArchivo);

void FacturandoGeneraXML_4_0(SiscomOperaciones *pSiscomOpePtrDato,FILE *pFlePtrArchivo);


int VerificandoCaracteres(SiscomOperaciones *pSiscomOpePtrDato);
int FormaArchivoPdfFactura4_0(SiscomOperaciones *pSiscomOpePtrDato);

void NombreArchivoFacturacion_4_0(SiscomOperaciones *pSiscomOpePtrDato,
				  const char *pchrPtrExtension,
				  char *pchrPtrArchivo);

float CalculandoElIva(float,SiscomRegistroProL *pSisRegProLPtrProductos);
#endif
