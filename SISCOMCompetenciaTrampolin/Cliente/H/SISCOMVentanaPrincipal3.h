#ifndef __SISCOMVENTANAPRINCIPAL3_H__
#define __SISCOMVENTANAPRINCIPAL3_H__

#include <qmainwindow.h>
#include <qxml.h>
#include <qptrlist.h>
#include <SISCOMComunicaciones++.h>
class QPopupMenu;
class QWorkspace;
class QAction;
class CQSiscomModuloTiendas;
class CQSiscomInfoModulos
{

	public:
		CQSiscomInfoModulos(const char *,
				    const char *,
				    const char *,
				    const char *,
				    const char *,
				    const char **);
		const char *ObtenNombreBiblioteca();
		const char *ObtenNombreFuncion();
		const char *ObtenNombreMenu();
		const char *ObtenTextoMenu();
		const char *ObtenNombreMenuAplicacion();
		const char **ObtenArgumentos();

	private:
		const char *chrPtrNmbBiblioteca;
		const char *chrPtrNmbFuncion;
		const char *chrPtrNmbMenu;
		const char *chrPtrTextoMenu;
		const char *chrPtrNmbMenuAplicacion;

		const char **chrPtrArgumentos;
};
class CQSiscomInfoModulosLista
{
	public:
		CQSiscomInfoModulosLista();
		void AnexaModulo(CQSiscomInfoModulos *);
		int NumModulos();
		CQSiscomInfoModulos *operator[](int );
	
	private:
	QPtrList<CQSiscomInfoModulos> QPLInfoModulos;

};
class CQSiscomAnalizaXMLModulos:public QXmlDefaultHandler
{
	public:
		CQSiscomInfoModulosLista ObtenListaModulos();
	private:
		bool startDocument();
		bool startElement(const QString &,
				const QString &,
				const QString &,
				const QXmlAttributes &);
		bool endElement(const QString &,const QString &,const QString &);
	private:
		CQSiscomInfoModulosLista CQSInfModLista;
		int intIniciaModulo;
		int intFinModulo;
		const char *chrPtrNmbMenuAplicacion;
		const char *chrPtrNmbModulo;
		const char *chrPtrNmbFuncion;
		const char *chrPtrMenu;
		const char *chrPtrTextoMenu;
		int intNumArgumento;
		const char **chrPtrArgumentos;
	private:
		void LiberaArgumentos();
		void AsignaMemoriaArgumentos();

};
class CQSiscomConfiguracionModulos
{
	public:
		CQSiscomConfiguracionModulos(const char *);
		CQSiscomInfoModulosLista ObtenListaModulos();
	private:
		void LeeArchivo();
	private:
		CQSiscomAnalizaXMLModulos CQSAXMLModulos;
};

class SISCOMVentanaPrincipal:public QMainWindow
{
	Q_OBJECT 
		public:
			SISCOMVentanaPrincipal(QWidget  *pQWParent=0,const char *pchrPtrNombre=0,WFlags =0);
			void ObtenVentanasActivas(QWidgetList &);
			void CambiaEstadoFirma(const char *);
			QWorkspace *ObtenAreaTrabajo();
			void PonDatosComunicaciones(SiscomDatCom *);
			void PonDatosComunicaciones(int ,const char *);
			void SiscomIniciaVentana();
			void ActualizaParametro(char *,int);
		private:

			QPopupMenu *QPMAplicacion;
			QPopupMenu *QPMEstadisticas;
			QPopupMenu *QPMVentanas;
			QWorkspace *ws;

			QPtrList<CQSiscomModuloTiendas> QPLModulos;
			QPtrList<CQSiscomModuloTiendas> QPLModulosSinMenu;
			int intUltimoIdMenuArchivo;
			int intUltimoIdVentanaActiva;
			char chrPtrAConfiguracionMod[1024];
			SiscomDatCom *SisDatCom;
			char **chrPtrArgumentos;
		private:
			void CreaMenus();
			void CreaWS();
			void CreaDatosComunicaciones();
			void CargaModulos(const char *);
			void CargaModulosSinMenu();
			void CargaSistemaSeguridad();
			QPopupMenu *ObtenMenuDestino(const char *);
			void CargaArchivosDeConfiguracion();
			void ReCargaConfiguracion(const char *);
			void MuestraVentanasActivas();
			void EliminaMenuVentanasActivas();
			void ActivaVentana(int );
			virtual void CargaFirmaUsuario();
			void EliminaModulosCargados();
			void ObtenNombreArchivoConfiguracion(const char *);
			void MuestraDatosExpendio();
			void closeEvent(QCloseEvent *);
		private slots:
			void SlotOperacionVentanas(int );
			void SlotMuestraVentanas();
			void SlotMuestraVentana(int );

};

class CQSiscomModuloTiendas:public QMainWindow
{
	Q_OBJECT
		public:
			CQSiscomModuloTiendas(char **,QWidget  *,const char *,WFlags );
			~CQSiscomModuloTiendas();
			void PonDatosModulo(const char *,const char *);
			void PonMenuAlQueVa(QPopupMenu *);
			void CargaModuloTiendas();
			void PonDatosComunicaciones(SiscomDatCom *);
			void IniciaOpcion(const char *,const char *);
			void ActualizaParametro(char *,int);
			
		private:
			const char *chrPtrNmbBiblioteca;
			const char *chrPtrNmbFuncion;
			QPopupMenu *QPMModulo;
			QMainWindow *QMWModulo;
			SiscomDatCom *SisDatCom;
			QWidget *QWSATrabajo;
			char **chrPtrArgumentos;
		        QMainWindow *(*CreaModuloTiendas)(SiscomDatCom *,
							  char **,
							  QWidget *,
							  const char *,
							  WFlags );
			QAction *QAOpcion;
			const char *chrPtrErrorDll;
			void *vidAncla;
			
		public slots:
			void SlotCargaOpcion();


};
#endif
