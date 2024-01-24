#include <IMP_Resultados.h>
#include <IMP_GimnastasCompetencia.h>
#include<SISCOMComunicaciones++.h>
#include <QCtrlCompetencias.h>
#include <QResCompetencia.h>

#include <CQSisClase.h>
#include <CQSisGrupo.h>
#include <CQSisNivel.h>
#include <CQSisCalificaciones.h>
#include <CQSisAparato.h>
#include <CQSisEntrenadores.h>
#include <CQSisGimnasios.h>

#include <CQSisCGimnastas.h>

#include <qtabwidget.h>
#include <qpushbutton.h>
void SiscomCambiaCaracteres(char pchrCaracter,
			    char pchrCambia,
			    char *pchrPtrCadena)
{
	for(;
	     *pchrPtrCadena;
	     *pchrPtrCadena++)
	if(*pchrPtrCadena==pchrCaracter)
	 *pchrPtrCadena=pchrCambia;
}
QResultados *InstanciaResultados(void *pSisDatCom,
                 char **pchrPtrArgumentos,
                 void *pQWParent,
                const char *pchrPtrName,
                 int pintWFlags)
{
	return new QResultados((SiscomDatCom *)pSisDatCom,	
			pchrPtrArgumentos,		
			(QWidget *)pQWParent,		
			pchrPtrName,			
			pintWFlags);
}
QResultados::QResultados(SiscomDatCom *pSisDatCom, 
			            char **pchrPtrArgumentos, 
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    WFlags pWFlags):	      
				Resultados(pQWParent,pchrPtrName,pWFlags),
				SisDatCom(pSisDatCom),
				chrPtrArgumentos(pchrPtrArgumentos)
{
IniciaVariables();
ConectaSlots();
if(chrPtrArgumentos[26])
{
 CQSCompetencia=(CQSisCompetencia *)chrPtrArgumentos[26];
 SlotCompetencia(CQSCompetencia);
}
}

QResultados::~QResultados()
{

}

