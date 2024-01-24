#include <IMP_ExistenciaExpendios.h>

#include <zExistenciaExpendios.h>
#include <zExistenciaExpendio.h>

#include <QCtrlProductosSE.h>

#include <zSiscomElectronica.h>
#include <zSiscomDesarrollo4.h>
#include <zSiscomRegistro.h>
#include <zSiscomQt3.h>

#include <qtextedit.h>
#include <qtable.h>
#include <qpushbutton.h>

QExistenciaExpendios *InstanciaExistenciaExpendios(void *pSisDatCom,
                 char **pchrPtrArgumentos,
                 void *pQWParent,
                const char *pchrPtrName,
                 int pintWFlags)
{
	return new QExistenciaExpendios((SiscomDatCom *)pSisDatCom,	
			pchrPtrArgumentos,		
			(QWidget *)pQWParent,		
			pchrPtrName,			
			pintWFlags);
}
QExistenciaExpendios::QExistenciaExpendios(SiscomDatCom *pSisDatCom, 
			            char **pchrPtrArgumentos, 
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    WFlags pWFlags):	      
				ExistenciaExpendios(pQWParent,pchrPtrName,pWFlags),
				zSisConexion((zSiscomConexion *)gzSiscomConexion),	
				chrPtrArgumentos(pchrPtrArgumentos)
{
IniciaVariables();
ConectaSlots();
}

QExistenciaExpendios::~QExistenciaExpendios()
{

}

void QExistenciaExpendios::ConectaSlots()
{

connect(QCtrProductos,
	SIGNAL(SignalSelecciono(zSiscomRegistro *)),
	SLOT(SlotSeleccionoProducto(zSiscomRegistro *)));
connect(QPBActualizar,
	SIGNAL(clicked()),
	SLOT(SlotActualizar()));
}
void QExistenciaExpendios::SlotActualizar()
{
   zExExpendios.Libera();
   Consulta(&zProdsRegreso);
   Muestra();
}
void QExistenciaExpendios::SlotSeleccionoProducto(zSiscomRegistro *pzSisRegProducto)
{
	QTExistenciaExpendios->setNumRows(0);
	zExExpendios.Libera();
	zProdsRegreso.Agrega((const char *)(*pzSisRegProducto)["cveproducto"]);
	zSisRegProducto=pzSisRegProducto;
        Consultando(&zProdsRegreso);
	/* SISCOM UPIITA Jueves 17 de octubre 2019
	 * Para que no se borre la entrada anterior  
	 * y muestre una lista de los productoss
	zProdsRegreso.Libera();
	*/

}
void QExistenciaExpendios::Consultando(zProductos *pzProductos)
{
Consulta(pzProductos);
Muestra();
zSiscomQt3::Foco(QCtrProductos);
zSiscomQt3::AjustaColumnasTabla(QTExistenciaExpendios);
}
void QExistenciaExpendios::Consulta(zProductos *pzProductos)
{

zSiscomElectronica lzSisElectronica(zSisConexion,"ExistenciaExpendios");
lzSisElectronica.ExistenciaExpendios(pzProductos,&zExExpendios);
}
int QExistenciaExpendios::MuestraExistenciaExpendio(int pintFila,
						     zExistenciaExpendio *pzExExpendio)
{
int lintContador;
zSiscomRegistros *lzSisRegsExpendios=pzExExpendio->AsociadosDelCampo("Expendio");
zSiscomRegistro *lzSisRegExpendio;
SiscomRegistrosLog(lzSisRegsExpendios);
for(lintContador=pintFila+1,
    lzSisRegExpendio=lzSisRegsExpendios->Primer();
    lzSisRegExpendio;
    lzSisRegExpendio=lzSisRegsExpendios->Siguiente(),
    lintContador++)
{
     QTExistenciaExpendios->setNumRows(lintContador+1);
     QTExistenciaExpendios->setText(lintContador,1,(const char *)(*lzSisRegExpendio)["razonsocial"]);
     QTExistenciaExpendios->setText(lintContador,2,(const char *)(*lzSisRegExpendio)["existencia"]);
     QTExistenciaExpendios->setText(lintContador,3,(const char *)(*lzSisRegExpendio)["precio"]);
}

   return lintContador; 
}
void QExistenciaExpendios::Muestra()
{
int lintContador;
zExistenciaExpendio *lzExExpendio;
for(lzExExpendio=(zExistenciaExpendio *)zExExpendios.Primer(),
    lintContador=0;
    lzExExpendio;
    lzExExpendio=(zExistenciaExpendio *)zExExpendios.Siguiente(),
    lintContador++)
{
    QTExistenciaExpendios->setNumRows(lintContador+1);
    QTExistenciaExpendios->setText(lintContador,0,(const char *)(*lzExExpendio)["cveproducto"]);
    lintContador=MuestraExistenciaExpendio(lintContador,lzExExpendio)-1;
}
zSiscomQt3::AjustaColumnasTabla(QTExistenciaExpendios);
}
void QExistenciaExpendios::IniciaVariables()
{
  QCtrProductos->Servidor(zSisConexion);  
  QCtrProductos->IniciaControl();
  zSiscomQt3::Foco(QCtrProductos);
}
