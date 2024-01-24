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
class SisUsuarioSeg3;
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
class CQSisParametrosModulo
{
public:
	CQSisParametrosModulo(const char *,const char **);
	const char **Parametros();
	const char *Modulo();
	void SiscomDatoParametro(int,const char *);
private:
	const char *chrPtrModulo;
	const char **chrPtrArgumentos;

};
class CQSisLstParametrosModulo:public QPtrList<CQSisParametrosModulo>
{
public:
	CQSisLstParametrosModulo();
	CQSisLstParametrosModulo &operator<<(CQSisParametrosModulo *);
	CQSisParametrosModulo *operator[](const char *);
	void SiscomAsignaDatoArgumento(int ,const char *);
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
			CQSisLstParametrosModulo &SiscomArgumentos();
			SiscomDatCom *ObtenDatosComunicacion();
			CQSisLstMenu &OpcionesMenu();
			char *SiscomObtenClaveAcceso();
			char *SiscomCPUInfo();
			const char *SiscomMacAddress();
			void UsuarioSeguridad3(SisUsuarioSeg3 *);
		private:
			CQSisLstParametrosModulo CQSLPModulo;
			QPopupMenu *QPMAplicacion;
			QPopupMenu *QPMEstadisticas;
			QPopupMenu *QPMVentanas;
			QWorkspace *ws;

			QPtrList<CQSiscomModuloTiendas> QPLModulos;
			int intUltimoIdMenuArchivo;
			int intUltimoIdVentanaActiva;
			char chrPtrAConfiguracionMod[1024];
			SiscomDatCom *SisDatCom;
			CQSisLstMenu CQSLMenus;
			char *chrPtrCPUInfo;
			char *chrPtrClaveAcceso;
			/*
			 * Una vez que se obtiene el usuario firmado
			 * este se pasara en la lista de argumentos 
			 * a todas las pantallas en la posicion 
			 * 0 del arreglo de argumentos
			 */
			SisUsuarioSeg3 *SUSeg3Firmado;
		private:
			void CreaMenus();
			void CreaWS();
			void CreaDatosComunicaciones();
			void CargaModulos(const char *);
			QPopupMenu *ObtenMenuDestino(const char *);
			void CargaArchivosDeConfiguracion();
			void ReCargaConfiguracion(const char *);
			void MuestraVentanasActivas();
			void EliminaMenuVentanasActivas();
			void ActivaVentana(int );
			void EliminaModulosCargados();
			void ObtenNombreArchivoConfiguracion(const char *);
			void MuestraDatosExpendio();
			void MuestraUsuarioFirmado();
			void closeEvent(QCloseEvent *);
			void SiscomLeeCPUInfo();
			void SiscomClaveAcceso();


			virtual void CargaFirmaUsuario();
			virtual void CargaArgumentos();
			virtual void CargaSistemaSeguridad();
			virtual void SiscomValidaAutenticidad();
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
			QAction *IniciaOpcion(const char *,const char *);
			
		private:
			char **chrPtrArgumentos;
			QWidget *QWSATrabajo;
			const char *chrPtrNmbBiblioteca;
			const char *chrPtrNmbFuncion;
			QPopupMenu *QPMModulo;
			QMainWindow *QMWModulo;
			SiscomDatCom *SisDatCom;
		        QMainWindow *(*CreaModuloTiendas)(SiscomDatCom *,
							  char **,
							  QWidget *,
							  const char *,
							  WFlags );
			QAction *QAOpcion;
			const char *chrPtrErrorDll;
			void *vidAncla;
			
		private slots:
			void SlotCargaOpcion();


};


#endif
