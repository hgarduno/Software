#ifndef __GENERALBIBLIOTECASEGURIDAD3_H__
#define __GENERALBIBLIOTECASEGURIDAD3_H__
#include <qstringlist.h>
#include <qwidget.h>
#include <CQSiscomCom.h>
#include <qobjectlist.h>

class CSISCOMDatComunicaciones;
class CQPerfiles;
class QSiscomPropiedadesBD
{
	public:
		QSiscomPropiedadesBD(QString ,QString ,QString);
		QString ObtenIdPropiedadBD();
		QString ObtenNombrePropiedad();
		QString ObtenValorPropiedad();
		void PonValorPropiedad(QString );
	private:
		QString QSIdPropiedadBD;
		QString QSNmbPropiedad;
		QString QSValorPropiedad;

};
typedef QPtrList<QSiscomPropiedadesBD> QSiscomListaPropBD;
class QSiscomObjetosQT
{
	public:
		QSiscomObjetosQT();
		void AnexaPropiedad(const char *,QString );
		void AnexaPropiedad(QString ,const char *,QString );
		void ActualizaPropiedad(const char *,QString );	
		void PonIdObjeto(QString );
		QString ObtenValorPropiedad(const char *);
		QString ObtenSiguientePropiedad();
		QString ObtenNombreObjeto();
		QString ObtenIdObjeto();
		QString ObtenClaseQT();
		QSiscomListaPropBD ObtenPropiedades();
		QObject *ObtenControlPantalla();
		
		int HayMasPropiedades();
		void PonPropiedades(QSiscomListaPropBD );
		void PonNombreObjeto(QString );
		void PonClaseQT(QString );
		void PonControlPantalla(QObject *);
		int operator == (QSiscomObjetosQT *);
		int operator == (QObject *);
		const QSiscomObjetosQT &operator=(QSiscomObjetosQT *);
		QSiscomObjetosQT *CopiaObjeto(const char *);
		
		
	private:
		QSiscomListaPropBD QSLPropBD;
		QString QSClaseQT;
		QString QSNmbObjeto;
		QString QSIdObjeto;
		int intPropiedad;
		QObject *QOControlPantalla;

};

typedef QPtrList<QSiscomObjetosQT> QSiscomListaObjQ;
class QSiscomArchivoUI
{
	public:
		QSiscomArchivoUI(const char *);
		QSiscomListaObjQ ObtenControlesArchivo();
		static void ObtenControles(QWidget *,QSiscomListaObjQ &);
		static void ImprimeObjetos(QSiscomListaObjQ ,const char *);
		QString ObtenClase();
		QString ObtenNmbForma();
	private:
		QWidget *QWPantalla;
		QString QSNmbArchivo;
		QString QSClase;
		QString QSNmbForma;
		QSiscomListaObjQ QPLObjetos;
	private:
		void LeeArchivo();
		void ObtenControles(QWidget *);
};
class QSiscomObjetosSeguridad:public CQOGenericaServidorSiscom
{
	public:
		QSiscomObjetosSeguridad(CSISCOMDatComunicaciones *,
				        QSiscomListaObjQ,
					QString,
					QString ,
					QString);
		QSiscomObjetosSeguridad(QSiscomListaObjQ ,
					QString,
				        QString,
				        QString,
					const char *);
		void FiltraObjetos();
		void ConsultaObjetos(QWidget *);
		QString ObtenNombreForma();
		const char *ObtenIdForma();
		void PonNombreForma(const char *);
		void PonObjetosFiltrados(QSiscomListaObjQ );
		QSiscomListaObjQ ObtenObjetosFiltrados();
	private:
		QSiscomListaObjQ QSLObjQ;
		QSiscomListaObjQ QSLObjFiltrados;
		QString QSAplicacion;
		QString QSClase;
		QString QSNmbForma;
		const char *chrPtrIdClase;
	private:
		void AnexaPropiedades(QSiscomObjetosQT *);
		void ConstruyeObjetosFiltrados();
		int EsElRegistroVacio(QStringList);
		void AsignaObjetoDePantallaABD(QSiscomListaObjQ ,QSiscomObjetosQT *);
		
};
typedef QPtrList<QSiscomObjetosSeguridad> QSiscomListaContXForma;
class QSiscomRegistraObjetos:public CQOGenericaServidorSiscom
{
	public:
		QSiscomRegistraObjetos(CSISCOMDatComunicaciones *,
				       QSiscomListaContXForma,
				       long  ,
				       int);
		QSiscomRegistraObjetos(CSISCOMDatComunicaciones *,
				       QSiscomListaContXForma,
				       long  ,
				       int,
				       const char *);
		QSiscomRegistraObjetos(CSISCOMDatComunicaciones *,
				       QSiscomListaContXForma,
				       long  ,
				       const char *);

