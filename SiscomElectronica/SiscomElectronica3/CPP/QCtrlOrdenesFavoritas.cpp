#include <QCtrlOrdenesFavoritas.h>
#include <QtSisBotonOrden.h>

#include <zSiscomElectronica.h>
#include <zOrdenFavorita.h>

#include <zSiscomDesarrollo4.h>

QCtrlOrdenesFavoritas::QCtrlOrdenesFavoritas(QWidget *pQWParent,
					     const char *pchrPtrName):
					     QGroupBox(pQWParent,pchrPtrName),
					     intModoControl(0)
{
setColumns(1);
setOrientation(Qt::Vertical);
setTitle("Ordenes Favoritas");
}

void QCtrlOrdenesFavoritas::AgregaBotonOrden(QtSisBotonOrden *pQtSisBtnOrden)
{
   QtSisBtnOrdenL.Agrega(pQtSisBtnOrden); 
   connect(pQtSisBtnOrden,SIGNAL(clicked()),SLOT(SlotOrden()));
}
void QCtrlOrdenesFavoritas::AgregaBotonOrden()
{
QtSisBotonOrden *lQtSisBtnOrden=BotonOrden();
   QtSisBtnOrdenL.Agrega(lQtSisBtnOrden); 
   connect(lQtSisBtnOrden,SIGNAL(clicked()),SLOT(SlotOrden()));
}
void QCtrlOrdenesFavoritas::SlotOrden()
{
   if(!intModoControl)
   emit SignalOrden((QtSisBotonOrden *)sender());
   else
   if(intModoControl==1)
   {
   ObtenOrdenVenta(((QtSisBotonOrden *)sender())->IdOrden());
   emit SignalOrdenVenta(zOrdVenta);
   }
   else
   if(intModoControl==2)
   emit SignalEliminaOrden((QtSisBotonOrden *)sender());
}
QtSisBotonOrden *QCtrlOrdenesFavoritas::BotonOrden()
{
QtSisBotonOrden *lQtSisBotonOrden=new QtSisBotonOrden(this);
lQtSisBotonOrden->setAutoDefault(false);
return lQtSisBotonOrden;
}
QtSisBotonOrden *QCtrlOrdenesFavoritas::BotonOrden(const char *pchrPtrTexto,
						   const char *pchrPtrIdOrden)
{
QtSisBotonOrden *lQtSisBotonOrden=BotonOrden();
lQtSisBotonOrden->Texto(pchrPtrTexto);
lQtSisBotonOrden->IdOrden(pchrPtrIdOrden);
return lQtSisBotonOrden;
}

QtSisBotonOrden *QCtrlOrdenesFavoritas::BotonOrden(zOrdenFavorita *pzOrdFavorita)
{
QtSisBotonOrden *lQtBtnOrden;
lQtBtnOrden=BotonOrden(pzOrdFavorita->Texto(),pzOrdFavorita->IdOrden());
lQtBtnOrden->OrdenFavorita(pzOrdFavorita);
return lQtBtnOrden;
}
void QCtrlOrdenesFavoritas::HabilitaBotones(bool pbOrden)
{
QtSisBotonOrden *lQtSisBtnOrden;
for(lQtSisBtnOrden=QtSisBtnOrdenL.first();
    lQtSisBtnOrden;
    lQtSisBtnOrden=QtSisBtnOrdenL.next())
 lQtSisBtnOrden->setEnabled(pbOrden);
}

void QCtrlOrdenesFavoritas::HabilitaBotones(QtSisBotonOrden *pQtSisBtnOrden,
					    bool pbOrden)
{
QtSisBotonOrden *lQtSisBtnOrden;
for(lQtSisBtnOrden=QtSisBtnOrdenL.first();
    lQtSisBtnOrden;
    lQtSisBtnOrden=QtSisBtnOrdenL.next())
if(lQtSisBtnOrden==pQtSisBtnOrden)
{
}
else
 lQtSisBtnOrden->setEnabled(pbOrden);
}
void QCtrlOrdenesFavoritas::HabilitaBotonesSiTieneOrden()
{
QtSisBotonOrden *lQtSisBtnOrden;
for(lQtSisBtnOrden=QtSisBtnOrdenL.first();
    lQtSisBtnOrden;
    lQtSisBtnOrden=QtSisBtnOrdenL.next())
     if(lQtSisBtnOrden->Orden())
       lQtSisBtnOrden->setEnabled(true);
     else
     lQtSisBtnOrden->setEnabled(false);
}

void QCtrlOrdenesFavoritas::IniciaControl()
{
   zOrdsFavoritas=new zOrdenesFavoritas;
   if(!Consultando())
   {
/*	LogSiscom("NO Hay Ordenes");
	AgregaBotonOrden();
*/

   }
   else
   {
   }
}
void QCtrlOrdenesFavoritas::Servidor(zSiscomConexion *pzSisConexion)
{
   zSisConexion=pzSisConexion;
}
int QCtrlOrdenesFavoritas::Consultando()
{
int lintRegreso;
  if((lintRegreso=Consulta()))
  AgregandoBotones();
return lintRegreso;
}
int QCtrlOrdenesFavoritas::Consulta()
{
zSiscomElectronica lzSisElectronica(zSisConexion,"ConsultaOrdenesFavoritas");
lzSisElectronica.ConsultaOrdenesFavoritas(zOrdsFavoritas);
return zOrdsFavoritas->NNodos();
}
void QCtrlOrdenesFavoritas::AgregandoBotones()
{
zOrdenFavorita *lzOrdenFavorita;
QtSisBotonOrden *lQtSisBtnOrden;
for(lzOrdenFavorita=(zOrdenFavorita *)zOrdsFavoritas->Primer();
    lzOrdenFavorita;
    lzOrdenFavorita=(zOrdenFavorita *)zOrdsFavoritas->Siguiente())
{
    lQtSisBtnOrden=BotonOrden(lzOrdenFavorita);
    QtSisBtnOrdenL.Agrega(lQtSisBtnOrden);
    connect(lQtSisBtnOrden, SIGNAL(clicked()),SLOT(SlotOrden()));
}
}
int QCtrlOrdenesFavoritas::ObtenOrdenVenta(const char *pchrPtrIdOrden)
{
zSiscomElectronica lzSisElectronica(zSisConexion,"ConsultaOrden");
zOrdVenta=lzSisElectronica.ConsultaOrden(pchrPtrIdOrden,"1",(zOrdenes **)0);
return zOrdVenta ? 1 : 0;
}
/* Mixquiahuala 
 * Domingo 12 Junio 2021 
 *  intModoControl 1 -> Consulta 
 *  intModoControl 0 -> Agregando 
 *  intModoControl 2 -> Eliminando
 */
void QCtrlOrdenesFavoritas::ModoControl(int pintModoControl)
{
   intModoControl=pintModoControl;
}
int QCtrlOrdenesFavoritas::ModoControl()
{
  return intModoControl;
}
void QCtrlOrdenesFavoritas::ReConsulta()
{
  Consultando();
}
