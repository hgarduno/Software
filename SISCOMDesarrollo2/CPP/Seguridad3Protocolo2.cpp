#include <Seguridad3Protocolo2.h>
#include <SiscomDesarrollo3Qt++.h>
#include <qvariant.h>
#include <qobjectlist.h>

Seguridad3Protocolo2::Seguridad3Protocolo2(
		SiscomDatCom *pSisDatCom,
		QPtrList<SiscomInformacion> *pQSisInformacion,
		QWidget *pQWParent):
	SisDatCom(pSisDatCom),
	QWPantalla(pQWParent)
{
	ControlesFormaBD(pQSisInformacion);
}

Seguridad3Protocolo2::Seguridad3Protocolo2(
			const char *pchrPtrAplicacion,
			const char *pchrPtrIdPerfil,
			SiscomDatCom *pSisDatCom,
			QWidget *pQWPantalla
			):
		chrPtrAplicacion(pchrPtrAplicacion),
		chrPtrIdPerfil(pchrPtrIdPerfil),
		SisDatCom(pSisDatCom),
		QWPantalla(pQWPantalla)
{

	ControlesFormaBD();


}
void Seguridad3Protocolo2::ControlesFormaBD(
	QPtrList<SiscomInformacion> *pQSisInformacion)
{
/*
QControlesSeguridad3 lQCSeguridad3;
*/
QOperacionesSeguridad3 lQOpSeguridad3(SisDatCom);

	lQOpSeguridad3.ControlesForma(
				      pQSisInformacion,
				      QCSeguridad3);
QControlSeguridad *lQCntSeguridad;
QPropiedadesControl lQPControl;
QPropiedadControl *lQPControlito;
QObjectList *lQObjList=QWPantalla->queryList();
QObject *lQObjControl;

	for(lQCntSeguridad=QCSeguridad3.first();
	    lQCntSeguridad;
	    lQCntSeguridad=QCSeguridad3.next())
	{
	   lQPControl=lQCntSeguridad->ObtenPropiedades();
	   for(lQPControlito=lQPControl.first();
	       lQPControlito;
	       lQPControlito=lQPControl.next())
	   {
	     if(!strcmp(lQPControlito->ObtenNmbPropiedad(),
	     		"name"))
	     {
	    	 if((lQObjList=QWPantalla->queryList(0,lQPControlito->ObtenValorPropiedad())))
		 {
		   
		   if((lQObjControl=lQObjList->first()))
		   {
	   		for(lQPControlito=lQPControl.next();
	       			lQPControlito;
	       			lQPControlito=lQPControl.next())
			  lQObjControl->setProperty(
			      lQPControlito->ObtenNmbPropiedad(),
			      QVariant(lQPControlito->ObtenValorPropiedad()));
		    }
		 }

	     }
	   }
	 }
}




QControlSeguridad *Seguridad3Protocolo2::Control(const char *pchrPtrNombre)
{
QControlSeguridad *lQCntSeguridad;
QPropiedadControl *lQPControlito;
QPropiedadesControl lQPControl;
for(lQCntSeguridad=QCSeguridad3.first();
    lQCntSeguridad;
    lQCntSeguridad=QCSeguridad3.next())
{
	lQPControl=lQCntSeguridad->ObtenPropiedades();
	   for(lQPControlito=lQPControl.first();
	       lQPControlito;
	       lQPControlito=lQPControl.next())
	   {
	     if(!strcmp(lQPControlito->ObtenNmbPropiedad(),"name") &&
	        !strcmp(lQPControlito->ObtenValorPropiedad(),pchrPtrNombre))
	       return lQCntSeguridad;
	     }

}
return 0;
}

