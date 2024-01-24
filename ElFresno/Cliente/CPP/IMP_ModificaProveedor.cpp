#include <IMP_ModificaProveedor.h>
#include <IMP_CapturaContacto.h>
#include <IMP_CapturaTelefono.h>

#include <CQSiscomCom.h>
#include <Empresas.h>
#include <DireccionesProt2.h>
#include <Contactos.h>
#include <MediosComunicacion.h>

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qtable.h>
#include <qlineedit.h>
#include <qtabwidget.h>
#include <qwidget.h>
#include <qcombobox.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include <qmessagebox.h>

QModificaProveedor::QModificaProveedor(CSISCOMDatComunicaciones *pCSisDatCom,
				       Empresa *pEmpresa,
				       QWidget* parent,
				       const char* name,
				       bool modal,
				       WFlags fl )
    : ModificaProveedor( parent, name, modal, fl ),
    CSisDatCom(pCSisDatCom),
    E_Empresa(pEmpresa)
{
	SDatCom=new SiscomDatCom(atoi(getenv("PtoComSvr2")),
				 CSisDatCom->ObtenDirIpSvr());
	ConectaSlots();
	MuestraEmpresa(E_Empresa);
	exec();

}

QModificaProveedor::~QModificaProveedor()
{
}
MedioComunicacion *QModificaProveedor::CapturaTelefono()
{
QCapturaTelefono lQCTelefono;
		if(lQCTelefono.ObtenOpcion()==QCapturaTelefono::Aceptar)
		return new MedioComunicacion(E_Empresa->ObtenIdEmpresa(),
					     lQCTelefono.ObtenDescripcion(),
					     "Telefono",
					     lQCTelefono.ObtenTelefono());
		else
		return 0;

}
Contacto *QModificaProveedor::CapturaContacto()
{
QCapturaContacto lQCContacto;

	if(lQCContacto.ObtenOpcion()==SISCOMGlobales::Aceptar)
	    return new Contacto(lQCContacto.ObtenNombre(),
	    			lQCContacto.ObtenAPaterno(),
				lQCContacto.ObtenAMaterno(),
				"",
				"",
				lQCContacto.ObtenDescripcion(),
				E_Empresa->ObtenIdEmpresa());
	else
	return 0;
}
void QModificaProveedor::ConectaSlots()
{
	connect(QPBMGenerales,
		SIGNAL(clicked()),
		SLOT(S_ModificaGenerales()));
	connect(QPBADireccion,
		SIGNAL(clicked()),
		SLOT(S_AnexaDireccion()));
	connect(QPBAContacto,
		SIGNAL(clicked()),
		SLOT(S_AnexaContacto()));
	connect(QPBATelefono,
		SIGNAL(clicked()),
		SLOT(S_AnexaTelefono()));
	connect(QPBEDireccion,
		SIGNAL(clicked()),
		SLOT(S_EliminaDireccion()));
	connect(QPBEContacto,
		SIGNAL(clicked()),
		SLOT(S_EliminaContacto()));
	connect(QPBETelefono,
		SIGNAL(clicked()),
		SLOT(S_EliminaTelefono()));
}
void QModificaProveedor::S_EliminaContacto()
{

}
void QModificaProveedor::S_EliminaTelefono()
{

}
void QModificaProveedor::S_EliminaDireccion()
{
CQ_Direcciones lCQDirecciones=E_Empresa->ObtenDirecciones();
int lintContador;
CQ_Direccion *lCQDireccion;
DireccionesProt2 lDireccionesProt2;
		for(lintContador=0;
		    lintContador<QTDirecciones->numRows();
		    lintContador++)
		{
		   if(QTDirecciones->isRowSelected(lintContador))
		   {
		      lCQDireccion=lCQDirecciones.at(lintContador);
		      lDireccionesProt2 <<
		      	new DireccionProt2(
				E_Empresa->ObtenIdEmpresa(),
				lCQDireccion->ObtenCalle(),
				lCQDireccion->ObtenNumero(),
				"",
				"",
				"",
				"");
		   }

		}
if(lDireccionesProt2.count())
{
SiscomGeneralOperacionesSrv lSGenOperaciones(SDatCom,
				      (QPtrList<SiscomInformacion> *)&lDireccionesProt2);
			lSGenOperaciones.SiscomEjecutaEnvio("EliminaDirecciones");
}
else
QMessageBox::information(this,"Sistema El Fresno","No Se Selecciono Una Direccion");

}
void QModificaProveedor::S_AnexaTelefono()
{
MedioComunicacion *lMComunicacion;
		if((lMComunicacion=CapturaTelefono()))
		{
		 QPtrList<MedioComunicacion> lQPtrLMComunicacion;
		 lQPtrLMComunicacion.append(lMComunicacion);
		 SiscomGeneralOperacionesSrv lSGenOp(SDatCom,
		 				     (QPtrList<SiscomInformacion> *)&lQPtrLMComunicacion);
		 lSGenOp.SiscomEjecutaEnvio("AnexaTelefono");

		}


}
void QModificaProveedor::S_AnexaContacto()
{
Contacto *lContacto;
	if((lContacto=CapturaContacto()))
	{
	  QPtrList<Contacto> lQPtrLContactos;
	  lQPtrLContactos.append(lContacto);
	  SiscomGeneralOperacionesSrv lSGenOp(SDatCom,
	  				      (QPtrList<SiscomInformacion> *)&lQPtrLContactos);
	  lSGenOp.SiscomEjecutaEnvio("AnexaContacto");

	}



}
void QModificaProveedor::S_AnexaDireccion()
{
QPtrList<DireccionProt2> lQPtrListDir;

	lQPtrListDir.append(new DireccionProt2(E_Empresa->ObtenIdEmpresa(),
					       (const char *)QLECalle->text(),
					       (const char *)QLENumero->text(),
					       (const char *)QLECP->text(),
					       (const char *)QLEColonia->text(),
					       (const char *)QLEMunicipio->text(),
					       (const char *)QCBEstados->currentText() ));

SiscomGeneralOperacionesSrv lSGenOperaciones(SDatCom,
					    (QPtrList<SiscomInformacion> *)&lQPtrListDir);


		lSGenOperaciones.SiscomEjecutaEnvio("AnexaDireccion");			       

}
void QModificaProveedor::S_ModificaGenerales()
{
QPtrList<EmpresaProt2 > lQPtrListEmp;
	lQPtrListEmp.append(new EmpresaProt2((const char *)QLERazonSocial->text(),
			    (const char *)QLERFC->text(),
			    E_Empresa->ObtenIdEmpresa(),
			    ""));
SiscomGeneralOperacionesSrv lSGenOperaciones(
				SDatCom,
				(QPtrList<SiscomInformacion> *)&lQPtrListEmp);
	
	
	lSGenOperaciones.SiscomEjecutaEnvio("ActualizaProveedor");

					 
	


}


