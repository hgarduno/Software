#ifndef __GENERAINSERCIONES_H__
#define __GENERAINSERCIONES_H__
#include <SiscomProtocoloComunicaciones.h>
void InsertandoProductos(const char *pchrPtrIdTienda,
			 SiscomRegistroProL *pSiscomRegProLPtrProductos,
			 SiscomRegistroProL **pSiscomRegProLPtrSqlPrim,
			 SiscomRegistroProL **pSiscomRegProLPtrSqlAct);
void InsercionesProductos(SiscomRegistroProL *pSiscomRegProLPtrProductos,
			 SiscomRegistroProL **pSiscomRegProLPtrSqlPrim,
			 SiscomRegistroProL **pSiscomRegProLPtrSqlAct);



void InsertandoEmpresas(const char *pchrPtrIdTienda,SiscomRegistroProL *pSiscomRegProLPtrProductos,
			 SiscomRegistroProL **pSiscomRegProLPtrSqlPrim,
			 SiscomRegistroProL **pSiscomRegProLPtrSqlAct);
void InsercionesEmpresas(SiscomRegistroProL *pSiscomRegProLPtrProductos,
			 SiscomRegistroProL **pSiscomRegProLPtrSqlPrim,
			 SiscomRegistroProL **pSiscomRegProLPtrSqlAct);

int DireccionProveedor(SiscomRegistroProL *pSiscomRegProLPtrEmpresa,
			SiscomRegistroProL **pSiscomRegProLPtrSqlPrim,
			SiscomRegistroProL **pSiscomRegProLPtrSqlAct);
int DireccionProveedor(SiscomRegistroProL *pSiscomRegProLPtrEmpresa,
			SiscomRegistroProL **pSiscomRegProLPtrSqlPrim,
			SiscomRegistroProL **pSiscomRegProLPtrSqlAct);

void DireccionEmpresa(int pintIdDireccion,
		      SiscomRegistroProL *pSiscomRegProLPtrEmpresas,
		      SiscomRegistroProL **pSiscomRegProLPtrSqlPrim,
		      SiscomRegistroProL **pSiscomRegProLPtrSqlAct);

const char *DescuentoValido(SiscomRegistroProL *pSiscomRegProLPtrEmpresa,
			    const char *pchrPtrDescuento);

int DescuentosEmpresa(SiscomRegistroProL *pSiscomRegProLPtrEmpresas,
		       SiscomRegistroProL **pSiscomRegProLPtrSqlPrim,
		       SiscomRegistroProL **pSiscomRegProLPtrSqlAct);

void UltimoDescuentoEmpresa(int pintIdDescuento,
			SiscomRegistroProL *pSiscomRegProLPtrEmpresa,
		       SiscomRegistroProL **pSiscomRegProLPtrSqlPrim,
		       SiscomRegistroProL **pSiscomRegProLPtrSqlAct);

void Telefonos(const char *pchrPtrTelefono,
		SiscomRegistroProL *pSiscomRegProLPtrEmpresa,
	      SiscomRegistroProL **pSiscomRegProLPtrSqlPrim,
	      SiscomRegistroProL **pSiscomRegProLPtrSqlAct);

void TelefonoEmpresa(SiscomRegistroProL *pSiscomRegProLPtrEmpresa,
		     SiscomRegistroProL **pSiscomRegProLPtrSqlPrim,
		     SiscomRegistroProL **pSiscomRegProLPtrSqlAct);

void ContactoEmpresa(SiscomRegistroProL *pSiscomRegProLPtrEmpresa,
		     SiscomRegistroProL **pSiscomRegProLPtrSqlPrim,
		     SiscomRegistroProL **pSiscomRegProLPtrSqlAct);

void PlazoEmpresa(SiscomRegistroProL *pSiscomRegProLPtrEmpresa,
		     SiscomRegistroProL **pSiscomRegProLPtrSqlPrim,
		     SiscomRegistroProL **pSiscomRegProLPtrSqlAct);

void IvaEmpresa(SiscomRegistroProL *pSiscomRegProLPtrEmpresa,
		     SiscomRegistroProL **pSiscomRegProLPtrSqlPrim,
		     SiscomRegistroProL **pSiscomRegProLPtrSqlAct);
void InsertandoTiposDocumentos(const char *pchrPtrIdTienda,
				SiscomRegistroProL *pSiscomRegProLPtrProductos,
			 SiscomRegistroProL **pSiscomRegProLPtrSqlPrim,
			 SiscomRegistroProL **pSiscomRegProLPtrSqlAct);

