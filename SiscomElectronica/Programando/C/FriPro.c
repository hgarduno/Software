#include <FriPro.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <unistd.h>



#include <FacturandoFriPro.h>


#include <stdlib.h>
FILE *gPtrFleArchivoLog;
int gintSocketProtocoloLog;
SiscomError gSiscomErrorSistema;

int main(int pintArgc,
	 char **pchrPtrArgv)
{
 StcSiscomOpciones *lStcPtrSisOpciones;
 SiscomRegistroProL *lSisRegProLPtrConfig;
 gPtrFleArchivoLog=stdout;
 Argumentos(pintArgc,pchrPtrArgv,&lStcPtrSisOpciones,&lSisRegProLPtrConfig);
 FacturandoFriPro(lStcPtrSisOpciones,lSisRegProLPtrConfig);
}

void Argumentos(int pintArgc,
		char **pchrPtrArgv,
		StcSiscomOpciones **pStcPtrSisOpciones,
		SiscomRegistroProL **pSisRegProLPtrConfig)
{
StcSiscomOpciones lStcSisOpciones;
char *lchrPtrComandos[]={"Importe" ,
			"Concepto",
			"Folio",
			"Configuracion",
			"FormaPago",
			"CodigoFormaPago",
			0};

    SiscomAnalizaOpciones(pchrPtrArgv,pintArgc,pStcPtrSisOpciones);

  if(!SiscomLineaComandosCompleta(lchrPtrComandos,*pStcPtrSisOpciones,&lStcSisOpciones)) 
  {
     printf("Modo de Uso:								\n"
     	    "FriPro :									\n"
	    " 		-Importe 							\n"
	    "			Monto total de la factura, IVA Incluido			\n"
	    "		-Concepto 							\n"
	    "			Concepto que se mostrara en la factura, si esta formado \n"
	    "			por varias palabras se debera poner entre comillas	\n"
	    "		-Folio								\n"
	    "			Numero entero que indica el folio de la factura		\n"
	    "		-Ambiente 							\n"
	    "			Se puede pasar:						\n"
	    "				Produccion 					\n"
	    "				  Para lo que se tomaran los datos de timbrado 	\n"
	    "				  de la factura con los datos de usuario y 	\n"
	    "				  servidor de produccion.			\n"
	    "				Pruebdas 					\n"
	    "				  Para lo que se tomaran los datos de timbrado 	\n"
	    "				  de la factura con los datos de usuario y 	\n"
	    "				  servidor de pruebas.				\n"
	    "		-Php  								\n"
	    "			Binario de Php 						\n"
	    "		-DirFacturacion							\n"
	    "			Ruta donde se encuentra el archivo 			\n"
	    "			SiscomFacturacion.php y el directorio 			\n"
	    "			CFDIgenerados						\n"
	    "		-Configuracion Archivo con la informacion de RFC, Razon Social	\n"
	    "			Datos de direccion para poder generalizar las facturas	\n"
	    "										\n"
	    "		-CodigoFormaPago         -FormaPago				\n"
	    "			01		    Efectivo				\n"
	    " 			02		    Cheque Nominativo			\n"
	    "			03		    Transferencia electronica de fondos \n"
	    "			04		    Tarjeta de credito			\n"
	    "			05		    Monedero electronico		\n"
	    "			06                  Dinero electronico			\n"
	    "			08                  Vales de despensa			\n"
	    "			12		    Dacion en pago			\n"
	    "			13		    Pago por subrogacion		\n"
	    "			14                  Pago por consignacion		\n"
	    "			15                  Condonacion				\n"
	    "			17                  Compensacion			\n"
	    "			23		    Novacion				\n"
	    "			24		    Confusion				\n"
	    "			25		    Remision de deuda			\n"
	    "			26                  Prescripcion o caducidad		\n"
	    "			27		    A satisfaccion del acredor		\n"
	    "			28 		    Tarjeta de debito			\n"
	    " 			29		    Tarjeta de servicios		\n"
	    "			30		    Aplicacion de anticipos		\n"
	    "			31		    Intermediario pagos			\n"
	    "			99		    Por definir				\n"
	    "										\n"
	    "Consideraciones adicionales						\n"
	    "              	Si no se pasa el parametro Ambiente, el programa	\n"
	    "		   inicializa con el datos de Pruebas				\n"
	    "		   	Php y DirFacturacion, se toman de variables de -	\n"
	    "		    de ambiente en el script que ejecuta el programa, --	\n"
	    "		    esto permitira dejar fijo en el script estos datos.		\n"
	    "										\n"
	    "Ejemplo de Uso 								\n"
    	    "FriPro -Importe 1200 -Concepto \"Desarrollo y Pruebas\" -Folio 1028 -Ambiente Pruebas -Php php7.0 -DirFacturacion /home/hgarduno/ProbandoFacturacion/SiscomFacturacion/3.3/Prod \n");
     exit(0);
  }
  else
  {
    if(SiscomEstaLaOpcion("Configuracion",*pStcPtrSisOpciones))
	 LeyendoConfiguracion(pStcPtrSisOpciones,pSisRegProLPtrConfig);	
    if(SiscomEstaLaOpcion("MasIva",*pStcPtrSisOpciones))
      ImporteMasIva(pStcPtrSisOpciones);
  
    if(!SiscomEstaLaOpcion("Ambiente",*pStcPtrSisOpciones))
     SiscomAgregaLineaComandos("Ambiente","Pruebas",pStcPtrSisOpciones);
     if(!SiscomEstaLaOpcion("DirFacturacion",*pStcPtrSisOpciones))
      AgregandoDirFacturacionDelAmbiente(pStcPtrSisOpciones);
      if(!SiscomEstaLaOpcion("Php",*pStcPtrSisOpciones))
      AgregandoBinarioPhp(pStcPtrSisOpciones);
  }
}
void AgregandoDirFacturacionDelAmbiente(StcSiscomOpciones **pStcPtrSisOpciones)
{
const char *lchrPtrDirFacturacion;

if((lchrPtrDirFacturacion=getenv("DirFacturacion")))
    SiscomAgregaLineaComandos("DirFacturacion",lchrPtrDirFacturacion,pStcPtrSisOpciones);
else
{
LogSiscom("NO Se ha definido la Ruta del Proyecto Siscom Facturacion");
exit(0);
}
}
void AgregandoBinarioPhp(StcSiscomOpciones **pStcPtrSisOpciones)
{
const char *lchrPtrDirFacturacion;

if((lchrPtrDirFacturacion=getenv("BinarioPhp")))
    SiscomAgregaLineaComandos("Php",lchrPtrDirFacturacion,pStcPtrSisOpciones);
else
{
LogSiscom("NO Se ha definido el binario del php");
exit(0);
}
}
int AbreArchivoConfiguracion(StcSiscomOpciones *pStcPtrSisOpciones)
{
int lintArchivo;
   if((lintArchivo=open(SiscomOpcionAChar("Configuracion",pStcPtrSisOpciones),S_IRUSR | S_IWUSR)))
   {

	return lintArchivo;
   }
   else
   return -1;
}
void LeyendoConfiguracion(StcSiscomOpciones **pStcPtrSisOpciones,
			  SiscomRegistroProL **pSisRegProLPtrConfig)
{
char lchrArrBuffer[128];
int lintArchivo;
SiscomRegistroProL *lSisRegProLPtrAct=0;
*pSisRegProLPtrConfig=0;
	if((lintArchivo=AbreArchivoConfiguracion(*pStcPtrSisOpciones)))
	{
	   SiscomVersionProtocolo4(lintArchivo);
	   SiscomLeeRegistrosSocket(lintArchivo,
	   			    lchrArrBuffer,
				    pSisRegProLPtrConfig,
				    &lSisRegProLPtrAct);
	   close(lintArchivo);
	}
}

void ImporteMasIva(StcSiscomOpciones **pStcPtrSisOpciones)
{
char lchrArrImporte[25];
float lfltImporte=SiscomOpcionAFloat("Importe",*pStcPtrSisOpciones);
lfltImporte*=1.16;
sprintf(lchrArrImporte,"%.2f",lfltImporte);
SiscomActualizaOpcion("Importe",lchrArrImporte,*pStcPtrSisOpciones);
LogSiscom("El importe Mas Iva %s",lchrArrImporte);
}
