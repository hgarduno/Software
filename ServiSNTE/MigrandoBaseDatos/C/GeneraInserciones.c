#include <GeneraInserciones.h>
#include <SiscomFuncionesComunes.h>
#include <SiscomDesarrolloMacros.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/* Martes 14 de Abril 2015 
 * Tabla TBMPrd
 * Prv_Cve
 * Prd_Cve
 * Prd_Nombre
 * Prd_Modelo
 * Prd_CostoB
 * Prd_Desc1
 * Prd_Desc2
 * Prd_Desc3
 * Prd_Desc4
 * Prd_IVA
 * Prd_CostoN
 * Prd_PrecioM
 * Prd_PrecioMSIVA
 * Prd_PrecioMIVA
 * Prd_PrecioF
 * Prd_PrecioFSIVA
 * Prd_PrecioFIVA
 * Prd_Margen
 * Prd_MargenF
 * Prd_Sts
 *
 */

void InsertandoProductos(const char *pchrPtrIdTienda,
			 SiscomRegistroProL *pSiscomRegProLPtrProductos,
			 SiscomRegistroProL **pSiscomRegProLPtrSqlPrim,
			 SiscomRegistroProL **pSiscomRegProLPtrSqlAct)
{
  InsercionesProductos(pSiscomRegProLPtrProductos,
  			pSiscomRegProLPtrSqlPrim,
			pSiscomRegProLPtrSqlAct);
}

void InsercionesProductos(SiscomRegistroProL *pSiscomRegProLPtrProductos,
			 SiscomRegistroProL **pSiscomRegProLPtrSqlPrim,
			 SiscomRegistroProL **pSiscomRegProLPtrSqlAct)
{
int lintContador;
char lchrArrSql[256],
	lchrArrBuffer[256];
for(;
     pSiscomRegProLPtrProductos;
     pSiscomRegProLPtrProductos=SiscomSiguienteNodoRegistroProL(pSiscomRegProLPtrProductos)
     )
{
lintContador=SiscomGeneraIdProducto(
		SiscomObtenCampoRegistroProLChar("prd_nombre",pSiscomRegProLPtrProductos),
		SiscomObtenCampoRegistroProLChar("prd_modelo",pSiscomRegProLPtrProductos));
sprintf(lchrArrSql,"insert into Productos values(%d,%s,'%s','%s');",
	lintContador,
	SiscomObtenCampoRegistroProLChar("prd_cve",pSiscomRegProLPtrProductos),
	SiscomObtenCampoRegistroProLChar("prd_nombre",pSiscomRegProLPtrProductos),
	SiscomObtenCampoRegistroProLChar("prd_modelo",pSiscomRegProLPtrProductos));
SiscomAnexaRegistroPro(pSiscomRegProLPtrSqlPrim,
		       pSiscomRegProLPtrSqlAct,
		       lchrArrBuffer,
		       "SentenciaSql,EstadoRegistro,",
		       lchrArrSql,0);
sprintf(lchrArrSql,
	"insert into ProductoProveedor values(%s,%d);",
	 SiscomObtenCampoRegistroProLChar("prv_cve",pSiscomRegProLPtrProductos),
	 lintContador);
SiscomAnexaRegistroPro(pSiscomRegProLPtrSqlPrim,
		       pSiscomRegProLPtrSqlAct,
		       lchrArrBuffer,
		       "SentenciaSql,EstadoRegistro,",
		       lchrArrSql,0);
EstatusProducto(lintContador,
		pSiscomRegProLPtrProductos,
  		pSiscomRegProLPtrSqlPrim,
		pSiscomRegProLPtrSqlAct);
ProductoCodigoBarras(lintContador,
		     pSiscomRegProLPtrProductos,
  		     pSiscomRegProLPtrSqlPrim,
		    pSiscomRegProLPtrSqlAct);
CostoBruto(lintContador,
	   pSiscomRegProLPtrProductos,
  	   pSiscomRegProLPtrSqlPrim,
	   pSiscomRegProLPtrSqlAct);
PrecioGeneral(lintContador,
		pSiscomRegProLPtrProductos,
  			pSiscomRegProLPtrSqlPrim,
			pSiscomRegProLPtrSqlAct);
PrecioForaneo(lintContador,
		pSiscomRegProLPtrProductos,
  			pSiscomRegProLPtrSqlPrim,
			pSiscomRegProLPtrSqlAct);
ProductoDepartamento(lintContador,
		  pSiscomRegProLPtrProductos,
		     pSiscomRegProLPtrSqlPrim,
		     pSiscomRegProLPtrSqlAct);
}
}
SiscomRegistroProL *ListaProductosDepartamento(SiscomRegistroProL *pSiscomRegProLPtrSqls)
{
    for(;
    	pSiscomRegProLPtrSqls;
	pSiscomRegProLPtrSqls=pSiscomRegProLPtrSqls->SiscomRegProLPtrSig)
    {
	if(SiscomObtenCampoRegistroProL("ProductosDepartamento",pSiscomRegProLPtrSqls))
	return pSiscomRegProLPtrSqls;
    }
return 0;
}
void ProductoDepartamento(int pintProducto,
			SiscomRegistroProL *pSiscomRegProLProductos,
			  SiscomRegistroProL **pSiscomRegProLSqlPrim,
			  SiscomRegistroProL **pSiscomRegProLSqlAct)
{
SiscomRegistroProL *lSiscomRegProLPtrSqls,
		   *lSiscomRegProLPtrProdProveedor;
char lchrArrSql[128],
	lchrArrBuffer[128];

if((lSiscomRegProLPtrSqls=ListaProductosDepartamento(*pSiscomRegProLSqlPrim)))
{
   lSiscomRegProLPtrProdProveedor=SiscomObtenRegistrosCampoProL("ProductosDepartamento",
   								lSiscomRegProLPtrSqls);
   
   for(	;
   	lSiscomRegProLPtrProdProveedor;
	lSiscomRegProLPtrProdProveedor=lSiscomRegProLPtrProdProveedor->SiscomRegProLPtrSig)
   {
	if(!SiscomComparaCampoRegistrosProL2("prv_cve",
					     "Prv_Cve",
					     pSiscomRegProLProductos,
					     lSiscomRegProLPtrProdProveedor) &&
	   !SiscomComparaCampoRegistrosProL2("prd_cve",
	   				     "Prd_Cve",
	   				     pSiscomRegProLProductos,
					     lSiscomRegProLPtrProdProveedor))
	 {
	   sprintf(lchrArrSql,
	   	   "insert into departamentoproducto values(%d,%s);",
		   	pintProducto,
			SiscomObtenCampoRegistroProLChar("Dep_Cve",lSiscomRegProLPtrProdProveedor));
	   SiscomAnexaRegistroPro(pSiscomRegProLSqlPrim,
		       		  pSiscomRegProLSqlAct,
		       		  lchrArrBuffer,
		       		  "SentenciaSql,EstadoRegistro,",
		       		  lchrArrSql,
				  0);
	 }
   }
} 
}
void CostoBruto(int pintContador,SiscomRegistroProL *pSiscomRegProLPtrProductos,
			 SiscomRegistroProL **pSiscomRegProLPtrSqlPrim,
			 SiscomRegistroProL **pSiscomRegProLPtrSqlAct)
{
char lchrArrFechaHoy[28];
char lchrArrSql[256],lchrArrBuffer[256];
const char *lchrPtrCostoBruto,
	   *lchrPtrCostoNeto;
int lintIdPrecio;
SiscomObtenFechaHoyCharAAAADDMM(lchrArrFechaHoy);
lchrPtrCostoBruto=SiscomObtenCampoRegistroProLChar("prd_costob",pSiscomRegProLPtrProductos);
lchrPtrCostoNeto=SiscomObtenCampoRegistroProLChar("prd_coston",pSiscomRegProLPtrProductos);
lintIdPrecio=SiscomObtenNumeroUnico();
sprintf(lchrArrSql,"insert into CostoBruto values(%ld,%s,%s,%d,'%s',%d);",
	(long )lintIdPrecio,
	SiEsNumeroVacioRegresaCero(lchrPtrCostoBruto),
	SiEsNumeroVacioRegresaCero(lchrPtrCostoNeto),
	0,
	lchrArrFechaHoy,
	pintContador);

SiscomAnexaRegistroPro(pSiscomRegProLPtrSqlPrim,
		       pSiscomRegProLPtrSqlAct,
		       lchrArrBuffer,
		       "SentenciaSql,EstadoRegistro,",
		       lchrArrSql,0);
sprintf(lchrArrSql,"insert into UltimoCosto values(%d,%d);",pintContador,lintIdPrecio);

SiscomAnexaRegistroPro(pSiscomRegProLPtrSqlPrim,
		       pSiscomRegProLPtrSqlAct,
		       lchrArrBuffer,
		       "SentenciaSql,EstadoRegistro,",
		       lchrArrSql,0);
}
void PrecioGeneral(int pintContador,SiscomRegistroProL *pSiscomRegProLPtrProductos,
			 SiscomRegistroProL **pSiscomRegProLPtrSqlPrim,
			 SiscomRegistroProL **pSiscomRegProLPtrSqlAct)
{
char lchrArrFechaHoy[28];
char lchrArrSql[256],lchrArrBuffer[256];
const char *lchrPtrCostoBruto;
const char *lchrPtrPrecioM;
int lintIdPrecio;
SiscomObtenFechaHoyCharAAAADDMM(lchrArrFechaHoy);

lchrPtrPrecioM=SiscomObtenCampoRegistroProLChar("prd_preciom",pSiscomRegProLPtrProductos);
lintIdPrecio=SiscomObtenNumeroUnico();
sprintf(lchrArrSql,"insert into PrecioGeneral values(%ld,%s,%s,%d,'%s',%d);",
	(long )lintIdPrecio,
	SiEsNumeroVacioRegresaCero(lchrPtrPrecioM),
	"0",
	0,
	lchrArrFechaHoy,
	pintContador);

SiscomAnexaRegistroPro(pSiscomRegProLPtrSqlPrim,
		       pSiscomRegProLPtrSqlAct,
		       lchrArrBuffer,
		       "SentenciaSql,EstadoRegistro,",
		       lchrArrSql,0);
sprintf(lchrArrSql,"insert into UltimoPrecioGeneral values(%d,%d);",pintContador,lintIdPrecio);

SiscomAnexaRegistroPro(pSiscomRegProLPtrSqlPrim,
		       pSiscomRegProLPtrSqlAct,
		       lchrArrBuffer,
		       "SentenciaSql,EstadoRegistro,",
		       lchrArrSql,0);
}

