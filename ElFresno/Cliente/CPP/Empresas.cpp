#include <Empresas.h>
#include <Direcciones.h>
#include <Personas.h>
#include <Telefonos.h>
#include <CQSiscomCom.h>

#include <qcombobox.h>
#include <qlineedit.h>
Empresa::Empresa()
{

}
Empresa::Empresa(const char *pchrPtrRazonSocial,
		 const char *pchrPtrRFC,
		 const char *pchrPtrIdEmpresa,
		 const char *pchrPtrEsExpendio):
		chrPtrRazonSocial(pchrPtrRazonSocial),
		chrPtrRFC(pchrPtrRFC),
		chrPtrIdEmpresa(pchrPtrIdEmpresa),
		chrPtrEsExpendio(pchrPtrEsExpendio)
{

}
const char *Empresa::ObtenIdEmpresa()
{
	return chrPtrIdEmpresa;
}
const char *Empresa::ObtenRazonSocial()
{
	return chrPtrRazonSocial;
}
const char *Empresa::ObtenRFC()
{
	return chrPtrRFC;
}
const char *Empresa::ObtenEsExpendio()
{
	return chrPtrEsExpendio;
}
const CQ_Personas &Empresa::ObtenContactos()
{
	return CQPContactos;
}
const CQ_Direcciones &Empresa::ObtenDirecciones()
{
	return CQDirecciones;
}
const CQ_Telefonos &Empresa::ObtenTelefonos()
{
	return CQTelefonos;
}
void Empresa::AnexarDireccion(CQ_Direccion *pCQDireccion)
{
	CQDirecciones.append(pCQDireccion);
}
void Empresa::AnexarContacto(CQ_Persona *pCQPContacto)
{
	CQPContactos.append(pCQPContacto);
}
void Empresa::AnexarTelefono(CQ_Telefono *pCQTelefono)
{
	CQTelefonos.append(pCQTelefono);
}
CQEmpresas::CQEmpresas()
{

}

