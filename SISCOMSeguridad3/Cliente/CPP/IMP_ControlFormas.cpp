#include <IMP_ControlFormas.h>
#include <IMP_CapturaDatos.h>
#include <IMP_SIN_UI_MenuOperaciones.h>
#include <IMP_ObjetosEjecucion.h>
#include <IMP_SelIconos.h>
#include <SISCOMComunicaciones++.h>

#include <CQSiscomCom.h>
#include <qvariant.h>
#include <qiconview.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include <qimage.h>
#include <qpixmap.h>
#include <qpushbutton.h>
#include <qptrlist.h>
CQSisControlFormas::CQSisControlFormas(QSiscomListaContXForma pQSLContXForma,
				       CSISCOMDatComunicaciones *pCSisDatCom,
					QString pQSAplicacion,
				        QWidget* parent, 
					const char* name,
					 WFlags fl ):
	 ControlFormas( parent, name, fl ),
      CSisDatCom(pCSisDatCom),
	QSAplicacion(pQSAplicacion),
	QPLObjetos(pQSLContXForma),
	CQSMOperaciones(0)
{
	MuestraFormas();
	ConectaSlots();
	show();
}


CQSisControlFormas::CQSisControlFormas(QStringList pQSLArchivos,
				       CSISCOMDatComunicaciones *pCSisDatCom,
					QString pQSAplicacion,
				        QWidget* parent, 
					const char* name,
					 WFlags fl ):
	 ControlFormas( parent, name, fl ),
      CSisDatCom(pCSisDatCom),
	QSAplicacion(pQSAplicacion),
	QSLArchivos(pQSLArchivos)
{
	CargaArchivos();
	MuestraFormas();
	ConectaSlots();
	show();
}

