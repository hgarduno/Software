#ifndef __SISCOMVENTANAPRINCIPAL_H__
#define __SISCOMVENTANAPRINCIPAL_H__

#include <qmainwindow.h>
#include <qxml.h>
#include <qptrlist.h>
class CSISCOMDatComunicaciones;
class QPopupMenu;
class QWorkspace;
class QAction;
class CQSiscomModuloTiendas;
class CQSiscomInfoModulos
{

	public:
		CQSiscomInfoModulos(const char *,const char *,const char *,const char *,const char *);
		const char *ObtenNombreBiblioteca();
		const char *ObtenNombreFuncion();
		const char *ObtenNombreMenu();
		const char *ObtenTextoMenu();
		const char *ObtenNombreMenuAplicacion();

	private:
		const char *chrPtrNmbBiblioteca;
		const char *chrPtrNmbFuncion;
		const char *chrPtrNmbMenu;
		const char *chrPtrTextoMenu;
		const char *chrPtrNmbMenuAplicacion;
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
		private:

			QPopupMenu *QPMAplicacion;
			QPopupMenu *QPMEstadisticas;
			QPopupMenu *QPMVentanas;
			QWorkspace *ws;
			CSISCOMDatComunicaciones *CSisDatCom;
			QPtrList<CQSiscomModuloTiendas> QPLModulos;
			int intUltimoIdMenuArchivo;
			int intUltimoIdVentanaActiva;
			char chrPtrAConfiguracionMod[1024];
		private:
			void CreaMenus();
			void CreaWS();
			void CreaDatosComunicaciones();
			void CargaModulos(const char *);
			void CargaSistemaSeguridad();
			QPopupMenu *ObtenMenuDestino(const char *);
			void CargaArchivosDeConfiguracion();
			void ReCargaConfiguracion(const char *);
			void MuestraVentanasActivas();
			void EliminaMenuVentanasActivas();
			void ActivaVentana(int );
			void CargaFirmaUsuario();
			void EliminaModulosCargados();
			void ObtenNombreArchivoConfiguracion(const char *);
		private slots:
			void SlotOperacionVentanas(int );
			void SlotMuestraVentanas();
			void SlotMuestraVentana(int );

};

class CQSiscomModuloTiendas:public QMainWindow
{
	Q_OBJECT
		public:
			CQSiscomModuloTiendas(QWidget  *,const char *,WFlags );
			~CQSiscomModuloTiendas();
			void PonDatosModulo(const char *,const char *);
			void PonMenuAlQueVa(QPopupMenu *);
			void CargaModuloTiendas();
			void PonDatosComunicaciones(CSISCOMDatComunicaciones *);
			void IniciaOpcion(const char *,const char *);
		private:
			const char *chrPtrNmbBiblioteca;
			const char *chrPtrNmbFuncion;
			QPopupMenu *QPMModulo;
			QMainWindow *QMWModulo;
			CSISCOMDatComunicaciones *CSisDatCom;
			QWidget *QWSATrabajo;
		        QMainWindow *(*CreaModuloTiendas)(CSISCOMDatComunicaciones *,QWidget *,const char *,WFlags );
			QAction *QAOpcion;
			const char *chrPtrErrorDll;
			void *vidAncla;
			
		private slots:
			void SlotCargaOpcion();


};
#endif
