#include <IMP_TablaResultados.h>
#include<SISCOMComunicaciones++.h>
#include <SiscomTableItemColor.h>
#include <CQSisCompetencias.h>
#include <CQSisCompitiendo.h>
#include <CQSisClase.h>
#include <CQSisGrupo.h>
#include <CQSisNivel.h>
#include <CQSisEntrenadores.h>
#include <CQSisConsultas.h>
#include <CQSisAparato.h>
#include <CQSisCalificaciones.h>
#include <CQSisGimnasios.h>
#include <SiscomDesarrollo3Qt++.h>


QTablaResultados *InstanciaTablaResultados(void *pSisDatCom,
                 char **pchrPtrArgumentos,
                 void *pQWParent,
                const char *pchrPtrName,
                 int pintWFlags)
{
	return new QTablaResultados((SiscomDatCom *)pSisDatCom,	
			pchrPtrArgumentos,		
			(QWidget *)pQWParent,		
			pchrPtrName,			
			pintWFlags);
}
QTablaResultados::QTablaResultados(SiscomDatCom *pSisDatCom, 
			           char **pchrPtrArgumentos, 
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    WFlags pWFlags):	      
				TablaResultados(pQWParent,pchrPtrName,pWFlags),
				SisDatCom(pSisDatCom),
				chrPtrArgumentos(pchrPtrArgumentos)
{
if(chrPtrArgumentos[26])
{
 CQSCompetencia=(CQSisCompetencia *)chrPtrArgumentos[26];
}
IniciaVariables();
ConectaSlots();
}

QTablaResultados::~QTablaResultados()
{

}

