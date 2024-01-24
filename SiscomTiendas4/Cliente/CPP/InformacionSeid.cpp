#include <InformacionSeid.h>
#include <CQSisFamilias.h>
#include <CQSisOpTiendas4.h>
#include <CQSisProductos.h>
#include <CQSisEmpresas2.h>
#include <CQSisEmpresas.h>
#include <CQSisCompras.h>
#include <CQSisFormaPago.h>
#include <CQSisContactos.h>
#include <CQSisPrecios.h>
#include <CQSisDatoPrecio.h>
#include <SisPersonas.h>
extern "C" 
{
#include <SiscomDesarrollo2.h>
}
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>

int errno;
FILE *gPtrFleArchivoLog3Qt;
FILE *gPtrFleArchivoLog;
/*
 * Consideracion para el formato
 * Que inicie con una Familia
 * El registro vacio esta formado por 43 tabuladores 
 * La posicion del Producto Clave 5 y descripcion 8
 *
 * Los datos de comunicacion del proveedor y contactos 
 * se insertaran por separado
 */

int gintPosClave=5;

int gintPosRSocialProveedor=21;
int gintPosContactoProveedor=22;
int gintPosTelefonoProveedor=23;
int gintPosTelefono2Proveedor=24;
int gintPosCorreoProveedor=25;
int gintPosPrecioMenudeo=31;
int gintPosPrecioMayoreo=34;
int gintPosPrecioDistribuidor=38;
int gintPosPrecioEstudiantes=42;
int gintPosPrecioCompra=16;
int gintPosCantidadCompra=17;


int gintPosCantidadMayoreo=36;
int gintPosCantidadDistribuidor=40;

const char *gchrPtrPrecioMayoreo="1306150861";
const char *gchrPtrPrecioMenudeo="1305950209";
const char *gchrPtrPrecioDistribuidor="1306272740";
const char *gchrPtrPrecioEstudiantes="1306150561";

int main(int pintArgc,
	 char **pchrPtrArgv)
{
FILE *lFlePtrArchivo;
SiscomDatCom *lSisDatCom=new SiscomDatCom(5650,"127.0.0.1");
gPtrFleArchivoLog3Qt=stdout;
gPtrFleArchivoLog=stdout;
AbreArchivo(pchrPtrArgv[1],&lFlePtrArchivo);
if(!strcmp(pchrPtrArgv[2],"RegistraFamilias"))
RegistraFamilias(lFlePtrArchivo,lSisDatCom);
if(!strcmp(pchrPtrArgv[2],"RegistraProductos"))
RegistrandoProductos(lFlePtrArchivo,lSisDatCom);
if(!strcmp(pchrPtrArgv[2],"RegistraProveedores"))
RegistrandoProveedores(lFlePtrArchivo,lSisDatCom);
if(!strcmp(pchrPtrArgv[2],"RegistraCompras"))
RegistrandoCompras(lFlePtrArchivo,lSisDatCom);
if(!strcmp(pchrPtrArgv[2],"RegistraPrecios"))
RegistrandoPrecios(lFlePtrArchivo,lSisDatCom);
}
void RegistrandoPrecios(FILE *pFlePtrArchivo,
			SiscomDatCom *pSisDatCom)
{
CQSisLstProducto lCQSLProductos;
ObtenProductos(pSisDatCom,&lCQSLProductos); 
RegistraPrecios(pFlePtrArchivo,pSisDatCom,&lCQSLProductos);
}
void RegistraPrecios(FILE *pFlePtrArchivo,
		     SiscomDatCom *pSisDatCom,
		     CQSisLstProducto *pCQSLProductos)
{
char lchrArrLinea[2048];
char lchrArrBuffer[2048];
char **lchrPtrCampos;
CQSisFamilia *lCQSFamilia;
char lchrArrFamilia[56];
char lchrArrIdFamilia[10];
SiscomLog("Analizando El Formato Seid");
while(!SiscomLeeLineaArchivo(pFlePtrArchivo,lchrArrLinea))
{
SiscomAnalizaCadenas(lchrArrLinea,
		     '\t',
		     lchrArrBuffer,
		     &lchrPtrCampos);
 if(EsRenglonFamilia2(lchrPtrCampos))
 {
 	SiscomLog("Familia:%s",lchrPtrCampos[1]);
       SiscomLeeLineaArchivo(pFlePtrArchivo,lchrArrLinea);
 }
 
ObtenPreciosProducto(pFlePtrArchivo,
	      pSisDatCom,
	      pCQSLProductos);
SiscomLeeLineaArchivo(pFlePtrArchivo,lchrArrLinea);

}
}
void ObtenPreciosProducto(FILE *pFlePtrArchivo,
			  SiscomDatCom *pSisDatCom,
			  CQSisLstProducto *pCQSLProductos)
{
char **lchrPtrCampos;
char lchrArrCadena[2048];
char lchrArrBuffer[2048];
while(!SiscomLeeLineaArchivo(pFlePtrArchivo,lchrArrCadena))
{
    SiscomAnalizaCadenas(lchrArrCadena,
    			 '\t',
			 lchrArrBuffer,
			 &lchrPtrCampos);
   if(RegistroVacio(lchrPtrCampos))
    break;
   else
   FormaPrecio(lchrPtrCampos,
   		pSisDatCom,
		pCQSLProductos);

}

}
void FormaPrecioMayoreo(const char *pchrPtrPrecioM,
			const char *pchrPtrCantidad,
			CQSisProducto *pCQSProducto,
			SiscomDatCom *pSisDatCom)
{
CQSisPrecio *lCQSPrecio=new CQSisPrecio(gchrPtrPrecioMayoreo,
					"",
					"");
CQSisOpTiendas4 lCQSOT4APrecio(pSisDatCom);
	lCQSOT4APrecio.ActualizaPrecioProducto(pCQSProducto,
			 new CQSisDatoPrecio(
			 	lCQSPrecio,
				pchrPtrPrecioM,
				pchrPtrCantidad));
}
void FormaPrecioMenudeo(const char *pchrPtrPrecioM,
			const char *pchrPtrCantidad,
			CQSisProducto *pCQSProducto,
			SiscomDatCom *pSisDatCom)
{
CQSisPrecio *lCQSPrecio=new CQSisPrecio(gchrPtrPrecioMenudeo,
					"",
					"");
CQSisOpTiendas4 lCQSOT4APrecio(pSisDatCom);
	lCQSOT4APrecio.ActualizaPrecioProducto(pCQSProducto,
			 new CQSisDatoPrecio(
			 	lCQSPrecio,
				pchrPtrPrecioM,
				pchrPtrCantidad));

}