void PrecioForaneo(int pintContador,SiscomRegistroProL *pSiscomRegProLPtrProductos,
			 SiscomRegistroProL **pSiscomRegProLPtrSqlPrim,
			 SiscomRegistroProL **pSiscomRegProLPtrSqlAct)
{
char lchrArrFechaHoy[28];
char lchrArrSql[256],lchrArrBuffer[256];
const char *lchrPtrCostoBruto;
const char *lchrPtrPrecioF;
int lintIdPrecio;
SiscomObtenFechaHoyCharAAAADDMM(lchrArrFechaHoy);

lchrPtrPrecioF=SiscomObtenCampoRegistroProLChar("prd_preciof",pSiscomRegProLPtrProductos);
lintIdPrecio=SiscomObtenNumeroUnico();
sprintf(lchrArrSql,"insert into PrecioForaneo values(%ld,%s,%s,%d,'%s',%d);",
	(long )lintIdPrecio,
	SiEsNumeroVacioRegresaCero(lchrPtrPrecioF),
	"0",
	0,
	lchrArrFechaHoy,
	pintContador);

SiscomAnexaRegistroPro(pSiscomRegProLPtrSqlPrim,
		       pSiscomRegProLPtrSqlAct,
		       lchrArrBuffer,
		       "SentenciaSql,EstadoRegistro,",
		       lchrArrSql,0);
sprintf(lchrArrSql,"insert into UltimoPrecioForaneo values(%d,%d);",pintContador,lintIdPrecio);

SiscomAnexaRegistroPro(pSiscomRegProLPtrSqlPrim,
		       pSiscomRegProLPtrSqlAct,
		       lchrArrBuffer,
		       "SentenciaSql,EstadoRegistro,",
		       lchrArrSql,0);
}


void ProductoCodigoBarras(int pintContador,SiscomRegistroProL *pSiscomRegProLPtrProductos,
			 SiscomRegistroProL **pSiscomRegProLPtrSqlPrim,
			 SiscomRegistroProL **pSiscomRegProLPtrSqlAct)
{
char lchrArrSql[256],lchrArrBuffer[128];
sprintf(lchrArrSql,
	"insert into ProductoCodigoBarras values('%011d%03d',%d);",
	pintContador,
	SiscomObtenCampoRegistroProLInt("prv_cve",pSiscomRegProLPtrProductos),
	pintContador);

SiscomAnexaRegistroPro(pSiscomRegProLPtrSqlPrim,
		       pSiscomRegProLPtrSqlAct,
		       lchrArrBuffer,
		       "SentenciaSql,EstadoRegistro,",
		       lchrArrSql,0);
}
void EstatusProducto(int pintContador,SiscomRegistroProL *pSiscomRegProLPtrProductos,
			 SiscomRegistroProL **pSiscomRegProLPtrSqlPrim,
			 SiscomRegistroProL **pSiscomRegProLPtrSqlAct)
{
const char *lchrPtrEstatusProducto;
char lchrArrBuffer[128],
	lchrArrSql[256];
lchrPtrEstatusProducto=SiscomObtenCampoRegistroProLChar("prd_sts",pSiscomRegProLPtrProductos);
if(*lchrPtrEstatusProducto=='A')
sprintf(lchrArrSql,"insert into EstatusProducto values(%d,1);",pintContador);
if(*lchrPtrEstatusProducto=='I')
sprintf(lchrArrSql,"insert into EstatusProducto values(%d,2);",pintContador);
if(*lchrPtrEstatusProducto=='D')
sprintf(lchrArrSql,"insert into EstatusProducto values(%d,3);",pintContador);
SiscomAnexaRegistroPro(pSiscomRegProLPtrSqlPrim,
		       pSiscomRegProLPtrSqlAct,
		       lchrArrBuffer,
		       "SentenciaSql,EstadoRegistro,",
		       lchrArrSql,0);
}

const char *SiEsNumeroVacioRegresaCero(const char *pchrPtrDato)
{
  return *pchrPtrDato ? pchrPtrDato : "0";
}

/*
 * Prv_Cve
 * Prv_Nombre
 * Prv_RFN
 * Prv_RFF
 * Prv_RFH
 * Prv_RFD
 * Prv_DirCalle
 * Prv_DirNoExt
 * Prv_DirNoInt
 * Prv_DirColonia
 * Prv_DirPobyEdo
 * Prv_CodPos
 * Prv_LADA
 * Prv_Tel1
 * Prv_Tel2
 * Prv_Tel3
 * Prv_Desc1
 * Prv_Desc2
 * Prv_Desc3
 * Prv_Desc4
 * Prv_IVA
 * Prv_Plazo
 * Prv_Consolidar
 * Prv_Contac
 * Prv_Sts
 */

void InsertandoEmpresas(const char *pchrPtrIdTienda,
			SiscomRegistroProL *pSiscomRegProLPtrEmpresas,
			 SiscomRegistroProL **pSiscomRegProLPtrSqlPrim,
			 SiscomRegistroProL **pSiscomRegProLPtrSqlAct)
{
  InsercionesEmpresas(pSiscomRegProLPtrEmpresas,
  			pSiscomRegProLPtrSqlPrim,
			pSiscomRegProLPtrSqlAct);

}
void InsercionesEmpresas(SiscomRegistroProL *pSiscomRegProLPtrEmpresas,
			 SiscomRegistroProL **pSiscomRegProLPtrSqlPrim,
			 SiscomRegistroProL **pSiscomRegProLPtrSqlAct)
{
int lintContador,
	lintIdDireccion,
	lintIdDescuento,
	lintIdTelefono;
for(lintContador=0;
     pSiscomRegProLPtrEmpresas;
     pSiscomRegProLPtrEmpresas=SiscomSiguienteNodoRegistroProL(pSiscomRegProLPtrEmpresas),
     lintContador++)
{
 Empresas(pSiscomRegProLPtrEmpresas,
  	  pSiscomRegProLPtrSqlPrim,
	  pSiscomRegProLPtrSqlAct);
 Proveedores(pSiscomRegProLPtrEmpresas,
  	     pSiscomRegProLPtrSqlPrim,
	     pSiscomRegProLPtrSqlAct);
lintIdDireccion=DireccionProveedor(pSiscomRegProLPtrEmpresas,
 		    pSiscomRegProLPtrSqlPrim,
		    pSiscomRegProLPtrSqlAct); 
  DireccionEmpresa(lintIdDireccion,
  		   pSiscomRegProLPtrEmpresas,
		   pSiscomRegProLPtrSqlPrim,
		   pSiscomRegProLPtrSqlAct);
  lintIdDescuento=DescuentosEmpresa(pSiscomRegProLPtrEmpresas,
  				    pSiscomRegProLPtrSqlPrim,
				    pSiscomRegProLPtrSqlAct);
   UltimoDescuentoEmpresa(lintIdDescuento,
   			  pSiscomRegProLPtrEmpresas,
   			  pSiscomRegProLPtrSqlPrim,
			  pSiscomRegProLPtrSqlAct);
TelefonoEmpresa(pSiscomRegProLPtrEmpresas,
		pSiscomRegProLPtrSqlPrim,
		pSiscomRegProLPtrSqlAct);
ContactoEmpresa(pSiscomRegProLPtrEmpresas,
		pSiscomRegProLPtrSqlPrim,
		pSiscomRegProLPtrSqlAct);

PlazoEmpresa(pSiscomRegProLPtrEmpresas,
		pSiscomRegProLPtrSqlPrim,
		pSiscomRegProLPtrSqlAct);
IvaEmpresa(pSiscomRegProLPtrEmpresas,
		pSiscomRegProLPtrSqlPrim,
		pSiscomRegProLPtrSqlAct);

}
}