const char *Seguridad3Protocolo2::PropiedadControl(const char *pchrPtrControl,
						   const char *pchrPtrPropiedad)
{
QControlSeguridad *lQCntSeguridad;
QPropiedadesControl lQPControl;
QPropiedadControl *lQPControlito;

if((lQCntSeguridad=Control(pchrPtrControl)))
{
 lQPControl=lQCntSeguridad->ObtenPropiedades();
 for(lQPControlito=lQPControl.first();
     lQPControlito;
     lQPControlito=lQPControl.next())
  {
     if(!strcmp(lQPControlito->ObtenNmbPropiedad(),pchrPtrPropiedad))
       return lQPControlito->ObtenValorPropiedad(); 
  }

}
return 0;
}

void Seguridad3Protocolo2::ControlesFormaBD()
{
/*
QControlesSeguridad3 lQCSeguridad3;
*/
QOperacionesSeguridad3 lQOpSeguridad3(SisDatCom);
SiscomEscribeLog3Qt("Aplicacion:%s",chrPtrAplicacion);
SiscomEscribeLog3Qt("Perfil:%s",chrPtrIdPerfil);
SiscomEscribeLog3Qt("Ventana:%s",QWPantalla->name());
	lQOpSeguridad3.ControlesForma(chrPtrAplicacion,
				      chrPtrIdPerfil,
				      QWPantalla->name(),
				      QCSeguridad3);
QControlSeguridad *lQCntSeguridad;
QPropiedadesControl lQPControl;
QPropiedadControl *lQPControlito,*lQPControlitoAA;
QObjectList *lQObjList=QWPantalla->queryList();
QObject *lQObjControl;
SiscomEscribeLog3Qt("Se regresaran:%d Registros",
			QCSeguridad3.count());
if(!QCSeguridad3.count())
{
SiscomEscribeLog3Qt("Error al obtener la informacion de la pantalla");
SiscomEscribeLog3Qt("No se asignara la informacion del Sistema de seguridad");
}
	for(lQCntSeguridad=QCSeguridad3.first();
	    lQCntSeguridad;
	    lQCntSeguridad=QCSeguridad3.next())
	{
	   lQPControl=lQCntSeguridad->ObtenPropiedades();
	   for(lQPControlito=lQPControl.first();
	       lQPControlito;
	       lQPControlito=lQPControl.next())
	   {
	     if(!strcmp(lQPControlito->ObtenNmbPropiedad(),
	     		"name"))
	     {
	     	/* Lunes 13 de Enero del 2014 
		 * Se agregaron los parametros para indicar a la busqueda, 
		 * que se deberia realizar con el texto del valor de la propiedad
		 * ya se tenia como expresion regular, lo que causaba que regresara
		 * los objetos que contenian una parte del texto de la propiedad
		 * lo que generaba que se habilitaran objetos que no de manera
		 * aleatoria, aunque en la base de datos se tenia bien el valor
		 * de la propiedad.
		 */
	    	 if((lQObjList=QWPantalla->queryList(0,lQPControlito->ObtenValorPropiedad(),0,0)))
		 {
		   if((lQObjControl=lQObjList->first()))
		   {
	   		for(lQPControlitoAA=lQPControl.next();
	       			lQPControlitoAA;
	       			lQPControlitoAA=lQPControl.next())
			  lQObjControl->setProperty(
			      lQPControlitoAA->ObtenNmbPropiedad(),
			      QVariant(lQPControlitoAA->ObtenValorPropiedad()));
		    }
		 }
		 else
		 SiscomEscribeLog3Qt("\t No se encontro :%s",lQPControlito->ObtenValorPropiedad());
	     }
	   }
	 }
}

QPropiedadControl::QPropiedadControl(
			const char *pchrPtrIdPropiedad,
			const char *pchrPtrNmbPropiedad,
			const char *pchrPtrValor):
		chrPtrIdPropiedad(pchrPtrIdPropiedad),
		chrPtrNmbPropiedad(pchrPtrNmbPropiedad),
		chrPtrValor(pchrPtrValor)
{

}
const char *QPropiedadControl::ObtenIdPropiedad()
{
	return chrPtrIdPropiedad;
}
const char *QPropiedadControl::ObtenNmbPropiedad()
{
	return chrPtrNmbPropiedad;
}
const char *QPropiedadControl::ObtenValorPropiedad()
{
	return chrPtrValor;
}
QPropiedadesControl::QPropiedadesControl()
{

}
QPropiedadesControl &QPropiedadesControl::operator<<(QPropiedadControl *pQPropControl)
{
	append(pQPropControl);
	return *this;
}

