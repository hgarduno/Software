
#ifndef __IMP_FIRMASISTEMA_H__
#define __IMP_FIRMASISTEMA_H__
#include <UIC_H_FirmaSistema.h>
#include <qfont.h>
class SiscomDatCom;
class QCtrlServidoresSiscom;
class PerfilSeguridadProt2;
class SisUsuarioSeg3;
class QFirmaSistema:public FirmaSistema
{
 Q_OBJECT
public:
	QFirmaSistema(
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    bool pbModal=false,
	    WFlags pWFlags=0);
	~QFirmaSistema();
	int OpcionFirma();
	SiscomDatCom *ServidorSiscom();
	SisUsuarioSeg3 *Usuario();
	const char *IdAplicacion();
	const char *IdPerfil();
	const QFont Letra();
private:
	QWidget *QWParent;
	int intOpcion;
	SiscomDatCom *SisDatCom;
	PerfilSeguridadProt2 *PSeguridadPro2;
	const char *chrPtrAplicacion;
	SisUsuarioSeg3 *SUsuarioSeg3;
	const char *chrPtrIdAplicacion;
	const char *chrPtrIdPerfil;
	int intValidaPassword;
	QFont QFLetra;
private:
	void ConectaSlots();
	void IniciaVariables();
	void closeEvent(QCloseEvent *);
	void AsignaNombreArchivoServidores();
	void MuestraPerfiles();
	void MuestraUsuarios();
	const char *ObtenAplicacion();
	void Firmate();
private slots:
	void SlotAceptar();
	void SlotCancelar();
	void SlotServidor(SiscomDatCom *);
	void SlotPerfil(PerfilSeguridadProt2 *);
	void SlotUsuario(SisUsuarioSeg3 *);

	void SlotTipoLetra();
};
#endif
