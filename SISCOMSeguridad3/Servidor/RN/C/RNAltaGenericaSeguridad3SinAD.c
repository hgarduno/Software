#include <RNAltaGenericaSeguridad3SinAD.h>
typedef struct OperacionesGen
{
	const char *chrPtrAlta;
	StcLtaRegComSISCOM *(*FormaAlta)(int ,const char *,StcLtaRegComSISCOM *,int *);
}StcOperacionesGenAlta;

StcOperacionesGenAlta gSOpGenericas[]={ {"RegistraPantalla",RegistraObjetosXPantalla},
					{"VerificaAplicacion",VerificaAplicacion}
				  };
			             
int gintNOpGenericas=2;					
/*
StcLtaRegComSISCOM *RegistraAplicacion(int pintPtoComAD,
				       const char *pchrPtrDirIpSvrAD,
				       StcLtaRegComSISCOM *pSLRCSisDat,
					int *pintPtrNRegistros)
{
StcLtaRegComSISCOM *lSLRCSisPtrPrimReg=0,
		   *lSLRCSisPtrActualReg=0;
int lintNRegistrosBD;
int lintContador=0;	
char lchrArrCadInsercion[256];
	      while(pSLRCSisDat)
	      {
		if(lintContador)
		{
		   sprintf(lchrArrCadInsercion,
			   "insert int aplicaciones values(%s,'%s','%s','%s')",
			   pSLRCSisDat->chrPtrRegistro[0], 
			   pSLRCSisDat->chrPtrRegistro[1], 
			   pSLRCSisDat->chrPtrRegistro[2], 
			   pSLRCSisDat->chrPtrRegistro[3]);
		   SISCOMAnexaRegistroLEnvio(&lSLRCSisPtrPrimReg,
					     &lSLRCSisPtrActualReg,
					     1,
					     "%s",
					     lchrArrCadInsercion);
		}	
		 lintContador++;
		 pSLRCSisDat=pSLRCSisDat->LSRCSISCOMPtrSig;
	      }
			
	
}
*/



StcLtaRegComSISCOM *GeneraIdenticadorAplicacion()
{
StcLtaRegComSISCOM *lSLRCSisPtrPrimReg=0,
		   *lSLRCSisPtrActualReg=0;
char lchrArrCadId[25];

sprintf(lchrArrCadId,"%ld",SISCOMObtenNumeroUnico());
SISCOMAnexaRegistroLEnvio(&lSLRCSisPtrPrimReg,
					  &lSLRCSisPtrActualReg,
					  1,
					  "%s",
					  lchrArrCadId);
return lSLRCSisPtrPrimReg;

}

StcLtaRegComSISCOM *VerificaAplicacion(int pintPtoComAD,
				       const char *pchrPtrDirIpSvrAD,
				       StcLtaRegComSISCOM *pSLRCSisDat,
					int *pintPtrNRegistros)
{
StcLtaRegComSISCOM *lSLRCSisPtrPrimReg=0,
		   *lSLRCSisPtrActualReg=0;
int lintNRegistrosBD;
char lchrArrCadReg[128];
		sprintf(lchrArrCadReg,
			"select * \
                         from aplicaciones \
                         where nmbaplicacion like '%%%s%%'",
			 pSLRCSisDat->chrPtrRegistro[1]);
		SISCOMEnviaYRecibeCadenasAD(pintPtoComAD,
					    pchrPtrDirIpSvrAD,
					    "hgarduno",
					    "hgarduno",
					      "libADConsultaGenericaSeguridad3.so",
					      "ADConsultas",
					     &lintNRegistrosBD,
					     &lSLRCSisPtrActualReg,
					     "%s",
					      lchrArrCadReg);
					    

	 *pintPtrNRegistros=1;
		if(!lintNRegistrosBD)
		return GeneraIdenticadorAplicacion();
		else
		return lSLRCSisPtrActualReg;
}


