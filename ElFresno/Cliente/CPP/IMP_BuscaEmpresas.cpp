#include <IMP_BuscaEmpresas.h>
#include <Empresas.h>

#include <qvariant.h>
#include <qlabel.h>
#include <qcombobox.h>
#include <qpushbutton.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include <qlineedit.h>

QBuscaEmpresas::QBuscaEmpresas(CSISCOMDatComunicaciones *pCSisDatCom,
				 QWidget* parent,
				 const char* name,
				 bool modal,
				  WFlags fl )
    : BuscaEmpresas( parent, name, modal, fl ),
	CSisDatCom(pCSisDatCom)
{
	IniciaVariables();
	ConectaSlots();
	exec();
}

QBuscaEmpresas::~QBuscaEmpresas()
{
}
void QBuscaEmpresas::ConectaSlots()
{

	connect(QPBAceptar,
		SIGNAL(clicked()),
		SLOT(S_Aceptar()));
	connect(QPBCancelar,
		SIGNAL(clicked()),
		SLOT(S_Cancelar()));

}
void QBuscaEmpresas::S_Cancelar()
{
	
	Opcion=SISCOMGlobales::Cancelar;
	done(1);
}
void QBuscaEmpresas::S_Aceptar()
{
	Opcion=SISCOMGlobales::Aceptar;
	done(1);
}
void QBuscaEmpresas::IniciaVariables()
{
	QLECRazonSocial=ColocaLineEditAlCombo(QCProveedores,
					      "QLECRazonSocial");
	 CQSProveedor=new CQSeleccionaProveedor(CSisDatCom,
                                           this,
                                           "CQSProveedor",
                                           QLECRazonSocial,
                                           QCProveedores);
	connect(CQSProveedor,
		SIGNAL(Signal_Proveedor(Empresa *)),
		SLOT(S_SeleccionoEmpresa(Empresa *)));
}
void QBuscaEmpresas::S_SeleccionoEmpresa(Empresa *pEmpresa)
{
	QPBAceptar->setEnabled(true);
	E_EmpresaSel=pEmpresa;
}
SISCOMGlobales::BTN_Captura QBuscaEmpresas::ObtenSeleccion()
{
	return Opcion;
}
Empresa *QBuscaEmpresas::ObtenEmpresa()
{
	return E_EmpresaSel;
}
