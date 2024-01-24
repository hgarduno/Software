#include <IMP_AnexaDireccion.h>
#include <SiscomDesarrollo3Qt++.h>
#include <QSisSepomex.h>
#include <CQSisOpTiendas43Qt.h>

#include <qpushbutton.h>
QAnexaDireccion::QAnexaDireccion(const char *pchrPtrIdPersona,
			            SiscomDatCom *pSisDatCom, 
			            char **pchrPtrArgumentos, 
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    bool pbModal,
				    WFlags pWFlags):	      
				AnexaDireccion(pQWParent,pchrPtrName,pbModal,pWFlags),
				SisDatCom(pSisDatCom),
				chrPtrArgumentos(pchrPtrArgumentos),
				chrPtrIdPersona(pchrPtrIdPersona),
				intOpcion(0)
{
IniciaVariables();
ConectaSlots();
exec();
}

QAnexaDireccion::~QAnexaDireccion()
{

}

void QAnexaDireccion::ConectaSlots()
{
    connect(QCtrSepomex,
    	    SIGNAL(SignalDireccion(SiscomRegistro3 *)),
	    SLOT(SlotDireccion(SiscomRegistro3 *)));
    connect(QPBRegistrar,
    	    SIGNAL(clicked()),
	    SLOT(SlotAnexa()));

}
void QAnexaDireccion::SlotAnexa()
{
CQSisOpTiendas43Qt lCQSisOpT43Qt(SisDatCom);
   SiscomEscribeLog3Qt("Anexando Direccion a %s",chrPtrIdPersona);
lCQSisOpT43Qt.AnexaDireccion(SisReg3Direccion);
intOpcion=1;
done(1);
}
void QAnexaDireccion::SlotDireccion(SiscomRegistro3 *pSisReg3Direccion)
{
 SiscomDesarrollo3Qt::PasaFocoControl(QPBRegistrar);
 SiscomEscribeLog3Qt("Se Capturo La Direccion"); 
 pSisReg3Direccion->SiscomActualizaCampo("IdEmpresa",chrPtrIdPersona);
 pSisReg3Direccion->SiscomActualizaCampo("IdPersona",chrPtrIdPersona);
 SisReg3Direccion=pSisReg3Direccion;
 SiscomContenidoRegistro3(pSisReg3Direccion);

}
void QAnexaDireccion::IniciaVariables()
{
 QCtrSepomex->PonServidor(SisDatCom);
 QCtrSepomex->SiscomDatosServidor("ConsultaTiendas4","SepomexEstados");
 QCtrSepomex->IniciaControl();
}
int QAnexaDireccion::Opcion()
{
return intOpcion;
}