void QTablaResultados::ConectaSlots()
{
connect(QTDatos,
	SIGNAL(doubleClicked(int,int,int,const QPoint &)),
	SLOT(SlotCapturaCalificacion(int,int,int,const QPoint &)));

}
void QTablaResultados::SlotCapturaCalificacion(int pintNFila,
					       int pintNColumna,
					       int,
					       const QPoint &)
{
CQTableItemCalificacion *lCQTICalificacion;
if((lCQTICalificacion=(CQTableItemCalificacion *)QTDatos->item(pintNFila,pintNColumna)))
 QCalificaGimnasta lQCGimnasta(SisDatCom,
 			       lCQTICalificacion->Compitiendo(),
			       lCQTICalificacion->Aparato());
Consultando();
ConsultandoClasificacionAparatos();
ConsultandoCompetenciaGeneral();
}
void QTablaResultados::IniciaVariables()
{
ConsultaAparatosCompetencia();
Consultando();
ConsultandoClasificacionAparatos();
ConsultandoCompetenciaGeneral();
}
void QTablaResultados::ConsultaAparatosCompetencia()
{
CQSisOpConsultas lCQSOConsulta(SisDatCom);
lCQSOConsulta.ConsultaAparatosCompetencia(CQSCompetencia,&CQSLACompetencia);
}
void QTablaResultados::ConsultaCompetenciaGeneral()
{
CQSisOpGmnCompitiendo lCQSOGCompitiendo(SisDatCom);
		lCQSOGCompitiendo.ObtenCompetenciaGeneral(
					CQSCompetencia,
					&CQSLLCompetenciaGeneral);
}
void QTablaResultados::ConsultandoCompetenciaGeneral()
{
ConsultaCompetenciaGeneral();
MuestraCompetenciaGeneral(&CQSLLCompetenciaGeneral,QTGeneral);
}
void QTablaResultados::ConsultandoClasificacionAparatos()
{
ConsultaClasificacionAparatos();
MuestraClasificacionAparatos(&CQSLLClasificacionAparatos,QTClasPorAparato);
}
void QTablaResultados::ConsultaClasificacionAparatos()
{
CQSisOpGmnCompitiendo lCQSOGCompitiendo(SisDatCom);
		lCQSOGCompitiendo.ObtenResultadosPorAparato(
					CQSCompetencia,
					&CQSLLClasificacionAparatos);
}
void QTablaResultados::Consultando()
{
Consulta();
MuestraInformacion(&CQSLLCompitiendoAparatos,QTDatos);
}
void QTablaResultados::Consulta()
{
CQSisOpGmnCompitiendo lCQSOGCompitiendo(SisDatCom);
		lCQSOGCompitiendo.TablaResultados(
					CQSCompetencia,
					&CQSLLCompitiendoAparatos);
}
void QTablaResultados::GimnasioCompetidor(CQSisCompitiendo *pCQSCompitiendo,
					  QString &pQSGimCompetidor)
{

	pQSGimCompetidor+=QString((*pCQSCompitiendo->ObtenGimnasio())["Gimnasio"]) +
			  "\n"							   +
			  "\n"							   +
			  (*pCQSCompitiendo->ObtenGimnasta())["Nombre"]		   +
			  " "							   +
			  (*pCQSCompitiendo->ObtenGimnasta())["APaterno"]	   +
			  " "							   +
			  (*pCQSCompitiendo->ObtenGimnasta())["AMaterno"]	   +
			  "\n"							   +
			  "\n";

}
void QTablaResultados::MuestraClasificacionAparatos(CQSisLstLstCompitiendo *pCQSLLCompitiendo,
					  QTable *pQTDatos)
{
CQSisClaseNivel *lCQSCNivel;
CQSisLstClaseNivel lCQSLCNivel;

CQSisGrupo *lCQSGrupo;
CQSisLstGrupo lCQSLGrupo;

CQSisAparatoCompetencia *lCQSACompetencia;
CQSisLstCompitiendo lCQSLComGimnastas;
CQSisLstCompitiendo *lCQSLCompitiendo;
CQSisCompitiendo *lCQSCompitiendo;
QString lQSGimCompetidor;
const QColor lQColor[]={ red,blue,yellow,green,red,blue,yellow};
pQTDatos->setNumRows(200);
int lintNFila=0;
int lintNColumna;
int lintContador=0;
int lintNFilaAparato;
int lintNAparato;
pCQSLLCompitiendo->Niveles(0,&lCQSLCNivel);
for(lCQSCNivel=lCQSLCNivel.first();
    lCQSCNivel;
    lCQSCNivel=lCQSLCNivel.next())
{
 pQTDatos->setText(lintNFila++,
 		 0,
		 QString((*lCQSCNivel->Clase())["Clase"]) +
		 " "					  +
 		(*lCQSCNivel->Nivel())["Nivel"]);
 
 lCQSLGrupo.clear();
 pCQSLLCompitiendo->Grupos(lCQSCNivel,&lCQSLGrupo);

 for(lCQSGrupo=lCQSLGrupo.first();
     lCQSGrupo;
     lCQSGrupo=lCQSLGrupo.next())
 {
 lintNFila++;
 pQTDatos->setText(lintNFila,
 		  1,
		  QString((*lCQSGrupo)["Grupo"]) + 
		  "  "				 +
		  (*lCQSGrupo)["RangoEdad"]);


 lintNFilaAparato=lintNFila; 
 for(lCQSACompetencia=CQSLACompetencia.first(),
     lintNColumna=2,
     lintNAparato=0;
     lCQSACompetencia;
     lCQSACompetencia=CQSLACompetencia.next(),
     lintNColumna+=3,
     lintNAparato++)
 {
   lCQSLComGimnastas.clear();
    pCQSLLCompitiendo->Gimnastas(lCQSCNivel,
    				       lCQSGrupo,
				       lCQSACompetencia,
				       &lCQSLComGimnastas);
  pQTDatos->setItem(lintNFila,
  	          lintNColumna+1,
		  new SiscomTableItemColor(QTDatos,
		  			   lQColor[lintNAparato],
					   QTableItem::Never,
					   (*lCQSACompetencia->ObtenAparato())["Aparato"]));
  for(lCQSCompitiendo=lCQSLComGimnastas.first(),
      lintContador=1;
      lCQSCompitiendo;
      lCQSCompitiendo=lCQSLComGimnastas.next(),
      lintContador++)
  {
  	lQSGimCompetidor="";
  	GimnasioCompetidor(lCQSCompitiendo,lQSGimCompetidor);
     pQTDatos->setText(lintNFilaAparato+lintContador,
     		       lintNColumna,
		       QString().sprintf("%d",lintContador));

     pQTDatos->setItem(lintNFilaAparato+lintContador,
     		       lintNColumna+1,
		       new SiscomTableItemColor(
		       		QTDatos,
				lQColor[lintNAparato],
				QTableItem::Never,
				lQSGimCompetidor));
    pQTDatos->setItem(lintNFilaAparato+lintContador,
    		     lintNColumna+2,
		     new CQTableItemCalificacion(
		     		lCQSCompitiendo,
				lCQSACompetencia->ObtenAparato(),
			        QTDatos,
				lQColor[lintNAparato],
				QTableItem::Never));
  }
 }
  lintNFila+=lintContador;
 }

}
SiscomDesarrollo3Qt::AjustaFilas(pQTDatos);
SiscomDesarrollo3Qt::AjustaColumnas(pQTDatos);
}