CQCtrEmpresas::CQCtrEmpresas(CSISCOMDatComunicaciones *pCSisDatCom,
			     QStringList pQSLArgumentos,
			     CQEmpresas *pCQEmpresas):
		CSisDatCom(pCSisDatCom)
{
	IniciaRegistroEnvio();
	IniciaComunicacion();
	EnviaParametrosOperacion(pQSLArgumentos);
	EnviaEmpresas(pCQEmpresas);
	EnviaInformacion();
	AnalizaRespuesta(pCQEmpresas);	
	

}
void CQCtrEmpresas::AnexaRegistro()
{
	CQOGSvrSiscom->AnexaRegistro(SISCOMRegEnvio.ObtenRegistro());
	SISCOMRegEnvio.LimpiaRegistro();
}
void CQCtrEmpresas::IniciaComunicacion()
{
CQOGSvrSiscom=new CQOGenericaServidorSiscom(CSisDatCom,
                                                  "libRNSistemaElFresno.so",
                                                  "RNOperacionesElFresno",
						  21);
	SISCOMRegEnvio["Servicio"]->PonContenido("OperacionesEmpresas");
	AnexaRegistro();
	

	 
}
void CQCtrEmpresas::EnviaParametrosOperacion(QStringList pQSLArgumentos)
{
int lintContador;
	for(lintContador=0;
	    lintContador<pQSLArgumentos.size();
	    lintContador++)
	{
	 SISCOMRegEnvio["ParametroOperacion"]->PonContenido(
			(const char *)pQSLArgumentos[lintContador]
			);
	 AnexaRegistro();
	}
	AnexaRegistroVacio();
}
void CQCtrEmpresas::EnviaFinDeRegistro()
{
	AnexaRegistroVacio();
}
void CQCtrEmpresas::EnviaEmpresas(CQEmpresas *pCQEmpresas)
{
Empresa *lE_Empresa;
	for(lE_Empresa=pCQEmpresas->first();
	    lE_Empresa;
	    lE_Empresa=pCQEmpresas->next())
	{
		EnviaGeneralesEmpresa(lE_Empresa);
		EnviaDirecciones(lE_Empresa);
		EnviaTelefonos(lE_Empresa);
		EnviaContactos(lE_Empresa);
		EnviaFinDeRegistro();
	}
}
void CQCtrEmpresas::AnexaDirecciones(Empresa *pEmpresa)
{

	while(!CQOGSvrSiscom->SiguienteRegistro(QSLRegistro) &&
	      !SISCOMEsElRegistroVacio(QSLRegistro))
		pEmpresa->AnexarDireccion(new CQ_Direccion(
				(const char *)QSLRegistro[4],		
				(const char *)QSLRegistro[5],		
				(const char *)QSLRegistro[6],		
				(const char *)QSLRegistro[7],		
				(const char *)QSLRegistro[8],		
				(const char *)QSLRegistro[9],		
				(const char *)QSLRegistro[10]
				));
		
}
void CQCtrEmpresas::AnexaTelefonos(Empresa *pEmpresa)
{

	while(!CQOGSvrSiscom->SiguienteRegistro(QSLRegistro) &&
	      !SISCOMEsElRegistroVacio(QSLRegistro))
	{
	    pEmpresa->AnexarTelefono(new CQ_Telefono(
					"",
					(const char *)QSLRegistro[17])
				    );
	}

}
void CQCtrEmpresas::AnexaContactos(Empresa *pEmpresa)
{

	while(!CQOGSvrSiscom->SiguienteRegistro(QSLRegistro) &&
	      !SISCOMEsElRegistroVacio(QSLRegistro))
	{
	    pEmpresa->AnexarContacto(new CQ_Persona(
					(const char *)QSLRegistro[12],
					(const char *)QSLRegistro[13],
					(const char *)QSLRegistro[14],
					(const char *)QSLRegistro[15],
					(const char *)QSLRegistro[16],
				        (const char *)QSLRegistro[11])
				      );
	}

}
void CQCtrEmpresas::AnalizaRespuesta(CQEmpresas *pCQEmpresas)
{
Empresa *lE_Empresa;
	while(!CQOGSvrSiscom->SiguienteRegistro(QSLRegistro) &&
	       QSLRegistro.count()==19)
	{
	  lE_Empresa=new Empresa((const char *)QSLRegistro[0],
				 (const char *)QSLRegistro[2],
				 (const char *)QSLRegistro[1],
				 "");
	  AnexaDirecciones(lE_Empresa);
	  AnexaTelefonos(lE_Empresa);
	  AnexaContactos(lE_Empresa);
          pCQEmpresas->append(lE_Empresa);	
	}

}
void CQCtrEmpresas::EnviaInformacion()
{
	CQOGSvrSiscom->EjecutaEnvioSvrSISCOM();
        CQOGSvrSiscom->ObtenRespuesta();
}
void CQCtrEmpresas::EnviaGeneralesEmpresa(Empresa *pEmpresa)
{
SISCOMRegEnvio["RazonSocial"]->PonContenido(pEmpresa->ObtenRazonSocial());
SISCOMRegEnvio["RFC"]->PonContenido(pEmpresa->ObtenRFC());
SISCOMRegEnvio["EsExpendio"]->PonContenido(pEmpresa->ObtenEsExpendio());
AnexaRegistro();
}
void CQCtrEmpresas::EnviaDirecciones(Empresa *pEmpresa)
{
CQ_Direccion *lCQ_Direccion;
CQ_Direcciones lCQDirecciones=pEmpresa->ObtenDirecciones();

	for(lCQ_Direccion=lCQDirecciones.first();
	    lCQ_Direccion;
	    lCQ_Direccion=lCQDirecciones.next())
	 {
	    SISCOMRegEnvio["Calle"]->PonContenido(lCQ_Direccion->ObtenCalle());
	    SISCOMRegEnvio["Numero"]->PonContenido(lCQ_Direccion->ObtenNumero());
	    SISCOMRegEnvio["Colonia"]->PonContenido(lCQ_Direccion->ObtenColonia());
	    SISCOMRegEnvio["CP"]->PonContenido(lCQ_Direccion->ObtenCP());
	    SISCOMRegEnvio["Municipio"]->PonContenido(lCQ_Direccion->ObtenDelegacion());
	    SISCOMRegEnvio["Estado"]->PonContenido(lCQ_Direccion->ObtenEstado());
	    SISCOMRegEnvio["Referencias"]->PonContenido(lCQ_Direccion->ObtenReferencias());	 
	    AnexaRegistro(); 
	 }
	AnexaRegistroVacio();	
}
void CQCtrEmpresas::EnviaTelefonos(Empresa *pEmpresa)
{
CQ_Telefono *lCQTelefono;
CQ_Telefonos lCQTelefonos=pEmpresa->ObtenTelefonos();
	for(lCQTelefono=lCQTelefonos.first();
	    lCQTelefono;
	    lCQTelefono=lCQTelefonos.next())
	{
	  SISCOMRegEnvio["Telefono"]->PonContenido(lCQTelefono->ObtenTelefono());
	  AnexaRegistro();
	}
	AnexaRegistroVacio();	
}
void CQCtrEmpresas::EnviaContactos(Empresa *pEmpresa)
{
CQ_Persona *lCQPersona;
CQ_Personas lCQPersonas=pEmpresa->ObtenContactos();

	for(lCQPersona=lCQPersonas.first();
	    lCQPersona;
	    lCQPersona=lCQPersonas.next())
	{
	   SISCOMRegEnvio["Con_Nombre"]->PonContenido(lCQPersona->ObtenNombre());
	   SISCOMRegEnvio["Con_APaterno"]->PonContenido(lCQPersona->ObtenAPaterno());
	   SISCOMRegEnvio["Con_AMaterno"]->PonContenido(lCQPersona->ObtenAMaterno());
	   SISCOMRegEnvio["Con_TipoPersona"]->PonContenido("2");
	   AnexaRegistro();
	}

}
void CQCtrEmpresas::AnexaRegistroVacio()
{
	SISCOMRegEnvio.LimpiaRegistro();
	AnexaRegistro();
}
void CQCtrEmpresas::IniciaRegistroEnvio()
{
	SISCOMRegEnvio <<  
	new SISCOMCampoEnvio("Servicio") <<
	new SISCOMCampoEnvio("ParametroOperacion") << 
	new SISCOMCampoEnvio("RazonSocial","") << 
	new SISCOMCampoEnvio("RFC") << 
	new SISCOMCampoEnvio("IdEmpresa") << 
	new SISCOMCampoEnvio("Calle","") << 
	new SISCOMCampoEnvio("Numero")  << 
	new SISCOMCampoEnvio("Colonia")  << 
	new SISCOMCampoEnvio("CP")  << 
	new SISCOMCampoEnvio("Municipio")  << 
	new SISCOMCampoEnvio("Estado")  << 
	new SISCOMCampoEnvio("Referencias") << 
	new SISCOMCampoEnvio("Con_Nombre")  << 
	new SISCOMCampoEnvio("Con_APaterno") << 
	new SISCOMCampoEnvio("Con_AMaterno") << 
	new SISCOMCampoEnvio("Con_RFC") << 
	new SISCOMCampoEnvio("Con_TipoPersona") << 
	new SISCOMCampoEnvio("Con_IdPersona") << 
	new SISCOMCampoEnvio("Telefono") <<
	new SISCOMCampoEnvio("EsExpendio") ;
}

