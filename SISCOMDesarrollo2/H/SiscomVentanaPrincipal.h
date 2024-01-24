#ifndef __SISCOMVENTANAPRINCIPAL_H__
#define __SISCOMVENTANAPRINCIPAL_H__


#include <SiscomClasesIni.h>
#include <SiscomModulos.h>
#include <qmainwindow.h>
#include <qobject.h>
class QApplication;
class QWorkspace;
class SiscomArchivoIni;
class SiscomQAction;
class SiscomDatCom;
class SisUsuarioSeg3;
class SiscomVentanaPrincipal:public QMainWindow
{
Q_OBJECT
public:
	SiscomVentanaPrincipal(QApplication *pQAppPrincipal,
			       QWidget *pQWParent=0,
			       const char *pchrPtrName=0,
			       WFlags pWFlags=0);
	SiscomVentanaPrincipal(QWidget *pQWParent=0,
			       const char *pchrPtrName=0,
			       WFlags pWFlags=0);
	QApplication *PrincipalQt();
	void SiscomIniciaVentana();
	void SiscomComunicaciones(SiscomDatCom *pSisDatCom);
	void SiscomArgumentos(char **pchrPtrArgumentos);
	void SiscomIconoAplicacion();
	void SiscomMenuVentanas(QPopupMenu *);
	SiscomDatCom *SiscomComunicaciones();
	void UsuarioSeguridad3(SisUsuarioSeg3 *);
	QWidget *SiscomParent();
	const char *SiscomAplicacion();
	QWorkspace *AreaTrabajoSiscom();
	

private:
	QApplication *QAppPrincipal;
	SiscomArchivoIni *SisArchIni;
	SiscomClasesIni SisClassIni;
	SiscomClasesIni SisClassIniMenus;
	SiscomClasesIni SisClassIniArgs;
	SiscomClaseIni *SisClasIniIconoAp;
	QWidget *QWParent;
	QWorkspace *QWSATrabajo;
	char **chrPtrArgumentos;
	SiscomModulos SisModulos;
	SiscomDatCom *SisDatCom;
	QPopupMenu *QPMVentanas;
	int intIdsVentanas;
	SisUsuarioSeg3 *SUSeg3Firmado;
	void *vidPtrBiblioteca;
	void *vidPtrIconos;
	const char *chrPtrAplicacion;
private:
	virtual void FirmaAlSistema();
	/* Queretaro a 4 de diciembre del 2015 
	 * Integro en el acceso al sistema la 
	 * funcionalidad que permite agrupar 
	 * los expendios por tipo de expendio
	 */
	virtual void AccesoSiscomElectronica();
	virtual void SiscomIniciaSeguridad();
	virtual void SiscomIniciaMenuVentanas();
	virtual void OrganizaVentanas();

	void AccesandoSistema();
	void SiscomArgumentosPantalla(const char *pchrPtrQAction);
	void SiscomValidaCpuInfo();
	void SiscomCargaBibliotecaIconos();
	void ObtenPosicionArgumentoValor(SiscomVariableIni *,
					 char *pchrPtrValor,
					 int *pintPtrPosicion);
	void SiscomPonAplicacion();
	void ArchivoConfiguracionModulos();
	void CreaMenus();
	void DatosMenu(SiscomClaseIni *pSisClasIni,
		       char *pchrPtrNmbMenu,
		       char *pchrPtrTexto);
	QPopupMenu *CreaMenu(const char *pchrPtrNmbMenu,
			     const char *pchrPtrTexto);
	SiscomQAction *CreaOpcion(SiscomClaseIni *pSisClasIni);
	void CreaOpcion(SiscomClaseIni *pSisClasIni,
			QPopupMenu *pQPMenu);
	void AreaTrabajo();

	void ValorPropiedad(SiscomClaseIni *pSisClasIni,
			    const char *pchrPtrPropiedad,
			    char *pchrPtrValor);
	void AsignaTexto(SiscomQAction *pSisQAOpcion,
			 SiscomClaseIni *pSisClasIni);
	void AsignaIcono(SiscomQAction *pSisQAOpcion,
			 SiscomClaseIni *pSisClasIni);
	void AsignaModulo(SiscomQAction *pSisQAOpcion,
			  SiscomClaseIni *pSisClasIni);
	void AsignaFuncion(SiscomQAction *pSisQAOpcion,
			   SiscomClaseIni *pSisClasIni);
	void VentanasCargadas();
	void ConectaSlots();
	void *CargaFuncionBiblioteca(const char *pchrPtrBiblioteca,const char *pchrPtrFuncion);
private slots:
	void SlotSelecciono(SiscomQAction *pSisQAOpcion);
	void SlotTerminar(QWidget *pQWVentana);
	void SlotSeleccionaVentana(int );

	void SlotActualizaMenu(const QString &);
};

#endif