void QModificaProveedor::MuestraEmpresa(Empresa *pEEmpresa)
{

	QLERazonSocial->setText(pEEmpresa->ObtenRazonSocial());	
	QLERFC->setText(pEEmpresa->ObtenRFC());
	MuestraDirecciones(pEEmpresa->ObtenDirecciones());
	MuestraTelefonos(pEEmpresa->ObtenTelefonos());
	MuestraContactos(pEEmpresa->ObtenContactos());


}
void QModificaProveedor::MuestraDirecciones(CQ_Direcciones pCQDirecciones)
{
CQ_Direccion *lCQDireccion;

	QTDirecciones->setNumRows(0);
	for(lCQDireccion=pCQDirecciones.first();
	    lCQDireccion;
	    lCQDireccion=pCQDirecciones.next())
	AnexarRegistroALaTabla(QTDirecciones,
				QStringList() <<
				QString(lCQDireccion->ObtenCalle()) +
				" "				    +
				lCQDireccion->ObtenNumero());
	MuestraDatosDireccion(pCQDirecciones.first());
}
void QModificaProveedor::MuestraDatosDireccion(CQ_Direccion *pCQDireccion)
{
	QLECalle->setText(pCQDireccion->ObtenCalle());
	QLENumero->setText(pCQDireccion->ObtenNumero());
	QLECP->setText(pCQDireccion->ObtenCP());
	QLEColonia->setText(pCQDireccion->ObtenColonia());
	QLEMunicipio->setText(pCQDireccion->ObtenDelegacion());
}
void QModificaProveedor::MuestraTelefonos(CQ_Telefonos pCQTelefonos)
{
CQ_Telefono *lCQTelefono;
	QTTelefonos->setNumRows(0);
	for(lCQTelefono=pCQTelefonos.first();
	    lCQTelefono;
	    lCQTelefono=pCQTelefonos.next())
	 AnexarRegistroALaTabla(QTTelefonos,
				QStringList() <<
				lCQTelefono->ObtenTelefono());
}
void QModificaProveedor::MuestraContactos(CQ_Personas pCQContactos)
{
CQ_Persona *lCQPersona;
	QTContactos->setNumRows(0);
	  for(lCQPersona=pCQContactos.first();
	      lCQPersona;
	      lCQPersona=pCQContactos.next())
	   AnexarRegistroALaTabla(QTContactos,
				  QStringList() <<
				  QString(lCQPersona->ObtenNombre()) +
				  " "                                +
				  lCQPersona->ObtenAPaterno());
}
