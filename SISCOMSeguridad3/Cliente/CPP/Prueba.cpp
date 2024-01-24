#include <GeneralBibliotecaSeguridad3.h>
#include <qapplication.h>

#include <IMP_ControlFormas.h>
#include <IMP_Aplicaciones.h>


const  char *gchrPtrSiscomSeguridad3NmbAplicacion="Prueba";
const  char *gchrPtrSiscomSeguridad3Perfil="General";
QFont gQFTipoLetra;
FILE *gPtrFleArchivoLog;


int main(int pintArgC,
	 char **pchrPtrArgv)
{
QApplication a(pintArgC,pchrPtrArgv);
CSISCOMDatComunicaciones lCDSDatCom(atoi(getenv("PTOCOMSISCOMRN")),
                                        getenv("DIRIPSISCOMRN"),
                                        "hgarduno",
                                        "hgarduno");
/*
QSiscomArchivoUI lQSAUiPrueba(pchrPtrArgv[1]);
QSiscomObjetosSeguridad lQSObjSeg(&lCDSDatCom,
				  lQSAUiPrueba.ObtenControlesArchivo(),
				  "Prueba",
				  lQSAUiPrueba.ObtenClase(),
				  lQSAUiPrueba.ObtenNmbForma());

QStringList lQSLArchivos;
for(int lintContador=1;lintContador<pintArgC;lintContador++)
  lQSLArchivos << pchrPtrArgv[lintContador] ;
CQSisControlFormas *lCQSisConFormasDat=new CQSisControlFormas(lQSLArchivos,
							      &lCDSDatCom,
							      "Pruebas");
*/
QSiscomConsultaObjetos *lQSCnsObj=new QSiscomConsultaObjetos(&lCDSDatCom,
						 	     "Prueba",
							     "Aplicaciones",
							     "General");


QSiscomListaObjQ lQPLObjetos=lQSCnsObj->ObtenObjetosDeLaForma();
QSiscomObjetosQT *lQSObjQT;
QSiscomListaPropBD lQSLPBDDat;
QSiscomPropiedadesBD *lQSPBDObj;
int lintContador;
	for(lQSObjQT=lQPLObjetos.first();
	    lQSObjQT;
	    lQSObjQT=lQPLObjetos.next())
	{
	   lQSLPBDDat=lQSObjQT->ObtenPropiedades();
	   printf("%s\n",(const char *)lQSObjQT->ObtenNombreObjeto()); 
	   for(lQSPBDObj=lQSLPBDDat.first();
	       lQSPBDObj;
	       lQSPBDObj=lQSLPBDDat.next())
	    printf("\t%s [%s]\n",
		   (const char *)lQSPBDObj->ObtenNombrePropiedad(),
		   (const char *)lQSPBDObj->ObtenValorPropiedad());
	}

/*
QSiscomConsultaAplicacion *lQSisCnsAplicacion=new QSiscomConsultaAplicacion(&lCDSDatCom,
									    "1138122286");


*/
a.connect(&a,SIGNAL(lastWindowClosed()), &a ,SLOT(quit()));


return a.exec();



}