void InsercionesTiposDocumentos(SiscomRegistroProL *pSiscomRegProLPtrProductos,
			 SiscomRegistroProL **pSiscomRegProLPtrSqlPrim,
			 SiscomRegistroProL **pSiscomRegProLPtrSqlAct);
void TiposDocumentos(int pintContador,SiscomRegistroProL *pLCSiscomProLPtrDatos,
			 SiscomRegistroProL **pSiscomRegProLPtrSqlPrim,
			 SiscomRegistroProL **pSiscomRegProLPtrSqlAct);


void InsertandoConceptosExistencias(const char *pchrPtrIdTienda,SiscomRegistroProL *pSiscomRegProLPtrConceptosExistencias,
			 SiscomRegistroProL **pSiscomRegProLPtrSqlPrim,
			 SiscomRegistroProL **pSiscomRegProLPtrSqlAct);
void InsercionesConceptosExistencias(SiscomRegistroProL *pSiscomRegProLPtrConceptosExistencias,
			 SiscomRegistroProL **pSiscomRegProLPtrSqlPrim,
			 SiscomRegistroProL **pSiscomRegProLPtrSqlAct);

void InsertandoTiendas(const char *pchrPtrIdTienda,SiscomRegistroProL *pSiscomRegProLPtrTiendas,
			 SiscomRegistroProL **pSiscomRegProLPtrSqlPrim,
			 SiscomRegistroProL **pSiscomRegProLPtrSqlAct);
void InsercionesTiendas(SiscomRegistroProL *pSiscomRegProLPtrTiendas,
			 SiscomRegistroProL **pSiscomRegProLPtrSqlPrim,
			 SiscomRegistroProL **pSiscomRegProLPtrSqlAct);

void InsertandoVendedores(const char *pchrPtrIdTienda,SiscomRegistroProL *pSiscomRegProLPtrVendedores,
			 SiscomRegistroProL **pSiscomRegProLPtrSqlPrim,
			 SiscomRegistroProL **pSiscomRegProLPtrSqlAct);
void InsercionesVendedores(SiscomRegistroProL *pSiscomRegProLPtrVendedores,
			 SiscomRegistroProL **pSiscomRegProLPtrSqlPrim,
			 SiscomRegistroProL **pSiscomRegProLPtrSqlAct);

void InsertandoDepartamentos(const char *pchrPtrIdTienda,
			 SiscomRegistroProL *pSiscomRegProLPtrDepartamentos,
			 SiscomRegistroProL **pSiscomRegProLPtrSqlPrim,
			 SiscomRegistroProL **pSiscomRegProLPtrSqlAct);
void InsercionesDepartamentos(SiscomRegistroProL *pSiscomRegProLPtrDepartamentos,
			      SiscomRegistroProL **pSiscomRegProLPtrSqlPrim,
			      SiscomRegistroProL **pSiscomRegProLPtrSqlAct);
void Departamentos(int pintContador,
		   SiscomRegistroProL *pSiscomRegProLPtrDepartamento,
		   SiscomRegistroProL **pSiscomRegProLPtrSqlPrim,
		   SiscomRegistroProL **pSiscomRegProLPtrSqlAct);


void ActualizandoExistenciasTienda(const char *pchrPtrIdTienda,SiscomRegistroProL *pSiscomRegProLPtrExistencias,
			 SiscomRegistroProL **pSiscomRegProLPtrSqlPrim,
			 SiscomRegistroProL **pSiscomRegProLPtrSqlAct);
void ActualizaExistenciasTiendas(const char *pchrPtrIdTienda,SiscomRegistroProL *pSiscomRegProLPtrExistencias,
			 SiscomRegistroProL **pSiscomRegProLPtrSqlPrim,
			 SiscomRegistroProL **pSiscomRegProLPtrSqlAct);

void InsertandoCreditosMaestros(const char *pchrPtrIdTienda,
				SiscomRegistroProL *pSiscomRegProLPtrExistencias,
			 SiscomRegistroProL **pSiscomRegProLPtrSqlPrim,
			 SiscomRegistroProL **pSiscomRegProLPtrSqlAct);
void InsertaCreditoMaestro(const char *pchrPtrIdTienda,
			   SiscomRegistroProL *pSiscomRegProLPtrExistencias,
			 SiscomRegistroProL **pSiscomRegProLPtrSqlPrim,
			 SiscomRegistroProL **pSiscomRegProLPtrSqlAct);

