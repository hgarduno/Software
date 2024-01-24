#include <QtCapturaDescripcionCotizacion.h>


#include <zSiscomQt3.h>
#include <zSiscomDesarrollo4.h>
#include <zCotizacionMediaCenter.h>
#include <zOrdenVenta.h>
#include <zSiscomElectronica.h>
#include <zSiscomRegistros.h>
#include <zEscuelas.h>
#include <zEscuela.h>
#include <zClienteSiscom.h>

#include <qtextedit.h>
#include <qlineedit.h>
#include <qpushbutton.h>
#include <qradiobutton.h>
#include <qbuttongroup.h>
#include <qlayout.h>



QtCapturaDescripcionCotizacion::QtCapturaDescripcionCotizacion(zOrdenVenta *pzOrdenVenta,
							       zSiscomConexion *pzSisConexion,
							       	QWidget *pQWParent,
							       const char *pchrPtrName,
							       bool pbModal,
							       WFlags pWFlags):
					CapturaDescripcionCotizacion(pQWParent,
								     pchrPtrName,
								     pbModal,
								     pWFlags),
								  zOrdVenta(pzOrdenVenta),
								  zSisConexion(pzSisConexion),
								  intCotizando(0),
								  intSoloDescripcion(0)
{
 ConectaSlots();
}
zOrdenVenta *QtCapturaDescripcionCotizacion::Orden()
{
   return zOrdVenta;
}
void QtCapturaDescripcionCotizacion::IniciaVariables()
{
 zSiscomQt3::Foco(QLETelefono);
 MuestraEscuelasEntrega();
 zCotMedCenter=new zCotizacionMediaCenter;
 Orden()->Cotizacion(zCotMedCenter);
 Cotizacion()->Modo(chrPtrModo);
}
void QtCapturaDescripcionCotizacion::IniciandoSoloDescripcion()
{
LogSiscom("Iniciando...... %s",Orden()->Cotizacion()->Descripcion());
   zCotMedCenter=new zCotizacionMediaCenter(Orden()->Cotizacion());
   Orden()->Cotizacion(zCotMedCenter);
   Cotizacion()->Modo(chrPtrModo);
   zSiscomQt3::Foco(QTEDescripcion);
   Cotizacion()->Escuela(Orden()->Cliente()->Escuela());
   intSoloDescripcion=1;
}
void QtCapturaDescripcionCotizacion::ComoInicioCotizacion()
{
   if(SoloDescripcion())
   IniciandoSoloDescripcion();
   else
   {
   zCotMedCenter=(zCotizacionMediaCenter *)Orden()->Cotizacion();
   Muestra();
   Cotizacion()->DescripcionMediaCenter();
   }
   Descripcion();
   HabilitandoAceptar();
}
void QtCapturaDescripcionCotizacion::Cotizando()
{ 
   MuestraEscuelasEntrega();
   ComoInicioCotizacion();
}
void QtCapturaDescripcionCotizacion::ConectaSlots()
{
connect(QLETelefono,SIGNAL(returnPressed()),SLOT(SlotFocoAPagaCon())); 
connect(QLEPagaCon,SIGNAL(returnPressed()),SLOT(SlotFocoAHora()));
connect(QLEHora,SIGNAL(returnPressed()),SLOT(SlotFocoAEscuela()));
connect(QPBAceptar,SIGNAL(clicked()),SLOT(SlotAceptar()));
connect(QBGEscuelas,SIGNAL(clicked(int)),SLOT(SlotEscuela(int)));
connect(QTEDescripcion,SIGNAL(doubleClicked(int,int)),SLOT(SlotSoloDescripcion(int,int)));
connect(QTEDescripcion,SIGNAL(textChanged()),SLOT(SlotCapturandoDescripcion()));
connect(QLENombre,SIGNAL(returnPressed()),SLOT(SlotCapturaNombre()));
}
void QtCapturaDescripcionCotizacion::SlotCapturaNombre()
{
  Nombre();
  zSiscomQt3::Foco(QLETelefono);
}
void QtCapturaDescripcionCotizacion::SlotCapturandoDescripcion()
{
   
}
void QtCapturaDescripcionCotizacion::SlotSoloDescripcion(int,int)
{
    HabilitaDesHabilita(false); 
    QTEDescripcion->setReadOnly(false);
    zSiscomQt3::Foco(QTEDescripcion);
    intSoloDescripcion=1;
}
void QtCapturaDescripcionCotizacion::SlotEscuela(int pintEscuela)
{
zEscuela *lzEscuela=(zEscuela *)zEscuelasS[pintEscuela];
Orden()->Cliente()->EscuelaCliente(lzEscuela);
Cotizacion()->Escuela(lzEscuela->Nombre());
Cotizacion()->DescripcionMediaCenter();
Descripcion();
HabilitandoAceptar();
}
void QtCapturaDescripcionCotizacion::SlotAceptar()
{
   if(!SoloDescripcion())
   Orden()->Cotizacion(Cotizacion());
   else
   Orden()->Cotizacion()->Descripcion((const char *)QTEDescripcion->text());
   done(1);
}
void QtCapturaDescripcionCotizacion::SlotFocoAEscuela()
{
 QBGEscuelas->setFocus();
 Hora();
}
void QtCapturaDescripcionCotizacion::SlotFocoAAceptar()
{
 Hora();
}
void QtCapturaDescripcionCotizacion::SlotFocoAHora()
{
PagaCon();
zSiscomQt3::Foco(QLEHora);
}
void QtCapturaDescripcionCotizacion::SlotFocoAPagaCon()
{
 Telefono();
 zSiscomQt3::Foco(QLEPagaCon);
}
void QtCapturaDescripcionCotizacion::Descripcion()
{
  LogSiscom("%s",Cotizacion()->Descripcion());
  QTEDescripcion->setText(Cotizacion()->Descripcion());
}
void QtCapturaDescripcionCotizacion::Telefono()
{
   Cotizacion()->Telefono((const char *)QLETelefono->text());
   Cotizacion()->DescripcionMediaCenter();
   Descripcion();
}
void QtCapturaDescripcionCotizacion::Hora()
{
  Cotizacion()->Hora((const char *)QLEHora->text());
  Cotizacion()->DescripcionMediaCenter();
  Descripcion();
}
void QtCapturaDescripcionCotizacion::PagaCon()
{
  Cotizacion()->PagaCon((const char *)QLEPagaCon->text());
  Cotizacion()->DescripcionMediaCenter();
  Descripcion();
}
void QtCapturaDescripcionCotizacion::Nombre()
{
  Cotizacion()->Nombre(zSiscomQt3::Texto(QLENombre));
  Cotizacion()->DescripcionMediaCenter();
  Descripcion();
}
void QtCapturaDescripcionCotizacion::MuestraEscuelasEntrega()
{
   EscuelasEntrega();
   MuestraEscuelas();
}
void QtCapturaDescripcionCotizacion::EscuelasEntrega()
{
zSiscomElectronica lzSisEEEscuelas(Conexion(),"EntregaEscuela"); 
lzSisEEEscuelas.EntregaEscuela(&zEscuelasS);
}