void ObtenObjetosDeLaBD(int pintPtoComAD,
			const char *pchrPtrDirIpSvrAD,
			StcLtaRegComSISCOM **pSLRCSisRegBD)
{
StcLtaRegComSISCOM *lSLRCSisPtrPrimReg=0,
		   *lSLRCSisPtrActualReg=0;
int lintNRegistrosBD;
char lchrArrCadReg[128];
		sprintf(lchrArrCadReg,
			"select * \
			 from objeto as a inner join \
                              propiedades as b using(idObjeto) \
			 where b.idPropiedad>0;");
		SISCOMAnexaRegistroLEnvio(&lSLRCSisPtrPrimReg,
					  &lSLRCSisPtrActualReg,
					  1,
					  "%s",
					  lchrArrCadReg);
		SISCOMEnviaInformacionAlSvrAD(pintPtoComAD,
					      pchrPtrDirIpSvrAD,
					      "hgarduno",
					      "hgarduno",
					      "libADConsultaGenericaSeguridad3.so",
					      "ADConsultas",
					      1,
					      lSLRCSisPtrPrimReg,
					      pSLRCSisRegBD,
					      &lintNRegistrosBD);
					      
}
void AsignaPropiedadesDelObjeto(char **pchrPtrRegistro,
				StcLtaRegComSISCOM *pSLRCSisDatObjBD,
				StcLtaRegComSISCOM **pSLRCSisRegCopiadoPrim,
				StcLtaRegComSISCOM **pSLRCSisRegCopiadoActual,
				int *pintPtrNRegistros)
{
/*
	       printf("Analizando [%s,%s]\n",
	 	      pchrPtrRegistro[2],
		      pchrPtrRegistro[3]);
*/

	  for(;pSLRCSisDatObjBD;pSLRCSisDatObjBD=pSLRCSisDatObjBD->LSRCSISCOMPtrSig)
	  { 
/*
	    printf("\tDato Entrada %s,BD %s Id Objeto [%s]\n",
		   pchrPtrRegistro[2],
		   pSLRCSisDatObjBD->chrPtrRegistro[1],
		   pSLRCSisDatObjBD->chrPtrRegistro[0]);
*/

	   if(!strcmp(pchrPtrRegistro[2],
		      pSLRCSisDatObjBD->chrPtrRegistro[1]))
	   {
/*
		printf("\t\tAsignando -> %s %s\n",
		       pchrPtrRegistro[2],
		       pchrPtrRegistro[3]);
*/
		SISCOMAnexaRegistroLEnvio(pSLRCSisRegCopiadoPrim,
					  pSLRCSisRegCopiadoActual,
					  5,
					  "%s%s%s%s%s",
					  pchrPtrRegistro[2],
					  pchrPtrRegistro[3],
					  pSLRCSisDatObjBD->chrPtrRegistro[0],
					  "",
					  "");
		(*pintPtrNRegistros)++;	
	
		while(pSLRCSisDatObjBD &&
		      !strcmp(pchrPtrRegistro[2],
		      pSLRCSisDatObjBD->chrPtrRegistro[1]))
		{

/*		   printf("\t\t\tAsignando Propiedad %s\n",pSLRCSisDatObjBD->chrPtrRegistro[3]);*/
				SISCOMAnexaRegistroLEnvio(pSLRCSisRegCopiadoPrim,
					  pSLRCSisRegCopiadoActual,
					  5,
					  "%s%s%s%s%s",
					  pchrPtrRegistro[2],
					  "",
					  pSLRCSisDatObjBD->chrPtrRegistro[0],
					  pSLRCSisDatObjBD->chrPtrRegistro[3],
					  pSLRCSisDatObjBD->chrPtrRegistro[2]);
					  
		(*pintPtrNRegistros)++;	
	        pSLRCSisDatObjBD=pSLRCSisDatObjBD->LSRCSISCOMPtrSig;
		}
				SISCOMAnexaRegistroLEnvio(pSLRCSisRegCopiadoPrim,
					  pSLRCSisRegCopiadoActual,
					  5,
					  "%s%s%s%s%s",
					  "",
					  "",
					  "",
					  "",
					  "");
		(*pintPtrNRegistros)++;	
	      return ;
	   }
	  }


}
void AsignaPropiedadesEntradaABD(StcLtaRegComSISCOM *pSLRCSisDatEnt,
				 StcLtaRegComSISCOM *pSLRCSisObjBD,
				 StcLtaRegComSISCOM **pSLRCSisDatSalida,
			         int *pintPtrNRegistros)
{
StcLtaRegComSISCOM *lSLRCSisPtrActual=0;

	while(pSLRCSisDatEnt)
	{
	  AsignaPropiedadesDelObjeto(pSLRCSisDatEnt->chrPtrRegistro,
				     pSLRCSisObjBD,
				     pSLRCSisDatSalida,
				     &lSLRCSisPtrActual,
				     pintPtrNRegistros);
	
	 pSLRCSisDatEnt=pSLRCSisDatEnt->LSRCSISCOMPtrSig; 

	}




}

StcLtaRegComSISCOM *RegistraObjetosXPantalla(int pintPtoComAD,
					     const char *pchrPtrSvrAD,
					     StcLtaRegComSISCOM *pSLRCSisDat,
						   int *pintPtrNCampos)
{
StcLtaRegComSISCOM *lSLRCSisPtrPrimReg=0;
StcLtaRegComSISCOM *lSLRCSisPtrObjBD=0;

char lchrArrCadCns[128];
int lintContador=0;
		*pintPtrNCampos=0;
/*		
		
		SISCOMImprimeContenidoCom(stdout,
					  '|',
					  '\n',
					  pSLRCSisDat);
*/

		ObtenObjetosDeLaBD(pintPtoComAD,pchrPtrSvrAD,&lSLRCSisPtrObjBD);
/*
		SISCOMImprimeContenidoCom(stdout,
					  '\t',
					  '\n',
					  lSLRCSisPtrObjBD);
*/	
	AsignaPropiedadesEntradaABD(pSLRCSisDat,
				    lSLRCSisPtrObjBD,
				    &lSLRCSisPtrPrimReg,
				    pintPtrNCampos);
/*
printf("El Numero De Registros %d\n",*pintPtrNCampos);				
		SISCOMImprimeContenidoCom(stdout,
					  '|',
					  '\n',
					  lSLRCSisPtrPrimReg);

*/
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
			      pSLRCSisDat,pintPtrNReg);
}
int RNAltaGenericaSinAD(int pintSCliente,
		       int pintTuberia[],
		       int pintPtoComAD,
		       char *pchrPtrDirIpSvrAD)
{


	SISCOMEjecutaConsultaSvrSiscomYEnviaAlClienteSinEnvioAD(pintSCliente,
						       pintPtoComAD,
						       pchrPtrDirIpSvrAD,
						       EjecutaAlta);
}