	private:
		QSiscomListaContXForma QSLContXForma;
		long lngIdAplicacion;
		int intIdPerfil;
	        
	private:
		void FormaRegistrosRegistro(const char *);	
};
class QSiscomSeguridad3
{
	public:
		/*
			Al integrar el manejo de los iconos, en las propiedades se requiere
			pasar al modulo de seguridad la ruta donde se encontraran los archivos
			ya que en la base de datos solo se guarda el nombre del archivo del 
			icono, en este punto en el tercer argumento const char * se pasa
			la ruta, que para mayor flexibilidad se podra tomar de una variable
			de ambiente, falta poder realizar el mismo proceso en la funcion
			AsignaControlesBDAPantalla
		*/
		QSiscomSeguridad3(QWidget *,CSISCOMDatComunicaciones *,const char *,const char *,const char *);	
		QSiscomSeguridad3(const QObjectList & ,
			          CSISCOMDatComunicaciones *,
				  const QStringList &,
				  const char *,
				  const char *);
		
				  
		QSiscomSeguridad3(QWidget *);	
		void AsignaControlesBDAPantalla(CSISCOMDatComunicaciones *);
		void AsignaControlesBDAPantalla(CSISCOMDatComunicaciones *,const char *,const char *,const char *);
		void AsignaControlesBDAPantalla(const QObjectList &);
		void PonBloqueaPropiedades(const QStringList &);
		static bool ValidaUsuario(CSISCOMDatComunicaciones *,const char *);
		static bool ValidaUsuario(CSISCOMDatComunicaciones *,const char *,char *);


		static bool RegistraUsuarioYFirma(CSISCOMDatComunicaciones *,
						  const char *,	
						  const char *,
						  const char *,
						  const char *,
						  const char *,
						  const char *,
						  const char *,
						  const char *);
		static CQPerfiles *ObtenPerfilesDeLaAplicacion(CSISCOMDatComunicaciones *);
		static long ElUsuarioTieneElPerfil(CSISCOMDatComunicaciones *,
						   const char *,
						   const char *);



	private:
		QSiscomListaObjQ QSLObjQPantalla;
		QSiscomListaObjQ QSLObjQBaseDatos;
		CSISCOMDatComunicaciones *CSisDatCom;
		const char *chrPtrNmbClase;
		const char *chrPtrFirma;
		const char *chrPtrAplicacion;
		const char *chrPtrRutaIconos;
		QStringList QSLBloqueaPropiedades;
		
	
	private:
		void ObtenControlesBD(const char *);	
		void AsignaPropiedadesBDAPantalla();
		void AsignaPropiedadesBDAlObjeto(QSiscomObjetosQT *,QSiscomObjetosQT *);
		void AsignaPropiedadesBDAlObjeto(QSiscomObjetosQT *,QObject *);
		int ValidaPropiedadesBloqueadas(const char *);



};
class QSiscomConsultaObjetos:public CQOGenericaServidorSiscom
{
	public:
		QSiscomConsultaObjetos(CSISCOMDatComunicaciones *,
				       const char *,
				       const char *,
				       const char *);
		QSiscomConsultaObjetos(CSISCOMDatComunicaciones *,
				       const char *,
				       const char *,
				       const char *,
				       const char *);
		QSiscomConsultaObjetos(CSISCOMDatComunicaciones *,
				       const QObjectList &,
				       const char *,
				       const char *);
		QSiscomConsultaObjetos(CSISCOMDatComunicaciones *);
		QSiscomListaObjQ ObtenObjetosDeLaForma();
		QSiscomObjetosSeguridad *ObtenObjetosSeguridad();
		void PonIdPantalla(const char *);
	private:
		void CreaListaDeObjetos();
		QSiscomObjetosQT *CreaObjeto(QStringList &);	
	private:
		QSiscomListaObjQ QPLContXForma;
		const char *chrPtrAplicacion;
		const char *chrPtrPerfil;
		const char *chrPtrClase;
		const char *chrPtrIdPantalla;
};
class QSiscomPantallaBD
{
	public:
		QSiscomPantallaBD(const char *,const char *,const char *,const char *);
		const char *ObtenIdPantalla();
		const char *ObtenNmbClase();	
		const char *ObtenArchivo();
		const char *ObtenIdAplicacion();