void IvaEmpresa(SiscomRegistroProL *pSiscomRegProLPtrEmpresa,
		     SiscomRegistroProL **pSiscomRegProLPtrSqlPrim,
		     SiscomRegistroProL **pSiscomRegProLPtrSqlAct)
{
char lchrArrSql[256],
	lchrArrBuffer[256];
  sprintf(lchrArrSql,
  	  "insert into IvaEmpresa values(%s,%s);",
	SiscomObtenCampoRegistroProLChar("Prv_Cve",pSiscomRegProLPtrEmpresa),
	SiscomObtenCampoRegistroProLChar("Prv_IVA",pSiscomRegProLPtrEmpresa));
SiscomAnexaRegistroPro(pSiscomRegProLPtrSqlPrim,
		       pSiscomRegProLPtrSqlAct,
		       lchrArrBuffer,
		       "SentenciaSql,EstadoRegistro",
		       lchrArrSql,
		       0);
}
void PlazoEmpresa(SiscomRegistroProL *pSiscomRegProLPtrEmpresa,
		     SiscomRegistroProL **pSiscomRegProLPtrSqlPrim,
		     SiscomRegistroProL **pSiscomRegProLPtrSqlAct)
{
char lchrArrSql[256],
	lchrArrBuffer[256];
  sprintf(lchrArrSql,
  	  "insert into PlazoEmpresa values(%s,%s);",
	SiscomObtenCampoRegistroProLChar("Prv_Cve",pSiscomRegProLPtrEmpresa),
	SiscomObtenCampoRegistroProLChar("Prv_Plazo",pSiscomRegProLPtrEmpresa));
SiscomAnexaRegistroPro(pSiscomRegProLPtrSqlPrim,
		       pSiscomRegProLPtrSqlAct,
		       lchrArrBuffer,
		       "SentenciaSql,EstadoRegistro",
		       lchrArrSql,
		       0);
}
void ContactoEmpresa(SiscomRegistroProL *pSiscomRegProLPtrEmpresa,
		     SiscomRegistroProL **pSiscomRegProLPtrSqlPrim,
		     SiscomRegistroProL **pSiscomRegProLPtrSqlAct)
{

char lchrArrSql[256],
	lchrArrBuffer[256];
const char *lchrPtrContacto;
lchrPtrContacto=SiscomObtenCampoRegistroProLChar("Prv_Contac",pSiscomRegProLPtrEmpresa);
if(*lchrPtrContacto &&
   *lchrPtrContacto!=' ')
{
  sprintf(lchrArrSql,
  	  "insert into ContactoEmpresa values(%s,'%s');",
	  SiscomObtenCampoRegistroProLChar("Prv_Cve",pSiscomRegProLPtrEmpresa),
	  lchrPtrContacto);
SiscomAnexaRegistroPro(pSiscomRegProLPtrSqlPrim,
		       pSiscomRegProLPtrSqlAct,
		       lchrArrBuffer,
		       "SentenciaSql,EstadoRegistro",
		       lchrArrSql,
		       0);
}
}

void TelefonoEmpresa(SiscomRegistroProL *pSiscomRegProLPtrEmpresa,
		     SiscomRegistroProL **pSiscomRegProLPtrSqlPrim,
		     SiscomRegistroProL **pSiscomRegProLPtrSqlAct)
{
Telefonos("Prv_Tel1",
	pSiscomRegProLPtrEmpresa,
	pSiscomRegProLPtrSqlPrim,
	pSiscomRegProLPtrSqlAct);
Telefonos("Prv_Tel2",
	pSiscomRegProLPtrEmpresa,
	pSiscomRegProLPtrSqlPrim,
	pSiscomRegProLPtrSqlAct);
Telefonos("Prv_Tel3",
	pSiscomRegProLPtrEmpresa,
	pSiscomRegProLPtrSqlPrim,
	pSiscomRegProLPtrSqlAct);
}
void Telefonos(const char *pchrPtrTelefono,
		SiscomRegistroProL *pSiscomRegProLPtrEmpresa,
	      SiscomRegistroProL **pSiscomRegProLPtrSqlPrim,
	      SiscomRegistroProL **pSiscomRegProLPtrSqlAct)
{
int lintIdTelefono;
char lchrArrBuffer[128],
	lchrArrSql[128];
const char *lchrPtrTelefono;
lintIdTelefono=SiscomObtenNumeroUnico();
lchrPtrTelefono=SiscomObtenCampoRegistroProLChar(pchrPtrTelefono,pSiscomRegProLPtrEmpresa);
if(strcmp(lchrPtrTelefono,"0"))
{
  sprintf(lchrArrSql,
  	  "insert into Telefonos(IdTelefono,Telefono) values(%d,'%s');",
	  lintIdTelefono,
	  lchrPtrTelefono);
SiscomAnexaRegistroPro(pSiscomRegProLPtrSqlPrim,
		       pSiscomRegProLPtrSqlAct,
		       lchrArrBuffer,
		       "SentenciaSql,EstadoRegistro",
		       lchrArrSql,
		       0);
  sprintf(lchrArrSql,
  	  "insert into TelefonosEmpresa values(%s,%d);",
	  SiscomObtenCampoRegistroProLChar("Prv_Cve",pSiscomRegProLPtrEmpresa),
	  lintIdTelefono);
SiscomAnexaRegistroPro(pSiscomRegProLPtrSqlPrim,
		       pSiscomRegProLPtrSqlAct,
		       lchrArrBuffer,
		       "SentenciaSql,EstadoRegistro",
		       lchrArrSql,
		       0);
}

}
void UltimoDescuentoEmpresa(int pintIdDescuento,
			SiscomRegistroProL *pSiscomRegProLPtrEmpresa,
		       SiscomRegistroProL **pSiscomRegProLPtrSqlPrim,
		       SiscomRegistroProL **pSiscomRegProLPtrSqlAct)
{
char lchrArrSql[128],
	lchrArrBuffer[128];
sprintf(lchrArrSql,
	"insert into UltimoDescuentoEmpresa values(%s,%d);",
	SiscomObtenCampoRegistroProLChar("Prv_Cve",pSiscomRegProLPtrEmpresa),
	pintIdDescuento);

SiscomAnexaRegistroPro(pSiscomRegProLPtrSqlPrim,
		       pSiscomRegProLPtrSqlAct,
		       lchrArrBuffer,
		       "SentenciaSql,EstadoRegistro",
		       lchrArrSql,
		       0);
}