void FormaPrecioDistribuidor(const char *pchrPtrPrecioM,
			const char *pchrPtrCantidad,
			CQSisProducto *pCQSProducto,
			SiscomDatCom *pSisDatCom)
{
CQSisPrecio *lCQSPrecio=new CQSisPrecio(gchrPtrPrecioDistribuidor,
					"",
					"");
CQSisOpTiendas4 lCQSOT4APrecio(pSisDatCom);
	lCQSOT4APrecio.ActualizaPrecioProducto(pCQSProducto,
			 new CQSisDatoPrecio(
			 	lCQSPrecio,
				pchrPtrPrecioM,
				pchrPtrCantidad));

}

void FormaPrecioEstudiante(const char *pchrPtrPrecioM,
			const char *pchrPtrCantidad,
			CQSisProducto *pCQSProducto,
			SiscomDatCom *pSisDatCom)
{
CQSisPrecio *lCQSPrecio=new CQSisPrecio(gchrPtrPrecioEstudiantes,
					"",
					"");
CQSisOpTiendas4 lCQSOT4APrecio(pSisDatCom);
	lCQSOT4APrecio.ActualizaPrecioProducto(pCQSProducto,
			 new CQSisDatoPrecio(
			 	lCQSPrecio,
				pchrPtrPrecioM,
				pchrPtrCantidad));

}

