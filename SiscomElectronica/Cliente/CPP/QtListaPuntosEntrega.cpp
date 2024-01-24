#include <QtListaPuntosEntrega.h>

#include <zSiscomQt3.h>

#include <zPuntosEntrega.h>
#include <zPuntoEntrega.h>
#include <zDireccion.h>

#include <qtable.h>
#include <qtextedit.h>
#include <qpushbutton.h>

QtListaPuntosEntrega::QtListaPuntosEntrega(QWidget *pQWParent,
					   const char *pchrPtrName,
					   bool pbModal,
					   WFlags pWFlags):
			ListaPuntosEntrega(pQWParent,pchrPtrName,pbModal,pWFlags),
			intAceptar(0)
{
IniciaVariables();
}
void QtListaPuntosEntrega::ConectaSlots()
{
connect(QTPuntosEntrega,
	SIGNAL(clicked(int,int,int,const QPoint &)),
	SLOT(SlotPuntoEntrega(int,int,int,const QPoint &)));
connect(QPBAceptar, SIGNAL(clicked()),SLOT(SlotAceptar()));
}
void QtListaPuntosEntrega::SlotCancelar()
{
 
}
void QtListaPuntosEntrega::SlotAceptar()
{
    intAceptar=1;
    done(intAceptar);  
}
void QtListaPuntosEntrega::SlotPuntoEntrega(int pintNPEntrega,int,int,const QPoint &)
{
  QTPuntosEntrega->selectRow(pintNPEntrega);
  Referencias(pintNPEntrega);
  zPEntrega=(zPuntoEntrega *)(*zPsEntrega)[pintNPEntrega];
  zSiscomQt3::Foco(QPBAceptar);
}
void QtListaPuntosEntrega::IniciaVariables()
{
   ConectaSlots();
}
void QtListaPuntosEntrega::Referencias(int pintPEntrega)
{
QTEReferencias->setText(zPsEntrega->Direccion(pintPEntrega)->Referencias());
}
void QtListaPuntosEntrega::Muestra()
{
zPuntoEntrega *lzPEntrega;
int lintContadorI=0;
char lchrArrDescripcion[256];
QTPuntosEntrega->setNumRows(zPsEntrega->NNodos());
for(lzPEntrega=(zPuntoEntrega *)zPsEntrega->Primer();
    lzPEntrega;
    lzPEntrega=(zPuntoEntrega *)zPsEntrega->Siguiente())
{
Descripcion(lzPEntrega,lchrArrDescripcion);
QTPuntosEntrega->setText(lintContadorI,0,lzPEntrega->PuntoEntrega());
QTPuntosEntrega->setText(lintContadorI,1,lchrArrDescripcion);
lintContadorI++;
}
zSiscomQt3::AjustaColumnasTabla(QTPuntosEntrega);
}
void QtListaPuntosEntrega::PuntosEntrega(zPuntosEntrega *pzPsEntrega)
{
	zPsEntrega=pzPsEntrega;
}
void QtListaPuntosEntrega::Descripcion(zPuntoEntrega *pzPEntrega,char *pchrPtrDescripcion)
{
sprintf(pchrPtrDescripcion,
	"%s %s",
	pzPEntrega->Direccion()->Calle(),
	pzPEntrega->Direccion()->Numero());
}
void QtListaPuntosEntrega::reject()
{

}
zPuntoEntrega *QtListaPuntosEntrega::PuntoEntrega()
{
 	return zPEntrega;
}
int QtListaPuntosEntrega::Aceptar()
{
	return intAceptar;
}
