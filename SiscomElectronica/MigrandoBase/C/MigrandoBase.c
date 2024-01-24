#include <POSTGRESQLComunes.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void CreaConsulta(const char *pchrPtrConsulta,
		  StcLtaRegComSISCOM **pSLRCSisRegreso)
{
char **lchrArrRegistro;
StcLtaRegComSISCOM *lSLRCSisActual=0;	
	lchrArrRegistro=(char **)malloc(sizeof(char *)*2);

	lchrArrRegistro[0]=(char *)strdup(pchrPtrConsulta);
	lchrArrRegistro[1]=0;

	SISCOMCreaListaRegCom(lchrArrRegistro,
			pSLRCSisRegreso,
			&lSLRCSisActual);
}


void EjecutaConsulta(const char *pchrPtrBD,
		     const char *pchrPtrConsulta,
		     StcLtaRegComSISCOM **pSLRCSisResultado)
{
StcLtaRegComSISCOM *lSLRCSisConsulta=0;
int lintNRegistros,
    lintNColumnas;
	CreaConsulta(pchrPtrConsulta,
		     &lSLRCSisConsulta);
	ControladorEjecutaConsulta(pchrPtrBD,
				   lSLRCSisConsulta,
				   &lintNColumnas,
				   &lintNRegistros,
				   pSLRCSisResultado);
}