void AsignandoProductosDepartamentos(const char *pchrPtrIdTienda,
				     SiscomRegistroProL *pSiscomRegProLPtrDepartamentos,
			 	     SiscomRegistroProL **pSiscomRegProLPtrSqlPrim,
			 	     SiscomRegistroProL **pSiscomRegProLPtrSqlAct);


void InsertandoRFCsCreditos(const char *pchrPtrIdTienda,
			  SiscomRegistroProL *pSiscomRegProLPtrExistencias,
			 SiscomRegistroProL **pSiscomRegProLPtrSqlPrim,
			 SiscomRegistroProL **pSiscomRegProLPtrSqlAct);



void Empresas(SiscomRegistroProL *pSiscomRegProLPtrEmpresas,
			 SiscomRegistroProL **pSiscomRegProLPtrSqlPrim,
			 SiscomRegistroProL **pSiscomRegProLPtrSqlAct);
void Proveedores(SiscomRegistroProL *pSiscomRegProLPtrEmpresas,
			 SiscomRegistroProL **pSiscomRegProLPtrSqlPrim,
			 SiscomRegistroProL **pSiscomRegProLPtrSqlAct);
void ConceptosExistencias(SiscomRegistroProL *pLCSiscomProLPtrDatos,
			 SiscomRegistroProL **pSiscomRegProLPtrSqlPrim,
			 SiscomRegistroProL **pSiscomRegProLPtrSqlAct);
void Tiendas(SiscomRegistroProL *pLCSiscomProLPtrDatos,
			 SiscomRegistroProL **pSiscomRegProLPtrSqlPrim,
			 SiscomRegistroProL **pSiscomRegProLPtrSqlAct);
void Vendedores(int pintIdVendedor,SiscomRegistroProL *pLCSiscomProLPtrDatos,
			 SiscomRegistroProL **pSiscomRegProLPtrSqlPrim,
			 SiscomRegistroProL **pSiscomRegProLPtrSqlAct);
void PersonaVendedor(int pintIdVendedor,SiscomRegistroProL *pLCSiscomProLPtrDatos,
			 SiscomRegistroProL **pSiscomRegProLPtrSqlPrim,
			 SiscomRegistroProL **pSiscomRegProLPtrSqlAct);
int Personas(int pintIdVendedor, SiscomRegistroProL *pLCSiscomProLPtrDatos,
			 SiscomRegistroProL **pSiscomRegProLPtrSqlPrim,
			 SiscomRegistroProL **pSiscomRegProLPtrSqlAct);


void EstatusProducto(int pintContador,SiscomRegistroProL *pSiscomRegProLPtrProductos,
			 SiscomRegistroProL **pSiscomRegProLPtrSqlPrim,
			 SiscomRegistroProL **pSiscomRegProLPtrSqlAct);
void ProductoCodigoBarras(int pintContador,SiscomRegistroProL *pSiscomRegProLPtrProductos,
			 SiscomRegistroProL **pSiscomRegProLPtrSqlPrim,
			 SiscomRegistroProL **pSiscomRegProLPtrSqlAct);
void CostoBruto(int pintContador,SiscomRegistroProL *pSiscomRegProLPtrProductos,
			 SiscomRegistroProL **pSiscomRegProLPtrSqlPrim,
			 SiscomRegistroProL **pSiscomRegProLPtrSqlAct);
void PrecioGeneral(int pintContador,SiscomRegistroProL *pSiscomRegProLPtrProductos,
			 SiscomRegistroProL **pSiscomRegProLPtrSqlPrim,
			 SiscomRegistroProL **pSiscomRegProLPtrSqlAct);
void PrecioForaneo(int pintContador,SiscomRegistroProL *pSiscomRegProLPtrProductos,
			 SiscomRegistroProL **pSiscomRegProLPtrSqlPrim,
			 SiscomRegistroProL **pSiscomRegProLPtrSqlAct);


const char *SiEsNumeroVacioRegresaCero(const char *pchrPtrDato);
int ObtenFinanciera(SiscomRegistroProL *pSiscomRegProLPtrRegistro);

void InsertaRFCsCreditos(SiscomRegistroProL **pSiscomRegProLPtrSqlPrim,
			 SiscomRegistroProL **pSiscomRegProLPtrSqlAct);

void ProductoDepartamento(int pintProducto,
			SiscomRegistroProL *pSiscomRegProLProductos,
			  SiscomRegistroProL **pSiscomRegProLSqlPrim,
			  SiscomRegistroProL **pSiscomRegProLSqlAct);
#endif