void QResultados::ConectaSlots()
{

	connect(QIVGrupos,
		SIGNAL(selectionChanged(QIconViewItem *)),
		SLOT(SlotGrupo(QIconViewItem *)));

	connect(QIVGruposA,
		SIGNAL(selectionChanged(QIconViewItem *)),
		SLOT(SlotGrupoAparato(QIconViewItem *)));
	connect(QPBImpresion,
		SIGNAL(clicked()),
		SLOT(SlotArchivoImpresion()));
}
void QResultados::SlotArchivoImpresion()
{
CQSisLstCompitiendo *lCQSLCompitiendo;
CQSisCompitiendo *lCQSCompitiendo;
QString lQSClaseNivel;
QResCompetencia *lQRCompetencia;
FILE *lFleArchivo;
char lchrArrArchivo[1024];
	sprintf(lchrArrArchivo,
			    "%s/%s.txt",
			    getenv("HOME"),
			    CQSCompetencia->SRegistrosPro2["Competencia"]);
	SiscomCambiaCaracteres(' ','_',lchrArrArchivo);		
	SiscomCambiaCaracteres('(','_',lchrArrArchivo);		
	SiscomCambiaCaracteres(')','_',lchrArrArchivo);		
	lFleArchivo=fopen(lchrArrArchivo,"w");

	fprintf(lFleArchivo,"Resultados Generales De:%s\n",
		CQSCompetencia->SRegistrosPro2["Competencia"]);
	for(lCQSLCompitiendo=CQSLLCompitiendo.first();
	    lCQSLCompitiendo;
	    lCQSLCompitiendo=CQSLLCompitiendo.next())
	{
	  lCQSCompitiendo=lCQSLCompitiendo->at(0);
	  fprintf(lFleArchivo,"Nivel %s %s \n",
		  lCQSCompitiendo->ObtenNivel()->SRegistrosPro2["Nivel"],
		  lCQSCompitiendo->ObtenGrupo()->SRegistrosPro2["Grupo"]);
	   for(lCQSCompitiendo=lCQSLCompitiendo->first();
	       lCQSCompitiendo;
	       lCQSCompitiendo=lCQSLCompitiendo->next())
	     fprintf(lFleArchivo,"%s %s %s\t%s\t%s\n",
	     	lCQSCompitiendo->ObtenGimnasta()->SRegistrosPro2["Nombre"],
	     	lCQSCompitiendo->ObtenGimnasta()->SRegistrosPro2["APaterno"],
	     	lCQSCompitiendo->ObtenGimnasta()->SRegistrosPro2["AMaterno"],
		lCQSCompitiendo->ObtenGimnasio()->SRegistrosPro2["Gimnasio"],
		lCQSCompitiendo->ObtenCalificacion()->SRegistrosPro2["NotaFinal"]);
	  fprintf(lFleArchivo,"\n");
	}
	fprintf(lFleArchivo,"\n\n\n\n\n\n");
	fprintf(lFleArchivo,
		"Resultados generados por SISCOM Mexico\n");
	fprintf(lFleArchivo,
		"Sistema Utilizado: SISCOMGimnasia, sistema para la administracion de competencias de gimnasia\n");
	fprintf(lFleArchivo,
		"SISCOM Mexico, A.v. I.P.N. # 2085 Colonia San Pedro Zacatenco, Gustavo A. Madero Mexico D.F.\n");
	fprintf(lFleArchivo,
		"Telefono:0155557540823\n");
	fprintf(lFleArchivo,
		"Contacto: Ingeniero Heli Garduno Esquivel");

	ResultadosAparatos(lFleArchivo);
	fclose(lFleArchivo);
}
void QResultados::ResultadosAparatos(FILE *pFleArchivo)
{
CQSisCompitiendo *lCQSCompitiendo;
CQSisLstCompitiendo *lCQSLCompitiendo;
QString lQSClaseNivel;
fprintf(pFleArchivo,"\n");
for(lCQSLCompitiendo=CQSLLCompitiendoAparatos.first();
	    lCQSLCompitiendo;
	    lCQSLCompitiendo=CQSLLCompitiendoAparatos.next())
	{
	  lCQSCompitiendo=lCQSLCompitiendo->at(0);
	  lQSClaseNivel=QString("Nivel ")						+
			lCQSCompitiendo->ObtenNivel()->SRegistrosPro2["Nivel"]  	+
			" "								+
			lCQSCompitiendo->ObtenGrupo()->SRegistrosPro2["Grupo"]		+
			" "								+
			lCQSCompitiendo->ObtenCalificacion()->ObtenAparato()->SRegistrosPro2["Aparato"];
	  fprintf(pFleArchivo,"%s\n",(const char *)lQSClaseNivel);
	    for(lCQSCompitiendo=lCQSLCompitiendo->first();
	        lCQSCompitiendo;
		lCQSCompitiendo=lCQSLCompitiendo->next())
		fprintf(pFleArchivo,"%s %s %s\t%s\t%s\n",
	     	lCQSCompitiendo->ObtenGimnasta()->SRegistrosPro2["Nombre"],
	     	lCQSCompitiendo->ObtenGimnasta()->SRegistrosPro2["APaterno"],
	     	lCQSCompitiendo->ObtenGimnasta()->SRegistrosPro2["AMaterno"],
		lCQSCompitiendo->ObtenGimnasio()->SRegistrosPro2["Gimnasio"],
		lCQSCompitiendo->ObtenCalificacion()->SRegistrosPro2["NotaFinal"]);
	  fprintf(pFleArchivo,"\n");
	  }

}
void QResultados::SlotGrupoAparato(QIconViewItem *pQIVItemGrupo)
{

	if(pQIVItemGrupo)
	 QTWResAparatos->showPage(((QIconViewItemGrupo *)pQIVItemGrupo)->ObtenGrupo());

}
void QResultados::SlotGrupo(QIconViewItem *pQIVItemGrupo)
{

	if(pQIVItemGrupo)
	 QTWResGeneral->showPage(((QIconViewItemGrupo *)pQIVItemGrupo)->ObtenGrupo());

}
void QResultados::SlotCompetencia(CQSisCompetencia *pCQSCompetencia)
{
	CQSCompetencia=pCQSCompetencia;
	LimpiaControles();
	ConsultaResultados();
	ConsultaResultadosAparato();
	MuestraResultados();
	MuestraResultadosAparato();
	
}
void QResultados::ConsultaResultados()
{
CQSisOpGmnCompitiendo lCQSOGCompitiendo(SisDatCom);
		lCQSOGCompitiendo.ObtenCompetenciaGeneral(
					CQSCompetencia,
					&CQSLLCompitiendo);


}
void QResultados::ConsultaResultadosAparato()
{
CQSisOpGmnCompitiendo lCQSOGCompitiendo(SisDatCom);
		lCQSOGCompitiendo.ObtenResultadosPorAparato(
					CQSCompetencia,
					&CQSLLCompitiendoAparatos);

}
void QResultados::MuestraResultados()
{
CQSisLstCompitiendo *lCQSLCompitiendo;
CQSisCompitiendo *lCQSCompitiendo;
QString lQSClaseNivel;
QResCompetencia *lQRCompetencia;
	QIVGrupos->clear();
	QTWResGeneral->removePage(QTWResGeneral->currentPage());
	for(lCQSLCompitiendo=CQSLLCompitiendo.first();
	    lCQSLCompitiendo;
	    lCQSLCompitiendo=CQSLLCompitiendo.next())
	{
	  lCQSCompitiendo=lCQSLCompitiendo->at(0);
	  lQSClaseNivel=QString("Clase ")					+
			"Nivel "						+
			" "							+
			lCQSCompitiendo->ObtenNivel()->SRegistrosPro2["Nivel"]  +
			" "							+
			lCQSCompitiendo->ObtenGrupo()->SRegistrosPro2["Grupo"]	+
			" "							+
			lCQSCompitiendo->ObtenGrupo()->SRegistrosPro2["RangoEdad"];
	  lQRCompetencia=new QResCompetencia(
	  			lCQSLCompitiendo);
	  QTWResGeneral->addTab(lQRCompetencia,lQSClaseNivel);
	  QIVGrupos->insertItem(new QIconViewItemGrupo(lQRCompetencia,
	  					       lQSClaseNivel,
						       QIVGrupos));
	  QRCompetenciaL << lQRCompetencia;
	  }
	QTWResGeneral->setCurrentPage(0);
}
void QResultados::MuestraResultadosAparato()
{
CQSisLstCompitiendo *lCQSLCompitiendo;
CQSisCompitiendo *lCQSCompitiendo;
QString lQSClaseNivel;
QResCompetencia *lQRCompetencia;
	QIVGruposA->clear();
	QTWResAparatos->removePage(QTWResAparatos->currentPage());
	for(lCQSLCompitiendo=CQSLLCompitiendoAparatos.first();
	    lCQSLCompitiendo;
	    lCQSLCompitiendo=CQSLLCompitiendoAparatos.next())
	{
	  lCQSCompitiendo=lCQSLCompitiendo->at(0);
	  lQSClaseNivel=QString("Clase ")						+
			"Nivel "							+
			lCQSCompitiendo->ObtenNivel()->SRegistrosPro2["Nivel"]  	+
			" "								+
			lCQSCompitiendo->ObtenGrupo()->SRegistrosPro2["Grupo"]		+
			" "								+
			lCQSCompitiendo->ObtenCalificacion()->ObtenAparato()->SRegistrosPro2["Aparato"];
	  lQRCompetencia=new QResCompetencia(
	  			lCQSLCompitiendo);
	  QTWResAparatos->addTab(lQRCompetencia,lQSClaseNivel);
	  QIVGruposA->insertItem(new QIconViewItemGrupo(lQRCompetencia,
	  					       lQSClaseNivel,
						       QIVGruposA));
	  QRCompetenciaLAparatos << lQRCompetencia;
	  }
}
void QResultados::IniciaVariables()
{
}
void QResultados::LimpiaControles()
{
	CQSLLCompitiendo.clear();
	LimpiaTabWidget();
	LimpiaTabWidgetAparatos();
}
void QResultados::LimpiaTabWidget()
{
QResCompetencia *lQRCompetencia;

	for(lQRCompetencia=QRCompetenciaL.first();
	    lQRCompetencia;
	    lQRCompetencia=QRCompetenciaL.next())
	   QTWResGeneral->removePage(lQRCompetencia);
	QRCompetenciaL.clear();
}
void QResultados::LimpiaTabWidgetAparatos()
{
QResCompetencia *lQRCompetencia;

	for(lQRCompetencia=QRCompetenciaLAparatos.first();
	    lQRCompetencia;
	    lQRCompetencia=QRCompetenciaLAparatos.next())
	   QTWResAparatos->removePage(lQRCompetencia);
	QRCompetenciaLAparatos.clear();
}
