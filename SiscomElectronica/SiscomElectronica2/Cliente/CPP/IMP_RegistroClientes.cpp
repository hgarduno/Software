#include <IMP_RegistroClientes.h>
#include<SISCOMComunicaciones++.h>
#include <QSisSepomex.h>


#include <QCtrlEscuelas.h>
#include <CQSisEscuelas.h>
#include <CQSisAlumnos.h>

#include <qpushbutton.h>
#include <qmessagebox.h>

QRegistroClientes *InstanciaRegistroClientes(void *pSisDatCom,
                 char **pchrPtrArgumentos,
                 void *pQWParent,
                const char *pchrPtrName,
                 int pintWFlags)
{
	return new QRegistroClientes((SiscomDatCom *)pSisDatCom,	
			pchrPtrArgumentos,		
			(QWidget *)pQWParent,		
			pchrPtrName,			
			pintWFlags);
}
QRegistroClientes::QRegistroClientes(SiscomDatCom *pSisDatCom, 
			            char **pchrPtrArgumentos, 
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    WFlags pWFlags):	      
				RegistroClientes(pQWParent,pchrPtrName,pWFlags),
				SisDatCom(pSisDatCom),
				chrPtrArgumentos(pchrPtrArgumentos)
{
}

QRegistroClientes::~QRegistroClientes()
{

}
