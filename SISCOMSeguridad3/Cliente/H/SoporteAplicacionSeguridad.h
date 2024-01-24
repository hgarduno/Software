#ifndef __SOPORTEAPLICACIONSEGURIDAD_H__
#define __SOPORTEAPLICACIONSEGURIDAD_H__
#include <CQSiscomCom.h>
#include <qstringlist.h>
#include <GeneralBibliotecaSeguridad3.h>
class CQAplicaciones:public CQOGenericaServidorSiscom
{

	public:
		CQAplicaciones(CSISCOMDatComunicaciones *,const char *);
		CQAplicaciones(CSISCOMDatComunicaciones *,
			       const char *,
			       const char *,
			       const char *,
			       const char *);
		QString ObtenIdAplicacion();
		QString ObtenDscAplicacion();
	        QString ObtenDirArchivosQt();
		int LaAplicacionEstaRegistrada();
	private:
		QStringList QSLRegistro;
};
/*
class CQPerfiles:public CQOGenericaServidorSiscom
{
	public:

	 	CQPerfiles(CSISCOMDatComunicaciones *,QSiscomPerfilBD *,const char *);
	 	CQPerfiles(CSISCOMDatComunicaciones *,const char *);
		CQPerfiles(CSISCOMDatComunicaciones *,const QSiscomPerfilBD &);
		CQPerfiles(CSISCOMDatComunicaciones *,const char *,int );
		~CQPerfiles();
		QSiscomPerfilBD *operator[](int );
		int CuantosPerfiles();

	private:
		const char *chrPtrIdAplicacion;
		const char *chrPtrIdPerfilRef;
		QSiscomListaPerfilesBD QSLPerfilesBD;
	private:
		void GeneraListaPerfiles();
		void CreaRegistrosEnvio();
		void CreaRegistroEnvio(QSiscomPerfilBD *);

};
*/
class CQUsuario
{
	public:
		CQUsuario(long ,
			   long ,
			   long ,
			   const char *,
			   const char *,
			   const char *);
		CQUsuario(long ,
			   long ,
			   long ,
			   const char *,
			   const char *,
			   const char *,
			   const char *,
			   const char *);

		CQUsuario(long ,
			   long ,
			   const char *,
			   const char *,
			   const char *);

		const char *ObtenNombre();
		const char *ObtenAPaterno();
		const char *ObtenAMaterno();
		const char *ObtenFirma();
		const char *ObtenPassword();
		const char *ObtenCPassword();
		const char *ObtenNmbAplicacion();
		void PonFirma(const char *);
		void PonPassword(const char *);
		long ObtenIdUsuario();
		long ObtenIdPerfil();
		long ObtenIdAplicacion();
		int operator==(char **);
		int operator==(QStringList );
		CQUsuario operator=(CQUsuario);
	private:
		const char *chrPtrNombre;
		const char *chrPtrAPaterno;
		const char *chrPtrAMaterno;
		const char *chrPtrFirma;
		const char *chrPtrPassword;
		const char *chrPtrCPassword;
		long idUsuario;
		long idAplicacion;
		long idPerfil;
		const char *chrPtrNmbAplicacion;

};
class CQUsuarios
{
	public:
		  CQUsuarios();
		  void AnexaUsuario(CQUsuario *);
		  void AnexaUsuario(CQUsuario );
		  CQUsuario *operator[](int);
		  CQUsuario *operator[](long);
		  CQUsuario *operator<<(CQUsuario );
		  
	private:
		QPtrList<CQUsuario> QPLUsuarios;	

};
class CQOperacionesUsuario
{
	public:
		CQOperacionesUsuario(CSISCOMDatComunicaciones *);

		void RegistraUsuarios(CQUsuarios *);
		int RegistraUsuario(const char *,CQUsuario *);
		void RegistraUsuario(CQUsuario *);
		void RegistraFirma(CQUsuario *);
		void AnexaRegistroUsuario(CQOGenericaServidorSiscom *,CQUsuario *);
		void ConsultaUsuarios(long ,long, CQUsuarios &);

	private:
		CSISCOMDatComunicaciones *CSisDatCom;
	private:
		void GeneraListaUsuarios(CQOGenericaServidorSiscom *,CQUsuarios &);

};
int VeSiLasPantallasEstanRegistradas(CSISCOMDatComunicaciones *,const char *);
#endif

