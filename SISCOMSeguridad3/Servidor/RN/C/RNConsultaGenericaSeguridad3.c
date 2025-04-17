#include <RNConsultaGenericaSeguridad3.h>
#include <RNAltaGenericaSeguridad3.h>
#include <FuncionesComunes.h>
typedef struct OperacionesGen
{
	const char *chrPtrConsulta;
	StcLtaRegComSISCOM *(*FormaConsulta)(int ,const char *,StcLtaRegComSISCOM *,int *);
}StcOperacionesGen;

StcOperacionesGen gSOpGenericas[]={ 
	{"VerificaAplicacion",VerificaAplicacion},
	{"ConsultaObjetosDeLaForma",ConsultaObjetosDeLaForma},
	{"VerificaQueEsteRegistradaLaAplicacion",VerificaQueEsteRegistradaLaAplicacion},
	{"ConsultaPantallasAplicacion",ConsultaPantallasAplicacion},
	{"ObtenPerfilesAplicacion",ObtenPerfilesAplicacion},
	{"ObtenPerfilesAplicacionConPantallas", ObtenPerfilesAplicacionConPantallas},
	{"ConsultaUsuariosXPerfil", ConsultaUsuariosXPerfil},
	{"ConsultaObjetosEnBD", ConsultaObjetosEnBD},
	{"ConsultaObjetosXNombre", ConsultaObjetosXNombre},
	{"ValidaFirma", ValidaFirma},
	{"ValidaPerfil",ValidaPerfil},
 	{"RegistraUsuarioDeUnaAplicacion",RegistraUsuarioDeUnaAplicacion}
				  };
			             
int gintNOpGenericas=12;				



long ObtenIdAplicacion(int pintPtoComAD,
		       const char *pchrPtrDirIp,
			const char *pchrPtrNmbAplicacion);



void ObtenIdsConsulta(StcLtaRegComSISCOM *pSLRCSisDat,
		      char **pchrPtrIdAplicacion,
		      char **pchrPtrIdPantalla,
		      char **pchrPtrIdPerfil);
StcLtaRegComSISCOM *ValidaPerfil(int pintPtoComAD,
				 const char *pchrPtrDirIpSvrAD,
				 StcLtaRegComSISCOM *pSLRCSisDat,
				 int *pintPtrNRegistros)
{
StcLtaRegComSISCOM *lSLRCSisPtrPrimReg=0,
		   *lSLRCSisPtrActualReg=0;
char lchrArrCadCns[1024];
	*pintPtrNRegistros=0;
	 SISCOMAnexaRegistroFormateandoParaEnvio(
			&lSLRCSisPtrPrimReg,
                        &lSLRCSisPtrActualReg,
                        pintPtrNRegistros,
                        lchrArrCadCns,
			"\
			SELECT idUsuario \
				from	aplicaciones,\
					firmas 	\
					inner join usuarios using( idUsuario) 	\
					inner join perfiles using(idPerfil) 	\
			where firma='%s' 	and 				\
			      nmbPerfil='%s'	and				\
			      NmbAplicacion='%s'",
			     pSLRCSisDat->chrPtrRegistro[1],
			     pSLRCSisDat->chrPtrRegistro[3],
			     pSLRCSisDat->chrPtrRegistro[2]); 
			

	return lSLRCSisPtrPrimReg;
}
StcLtaRegComSISCOM *ValidaFirma(int pintPtoComAD,
				const char *pchrPtrDirIpSvrAD,
				StcLtaRegComSISCOM *pSLRCSisDat,
				int *pintPtrNRegistros)
{
StcLtaRegComSISCOM *lSLRCSisPtrPrimReg=0,
		   *lSLRCSisPtrActualReg=0;
char lchrArrCadCns[1024];

	*pintPtrNRegistros=0;
	 SISCOMAnexaRegistroFormateandoParaEnvio(&lSLRCSisPtrPrimReg,
                                                 &lSLRCSisPtrActualReg,
                                                 pintPtrNRegistros,
                                                 lchrArrCadCns,
				                 "\
						 SELECT  case when \
						              cast('%s' as varchar(30))=c.password \
							  then 1 \
							  else 0 \
							  end,   \
							  idAplicacion\
				                  from aplicaciones inner join \
						       usuarios as b using(idAplicacion) inner join \
						       firmas as c using(idUsuario) \
						  where NmbAplicacion='%s' and firma='%s';",
						 pSLRCSisDat->chrPtrRegistro[2],
						 pSLRCSisDat->chrPtrRegistro[3],
						 pSLRCSisDat->chrPtrRegistro[1]);
	printf("%s\n",lchrArrCadCns);

	return lSLRCSisPtrPrimReg;

}
long ObtenIdPerfil(int pintPtoComAD,
		       const char *pchrPtrDirIp,
			const char *pchrPtrNmbPerfil,
			long plngIdAplicacion)
{
int lintNRegistros;
StcLtaRegComSISCOM *lSLRCSisDat=0;
char lchrArrCadConsulta[256];

	sprintf(lchrArrCadConsulta,
		"select idPerfil \
		 from perfiles \
		 where NmbPerfil='%s' and \
		       idAplicacion=%ld",
		pchrPtrNmbPerfil,
		plngIdAplicacion);
	printf("%s\n",lchrArrCadConsulta);
	SISCOMEnviaYRecibeCadenasAD(pintPtoComAD,
				    pchrPtrDirIp,
				    "hgarduno",
				    "hgarduno",
				     "libADConsultaGenericaSeguridad3.so",
				     "ADConsultas",
				     &lintNRegistros,
				     &lSLRCSisDat,
				     "%s",
				     lchrArrCadConsulta);
	return atol(lSLRCSisDat->chrPtrRegistro[0]);
				     


}

