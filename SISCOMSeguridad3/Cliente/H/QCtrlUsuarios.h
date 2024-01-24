#ifndef __QCTRLUSUARIOS_H__
#define __QCTRLUSUARIOS_H__

#include <Seguridad3Protocolo2.h>
#include <qwidget.h>
#include <qwidgetplugin.h>
#include <qiconview.h>

class QIconView;
class QHBoxLayout;
class PerfilSeguridadProt2;
class SiscomDatCom;

class QIVItemUsuario:public QIconViewItem
{
public:
	QIVItemUsuario(SisUsuarioSeg3 *, QIconView *);
	SisUsuarioSeg3 *ObtenUsuario();
private:
	SisUsuarioSeg3 *SisUSeg3;
private:
	void IniciaVariables();

};
class QT_WIDGET_PLUGIN_EXPORT QCtrlUsuarios : public QWidget
{
    Q_OBJECT
public:
    QCtrlUsuarios( QWidget *parent = 0, const char *name = 0);
    void IniciaControl();
    void PonServidor(SiscomDatCom *);
    void PonAplicacion(const char *);
    void PonIdPerfil(const char *);
    void setFocus();
    void LimpiaSeleccion();
private:
	void LimpiaVariables();
	void IniciaVariables();
	void ConsultaUsuarios();
	void MuestraUsuarios();
	void ConectaSlots();
private:
	QHBoxLayout *QHBLayout;
	QIconView *QIVPerfiles;
	SiscomDatCom *SisDatCom;
	const char *chrPtrAplicacion;
	const char *chrPtrIdPerfil;
	SisUsuariosSeg3 SisUsSeg3;
private slots:
	void S_SeleccionoUsuario(QIconViewItem *);
signals:	
	void SignalUsuario(SisUsuarioSeg3 *);
};

#endif
