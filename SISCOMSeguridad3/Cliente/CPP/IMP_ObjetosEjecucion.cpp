#include <IMP_ObjetosEjecucion.h>

#include <SoporteAplicacionSeguridad.h>
#include <CQSiscomCom.h>

#include <SISCOMComunicaciones++.h>
#include <qvariant.h>
#include <qpushbutton.h>
#include <qtable.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include <qimage.h>
#include <qpixmap.h>


CQSisObjetosEjecucion::CQSisObjetosEjecucion(CSISCOMDatComunicaciones *pCSisDatCom,
					     const char *pchrPtrNmbForma,
					     QWidget* parent,
					      const char* name, 
					     bool modal,
					      WFlags fl )
    : ObjetosEjecucion( parent, name, modal, fl ),
      CSisDatCom(pCSisDatCom),
      chrPtrNmbForma(pchrPtrNmbForma)
{
	ConectaSlots();
	ConsultaObjetos();
	MuestraObjetos();
	exec();
}

CQSisObjetosEjecucion::~CQSisObjetosEjecucion()
{
}
void CQSisObjetosEjecucion::ConsultaObjetos()
{
QSiscomConsultaObjetos lQSCObjetos(CSisDatCom);
	QSLObjetosQT=lQSCObjetos.ObtenObjetosSeguridad()->ObtenObjetosFiltrados();

	
		

}
void CQSisObjetosEjecucion::ConectaSlots()
{
	connect(QTDatosO,
		SIGNAL(clicked(int,int,int,const QPoint &)),
		SLOT(SlotSeleccionaObjeto(int ,int ,int,const QPoint &)));
	connect(QPBAnexarObjeto,
		SIGNAL(clicked()),
		SLOT(SlotAnexarObjeto()));
	connect(QPBAceptar,
		SIGNAL(clicked()),
		SLOT(SlotAceptar()));
}
void CQSisObjetosEjecucion::SlotAceptar()
{

	BTNCual=BTN_Aceptar;
	done(0);

}
void CQSisObjetosEjecucion::SlotAnexarObjeto()
{
QSiscomObjetosQT *lCQSObjeto;
QSiscomListaObjQ l;	
	MuestraObjetoAAnexar();
	lCQSObjeto=QSLObjetosQT.at(intCualObjeto)->CopiaObjeto((const char *)QLENombre->text());
	printf("El Nombre %s \n",(const char *)lCQSObjeto->ObtenValorPropiedad("name"));
	QSLObjetosAAnexar.append(lCQSObjeto);
	l.append(lCQSObjeto);
	QSiscomArchivoUI::ImprimeObjetos(QSLObjetosAAnexar,"CQSisObjetosEjecucion::SlotAnexarObjeto");
	
}
void CQSisObjetosEjecucion::SlotSeleccionaObjeto(int pintFila,
						 int ,
						 int ,
						 const QPoint &)
{
	intCualObjeto=pintFila;
	QLEObjeto->setText(QTDatosO->text(pintFila,0));
	MuestraPropiedadesXObjeto(pintFila);

}
void CQSisObjetosEjecucion::MuestraObjetoAAnexar()
{
	AnexarRegistroALaTabla(QTDatosObj,
			       QStringList () <<
				QLEObjeto->text() <<
				QLENombre->text() );	
}
void CQSisObjetosEjecucion::MuestraPropiedadesXObjeto(int pintNumObjeto)
{
QSiscomListaPropBD lQSLPropiedades=QSLObjetosQT.at(pintNumObjeto)->ObtenPropiedades();
QSiscomPropiedadesBD *lQSPropiedades;

	QTDatosP->setNumRows(0);
	for(lQSPropiedades=lQSLPropiedades.first();
	    lQSPropiedades;
	    lQSPropiedades=lQSLPropiedades.next())
	{
		AnexarRegistroALaTabla(QTDatosP,
				      QStringList () <<
				       lQSPropiedades->ObtenNombrePropiedad()); 
	}


}
void CQSisObjetosEjecucion::MuestraObjetos()
{
int lintContador;
QSiscomObjetosQT *lCQSObjetosQT;
	QTDatosO->setNumRows(0);
	for(lCQSObjetosQT=QSLObjetosQT.first();
	    lCQSObjetosQT;
	    lCQSObjetosQT=QSLObjetosQT.next())
	  AnexarRegistroALaTabla(QTDatosO,
				 QStringList () <<
				   lCQSObjetosQT->ObtenClaseQT());
}
CQSisObjetosEjecucion::BTN_Seleccion CQSisObjetosEjecucion::ObtenBotonSeleccionado()
{
	return BTNCual;
}
const char *CQSisObjetosEjecucion::ObtenLosObjetosAAnexar(QSiscomListaObjQ &pQSLObjQReg)
{
	pQSLObjQReg=QSLObjetosAAnexar;
	return chrPtrNmbForma;
}
