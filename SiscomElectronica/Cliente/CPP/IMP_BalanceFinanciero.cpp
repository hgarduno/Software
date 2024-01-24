#include <IMP_BalanceFinanciero.h>

#include <zSiscomElectronica.h>


#include <zSiscomDesarrollo4.h>
#include <zSiscomRegistro.h>

#include <zSiscomQt3.h>
#include <qpushbutton.h>
#include <qtextbrowser.h>
#include <qlineedit.h>
QBalanceFinanciero *InstanciaBalanceFinanciero(void *pSisDatCom,
                 char **pchrPtrArgumentos,
                 void *pQWParent,
                const char *pchrPtrName,
                 int pintWFlags)
{
	return new QBalanceFinanciero((SiscomDatCom *)pSisDatCom,	
			pchrPtrArgumentos,		
			(QWidget *)pQWParent,		
			pchrPtrName,			
			pintWFlags);
}
QBalanceFinanciero::QBalanceFinanciero(SiscomDatCom *pSisDatCom, 
			            char **pchrPtrArgumentos, 
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    WFlags pWFlags):	      
				BalanceFinanciero(pQWParent,pchrPtrName,pWFlags),
				SisDatCom(pSisDatCom),
				chrPtrArgumentos(pchrPtrArgumentos)
{
IniciaVariables();
ConectaSlots();
}

QBalanceFinanciero::~QBalanceFinanciero()
{

}

void QBalanceFinanciero::ConectaSlots()
{
connect(QPBCargaArchivoHtml,
	SIGNAL(clicked()),
	SLOT(SlotCargaArchivoHtml()));

}
void QBalanceFinanciero::SlotCargaArchivoHtml()
{
CargaArchivoHtml();
}
void QBalanceFinanciero::IniciaVariables()
{
  CargaArchivoHtml();
}

void QBalanceFinanciero::CargaArchivoHtml()
{
char lchrArrBufferLinea[256];
zSiscomDesarrollo4::LeeArchivo("BalanceFinanciero.html",
				lchrArrBufferLinea,
				chrArrBalanceFinanciero);
QTBBalanceFinanciero->setText(chrArrBalanceFinanciero);
}