long ObtenIdAplicacion(int pintPtoComAD,
		       const char *pchrPtrDirIp,
			const char *pchrPtrNmbAplicacion)
{
int lintNRegistros;
StcLtaRegComSISCOM *lSLRCSisDat=0;
char lchrArrCadConsulta[256];

	sprintf(lchrArrCadConsulta,
		"select idAplicacion	\
		 from Aplicaciones 	\
		 where NmbAplicacion='%s'",
		 pchrPtrNmbAplicacion);
	SISCOMEnviaYRecibeCadenasAD(pintPtoComAD,
				    pchrPtrDirIp,
				    "hgarduno",
				    "hgarduno",
				     "libADConsultaGenericaSeguridad3.so",
				     "ADConsultas",
				     &lintNRegistros,
				     &lSLRCSisDat,
				     "%s",
				     lchrArrCadConsulta);
	return atol(lSLRCSisDat->chrPtrRegistro[0]);
				     


}
void RegistraUsuario(int pintPtoComAD,
		     const char *pchrPtrDirIpSvr,
		     long plngIdAplicacion,
		     long plngIdPerfil,
		     char **pchrPtrRegistro,
		     long *plngPtrIdUsuario)
{
StcLtaRegComSISCOM *lSLRCSisPtrPrimReg=0,
		   *lSLRCSisPtrActualReg=0,
		   *lSLRCSisPtrRespuesta=0;
char lchrArrCadInsercion[256];
int lintNRegistros=0;
int lintRegRes;
	 SISCOMAnexaRegistroFormateandoParaEnvio(&lSLRCSisPtrPrimReg,
                                                 &lSLRCSisPtrActualReg,
						 &lintNRegistros,
						 lchrArrCadInsercion,
						 "insert into Usuarios values(%ld,%ld,%ld,'%s','%s','%s');",
						 (*plngPtrIdUsuario=SISCOMObtenNumeroUnico()),
						 plngIdAplicacion,
						 plngIdPerfil,
						 pchrPtrRegistro[3],
					  	 pchrPtrRegistro[4],
						 pchrPtrRegistro[5]);

	SISCOMEnviaInformacionAlSvrAD(pintPtoComAD,
				      pchrPtrDirIpSvr,
				      "hgarduno",
				      "hgarduno",	
				      "libADAltaGenericaSeguridad3.so",
				      "ADComandosAlta",
				       lintNRegistros,
				       lSLRCSisPtrPrimReg,
				       &lSLRCSisPtrRespuesta,
				       &lintRegRes);
				        	
}
void RegistraFirma(int pintPtoComAD,
		     const char *pchrPtrDirIpSvr,
		     long plngIdAplicacion,
		     long plngIdPerfil,
		     long plngIdUsuario,
		     char **pchrPtrRegistro)
{
StcLtaRegComSISCOM *lSLRCSisPtrPrimReg=0,
		   *lSLRCSisPtrActualReg=0,
		   *lSLRCSisPtrRespuesta=0;
char lchrArrCadInsercion[256];
int lintNRegistros=0;
int lintRegRes;
	 SISCOMAnexaRegistroFormateandoParaEnvio(&lSLRCSisPtrPrimReg,
                                                 &lSLRCSisPtrActualReg,
						 &lintNRegistros,
						 lchrArrCadInsercion,
						 "insert into firmas values(%ld,'%s','%s');",
						 plngIdUsuario,
					  	 pchrPtrRegistro[7],
						 pchrPtrRegistro[8]);

	SISCOMEnviaInformacionAlSvrAD(pintPtoComAD,
				      pchrPtrDirIpSvr,
				      "hgarduno",
				      "hgarduno",	
				      "libADAltaGenericaSeguridad3.so",
				      "ADComandosAlta",
				       lintNRegistros,
				       lSLRCSisPtrPrimReg,
				       &lSLRCSisPtrRespuesta,
				       &lintRegRes);




}
StcLtaRegComSISCOM *RespuestaRegistro(long plngEdoValida)
{
StcLtaRegComSISCOM *lSLRCSisDatPrim=0,
		   *lSLRCSisDatActual=0;
char lchrArrCadInsercion[128];
int lintNRegistros=0;
	SISCOMAnexaRegistroFormateandoParaEnvio(&lSLRCSisDatPrim,
                                                 &lSLRCSisDatActual,
						 &lintNRegistros,
						 lchrArrCadInsercion,
						 "select %ld",
						 plngEdoValida);

	return lSLRCSisDatPrim;	
}
int ValidaPasswordRegistro(char **pchrPtrRegistro)
{
	return !strcmp(pchrPtrRegistro[8],pchrPtrRegistro[9]);
} 
StcLtaRegComSISCOM *RegistraUsuarioDeUnaAplicacion(int pintPtoComAD,
				const char *pchrPtrDirIpSvrAD,
				StcLtaRegComSISCOM *pSLRCSisDat,
				int *pintPtrNRegistros)
{
StcLtaRegComSISCOM *lSLRCSisPtrPrimReg=0,
		   *lSLRCSisPtrActualReg=0;
char lchrArrCadCns[1024];
long llngIdAplicacion,
     llngIdPerfil,
     llngIdUsuario;
	*pintPtrNRegistros=1;
long llngEdoValidacion=0;

printf("RegistraUsuarioDeUnaAplicacion:--> Registrando\n");
	if((llngEdoValidacion=ValidaPasswordRegistro(pSLRCSisDat->chrPtrRegistro)))
	{
	llngIdAplicacion=ObtenIdAplicacion(pintPtoComAD,
					   pchrPtrDirIpSvrAD,
					   pSLRCSisDat->chrPtrRegistro[1]);
	llngIdPerfil=ObtenIdPerfil(pintPtoComAD,
				   pchrPtrDirIpSvrAD,
				   pSLRCSisDat->chrPtrRegistro[2],
				   llngIdAplicacion);
	RegistraUsuario(pintPtoComAD,
			pchrPtrDirIpSvrAD,
			llngIdAplicacion,
			llngIdPerfil,
			pSLRCSisDat->chrPtrRegistro,
			&llngIdUsuario);
	RegistraFirma(pintPtoComAD,
		      pchrPtrDirIpSvrAD,
		      llngIdAplicacion,
		      llngIdPerfil,
		      llngIdUsuario,
		      pSLRCSisDat->chrPtrRegistro);
	}
	else
	printf("RegistraUsuarioDeUnaAplicacion:%ld",llngEdoValidacion);
	return RespuestaRegistro(llngEdoValidacion);

}