void FormaPrecio(char **pchrPtrCampos,
		 SiscomDatCom *pSisDatCom,
		 CQSisLstProducto *pCQSLProducto)
{
CQSisProducto *lCQSProducto=BuscaProducto(pchrPtrCampos[gintPosClave],
				          pCQSLProducto);
char lchrArrPMenudeo[20];
char lchrArrPMayoreo[20];
char lchrArrPDistribuidor[20];
char lchrArrPEstudiantes[20];
if(lCQSProducto &&
   pchrPtrCampos[gintPosPrecioMenudeo]			&&
   pchrPtrCampos[gintPosPrecioMayoreo]			&&
   pchrPtrCampos[gintPosCantidadMayoreo]		&&
   pchrPtrCampos[gintPosPrecioDistribuidor]		&&
   pchrPtrCampos[gintPosCantidadDistribuidor]		&&
   pchrPtrCampos[gintPosPrecioEstudiantes]		&&
   pchrPtrCampos[gintPosPrecioMenudeo][0]		&&
   pchrPtrCampos[gintPosPrecioMayoreo][0]		&&
   pchrPtrCampos[gintPosCantidadMayoreo][0]		&&
   pchrPtrCampos[gintPosPrecioDistribuidor][0]		&&
   pchrPtrCampos[gintPosCantidadDistribuidor][0]	&&
   pchrPtrCampos[gintPosPrecioEstudiantes][0])
{
FormateaPrecio(pchrPtrCampos[gintPosPrecioMenudeo],lchrArrPMenudeo);
FormateaPrecio(pchrPtrCampos[gintPosPrecioMayoreo],lchrArrPMayoreo);
FormateaPrecio(pchrPtrCampos[gintPosPrecioDistribuidor],lchrArrPDistribuidor);
FormateaPrecio(pchrPtrCampos[gintPosPrecioEstudiantes],lchrArrPEstudiantes);
SiscomLog("Producto:%s Menudeo (%s) Mayoreo (%s,%s) Distribuidor (%s,%s) Estudiante (%s)",
	  (*lCQSProducto)["Clave"],
	   lchrArrPMenudeo,
	   lchrArrPMayoreo,
	   pchrPtrCampos[gintPosCantidadMayoreo],
	   lchrArrPDistribuidor,
	   pchrPtrCampos[gintPosCantidadDistribuidor],
	   lchrArrPEstudiantes);
FormaPrecioMayoreo(lchrArrPMayoreo,
		  pchrPtrCampos[gintPosCantidadMayoreo],
		  lCQSProducto,
		  pSisDatCom);
FormaPrecioMenudeo(lchrArrPMenudeo,
		   "1",
		   lCQSProducto,
		   pSisDatCom);
FormaPrecioDistribuidor(lchrArrPDistribuidor,
			pchrPtrCampos[gintPosCantidadDistribuidor],
			lCQSProducto,
			pSisDatCom);
FormaPrecioEstudiante(lchrArrPEstudiantes,
		      "1",
		      lCQSProducto,
		      pSisDatCom);
}
else
if(lCQSProducto)
SiscomLog("NO Se pudo formar el Precio de :%s",(*lCQSProducto)["Clave"]);
}
void RegistrandoCompras(FILE *pFlePtrArchivo,
			SiscomDatCom *pSisDatCom)
{
CQSisLstEmpresa lCQSLEmpresas;
CQSisLstProducto lCQSLProductos;
ObtenProveedores(pSisDatCom,&lCQSLEmpresas);
ObtenProductos(pSisDatCom,&lCQSLProductos); 
RegistraCompras(pFlePtrArchivo,
		pSisDatCom,
		&lCQSLEmpresas,
		&lCQSLProductos);
}
void RegistraCompras(FILE *pFlePtrArchivo,
		     SiscomDatCom *pSisDatCom,
		     CQSisLstEmpresa *pCQSLEmpresas,
		     CQSisLstProducto *pCQSLProductos)
{
char lchrArrLinea[2048];
char lchrArrBuffer[2048];
char **lchrPtrCampos;
CQSisFamilia *lCQSFamilia;
char lchrArrFamilia[56];
char lchrArrIdFamilia[10];
CQSisLstCompra lCQSLCompras;
SiscomLog("Analizando El Formato Seid");
while(!SiscomLeeLineaArchivo(pFlePtrArchivo,lchrArrLinea))
{
SiscomAnalizaCadenas(lchrArrLinea,
		     '\t',
		     lchrArrBuffer,
		     &lchrPtrCampos);
 if(EsRenglonFamilia2(lchrPtrCampos))
 {
       SiscomLeeLineaArchivo(pFlePtrArchivo,lchrArrLinea);
 }
 
  ObtenCompraProducto(pFlePtrArchivo,
  		      pSisDatCom,
		      pCQSLEmpresas,
		      pCQSLProductos,
		      &lCQSLCompras);
  SiscomLeeLineaArchivo(pFlePtrArchivo,lchrArrLinea);

}
CQSisOpCompras lCQSOpCompra(pSisDatCom);
lCQSOpCompra.Registra(&lCQSLCompras);
}
void ObtenCompraProducto(FILE *pFlePtrArchivo,
			 SiscomDatCom *pSisDatCom,
			 CQSisLstEmpresa *pCQSLEmpresa,
			 CQSisLstProducto *pCQSLProductos,
			 CQSisLstCompra *pCQSLCompras)
{
char **lchrPtrCampos;
char lchrArrCadena[2048];
char lchrArrBuffer[2048];
int lintNCampos;
while(!SiscomLeeLineaArchivo(pFlePtrArchivo,lchrArrCadena))
{
    lintNCampos=SiscomAnalizaCadenas(lchrArrCadena,
    			 '\t',
			 lchrArrBuffer,
			 &lchrPtrCampos);
   if(RegistroVacio(lchrPtrCampos))
    break;
   else
   FormaCompra(lchrPtrCampos,
   	       lintNCampos,
   		pSisDatCom,
		pCQSLEmpresa,
		pCQSLProductos,
		pCQSLCompras);

}
}
void FormateaPrecio(char *pchrPtrPrecio,
		    char *pchrPtrPrecioF)
{
SiscomEliminaEspaciosInicio(pchrPtrPrecio);
SiscomEliminaEspaciosFinal(pchrPtrPrecio);
if(*pchrPtrPrecio=='$')
 pchrPtrPrecio++;
 strcpy(pchrPtrPrecioF,pchrPtrPrecio);

}
void FormaCompra(char **pchrPtrCampos,
		 int pintNCampos,
		 SiscomDatCom *pSisDatCom,
		 CQSisLstEmpresa *pCQSLEmpresas,
		 CQSisLstProducto *pCQSLProductos,
		 CQSisLstCompra *pCQSLCompra)
{
if(pintNCampos==44)
{
CQSisEmpresa *lCQSProveedor=BuscaProveedor(pchrPtrCampos[gintPosRSocialProveedor],
					   pCQSLEmpresas);
CQSisProducto *lCQSProducto=BuscaProducto(pchrPtrCampos[gintPosClave],
					  pCQSLProductos);
CQSisContacto *lCQSContacto=new CQSisContacto(new SisPersona("","","","1300177306"));
CQSisFormaPago *lCQSFPago=new CQSisFormaPago("1","Contado","0");
char lchrArrPrecio[25];
if(lCQSProducto &&
   lCQSProveedor &&
   pchrPtrCampos[gintPosPrecioCompra][0])
{
FormateaPrecio(pchrPtrCampos[gintPosPrecioCompra],lchrArrPrecio);
SiscomLog("(Campos %d) %s %s %s %s %s",
	  pintNCampos,
	  pchrPtrCampos[gintPosClave],
	  pchrPtrCampos[gintPosRSocialProveedor],
	  pchrPtrCampos[gintPosPrecioCompra],
	  lchrArrPrecio,
	  pchrPtrCampos[gintPosCantidadCompra]);
(*pCQSLCompra) << new CQSisCompra(lCQSProducto,
			       lCQSProveedor,
			       lCQSContacto,
			       lCQSFPago,
			       "",
			       pchrPtrCampos[gintPosCantidadCompra],
			       lchrArrPrecio,
			       "Inicio",
			       "",
			       "0");
}
}
}
void RegistrandoProductos(FILE *pFlePtrArchivo,
			  SiscomDatCom *pSisDatCom)
{
CQSisLstFamilia lCQSLFamilias;
CQSisFamilia *lCQSFamilia;
ObtenFamilias(pSisDatCom,&lCQSLFamilias);
RegistraProductos(pFlePtrArchivo,pSisDatCom,&lCQSLFamilias);
}
void ObtenFamilias(SiscomDatCom *pSisDatCom,
		   CQSisLstFamilia *pCQSLFamilias)
{
CQSisOpTiendas4 lCQSOpT4Familias(pSisDatCom);
lCQSOpT4Familias.Familias(pCQSLFamilias);
}
void RegistrandoProveedores(FILE *pFlePtrArchivo,
			    SiscomDatCom *pSisDatCom)
{

	RegistraProveedores(pFlePtrArchivo,pSisDatCom);
}
void RegistraProveedores(FILE *pFlePtrArchivo,
			 SiscomDatCom *pSisDatCom)
{
char lchrArrLinea[2048];
char lchrArrBuffer[2048];
char **lchrPtrCampos;
CQSisFamilia *lCQSFamilia;
char lchrArrFamilia[56];
char lchrArrIdFamilia[10];
SiscomLog("Analizando El Formato Seid");
while(!SiscomLeeLineaArchivo(pFlePtrArchivo,lchrArrLinea))
{
SiscomAnalizaCadenas(lchrArrLinea,
		     '\t',
		     lchrArrBuffer,
		     &lchrPtrCampos);
 if(EsRenglonFamilia2(lchrPtrCampos))
 {
       SiscomLeeLineaArchivo(pFlePtrArchivo,lchrArrLinea);
 }
 
  ObtenProveedorProducto(pFlePtrArchivo,pSisDatCom);
   SiscomLeeLineaArchivo(pFlePtrArchivo,lchrArrLinea);

}

}
void ObtenProveedorProducto(FILE *pFlePtrArchivo,
			    SiscomDatCom *pSisDatCom)
{
char **lchrPtrCampos;
char lchrArrCadena[2048];
char lchrArrBuffer[2048];
int lintNCampos;
while(!SiscomLeeLineaArchivo(pFlePtrArchivo,lchrArrCadena))
{
    lintNCampos=SiscomAnalizaCadenas(lchrArrCadena,
    			 '\t',
			 lchrArrBuffer,
			 &lchrPtrCampos);
   SiscomLog("El Numero de campos Excell:%d",lintNCampos);
   if(RegistroVacio(lchrPtrCampos))
    break;
   else
   FormaProveedor(lchrPtrCampos,pSisDatCom);
}
}
int AnalizaNombreCompleto(const char *pchrPtrNmbCompleto,
			   char *pchrPtrNombre,
			   char *pchrPtrAPaterno,
			   char *pchrPtrAMaterno)
{
char **lchrPtrNombre;
char lchrArrBuffer[75];
int lintCampos;
if((lintCampos=SiscomAnalizaCadenas(pchrPtrNmbCompleto,
			' ',
			lchrArrBuffer,
			&lchrPtrNombre)))
{
//SiscomLog("El Numero de campos:%d",lintCampos); 
if(lintCampos==1)
{
 strcpy(pchrPtrNombre,lchrPtrNombre[0]);
 strcpy(pchrPtrAPaterno,"Sin APaterno");
 strcpy(pchrPtrAMaterno,"Sin AMaterno");
 return 1;
}
else
if(lintCampos==2)
{
    if(!strchr(lchrPtrNombre[0],'.'))
    {

    strcpy(pchrPtrNombre,lchrPtrNombre[0]);
    strcpy(pchrPtrAPaterno,lchrPtrNombre[1]);
    strcpy(pchrPtrAMaterno,"Sin AMaterno");
    }
    else
    {


    strcpy(pchrPtrNombre,lchrPtrNombre[1]);
    strcpy(pchrPtrAPaterno,"Sin APaterno");
    strcpy(pchrPtrAMaterno,"Sin AMaterno");
    }
    return 1;
}
else
if(lintCampos==4)
{
 if(strchr(lchrPtrNombre[0],'.'))
 {
    strcpy(pchrPtrNombre,lchrPtrNombre[1]);
    strcpy(pchrPtrAPaterno,lchrPtrNombre[2]);
    strcpy(pchrPtrAMaterno,lchrPtrNombre[3]);
 }
return 1;
}
else
if(lintCampos==3)
{

    strcpy(pchrPtrNombre,lchrPtrNombre[0]);
    strcpy(pchrPtrAPaterno,lchrPtrNombre[1]);
    strcpy(pchrPtrAMaterno,lchrPtrNombre[2]);
 return 1;
}
}
else
return 0;

}
int ObtenNombreCompleto(const char *pchrPtrNmbCompleto,
			 char *pchrPtrNombre,
			 char *pchrPtrAPaterno,
			 char *pchrPtrAMaterno)
{
char lchrArrNombre[75];
strcpy(lchrArrNombre,pchrPtrNmbCompleto);
SiscomCambiaMayusculas(lchrArrNombre);
if(strstr(lchrArrNombre,"SIN REFERENCIA"))
{
SiscomLog("No hay datos del contacto");
return 0;
}
else
{
/*SiscomLog("%s",pchrPtrNmbCompleto);*/
return AnalizaNombreCompleto(pchrPtrNmbCompleto,
			     pchrPtrNombre,
			     pchrPtrAPaterno,
			     pchrPtrAMaterno);
}
}
CQSisContactoE *FormaContacto(char **pchrPtrCampos)
{
CQSisContactoE *lCQSContactoE;
char lchrArrNombre[25];
char lchrArrAPaterno[25];
char lchrArrAMaterno[25];
if(ObtenNombreCompleto(pchrPtrCampos[gintPosContactoProveedor],
 		     lchrArrNombre,
		     lchrArrAPaterno,
		     lchrArrAMaterno))
{
//SiscomLog("(%s) (%s) (%s)",lchrArrNombre,lchrArrAPaterno,lchrArrAMaterno);
lCQSContactoE=new CQSisContactoE("",
				 "Contacto",
				 lchrArrNombre,
				 lchrArrAPaterno,
				 lchrArrAMaterno);
}
else
lCQSContactoE=0;
 return lCQSContactoE;

}
CQSisMedioComunicacionE *FormaTelefono(const char *pchrPtrCampo)
{
return new CQSisMedioComunicacionE("",
				   "",
				   "1",
				   "Telefono",
				   pchrPtrCampo);
}
CQSisMedioComunicacionE *FormaCorreoElectronico(const char *pchrPtrCampo)
{
return new CQSisMedioComunicacionE("",
				   "",
				   "2",
				   "Correo Electronico",
				   pchrPtrCampo);
}
CQSisDireccionE *FormaDireccion()
{
return new CQSisDireccionE("",
			   "",
			   "Linea 1",
			   "Linea 2",
			   "Linea 3");
}
void FormaProveedor(char **pchrPtrCampos,
		   SiscomDatCom *pSisDatCom)
{
CQSisEmpresa2 lCQSEmpresa2;
CQSisContactoE *lCQSContactoE;
SiscomRegistro4 lSisReg4Regreso;
if(pchrPtrCampos[gintPosRSocialProveedor])
{
/**
 * SubRegistros 
 * 0 Direcciones
 * 1 Comunicacion
 * 2 Contactos
 */
SiscomLog("{%s} (%s) (%s) (%s) (%s) (%s)",
	pchrPtrCampos[gintPosClave],
	pchrPtrCampos[gintPosRSocialProveedor],
	pchrPtrCampos[gintPosContactoProveedor],
	pchrPtrCampos[gintPosTelefonoProveedor],
	pchrPtrCampos[gintPosTelefono2Proveedor],
	pchrPtrCampos[gintPosCorreoProveedor]);
lCQSEmpresa2.Generales("",pchrPtrCampos[gintPosRSocialProveedor],"Proveedor");
lCQSEmpresa2.AgregaDireccion(FormaDireccion());
lCQSEmpresa2.AgregaMedioComunicacion(FormaTelefono(pchrPtrCampos[gintPosTelefonoProveedor]));
lCQSEmpresa2.AgregaMedioComunicacion(FormaTelefono(pchrPtrCampos[gintPosTelefono2Proveedor]));
lCQSEmpresa2.AgregaMedioComunicacion(FormaCorreoElectronico(pchrPtrCampos[gintPosCorreoProveedor]));
if((lCQSContactoE=FormaContacto(pchrPtrCampos)))
lCQSEmpresa2.AgregaContacto(lCQSContactoE);
//SiscomContenidoRegistro4Log(&lCQSEmpresa2);
lCQSEmpresa2.first();
CQSisOperacionesEmp2 lCQSOpEmpresa2(pSisDatCom);

//if(!lCQSOpEmpresa2.EmpresaRegistrada(&lCQSEmpresa2))
{
//SiscomContenidoRegistro4Log(&lCQSEmpresa2);
lCQSEmpresa2.first();
lCQSOpEmpresa2.Envia(0,&lCQSEmpresa2,&lSisReg4Regreso);
}
}
else
SiscomLog("Proveedor Nulo");
}
void RegistraProductos(FILE *pFlePtrArchivo,
		       SiscomDatCom *pSisDatCom,
		       CQSisLstFamilia *pCQSLFamilias)
{
char lchrArrLinea[2048];
char lchrArrBuffer[2048];
char **lchrPtrCampos;
CQSisFamilia *lCQSFamilia;
char lchrArrFamilia[56];
char lchrArrIdFamilia[10];
SiscomLog("Analizando El Formato Seid");
while(!SiscomLeeLineaArchivo(pFlePtrArchivo,lchrArrLinea))
{
SiscomAnalizaCadenas(lchrArrLinea,
		     '\t',
		     lchrArrBuffer,
		     &lchrPtrCampos);
 if(EsRenglonFamilia2(lchrPtrCampos))
 {
    if((lCQSFamilia=BuscaFamilia(lchrPtrCampos[1],pCQSLFamilias)))
    {
       SiscomLog("%s  %s",(*lCQSFamilia)["IdFamilia"],(*lCQSFamilia)["Dsc"]); 
       SiscomLeeLineaArchivo(pFlePtrArchivo,lchrArrLinea);
    }
    else
     SiscomLog("NO se encontro la familia:%s",lchrPtrCampos[1]);
 }
  ObtenProductosFamilia(lCQSFamilia,pFlePtrArchivo,pSisDatCom);
   SiscomLeeLineaArchivo(pFlePtrArchivo,lchrArrLinea);
}

}
void RegistraFamilias(FILE *pFlePtrArchivo,
		      SiscomDatCom *pSisDatCom)
{
char lchrArrLinea[2048];
char lchrArrBuffer[2048];
char **lchrPtrCampos;
CQSisFamilia *lCQSFamilia;
int lintContadorFamilia=0;
char lchrArrFamilia[56];
char lchrArrIdFamilia[10];
SiscomLog("Analizando El Formato Seid");
while(!SiscomLeeLineaArchivo(pFlePtrArchivo,lchrArrLinea))
{
SiscomAnalizaCadenas(lchrArrLinea,
		     '\t',
		     lchrArrBuffer,
		     &lchrPtrCampos);
 if((lCQSFamilia=EsRenglonFamilia(lchrPtrCampos)))
 {
   GeneraClaveFamilia(lintContadorFamilia,lchrArrFamilia);
   lCQSFamilia->SiscomActualizaCampo("Familia",lchrArrFamilia);
   SiscomLog("%s %s",(*lCQSFamilia)["Familia"],(*lCQSFamilia)["Dsc"]);
   EnviaFamilia(pSisDatCom,lCQSFamilia);
   lintContadorFamilia++;
 }
}
}
void GeneraClaveFamilia(int pintContador,
			char *pchrPtrFamilia)
{
 sprintf(pchrPtrFamilia,"Familia%02d",pintContador);
}
int RegistroVacio(char **pchrPtrProductos)
{
int lintContador=0;
	while(*pchrPtrProductos)
	{
	 if(!(*pchrPtrProductos)[0])
	 lintContador++;
	  pchrPtrProductos++;
	}
return lintContador==43;
}
void ObtenProductosFamilia(CQSisFamilia *pCQSFamilia,
			   FILE *pFlePtrArchivo,
			   SiscomDatCom *pSisDatCom)
{
char **lchrPtrCampos;
char lchrArrCadena[2048];
char lchrArrBuffer[2048];
while(!SiscomLeeLineaArchivo(pFlePtrArchivo,lchrArrCadena))
{
    SiscomAnalizaCadenas(lchrArrCadena,
    			 '\t',
			 lchrArrBuffer,
			 &lchrPtrCampos);
   if(RegistroVacio(lchrPtrCampos))
    break;
   else
   FormaProducto(pCQSFamilia,lchrPtrCampos,pSisDatCom);
}
}

