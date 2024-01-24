#ifndef __INFORMACIONSEID_H__
#define __INFORMACIONSEID_H__
#include <stdio.h>
class CQSisFamilia;
class SiscomDatCom;
class CQSisLstFamilia;
class CQSisProducto;
class CQSisLstEmpresa;
class CQSisLstProducto;
class CQSisLstCompra;
class CQSisEmpresa;
void RegistraFamilias(FILE *pFlePtrArchivo,SiscomDatCom *);
void AbreArchivo(const char *pchrPtrArchivo,FILE **pFlePtrArchivo);
CQSisFamilia *EsRenglonFamilia(char **pchrPtrCampos);
void ObtenProductosFamilia(CQSisFamilia *,FILE *pFlePtrArchivo,SiscomDatCom *pSisDatCom);
int RegistroVacio(char **pchrPtrCampos);
void FormaProducto(CQSisFamilia *,char **pchrPtrCampos,SiscomDatCom *pSisDatCom);
void GeneraClaveFamilia(int pintContador,char *pchrPtrFamilia);

void EnviaFamilia(SiscomDatCom *pSisDatCom,CQSisFamilia *);

void RegistraProductos(FILE *pFlePtrArchivo,SiscomDatCom *,CQSisLstFamilia *);
void ObtenFamilias(SiscomDatCom *pSisDatCom,
		   CQSisLstFamilia *pCQSLFamilias);
void RegistrandoProductos(FILE *pFlePtrArchivo,
			  SiscomDatCom *pSisDatCom);

void RegistrandoProveedores(FILE *pFlePtrArchivo,SiscomDatCom *pSisDatCom);
void RegistraProveedores(FILE *pFlePtrArchivo,SiscomDatCom *pSisDatCom);
int EsRenglonFamilia2(char **pchrPtrCampos);

CQSisFamilia *BuscaFamilia(const char *pchrPtrDsc,CQSisLstFamilia *);

void ObtenProveedorProducto(FILE *pFlePtrArchivo,
			    SiscomDatCom *pSisDatCom);
void FormaProveedor(char **pchrPtrCampos,
		   SiscomDatCom *pSisDatCom);

void RegistrandoCompras(FILE *pFlePtrArchivo,
			SiscomDatCom *pSisDatCom);

void RegistraCompras(FILE *pFlePtrArchivo,
		     SiscomDatCom *pSisDatCom,
		     CQSisLstEmpresa *pCQSLEmpresas,
		     CQSisLstProducto *pCQSLProductos);
void ObtenProveedores(SiscomDatCom *pSisDatCom,CQSisLstEmpresa *);

void ObtenProductos(SiscomDatCom *pSisDatCom,CQSisLstProducto *);
void ObtenCompraProducto(FILE *pFlePtrArchivo,
			 SiscomDatCom *pSisDatCom,
			 CQSisLstEmpresa *pCQSLEmpresa,
			 CQSisLstProducto *pCQSLProductos,
			 CQSisLstCompra *pCQSLCompras);
void FormaCompra(char **pchrPtrCampos,
		 int pintNCampos,
		 SiscomDatCom *pSisDatCom,
		 CQSisLstEmpresa *pCQSLEmpresas,
		 CQSisLstProducto *pCQSLProductos,
		 CQSisLstCompra *pCQSLCompra);
CQSisProducto *BuscaProducto(const char *pchrPtrClave,CQSisLstProducto *pCQSLProducto);
CQSisEmpresa *BuscaProveedor(const char *pchrPtrRSocial,CQSisLstEmpresa *pCQSLEmpresas);

void RegistrandoPrecios(FILE *pFlePtrArchivo, SiscomDatCom *pSisDatCom);
void RegistraPrecios(FILE *pFlePtrArchivo,
		     SiscomDatCom *pSisDatCom,
		     CQSisLstProducto *pCQSLProductos);
void ObtenPreciosProducto(FILE *pFlePtrArchivo,
			  SiscomDatCom *pSisDatCom,
			  CQSisLstProducto *pCQSLProducto);
void FormaPrecio(char **pchrPtrCampos,
		 SiscomDatCom *pSisDatCom,
		 CQSisLstProducto *pCQSLProducto);

void FormateaPrecio(char *pchrPtrPrecio,
		    char *pchrPtrPrecioF);
#endif