CQSisControlFormas::~CQSisControlFormas()
{
}
void CQSisControlFormas::showEvent(QShowEvent *)
{
	printf("Es la forma \n");
}
void CQSisControlFormas::focusInEvent(QFocusEvent *)
{
	printf("Esta en el control \n");
}
void CQSisControlFormas::mouseReleaseEvent(QMouseEvent *)
{
	printf("Se preciono el raton \n");
}
void CQSisControlFormas::ConectaSlots()
{
	connect(QLVLista,
		SIGNAL(clicked(QListViewItem *,const QPoint &,int)),
		SLOT(SlotSeleccionoItem(QListViewItem *,const QPoint &,int )));
	connect(QLVLista,
		SIGNAL(contextMenuRequested(QListViewItem *,const QPoint &,int )),
		SLOT(SlotMenuOperaciones(QListViewItem *,const QPoint &,int )));

}
void CQSisControlFormas::SlotMenuOperaciones(QListViewItem *pQLVItemDat,
					     const QPoint &pQPDonde,
					     int )
{
      if(CQSMOperaciones)
      {
       delete CQSMOperaciones;
       CQSMOperaciones=0;
      }
      CQSMOperaciones=new CQSisMOperaciones(pQPDonde,
					    QLVLista,
					    "lCQSMOperaciones");
	connect(CQSMOperaciones,
		SIGNAL(SignalAnexaObjeto()),
		SLOT(SlotAnexarObjetos()));
	chrPtrFormaAAnexarOE=pQLVItemDat->text(0);
	
}
void CQSisControlFormas::SlotAnexarObjetos()
{
CQSisObjetosEjecucion *lCQSOEjecucion=new CQSisObjetosEjecucion(CSisDatCom,chrPtrFormaAAnexarOE);
QSiscomListaObjQ lQSLObjAAnexar;
const char *lchrPtrNmbForma;
	if(lCQSOEjecucion->ObtenBotonSeleccionado()==CQSisObjetosEjecucion::BTN_Aceptar)
	{
		QLVLista->clear();
		lchrPtrNmbForma=lCQSOEjecucion->ObtenLosObjetosAAnexar(lQSLObjAAnexar);	
		AnexaControlesEnTiempoDeEjecucion(lchrPtrNmbForma,lQSLObjAAnexar);
		MuestraFormas();		
	}

delete lCQSOEjecucion;

}
void CQSisControlFormas::AnexaControlesEnTiempoDeEjecucion(const char *pchrPtrNmbForma,
							   QSiscomListaObjQ pQSLObjetos)
{
QSiscomObjetosSeguridad *lQSisObjSeguridad;
QSiscomListaObjQ lQSLObjActuales;
int lintContador;
	for(lQSisObjSeguridad=QPLObjetos.first();
	    lQSisObjSeguridad;
	    lQSisObjSeguridad=QPLObjetos.next())
	{
		if(lQSisObjSeguridad->ObtenNombreForma()==pchrPtrNmbForma  &&
		   pQSLObjetos.count())
		{
			printf("Se Anexaran los objetos A {%s}\n",pchrPtrNmbForma);	
			lQSLObjActuales=lQSisObjSeguridad->ObtenObjetosFiltrados();
			for(lintContador=0;
			    lintContador<pQSLObjetos.count();
			    lintContador++)
		         {
			  printf("Anexando -> {%s} \n",
				(const char *)pQSLObjetos.at(lintContador)->ObtenNombreObjeto());
			 lQSLObjActuales.append(pQSLObjetos.at(lintContador));
			 }
		       for(lintContador=0;lintContador<lQSLObjActuales.count();lintContador++)
			  printf("Los Controles Despues ... {%s} \n",
				(const char *)lQSLObjActuales.at(lintContador)->ObtenNombreObjeto());

			lQSisObjSeguridad->PonObjetosFiltrados(lQSLObjActuales);
			
		}
	}
    QSiscomArchivoUI::ImprimeObjetos(lQSLObjActuales,
				    "CQSisControlFormas::AnexaControlEnTiempoDeEjecucion");
}
/*
void CQSisControlFormas::SlotPrueba()
{
int lintContador;
int lintNFormas=QPLObjetos.count();
QSiscomObjetosSeguridad *lQSisObjSeguridad;
QSiscomListaObjQ lQSLObjCont;
QSiscomObjetosQT *lQSObjQtDat;
QSiscomPropiedadesBD *lQSPropXObj;
QSiscomListaPropBD lQSLPropiedades;
	for(lintContador=0;lintContador<lintNFormas;lintContador++)
	{
	  for(lQSisObjSeguridad=QPLObjetos.first();
	      lQSisObjSeguridad;
	      lQSisObjSeguridad=QPLObjetos.next())
	  {
		printf("%s\n",(const char *)lQSisObjSeguridad->ObtenNombreForma());
		lQSLObjCont=lQSisObjSeguridad->ObtenObjetosFiltrados();
		for(lQSObjQtDat=lQSLObjCont.first();
		    lQSObjQtDat;
		    lQSObjQtDat=lQSLObjCont.next())
		{
		   lQSLPropiedades=lQSObjQtDat->ObtenPropiedades(); 
		   printf("\t%s\n",(const char *)lQSObjQtDat->ObtenNombreObjeto());
		  for(lQSPropXObj=lQSLPropiedades.first();
		      lQSPropXObj;
		      lQSPropXObj=lQSLPropiedades.next())
		   printf("\t\t%s->%s\n",
			(const char *)lQSPropXObj->ObtenNombrePropiedad(),
			(const char *)lQSPropXObj->ObtenValorPropiedad());
		    

		}
		

	  }

	}


}
*/
QSiscomListaObjSeguridad CQSisControlFormas::ObtenObjetos()
{
	return QPLObjetos;
}
void CQSisControlFormas::SlotSeleccionoItem(QListViewItem *pQLVIDato,
					    const QPoint &,
					    int pintC)
{
	if(pQLVIDato)
	{
	  CQSisListViewItemValorPropiedad *lCQSisLVIVPropiedad=(CQSisListViewItemValorPropiedad *)pQLVIDato;
	  if(!lCQSisLVIVPropiedad->childCount())
	  {
	  QSiscomPropiedadesBD *QSisPropObjBD=lCQSisLVIVPropiedad->ObtenPropiedades();
	 
	  if(QSisPropObjBD->ObtenNombrePropiedad()=="iconSet")
	  CapturaIcono(QSisPropObjBD,pQLVIDato);
	  else 
	  if(QSisPropObjBD->ObtenNombrePropiedad()!="name")
	    CapturaDatoPropiedad(QSisPropObjBD,pQLVIDato);
	  }
	 }
}
void CQSisControlFormas::CapturaIcono(QSiscomPropiedadesBD *pQSPropiedades,
				      QListViewItem *pQLVIDato)
{
CQSisSelIconos *lQSSIconos=new CQSisSelIconos();
	
		if(lQSSIconos->ObtenLaSeleccion()==CQSisSelIconos::BTN_Aceptar)
		{
		    pQSPropiedades->PonValorPropiedad(lQSSIconos->ObtenArchivo());
		    pQLVIDato->setText(0,lQSSIconos->ObtenArchivo());
		}

	delete lQSSIconos;

}
void CQSisControlFormas::CapturaDatoPropiedad(QSiscomPropiedadesBD *pQSPropiedades,
					      QListViewItem *pQLVIDato)
{
CQSisCapturaDatos *lQSisCapDatos;
	  lQSisCapDatos=new CQSisCapturaDatos(pQSPropiedades->ObtenValorPropiedad());
	  if((lQSisCapDatos->ElBotonSeleccionado()==CQSisCapturaDatos::BTN_Aceptar))
	  {
	    pQSPropiedades->PonValorPropiedad(lQSisCapDatos->ObtenDatoNuevo());
	    pQLVIDato->setText(0,lQSisCapDatos->ObtenDatoNuevo());
	    
	  }
   delete lQSisCapDatos;
}
void CQSisControlFormas::CargaArchivo(QString pQSArchivo)
{
QSiscomArchivoUI lQSisAUi(pQSArchivo);
	QPLObjetos.append(new QSiscomObjetosSeguridad(CSisDatCom,
						      lQSisAUi.ObtenControlesArchivo(),
						      QSAplicacion,
						      lQSisAUi.ObtenClase(),
						      lQSisAUi.ObtenNmbForma()));

}
void CQSisControlFormas::MuestraFormas()
{
int lintContador,
    lintNFormas=QPLObjetos.count();
CQSisListViewItemFormas *lCQSisLVItemFormas;
QSiscomObjetosSeguridad *lQSisObjSeguridad;
	for(lintContador=0;lintContador<lintNFormas;lintContador++)
	{
		lQSisObjSeguridad=QPLObjetos.at(lintContador);	
		lCQSisLVItemFormas=new CQSisListViewItemFormas(QPLObjetos.at(lintContador),
							 QLVLista,
							 lQSisObjSeguridad->ObtenNombreForma());	
		 QLVLista->insertItem(lCQSisLVItemFormas);
		 ColocaControlesXForma(lCQSisLVItemFormas,lQSisObjSeguridad);
	}



}
void CQSisControlFormas::ColocaControlesXForma(CQSisListViewItemFormas *pCQSisLVFormas,
					       QSiscomObjetosSeguridad *pQSisObjSeguridad)
{
CQSisListViewItemConXForma *lCQSisLVIConXForma;
QSiscomObjetosQT *lQSisObjQT;
QSiscomListaObjQ lQSisLObjQT=pQSisObjSeguridad->ObtenObjetosFiltrados();
int lintContador;
	
		for(lQSisObjQT=lQSisLObjQT.first();
		    lQSisObjQT;
		    lQSisObjQT=lQSisLObjQT.next())
		{
		   lCQSisLVIConXForma=new CQSisListViewItemConXForma(lQSisObjQT,
								     (QListViewItem *)pCQSisLVFormas,
								     lQSisObjQT->ObtenNombreObjeto());
		   pCQSisLVFormas->insertItem(lCQSisLVIConXForma);
		   ColocaPropiedadesXObjeto(lCQSisLVIConXForma,lQSisObjQT);
		}
		  	

}
void CQSisControlFormas::ColocaPropiedadesXObjeto(CQSisListViewItemConXForma *pCQSisLVICXForma,
						  QSiscomObjetosQT *pQSisObjQT)
{
CQSisListViewItemPropiedadesObj *lCQSisLVIPropObj;
QSiscomPropiedadesBD *lQSisPropObjDB;
QSiscomListaPropBD lQSisLPropBD=pQSisObjQT->ObtenPropiedades();

			for(lQSisPropObjDB=lQSisLPropBD.first();
			    lQSisPropObjDB;
			    lQSisPropObjDB=lQSisLPropBD.next())
			 {
				lCQSisLVIPropObj=new CQSisListViewItemPropiedadesObj(
						      lQSisPropObjDB,
						      (QListViewItem *)pCQSisLVICXForma,
						      lQSisPropObjDB->ObtenNombrePropiedad());
				pCQSisLVICXForma->insertItem(lCQSisLVIPropObj);
				lCQSisLVIPropObj->insertItem(new CQSisListViewItemValorPropiedad(lQSisPropObjDB,
								  lCQSisLVIPropObj,
								  lQSisPropObjDB->ObtenValorPropiedad()));
			 }
} 
void CQSisControlFormas::CargaArchivos()
{
int lintContador,
    lintNArchivos=QSLArchivos.size();
	for(lintContador=0;lintContador<lintNArchivos;lintContador++)
	{
	 printf("El Archivo -> %s \n",(const char *)QSLArchivos[lintContador]);
	 CargaArchivo(QSLArchivos[lintContador]);
	}

}



