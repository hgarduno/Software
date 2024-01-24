#include <IMP_Facturando.h>
#include <QImprimeFactura.h>
#include <qlayout.h>
#include <qtable.h>
#include <qlineedit.h>
#include <qscrollview.h>
#include <qvbox.h>
#include <qpushbutton.h>
#include<SISCOMComunicaciones++.h>
QFacturando::QFacturando(const char *pchrPtrCliente,
			 const char *pchrPtrRFC,
			 const ProductosE &pProductos,
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    bool pBModal,
				    WFlags pWFlags):	      
				QDialog(pQWParent,pchrPtrName,pBModal,pWFlags),
				chrPtrCliente(pchrPtrCliente),
				chrPtrRFC(pchrPtrRFC),
				PProductos(pProductos)
{
IniciaVariables();
ConectaSlots();
}

QFacturando::~QFacturando()
{

}

void QFacturando::ConectaSlots()
{


}
/*
void QFacturando::IniciaVariables()
{
 	QIFactura=new QImprimeFactura(chrPtrCliente,
				      chrPtrRFC,
				      PProductos,
				      this);

	QHBRegilla=new QHBoxLayout(this);
	QIFactura->setSizePolicy(
		QSizePolicy(QSizePolicy::Expanding,QSizePolicy::Preferred,true));
	QIFactura->setMaximumSize(QSize(10000,10000));
	QIFactura->setMinimumSize(QSize(600,100));
	QIFactura->PonTamanoFactura(216,279/2);
	QIFactura->resize(QSize(300,400));
	resize(QSize(1000,1000));
	QHBRegilla->addWidget(QIFactura);

}

*/

void QFacturando::IniciaVariables()
{
	resize(QSize(1000,1000));

QIFactura=new QImprimeFactura(chrPtrCliente,
				      chrPtrRFC,
				      PProductos,
				      this);

	QHBRegilla=new QGridLayout(this,1,1,11,6,"QHRegilla");
	QIFactura->PonTamanoFactura(216,279/2);
	/*
	QSSeparador=new QSpacerItem(20,
				    40,
				    QSizePolicy::Minimum,
				    QSizePolicy::Expanding);
	QHBRegilla->addItem(QSSeparador,1,0);
	*/
	QHBRegilla->addWidget(QIFactura,0,0);
	

	


}
