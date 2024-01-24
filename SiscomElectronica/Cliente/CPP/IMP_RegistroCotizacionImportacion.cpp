#include <IMP_RegistroCotizacionImportacion.h>


#include <qtextedit.h>
#include <qpushbutton.h>
#include <qtable.h>

#include <zSiscomElectronica.h>
#include <zSiscomDesarrollo4.h>
#include <zSiscomRegistro.h>
#include <zSiscomQt3.h>
#include <zSiscomConexion.h>

#include <zCotizacionImportacion.h>

QRegistroCotizacionImportacion::QRegistroCotizacionImportacion(
				   zCotizacionImportacion *pzCotImportacion,
			            char **pchrPtrArgumentos, 
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    bool pbModal,
				    WFlags pWFlags):	      
				RegistroCotizacionImportacion(pQWParent,pchrPtrName,pbModal,pWFlags),
				chrPtrArgumentos(pchrPtrArgumentos),
				zSisConexion((zSiscomConexion *)gzSiscomConexion),
				zCotImportacion(pzCotImportacion),
				intCotizando(0)
{
IniciaVariables();
ConectaSlots();
exec();
}

QRegistroCotizacionImportacion::~QRegistroCotizacionImportacion()
{

}

void QRegistroCotizacionImportacion::ConectaSlots()
{
connect(QTECotizacion,SIGNAL(textChanged()),SLOT(SlotCapturandoCotizacion()));
connect(QPBRegistrar,SIGNAL(clicked()),SLOT(SlotRegistrar()));
connect(QTCotizaciones,SIGNAL(doubleClicked(int,int,int,const QPoint &)),SLOT(SlotSeleccionaCotizacion(int,int,int,const QPoint &)));
}
void QRegistroCotizacionImportacion::SlotSeleccionaCotizacion(int pintCotizacion,
							      int,
							      int,
							      const QPoint &)
{
    zCotImportacion=(zCotizacionImportacion *)zCotsImportacion[pintCotizacion];
    CompletaCotizacion(zCotImportacion);
    done(1);
}
void QRegistroCotizacionImportacion::SlotRegistrar()
{
   zCotImportacion->Cotizacion(zSiscomQt3::Texto(QTECotizacion));
   Registrando();
}
void QRegistroCotizacionImportacion::SlotCapturandoCotizacion()
{
   QPBRegistrar->setEnabled(zSiscomQt3::TextoValido(QTECotizacion));
}
void QRegistroCotizacionImportacion::IniciaVariables()
{
 if(zCotImportacion)
 IniciaVariablesRegistro();
 else
 IniciaVariablesConsulta();

 ConsultandoCotizacionesImportacion();
}

void QRegistroCotizacionImportacion::ConsultandoCotizacionesImportacion()
{
 ConsultaCotizacionesImportacion();
 MuestraCotizacionesImportacion();
}

void QRegistroCotizacionImportacion::ConsultaCotizacionesImportacion()
{
zSiscomElectronica lzSisElec(zSisConexion,"ConsultandoCotizacionImportacion");
		lzSisElec.CotizacionesImportacion(&zCotsImportacion);
}

void QRegistroCotizacionImportacion::MuestraCotizacionesImportacion()
{
zCotizacionImportacion *lzCotImpor;
int lintFila;
QTCotizaciones->setNumRows(zCotsImportacion.NNodos());

for(lzCotImpor=(zCotizacionImportacion *)zCotsImportacion.Primer(),
    lintFila=0;
    lzCotImpor;
    lzCotImpor=(zCotizacionImportacion *)zCotsImportacion.Siguiente(),
    lintFila++)
     MuestraCotizacion(lintFila,lzCotImpor); 

zSiscomQt3::AjustaColumnasTabla(QTCotizaciones);
zSiscomQt3::AjustaFilasTabla(QTCotizaciones);
}
void QRegistroCotizacionImportacion::Registrando()
{
   if(Registra())
   SeRegistroLaCotizacion();
}
int QRegistroCotizacionImportacion::Registra()
{
zSiscomElectronica lzSisElec(zSisConexion,"RegistrandoCotizacionImportacion"); 
return lzSisElec.RegistrandoCotizacionImportacion(zCotImportacion);
}
void QRegistroCotizacionImportacion::SeRegistroLaCotizacion()
{
      intCotizando=1;
      done(1); 
}
int QRegistroCotizacionImportacion::Cotizando()
{
     return intCotizando;
}
void QRegistroCotizacionImportacion::MuestraCotizacion(int pintFila,
						       zCotizacionImportacion *pzCotImpor)
{
   QTCotizaciones->setText(pintFila,0,pzCotImpor->Cotizacion());	
   QTCotizaciones->setText(pintFila,1,pzCotImpor->RazonSocial());
   QTCotizaciones->setText(pintFila,2,pzCotImpor->PesoTotal());
   QTCotizaciones->setText(pintFila,3,pzCotImpor->ImporteTotal());
}
zCotizacionImportacion *QRegistroCotizacionImportacion::Cotizacion()
{
    return zCotImportacion;
}
void QRegistroCotizacionImportacion::IniciaVariablesConsulta()
{
   QTECotizacion->setEnabled(false);
}
void QRegistroCotizacionImportacion::IniciaVariablesRegistro()
{
 setCaption(zCotImportacion->RazonSocial());
}
void QRegistroCotizacionImportacion::CompletaCotizacion(zCotizacionImportacion *pzCotizacionImp)
{
zSiscomElectronica lzSiscomElec(zSisConexion,"SeleccionoCotizaImportacion");
lzSiscomElec.SeleccionoCotizacionImportacion(pzCotizacionImp);
}
