#ifndef __SEGURIDAD3PROTOCOLO2_H__
#define __SEGURIDAD3PROTOCOLO2_H__
#include <SISCOMComunicaciones++.h>
#include <SisPersonas.h>



class QPropiedadControl
{
public:
	QPropiedadControl(
				const char *,
			  	const char *,
				const char *
			);
	const char *ObtenIdPropiedad();
	const char *ObtenNmbPropiedad();
	const char *ObtenValorPropiedad();
private:
	const char *chrPtrIdPropiedad;
	const char *chrPtrNmbPropiedad;
	const char *chrPtrValor;
};

class QPropiedadesControl:public QPtrList<QPropiedadControl>
{
public:
	QPropiedadesControl();
	QPropiedadesControl &operator<<(QPropiedadControl *);
};
class QControlSeguridad
{
public:
	QControlSeguridad(const char *);
	QControlSeguridad &operator<<(QPropiedadControl *);
	const QPropiedadesControl &ObtenPropiedades();
private:
	const char *chrPtrIdControl;
	QPropiedadesControl QPropControl;

};
class QControlesSeguridad3:public QPtrList<QControlSeguridad>
{
public:
	QControlesSeguridad3();
	QControlesSeguridad3 &operator<<(QControlSeguridad *);
};
class PerfilSeguridadProt2:public SiscomInformacion
{

	public:
		PerfilSeguridadProt2(const char *,
				    const char *,
				    const char *,
				    const char *);

};

class PerfilesSeguridadProt2:public QPtrList<PerfilSeguridadProt2>
{

public:
	PerfilesSeguridadProt2();
	PerfilesSeguridadProt2 &operator<<(PerfilSeguridadProt2 *);
	void GeneraRegistros(const SiscomComunicaSrv *);

};
class QOperacionesSeguridad3
{
public:
	QOperacionesSeguridad3(SiscomDatCom *);
	void ControlesForma(
				const char *,
				const char *,
				const char *,
				QControlesSeguridad3 &
			   );
	 void ControlesForma(
	 			QPtrList<SiscomInformacion> *,
				QControlesSeguridad3 &);
	 void PerfilesAplicacion(const char *,
	 			 PerfilesSeguridadProt2 &);

			        
			
private:
	SiscomDatCom *SisDatCom;
private:
	void GeneraControles(const SiscomComunicaSrv *pSComunicaSrv,
			     QControlesSeguridad3 &pQCSeguridad3);
};

class Seguridad3Protocolo2
{
public:
	Seguridad3Protocolo2(const char *,
			     const char *,
			     SiscomDatCom *,
			     QWidget *
			     );
	Seguridad3Protocolo2(SiscomDatCom *,
			    QPtrList<SiscomInformacion> *,
			    QWidget *);
	QControlSeguridad *Control(const char *pchrPtrNombre);
	const char *PropiedadControl(const char *pchrPtrControl,
				     const char *pchrPtrPropiedad);
			
private:
	const char *chrPtrAplicacion;
	const char *chrPtrIdPerfil;
	SiscomDatCom *SisDatCom;
	QWidget *QWPantalla;
	QControlesSeguridad3 QCSeguridad3;
private:
	void ControlesFormaBD();
	void ControlesFormaBD(QPtrList<SiscomInformacion> *);
};

/*
 * Manejo de los usuarios en la base de datos de la aplicacion no en la base 
 * de datos de seguridad 
 *
 */
class SisFirmaSeg3:public SiscomInformacion2
{
public:
	SisFirmaSeg3();
private:
	void SiscomFormaRegistro();
	void SiscomAnexaRegistro();

};
class SisUsuarioSeg3:public SisPersona
{
public:
	SisUsuarioSeg3(const char *,
		       const char *,
		       const char *,
		       const char *);
	void PonFirma(const char *);
	void PonPassword(const char *);
	void PonAcceso(const char *);
};
class SisUsuariosSeg3:public QPtrList<SisUsuarioSeg3>
{
public:
	SisUsuariosSeg3();
	SisUsuariosSeg3 &operator<<(SisUsuarioSeg3 *);
};
class OpUsuariosSeg3:public SiscomOperaciones
{
public:
	OpUsuariosSeg3(SiscomDatCom *);
	void ObtenUsuarios(const char *,const char *,SisUsuariosSeg3 *);
	int ValidaFirmaAlSistema(const char *,const char *);
private:
	void IniciaConsultaUsuarios(const char *,const char *);
	void IniciaValidaFirmaAlSistema(const char *,const char *);
	void SiscomGeneraRegistros(const SiscomComunicaSrv *,
				   SiscomInformacionLst *);
private:
	SiscomParametrosConsulta SPConsulta;

};
#endif