QControlSeguridad::QControlSeguridad(const char *pchrPtrIdControl):
		chrPtrIdControl(pchrPtrIdControl)
{

}
QControlSeguridad &QControlSeguridad::operator<<(QPropiedadControl *pQCntPropiedad)
{
		QPropControl << pQCntPropiedad;
		return *this;
}
const QPropiedadesControl &QControlSeguridad::ObtenPropiedades()
{
	return QPropControl;
}
QControlesSeguridad3::QControlesSeguridad3()
{

}
QControlesSeguridad3 &QControlesSeguridad3::operator<<(QControlSeguridad *pQCSeguridad)
{
	append(pQCSeguridad);
	return *this;
}
QOperacionesSeguridad3::QOperacionesSeguridad3(SiscomDatCom *pSisDatCom):
			SisDatCom(pSisDatCom)
{


}
void QOperacionesSeguridad3::ControlesForma(QPtrList<SiscomInformacion> *pQSisInforma,
					    QControlesSeguridad3 &pQCntSeguridad3)
{
SiscomGeneralOperacionesSrv lSGenOp(SisDatCom,
				   (QPtrList<SiscomInformacion> *)pQSisInforma); 
	lSGenOp.SiscomEjecutaEnvio("ConsultaSeguridad3Pro2Version2"); 
	GeneraControles((const SiscomComunicaSrv *)lSGenOp,pQCntSeguridad3);


}
void QOperacionesSeguridad3::ControlesForma(
				const char *pchrPtrAplicacion,
				const char *pchrPtrIdPerfil,
				const char *pchrPtrNmbForma,
				QControlesSeguridad3 &pQCntSeguridad3
				)
{
SiscomParametrosConsulta lSPConsulta;
		lSPConsulta <<
		new SiscomParametroConsulta("ControlesForma") 	<<
		new SiscomParametroConsulta(pchrPtrNmbForma)	<<
		new SiscomParametroConsulta(pchrPtrIdPerfil)    <<
		new SiscomParametroConsulta(pchrPtrAplicacion); 
SiscomGeneralOperacionesSrv lSGenOp(SisDatCom,
				   (QPtrList<SiscomInformacion> *)&lSPConsulta); 
	lSGenOp.SiscomEjecutaEnvio("ConsultaSeguridad3Pro2"); 
	GeneraControles((const SiscomComunicaSrv *)lSGenOp,pQCntSeguridad3);
}
void QOperacionesSeguridad3::GeneraControles(const SiscomComunicaSrv *pSComunicaSrv,
					     QControlesSeguridad3 &pQCSeguridad3)
{
SiscomRegistrosPro2 lSRegistrosPro2((SiscomComunicaSrv *)pSComunicaSrv);
QControlSeguridad *lQCntSeguridad;
	++lSRegistrosPro2;
	for(;
		!lSRegistrosPro2.SiscomEsElUltimoRegistro();
		++lSRegistrosPro2)
	{
		lQCntSeguridad=new QControlSeguridad(lSRegistrosPro2["idobjeto"]);
		while(!lSRegistrosPro2.SiscomEsElUltimoRegistro() &&
		       strcmp(lSRegistrosPro2["nmbpropiedad"],"IniciaControl"))
	   {
		(*lQCntSeguridad) << new QPropiedadControl(
						lSRegistrosPro2["idpropiedad"],
						lSRegistrosPro2["nmbpropiedad"],
						lSRegistrosPro2["valorpropiedad"]);
		++lSRegistrosPro2;
	   }
		pQCSeguridad3 << lQCntSeguridad;	    
	}
   delete pSComunicaSrv;
}

