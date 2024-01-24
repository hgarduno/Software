#include <QtSincronizaExpendio.h>
#include <IMP_ExpendioOrigen.h>


#include <SISCOMComunicaciones++.h>
#include <QCtrlExpendios.h>

#include <zEmpresa.h>
#include <zListaExpendios.h>

#include <qpushbutton.h>

#include <zSiscomDesarrollo4.h>
#include <zSiscomElectronica.h>

QtSincronizaExpendio::QtSincronizaExpendio(SiscomDatCom *pSisDatCom,
					   char **pchrPtrArgumentos,
					   QWidget *pQWParent,
					   const char *pchrPtrName,
					   WFlags pWFlags):
			SincronizaExpendio(pQWParent,pchrPtrName,pWFlags),
				  SisDatCom(pSisDatCom),
				  chrPtrArgumentos(pchrPtrArgumentos),
				  zSisConexion((zSiscomConexion *)gzSiscomConexion),
				  zEExpendioO(0)
				 
{
 IniciaVariables();
 ConectaSlots();
}



void QtSincronizaExpendio::IniciaExpendios()
{
 QCtrExpendiosO->Servidor(SisDatCom);
 QCtrExpendiosO->Expendio(chrPtrArgumentos[0]);
 QCtrExpendiosO->IniciaControl();
}
void QtSincronizaExpendio::IniciandoLasVariables()
{
 zLstExpendios=new zListaExpendios;
}
void QtSincronizaExpendio::IniciaVariables()
{
   IniciandoLasVariables();
   IniciaExpendios();
}

void QtSincronizaExpendio::ConectaSlots()
{
	connect(QPBSincronizaProd,
		SIGNAL(clicked()),
		SLOT(SlotSincronizaProductos()));
	connect(QCtrExpendiosO,
                SIGNAL(SignalExpendio(SiscomRegistro3 *)),
                SLOT(SlotExpendio(SiscomRegistro3 *)));
	connect(QPBSincronizaPrec,
		SIGNAL(clicked()),
		SLOT(SlotSincronizaPrecios()));
}
void QtSincronizaExpendio::SlotSincronizaPrecios()
{
      ExpendioOrigen();
}
void QtSincronizaExpendio::SlotExpendio(SiscomRegistro3 *pSisReg3Expendio)
{
      Expendios()->Agrega(zEmpresa::DeSiscomRegistro3(pSisReg3Expendio));
      QPBSincronizaPrec->setEnabled(true);
}
void QtSincronizaExpendio::SlotSincronizaProductos()
{
	SincronizaProductos(zLstExpendios);
}
void QtSincronizaExpendio::SincronizaProductos(zListaExpendios *pzLstExpendios)
{
}

zListaExpendios *QtSincronizaExpendio::Expendios()
{
   return zLstExpendios;
}

void QtSincronizaExpendio::ExpendioOrigen()
{
if(!ExpendioO())
{
QExpendioOrigen lQExpO(SisDatCom,chrPtrArgumentos);
QPBSincronizaPrec->setText(QString("Sincroniza\n")		+
				    "Precios"			+
				    "\n"			+
				    "Expendio Origen\n"		+
				    lQExpO.Expendio()->RazonSocial());
  ExpendioO(lQExpO.Expendio());
  Expendios()->Agrega(ExpendioO());
  QPBSincronizaPrec->setEnabled(false);
}
else
SincronizaPrecios();
}
void QtSincronizaExpendio::ExpendioO(zEmpresa *pzEmpresa)
{
	zEExpendioO=pzEmpresa;
}
zEmpresa *QtSincronizaExpendio::ExpendioO()
{
	return zEExpendioO;
}
void QtSincronizaExpendio::SincronizaPrecios()

{
}