void ObtenDatosParaConsultar(int pintPtoComAD,
			    const char *pchrPtrDirIpSvr,
			    char **pchrPtrRegistro,
			    char **pchrPtrIdAplicacion,
			    char **pchrPtrIdPantalla,
			    char **pchrPtrIdPerfil)
{
char lchrArrCadCnsPerfil[256],
     lchrArrCadCnsIdAplicacion[256],
     lchrArrCadCnsIdPantalla[256],
     lchrArrCadConsulta[1024];
StcLtaRegComSISCOM *lSLRCSisPtrRegreso=0;
int lintNRegReg;
	   sprintf(lchrArrCadCnsPerfil,
		   "select 'IdPerfil', \
			   idPerfil \
	            from usuarios \
		    where idUsuario=( select idUsuario \
				      from firmas \
				      where firma='%s')",
		    pchrPtrRegistro[3]);	
	    sprintf(lchrArrCadCnsIdAplicacion,
		    "select 'IdAplicacion', idAplicacion \
		     from aplicaciones  \
		     where nmbAplicacion='%s'",
		     pchrPtrRegistro[1]);
	    sprintf(lchrArrCadCnsIdPantalla,
		    "select 'IdPantalla', \
			    idPantalla \
		     from pantalla \
		     where nmbClase='%s'",
		     pchrPtrRegistro[4]);
 
		sprintf(lchrArrCadConsulta,
			"%s \
			 union \
			 %s \
			 union \
			 %s",
			 lchrArrCadCnsPerfil,
			 lchrArrCadCnsIdAplicacion,
			 lchrArrCadCnsIdPantalla);

	printf("La Consulta %s \n",lchrArrCadConsulta);	

	SISCOMEnviaYRecibeCadenasAD(pintPtoComAD,
                                            pchrPtrDirIpSvr,
                                            "hgarduno",
                                            "hgarduno",
                                            "libADConsultaGenericaSeguridad3.so",
                                            "ADConsultas",
                                            &lintNRegReg,
                                            &lSLRCSisPtrRegreso,
                                            "%s",
                                            lchrArrCadConsulta);

	 ObtenIdsConsulta(lSLRCSisPtrRegreso,
			  pchrPtrIdAplicacion,
			  pchrPtrIdPantalla,
			  pchrPtrIdPerfil);




}
StcLtaRegComSISCOM *ConsultaObjetosXNombre(int pintPtoComAD,
					   const char *pchrPtrDirIpSvrAD,
					   StcLtaRegComSISCOM *pSLRCSisDat,
					   int *pintPtrNRegistros)
{
char *lchrPtrIdPerfil,
     *lchrPtrIdAplicacion,
     *lchrPtrIdPantalla;
StcLtaRegComSISCOM *lSLRCSisPtrPrimReg=0,
                   *lSLRCSisPtrActualReg=0;
char lchrArrCadCns[1024];	
char lchrArrControl[512];
 int lintContador=0;
	ObtenDatosParaConsultar(pintPtoComAD,
				pchrPtrDirIpSvrAD,
			        pSLRCSisDat->chrPtrRegistro,
				&lchrPtrIdAplicacion,
				&lchrPtrIdPantalla,
				&lchrPtrIdPerfil);
	printf("Consultando %s \t%s \t%s\n",
		lchrPtrIdAplicacion,
		lchrPtrIdPantalla,
		lchrPtrIdPerfil);
/*
	sprintf(lchrArrCadCns,
		"select * \
		 from pantalla as a inner join \
     		      ObjetosXPantalla as b using(idPantalla) inner join \
                      Objeto as c using(idObjeto) inner join  \
                      Propiedades as d using(idObjeto,idPropiedad) \
                 where a.idAplicacion=%s and \
                       a.idPantalla=%s and  \
                       b.idPerfil=%s and  \
                       b.valorpropiedad in(", 
		  lchrPtrIdAplicacion,
		  lchrPtrIdPantalla,
		  lchrPtrIdPerfil);
*/
	sprintf(lchrArrCadCns,
		"select * 							\n\
		 from pantalla as a inner join 					\n\
     		      ObjetosXPantalla as b using(idPantalla) inner join 	\n\
                      Objeto as c using(idObjeto) inner join  			\n\
                      Propiedades as d using(idObjeto,idPropiedad) 		\n\
                 where a.idAplicacion=%s and 					\n\
                       a.idPantalla=%s and  					\n\
                       b.idPerfil=%s 						\n\
		 order by numobjeto,idpropiedad",
		  lchrPtrIdAplicacion,
		  lchrPtrIdPantalla,
		  lchrPtrIdPerfil);



/*
	while(pSLRCSisDat)
	{
	   if(lintContador)
	   {
	       if(pSLRCSisDat->LSRCSISCOMPtrSig)
	       
		sprintf(lchrArrControl,
			"'%s',",
			pSLRCSisDat->chrPtrRegistro[4]);
	        else
	        sprintf(lchrArrControl,"'%s');",
		        pSLRCSisDat->chrPtrRegistro[4]);
		strcat(lchrArrCadCns,lchrArrControl);
	   }	    
	  lintContador++;	
	  pSLRCSisDat=pSLRCSisDat->LSRCSISCOMPtrSig;
	}
*/	
	printf("La Consultota %s \n",lchrArrCadCns);

	*pintPtrNRegistros=1;
SISCOMAnexaRegistroLEnvio(&lSLRCSisPtrPrimReg,
                                  &lSLRCSisPtrActualReg,
                                  1,
                                  "%s",
                                  lchrArrCadCns);

	return lSLRCSisPtrPrimReg;
	

}
StcLtaRegComSISCOM *ConsultaObjetosEnBD(int pintPtoComAD,
						          const char *pchrPtrDirIpSvrAD,
							  StcLtaRegComSISCOM *pSLRCSisDat,
							  int *pintPtrNRegistros)
{
StcLtaRegComSISCOM *lSLRCSisPtrPrimReg=0,
		   *lSLRCSisPtrActualReg=0;
char lchrArrCadCns[1024];

	*pintPtrNRegistros=0;
	 SISCOMAnexaRegistroFormateandoParaEnvio(&lSLRCSisPtrPrimReg,
                                                 &lSLRCSisPtrActualReg,
                                                 pintPtrNRegistros,
                                                 lchrArrCadCns,
						 "select idObjeto, \
       							idPropiedad, \
       							'%s', \
       							'IdAplicacion', \
       							'NmbPantalla', \
       							'Archivo', \
       							'IdPerfil', \
       							'Valor Propiedad', \
       							nmbClase, \
       							nmbPropiedad \
						from objeto   \
     							inner join  propiedades using(idObjeto)",
						"IdPantalla");
	return lSLRCSisPtrPrimReg;
}




