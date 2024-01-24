#include <RNAltaGenericaSeguridad3.h>
typedef struct OperacionesGen
{
	const char *chrPtrAlta;
	StcLtaRegComSISCOM *(*FormaAlta)(int ,const char *,StcLtaRegComSISCOM *,int *);
}StcOperacionesGenAlta;

StcOperacionesGenAlta gSOpGenericas[]={ {"RegistraAplicacion",RegistraAplicacion},
					{"RegistraObjetosDeLaAplicacion",RegistraObjetosDeLaAplicacion},
					{"ActualizaObjetosDeLaAplicacion",ActualizaObjetosDeLaAplicacion},
					{"ActualizaAplicacion",ActualizaAplicacion},
					{"RegistraPerfiles",RegistraPerfiles},
					{"RegistraUsuarios",RegistraUsuarios},
					{"RegistraFirmas",RegistraFirmas}
		
				  };

StcDRegistroAValidar gSDRAValidar[]={ 
				       {
					 /* Registro Vacio  0 */
					 {-1},
					 {0,1,2,3,4,5,6,7,-1},
				       },
				       {
					 /* Registro Con el Id Aplicacion  1 */
					 {0,-1},
					 {1,2,3,4,5,6,7,-1}   
					},	
					/* Registro con Nombre de la pantalla 2 */
					{
					  {1,2,3,-1},
					  {0,4,5,6,7,-1}
					},
					/* Registro con el id del objeto  3 */
					{
					  {4,-1},
					  {0,1,2,3,5,6,7,-1}
					},
					/* Registro con los datos del objeto 4 */
					{
					  {5,6,-1},
					  {0,1,2,3,4,7,-1}
					}
				    };
					
			             
int gintNOpGenericas=7;					
StcLtaRegComSISCOM *RegistraFirmas(int pintPtoComAD,
						   const char *pchrPtrDirIpSvrAD,
						   StcLtaRegComSISCOM *pSLRCSisDat,
						   int *pintPtrNRegistros)
{
char *lchrPtrIdAplicacion;
StcLtaRegComSISCOM *lSLRCSisPtrPrimReg=0,
		   *lSLRCSisPtrActualReg=0;
char lchrArrCadInserta[1024];
*pintPtrNRegistros=0;
/*
		SISCOMImprimeContenidoCom(stdout,
					  '|',
					  '\n',
					  pSLRCSisDat);
		SiscomImprimeContenidoCom('|','\n',pSLRCSisDat);
*/
		while(pSLRCSisDat)
		{
		  SISCOMAnexaRegistroFormateandoParaEnvio(&lSLRCSisPtrPrimReg,
							  &lSLRCSisPtrActualReg,
							  pintPtrNRegistros,
							  lchrArrCadInserta,
							  "insert into Firmas values(%s,'%s','%s');",
							  pSLRCSisDat->chrPtrRegistro[1],
							  pSLRCSisDat->chrPtrRegistro[2],
							  pSLRCSisDat->chrPtrRegistro[3]);
		 /*printf("La Cadena %s \n",lchrArrCadInserta); */
		 pSLRCSisDat=pSLRCSisDat->LSRCSISCOMPtrSig;
		}
 return lSLRCSisPtrPrimReg;
}



StcLtaRegComSISCOM *RegistraUsuarios(int pintPtoComAD,
						   const char *pchrPtrDirIpSvrAD,
						   StcLtaRegComSISCOM *pSLRCSisDat,
						   int *pintPtrNRegistros)
{
char *lchrPtrIdAplicacion;
StcLtaRegComSISCOM *lSLRCSisPtrPrimReg=0,
		   *lSLRCSisPtrActualReg=0;
char lchrArrCadInserta[1024];
int lintContador=0;
*pintPtrNRegistros=0;

		SiscomImprimeContenidoCom('|','\n',pSLRCSisDat);
		while(pSLRCSisDat)
		{
		  if(lintContador)
		  SISCOMAnexaRegistroFormateandoParaEnvio(&lSLRCSisPtrPrimReg,
							  &lSLRCSisPtrActualReg,
							  pintPtrNRegistros,
							  lchrArrCadInserta,
							  "insert into Usuarios values(%ld,%s,%s,'%s','%s','%s');",
							  SISCOMObtenNumeroUnico(),
							  pSLRCSisDat->chrPtrRegistro[1],
							  pSLRCSisDat->chrPtrRegistro[2],
							  pSLRCSisDat->chrPtrRegistro[4],
							  pSLRCSisDat->chrPtrRegistro[5],
							  pSLRCSisDat->chrPtrRegistro[6]);
		 /*printf("La Cadena %s \n",lchrArrCadInserta); */
		 pSLRCSisDat=pSLRCSisDat->LSRCSISCOMPtrSig;
		 lintContador++;
		}
 return lSLRCSisPtrPrimReg;
}