void QTablaResultados::MuestraCompetenciaGeneral(CQSisLstLstCompitiendo *pCQSLLCompitiendo,
					  QTable *pQTDatos)
{
CQSisClaseNivel *lCQSCNivel;
CQSisLstClaseNivel lCQSLCNivel;

CQSisGrupo *lCQSGrupo;
CQSisLstGrupo lCQSLGrupo;

CQSisAparatoCompetencia *lCQSACompetencia;
CQSisLstLstCompitiendo lCQSLLCompitiendo;
CQSisLstCompitiendo *lCQSLCompitiendo;
CQSisCompitiendo *lCQSCompitiendo;
const QColor lQColor[]={ red,blue,yellow,green,red,blue,yellow};
pQTDatos->setNumRows(200);
int lintNFila=0;
int lintNColumna;
int lintContador=0;
int lintNFilaAparato;
int lintNAparato;
pCQSLLCompitiendo->Niveles(0,&lCQSLCNivel);
for(lCQSCNivel=lCQSLCNivel.first();
    lCQSCNivel;
    lCQSCNivel=lCQSLCNivel.next())
{
 pQTDatos->setText(lintNFila++,
 		 0,
		 QString((*lCQSCNivel->Clase())["Clase"]) +
		 " "					  +
 		(*lCQSCNivel->Nivel())["Nivel"]);
 
 lCQSLGrupo.clear();
 pCQSLLCompitiendo->Grupos(lCQSCNivel,&lCQSLGrupo);

 for(lCQSGrupo=lCQSLGrupo.first();
     lCQSGrupo;
     lCQSGrupo=lCQSLGrupo.next())
 {
 lintNFila++;
 pQTDatos->setText(lintNFila,
 		  1,
		  QString((*lCQSGrupo)["Grupo"]) + 
		  "  "				 +
		  (*lCQSGrupo)["RangoEdad"]);
	lCQSLLCompitiendo.clear();
       pCQSLLCompitiendo->Gimnastas(lCQSCNivel,
       				    lCQSGrupo,
				    &lCQSLLCompitiendo);
       lCQSLCompitiendo=lCQSLLCompitiendo.first();
  for(lCQSCompitiendo=lCQSLCompitiendo->first(),
      lintContador=1;
      lCQSCompitiendo;
      lCQSCompitiendo=lCQSLCompitiendo->next(),
      lintContador++)
  {
  /*
     pQTDatos->setItem(lintNFilaAparato+lintContador,
     		       lintNColumna-1,
		       new SiscomTableItemColor(
		       		QTDatos,
				lQColor[lintNAparato],
				QTableItem::Never,
		       QString((*lCQSCompitiendo->ObtenGimnasta())["Nombre"])	+
		       " "							+
		       (*lCQSCompitiendo->ObtenGimnasta())["APaterno"]		+
		       " "							+
		       (*lCQSCompitiendo->ObtenGimnasta())["AMaterno"]));
   */
    pQTDatos->setText(lintNFila+lintContador,
    		      3,
		      QString((*lCQSCompitiendo->ObtenGimnasta())["Nombre"])    +
		       " "							+
		       (*lCQSCompitiendo->ObtenGimnasta())["APaterno"]		+
		       " "							+
		       (*lCQSCompitiendo->ObtenGimnasta())["AMaterno"]);
    pQTDatos->setText(lintNFila+lintContador,
    		      4,
		      (*lCQSCompitiendo->ObtenCalificacion())["NotaFinal"]);
   /*
    pQTDatos->setItem(lintNFilaAparato+lintContador,
    		     lintNColumna,
		     new CQTableItemCalificacion(
		     		lCQSCompitiendo,
				lCQSACompetencia->ObtenAparato(),
			        QTDatos,
				lQColor[lintNAparato],
				QTableItem::Never));
    */
  }
  lintNFila+=lintContador;
 }
}
SiscomDesarrollo3Qt::AjustaFilas(pQTDatos);
SiscomDesarrollo3Qt::AjustaColumnas(pQTDatos);
}
void QTablaResultados::MuestraInformacion(CQSisLstLstCompitiendo *pCQSLLCompitiendo,
					  QTable *pQTDatos)
{
CQSisClaseNivel *lCQSCNivel;
CQSisLstClaseNivel lCQSLCNivel;

CQSisGrupo *lCQSGrupo;
CQSisLstGrupo lCQSLGrupo;

CQSisAparatoCompetencia *lCQSACompetencia;
CQSisLstCompitiendo lCQSLComGimnastas;
CQSisLstCompitiendo *lCQSLCompitiendo;
CQSisCompitiendo *lCQSCompitiendo;
const QColor lQColor[]={ red,blue,yellow,green,red,blue,yellow};
pQTDatos->setNumRows(200);
int lintNFila=0;
int lintNColumna;
int lintContador=0;
int lintNFilaAparato;
int lintNAparato;
pCQSLLCompitiendo->Niveles(0,&lCQSLCNivel);
for(lCQSCNivel=lCQSLCNivel.first();
    lCQSCNivel;
    lCQSCNivel=lCQSLCNivel.next())
{
 pQTDatos->setText(lintNFila++,
 		 0,
		 QString((*lCQSCNivel->Clase())["Clase"]) +
		 " "					  +
 		(*lCQSCNivel->Nivel())["Nivel"]);
 
 lCQSLGrupo.clear();
 pCQSLLCompitiendo->Grupos(lCQSCNivel,&lCQSLGrupo);

 for(lCQSGrupo=lCQSLGrupo.first();
     lCQSGrupo;
     lCQSGrupo=lCQSLGrupo.next())
 {
 lintNFila++;
 pQTDatos->setText(lintNFila,
 		  1,
		  QString((*lCQSGrupo)["Grupo"]) +
		  " "				 +
		  (*lCQSGrupo)["RangoEdad"]);
 lintNFilaAparato=lintNFila; 
 for(lCQSACompetencia=CQSLACompetencia.first(),
     lintNColumna=2,
     lintNAparato=0;
     lCQSACompetencia;
     lCQSACompetencia=CQSLACompetencia.next(),
     lintNColumna++,
     lintNAparato++)
 {
   lCQSLComGimnastas.clear();
    pCQSLLCompitiendo->Gimnastas(lCQSCNivel,
    				       lCQSGrupo,
				       lCQSACompetencia,
				       &lCQSLComGimnastas);
  /*QTDatos->setText(0,lintNColumna,(*lCQSACompetencia->ObtenAparato())["Aparato"]); 
  pQTDatos->setText(0,lintNColumna,(*lCQSACompetencia->ObtenAparato())["Aparato"]); */
  pQTDatos->setItem(lintNFila,
  	          lintNColumna,
		  new SiscomTableItemColor(QTDatos,
		  			   lQColor[lintNAparato],
					   QTableItem::Never,
					   (*lCQSACompetencia->ObtenAparato())["Aparato"]));
  for(lCQSCompitiendo=lCQSLComGimnastas.first(),
      lintContador=1;
      lCQSCompitiendo;
      lCQSCompitiendo=lCQSLComGimnastas.next(),
      lintContador++)
  {
     pQTDatos->setText(lintNFilaAparato+lintContador,
     		       1,
		       QString((*lCQSCompitiendo->ObtenGimnasta())["Nombre"])	+
		       " "							+
		       (*lCQSCompitiendo->ObtenGimnasta())["APaterno"]		+
		       " "							+
		       (*lCQSCompitiendo->ObtenGimnasta())["AMaterno"]);
    pQTDatos->setItem(lintNFilaAparato+lintContador,
    		     lintNColumna,
		     new CQTableItemCalificacion(
		     		lCQSCompitiendo,
				lCQSACompetencia->ObtenAparato(),
			        QTDatos,
				lQColor[lintNAparato],
				QTableItem::Never));
  }
 }
  lintNFila+=lintContador;
 }

}
SiscomDesarrollo3Qt::AjustaFilas(pQTDatos);
SiscomDesarrollo3Qt::AjustaColumnas(pQTDatos);
}
void QTablaResultados::Muestra()
{
CQSisClaseNivel *lCQSCNivel;
CQSisLstClaseNivel lCQSLCNivel;

CQSisGrupo *lCQSGrupo;
CQSisLstGrupo lCQSLGrupo;

CQSisAparatoCompetencia *lCQSACompetencia;
CQSisLstCompitiendo lCQSLComGimnastas;
CQSisLstCompitiendo *lCQSLCompitiendo;
CQSisCompitiendo *lCQSCompitiendo;
const QColor lQColor[]={ red,blue,yellow,green,red,blue,yellow};
QTDatos->setNumRows(200);
int lintNFila=0;
int lintNColumna;
int lintContador=0;
int lintNFilaAparato;
int lintNAparato;
CQSLLCompitiendoAparatos.Niveles(0,&lCQSLCNivel);
for(lCQSCNivel=lCQSLCNivel.first();
    lCQSCNivel;
    lCQSCNivel=lCQSLCNivel.next())
{
 QTDatos->setText(lintNFila++,
 		 0,
		 QString((*lCQSCNivel->Clase())["Clase"]) +
		 " "					  +
 		(*lCQSCNivel->Nivel())["Nivel"]);
 
 lCQSLGrupo.clear();
 CQSLLCompitiendoAparatos.Grupos(lCQSCNivel,&lCQSLGrupo);

 for(lCQSGrupo=lCQSLGrupo.first();
     lCQSGrupo;
     lCQSGrupo=lCQSLGrupo.next())
 {
 lintNFila++;
 QTDatos->setText(lintNFila,
 		  1,
		  QString((*lCQSGrupo)["Grupo"]) +
		  " "                            +
		  (*lCQSGrupo)["RangoEdad"]);
 lintNFilaAparato=lintNFila; 
 for(lCQSACompetencia=CQSLACompetencia.first(),
     lintNColumna=2,
     lintNAparato=0;
     lCQSACompetencia;
     lCQSACompetencia=CQSLACompetencia.next(),
     lintNColumna++,
     lintNAparato++)
 {
   lCQSLComGimnastas.clear();
    CQSLLCompitiendoAparatos.Gimnastas(lCQSCNivel,
    				       lCQSGrupo,
				       lCQSACompetencia,
				       &lCQSLComGimnastas);
  /*QTDatos->setText(0,lintNColumna,(*lCQSACompetencia->ObtenAparato())["Aparato"]); */
  QTDatos->setText(0,lintNColumna,(*lCQSACompetencia->ObtenAparato())["Aparato"]);
  QTDatos->setItem(0,
  	          lintNColumna,
		  new SiscomTableItemColor(QTDatos,
		  			   lQColor[lintNAparato],
					   QTableItem::Never,
					   (*lCQSACompetencia->ObtenAparato())["Aparato"]));
  for(lCQSCompitiendo=lCQSLComGimnastas.first(),
      lintContador=1;
      lCQSCompitiendo;
      lCQSCompitiendo=lCQSLComGimnastas.next(),
      lintContador++)
  {
     QTDatos->setText(lintNFilaAparato+lintContador,
     		       1,
		       QString((*lCQSCompitiendo->ObtenGimnasta())["Nombre"])	+
		       " "							+
		       (*lCQSCompitiendo->ObtenGimnasta())["APaterno"]		+
		       " "							+
		       (*lCQSCompitiendo->ObtenGimnasta())["AMaterno"]);
    QTDatos->setItem(lintNFilaAparato+lintContador,
    		     lintNColumna,
		     new CQTableItemCalificacion(
		     		lCQSCompitiendo,
				lCQSACompetencia->ObtenAparato(),
			        QTDatos,
				lQColor[lintNAparato],
				QTableItem::Never));
  }
 }
  lintNFila+=lintContador;
 }

}
}
void QTablaResultados::keyPressEvent(QKeyEvent *pQKETecla)
{

	switch(pQKETecla->key())
	{
	 case Qt::Key_F5:
	 		SiscomEscribeLog3Qt("Se actualiza la informacion");
			SiscomDesarrollo3Qt::EliminaFilas(QTDatos);
			SiscomDesarrollo3Qt::EliminaFilas(QTClasPorAparato);
			SiscomDesarrollo3Qt::EliminaFilas(QTGeneral);
			Consultando();
			ConsultandoClasificacionAparatos();
			ConsultandoCompetenciaGeneral();
	 break;
        }

}
CQTableItemCalificacion::CQTableItemCalificacion(
				   CQSisCompitiendo *pCQSCompitiendo,
				   CQSisAparato *pCQSAparato,
					         QTable *pQTable,
				   const QColor &pQCColor,
				   EditType pQEType):
	  QTableItem(pQTable,pQEType,(*pCQSCompitiendo->ObtenCalificacion())["NotaFinal"]),
	  QCColor(pQCColor),
	  CQSCompitiendo(pCQSCompitiendo),
	  CQSAparato(pCQSAparato)
{

}
void CQTableItemCalificacion::paint(QPainter *pQPainter,
			     const QColorGroup &pQCGDato,
			     const QRect &pQRArea,
			     bool pbSelect)
{
	QColorGroup g(pQCGDato);
	g.setColor(QColorGroup::Base,QCColor);
	QTableItem::paint(pQPainter,
			  g,
			  pQRArea,
			  pbSelect);
}
CQSisCompitiendo *CQTableItemCalificacion::Compitiendo()
{
return CQSCompitiendo;
}
CQSisAparato *CQTableItemCalificacion::Aparato()
{
return CQSAparato;
}