StcLtaRegComSISCOM *ConsultaUsuariosXPerfil(int pintPtoComAD,
						          const char *pchrPtrDirIpSvrAD,
							  StcLtaRegComSISCOM *pSLRCSisDat,
							  int *pintPtrNRegistros)
{
StcLtaRegComSISCOM *lSLRCSisPtrPrimReg=0,
		   *lSLRCSisPtrActualReg=0;
char lchrArrCadCns[512];

	*pintPtrNRegistros=0;


	 SISCOMAnexaRegistroFormateandoParaEnvio(&lSLRCSisPtrPrimReg,
                                                 &lSLRCSisPtrActualReg,
                                                 pintPtrNRegistros,
                                                 lchrArrCadCns,
						 "select \
        						a.idUsuario,\
        						a.idAplicacion,\
        						a.idPerfil,\
        						a.NmbUsuario,\
        						a.APaterno,\
        						a.AMaterno,\
        						b.Firma,\
        						b.Password\
						from usuarios as a \
						     left outer join firmas as b \
						     on(a.idUsuario=b.idUsuario) \
						where idPerfil=%s and \
      						      idAplicacion=%s ;",
						pSLRCSisDat->chrPtrRegistro[2],
						pSLRCSisDat->chrPtrRegistro[1]);
	printf("La Consulta %s\n",lchrArrCadCns);
	return lSLRCSisPtrPrimReg;
}