void QtCapturaDescripcionCotizacion::MuestraEscuelas()
{
zEscuela *lzEscuela;
int lintContador;
for(lzEscuela=(zEscuela *)zEscuelasS.Primer(),lintContador=0 ;
     lzEscuela;
     lzEscuela=(zEscuela *)zEscuelasS.Siguiente(),lintContador++)
  QBGEscuelasLayout->addWidget(Escuela(lzEscuela),lintContador,0);
}
QRadioButton *QtCapturaDescripcionCotizacion::Escuela(zEscuela *pzEscuela)
{
QRadioButton *lQRBEscuela;
  lQRBEscuela=new QRadioButton(QBGEscuelas,pzEscuela->Nombre());
  lQRBEscuela->setText(pzEscuela->Nombre());
  return lQRBEscuela;
}
zEscuela *QtCapturaDescripcionCotizacion::Escuela()
{
    return (zEscuela *)Orden()->Cliente()->EscuelaReg();
}

void QtCapturaDescripcionCotizacion::HabilitandoAceptar()
{
  QPBAceptar->setEnabled(Cotizacion()->Escuela() ? 1 :0); 
  zSiscomQt3::Foco(QPBAceptar);
}
void QtCapturaDescripcionCotizacion::HabilitaDesHabilitaEscuelas(bool pbEstado)
{
  if(pbEstado==false)
  {
	if(Orden()->Cliente()->Escuela())
   	QBGEscuelas->setEnabled(pbEstado);
	else
   	QBGEscuelas->setEnabled(true);
  }
  else
   	QBGEscuelas->setEnabled(true);

}
void QtCapturaDescripcionCotizacion::HabilitaDesHabilita(bool pbEstado)
{
  
   HabilitaDesHabilitaEscuelas(pbEstado);
   QLEPagaCon->setEnabled(pbEstado);
   QLEHora->setEnabled(pbEstado);
   QLENombre->setEnabled(pbEstado);
   QLETelefono->setEnabled(pbEstado);
}
void QtCapturaDescripcionCotizacion::TraeEscuela(zClienteSiscom *pzCliSiscom)
{
  if(pzCliSiscom->Escuela()) 
  {
	QBGEscuelas->setEnabled(false);
	QPBAceptar->setEnabled(true);
	LlevandoA(pzCliSiscom->Escuela());
	zCotMedCenter->LlevarA(pzCliSiscom->Escuela());
  }
  else
    QBGEscuelas->setEnabled(false);

}
zSiscomConexion *QtCapturaDescripcionCotizacion::Conexion()
{
 return zSisConexion;
}
zCotizacionMediaCenter *QtCapturaDescripcionCotizacion::Cotizacion()
{
    return zCotMedCenter;
}
void QtCapturaDescripcionCotizacion::SoloDescripcion(int pintSoloDescripcion)
{
  intSoloDescripcion=pintSoloDescripcion;
}
int QtCapturaDescripcionCotizacion::SoloDescripcion()
{
   return intSoloDescripcion;
}
void QtCapturaDescripcionCotizacion::Modo(const char *pchrPtrModo)
{
//     Cotizacion()->Modo(pchrPtrModo);
  chrPtrModo=pchrPtrModo;
}
void QtCapturaDescripcionCotizacion::TeclasEspeciales(QKeyEvent *pQKETeclas)
{
     if(pQKETeclas->state()==Qt::ControlButton)
     {
	if(pQKETeclas->key()==Qt::Key_F12)
	zSiscomQt3::Foco(QLENombre); 
	if(pQKETeclas->key()==Qt::Key_F11)
	QBGEscuelas->setFocus();
     }

}
void QtCapturaDescripcionCotizacion::keyPressEvent(QKeyEvent *pQKETeclas)
{
      TeclasEspeciales(pQKETeclas); 
}

void QtCapturaDescripcionCotizacion::Muestra()
{
   if(zCotMedCenter->Nombre())
   QLENombre->setText(zCotMedCenter->Nombre());
   if(zCotMedCenter->PagaCon())
   QLEPagaCon->setText(zCotMedCenter->PagaCon());
   if(zCotMedCenter->Hora())
   QLEHora->setText(zCotMedCenter->Hora());
   if(zCotMedCenter->Telefono())
    QLETelefono->setText(zCotMedCenter->Telefono());
}

void QtCapturaDescripcionCotizacion::LlevandoA(const char *)
{


}
