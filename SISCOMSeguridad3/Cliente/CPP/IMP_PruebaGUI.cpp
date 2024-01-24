#include <IMP_PruebaGUI.h>

#include <CSISCOMComunicaciones.h>
#include <GeneralBibliotecaSeguridad3.h>

#include <SISCOMComunicaciones++.h>
#include <qvariant.h>
#include <qtable.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include <qaction.h>

CQSisPruebasGUI::CQSisPruebasGUI(CSISCOMDatComunicaciones *pCSisDatCom,
				  QWidget* parent, const char* name, WFlags fl )
    : PruebasGUI( parent, name, fl ) ,
	CSisDatCom(pCSisDatCom)
{

	connect(QTDatos,
		SIGNAL(contextMenuRequested(int,int,const QPoint &)),
		SLOT(SlotMuestraMenu(int ,int ,const QPoint &)));

}

CQSisPruebasGUI::~CQSisPruebasGUI()
{
}
void CQSisPruebasGUI::SlotMuestraMenu(int ,
				      int ,
				      const QPoint &pQPPosicion)
{
  CQSisMenuPrueba *lCQSMPrueba=new CQSisMenuPrueba(QTDatos,
						   pQPPosicion,
						   CSisDatCom);

}

CQSisMenuPrueba::CQSisMenuPrueba(QWidget *pQWParent,
				 const QPoint &pQPPosicion,
				 CSISCOMDatComunicaciones *pCSisDatCom):
				QPopupMenu(pQWParent,0),
				CSisDatCom(pCSisDatCom)
{
	CreaMenu();
	AsignaPermisos();
	popup(pQPPosicion);

}
void CQSisMenuPrueba::CreaMenu()
{
	(QAPrueba1=CreaOpcionMenu("Prueba1","Prueba1"))->addTo(this);
	(QAPrueba2=CreaOpcionMenu("Prueba2","Prueba2"))->addTo(this);
	(QAPrueba3=CreaOpcionMenu("Prueba3","Prueba3"))->addTo(this);
	(QAPrueba4=CreaOpcionMenu("Prueba4","Prueba4"))->addTo(this);

}
QAction *CQSisMenuPrueba::CreaOpcionMenu(const char *pchrPtrTexto,
				         const char *pchrPtrNombre,
				         const char *pchrPtrSlot)
{
QAction *lQAOpcion=new QAction(this,pchrPtrNombre);

	lQAOpcion->setText(pchrPtrTexto);	

	return lQAOpcion;
}
void CQSisMenuPrueba::AsignaPermisos()
{
QObjectList lQOLDatos;

	lQOLDatos.append(QAPrueba1);
	lQOLDatos.append(QAPrueba2);
	lQOLDatos.append(QAPrueba3);
	lQOLDatos.append(QAPrueba4);
QSiscomSeguridad3 lQSSeguridad3(
				  lQOLDatos,
				CSisDatCom,
				QStringList() << "text" , 
				  "Pruebas",
				  "Aplicaciones");
				   
}