StcLtaRegComSISCOM *ObtenPerfilesAplicacionConPantallas(int pintPtoComAD,
						          const char *pchrPtrDirIpSvrAD,
							  StcLtaRegComSISCOM *pSLRCSisDat,
							  int *pintPtrNRegistros)
{
StcLtaRegComSISCOM *lSLRCSisPtrPrimReg=0,
		   *lSLRCSisPtrActualReg=0;
char lchrArrCadCns[512];

	*pintPtrNRegistros=0;
	 SISCOMAnexaRegistroFormateandoParaEnvio(&lSLRCSisPtrPrimReg,
                                                 &lSLRCSisPtrActualReg,
                                                 pintPtrNRegistros,
                                                 lchrArrCadCns,
						 "select * \
						  from perfiles \
						  where idPerfil in(\
							            SELECT distinct idperfil \
								    from objetosxpantalla \
								    where idAplicacion=%s)",
						pSLRCSisDat->chrPtrRegistro[1]);
	return lSLRCSisPtrPrimReg;
}



StcLtaRegComSISCOM *ObtenPerfilesAplicacion(int pintPtoComAD,
						          const char *pchrPtrDirIpSvrAD,
							  StcLtaRegComSISCOM *pSLRCSisDat,
							  int *pintPtrNRegistros)
{
StcLtaRegComSISCOM *lSLRCSisPtrPrimReg=0,
		   *lSLRCSisPtrActualReg=0;
char lchrArrCadCns[128];

	*pintPtrNRegistros=0;
	 SISCOMAnexaRegistroFormateandoParaEnvio(&lSLRCSisPtrPrimReg,
                                                 &lSLRCSisPtrActualReg,
                                                 pintPtrNRegistros,
                                                 lchrArrCadCns,
						 "select * \
						  from perfiles \
						  where idAplicacion=%s",
						  pSLRCSisDat->chrPtrRegistro[1]);
	printf("--> %s\n",lchrArrCadCns);
	return lSLRCSisPtrPrimReg;
}




