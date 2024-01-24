#include <IMP_SeguridadCajaVentas.h>
#include <IMP_CambiaEdoControlCaja.h>
#include <QtSeguridadCajas.h>
#include<SISCOMComunicaciones++.h>
#include <SiscomDesarrollo3Qt++.h>

QSeguridadCajaVentas *InstanciaSeguridadCajaVentas(void *pSisDatCom,
                 char **pchrPtrArgumentos,
                 void *pQWParent,
                const char *pchrPtrName,
                 int pintWFlags)
{
	return new QSeguridadCajaVentas((SiscomDatCom *)pSisDatCom,	
			pchrPtrArgumentos,		
			(QWidget *)pQWParent,		
			pchrPtrName,			
			pintWFlags);
}
QSeguridadCajaVentas::QSeguridadCajaVentas(SiscomDatCom *pSisDatCom, 
			            char **pchrPtrArgumentos, 
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    WFlags pWFlags):	      
				SeguridadCajaVentas(pQWParent,pchrPtrName,pWFlags),
				SisDatCom(pSisDatCom),
				chrPtrArgumentos(pchrPtrArgumentos)
{
IniciaVariables();
ConectaSlots();
}

QSeguridadCajaVentas::~QSeguridadCajaVentas()
{

}

void QSeguridadCajaVentas::ConectaSlots()
{
	connect(QPBRCambios,
		SIGNAL(clicked()),
		SLOT(SlotRegistrar()));
	connect(QPBActualizar,
		SIGNAL(clicked()),
		SLOT(SlotActualizar()));
	connect(QLVCajas,
		SIGNAL(clicked(QListViewItem *)),
		SLOT(SlotSeleccionoCaja(QListViewItem *)));

}
void QSeguridadCajaVentas::SlotSeleccionoCaja(QListViewItem *pQLVItemCaja)
{
QtListViewItemEstadoControl *lQtLstViewItemEdoControl;
if(pQLVItemCaja)
{
   if(!pQLVItemCaja->childCount())
   {
      lQtLstViewItemEdoControl=(QtListViewItemEstadoControl *)pQLVItemCaja;
      QCambiaEdoControlCaja lQCEdoControl(lQtLstViewItemEdoControl);


   }


}
}
void QSeguridadCajaVentas::SlotActualizar()
{
	QLVCajas->clear();	
	ConsultandoCajas();
}
void QSeguridadCajaVentas::SlotRegistrar()
{
CQSisOpControlCaja lCQSOCaja(SisDatCom);
lCQSOCaja.RegistraEstados(chrPtrArgumentos[0],
			  &CQSCajasSeguridad);
}
void QSeguridadCajaVentas::IniciaVariables()
{
ConsultandoCajas();
}
void QSeguridadCajaVentas::ConsultandoCajas()
{
	ConsultaCajas();
	MuestraCajas();
}
void QSeguridadCajaVentas::ConsultaCajas()
{
SiscomRegistro3Lst lSReg3CajasYControles;
CQSisOpControlCaja lCQSOControlCaja(SisDatCom);
CQSCajasSeguridad.clear();
lCQSOControlCaja.CajasYControles(chrPtrArgumentos[0],
				 &lSReg3CajasYControles,
				 &CQSCajasSeguridad);
}
void QSeguridadCajaVentas::MuestraCajas()
{
CQSisCajaSeguridad *lCQSCajaSeguridad;
QtListViewItemCaja *lQtLstViewItemCaja;
SiscomRegistro3Lst lSisReg3LstControles;
for(lCQSCajaSeguridad=CQSCajasSeguridad.first();
    lCQSCajaSeguridad;
    lCQSCajaSeguridad=CQSCajasSeguridad.next())
{
lQtLstViewItemCaja=new QtListViewItemCaja(lCQSCajaSeguridad,QLVCajas);
QLVCajas->insertItem(lQtLstViewItemCaja);
lSisReg3LstControles=lCQSCajaSeguridad->ControlesCaja();
MuestraControlesCaja(lSisReg3LstControles,lQtLstViewItemCaja);

}
}
void QSeguridadCajaVentas::MuestraControlesCaja(
				SiscomRegistro3Lst &pSisReg3LstControles,
				QtListViewItemCaja *pQtLstViewItemCaja)
{
SiscomRegistro3 *lSisReg3Control;
QtListViewItemControlCaja *lQtLstViewItemCCaja;
for(lSisReg3Control=pSisReg3LstControles.first();
    lSisReg3Control;
    lSisReg3Control=pSisReg3LstControles.next())
{
SiscomEscribeLog3Qt("\t%s(%s)",
		    (*lSisReg3Control)["nombreqt"],
		    (*lSisReg3Control)["estado"]);
lQtLstViewItemCCaja=new QtListViewItemControlCaja(lSisReg3Control,
						 pQtLstViewItemCaja);
pQtLstViewItemCaja->insertItem(lQtLstViewItemCCaja);
}
}
void QSeguridadCajaVentas::closeEvent(QCloseEvent *)
{
emit SignalTerminar(this);
}
