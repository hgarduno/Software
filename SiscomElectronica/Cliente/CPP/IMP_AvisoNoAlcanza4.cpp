#include <IMP_AvisoNoAlcanza4.h>
#include <IMP_CapturaDato.h>

#include <zProductoCotizar.h>


#include <zSiscomDesarrollo4.h>
#include <zSiscomRegistro.h>
#include <zSiscomQt3.h>

#include <qlineedit.h>
#include <qtextedit.h>
#include <qtable.h>
#include <qpushbutton.h>
#include <qlcdnumber.h>

QAvisoNoAlcanza4::QAvisoNoAlcanza4(zProductoCotizar *pzProdCotizar,
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    WFlags pWFlags):	      
				AvisoNoAlcanza4(pQWParent,pchrPtrName,pWFlags),
				zProdCotizar(pzProdCotizar),
				intSeElimino(0)
{
IniciaVariables();
ConectaSlots();
exec();
}

QAvisoNoAlcanza4::~QAvisoNoAlcanza4()
{

}

void QAvisoNoAlcanza4::ConectaSlots()
{
connect(QPBCCantidad,SIGNAL(clicked()),SLOT(SlotCambiaCantidad()));
connect(QPBEliminar,SIGNAL(clicked()),SLOT(SlotEliminar()));
connect(QPBVende,SIGNAL(clicked()),SLOT(SlotVende()));
}
void QAvisoNoAlcanza4::SlotVende()
{
  VendeLoQueHay();
}
void QAvisoNoAlcanza4::SlotEliminar()
{ 
    intSeElimino=1;
    done(1);
}
void QAvisoNoAlcanza4::SlotCambiaCantidad()
{
  CambiandoCantidad();
  done(1);
}
void QAvisoNoAlcanza4::IniciaVariables()
{
Muestra(); 
}
void QAvisoNoAlcanza4::Muestra()
{
   QLEProducto->setText(zProdCotizar->Clave());
   QLECantidad->setText(zProdCotizar->Cantidad());
   QTEDescripcion->setText(zProdCotizar->Descripcion());
   QLCNExistencia->display(zProdCotizar->Existencia());
}
void QAvisoNoAlcanza4::reject()
{
}
void QAvisoNoAlcanza4::CambiaCantidad(char *pchrPtrCantidad)
{
QCapturaDato lQCDato("Cambia Cantidad",
		     "Cantidad",
		     "1");
lQCDato.ObtenDato(pchrPtrCantidad);
}
void QAvisoNoAlcanza4::CambiandoCantidad()
{
char lchrArrCantidad[28];
CambiaCantidad(lchrArrCantidad);
zProdCotizar->Cantidad(lchrArrCantidad);
}
int QAvisoNoAlcanza4::SeElimino()
{
   return intSeElimino;
}
void QAvisoNoAlcanza4::VendeLoQueHay()
{
  zProdCotizar->Cantidad(zProdCotizar->Existencia());
  done(1);
}