void QOperacionesSeguridad3::PerfilesAplicacion(const char *pchrPtrIdAplicacion,
						PerfilesSeguridadProt2 &pPSeguridadPro2)
{
SiscomParametrosConsulta lSPConsulta;
		lSPConsulta <<
		new SiscomParametroConsulta("PerfilesAplicacion") 	<<
		new SiscomParametroConsulta(pchrPtrIdAplicacion);
SiscomGeneralOperacionesSrv lSGenOp(SisDatCom,
				   (QPtrList<SiscomInformacion> *)&lSPConsulta); 
	lSGenOp.SiscomEjecutaEnvio("ConsultaSeguridad3Pro2"); 
	pPSeguridadPro2.GeneraRegistros((const SiscomComunicaSrv *)lSGenOp);
}
PerfilSeguridadProt2::PerfilSeguridadProt2(const char *pchrPtrIdPerfil,
					   const char *pchrPtrIdAplicacion,
					   const char *pchrPtrNmbPerfil,
					   const char *pchrPtrDscPerfil)
{

	SRegistroPro2   		<<
	"IdPerfil"			<<
	"IdAplicacion"			<<
	"NmbPerfil"			<<
	"DscPerfil";
	SRegistrosPro2.PonRegistroPro2(&SRegistroPro2);
	SRegistrosPro2                                  	<<
	SiscomCampoPro2("IdPerfil",pchrPtrIdPerfil)		<<
	SiscomCampoPro2("IdAplicacion",pchrPtrIdAplicacion)	<<
	SiscomCampoPro2("NmbPerfil",pchrPtrNmbPerfil)		<<
	SiscomCampoPro2("DscPerfil",pchrPtrDscPerfil);
	SRegistrosPro2.SiscomAnexaRegistro();
}
PerfilesSeguridadProt2::PerfilesSeguridadProt2()
{

}
PerfilesSeguridadProt2 &PerfilesSeguridadProt2::operator<<(PerfilSeguridadProt2 *pPSegProt2)
{
	append(pPSegProt2);
	return *this;
}
void PerfilesSeguridadProt2::GeneraRegistros(const SiscomComunicaSrv *pSComunicaSrv)
{
SiscomRegistrosPro2 lSRegistrosPro2((SiscomComunicaSrv *)pSComunicaSrv);

	for(;
	    !lSRegistrosPro2.SiscomEsElUltimoRegistro();
	    ++lSRegistrosPro2)
	 append(new PerfilSeguridadProt2(
	 		lSRegistrosPro2["idperfil"],
	 		lSRegistrosPro2["idaplicacion"],
	 		lSRegistrosPro2["nmbperfil"],
	 		lSRegistrosPro2["dscperfil"]));
	 				
delete pSComunicaSrv;
}


SisFirmaSeg3::SisFirmaSeg3()
{
	SiscomAsignaInformacion();
}
void SisFirmaSeg3::SiscomFormaRegistro()
{
	SRegistroPro2			<<
	"Firma"				<<
	"Password"			<<
	"Acceso";
}
void SisFirmaSeg3::SiscomAnexaRegistro()
{
	SRegistrosPro2 			<<
	SiscomCampoPro2("Firma","")	<<
	SiscomCampoPro2("Password","")	<<
	SiscomCampoPro2("Acceso","");
}