int ValidaClaveProducto(char **pchrPtrCampos)
{
     if(strchr(pchrPtrCampos[gintPosClave],' ') ||
        strstr(pchrPtrCampos[gintPosClave],"\""))
     return 0;
     else
     return 1;
}
void FormaProducto(CQSisFamilia *pCQSFamilia,
		   char **pchrPtrCampos,
		   SiscomDatCom *pSisDatCom)
{
if(ValidaClaveProducto(pchrPtrCampos))
{
CQSisProducto *lCQSProducto=new CQSisProducto(pCQSFamilia,
					      "",
					      pchrPtrCampos[gintPosClave],
					      pchrPtrCampos[8]);
CQSisOpTiendas4 lCQSOpT4Producto(pSisDatCom);
lCQSOpT4Producto.AnexaProducto(lCQSProducto);
   SiscomLog("(%d) %s -> %s ",
   	     strlen(pchrPtrCampos[gintPosClave]),
	     pchrPtrCampos[gintPosClave],
	     pchrPtrCampos[8]); 
}
else
SiscomLog("Clave No valida:%s",pchrPtrCampos[gintPosClave]);
 
}
void AbreArchivo(const char *pchrPtrArchivo,
		 FILE **pFlePtrArchivo)
{

if(!(*pFlePtrArchivo=fopen(pchrPtrArchivo,"r")))
{
 SiscomLog("%s",strerror(errno));
 exit(errno);

}


}