CQSeleccionaProveedor::CQSeleccionaProveedor(CSISCOMDatComunicaciones *pCSisDatCom,
					     QWidget *pQWParent,
					     const char *pchrPtrName,
					     QLineEdit *pQLECRazonSocial,
					     QComboBox *pQCBRazonSocial):
			QObject((QObject *)pQWParent,pchrPtrName),
			CSisDatCom(pCSisDatCom),
			QLECRazonSocial(pQLECRazonSocial),
			QCBRazonSocial(pQCBRazonSocial)
{

	LlenaComboRazonSocial();
	ConectaSlots();

}
void CQSeleccionaProveedor::LlenaComboRazonSocial()
{
CQCtrEmpresas lQCEmpresas(CSisDatCom,
			  QStringList() <<
			  QString("ConsultaEmpresas") <<
			  "Proveedores",
			  &CQ_Empresas); 
Empresa *lE_Empresa;
	for(lE_Empresa=CQ_Empresas.first();
	    lE_Empresa;
	    lE_Empresa=CQ_Empresas.next())
	  QCBRazonSocial->insertItem(lE_Empresa->ObtenRazonSocial());
}
void CQSeleccionaProveedor::ConectaSlots()
{
	connect(QCBRazonSocial,
		SIGNAL(activated(int)),
		SLOT(S_SeleccionoProveedor(int)));
	connect(QLECRazonSocial,
		SIGNAL(returnPressed()),
		SLOT(S_SeleccionoProveedor()));

}
void CQSeleccionaProveedor::S_SeleccionoProveedor()
{
     emit Signal_Proveedor(CQ_Empresas.at(QCBRazonSocial->currentItem()));
}
void CQSeleccionaProveedor::S_SeleccionoProveedor(int pintNProveedor)
{

	emit Signal_Proveedor(CQ_Empresas.at(pintNProveedor));
}