	private:

		const char *chrPtrIdPantalla;
		const char *chrPtrNmbClase;
		const char *chrPtrArchivo;
		const char *chrPtrIdAplicacion;

};
class QSiscomPerfilBD
{
	public:
		QSiscomPerfilBD(const char *,const char *,const char *,const char *);
		const char *ObtenIdPerfil();
		const char *ObtenIdAplicacion();
		const char *ObtenNmbPerfil();
		const char *ObtenDscPerfil();
		int operator==(const char *);
	private:
		const char *chrPtrIdPerfil;
		const char *chrPtrIdAplicacion;
		const char *chrPtrNmbPerfil;
		const char *chrPtrDscPerfil;


};
typedef QPtrList<QSiscomPerfilBD> QSiscomListaPerfilesBD;
class QSiscomPantallaConControlesBD
{
	public:
		QSiscomPantallaConControlesBD(QSiscomPantallaBD *,
				   QSiscomListaContXForma *);
		QSiscomPantallaConControlesBD(QSiscomPantallaBD *);
		QSiscomPantallaBD *ObtenPantallaBD();
	private:

		QSiscomPantallaBD *QSPantallaBD;
		QSiscomListaContXForma QSLContXForma;

};

typedef QPtrList<QSiscomPantallaConControlesBD> QSiscomListaPantallasBD;
class QSiscomConsultaAplicacion:public CQOGenericaServidorSiscom
{
	public:
		QSiscomConsultaAplicacion(CSISCOMDatComunicaciones *,	
					  const char *,
				          const char *);
		const QSiscomListaPantallasBD &ObtenPantallasBD();
		QSiscomPantallaBD *operator[](long);
		QSiscomPantallaBD *operator[](int );
		//const QSiscomListaContXForma &ObtenPantallasYControles();

	private:
		const char *chrPtrIdAplicacion;
		const char *chrPtrNmbAplicacion;
		QSiscomListaPantallasBD QSLPantallasBD;
		//QSiscomListaContXForma QSLContXForma;
		CSISCOMDatComunicaciones *CSDatCom;
	private:
		void ConsultaPantallasBD();

};

class CQPerfiles:public CQOGenericaServidorSiscom
{
	public:
/*
	Para usar la misma infraestructura, para realizar las altas y eliminar 
	se usan dos constructores de la clase, para eliminar se pasa la referencia
	a una lista de perfiles, y para la alta de una lista se pasa despues
	de los datos de comunicaciones un long, despues la referencia de la
	lista de perfiles.

	Si esta chafa pero amodo.

*/
	 	CQPerfiles(CSISCOMDatComunicaciones *,QSiscomPerfilBD *,const char *);
	 	CQPerfiles(CSISCOMDatComunicaciones *,const char *);
		CQPerfiles(CSISCOMDatComunicaciones *,const QSiscomPerfilBD &);
		CQPerfiles(CSISCOMDatComunicaciones *,const char *,int );
		~CQPerfiles();
		QSiscomPerfilBD *operator[](int );
		QSiscomPerfilBD *operator[](const char *);
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
extern QFont gQFTipoLetra;
#endif
