#include <IMP_DonacionMaterial.h>

#include <zSiscomQt3.h>

#include <zDonacionMaterial.h> 

#include <qpushbutton.h>
QDonacionMaterial::QDonacionMaterial(QWidget *pQWParent,       
				    const char *pchrPtrName,
				    bool pbModal,
				    WFlags pWFlags):	      
				DonacionMaterial(pQWParent,pchrPtrName,pbModal,pWFlags)
{
IniciaVariables();
ConectaSlots();
exec();
}

QDonacionMaterial::~QDonacionMaterial()
{

}

void QDonacionMaterial::ConectaSlots()
{
connect(QPBAceptar,SIGNAL(clicked()),SLOT(SlotAceptar()));
connect(QPBCancelar,SIGNAL(clicked()),SLOT(SlotCancelar()));


}
void QDonacionMaterial::SlotAceptar()
{
	intAceptar=1;
	done(1);
}
void QDonacionMaterial::SlotCancelar()
{
	intAceptar=0;
	done(1);
}

void QDonacionMaterial::IniciaVariables()
{

}
zDonacionMaterial *QDonacionMaterial::MaterialDonado()
{
  return new zDonacionMaterial(zSiscomQt3::Texto(QTEExplicacion));
}
int QDonacionMaterial::Aceptar()
{
	return intAceptar;
}