int DescuentosEmpresa(SiscomRegistroProL *pSiscomRegProLPtrEmpresa,
		       SiscomRegistroProL **pSiscomRegProLPtrSqlPrim,
		       SiscomRegistroProL **pSiscomRegProLPtrSqlAct)
{
char lchrArrSql[128],lchrArrBuffer[1024];
const char *lchrPtrDescuento1,
	   *lchrPtrDescuento2,
	   *lchrPtrDescuento3,
	   *lchrPtrDescuento4;

int lintIdDescuento=SiscomObtenNumeroUnico();
sprintf(lchrArrSql,
	"insert into descuentosempresa values(%d,%s,%s,%s,%s,%s,'%s');",
	lintIdDescuento,
	SiscomObtenCampoRegistroProLChar("Prv_Cve",pSiscomRegProLPtrEmpresa),
	SiscomObtenCampoRegistroProLChar("Prv_Desc1",pSiscomRegProLPtrEmpresa),
	SiscomObtenCampoRegistroProLChar("Prv_Desc2",pSiscomRegProLPtrEmpresa),
	SiscomObtenCampoRegistroProLChar("Prv_Desc3",pSiscomRegProLPtrEmpresa),
	SiscomObtenCampoRegistroProLChar("Prv_Desc4",pSiscomRegProLPtrEmpresa),
	"2016-08-16");
	
SiscomAnexaRegistroPro(pSiscomRegProLPtrSqlPrim,
		       pSiscomRegProLPtrSqlAct,
		       lchrArrBuffer,
		       "SentenciaSql,EstadoRegistro",
		       lchrArrSql,
		       0);
return lintIdDescuento;
}
void DireccionEmpresa(int pintIdDireccion,
		      SiscomRegistroProL *pSiscomRegProLPtrEmpresas,
		      SiscomRegistroProL **pSiscomRegProLPtrSqlPrim,
		      SiscomRegistroProL **pSiscomRegProLPtrSqlAct)
{
char lchrArrSql[128];
char lchrArrBuffer[128];
 sprintf(lchrArrSql,
 	"insert into direccionesempresa values(%s,%d);",
	SiscomObtenCampoRegistroProLChar("Prv_Cve",pSiscomRegProLPtrEmpresas),
	pintIdDireccion);
SiscomAnexaRegistroPro(pSiscomRegProLPtrSqlPrim,
		       pSiscomRegProLPtrSqlAct,
		       lchrArrBuffer,
		       "SentenciaSql,EstadoRegistro",
		       lchrArrSql,
		       0);
}
int DireccionProveedor(SiscomRegistroProL *pSiscomRegProLPtrEmpresa,
		        SiscomRegistroProL **pSiscomRegProLPtrSqlPrim,
			SiscomRegistroProL **pSiscomRegProLPtrSqlAct)
{
char lchrArrBuffer[1024],
	lchrArrSql[1024]; 
int lintIdDireccion=SiscomObtenNumeroUnico();
sprintf(lchrArrSql,
	"insert into direcciones values(%d,'%s','%s','%s','%s','%s',%s,'');",
	lintIdDireccion,
	SiscomObtenCampoRegistroProLChar("Prv_DirCalle",pSiscomRegProLPtrEmpresa),
	"",
	SiscomObtenCampoRegistroProLChar("Prv_DirNoExt",pSiscomRegProLPtrEmpresa),
	SiscomObtenCampoRegistroProLChar("Prv_DirColonia",pSiscomRegProLPtrEmpresa),
	SiscomObtenCampoRegistroProLChar("Prv_DirPobyEdo",pSiscomRegProLPtrEmpresa),
	SiscomObtenCampoRegistroProLChar("Prv_CodPos",pSiscomRegProLPtrEmpresa));
SiscomAnexaRegistroPro(pSiscomRegProLPtrSqlPrim,
		       pSiscomRegProLPtrSqlAct,
		       lchrArrBuffer,
		       "SentenciaSql,EstadoRegistro",
		       lchrArrSql,
		       0);
return lintIdDireccion;
}
/* 
 * TDc_Cve
 * TDc_Nombre
 * TDc_IoP
 * TDc_Mod
 * TDc_Sts
 *
 */

void InsertandoTiposDocumentos(const char *pchrPtrIdTienda,
				SiscomRegistroProL *pSiscomRegProLPtrTiposDocumentos,
				SiscomRegistroProL **pSiscomRegProLPtrSqlPrim,
				SiscomRegistroProL **pSiscomRegProLPtrSqlAct)
{
  InsercionesTiposDocumentos(pSiscomRegProLPtrTiposDocumentos,
  			     pSiscomRegProLPtrSqlPrim,
			     pSiscomRegProLPtrSqlAct);

}
void InsercionesTiposDocumentos(SiscomRegistroProL *pSiscomRegProLPtrTiposDocumentos,
				SiscomRegistroProL **pSiscomRegProLPtrSqlPrim,
				SiscomRegistroProL **pSiscomRegProLPtrSqlAct)
{
int lintContador;

for(lintContador=0;
     pSiscomRegProLPtrTiposDocumentos;
     pSiscomRegProLPtrTiposDocumentos=SiscomSiguienteNodoRegistroProL(pSiscomRegProLPtrTiposDocumentos),
     lintContador++)
{
 TiposDocumentos(lintContador,
 		  pSiscomRegProLPtrTiposDocumentos,
		  pSiscomRegProLPtrSqlPrim,
		  pSiscomRegProLPtrSqlAct);
}
}

void TiposDocumentos(int pintContador,
		     SiscomRegistroProL *pLCSiscomProLPtrDatos,
		     SiscomRegistroProL **pSiscomRegProLPtrSqlPrim,
		     SiscomRegistroProL **pSiscomRegProLPtrSqlAct)
{
char lchrArrSql[256],lchrArrBuffer[256];
sprintf(lchrArrSql,"insert into TipoDocumentos values(%d,%s,'%s','%s','%s','%s');",
	pintContador,
	SiscomObtenCampoRegistroProLChar("TDc_Cve",pLCSiscomProLPtrDatos),
	SiscomObtenCampoRegistroProLChar("TDc_Nombre",pLCSiscomProLPtrDatos),
	SiscomObtenCampoRegistroProLChar("TDc_IoP",pLCSiscomProLPtrDatos),
	SiscomObtenCampoRegistroProLChar("TDc_Mod",pLCSiscomProLPtrDatos),
	SiscomObtenCampoRegistroProLChar("TDc_Sts",pLCSiscomProLPtrDatos));

SiscomAnexaRegistroPro(pSiscomRegProLPtrSqlPrim,
		       pSiscomRegProLPtrSqlAct,
		       lchrArrBuffer,
		       "SentenciaSql,EstadoRegistro,",
		       lchrArrSql,0);
}

/*
 * Con_Cve
 * Con_Nombre
 * Con_NomAbr
 * Con_Signo
 * Con_SoP
 * Con_CxP
 * Con_CxC
 * Con_Inbursa
 * Con_Sts
 *
 */


void InsertandoConceptosExistencias(const char *pchrPtrIdTienda,
				    SiscomRegistroProL *pSiscomRegProLPtrConceptosExistencias,
				    SiscomRegistroProL **pSiscomRegProLPtrSqlPrim,
				    SiscomRegistroProL **pSiscomRegProLPtrSqlAct)
{
  InsercionesConceptosExistencias(pSiscomRegProLPtrConceptosExistencias,
  				  pSiscomRegProLPtrSqlPrim,
				  pSiscomRegProLPtrSqlAct);

}
void InsercionesConceptosExistencias(SiscomRegistroProL *pSiscomRegProLPtrConceptosExistencias,
				    SiscomRegistroProL **pSiscomRegProLPtrSqlPrim,
				    SiscomRegistroProL **pSiscomRegProLPtrSqlAct)
{
int lintContador;

for(lintContador=0;
     pSiscomRegProLPtrConceptosExistencias;
     pSiscomRegProLPtrConceptosExistencias=SiscomSiguienteNodoRegistroProL(pSiscomRegProLPtrConceptosExistencias),
     lintContador++)
{
 ConceptosExistencias(pSiscomRegProLPtrConceptosExistencias,
 		      pSiscomRegProLPtrSqlPrim,
		      pSiscomRegProLPtrSqlAct);
}
}

void ConceptosExistencias(SiscomRegistroProL *pLCSiscomProLPtrDatos,
			  SiscomRegistroProL **pSiscomRegProLPtrSqlPrim,
			  SiscomRegistroProL **pSiscomRegProLPtrSqlAct)
{
char lchrArrSql[256],lchrArrBuffer[256];
sprintf(lchrArrSql,
	"insert into ConceptosExistencias values(%s,'%s','%s',%s,'%s','%s','%s','%s');",
	SiscomObtenCampoRegistroProLChar("Con_Cve",pLCSiscomProLPtrDatos),
	SiscomObtenCampoRegistroProLChar("Con_Nombre",pLCSiscomProLPtrDatos),
	SiscomObtenCampoRegistroProLChar("Con_NomAbr",pLCSiscomProLPtrDatos),
	SiscomObtenCampoRegistroProLChar("Con_Signo",pLCSiscomProLPtrDatos),
	SiscomObtenCampoRegistroProLChar("Con_SoP",pLCSiscomProLPtrDatos),
	SiscomObtenCampoRegistroProLChar("Con_CxP",pLCSiscomProLPtrDatos),
	SiscomObtenCampoRegistroProLChar("Con_CxC",pLCSiscomProLPtrDatos),
	SiscomObtenCampoRegistroProLChar("Con_Inbursa",pLCSiscomProLPtrDatos));

SiscomAnexaRegistroPro(pSiscomRegProLPtrSqlPrim,
		       pSiscomRegProLPtrSqlAct,
		       lchrArrBuffer,
		       "SentenciaSql,EstadoRegistro,",
		       lchrArrSql,0);




}