StcLtaRegComSISCOM *RegistraPerfiles(int pintPtoComAD,
						   const char *pchrPtrDirIpSvrAD,
						   StcLtaRegComSISCOM *pSLRCSisDat,
						   int *pintPtrNRegistros)
{
char *lchrPtrIdAplicacion;
StcLtaRegComSISCOM *lSLRCSisPtrPrimReg=0,
		   *lSLRCSisPtrActualReg=0;
char lchrArrCadInserta[1024];
long llngIdPerfil;
*pintPtrNRegistros=0;
/*
	LOGSeguridad3("El Perfil Referencia %s\n",pSLRCSisDat->chrPtrRegistro[5]);
*/
	while(pSLRCSisDat)
	{
	SISCOMAnexaRegistroFormateandoParaEnvio(&lSLRCSisPtrPrimReg,
						&lSLRCSisPtrActualReg,
							pintPtrNRegistros,
							lchrArrCadInserta,
							"insert into Perfiles values(%ld,%s,'%s','%s');",
							(llngIdPerfil=SISCOMObtenNumeroUnico()),
							pSLRCSisDat->chrPtrRegistro[2],
							pSLRCSisDat->chrPtrRegistro[3],
							pSLRCSisDat->chrPtrRegistro[4]);
	  if(pSLRCSisDat->chrPtrRegistro[5][0])
	  SISCOMAnexaRegistroFormateandoParaEnvio(&lSLRCSisPtrPrimReg,
						  &lSLRCSisPtrActualReg,
						  pintPtrNRegistros,
						  lchrArrCadInserta,
						  "insert into ObjetosXPantalla ( 		\n\
								        select idPantalla, 	\n\
                                     					       idObjeto, 	\n\
                                     		  			       %ld, 		\n\
                                     					       idPropiedad, 	\n\
                                     					       valorPropiedad,	\n\
									       numobjeto	\n\
                               						from objetosXPantalla 	\n\
                               						where idPerfil=%s)",	
						   llngIdPerfil,
						   pSLRCSisDat->chrPtrRegistro[5]);
	 pSLRCSisDat=pSLRCSisDat->LSRCSISCOMPtrSig;
	}


 return lSLRCSisPtrPrimReg;
}
void ObtenDatosPantalla(char *pchrPtrIdAplicacion,
			StcLtaRegComSISCOM **pSLRCSisDatEntrada,
			StcLtaRegComSISCOM **pSLRCSisPrimResultado,
			StcLtaRegComSISCOM **pSLRCSisActualResultado,
			int *pintPtrNRegistros)
{
char lchrArrCadInsercion[4096],
     lchrArrIdPantalla[22];
static int lintNumPantalla=0;
const char *lchrPtrIdObjeto,
	   *lchrPtrIdPerfil;
int lintNumObjeto=0;
	if(SISCOMValidaRegistro((*pSLRCSisDatEntrada)->chrPtrRegistro,
				gSDRAValidar[2]))
	{
		SISCOMImprimeContenidoRegistro((*pSLRCSisDatEntrada)->chrPtrRegistro,
					       "Inicia Pantalla");	
		sprintf(lchrArrIdPantalla,"%ld",SISCOMObtenNumeroUnico()+lintNumPantalla++);
		lchrPtrIdPerfil=(*pSLRCSisDatEntrada)->chrPtrRegistro[2];
		sprintf(lchrArrCadInsercion,
			"insert into Pantalla values(%s,%s,'%s','%s');",
			lchrArrIdPantalla,
			pchrPtrIdAplicacion,
			(*pSLRCSisDatEntrada)->chrPtrRegistro[1],
			(*pSLRCSisDatEntrada)->chrPtrRegistro[3]);

		 SISCOMAnexaRegistroLEnvio(pSLRCSisPrimResultado,
					   pSLRCSisActualResultado,
					   1,
					   "%s",
					    lchrArrCadInsercion);
		(*pintPtrNRegistros)++;
		lintNumObjeto=0;
	       do
	      {
		    SISCOMImprimeContenidoRegistro((*pSLRCSisDatEntrada)->chrPtrRegistro,
					       "\tDoWhile");	
		while(*pSLRCSisDatEntrada &&
		      !SISCOMValidaRegistro((*pSLRCSisDatEntrada)->chrPtrRegistro, 
					    gSDRAValidar[0]))
		{
		    SISCOMImprimeContenidoRegistro((*pSLRCSisDatEntrada)->chrPtrRegistro,
					       "\tDoWhile>>");	
				
		  if(SISCOMValidaRegistro((*pSLRCSisDatEntrada)->chrPtrRegistro,
					   gSDRAValidar[3])) 
		  {
		    lchrPtrIdObjeto=(*pSLRCSisDatEntrada)->chrPtrRegistro[4];
		    SISCOMImprimeContenidoRegistro((*pSLRCSisDatEntrada)->chrPtrRegistro,
					       "\tIniciaRegistroObjeto");	
		   sprintf(lchrArrCadInsercion,
			   "insert into ObjetosXPantalla values(%s,%s,%s,%s,'%s',%ld);",
			   lchrArrIdPantalla,
			   lchrPtrIdObjeto,
			   lchrPtrIdPerfil, 
			   "0",
			   "IniciaControl",
			   (long )lintNumObjeto);
			lintNumObjeto++;
			 SISCOMAnexaRegistroLEnvio(pSLRCSisPrimResultado,
					   pSLRCSisActualResultado,
					   1,
					   "%s",
					    lchrArrCadInsercion);

			(*pintPtrNRegistros)++;
		  }
		  else
		  {
		  if(SISCOMValidaRegistro((*pSLRCSisDatEntrada)->chrPtrRegistro,
					   gSDRAValidar[4])) 
		  {
		  SISCOMImprimeContenidoRegistro((*pSLRCSisDatEntrada)->chrPtrRegistro,
					       "\t\tControles");
		   sprintf(lchrArrCadInsercion,
			   "insert into ObjetosXPantalla values(%s,%s,%s,%s,'%s',%ld);",
			   lchrArrIdPantalla,
			   lchrPtrIdObjeto,
			   lchrPtrIdPerfil, 
			   (*pSLRCSisDatEntrada)->chrPtrRegistro[5],
			   (*pSLRCSisDatEntrada)->chrPtrRegistro[6],
			   (long )(lintNumObjeto-1));
			 SISCOMAnexaRegistroLEnvio(pSLRCSisPrimResultado,
					   pSLRCSisActualResultado,
					   1,
					   "%s",
					    lchrArrCadInsercion);
		(*pintPtrNRegistros)++;
		    }
			   

		  }
		    *pSLRCSisDatEntrada=(*pSLRCSisDatEntrada)->LSRCSISCOMPtrSig;
		  
		}
		    *pSLRCSisDatEntrada=(*pSLRCSisDatEntrada)->LSRCSISCOMPtrSig;
	      }while(*pSLRCSisDatEntrada &&
                    SISCOMValidaRegistro((*pSLRCSisDatEntrada)->chrPtrRegistro,
					  gSDRAValidar[3]));
	}
}
void ObtenDatosAplicacion(StcLtaRegComSISCOM **pSLRCSisReg,
			  char **pchrPtrIdAplicacion)
{
	*pSLRCSisReg=(*pSLRCSisReg)->LSRCSISCOMPtrSig;
	*pchrPtrIdAplicacion=(*pSLRCSisReg)->chrPtrRegistro[0];
	*pSLRCSisReg=(*pSLRCSisReg)->LSRCSISCOMPtrSig;

}
void FormaCadenaEliminaControlesPantalla(const char *pchrPtrIdAplicacion,
					 const char *pchrPtrIdPantalla,
					 char *pchrPtrCadBorra)
{
	sprintf(pchrPtrCadBorra,
		"delete  		\
		 from objetosxpantalla  \
		 where idPantalla=%s and \
		       idAplicacion=%s",
		 pchrPtrIdPantalla,
		 pchrPtrIdAplicacion);
}
void CreaInsercionesObjetosXPantalla(const char *pchrPtrIdAplicacion,
				     const char *pchrPtrIdPantalla,
				     StcLtaRegComSISCOM **pSLRCSisDatEntrada,	
				     StcLtaRegComSISCOM **pSLRCSisDatSalPrim,
				     StcLtaRegComSISCOM **pSLRCSisDatSalActual)
{
char *lchrPtrIdObjeto;

		(*pSLRCSisDatEntrada)=(*pSLRCSisDatEntrada)->LSRCSISCOMPtrSig;
		if(SISCOMValidaRegistro((*pSLRCSisDatEntrada)->chrPtrRegistro,
				        gSDRAValidar[3]))	
		{
		  lchrPtrIdObjeto=(*pSLRCSisDatEntrada)->chrPtrRegistro[4];
		  printf("\tInicia El Objeto %s\n",lchrPtrIdObjeto);
		}
	  



}
int ValidaRegistroVacio(char **pchrPtrRegistro)
{

	return SISCOMValidaRegistro(pchrPtrRegistro,
				    gSDRAValidar[0]);
}
int ValidaRegistroIdObjeto(char **pchrPtrRegistro)
{
	return SISCOMValidaRegistro(pchrPtrRegistro,
				    gSDRAValidar[3]);
}
void ObtenObjetosAActualizar(StcLtaRegComSISCOM **pSLRCSisDatRegPrim,
			     StcLtaRegComSISCOM **pSLRCSisDatRegActual,
			     StcLtaRegComSISCOM **pSLRCSisEntrada,
			     const char *pchrPtrIdPantalla,
			     const char *pchrPtrIdPerfil,
			     int *pintPtrNRegistros)
{
char lchrArrCadInserta[1024];
char *lchrPtrIdObjeto;

int lintNumObjeto=0;
	while((*pSLRCSisEntrada=(*pSLRCSisEntrada)->LSRCSISCOMPtrSig) &&
	      ValidaRegistroIdObjeto((*pSLRCSisEntrada)->chrPtrRegistro))
	{
	/*
		SISCOMImprimeContenidoRegistro((*pSLRCSisEntrada)->chrPtrRegistro,
					       "\tObjeto");
	*/
		lchrPtrIdObjeto=(*pSLRCSisEntrada)->chrPtrRegistro[4];

		SISCOMAnexaRegistroFormateandoParaEnvio(pSLRCSisDatRegPrim,
						        pSLRCSisDatRegActual,
							pintPtrNRegistros,
							lchrArrCadInserta,
							"insert into ObjetosXPantalla values(%s,%s,%s,%s,'%s',%ld);",
							pchrPtrIdPantalla,
							lchrPtrIdObjeto,
							pchrPtrIdPerfil,
							"0",
							"IniciaControl",
							(long )lintNumObjeto);
							
	   
		
	   while((*pSLRCSisEntrada=(*pSLRCSisEntrada)->LSRCSISCOMPtrSig) &&
	         !ValidaRegistroVacio((*pSLRCSisEntrada)->chrPtrRegistro))
	   {
	   	/*
	     SISCOMMensajesDepuracion("%d %s",lintNumObjeto,(*pSLRCSisEntrada)->chrPtrRegistro[5]);
		SISCOMImprimeContenidoRegistro((*pSLRCSisEntrada)->chrPtrRegistro,
					       "\t\tPropiedades");
	   	*/
		SISCOMAnexaRegistroFormateandoParaEnvio(pSLRCSisDatRegPrim,
						        pSLRCSisDatRegActual,
							pintPtrNRegistros,
							lchrArrCadInserta,
							"insert into ObjetosXPantalla values(%s,%s,%s,%s,'%s',%ld);",
							pchrPtrIdPantalla,
							lchrPtrIdObjeto,
							pchrPtrIdPerfil,
							(*pSLRCSisEntrada)->chrPtrRegistro[5],
							(*pSLRCSisEntrada)->chrPtrRegistro[6],
							(long )lintNumObjeto);
		
	   }

	  lintNumObjeto++;
	}

}
StcLtaRegComSISCOM *ActualizaObjetosDeLaAplicacion(int pintPtoComAD,
						   const char *pchrPtrDirIpSvrAD,
						   StcLtaRegComSISCOM *pSLRCSisDat,
						   int *pintPtrNRegistros)
{
char *lchrPtrIdAplicacion;
StcLtaRegComSISCOM *lSLRCSisPtrPrimReg=0,
		   *lSLRCSisPtrActualReg=0;
char lchrArrCadBorrando[512];
*pintPtrNRegistros=0;
		ObtenDatosAplicacion(&pSLRCSisDat,
			             &lchrPtrIdAplicacion);
	/*	SiscomImprimeContenidoCom('|','\n',pSLRCSisDat); */
		SISCOMMensajesDepuracion("La Aplicacion %s",lchrPtrIdAplicacion);
		while(pSLRCSisDat)
		{
		   if(SISCOMValidaRegistro(pSLRCSisDat->chrPtrRegistro,
					   gSDRAValidar[2]))
		   {
		     SISCOMMensajesDepuracion("La Pantalla %s El Perfil %s",
				pSLRCSisDat->chrPtrRegistro[1],
				pSLRCSisDat->chrPtrRegistro[2]);

		     SISCOMAnexaRegistroFormateandoParaEnvio(&lSLRCSisPtrPrimReg,
							     &lSLRCSisPtrActualReg,
							     pintPtrNRegistros,
							     lchrArrCadBorrando,		
							     "delete \
							      from ObjetosXPantalla \
							      where idPantalla=%s and \
								     idPerfil=%s;",
							     pSLRCSisDat->chrPtrRegistro[1],
							     pSLRCSisDat->chrPtrRegistro[2]);

			
							     
		     ObtenObjetosAActualizar(&lSLRCSisPtrPrimReg,
					     &lSLRCSisPtrActualReg,
					     &pSLRCSisDat,
					     pSLRCSisDat->chrPtrRegistro[1],
					     pSLRCSisDat->chrPtrRegistro[2],
					     pintPtrNRegistros);
		     	
			
		   }  
		   pSLRCSisDat=pSLRCSisDat->LSRCSISCOMPtrSig;

		}
/*
SISCOMImprimeContenidoCom2(stdout,"ActualizaObjetosDeLaAplicacion",'|','\n',lSLRCSisPtrPrimReg);
SiscomImprimeContenidoCom('|','\n',lSLRCSisPtrPrimReg);
*/
SISCOMMensajesDepuracion("Se Enviaran %d Registros",*pintPtrNRegistros);
	return lSLRCSisPtrPrimReg;
}
int ValidaQueEstaLaPantalla(int pintPtoComAD,
			    const char *pchrPtrDirIpSvr,
			    const char *pchrPtrIdAplicacion,
			    const char *pchrPtrNmbPantalla,
			    char *pchrPtrIdPantalla)
{
char lchrArrCadenaCns[128];
int lintNRegistros;
StcLtaRegComSISCOM *lSLRCSisRegreso=0;
		sprintf(lchrArrCadenaCns,
			"select *			\
			 from pantalla 			\
			 where idAplicacion=%s and 	\
			       NmbClase='%s'",
			 pchrPtrIdAplicacion,
			 pchrPtrNmbPantalla);
	SISCOMEnviaYRecibeCadenasAD(pintPtoComAD,
				    pchrPtrDirIpSvr,
				    "hgarduno",
				    "hgarduno",
				    "libADConsultaGenericaSeguridad3.so",
				    "ADConsultas",
				     &lintNRegistros,
				     &lSLRCSisRegreso,
				     "%s",
				     lchrArrCadenaCns);
	if(lintNRegistros)
	 strcpy(pchrPtrIdPantalla,lSLRCSisRegreso->chrPtrRegistro[0]);
	else
	 pchrPtrIdPantalla[0]=0;
	return lintNRegistros ;


}
void ObtenControlesDeLaPantalla(const char *pchrPtrIdAplicacion,
				StcLtaRegComSISCOM *pSLRCSisDat,
				StcLtaRegComSISCOM **pSLRCSisControles)
{
const char *lchrPtrNmbForma;
const char *lchrPtrIdControl;
StcLtaRegComSISCOM *lSLRCSisActual=0;
	lchrPtrNmbForma=pSLRCSisDat->chrPtrRegistro[1];
	for(;
	    pSLRCSisDat &&
	    !SISCOMValidaRegistro(pSLRCSisDat->chrPtrRegistro,
			         gSDRAValidar[0]);
	    pSLRCSisDat=pSLRCSisDat->LSRCSISCOMPtrSig)
	{
	  if(SISCOMValidaRegistro(pSLRCSisDat->chrPtrRegistro,
				  gSDRAValidar[3]))
	  {
	  lchrPtrIdControl=pSLRCSisDat->chrPtrRegistro[4];
	  for(;
	       pSLRCSisDat &&
	       !SISCOMValidaRegistro(pSLRCSisDat->chrPtrRegistro,
				     gSDRAValidar[0]);
	       pSLRCSisDat=pSLRCSisDat->LSRCSISCOMPtrSig)
	   {
	        if(SISCOMValidaRegistro(pSLRCSisDat->chrPtrRegistro,
				        gSDRAValidar[4]))
		  SISCOMAnexaRegistroLEnvio(
				pSLRCSisControles,
				&lSLRCSisActual,
				4,
				"%s%s%s%s",
				lchrPtrNmbForma,
				lchrPtrIdControl,
				pSLRCSisDat->chrPtrRegistro[5],
				pSLRCSisDat->chrPtrRegistro[6]);
	   }
	   
		   SISCOMAnexaRegistroLEnvio(
				pSLRCSisControles,
				&lSLRCSisActual,
				4,
				"%s%s%s%s",
				"",
				"",
				"",
				"");

	  
	  }  

	}
}
void ObtenPerfilesDeLaAplicacion(int pintPtoComAD,
				 const char *pchrPtrDirIpSvr,
				 const char *pchrPtrIdAplicacion,
				 StcLtaRegComSISCOM **pSLRCSisPerfiles)
{
char lchrArrCadenaCns[128];
int lintNRegistros;
		sprintf(lchrArrCadenaCns,
			"select	idPerfil	\
			 from perfiles 		\
			 where idAplicacion=%s",
			pchrPtrIdAplicacion);
	SISCOMEnviaYRecibeCadenasAD(pintPtoComAD,
				    pchrPtrDirIpSvr,
				    "hgarduno",
				    "hgarduno",
				    "libADConsultaGenericaSeguridad3.so",
				    "ADConsultas",
				     &lintNRegistros,
				     pSLRCSisPerfiles,
				     "%s",
				     lchrArrCadenaCns);
}
void GeneraActualizacionPantalla(StcLtaRegComSISCOM *pSLRCSisPerfiles,
				 StcLtaRegComSISCOM *pSLRCSisControles,
				 const char *pchrPtrIdAplicacion,
				 const char *pchrPtrIdPantalla,
				 StcLtaRegComSISCOM **pSLRCSisActualizaPrim,
				 StcLtaRegComSISCOM **pSLRCSisActualizaAct,
			 	 int *pintPtrNRegActualiza)
{
char lchrArrBuffer[1024];
int lintNumObjeto=0;
StcLtaRegComSISCOM *lSLRCSisControles=pSLRCSisControles;

		SISCOMAnexaRegistroFormateandoParaEnvio(
		pSLRCSisActualizaPrim,
		pSLRCSisActualizaAct,
		pintPtrNRegActualiza,
		lchrArrBuffer,
		"delete from objetosxpantalla \
		 where idPantalla=%s;",
		 pchrPtrIdPantalla);
		 /*
	SISCOMImprimeContenidoCom(stdout,
				  '|',
				  '\n',
				  pSLRCSisPerfiles);
	SiscomImprimeContenidoCom('|','\n',pSLRCSisPerfiles);
	*/
	    for(;
		pSLRCSisPerfiles;
		pSLRCSisPerfiles=pSLRCSisPerfiles->LSRCSISCOMPtrSig)
	   {
	     LOGSeguridad3("Perfil %s\n",pSLRCSisPerfiles->chrPtrRegistro[0]);
	     for(lSLRCSisControles=pSLRCSisControles;
		 lSLRCSisControles;
		 lSLRCSisControles=lSLRCSisControles->LSRCSISCOMPtrSig)
	      {
	        SISCOMAnexaRegistroFormateandoParaEnvio(
		pSLRCSisActualizaPrim,
		pSLRCSisActualizaAct,
		pintPtrNRegActualiza,
		lchrArrBuffer,
		"insert into objetosxpantalla values(%s,%s,%s,0,'IniciaControl',%ld);",
		pchrPtrIdPantalla,
		lSLRCSisControles->chrPtrRegistro[1],
		pSLRCSisPerfiles->chrPtrRegistro[0],
		(long )lintNumObjeto);
		/*LOGSeguridad3("buffer %s \n",lchrArrBuffer); */
		 for(;
		     lSLRCSisControles &&
		     !SISCOMEsRegistroVacio(lSLRCSisControles->chrPtrRegistro);
		     lSLRCSisControles=lSLRCSisControles->LSRCSISCOMPtrSig)
		 {
		SISCOMAnexaRegistroFormateandoParaEnvio(
		pSLRCSisActualizaPrim,
		pSLRCSisActualizaAct,
		pintPtrNRegActualiza,
		lchrArrBuffer,
		"insert into objetosxpantalla values(%s,%s,%s,%s,'%s',%ld);",
		pchrPtrIdPantalla,
		lSLRCSisControles->chrPtrRegistro[1],
		pSLRCSisPerfiles->chrPtrRegistro[0],
		lSLRCSisControles->chrPtrRegistro[2],
		lSLRCSisControles->chrPtrRegistro[3],
		(long )lintNumObjeto);
	        /*LOGSeguridad3("\t\tbuffer %s \n",lchrArrBuffer); */
		 }
		 lintNumObjeto++;
	      }

	     	
	   }

}
void GeneraInsercionesPantalla(StcLtaRegComSISCOM *pSLRCSisPerfiles,
			       StcLtaRegComSISCOM *pSLRCSisControles,
			       const char *pchrPtrIdAplicacion,
			       int pintContador,
			       StcLtaRegComSISCOM **pSLRCSisActualizaPrim,
			       StcLtaRegComSISCOM **pSLRCSisActualizaAct,
			       int *pintPtrNRegActualiza)
{
char lchrArrBuffer[1024];
long llngIdPantalla;
StcLtaRegComSISCOM *lSLRCSisControles=pSLRCSisControles;
	SISCOMAnexaRegistroFormateandoParaEnvio(
		pSLRCSisActualizaPrim,
		pSLRCSisActualizaAct,
		pintPtrNRegActualiza,
		lchrArrBuffer,
		"insert into Pantalla values(%ld,%s,'%s','No Disponible');",
		(llngIdPantalla=SISCOMObtenNumeroUnico()+pintContador),
		pchrPtrIdAplicacion,
		lSLRCSisControles->chrPtrRegistro[0]);
	for(;
	    pSLRCSisPerfiles;
	    pSLRCSisPerfiles=pSLRCSisPerfiles->LSRCSISCOMPtrSig)
	{
	LOGSeguridad3("Perfiles %s\n",pSLRCSisPerfiles->chrPtrRegistro[0]);
	for(lSLRCSisControles=pSLRCSisControles;
	    lSLRCSisControles;
	    lSLRCSisControles=lSLRCSisControles->LSRCSISCOMPtrSig)
	{
	 SISCOMAnexaRegistroFormateandoParaEnvio(
		pSLRCSisActualizaPrim,
		pSLRCSisActualizaAct,
		pintPtrNRegActualiza,
		lchrArrBuffer,
		"insert into objetosxpantalla values(%ld,%s,%s,0,'IniciaControl');",
		llngIdPantalla,
		lSLRCSisControles->chrPtrRegistro[1],
		pSLRCSisPerfiles->chrPtrRegistro[0]);

	    for(;
		lSLRCSisControles &&
		!SISCOMEsRegistroVacio(lSLRCSisControles->chrPtrRegistro);
		lSLRCSisControles=lSLRCSisControles->LSRCSISCOMPtrSig)
	    {
	
	       SISCOMAnexaRegistroFormateandoParaEnvio(
		pSLRCSisActualizaPrim,
		pSLRCSisActualizaAct,
		pintPtrNRegActualiza,
		lchrArrBuffer,
		"insert into objetosxpantalla values(%ld,%s,%s,%s,'%s');",
		llngIdPantalla,
		lSLRCSisControles->chrPtrRegistro[1],
		pSLRCSisPerfiles->chrPtrRegistro[0],
		lSLRCSisControles->chrPtrRegistro[2],
		lSLRCSisControles->chrPtrRegistro[3]);
		 
	    } 
	}
	}


}
StcLtaRegComSISCOM *ActualizaAplicacion(int pintPtoComAD,
						   const char *pchrPtrDirIpSvrAD,
						   StcLtaRegComSISCOM *pSLRCSisDat,
						   int *pintPtrNRegistros)
{
int lintNRegistros;
char *lchrPtrIdAplicacion;
StcLtaRegComSISCOM *lSLRCSisPerfiles=0;
StcLtaRegComSISCOM *lSLRCSisControles=0;
StcLtaRegComSISCOM *lSLRCSisActualizacionPrim=0;
StcLtaRegComSISCOM *lSLRCSisActualizacionActual=0;
int lintContador=0;
int lintNRegistrosActualizacion=0;
char lchrArrIdPantalla[25];
*pintPtrNRegistros=0;
	pSLRCSisDat=pSLRCSisDat->LSRCSISCOMPtrSig;
	ObtenIdAplicacion(pSLRCSisDat->chrPtrRegistro,&lchrPtrIdAplicacion);
	ObtenPerfilesDeLaAplicacion(pintPtoComAD,
				    pchrPtrDirIpSvrAD,
				    lchrPtrIdAplicacion,
				    &lSLRCSisPerfiles);

	for(;
	    pSLRCSisDat;
	    pSLRCSisDat=pSLRCSisDat->LSRCSISCOMPtrSig)
	   if(SISCOMValidaRegistro(pSLRCSisDat->chrPtrRegistro,
				   gSDRAValidar[2]))
	   {
	      if(ValidaQueEstaLaPantalla(pintPtoComAD,
					 pchrPtrDirIpSvrAD,
					 lchrPtrIdAplicacion,
					 pSLRCSisDat->chrPtrRegistro[1],
					 lchrArrIdPantalla))
	      {
		LOGSeguridad3("Se actualiza la pantalla {%s} {%s}\n",
			 pSLRCSisDat->chrPtrRegistro[1],
			 lchrArrIdPantalla);
				
		 ObtenControlesDeLaPantalla(lchrPtrIdAplicacion,
					pSLRCSisDat,
				        &lSLRCSisControles);
		if(lSLRCSisControles)	
		GeneraActualizacionPantalla(
				lSLRCSisPerfiles,
				lSLRCSisControles,
				lchrPtrIdAplicacion,
				lchrArrIdPantalla,
				&lSLRCSisActualizacionPrim,
				&lSLRCSisActualizacionActual,
				pintPtrNRegistros);

	      }
	      else
	      {
		 LOGSeguridad3("Se Inserta la pantalla {%s} {%s}.....\n",
			 pSLRCSisDat->chrPtrRegistro[1],
			 lchrArrIdPantalla);


		 ObtenControlesDeLaPantalla(lchrPtrIdAplicacion,
					pSLRCSisDat,
				        &lSLRCSisControles);

		if(lSLRCSisControles)	
		 GeneraInsercionesPantalla(lSLRCSisPerfiles,
					   lSLRCSisControles,
					   lchrPtrIdAplicacion,
					   lintContador++,
					   &lSLRCSisActualizacionPrim,
					   &lSLRCSisActualizacionActual,
					   pintPtrNRegistros);
	      }
		lSLRCSisControles=0;
	   }
/*
SiscomImprimeContenidoCom('|','\n',lSLRCSisActualizacionPrim);
*/
LOGSeguridad3("Se enviaron %d Registros ----\n",*pintPtrNRegistros);
	return lSLRCSisActualizacionPrim;
}
void ObtenIdAplicacion(char **pchrPtrRegistro,
		       char **pchrPtrIdAplicacion)
{

	*pchrPtrIdAplicacion=pchrPtrRegistro[0];

}
StcLtaRegComSISCOM *RegistraObjetosDeLaAplicacion(int pintPtoComAD,
					     const char *pchrPtrSvrAD,
					     StcLtaRegComSISCOM *pSLRCSisDat,
						   int *pintPtrNCampos)
{
StcLtaRegComSISCOM *lSLRCSisPtrPrimReg=0,
		   *lSLRCSisPtrActualReg=0;
char *lchrArrIdAplicacion;

	*pintPtrNCampos=0;
	SISCOMImprimeContenidoCom2(stdout,
				   "RegistraObjetosDeLaAplicacion",
				   '|',
				   '\n',
				   pSLRCSisDat);
	SiscomImprimeContenidoCom('|','\n',pSLRCSisDat);
	/** Salta el movimiento en la alta generica */
	pSLRCSisDat=pSLRCSisDat->LSRCSISCOMPtrSig;

	ObtenIdAplicacion(pSLRCSisDat->chrPtrRegistro,&lchrArrIdAplicacion);

	/** Salta el id De La Aplicacion*/
	pSLRCSisDat=pSLRCSisDat->LSRCSISCOMPtrSig;
	while(pSLRCSisDat)
	{
	   ObtenDatosPantalla(lchrArrIdAplicacion,
			      &pSLRCSisDat,
			      &lSLRCSisPtrPrimReg,
			      &lSLRCSisPtrActualReg,
			      pintPtrNCampos);
	   
	   pSLRCSisDat= pSLRCSisDat ? pSLRCSisDat->LSRCSISCOMPtrSig:0;
	}
	
	SISCOMImprimeContenidoCom2(stdout,
				   "RegistraObjetosDeLaAplicacion",
				   '|',
				   '\n',
				   lSLRCSisPtrPrimReg);
	SiscomImprimeContenidoCom('|','\n',lSLRCSisPtrPrimReg);
	printf("El Numero de Registros a insertar %d\n",*pintPtrNCampos);
	return lSLRCSisPtrPrimReg;
}

