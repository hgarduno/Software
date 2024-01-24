#include <IMP_ResultadosBusqueda.h>
#include <SiscomDesarrollo3Qt++.h>
#include <SiscomRegistros3.h>

#include <qtable.h>
QResultadosBusqueda::QResultadosBusqueda(
				    SiscomRegistro3Lst *pSisReg3LstReg,
				    SiscomDatCom *pSisDatCom, 
			            char **pchrPtrArgumentos, 
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    bool pbModal,
				    WFlags pWFlags):	      
				ResultadosBusqueda(pQWParent,pchrPtrName,pWFlags),
				SisDatCom(pSisDatCom),
				chrPtrArgumentos(pchrPtrArgumentos),
				SisReg3LstRegreso(pSisReg3LstReg),
				chrPtrClave(0)
{
IniciaVariables();
ConectaSlots();
exec();
}

QResultadosBusqueda::~QResultadosBusqueda()
{

}

void QResultadosBusqueda::ConectaSlots()
{
	connect(QTDatos,
		SIGNAL(doubleClicked(int,int,int,const QPoint &)),
		SLOT(SlotSelecciono(int ,int,int,const QPoint &)));

}
void QResultadosBusqueda::SlotSelecciono(int pintNFila,
					 int ,
					 int,
					 const QPoint &)
{
     chrPtrClave=(*(*SisReg3LstRegreso)[pintNFila])["clave"]; 
     SiscomEscribeLog3Qt("La clave:%s",chrPtrClave);
     done(1);

}
void QResultadosBusqueda::IniciaVariables()
{
 MuestraResultados();
}
void QResultadosBusqueda::MuestraResultados()
{
char *lchrPtrCampos[]={"clave",
			     "dsc",
			     "existencia",
			     "precio",
			     "nombre",
			     "cantidad",
			     0
			     };
SiscomDesarrollo3Qt::RegistrosALaTabla(lchrPtrCampos,
				 	QTDatos,
					SisReg3LstRegreso);
SiscomDesarrollo3Qt::AjustaColumnas(QTDatos);
}
const char *QResultadosBusqueda::Clave()
{
return chrPtrClave;
}

