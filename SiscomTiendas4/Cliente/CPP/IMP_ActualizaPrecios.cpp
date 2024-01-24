#include <IMP_ActualizaPrecios.h>
#include <CQSisOpTiendas43Qt.h>
#include <SiscomDesarrollo3Qt++.h>
#include <QCtrlFamilias.h>
QActualizaPrecios *InstanciaActualizaPrecios(void *pSisDatCom,
                 char **pchrPtrArgumentos,
                 void *pQWParent,
                const char *pchrPtrName,
                 int pintWFlags)
{
	return new QActualizaPrecios((SiscomDatCom *)pSisDatCom,	
			pchrPtrArgumentos,		
			(QWidget *)pQWParent,		
			pchrPtrName,			
			pintWFlags);
}
QActualizaPrecios::QActualizaPrecios(SiscomDatCom *pSisDatCom, 
			            char **pchrPtrArgumentos, 
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    WFlags pWFlags):	      
				ActualizaPrecios(pQWParent,pchrPtrName,pWFlags),
				SisDatCom(pSisDatCom),
				chrPtrArgumentos(pchrPtrArgumentos)
{
IniciaVariables();
ConectaSlots();
}

QActualizaPrecios::~QActualizaPrecios()
{

}

void QActualizaPrecios::ConectaSlots()
{
connect(QCtrFamilias,
	SIGNAL(SignalFamilia(CQSisFamilia *)),
	SLOT(SlotFamilia(CQSisFamilia *)));
connect(QPBConsulta,
	SIGNAL(clicked()),
	SLOT(SlotConsulta()));

}
void QActualizaPrecios::SlotConsulta()
{
ConsultandoProductos();
}
void QActualizaPrecios::SlotFamilia(CQSisFamilia *pCQSFamilia)
{
  CQSFamilia=pCQSFamilia;
  SiscomDesarrollo3Qt::PasaFocoControl(QPBConsulta);
}
void QActualizaPrecios::IniciaVariables()
{
QCtrFamilias->PonServidor(SisDatCom);
QCtrFamilias->IniciaControl();
}

void QActualizaPrecios::ConsultandoProductos()
{
	ConsultaProductos();
	MuestraProductos();
}
void QActualizaPrecios::ConsultaProductos()
{
CQSisOpTiendas43Qt lCQSOpProductos(SisDatCom);
lCQSOpProductos.DatosProductosPorFamilia((*CQSFamilia)["IdFamilia"],
					 &SisReg4Productos);
}
void QActualizaPrecios::MuestraColumna(SiscomRegistro4 *pSisReg4Dato,
				      const char *pchrPtrDato,
				    int pintFila,
				    int pintColumna,
				    int pintSubGrupo,
				    int pintRegistro)
{
QTProductos->setText(pintFila,
		 pintColumna,
		 pSisReg4Dato->CampoRegistroSubGrupo(pintFila,
		 				     pintSubGrupo,
						     pintRegistro,
						     pchrPtrDato));

}
void QActualizaPrecios::MuestraColumnasPrecios(SiscomRegistro3Lst *pSisReg3LstPrecios,
					      int pintFila)
{
int lintColumna=2;
SiscomRegistro3 *lSisReg3Precio;
QHeader *lQHNmbPrecio=QTProductos->horizontalHeader();
for(lintColumna=6,
    lSisReg3Precio=pSisReg3LstPrecios->first();
    lSisReg3Precio;
    lintColumna+=3,
    lSisReg3Precio=pSisReg3LstPrecios->next())
{
lQHNmbPrecio->setLabel(lintColumna,(*lSisReg3Precio)["nombre"]);
QTProductos->setText(pintFila,lintColumna,(*lSisReg3Precio)["precio"]);
QTProductos->setText(pintFila,lintColumna+1,(*lSisReg3Precio)["cantidad"]);
}
    

}
void QActualizaPrecios::MuestraProductos()
{
int lintContador;
int lintNFilas;
SiscomEscribeLog3Qt("Mostrando los resultados");
SiscomRegistro3LstContenido(SisReg4Productos.RegistrosSubGrupo(5,0));
SiscomRegistro3LstContenido(SisReg4Productos.RegistrosSubGrupo(5,1));
SiscomRegistro3LstContenido(SisReg4Productos.RegistrosSubGrupo(5,2));
QTProductos->setNumRows((lintNFilas=SisReg4Productos.count()));
QTProductos->setNumCols(QTProductos->numCols()+
			3*SisReg4Productos.RegistrosSubGrupo(0,1)->count());
for(lintContador=0;
    lintContador<lintNFilas;
    lintContador++)
{
MuestraColumna(&SisReg4Productos,"clave",lintContador,0,0,0);
MuestraColumna(&SisReg4Productos,"dsc",lintContador,1,0,0);
MuestraColumna(&SisReg4Productos,"fecha",lintContador,2,2,0);
MuestraColumna(&SisReg4Productos,"cantidad",lintContador,3,2,0);
MuestraColumna(&SisReg4Productos,"razonsocial",lintContador,4,2,0);
MuestraColumna(&SisReg4Productos,"preciocompra",lintContador,5,2,0);
MuestraColumnasPrecios(SisReg4Productos.RegistrosSubGrupo(lintContador,1),lintContador);	
}
SiscomDesarrollo3Qt::AjustaColumnas(QTProductos);
}