StcLtaRegComSISCOM *ConsultaPantallasAplicacion(int pintPtoComAD,
						          const char *pchrPtrDirIpSvrAD,
							  StcLtaRegComSISCOM *pSLRCSisDat,
							  int *pintPtrNRegistros)
{
StcLtaRegComSISCOM *lSLRCSisPtrPrimReg=0,
		   *lSLRCSisPtrActualReg=0;
char lchrArrCadCns[128];
		sprintf(lchrArrCadCns,
			"select IdPantalla, \n\
			        NmbClase, \n\
			        Archivo  \n\
			 from pantalla \n\
			 where IdAplicacion=%s",
			  pSLRCSisDat->chrPtrRegistro[1]);
		SISCOMAnexaRegistroLEnvio(&lSLRCSisPtrPrimReg,
				  &lSLRCSisPtrActualReg,
				  1,
				  "%s",
				  lchrArrCadCns);
	LOGSeguridad3("%s\n",lchrArrCadCns);	
	*pintPtrNRegistros=1;
	return lSLRCSisPtrPrimReg;


}


StcLtaRegComSISCOM *VerificaQueEsteRegistradaLaAplicacion(int pintPtoComAD,
						          const char *pchrPtrDirIpSvrAD,
							  StcLtaRegComSISCOM *pSLRCSisDat,
							  int *pintPtrNRegistros)
{
StcLtaRegComSISCOM *lSLRCSisPtrPrimReg=0,
		   *lSLRCSisPtrActualReg=0;
char lchrArrCadCns[128];
		sprintf(lchrArrCadCns,
			"SELECT count(*) \
		         from pantalla inner join \
			      objetosxpantalla using(idPantalla) \
			 where idAplicacion=%s;",
			  pSLRCSisDat->chrPtrRegistro[1]);

		SISCOMAnexaRegistroLEnvio(&lSLRCSisPtrPrimReg,
				  &lSLRCSisPtrActualReg,
				  1,
				  "%s",
				  lchrArrCadCns);
	*pintPtrNRegistros=1;
	return lSLRCSisPtrPrimReg;


}
StcLtaRegComSISCOM *VerificaAplicacion(int pintPtoComAD,
					           const char *pchrPtrDirIpSvrAD,
							StcLtaRegComSISCOM *pSLRCSisDat,
						   int *pintPtrNCampos)
{
StcLtaRegComSISCOM *lSLRCSisPtrPrimReg=0,
		   *lSLRCSisPtrActualReg=0;
char lchrArrCadCns[128];
		sprintf(lchrArrCadCns,
			"select idAplicacion \
			 from aplicaciones  \
			 where nmbaplicacion like '%%%s%%'",
			  pSLRCSisDat->chrPtrRegistro[1]);

		SISCOMAnexaRegistroLEnvio(&lSLRCSisPtrPrimReg,
				  &lSLRCSisPtrActualReg,
				  1,
				  "%s",
				  lchrArrCadCns);
	*pintPtrNCampos=1;
	return lSLRCSisPtrPrimReg;
}
void ObtenIdsConsulta(StcLtaRegComSISCOM *pSLRCSisDat,
		      char **pchrPtrIdAplicacion,
		      char **pchrPtrIdPantalla,
		      char **pchrPtrIdPerfil)
{
SISCOMMensajesDepuracion("");
	while(pSLRCSisDat)
	{
	   if(!strcmp(pSLRCSisDat->chrPtrRegistro[0],
		      "IdPerfil"))
	      *pchrPtrIdPerfil=pSLRCSisDat->chrPtrRegistro[1];
	   if(!strcmp(pSLRCSisDat->chrPtrRegistro[0],
		      "IdPantalla"))
	      *pchrPtrIdPantalla=pSLRCSisDat->chrPtrRegistro[1];
	   if(!strcmp(pSLRCSisDat->chrPtrRegistro[0],
		      "IdAplicacion"))
	      *pchrPtrIdAplicacion=pSLRCSisDat->chrPtrRegistro[1];

	   pSLRCSisDat=pSLRCSisDat->LSRCSISCOMPtrSig;
	}

}
char *ObtenIdAplicacionDelNombre(int pintPtoComAD,
			const char *pchrPtrDirIpSvr,
			char *pchrPtrNmbAplicacion)
{
StcLtaRegComSISCOM *lSLRCSisPtrRegreso=0;
int lintNRegReg;
char lchrArrCadCns[128];
	sprintf(lchrArrCadCns,
		"select * 		\
		 from aplicaciones 	\
		 where NmbAplicacion='%s'",
		 pchrPtrNmbAplicacion);
SISCOMEnviaYRecibeCadenasAD(pintPtoComAD,
					    pchrPtrDirIpSvr,
					    "hgarduno",
					    "hgarduno",
					    "libADConsultaGenericaSeguridad3.so",
					    "ADConsultas",
					    &lintNRegReg,
					    &lSLRCSisPtrRegreso,
					    "%s",
					    lchrArrCadCns);

return lSLRCSisPtrRegreso->chrPtrRegistro[0];


}
void FormaCadenaDeConsultaDatosPantalla(int pintPtoComAD,
			    const char *pchrPtrDirIp,
			    char **pchrPtrRegistro,
			    char *pchrPtrCadConsulta)
{
StcLtaRegComSISCOM *lSLRCSisPtrRegreso=0;
char lchrArrCadCns[512],
     *lchrArrIdPerfil,
     *lchrArrIdAplicacion,
     *lchrArrIdPantalla;
char lchrArrCadPerfil[512];
int lintNRegReg;

		
	lchrArrIdAplicacion=ObtenIdAplicacionDelNombre(pintPtoComAD,
						       pchrPtrDirIp,
						       pchrPtrRegistro[1]);

		LOGCadenas(pchrPtrRegistro);
		if(pchrPtrRegistro[4])
		{
		   sprintf(lchrArrCadPerfil,
			   "SELECT 'IdPerfil',idPerfil 		\n\
			    from usuarios 			\n\
			    where idUsuario=(			\n\
					     select 		\n\
						   idUsuario 	\n\
					     from firmas 	\n\
					     where firma='%s') and idAplicacion=%s",
			   pchrPtrRegistro[4],
			   lchrArrIdAplicacion);

		}
		else
		{
		sprintf(lchrArrCadPerfil,
			"select 'IdPerfil',idPerfil \n\
				 from perfiles \n\
				 where NmbPerfil='%s' and idAplicacion=%s",
			 pchrPtrRegistro[2],
			 lchrArrIdAplicacion);
		SISCOMMensajesDepuracion("%s",lchrArrCadPerfil);
		}
		sprintf(lchrArrCadCns,
			"%s \n\
		         union \n\
			 select 'IdAplicacion',idAplicacion \n\
			 from aplicaciones  \n\
			 where nmbAplicacion='%s'  \n\
			 union  \n\
			 select 'IdPantalla',idPantalla \n\
			 from pantalla \n\
			 where nmbClase='%s' and idAplicacion=%s", 
			 lchrArrCadPerfil,
			 pchrPtrRegistro[1],
			 pchrPtrRegistro[3],
			 lchrArrIdAplicacion);
	  	SISCOMMensajesDepuracion("%s",lchrArrCadCns);	
		SISCOMEnviaYRecibeCadenasAD(pintPtoComAD,
					    pchrPtrDirIp,
					    "hgarduno",
					    "hgarduno",
					    "libADConsultaGenericaSeguridad3.so",
					    "ADConsultas",
					    &lintNRegReg,
					    &lSLRCSisPtrRegreso,
					    "%s",
					    lchrArrCadCns);
		 
 		ObtenIdsConsulta(lSLRCSisPtrRegreso,
				 &lchrArrIdAplicacion,
				 &lchrArrIdPantalla,
				 &lchrArrIdPerfil);	
		SISCOMMensajesDepuracion("(Pantalla:%s Perfil:%s)",lchrArrIdPantalla,lchrArrIdPerfil);
		sprintf(pchrPtrCadConsulta,
			"select  b.idobjeto,						\n\
				 b.idpropiedad,						\n\
				 a.idpantalla,						\n\
				 a.idaplicacion,					\n\
				 a.nmbclase,						\n\
				 a.archivo,						\n\
				 b.idperfil,						\n\
				 b.valorpropiedad,					\n\
				 c.nmbclase,						\n\
				 d.nmbpropiedad						\n\
			 from Pantalla as a inner join  				\n\
     			      ObjetosXPantalla as b using(idPantalla) inner join 	\n\
     			      Objeto as c using(idObjeto) inner join 			\n\
     			      Propiedades as d using(idObjeto,idPropiedad) 		\n\
			 where a.idAplicacion=%s and 					\n\
      			       a.idPantalla=%s   and 					\n\
			       b.idPerfil=%s						\n\
			  order by numobjeto,idpropiedad;",
			lchrArrIdAplicacion,
		 	lchrArrIdPantalla,
			lchrArrIdPerfil);
		LOGSeguridad3("%s\n",pchrPtrCadConsulta);
		

}
StcLtaRegComSISCOM *ConsultaObjetosDeLaForma(int pintPtoComAD,
					           const char *pchrPtrDirIpSvrAD,
							StcLtaRegComSISCOM *pSLRCSisDat,
						   int *pintPtrNCampos)
{
StcLtaRegComSISCOM *lSLRCSisPtrPrimReg=0,
		   *lSLRCSisPtrActualReg=0;
char lchrArrCadCns[1024];

		FormaCadenaDeConsultaDatosPantalla(pintPtoComAD,
				       pchrPtrDirIpSvrAD,
				       pSLRCSisDat->chrPtrRegistro,
				       lchrArrCadCns);
		SISCOMAnexaRegistroLEnvio(&lSLRCSisPtrPrimReg,
				  &lSLRCSisPtrActualReg,
				  1,
				  "%s",
				  lchrArrCadCns);
	*pintPtrNCampos=1;
	return lSLRCSisPtrPrimReg;
}