CQSisFamilia *FamiliaSeidASiscomTiendas4(char **pchrPtrCampos)
{
return new CQSisFamilia("0","Familia",pchrPtrCampos[1]);
}
CQSisFamilia *EsRenglonFamilia(char **pchrPtrCampos)
{
CQSisFamilia *lCQSFamilia=0;
char **lchrPtrCampos=pchrPtrCampos;
int lintCamposConInfo=0;
	while(*lchrPtrCampos)
	{
	 if((*lchrPtrCampos)[0])
	  lintCamposConInfo++;
	  lchrPtrCampos++;
	}
 if(lintCamposConInfo==1)
  lCQSFamilia=FamiliaSeidASiscomTiendas4(pchrPtrCampos);
  return lCQSFamilia;
}

int EsRenglonFamilia2(char **pchrPtrCampos)
{
char **lchrPtrCampos=pchrPtrCampos;
int lintCamposConInfo=0;
	while(*lchrPtrCampos)
	{
	 if((*lchrPtrCampos)[0])
	  lintCamposConInfo++;
	  lchrPtrCampos++;
	}
return lintCamposConInfo==1;
}


void EnviaFamilia(SiscomDatCom *pSisDatCom,
		  CQSisFamilia *pCQSFamilia)
{
CQSisOpTiendas4 lCQSOpT4Envio(pSisDatCom);
lCQSOpT4Envio.AnexaFamilia(pCQSFamilia);
}

