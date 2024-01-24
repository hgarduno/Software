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
class Persona;
class EmpresaN;
class QApplication;
class SiscomRegistro3;
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
class SiscomTiendasSeguridad3:public SiscomInformacion
{
public:
	SiscomTiendasSeguridad3(const char *,
				const char *,
				const char *,
				const char *,
				const char *);

};
class SiscomTiendasSeguridad3Envio:public QPtrList<SiscomTiendasSeguridad3>
{
public:
	SiscomTiendasSeguridad3Envio();
	SiscomTiendasSeguridad3Envio &operator<<(SiscomTiendasSeguridad3 *);

};

/*!
 * \brief Inicia la interfaz grafica de usuario
 *
 */

class SISCOMVentanaPrincipal:public QMainWindow
{
	Q_OBJECT 
		public:
			SISCOMVentanaPrincipal(QApplication *,
					       QWidget  *pQWParent=0,
					       const char *pchrPtrNombre=0,
					       WFlags =0);
			void ActualizaExpendio(EmpresaN *);
			void ObtenVentanasActivas(QWidgetList &);
			void CambiaEstadoFirma(const char *);
			QWorkspace *ObtenAreaTrabajo();
			Persona *ObtenEmpleado();
			/*! 
			 * \brief Inicia la ventana para que el usuario se firme<br>
			 * una ves que el usuario es validado, en esta funcion se <br>
			 * se inician los argumentos globales que se pasan a las <br>
			 * pantallas de lainterfaz, la inicializacion se realiza de <br>
			 * la siguiente forma:<br>
			 *<br>
			 * chrPtrArgumentos[0]=(char *)Expendio->SRegistrosPro2["IdEmpresa"];<br>
		         * chrPtrArgumentos[1]=(char *)Empleado->SRegistrosPro2["IdPersona"];<br>
                         * chrPtrArgumentos[2]=(char *)Expendio<br>
			 * chrPtrArgumentos[3]=(char *)this;<br>
	                 * chrPtrArgumentos[4]=(char *)Empleado->SRegistrosPro2["TipoPersona"];<br>
			 */
			void CargaFirmaUsuario();

		private:

			QPopupMenu *QPMAplicacion;
			QPopupMenu *QPMEstadisticas;
			QPopupMenu *QPMVentanas;
			QWorkspace *ws;
			QApplication *QAPrincipal;

			QPtrList<CQSiscomModuloTiendas> QPLModulos;
			int intUltimoIdMenuArchivo;
			int intUltimoIdVentanaActiva;
			char chrPtrAConfiguracionMod[1024];
			SiscomDatCom *SisDatCom;
			char **chrPtrArgumentos;
			Persona *Empleado;
			EmpresaN *Expendio;
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
			void EliminaModulosCargados();
			void ObtenNombreArchivoConfiguracion(const char *);
			void MuestraDatosExpendio();
			void closeEvent(QCloseEvent *);
			SiscomRegistro3 *ExpendioRegistro3();
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
			
		private slots:
			void SlotCargaOpcion();


};
#endif