StcLtaRegComSISCOM *SeleccionaConsulta(int pintPtoComAD,
					           const char *pchrPtrDirIpSvrAD,
							StcLtaRegComSISCOM *pSLRCSisDat,
				       int *pintPtrNRegistros)
{
int lintContador;
		for(lintContador=0;
		    lintContador<gintNOpGenericas;
		    lintContador++)
		 if(!strcmp(gSOpGenericas[lintContador].chrPtrConsulta,
		            pSLRCSisDat->chrPtrRegistro[0]))
		  return gSOpGenericas[lintContador].FormaConsulta(pintPtoComAD,
							           pchrPtrDirIpSvrAD,
								   pSLRCSisDat,
								   pintPtrNRegistros);

}
StcLtaRegComSISCOM *EjecutaConsulta(int pintPtoComAD,
				    const char *pchrPtrDirIpSvrAD,
				    StcLtaRegComSISCOM *pSLRCSisDat,
				    int *pintPtrNReg)
{

	return SeleccionaConsulta(pintPtoComAD,pchrPtrDirIpSvrAD,pSLRCSisDat,pintPtrNReg);
}
int RNConsultaGenerica(int pintSCliente,
		       int pintTuberia[],
		       int pintPtoComAD,
		       char *pchrPtrDirIpSvrAD)
{


	SISCOMEjecutaConsultaSvrSiscomYEnviaAlCliente2(pintSCliente,
						       pintPtoComAD,
						       pchrPtrDirIpSvrAD,
						       "hgarduno",
						       "hgarduno",
						       "libADConsultaGenericaSeguridad3.so",
						       "ADConsultas",
						       EjecutaConsulta);
}

