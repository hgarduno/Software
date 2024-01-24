#include <IMP_MuestraExistenciaExpendios.h>
#include <zExistenciaExpendio.h>
#include <zSiscomElectronica.h>
#include <zSiscomDesarrollo4.h>
#include <zSiscomRegistro.h>
#include <zSiscomQt3.h>

#include <qmessagebox.h>
#include <qtable.h>
#include <qpushbutton.h>
QMuestraExistenciaExpendios::QMuestraExistenciaExpendios(
				   zSiscomRegistro *pzSisRegProducto,
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    bool pbModal,
				    WFlags pWFlags):	      
				MuestraExistenciaExpendios(pQWParent,pchrPtrName,pbModal,pWFlags),
				zSisConexion((zSiscomConexion *)gzSiscomConexion),
				zSisRegProducto(pzSisRegProducto)
{
setFont(pQWParent->font());
IniciaVariables();
ConectaSlots();
exec();
}

QMuestraExistenciaExpendios::~QMuestraExistenciaExpendios()
{

}
void QMuestraExistenciaExpendios::IniciaVariables()
{
  zProdsRegreso.Agrega((const char *)(*zSisRegProducto)["cveproducto"]); 
  Consultando(&zProdsRegreso);
}
void QMuestraExistenciaExpendios::ConectaSlots()
{
  connect(QPBCancelar,SIGNAL(clicked()),SLOT(SlotCancelar()));
}
void QMuestraExistenciaExpendios::SlotCancelar()
{
   done(1);
}
void QMuestraExistenciaExpendios::Consultando(zProductos *pzProductos)
{
Consulta(pzProductos);  
Muestra();
}
void QMuestraExistenciaExpendios::Consulta(zProductos *pzProductos)
{
zSiscomElectronica lzSisElectronica(zSisConexion,"ExistenciaExpendios");
lzSisElectronica.ExistenciaExpendios(pzProductos,&zExExpendios);
}


void QMuestraExistenciaExpendios::Muestra()
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

int QMuestraExistenciaExpendios::MuestraExistenciaExpendio(int pintFila,zExistenciaExpendio *pzExExpendio)
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
     QTExistenciaExpendios->setText(lintContador,4,(const char *)(*lzSisRegExpendio)["bodega"]);
     QTExistenciaExpendios->setText(lintContador,5,(const char *)(*lzSisRegExpendio)["existenciab"]);
}

   return lintContador; 
}
void QMuestraExistenciaExpendios::reject()
{

}
