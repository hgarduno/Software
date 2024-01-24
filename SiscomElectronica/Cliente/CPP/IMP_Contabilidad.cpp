#include <IMP_Contabilidad.h>

#include <CQSisContabilidad.h>
#include <SiscomDesarrollo3Qt++.h>

#include <qapplication.h>
#include <qclipboard.h>
#include <qpushbutton.h>


#include <SiscomRegistros3.h>
#include <SiscomOperaciones3.h>
QContabilidad *InstanciaContabilidad(void *pSisDatCom,
                 char **pchrPtrArgumentos,
                 void *pQWParent,
                const char *pchrPtrName,
                 int pintWFlags)
{
	return new QContabilidad((SiscomDatCom *)pSisDatCom,	
			pchrPtrArgumentos,		
			(QWidget *)pQWParent,		
			pchrPtrName,			
			pintWFlags);
}
QContabilidad::QContabilidad(SiscomDatCom *pSisDatCom, 
			            char **pchrPtrArgumentos, 
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    WFlags pWFlags):	      
				Contabilidad(pQWParent,pchrPtrName,pWFlags),
				SisDatCom(pSisDatCom),
				chrPtrArgumentos(pchrPtrArgumentos)
{
IniciaVariables();
ConectaSlots();
}

QContabilidad::~QContabilidad()
{

}

void QContabilidad::ConectaSlots()
{
connect(QPBPFacturasC,
	SIGNAL(clicked()),
	SLOT(SlotCopiarFacturasCompras()));
connect(QPBEjecutaContabilidad,
	SIGNAL(clicked()),
	SLOT(SlotEjecutaContabilidad()));
}
void QContabilidad::SlotEjecutaContabilidad()
{
CQSisContabilidad lCQSContabilidad(SisDatCom);
lCQSContabilidad.EjecutaProceso(chrPtrArgumentos[0],	
				"0");
}
void QContabilidad::SlotCopiarFacturasCompras()
{
ObtenFacturasPortaPapeles();
MuestraFacturas();
}
void QContabilidad::IniciaVariables()
{
}

void QContabilidad::ObtenFacturasPortaPapeles()
{
SiscomOperaciones3 lSisOp3Prueba;
lSisOp3Prueba.SiscomFormaRegistrosCadena((const char *)QApplication::clipboard()->text(),
					 &SisReg3LstFacturas);
}
void QContabilidad::MuestraFacturas()
{
const char *lchrPtrCampos[]={"numfactura",
			"fecha",
			"razonsocial",
			0
			};
SiscomDesarrollo3Qt::RegistrosALaTabla(lchrPtrCampos,
				       QTFacturas,
				       &SisReg3LstFacturas);
SiscomDesarrollo3Qt::AjustaColumnas(QTFacturas);
}

void QContabilidad::ConsultandoContabilidad()
{
 ConsultaContabilidad();
 MuestraContabilidad();
}
void QContabilidad::ConsultaContabilidad()
{
CQSisContabilidad lCQSContabilidad(SisDatCom);
	lCQSContabilidad.Contabilidad(chrPtrArgumentos[0],
				      &SisReg3LstFactCompras,
				      &SisReg3LstFactVentas,
				      &SisReg3LstTotales,
				      &SisReg3LstDatRegistro);

}
void QContabilidad::MuestraContabilidad()
{

	MuestraFacturasCompras();
	MuestraFacturasVentas();
	MuestraTotales();
	MuestraDatosRegistro();

}
void QContabilidad::MuestraFacturasCompras()
{

}

void QContabilidad::MuestraFacturasVentas()
{

}
void QContabilidad::MuestraTotales()
{

}
void QContabilidad::MuestraDatosRegistro()
{

}
void QContabilidad::closeEvent(QCloseEvent *)
{
	emit SignalTerminar(this);
}