void Empresas(SiscomRegistroProL *pSiscomRegProLPtrEmpresas,
	      SiscomRegistroProL **pSiscomRegProLPtrSqlPrim,
	      SiscomRegistroProL **pSiscomRegProLPtrSqlAct)
{
char lchrArrSql[256],lchrArrBuffer[256];
 sprintf(lchrArrSql,"insert into empresas values(%s,'%s');",
	SiscomObtenCampoRegistroProLChar("Prv_Cve",pSiscomRegProLPtrEmpresas),
	SiscomObtenCampoRegistroProLChar("Prv_Nombre",pSiscomRegProLPtrEmpresas));
SiscomAnexaRegistroPro(pSiscomRegProLPtrSqlPrim,
		       pSiscomRegProLPtrSqlAct,
		       lchrArrBuffer,
		       "SentenciaSql,EstadoRegistro,",
		       lchrArrSql,0);
}
void Proveedores(SiscomRegistroProL *pSiscomRegProLPtrEmpresas,
		 SiscomRegistroProL **pSiscomRegProLPtrSqlPrim,
		 SiscomRegistroProL **pSiscomRegProLPtrSqlAct)
{

char lchrArrSql[256],lchrArrBuffer[256];
sprintf(lchrArrSql,"insert into proveedores values(%s);",
	SiscomObtenCampoRegistroProLChar("Prv_Cve",pSiscomRegProLPtrEmpresas));

SiscomAnexaRegistroPro(pSiscomRegProLPtrSqlPrim,
		       pSiscomRegProLPtrSqlAct,
		       lchrArrBuffer,
		       "SentenciaSql,EstadoRegistro,",
		       lchrArrSql,0);
}


/* Cia_Cve
 * Tda_Cve
 * Tda_Nombre
 * Tda_NomAbr
 * Tda_Siglas
 * Tda_DirCalle
 * Tda_DirNoExt
 * Tda_DirNoInt
 * Tda_DirColonia
 * Tda_DirPobyEdo
 * Tda_CodPos
 * Tda_LADA
 * Tda_Tel1
 * Tda_Tel2
 * Tda_Tel3
 * Tda_Respon
 * Tda_LoF
 * Tda_Sts
 */

void InsertandoTiendas(const char *pchrPtrIdTienda,
		      SiscomRegistroProL *pSiscomRegProLPtrTiendas,
		      SiscomRegistroProL **pSiscomRegProLPtrSqlPrim,
		      SiscomRegistroProL **pSiscomRegProLPtrSqlAct)
{
  InsercionesTiendas(pSiscomRegProLPtrTiendas,
  		     pSiscomRegProLPtrSqlPrim,
		     pSiscomRegProLPtrSqlAct);

}
void InsercionesTiendas(SiscomRegistroProL *pSiscomRegProLPtrTiendas,
			SiscomRegistroProL **pSiscomRegProLPtrSqlPrim,
			SiscomRegistroProL **pSiscomRegProLPtrSqlAct)
{
for(;
     pSiscomRegProLPtrTiendas;
     pSiscomRegProLPtrTiendas=SiscomSiguienteNodoRegistroProL(pSiscomRegProLPtrTiendas))
{
 Tiendas(pSiscomRegProLPtrTiendas,
 	 pSiscomRegProLPtrSqlPrim,
	 pSiscomRegProLPtrSqlAct);
}
}
void Tiendas(SiscomRegistroProL *pLCSiscomProLPtrDatos,
	     SiscomRegistroProL **pSiscomRegProLPtrSqlPrim,
	     SiscomRegistroProL **pSiscomRegProLPtrSqlAct)
{
char lchrArrSql[256],lchrArrBuffer[256];
sprintf(lchrArrSql,"insert into Tiendas values(%s,'%s','%s','%s');",
	SiscomObtenCampoRegistroProLChar("tda_cve",pLCSiscomProLPtrDatos),
	SiscomObtenCampoRegistroProLChar("tda_nombre",pLCSiscomProLPtrDatos),
	SiscomObtenCampoRegistroProLChar("tda_nomabr",pLCSiscomProLPtrDatos),
	SiscomObtenCampoRegistroProLChar("tda_siglas",pLCSiscomProLPtrDatos));

SiscomAnexaRegistroPro(pSiscomRegProLPtrSqlPrim,
		       pSiscomRegProLPtrSqlAct,
		       lchrArrBuffer,
		       "SentenciaSql,EstadoRegistro,",
		       lchrArrSql,0);
}

/*
 * Ven_Cve
 * Ven_Nombre
 * Ven_NomAbr
 * Ven_Sts
 */

void InsertandoVendedores(const char *pchrPtrIdTienda,
			  SiscomRegistroProL *pSiscomRegProLPtrVendedores,
			  SiscomRegistroProL **pSiscomRegProLPtrSqlPrim,
			  SiscomRegistroProL **pSiscomRegProLPtrSqlAct)
{
  InsercionesVendedores(pSiscomRegProLPtrVendedores,
  			pSiscomRegProLPtrSqlPrim,
			pSiscomRegProLPtrSqlAct);

}
void InsercionesVendedores(SiscomRegistroProL *pSiscomRegProLPtrVendedores,
			   SiscomRegistroProL **pSiscomRegProLPtrSqlPrim,
			   SiscomRegistroProL **pSiscomRegProLPtrSqlAct)
{
int lintContador;
for(lintContador=0;
     pSiscomRegProLPtrVendedores;
     pSiscomRegProLPtrVendedores=SiscomSiguienteNodoRegistroProL(pSiscomRegProLPtrVendedores),
     lintContador++)
{
 if(Personas(lintContador,
 	     pSiscomRegProLPtrVendedores,
	     pSiscomRegProLPtrSqlPrim,
	     pSiscomRegProLPtrSqlAct))
 Vendedores(lintContador,
 	    pSiscomRegProLPtrVendedores,
	    pSiscomRegProLPtrSqlPrim,
	    pSiscomRegProLPtrSqlAct);

}
}
int Personas(int pintIdVendedor,
		SiscomRegistroProL *pLCSiscomProLPtrDatos,
		SiscomRegistroProL **pSiscomRegProLPtrSqlPrim,
		SiscomRegistroProL **pSiscomRegProLPtrSqlAct)
{

char lchrArrSql[256],lchrArrBuffer[256];
char **lchrPtrCamposNombre;
int lintNCampos;
const char *lchrPtrNombre=SiscomObtenCampoRegistroProLChar("Ven_Nombre",pLCSiscomProLPtrDatos);
lintNCampos=SiscomAnalizaCadenas(lchrPtrNombre,' ',lchrArrBuffer,&lchrPtrCamposNombre);

if(lintNCampos==3)
sprintf(lchrArrSql,"insert into Personas values(%d,'%s','%s','%s');",
	pintIdVendedor,
	*(lchrPtrCamposNombre+0),
	*(lchrPtrCamposNombre+1),
	*(lchrPtrCamposNombre+2));
else
if(lintNCampos==2)
sprintf(lchrArrSql,"insert into Personas values(%d,'%s','%s','%s');",
	pintIdVendedor,
	*(lchrPtrCamposNombre+0),
	*(lchrPtrCamposNombre+1),
	"");
else
if(lintNCampos==1)
sprintf(lchrArrSql,"insert into Personas values(%d,'%s','%s','%s');",
	pintIdVendedor,
	*(lchrPtrCamposNombre+0),
	"",
	"");
SiscomAnexaRegistroPro(pSiscomRegProLPtrSqlPrim,
		       pSiscomRegProLPtrSqlAct,
		       lchrArrBuffer,
		       "SentenciaSql,EstadoRegistro,",
		       lchrArrSql,0);
return lintNCampos==1 ||
       lintNCampos==2 ||
       lintNCampos==3 ;
}
void Vendedores(int pintIdVendedor,
		SiscomRegistroProL *pLCSiscomProLPtrDatos,
		SiscomRegistroProL **pSiscomRegProLPtrSqlPrim,
		SiscomRegistroProL **pSiscomRegProLPtrSqlAct)
{

char lchrArrSql[256],lchrArrBuffer[256];
sprintf(lchrArrSql,"insert into vendedores values(%d,'%s','%s');",
	pintIdVendedor,
	SiscomObtenCampoRegistroProLChar("Ven_Cve",pLCSiscomProLPtrDatos),
	SiscomObtenCampoRegistroProLChar("Ven_NomAbr",pLCSiscomProLPtrDatos));
SiscomAnexaRegistroPro(pSiscomRegProLPtrSqlPrim,
		       pSiscomRegProLPtrSqlAct,
		       lchrArrBuffer,
		       "SentenciaSql,EstadoRegistro,",
		       lchrArrSql,0);
}
void PersonaVendedor(int pintIdVendedor,
		SiscomRegistroProL *pLCSiscomProLPtrDatos,
		SiscomRegistroProL **pSiscomRegProLPtrSqlPrim,
		SiscomRegistroProL **pSiscomRegProLPtrSqlAct)