StcLtaRegComSISCOM *RegistraAplicacion(int pintPtoComAD,
					     const char *pchrPtrSvrAD,
					     StcLtaRegComSISCOM *pSLRCSisDat,
						   int *pintPtrNCampos)
{
StcLtaRegComSISCOM *lSLRCSisPtrPrimReg=0,
		   *lSLRCSisPtrActualReg=0;
int lintNRegistrosBD;
char lchrArrCadInsercion[256];
		(*pintPtrNCampos)=0;
	      while(pSLRCSisDat)
	      {
		   sprintf(lchrArrCadInsercion,
			   "insert into aplicaciones values(%s,'%s','%s','%s');",
			   pSLRCSisDat->chrPtrRegistro[1], 
			   pSLRCSisDat->chrPtrRegistro[2], 
			   pSLRCSisDat->chrPtrRegistro[3], 
			   pSLRCSisDat->chrPtrRegistro[4]);
		   SISCOMAnexaRegistroLEnvio(&lSLRCSisPtrPrimReg,
					     &lSLRCSisPtrActualReg,
					     1,
					     "%s",
					     lchrArrCadInsercion);
		  (*pintPtrNCampos)++;
		 pSLRCSisDat=pSLRCSisDat->LSRCSISCOMPtrSig;
	      }
	return lSLRCSisPtrPrimReg;
}
StcLtaRegComSISCOM *SeleccionaAlta(int pintPtoComAD,
				   const char *pchrPtrSvrAD,
				   StcLtaRegComSISCOM *pSLRCSisDat,
				       int *pintPtrNRegistros)
{
int lintContador;
		for(lintContador=0;
		    lintContador<gintNOpGenericas;
		    lintContador++)
		 if(!strcmp(gSOpGenericas[lintContador].chrPtrAlta,
		            pSLRCSisDat->chrPtrRegistro[0]))
		  return gSOpGenericas[lintContador].FormaAlta(pintPtoComAD,
							       pchrPtrSvrAD,
								pSLRCSisDat,
								   pintPtrNRegistros);

}
StcLtaRegComSISCOM *EjecutaAlta(int pintPtoComAD,
				    const char *pchrPtrDirIpSvrAD,
				    StcLtaRegComSISCOM *pSLRCSisDat,
				    int *pintPtrNReg)
{
	
	return SeleccionaAlta(pintPtoComAD,
			      pchrPtrDirIpSvrAD,
			      pSLRCSisDat,
			      pintPtrNReg);
}
int RNAltaGenerica(int pintSCliente,
		       int pintTuberia[],
		       int pintPtoComAD,
		       char *pchrPtrDirIpSvrAD)
{

	SISCOMEjecutaConsultaSvrSiscomYEnviaAlCliente2(pintSCliente,
						       pintPtoComAD,
						       pchrPtrDirIpSvrAD,
						       "hgarduno",
						       "hgarduno",
						       "libADAltaGenericaSeguridad3.so",
                                      			"ADComandosAlta",
						       EjecutaAlta);
}

