#include <IMP_RegistrarCajaMaterial.h>

#include <qpushbutton.h>
#include <qlineedit.h>
#include <qtextedit.h>

#include <zSiscomConexion.h>
#include <zSiscomRegistros.h>
#include <zSiscomRegistro.h>
#include <zSiscomDesarrollo4.h>
#include <zSiscomQt3.h>
#include <zSiscomCampo.h>


#include <zSiscomElectronica.h>

#include <zCajaMaterial.h>

QRegistrarCajaMaterial::QRegistrarCajaMaterial(QWidget *pQWParent,       
				    const char *pchrPtrName,
				    bool pbModal,
				    WFlags pWFlags):	      
				RegistrarCajaMaterial(pQWParent,
						      pchrPtrName,
						      pbModal,
						      pWFlags),
				 zSisConexion((zSiscomConexion *)gzSiscomConexion),
				 intAceptar(0)
{
IniciaVariables();
ConectaSlots();
exec();
}

QRegistrarCajaMaterial::~QRegistrarCajaMaterial()
{

}

void QRegistrarCajaMaterial::ConectaSlots()
{
connect(QPBRegistrar,SIGNAL(clicked()),SLOT(SlotRegistrar()));
connect(QLECaja,SIGNAL(textChanged(const QString &)),SLOT(SlotCapturandoCaja(const QString &)));
connect(QTEDescripcion,SIGNAL(textChanged()),SLOT(SlotCapturandoDescripcion()));
connect(QPBAceptar,SIGNAL(clicked()),SLOT(SlotAceptar()));
}
void QRegistrarCajaMaterial::SlotAceptar()
{
  if(intAceptar==1)
  intAceptar=2;
   done(intAceptar);
}
void QRegistrarCajaMaterial::SlotCapturandoCaja(const QString &)
{
   HabilitaRegistrar();
}
void QRegistrarCajaMaterial::SlotCapturandoDescripcion()
{
   HabilitaRegistrar();
}
void QRegistrarCajaMaterial::SlotRegistrar()
{
  CajaMaterial();
  RegistraCajaMaterial();

  QPBRegistrar->setEnabled(false);
  QPBAceptar->setEnabled(true);
  intAceptar=1;

}
void QRegistrarCajaMaterial::IniciaVariables()
{
zCaMaterial=new zCajaMaterial;
}
void QRegistrarCajaMaterial::RegistraCajaMaterial()
{
zSiscomElectronica lzSisElectronica(zSisConexion,"RegistraCajaMaterial");
lzSisElectronica.RegistraCajaMaterial(zCaMaterial);

}
void QRegistrarCajaMaterial::CajaMaterial()
{
  zCaMaterial->Caja(zSiscomQt3::Texto(QLECaja));
  zCaMaterial->Descripcion(zSiscomQt3::Texto(QTEDescripcion));
}
void QRegistrarCajaMaterial::HabilitaRegistrar()
{
int lintEdoHabilita=zSiscomQt3::TextoValido(QLECaja) &&
                    zSiscomQt3::TextoValido(QTEDescripcion);
QPBRegistrar->setEnabled(lintEdoHabilita);
}
int QRegistrarCajaMaterial::Aceptar()
{
  return intAceptar;
}
