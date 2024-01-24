#include <RNEmpresas.h>
#include <RNPersonas.h>
#include <ServidorGeneral.h>

#include <ComunElectronica.h>
#include <ComunElectronica2.h>
#include <string.h>

StcConsultas gStcCnsEmpresas[]={ {EsConsultaEmpresas,FormaConsultaEmpresas},
				 {EsConsultaProveedores,FormaConsultaProveedores},
				 {EsConsultaMatriz,FormaConsultaMatriz}
			       };
int gintCnsEmpresas=3;

int EsConsultaMatriz(char **pchrPtrEntrada)
{
	return !strcmp(pchrPtrEntrada[0],"ConsultaMatriz");

}
void FormaConsultaMatriz(char **pchrPtrEntrada,
			   SiscomOperacionesServidor *pSOpServidor)
{

 SiscomInformacionOperaciones("ConsultaSQL","Consultas",pSOpServidor);
 SiscomAnexaRegistroPro2(&pSOpServidor->LCSiscomPro2EPrim,
		         &pSOpServidor->LCSiscomPro2EAct,
			&pSOpServidor->intNRegistros,
			"ConsultaSQL",
			"SELECT * from empresas inner join matriz using(idEmpresa)");
}

int EsConsultaProveedores(char **pchrPtrEntrada)
{
	return !strcmp(pchrPtrEntrada[0],"Proveedores");

}
void FormaConsultaProveedores(char **pchrPtrEntrada,
			   SiscomOperacionesServidor *pSOpServidor)
{
char lchrArrConsulta[128];

	sprintf(lchrArrConsulta,
		"select *		\
		from empresas 		\
		where idEmpresa>0");
 SiscomInformacionOperaciones("ConsultaSQL","Consultas",pSOpServidor);
 SiscomAnexaRegistroPro2(&pSOpServidor->LCSiscomPro2EPrim,
		         &pSOpServidor->LCSiscomPro2EAct,
			&pSOpServidor->intNRegistros,
			"ConsultaSQL",
			lchrArrConsulta);


}
int EsConsultaEmpresas(char **pchrPtrEntrada)
{
	return !strcmp(pchrPtrEntrada[0],"Expendios");
}
void FormaConsultaEmpresas(char **pchrPtrEntrada,
			   SiscomOperacionesServidor *pSOpServidor)
{
char lchrArrConsulta[512];

	sprintf(lchrArrConsulta,
		"					\n\
select a.*,						\n\
	ptocomad,					\n\
	diripsvrad,					\n\
	basedatos					\n\
from 							\n\
      empresas as a left outer join			\n\
     expendios as b using(idempresa) inner join		\n\
     expendioabierto as c using(idempresa)		\n\
where idEmpresa<0");
 SiscomInformacionOperaciones("ConsultaSQL","Consultas",pSOpServidor);
 SiscomAnexaRegistroPro2(&pSOpServidor->LCSiscomPro2EPrim,
		         &pSOpServidor->LCSiscomPro2EAct,
			&pSOpServidor->intNRegistros,
			"ConsultaSQL",
			lchrArrConsulta);
SiscomLog("%s",lchrArrConsulta);

}
void AnalizaConsultaEmpresas(char **pchrPtrEntrada,
			      SiscomOperacionesServidor *pSOpServidor)
{
int lintContador;
	for(lintContador=0;
	    lintContador<gintCnsEmpresas;
	    lintContador++)
	   if(gStcCnsEmpresas[lintContador].Consulta(pchrPtrEntrada))
	   {
	      gStcCnsEmpresas[lintContador].FormaConsulta(pchrPtrEntrada,
	     						  pSOpServidor);
		return ;
	   }

	

}
void ConsultaEmpresas(int pintSocket,
		       int pintNRegistros)
{
SiscomOperacionesServidor lSOpServidor;
char **lchrPtrEntrada=0;
	lSOpServidor.EjecutaProcesoAntes=0;
	SiscomIniciaComunicacionesSrv(gSSiscomConfiguracionSvr.chrPtrDirIpAccesoDatos,
				      gSSiscomConfiguracionSvr.intPtoAccesoDatos,
				      &lSOpServidor);
	SiscomLeeInformacionProtocolo(pintSocket,
				      pintNRegistros,
				      &lSOpServidor.LCSiscomPro2Dat);
	SiscomCopiaDatosProtocoloCharChar(lSOpServidor.LCSiscomPro2Dat,
					  pintNRegistros,
					  "Parametro",
					  &lchrPtrEntrada);

	AnalizaConsultaEmpresas(lchrPtrEntrada,&lSOpServidor);
	SiscomOperacionesServidores(&lSOpServidor);
	SiscomEnviaAlServidor(pintSocket,
			      lSOpServidor.intNRegistrosRes,
			      "ClientesRegistrados",
			      lSOpServidor.LCSiscomPro2);

	close(pintSocket);
}
int AnexaDatosEmpresa(LCamposSiscomPro2 *pLCSiscomPro2,
		       int pintContador,
		       char *pchrPtrCadenaInsercion,
		       int *pintPtrIdEmpresa)
{
const char *lchrPtrRazonSocial;
	lchrPtrRazonSocial=SiscomObtenDato(pLCSiscomPro2,"RazonSocial");
	if(lchrPtrRazonSocial[0])
	{
	 sprintf(pchrPtrCadenaInsercion,
	 	"insert into Empresas values('%s',%d,'%s');",
		lchrPtrRazonSocial,
		(*pintPtrIdEmpresa=SiscomObtenNumeroUnico()+pintContador),
		SiscomObtenDato(pLCSiscomPro2,"RFC"));
	 return 1;
	}
	else
	{
	pchrPtrCadenaInsercion[0]=0;
	return 0;
	}

	

}
void AnexaDireccionesEmpresa(int pintIdEmpresa,
			     LCamposSiscomPro2 *pLCSiscomPro2,
			     char *pchrPtrCadenaInsercion)
{
const char	*lchrPtrCalle=SiscomObtenDato(pLCSiscomPro2,"Calle"),
		*lchrPtrNumero=SiscomObtenDato(pLCSiscomPro2,"Numero");


		if(lchrPtrCalle[0] &&
		   lchrPtrNumero[0])
		  sprintf(pchrPtrCadenaInsercion,
		  	  "insert into Direcciones values(0,%d,'%s','%s','%s',%s,'%s','%s','%s');",
			  pintIdEmpresa,
			  lchrPtrCalle,
			  lchrPtrNumero,
			  SiscomObtenDato(pLCSiscomPro2,"Colonia"),
			  SiscomObtenDato(pLCSiscomPro2,"CP"),
			  SiscomObtenDato(pLCSiscomPro2,"Municipio"),
			  SiscomObtenDato(pLCSiscomPro2,"Estado"),
			  SiscomObtenDato(pLCSiscomPro2,"Referencia"));
		 else
		 pchrPtrCadenaInsercion[0]=0;
		


}
void AnexaTelefonoEmpresa(int pintIdEmpresa,
			  LCamposSiscomPro2 *pLCSiscomPro2,
			  char *pchrPtrCadenaInsercion)
{
const char *lchrPtrTelefono=SiscomObtenDato(pLCSiscomPro2,"Telefono"),
	   *lchrPtrComentario=SiscomObtenDato(pLCSiscomPro2,"Comentario");

	if(lchrPtrTelefono[0] &&
	   lchrPtrComentario[0] )
	 sprintf(pchrPtrCadenaInsercion,
	 	"insert into telefonos values(0,%d,'%s','%s')",
		pintIdEmpresa,
		SiscomObtenDato(pLCSiscomPro2,"Telefono"),
		SiscomObtenDato(pLCSiscomPro2,"Comentario"));
}
int AnexaContactoEmpresa(int pintContador,
			  int pintIdEmpresa,
			  LCamposSiscomPro2 *pLCSiscomPro2,
			  char *pchrPtrCadena)
{
const char *lchrPtrNombre=SiscomObtenDato(pLCSiscomPro2,"Nombre"),
	   *lchrPtrDepartamento=SiscomObtenDato(pLCSiscomPro2,"Departamento");
/*
 *	Para poder relacionar, el contacto de la empresa
 *	con el tipo de persona, se realiza la insercion del 
 *	idEmpresa, en el idPersona, de tal forma que los contactos
 *	de la empresa se buscaran en la tabla de personas, mediante
 *	el idEmpresa=idPersona
 *
 *	Por otro, lado, se debe registrar el tipo de persona 
 *	contacto de empresa, con el valor de 1000
 *
 */
	if(lchrPtrNombre[0] &&
	   lchrPtrDepartamento[0])
	{
	  sprintf(pchrPtrCadena,
	  	  "insert into personas values('%s','%s','%s','%s',%d,1000,'%s')",
		  SiscomObtenDato(pLCSiscomPro2,"Nombre"),
		  SiscomObtenDato(pLCSiscomPro2,"APaterno"),
		  SiscomObtenDato(pLCSiscomPro2,"AMaterno"),
		  "",
		  pintIdEmpresa,
		  SiscomObtenDato(pLCSiscomPro2,"Departamento"));
	   return 1;
	}
	else
	{
	pchrPtrCadena[0]=0;
	return 0;
	}
}
void FormaCadenaOperacionSqlEmpresas(int pintContador,
			     LCamposSiscomPro2 *pLCSiscomPro2,
			     char *pchrPtrCadena,
			     int *pintPtrIdEmpresa)
{

	AnexaDatosEmpresa(pLCSiscomPro2,pintContador,pchrPtrCadena,pintPtrIdEmpresa);
	if(!pchrPtrCadena[0])
	{
	AnexaDireccionesEmpresa(*pintPtrIdEmpresa,pLCSiscomPro2,pchrPtrCadena);
	if(!pchrPtrCadena[0])
	{
	AnexaTelefonoEmpresa(*pintPtrIdEmpresa,pLCSiscomPro2,pchrPtrCadena);
	if(!pchrPtrCadena[0])
	 AnexaContactoEmpresa(pintContador,*pintPtrIdEmpresa,pLCSiscomPro2,pchrPtrCadena);
	}
	}
 		
	
			


}
void RegistraEmpresas(int pintSocket,
			int pintNRegistros)
{
LCamposSiscomPro2 *lLCSiscomPro2=0;
LCamposSiscomPro2 *lLCSiscomPro2Ins=0,
                  *lLCSiscomPro2InsAct=0;
char lchrArrActualiza[1204];
char *lchrPtrEdoConexion=0;
int     lintSocketAD,
        lintNRegistros=0,
	lintContador,
	lintIdEmpresa;

SiscomLeeInformacionProtocolo(pintSocket,
                                      pintNRegistros,
                                      &lLCSiscomPro2);

  for(lintContador=0;
  	lLCSiscomPro2;
	lLCSiscomPro2=lLCSiscomPro2->SCP2PtrSig,
	lintContador++)
  {
  	 FormaCadenaOperacionSqlEmpresas(lintContador,
	 				 lLCSiscomPro2,
					 lchrArrActualiza,
					 &lintIdEmpresa); 
	 if(lchrArrActualiza[0])
	 SiscomAnexaRegistroPro2(&lLCSiscomPro2Ins,
	 			 &lLCSiscomPro2InsAct,
				 &lintNRegistros,
				 "ComandoSQL",
				 lchrArrActualiza);
  }
	SiscomInformacionServidor(gSSiscomConfiguracionSvr.intPtoAccesoDatos,
	                          gSSiscomConfiguracionSvr.chrPtrDirIpAccesoDatos,
				  "Inserciones",
				  lintNRegistros,
				  lLCSiscomPro2Ins,
				  &lchrPtrEdoConexion,
				  &lintSocketAD);
	if(lchrPtrEdoConexion)
	SiscomMensajesLog(gPtrFleArchivoLog,
			  "Error Al Enviar:%s",
	                  lchrPtrEdoConexion);
}