{
char lchrArrSql[256],lchrArrBuffer[256];
sprintf(lchrArrSql,
	"insert into vendedores values(%d,'%s','%s');",
	pintIdVendedor,
	SiscomObtenCampoRegistroProLChar("Ven_Cve",pLCSiscomProLPtrDatos),
	SiscomObtenCampoRegistroProLChar("Ven_NomAbr",pLCSiscomProLPtrDatos));
SiscomAnexaRegistroPro(pSiscomRegProLPtrSqlPrim,
		       pSiscomRegProLPtrSqlAct,
		       lchrArrBuffer,
		       "SentenciaSql,EstadoRegistro,",
		       lchrArrSql,0);
}

/*
 * select * from tgcdep
 * Cia_Cve
 * Dep_Cve
 * Dep_Nombre
 */

void InsertandoDepartamentos(const char *pchrPtrIdTienda,
				SiscomRegistroProL *pSiscomRegProLPtrDepartamentos,
			 SiscomRegistroProL **pSiscomRegProLPtrSqlPrim,
			 SiscomRegistroProL **pSiscomRegProLPtrSqlAct)
{

  InsercionesDepartamentos(pSiscomRegProLPtrDepartamentos,
  			pSiscomRegProLPtrSqlPrim,
			pSiscomRegProLPtrSqlAct);

}
void InsercionesDepartamentos(SiscomRegistroProL *pSiscomRegProLPtrDepartamentos,
			 SiscomRegistroProL **pSiscomRegProLPtrSqlPrim,
			 SiscomRegistroProL **pSiscomRegProLPtrSqlAct)
{
int lintContador;
for(lintContador=1;
     pSiscomRegProLPtrDepartamentos;
     pSiscomRegProLPtrDepartamentos=SiscomSiguienteNodoRegistroProL(pSiscomRegProLPtrDepartamentos),
     lintContador++)
{
    Departamentos(lintContador,pSiscomRegProLPtrDepartamentos,
  			pSiscomRegProLPtrSqlPrim,
			pSiscomRegProLPtrSqlAct);
}
}

void Departamentos(int pintContador,SiscomRegistroProL *pSiscomRegProLPtrDepartamento,
			 SiscomRegistroProL **pSiscomRegProLPtrSqlPrim,
			 SiscomRegistroProL **pSiscomRegProLPtrSqlAct)
{

char lchrArrSql[256],lchrArrBuffer[256];
  sprintf(lchrArrSql,"insert into Departamentos values(%d,'%s','%s');",
  	 pintContador,
  	 SiscomObtenCampoRegistroProLChar("Dep_Nombre",pSiscomRegProLPtrDepartamento),
  	 SiscomObtenCampoRegistroProLChar("Dep_NomAbr",pSiscomRegProLPtrDepartamento));

SiscomAnexaRegistroPro(pSiscomRegProLPtrSqlPrim,
		       pSiscomRegProLPtrSqlAct,
		       lchrArrBuffer,
		       "SentenciaSql,EstadoRegistro,",
		       lchrArrSql,0);

}

void AsignandoProductosDepartamentos(const char *pchrPtrIdTienda,
				     SiscomRegistroProL *pSiscomRegProLPtrDepartamentos,
			 	     SiscomRegistroProL **pSiscomRegProLPtrSqlPrim,
			 	     SiscomRegistroProL **pSiscomRegProLPtrSqlAct)
{
SiscomRegistroProL *lSiscomRegProLPtrDepPrim=0,
		   *lSiscomRegProLPtrDepAct=0;
char lchrArrBuffer[128];
for(;
    pSiscomRegProLPtrDepartamentos;
    pSiscomRegProLPtrDepartamentos=pSiscomRegProLPtrDepartamentos->SiscomRegProLPtrSig)
{
     if(SiscomEstaElCampo("Dep_Cve",pSiscomRegProLPtrDepartamentos) &&
        SiscomEstaElCampo("Prd_Cve",pSiscomRegProLPtrDepartamentos))
      	SiscomAnexaRegistroPro2(&lSiscomRegProLPtrDepPrim,
				&lSiscomRegProLPtrDepAct,
				pSiscomRegProLPtrDepartamentos);
}

if(!*pSiscomRegProLPtrSqlPrim)
SiscomAnexaRegistroPro(pSiscomRegProLPtrSqlPrim,
		       pSiscomRegProLPtrSqlAct,
		       lchrArrBuffer,
		       "SentenciaSql,EstadoRegistro,",
		       0,
		       0);
SiscomAgregaCampoRegistros("ProductosDepartamento",0,*pSiscomRegProLPtrSqlAct);
SiscomRegistrosAlCampo("ProductosDepartamento",
			lSiscomRegProLPtrDepPrim,
			lSiscomRegProLPtrDepAct,
			*pSiscomRegProLPtrSqlAct);
}
void ActualizaExistenciasTiendas(const char *pchrPtrIdTienda,
				SiscomRegistroProL *pSiscomRegProLPtrExistencias,
			 SiscomRegistroProL **pSiscomRegProLPtrSqlPrim,
			 SiscomRegistroProL **pSiscomRegProLPtrSqlAct)
{
char lchrArrSql[512],lchrArrBuffer[512];
if(!SiscomComparaCadenaCampoRegistroProL(pchrPtrIdTienda,
				        "Tda",
					pSiscomRegProLPtrExistencias))
{
  if(SiscomObtenCampoRegistroProLInt("Stk",pSiscomRegProLPtrExistencias)>0) 
{
sprintf(lchrArrSql,
	"insert into productostock (select idproducto 				\n\
				    from productos inner join 			\n\
				         productoproveedor using(idproducto)	\n\
				  where idempresa=%s and numproducto=%s);",
	SiscomObtenCampoRegistroProLChar("Prov",pSiscomRegProLPtrExistencias),
	SiscomObtenCampoRegistroProLChar("Prod",pSiscomRegProLPtrExistencias));


SiscomAnexaRegistroPro(pSiscomRegProLPtrSqlPrim,
		       pSiscomRegProLPtrSqlAct,
		       lchrArrBuffer,
		       "SentenciaSql,EstadoRegistro,",
		       lchrArrSql,0);
}
sprintf(lchrArrSql,
	"update stock set Existencia=%s 					\n\
	where idproducto in (select idproducto 					\n\
			     from productos inner join 				\n\
				  productoproveedor using(idproducto) 		\n\
			     where idempresa=%s and numproducto=%s);",
  	    SiscomObtenCampoRegistroProLChar("Stk",pSiscomRegProLPtrExistencias),
  	    SiscomObtenCampoRegistroProLChar("Prov",pSiscomRegProLPtrExistencias),
  	    SiscomObtenCampoRegistroProLChar("Prod",pSiscomRegProLPtrExistencias));
	 
SiscomAnexaRegistroPro(pSiscomRegProLPtrSqlPrim,
		       pSiscomRegProLPtrSqlAct,
		       lchrArrBuffer,
		       "SentenciaSql,EstadoRegistro,",
		       lchrArrSql,0);
sprintf(lchrArrSql,
	"update existencia set Existencia=%s 					\n\
	where idproducto in (select idproducto 					\n\
			     from productos inner join 				\n\
				  productoproveedor using(idproducto) 		\n\
			     where idempresa=%s and numproducto=%s);",
  	    SiscomObtenCampoRegistroProLChar("Existencia",pSiscomRegProLPtrExistencias),
  	    SiscomObtenCampoRegistroProLChar("Prov",pSiscomRegProLPtrExistencias),
  	    SiscomObtenCampoRegistroProLChar("Prod",pSiscomRegProLPtrExistencias));
SiscomAnexaRegistroPro(pSiscomRegProLPtrSqlPrim,
		       pSiscomRegProLPtrSqlAct,
		       lchrArrBuffer,
		       "SentenciaSql,EstadoRegistro,",
		       lchrArrSql,0);
}

}
void ActualizandoExistenciasTienda(const char *pchrPtrIdTienda,
				SiscomRegistroProL *pSiscomRegProLPtrExistencias,
			 SiscomRegistroProL **pSiscomRegProLPtrSqlPrim,
			 SiscomRegistroProL **pSiscomRegProLPtrSqlAct)
{
   for(;
   	pSiscomRegProLPtrExistencias;
	pSiscomRegProLPtrExistencias=SiscomSiguienteNodoRegistroProL(pSiscomRegProLPtrExistencias))
     ActualizaExistenciasTiendas(pchrPtrIdTienda,pSiscomRegProLPtrExistencias,
  			pSiscomRegProLPtrSqlPrim,
			pSiscomRegProLPtrSqlAct);
}