CQSisEmpresa *BuscaProveedor(const char *pchrPtrRSocial,
			     CQSisLstEmpresa *pCQSLEmpresas)
{
CQSisEmpresa *lCQSEmpresa;
for(lCQSEmpresa=pCQSLEmpresas->first();
    lCQSEmpresa;
    lCQSEmpresa=pCQSLEmpresas->next())
if(!strcmp(pchrPtrRSocial,(*lCQSEmpresa)["RazonSocial"]))
 return lCQSEmpresa;

 return 0;
}
CQSisProducto *BuscaProducto(const char *pchrPtrClave,
			     CQSisLstProducto *pCQSLProducto)
{
CQSisProducto *lCQSProducto;
for(lCQSProducto=pCQSLProducto->first();
    lCQSProducto;
    lCQSProducto=pCQSLProducto->next())
if(!strcmp(pchrPtrClave,(*lCQSProducto)["Clave"]))
return lCQSProducto;

return 0;

}
CQSisFamilia *BuscaFamilia(const char *pchrPtrDsc,
			   CQSisLstFamilia *pCQSLFamilia)
{
CQSisFamilia *lCQSFamilia;
for(lCQSFamilia=pCQSLFamilia->first();
    lCQSFamilia;
    lCQSFamilia=pCQSLFamilia->next())
if(!strcmp(pchrPtrDsc,(*lCQSFamilia)["Dsc"]))
 return lCQSFamilia;

 return 0;

}
void ObtenProveedores(SiscomDatCom *pSisDatCom,
		      CQSisLstEmpresa *pCQSLEmpresas)
{
CQSisOpTiendas4 lCQSOT4Empresas(pSisDatCom);
lCQSOT4Empresas.Proveedores(pCQSLEmpresas);

}
void ObtenProductos(SiscomDatCom *pSisDatCom,
		    CQSisLstProducto *pCQSLProductos)
{
CQSisOpTiendas4 lCQSOT4Empresas(pSisDatCom);
lCQSOT4Empresas.Productos(pCQSLProductos);
}