CQSisIconViewContF::CQSisIconViewContF(QSiscomObjetosSeguridad *pQSisObjSeguridad,
				       QIconView *pQIVControl):
		    QIconViewItem(pQIVControl),
		    QSisObjSeguridad(pQSisObjSeguridad)
		    
{
	setText(QSisObjSeguridad->ObtenNombreForma(),1);
}
void CQSisIconViewContF::MuestraControles()
{
 

}
CQSisListViewItemFormas::CQSisListViewItemFormas(QSiscomObjetosSeguridad *pQSObjSeguridad,
				     QListView *pQLVControl,
				     QString pQSCadena):
		    QSisObjSeguridad(pQSObjSeguridad),
		    QListViewItem(pQLVControl,pQSCadena)
{

}
CQSisListViewItemConXForma::CQSisListViewItemConXForma(
					QSiscomObjetosQT *pQSObjetosQT,
					QListViewItem *pQLVIParent,
					QString pQSCadena):
			QSisObjQT(pQSObjetosQT),
			QListViewItem(pQLVIParent)
{

	   setText(0,pQSCadena);

}
CQSisListViewItemPropiedadesObj::CQSisListViewItemPropiedadesObj(
				  QSiscomPropiedadesBD *pQSisPropObj,
				  QListViewItem *pQLVIParent,
				  QString pQSCadena):
			QSisPropObjBD(pQSisPropObj),
			QListViewItem(pQLVIParent)
{
	setText(0,pQSCadena);
}
CQSisListViewItemValorPropiedad::CQSisListViewItemValorPropiedad(QSiscomPropiedadesBD *pQPropObjeto,
								 QListViewItem *pQLVIParent,
								 QString pQSValor):
			QListViewItem(pQLVIParent),
			QSisPropObjBD(pQPropObjeto)

{
	setText(0,pQSValor);
}
QSiscomPropiedadesBD *CQSisListViewItemValorPropiedad::ObtenPropiedades()
{
	return QSisPropObjBD;
}