void InsertandoCreditosMaestros(const char *pchrPtrIdTienda,
				SiscomRegistroProL *pSiscomRegProLPtrExistencias,
			 	SiscomRegistroProL **pSiscomRegProLPtrSqlPrim,
			 	SiscomRegistroProL **pSiscomRegProLPtrSqlAct)
{
   for(;
   	pSiscomRegProLPtrExistencias;
	pSiscomRegProLPtrExistencias=SiscomSiguienteNodoRegistroProL(pSiscomRegProLPtrExistencias))
     InsertaCreditoMaestro(pchrPtrIdTienda,pSiscomRegProLPtrExistencias,
  			pSiscomRegProLPtrSqlPrim,
			pSiscomRegProLPtrSqlAct);
}
void InsertaPersona(int pintIdPersona,
		    SiscomRegistroProL *pSiscomRegProLPtrCliente,
			 SiscomRegistroProL **pSiscomRegProLPtrSqlPrim,
			 SiscomRegistroProL **pSiscomRegProLPtrSqlAct)
{

char lchrArrSql[256],lchrArrBuffer[256];
SiscomEliminaEspaciosFinalCampo("Nombre-1",pSiscomRegProLPtrCliente);
SiscomEliminaEspaciosFinalCampo("Nombre-2",pSiscomRegProLPtrCliente);
SiscomEliminaEspaciosFinalCampo("Paterno",pSiscomRegProLPtrCliente);
SiscomEliminaEspaciosFinalCampo("Materno",pSiscomRegProLPtrCliente);
if(SiscomCampoRegistroProLCharEsVacio("Nombre-2",pSiscomRegProLPtrCliente))
sprintf(lchrArrSql,
	"insert into Personas values(%d,'%s','%s','%s','%s');",
       pintIdPersona,
       SiscomObtenCampoRegistroProLChar("Nombre-1",pSiscomRegProLPtrCliente),
       SiscomObtenCampoRegistroProLChar("Paterno",pSiscomRegProLPtrCliente),
       SiscomObtenCampoRegistroProLChar("Materno",pSiscomRegProLPtrCliente),
       SiscomObtenCampoRegistroProLChar("R.F.C.",pSiscomRegProLPtrCliente));
else
sprintf(lchrArrSql,"insert into Personas values(%d,'%s %s','%s','%s','%s');",
       pintIdPersona,
       SiscomObtenCampoRegistroProLChar("Nombre-1",pSiscomRegProLPtrCliente),
       SiscomObtenCampoRegistroProLChar("Nombre-2",pSiscomRegProLPtrCliente),
       SiscomObtenCampoRegistroProLChar("Paterno",pSiscomRegProLPtrCliente),
       SiscomObtenCampoRegistroProLChar("Materno",pSiscomRegProLPtrCliente),
       SiscomObtenCampoRegistroProLChar("R.F.C.",pSiscomRegProLPtrCliente));
SiscomAnexaRegistroPro(pSiscomRegProLPtrSqlPrim,
		       pSiscomRegProLPtrSqlAct,
		       lchrArrBuffer,
		       "SentenciaSql,EstadoRegistro,",
		       lchrArrSql,0);
}

void InsertandoRFCsCreditos(const char *pchrPtrIdTienda,
				SiscomRegistroProL *pSiscomRegProLPtrExistencias,
			 	SiscomRegistroProL **pSiscomRegProLPtrSqlPrim,
			 	SiscomRegistroProL **pSiscomRegProLPtrSqlAct)
{
char lchrArrBuffer[4192],lchrArrSql[256];

   for(;
   	pSiscomRegProLPtrExistencias;
	pSiscomRegProLPtrExistencias=SiscomSiguienteNodoRegistroProL(pSiscomRegProLPtrExistencias))
{
sprintf(lchrArrSql,
	"insert into rfcbasedatos values('%s');",
       SiscomObtenCampoRegistroProLChar("rfc",pSiscomRegProLPtrExistencias));

SiscomAnexaRegistroPro(pSiscomRegProLPtrSqlPrim,
		       pSiscomRegProLPtrSqlAct,
		       lchrArrBuffer,
		       "SentenciaSql,EstadoRegistro,",
		       lchrArrSql,0);
}
}

