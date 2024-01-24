#include <IMP_MaterialAreaDiseno.h>
#include <zMaterialAAreaDiseno.h> 

#include <zSiscomQt3.h>

#include <qpushbutton.h>
#include <qtextedit.h>
QMaterialAreaDiseno::QMaterialAreaDiseno(
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    bool pbModal,
				    WFlags pWFlags):	      
				MaterialAreaDiseno(pQWParent,pchrPtrName,pbModal,pWFlags)
{
IniciaVariables();
ConectaSlots();
exec();
}

QMaterialAreaDiseno::~QMaterialAreaDiseno()
{

}

void QMaterialAreaDiseno::ConectaSlots()
{
connect(QPBAceptar,SIGNAL(clicked()),SLOT(SlotAceptar()));
connect(QPBCancelar,SIGNAL(clicked()),SLOT(SlotCancelar()));


}
void QMaterialAreaDiseno::SlotAceptar()
{
  intAceptar=1;
  done(1);
}
void QMaterialAreaDiseno::SlotCancelar()
{
  intAceptar=0;
  done(1);

}
void QMaterialAreaDiseno::IniciaVariables()
{

}
int QMaterialAreaDiseno::Aceptar()
{
	return intAceptar;
}
zMaterialAAreaDiseno *QMaterialAreaDiseno::MaterialAAreaDiseno()
{
return new zMaterialAAreaDiseno(zSiscomQt3::Texto(QTEExplicacion));
}