void InsertaProductos(StcLtaRegComSISCOM *pSLRCSisDatos)
{
char lchrArrInsercion[1024];
int lintNRegistros=0;
StcLtaRegComSISCOM *lSLRCSisDatInserta=0,
		   *lSLRCSisDatInsertaAct=0;
/*
	SISCOMImprimeContenidoCom(stdout,
				  '|',
				  '\n',
				  pSLRCSisDatos);
*/
	for(;
	     pSLRCSisDatos;
	     pSLRCSisDatos=pSLRCSisDatos->LSRCSISCOMPtrSig)
	{
	  if(pSLRCSisDatos->chrPtrRegistro[1][0]==' ')
	   pSLRCSisDatos->chrPtrRegistro[1]++;
	  /*SISCOMImprimeContenidoRegistro(pSLRCSisDatos->chrPtrRegistro,"InsertaProductos");*/

	  SISCOMAnexaRegistroFormateandoParaEnvio(
	  		&lSLRCSisDatInserta,
			&lSLRCSisDatInsertaAct,
			&lintNRegistros,
			lchrArrInsercion,
			"insert into productos values('%s','%s',0,0);",
			pSLRCSisDatos->chrPtrRegistro[0],
			pSLRCSisDatos->chrPtrRegistro[1]);


	}
	
	SISCOMImprimeContenidoCom(stdout,
				  ';',
				  '\n',
				  lSLRCSisDatInserta);

	ControladorComandoSQL("SiscomElectronica",
			      lSLRCSisDatInserta);
}
void CopiaProductos()
{
StcLtaRegComSISCOM *lSLRCSisDatProductos=0;
	EjecutaConsulta("SiscomTiendas",
			"select * from productos",
			&lSLRCSisDatProductos);
	InsertaProductos(lSLRCSisDatProductos);
}
void CreaActualizacionPrecios(StcLtaRegComSISCOM *pSLRCSisDatos)
{
char lchrArrInsercion[1024];
int lintNRegistros=0;
StcLtaRegComSISCOM *lSLRCSisDatInserta=0,
		   *lSLRCSisDatInsertaAct=0;
	for(;
	     pSLRCSisDatos;
	     pSLRCSisDatos=pSLRCSisDatos->LSRCSISCOMPtrSig)
	{

	  SISCOMAnexaRegistroFormateandoParaEnvio(
	  		&lSLRCSisDatInserta,
			&lSLRCSisDatInsertaAct,
			&lintNRegistros,
			lchrArrInsercion,
			"update precios set precio=%s where cveProducto='%s';",
			pSLRCSisDatos->chrPtrRegistro[2],
			pSLRCSisDatos->chrPtrRegistro[0]);

	}
	SISCOMImprimeContenidoCom(stdout,
				  ';',
				  '\n',
				  lSLRCSisDatInserta);

	ControladorComandoSQL("SiscomElectronica",
				lSLRCSisDatInserta);
}
void ActualizaPrecios()
{
StcLtaRegComSISCOM *lSLRCSisPrecios=0;

	EjecutaConsulta("SiscomTiendas",
			"select * from preciosventaexistencia",
			&lSLRCSisPrecios);
/*
	SISCOMImprimeContenidoCom(stdout,
				  '|',
				  '\n',
				  lSLRCSisPrecios);
*/
	CreaActualizacionPrecios(lSLRCSisPrecios);
}
void CreaCopiaClientes(StcLtaRegComSISCOM *pSLRCSisDatos)
{
char lchrArrInsercion[1024];
int lintNRegistros=0,
    lintContador=0;
StcLtaRegComSISCOM *lSLRCSisDatInserta=0,
		   *lSLRCSisDatInsertaAct=0;
	for(lintContador=0;
	     pSLRCSisDatos;
	     pSLRCSisDatos=pSLRCSisDatos->LSRCSISCOMPtrSig,
	     lintContador++)
	{
	  SISCOMAnexaRegistroFormateandoParaEnvio(
	  		&lSLRCSisDatInserta,
			&lSLRCSisDatInsertaAct,
			&lintNRegistros,
			lchrArrInsercion,
			"insert into personas values('%s','%s','%s','%s',%ld,1);",
			pSLRCSisDatos->chrPtrRegistro[1],
			pSLRCSisDatos->chrPtrRegistro[2],
			pSLRCSisDatos->chrPtrRegistro[3],
			pSLRCSisDatos->chrPtrRegistro[0],
			SISCOMObtenNumeroUnico()+lintContador);

	}
	
	SISCOMImprimeContenidoCom(stdout,
				  ';',
				  '\n',
				  lSLRCSisDatInserta);
	

	ControladorComandoSQL("SiscomElectronica",
			      lSLRCSisDatInserta);
}
void CopiaClientes()
{
StcLtaRegComSISCOM *lSLRCSisDatos=0;

		EjecutaConsulta("SiscomTiendas",
				 "select * from clientestienda",
				 &lSLRCSisDatos);
	CreaCopiaClientes(lSLRCSisDatos);

}
void CopiaInventarioAExpendios()
{
StcLtaRegComSISCOM *lSLRCExpendios=0;
StcLtaRegComSISCOM *lSLRCExistencias=0,
		   *lSLRCExistenciasCont;
StcLtaRegComSISCOM *lSLRCInsertaPrim=0,
		   *lSLRCInsertaAct=0;
char lchrArrCadInsercion[1024];
int lintNRegistros=0;
		  EjecutaConsulta("SiscomElectronica",
		  		  "select * from empresas where idempresa < 0",
				  &lSLRCExpendios);
		  EjecutaConsulta("SiscomTiendas",
		 		  "select * from preciosventaexistencia",
				  &lSLRCExistencias);
		SISCOMImprimeContenidoCom(stdout,
					  '|',
					  '\n',
					  lSLRCExpendios);
			/*
		SISCOMImprimeContenidoCom(stdout,
					  '|',
					  '\n',
					  lSLRCExistencias);
			*/
		 for(;
		 	lSLRCExpendios;
		     lSLRCExpendios=lSLRCExpendios->LSRCSISCOMPtrSig)
		  for(lSLRCExistenciasCont=lSLRCExistencias;
		      lSLRCExistenciasCont;
		      lSLRCExistenciasCont=lSLRCExistenciasCont->LSRCSISCOMPtrSig)
		  {
		     SISCOMAnexaRegistroFormateandoParaEnvio(
		     		&lSLRCInsertaPrim,
				&lSLRCInsertaAct,
				&lintNRegistros,
				lchrArrCadInsercion,
				"insert into compras values('%s','%s',%s,%s,%s,%s,%s,%s,'%s','%s',%s);",
				"2006-12-12",
				lSLRCExistenciasCont->chrPtrRegistro[0],
				lSLRCExistenciasCont->chrPtrRegistro[1],
				"0",
				"0",
				"0",
				"0",
				lSLRCExpendios->chrPtrRegistro[1],
				"Inventario",
				"Inventario",
				"0");
		     SISCOMAnexaRegistroFormateandoParaEnvio(
		     			&lSLRCInsertaPrim,
					&lSLRCInsertaAct,
					&lintNRegistros,
					lchrArrCadInsercion,
					"insert into existencias values('%s',%s,%s);",
				lSLRCExistenciasCont->chrPtrRegistro[0],
				lSLRCExistenciasCont->chrPtrRegistro[1],
				lSLRCExpendios->chrPtrRegistro[1]);

		  }
	ControladorComandoSQL("SiscomElectronica",
			      lSLRCInsertaPrim);
}
void ObtenPracticasEscuela(StcLtaRegComSISCOM **pSLRCSisDatPracticas)
{

	EjecutaConsulta("SiscomTiendas",
			"SELECT distinct escuela  from detallepracticas ;",
			pSLRCSisDatPracticas);


}
void ObtenMateriasDeLaEscuela(const char *pchrPtrEscuela,
			      StcLtaRegComSISCOM **pSLRCSisMaterias)
{
char lchrArrConsulta[1024];
	
		sprintf(lchrArrConsulta,
			"select distinct materia \
			 from detallepracticas   \
			 where escuela='%s'",
			 pchrPtrEscuela);

		EjecutaConsulta("SiscomTiendas",
				lchrArrConsulta,
				pSLRCSisMaterias);
	

}
void ObtenPracticasDeLaEscuela(const char *pchrPtrEscuela,
			   const char *pchrPtrMateria,
			   StcLtaRegComSISCOM **pSLRCSisPracticas)
{
char lchrArrConsulta[1024];

	sprintf(lchrArrConsulta,
		"SELECT distinct nopractica 	\
		 from detallepracticas 		\
		 where	escuela='%s' and	\
		 	Materia='%s'",
		 pchrPtrEscuela,
		 pchrPtrMateria);
	EjecutaConsulta("SiscomTiendas",
			lchrArrConsulta,
			pSLRCSisPracticas);
		 	

}
void ConsultaDetallePractica(const char *pchrPtrEscuela,
			     const char *pchrPtrMateria,
			     const char *pchrPtrNoPractica,
			     StcLtaRegComSISCOM **pSLRCSisDetalle)
{
char lchrArrConsulta[1024];
	sprintf(lchrArrConsulta,
		"select chrCveProducto,		\
			intCantidad		\
		 from detallepracticas		\
		 where escuela='%s' and		\
		       materia='%s' and		\
		       nopractica='%s'",
		  pchrPtrEscuela,
		  pchrPtrMateria,
		  pchrPtrNoPractica);
	EjecutaConsulta("SiscomTiendas",
			lchrArrConsulta,
			pSLRCSisDetalle);

}
void MigraPracticas()
{
StcLtaRegComSISCOM *lSLRCSisEscuela=0,
		   *lSLRCSisMaterias=0;

StcLtaRegComSISCOM *lSLRCSisMigraPrim=0,
		   *lSLRCSisMigraAct=0;
StcLtaRegComSISCOM *lSLRCSisPracEscuelas=0;
StcLtaRegComSISCOM *lSLRCSisDetallePractica=0;
int lintNRegistros=0;
char lchrArrCadena[1024];
int lintContador,
    lintIdEscuela,
    lintIdMateria,
    lintIdPractica;
	ObtenPracticasEscuela(&lSLRCSisEscuela);

	for(lintContador=0 ;
		lSLRCSisEscuela;
	    lSLRCSisEscuela=lSLRCSisEscuela->LSRCSISCOMPtrSig,
	    lintContador++)
	 {
		SISCOMAnexaRegistroFormateandoParaEnvio(
				&lSLRCSisMigraPrim,
				&lSLRCSisMigraAct,
				&lintNRegistros,
				lchrArrCadena,
				"insert into Escuelas values(%ld,'%s');",
				(lintIdEscuela=SISCOMObtenNumeroUnico()+lintContador),
				lSLRCSisEscuela->chrPtrRegistro[0]);
	 	lSLRCSisMaterias=0;
		ObtenMateriasDeLaEscuela(lSLRCSisEscuela->chrPtrRegistro[0],
					 &lSLRCSisMaterias);
	    for(;
	    	 lSLRCSisMaterias;
		 lSLRCSisMaterias=lSLRCSisMaterias->LSRCSISCOMPtrSig)
	    {
	    	if(lSLRCSisMaterias->chrPtrRegistro[0][0])
		{
		SISCOMAnexaRegistroFormateandoParaEnvio(
				&lSLRCSisMigraPrim,
				&lSLRCSisMigraAct,
				&lintNRegistros,
				lchrArrCadena,
				"insert into Materias values(%ld,%ld,'%s');",
				lintIdEscuela,
				(lintIdMateria=SISCOMObtenNumeroUnico()+lintContador+1),
				lSLRCSisMaterias->chrPtrRegistro[0]);
		ObtenPracticasDeLaEscuela(lSLRCSisEscuela->chrPtrRegistro[0],
					  lSLRCSisMaterias->chrPtrRegistro[0],
					  &lSLRCSisPracEscuelas);

		for( ;
		    lSLRCSisPracEscuelas;
		    lSLRCSisPracEscuelas=lSLRCSisPracEscuelas->LSRCSISCOMPtrSig)
		{
		  SISCOMAnexaRegistroFormateandoParaEnvio(
		  		&lSLRCSisMigraPrim,
				&lSLRCSisMigraAct,
				&lintNRegistros,
				lchrArrCadena,
				"insert into practicas values(%ld,%ld,'%s');",
				(lintIdPractica=SISCOMObtenNumeroUnico()+lintContador+2),
				lintIdMateria,
				lSLRCSisPracEscuelas->chrPtrRegistro[0]);
		  ConsultaDetallePractica(lSLRCSisEscuela->chrPtrRegistro[0],
		  			  lSLRCSisMaterias->chrPtrRegistro[0],
					  lSLRCSisPracEscuelas->chrPtrRegistro[0],
					  &lSLRCSisDetallePractica);
		  for(;
		  	lSLRCSisDetallePractica;
		      lSLRCSisDetallePractica=lSLRCSisDetallePractica->LSRCSISCOMPtrSig)
		   {
		     SISCOMAnexaRegistroFormateandoParaEnvio(
		     		&lSLRCSisMigraPrim,
				&lSLRCSisMigraAct,
				&lintNRegistros,
				lchrArrCadena,
				"insert into DetallePractica values(%ld,'%s',%s);",
				lintIdPractica,
				lSLRCSisDetallePractica->chrPtrRegistro[0],
				lSLRCSisDetallePractica->chrPtrRegistro[1]);

		   } 

	   }
	   	lSLRCSisDetallePractica=lSLRCSisPracEscuelas=0;  
	
	 }
	}
	}
	SISCOMImprimeContenidoCom(stdout,
				  ';',
				  '\n',
				  lSLRCSisMigraPrim);
	ControladorComandoSQL("SiscomElectronica",
			      lSLRCSisMigraPrim);


}

int main(int pintArgc,
	 char **pchrPtrArgv)
{
/* Primero se copian los productos, 
 * despues dentro de la interfaz del sistema se inician los
 * precios para el cliente publico en general
 */
	CopiaProductos();  

/* Se actualizan los precios */

	ActualizaPrecios(); 


	CopiaClientes();	


CopiaInventarioAExpendios();


	MigraPracticas();
}