void InsertaDireccion(int pintIdPersona,
		      SiscomRegistroProL *pSiscomRegProLPtrCliente,
			 SiscomRegistroProL **pSiscomRegProLPtrSqlPrim,
			 SiscomRegistroProL **pSiscomRegProLPtrSqlAct)
{
char lchrArrSql[256],lchrArrBuffer[256];
int lintIdDireccion;
lintIdDireccion=SiscomObtenNumeroUnico();
sprintf(lchrArrSql,
	"insert into Direcciones values (%d,'%s','%s','%s','%s','%s','%s','%s','%s');",
	lintIdDireccion,
       SiscomObtenCampoRegistroProLChar("Calle",pSiscomRegProLPtrCliente),
       SiscomObtenCampoRegistroProLChar("Interior",pSiscomRegProLPtrCliente),
       SiscomObtenCampoRegistroProLChar("#/Ext",pSiscomRegProLPtrCliente),
       SiscomObtenCampoRegistroProLChar("Colonia",pSiscomRegProLPtrCliente),
       "",
       "",
       SiscomObtenCampoRegistroProLChar("C.P.",pSiscomRegProLPtrCliente),
       "");

SiscomAnexaRegistroPro(pSiscomRegProLPtrSqlPrim,
		       pSiscomRegProLPtrSqlAct,
		       lchrArrBuffer,
		       "SentenciaSql,EstadoRegistro,",
		       lchrArrSql,0);
sprintf(lchrArrSql,
	"insert into DireccionesCliente values(%d,%d);",
	pintIdPersona,
	lintIdDireccion);

SiscomAnexaRegistroPro(pSiscomRegProLPtrSqlPrim,
		       pSiscomRegProLPtrSqlAct,
		       lchrArrBuffer,
		       "SentenciaSql,EstadoRegistro,",
		       lchrArrSql,0);
}
void SiscomCadenasEntreDosSeparadores(const char *pchrPtrCadena,
				      char pchrSeparador,
				      char *pchrPtrCadena1,
				      char *pchrPtrCadena2,
				      char *pchrPtrCadena3)
{
/*
int lintNSeparador=0;
LogSiscom("(%s)",pchrPtrCadena);
   while(*pchrPtrCadena)
   {
        while(*pchrPtrCadena!=pchrSeparador)
	{
	 if(!lintNSeparador)
	 {
	 *pchrPtrCadena1=*pchrPtrCadena;
	 pchrPtrCadena1++;
	 }
	 if(lintNSeparador==1)
	 {
	    *pchrPtrCadena2=*pchrPtrCadena;
	    pchrPtrCadena2++;
	 }
	 if(lintNSeparador==2)
	 {
	   *pchrPtrCadena3=*pchrPtrCadena;
	   pchrPtrCadena3++;
	 }

	 pchrPtrCadena++;
	}
	if(!lintNSeparador)
	{
	  lintNSeparador++;
	  *pchrPtrCadena1=0;
	  LogSiscom("Se Asigna Cadena 1");
	}
	if(lintNSeparador==1)
	{
	   lintNSeparador++;
	   *pchrPtrCadena2=0;
	  LogSiscom("Se Asigna Cadena 2");
	}
	if(lintNSeparador==2)
	{
	     *pchrPtrCadena3=0;
	     LogSiscom("Se Asigna Cadena 3 (%d) %s",*pchrPtrCadena,pchrPtrCadena);
	}
	pchrPtrCadena++;
   }
*/


}
int CambiaFormatoFecha(SiscomRegistroProL *pSiscomRegProLPtrCliente,
			char *pchrPtrFecha)
{
char **lchrPtrCampos;
char lchrArrBuffer[28];
/*
char lchrArrDia[3],
	lchrArrMes[3],
	lchrArrA[5];
*/
const char *lchrPtrFecha=SiscomObtenCampoRegistroProLChar("F/Factura",pSiscomRegProLPtrCliente);
if(lchrPtrFecha)
{
if(SiscomAnalizaCadenas(lchrPtrFecha,'/',lchrArrBuffer,&lchrPtrCampos))
{
   if(lchrPtrCampos[0] &&
      lchrPtrCampos[1] &&
      lchrPtrCampos[2])
   {
   sprintf(pchrPtrFecha,
   	   "%04d-%02d-%02d",
	   atoi(lchrPtrCampos[2]),
	   atoi(lchrPtrCampos[0]),
	   atoi(lchrPtrCampos[1]));
     SiscomLiberaCadenas(lchrPtrCampos);
     return 1;
     }
     else
     return 0;
}
}
}
int CambiaImportePrecioANumero(SiscomRegistroProL *pSiscomRegProLPtrCliente,
			       char *pchrPtrMonto)
{
char lchrArrBuffer[12];
char *lchrPtrMonto;
lchrPtrMonto=(char *)SiscomObtenCampoRegistroProLChar("Importe Fac.",pSiscomRegProLPtrCliente);
if(lchrPtrMonto)
{
SiscomEliminaCaracterCadena('$',lchrPtrMonto,lchrArrBuffer);
SiscomEliminaCaracterCadena(',',lchrArrBuffer,pchrPtrMonto);
}
}
void InsertaVentaACredito(int pintIdVenta,
			  SiscomRegistroProL *pSiscomRegProLPtrCliente,
			 SiscomRegistroProL **pSiscomRegProLPtrSqlPrim,
			 SiscomRegistroProL **pSiscomRegProLPtrSqlAct)
{

char lchrArrSql[1024],lchrArrBuffer[1024];
int lintIdFinanciera=ObtenFinanciera(pSiscomRegProLPtrCliente);

if(!SiscomComparaCadenaCampoRegistroProL("12","Plazo",pSiscomRegProLPtrCliente))
sprintf(lchrArrSql,
	"insert into VentaCredito values(%d,%d,2,0,0);",
	pintIdVenta,
	lintIdFinanciera);
if(!SiscomComparaCadenaCampoRegistroProL("18","Plazo",pSiscomRegProLPtrCliente))
sprintf(lchrArrSql,
	"insert into VentaCredito values(%d,%d,2,0,0);",
	pintIdVenta,
	lintIdFinanciera);
if(!SiscomComparaCadenaCampoRegistroProL("24","Plazo",pSiscomRegProLPtrCliente))
sprintf(lchrArrSql,
	"insert into VentaCredito values(%d,%d,2,0,0);",
	pintIdVenta,
	lintIdFinanciera);

SiscomAnexaRegistroPro(pSiscomRegProLPtrSqlPrim,
		       pSiscomRegProLPtrSqlAct,
		       lchrArrBuffer,
		       "SentenciaSql,EstadoRegistro,",
		       lchrArrSql,0);

}
void InsertaVentaCredito(int pintIdCliente,
			 SiscomRegistroProL *pSiscomRegProLPtrCliente,
			 SiscomRegistroProL **pSiscomRegProLPtrSqlPrim,
			 SiscomRegistroProL **pSiscomRegProLPtrSqlAct)
{
char lchrArrSql[256],lchrArrBuffer[256];
int lintIdVenta;
char lchrArrFecha[28],lchrArrMonto[12];

lintIdVenta=SiscomObtenNumeroUnico();
CambiaFormatoFecha(pSiscomRegProLPtrCliente,lchrArrFecha);
CambiaImportePrecioANumero(pSiscomRegProLPtrCliente,lchrArrMonto);
sprintf(lchrArrSql,"insert into ventas values(%d,%d,2,1,'%s','','%s');",
	lintIdVenta,
	pintIdCliente,
       SiscomObtenCampoRegistroProLChar("Factura",pSiscomRegProLPtrCliente),
       lchrArrFecha);

SiscomAnexaRegistroPro(pSiscomRegProLPtrSqlPrim,
		       pSiscomRegProLPtrSqlAct,
		       lchrArrBuffer,
		       "SentenciaSql,EstadoRegistro,",
		       lchrArrSql,0);
sprintf(lchrArrSql,"insert into ImporteVenta(IdVenta,Total) values(%d,%s);",
	lintIdVenta,
	lchrArrMonto);

SiscomAnexaRegistroPro(pSiscomRegProLPtrSqlPrim,
		       pSiscomRegProLPtrSqlAct,
		       lchrArrBuffer,
		       "SentenciaSql,EstadoRegistro,",
		       lchrArrSql,0);
InsertaVentaACredito(lintIdVenta,
		pSiscomRegProLPtrCliente,
		pSiscomRegProLPtrSqlPrim,
		pSiscomRegProLPtrSqlAct);
	
}
void InsertaCliente(int pintIdPersona,
			 SiscomRegistroProL **pSiscomRegProLPtrSqlPrim,
			 SiscomRegistroProL **pSiscomRegProLPtrSqlAct)
{
char lchrArrSql[256],lchrArrBuffer[256];
sprintf(lchrArrSql,"insert into Clientes values(%d,'%d');",pintIdPersona,pintIdPersona);
SiscomAnexaRegistroPro(pSiscomRegProLPtrSqlPrim,
		       pSiscomRegProLPtrSqlAct,
		       lchrArrBuffer,
		       "SentenciaSql,EstadoRegistro,",
		       lchrArrSql,0);
}
		   
int ObtenFinanciera(SiscomRegistroProL *pSiscomRegProLPtrRegistro)
{
char lchrArrBuffer[512];
   if(SiscomBuscaCadenaCampoRegistroProL("Hidalgo",
   					  "Seccion",
					  pSiscomRegProLPtrRegistro))
   return 3;
   else
   if(SiscomBuscaCadenaCampoRegistroProL("Tlaxcala",
   					  "Seccion",
					  pSiscomRegProLPtrRegistro))
   return 3;
   if(SiscomBuscaCadenaCampoRegistroProL("Puebla",
   					  "Seccion",
					  pSiscomRegProLPtrRegistro))
   return 4;
}
void InsertaCreditoMaestro(const char *pchrPtrIdTienda,
			   SiscomRegistroProL *pSiscomRegProLPtrExistencias,
			 SiscomRegistroProL **pSiscomRegProLPtrSqlPrim,
			 SiscomRegistroProL **pSiscomRegProLPtrSqlAct)
{
int lintIdPersona;
char lchrArrFecha[12];
/*
if(!SiscomComparaCadenaCampoRegistroProL(pchrPtrIdTienda,
				        "Tda",
					pSiscomRegProLPtrExistencias))
*/
{
lintIdPersona=SiscomObtenNumeroUnico();
InsertaPersona(lintIdPersona,pSiscomRegProLPtrExistencias,
  			pSiscomRegProLPtrSqlPrim,
			pSiscomRegProLPtrSqlAct);
InsertaCliente(lintIdPersona,
  			pSiscomRegProLPtrSqlPrim,
			pSiscomRegProLPtrSqlAct);
InsertaDireccion(lintIdPersona,pSiscomRegProLPtrExistencias,
  			pSiscomRegProLPtrSqlPrim,
			pSiscomRegProLPtrSqlAct);
InsertaVentaCredito(lintIdPersona,pSiscomRegProLPtrExistencias,
  			pSiscomRegProLPtrSqlPrim,
			pSiscomRegProLPtrSqlAct);
}
}


void InsertaRFCsCreditos(SiscomRegistroProL **pSiscomRegProLPtrSqlPrim,
			 SiscomRegistroProL **pSiscomRegProLPtrSqlAct)
{

/*
SiscomBuscaArchivos(const char *pchrPtrDirectorio,
			 const char *pchrPtrCadenaNombre,
			 const char *pchrPtrExtension,
			 SiscomArchivosDirectorio **pLNArchivoPrim,
			 SiscomArchivosDirectorio **pLNArchivoActual)
*/
}