SisUsuarioSeg3::SisUsuarioSeg3(const char *pchrPtrNombre,
				const char *pchrPtrAPaterno,
				const char *pchrPtrAMaterno,
				const char *pchrPtrIdPersona):
		SisPersona(pchrPtrNombre,
			   pchrPtrAPaterno,
			   pchrPtrAMaterno,
			   pchrPtrIdPersona)
{
	SiscomAnexaCampos(SisFirmaSeg3());
}
void SisUsuarioSeg3::PonFirma(const char *pchrPtrFirma)
{
	SRegistrosPro2.SiscomActualizaCampo("Firma",pchrPtrFirma);
}
void SisUsuarioSeg3::PonPassword(const char *pchrPtrPassword)
{
	SRegistrosPro2.SiscomActualizaCampo("Password",pchrPtrPassword);
}
void SisUsuarioSeg3::PonAcceso(const char *pchrPtrAcceso)
{
	SRegistrosPro2.SiscomActualizaCampo("Acceso",pchrPtrAcceso);
}
SisUsuariosSeg3::SisUsuariosSeg3()
{

}
SisUsuariosSeg3 &SisUsuariosSeg3::operator<<(SisUsuarioSeg3 *pSUsSeg3)
{
	append(pSUsSeg3);
	return *this;
}
OpUsuariosSeg3::OpUsuariosSeg3(SiscomDatCom *pSisDatCom):
		SiscomOperaciones(pSisDatCom)
{

}
void OpUsuariosSeg3::IniciaConsultaUsuarios(const char *pchrPtrAplicacion,
					    const char *pchrPtrIdPerfil)

{
	SPConsulta <<
	new SiscomParametroConsulta("UsuariosAplicacionPerfil")		<<
	new SiscomParametroConsulta(pchrPtrAplicacion)			<<
	new SiscomParametroConsulta(pchrPtrIdPerfil);
	SiscomPonParametrosConsulta((SiscomInformacionLst  *)&SPConsulta);
}

void OpUsuariosSeg3::ObtenUsuarios(const char *pchrPtrAplicacion,
				   const char *pchrPtrIdPerfil,
				   SisUsuariosSeg3 *pSUsSeg3)
{
			
	IniciaConsultaUsuarios(pchrPtrAplicacion,pchrPtrIdPerfil);
	SiscomConsulta("ConsultaSeguridad3Pro2",
		       (SiscomInformacionLst *)pSUsSeg3);

}
void OpUsuariosSeg3::IniciaValidaFirmaAlSistema(const char *pchrPtrFirma,
						const char *pchrPtrPassword)
{
	SPConsulta						<<
	new SiscomParametroConsulta("ValidaFirmaAlSistema")	<<
	new SiscomParametroConsulta(pchrPtrFirma)		<<
	new SiscomParametroConsulta(pchrPtrPassword);
	SiscomPonParametrosConsulta((SiscomInformacionLst  *)&SPConsulta);
	
}
int OpUsuariosSeg3::ValidaFirmaAlSistema(const char *pchrPtrFirma,
				         const char *pchrPtrPassword)
{
SisUsuariosSeg3 lSUsSeg3;
	IniciaValidaFirmaAlSistema(pchrPtrFirma,pchrPtrPassword);
	SiscomConsulta("ConsultaSeguridad3Pro2",
			(SiscomInformacionLst *)&lSUsSeg3);
	return lSUsSeg3.count() &&
	       !strcmp(lSUsSeg3.at(0)->SRegistrosPro2["Acceso"],
	       	       "Si");

}
void OpUsuariosSeg3::SiscomGeneraRegistros(
				const SiscomComunicaSrv *pSComunicaSrv,
				SiscomInformacionLst *pSisInfoLstRegreso)
{
SiscomRegistrosPro2 lSRegistrosPro2((SiscomComunicaSrv *)pSComunicaSrv);
SisUsuariosSeg3 *lSisUs3=(SisUsuariosSeg3 *)pSisInfoLstRegreso;
SisUsuarioSeg3 *lSisUsuario;
	for(;
		!lSRegistrosPro2.SiscomEsElUltimoRegistro();
		++lSRegistrosPro2)
	{
		lSisUsuario=new SisUsuarioSeg3(lSRegistrosPro2["nombre"],
					       lSRegistrosPro2["apaterno"],
					       lSRegistrosPro2["amaterno"],
					       lSRegistrosPro2["idpersona"]);
		lSisUsuario->PonFirma(lSRegistrosPro2["firma"]);
		lSisUsuario->PonAcceso(lSRegistrosPro2["acceso"]);
		(*lSisUs3) << lSisUsuario;
	}
}
