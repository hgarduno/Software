#include <IMP_CapturaPesoProducto.h>



#include <zSiscomElectronica.h> 

#include <zSiscomElectronica.h>
#include <zSiscomRegistros.h>
#include <zSiscomRegistro.h>
#include <zSiscomQt3.h>

#include <zSiscomDesarrollo4.h>
#include <zSiscomRegistro.h>
#include <zSiscomQt3.h>


#include <qlineedit.h>
#include <qpushbutton.h>

#include <string.h>
QCapturaPesoProducto::QCapturaPesoProducto(zSiscomRegistro *pzSisRegProducto,
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    bool pbModal,
				    WFlags pWFlags):	      
				CapturaPesoProducto(pQWParent,pchrPtrName,pWFlags),
				zSisConexion((zSiscomConexion *)gzSiscomConexion),
				zSisRegProducto(pzSisRegProducto),
				intRegreso(0)
{
IniciaVariables();
ConectaSlots();
exec();
}

QCapturaPesoProducto::~QCapturaPesoProducto()
{

}

void QCapturaPesoProducto::ConectaSlots()
{
    connect(QLEPeso,SIGNAL(returnPressed()),SLOT(SlotFocoARegistrar()));
    connect(QPBRegistrar,SIGNAL(clicked()),SLOT(SlotRegistrar()));
    connect(QPBTerminar,SIGNAL(clicked()),SLOT(SlotTerminar()));

}
void QCapturaPesoProducto::SlotTerminar()
{
     done(1);
}
void QCapturaPesoProducto::SlotRegistrar()
{
   RegistrandoPeso();
   done(1);
}
void QCapturaPesoProducto::SlotFocoARegistrar()
{
    zSiscomQt3::Foco(QPBRegistrar);
}
void QCapturaPesoProducto::IniciaVariables()
{
  QLEProducto->setText(((const char *)(*zSisRegProducto)["CveProducto"]));
  zSiscomQt3::Foco(QLEPeso);
}
void QCapturaPesoProducto::RegistrandoPeso()
{
    if(RegistraPeso())
    {
	intRegreso=1;
    }
}
int QCapturaPesoProducto::RegistraPeso()
{
zSiscomElectronica lzSisElectronica(zSisConexion,"RegistraPesoProducto");
return lzSisElectronica.RegistraPesoProducto(zSisRegProducto,zSiscomQt3::Texto(QLEPeso));
}
int QCapturaPesoProducto::Regreso(char *pchrPtrPeso)
{
   strcpy(pchrPtrPeso,(const char *)QLEPeso->text());
   return intRegreso;
}
