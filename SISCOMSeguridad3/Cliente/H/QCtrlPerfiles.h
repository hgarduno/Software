#ifndef __QCTRLPERFILES_H__
#define __QCTRLPERFILES_H__

#include <Seguridad3Protocolo2.h>
#include <qwidget.h>
#include <qwidgetplugin.h>
#include <qiconview.h>

class QIconView;
class QHBoxLayout;
class PerfilSeguridadProt2;
class SiscomDatCom;

class QIVItemPerfil:public QIconViewItem
{
public:
	QIVItemPerfil(PerfilSeguridadProt2 *, QIconView *);
	PerfilSeguridadProt2 *ObtenPerfil();
private:
	PerfilSeguridadProt2 *PSeg3Prot2;
private:
	void IniciaVariables();

};
class QT_WIDGET_PLUGIN_EXPORT QCtrlPerfiles : public QWidget
{
    Q_OBJECT
public:
    QCtrlPerfiles( QWidget *parent = 0, const char *name = 0);
    void IniciaControl();
    void PonServidor(SiscomDatCom *);
    void PonAplicacion(const char *);
    void setFocus();
    void LimpiaSeleccion();
    void Limpia();
private:
	void IniciaVariables();
	void ConsultaPerfiles();
	void MuestraPerfiles();
	void ConectaSlots();
private:
	QHBoxLayout *QHBLayout;
	QIconView *QIVPerfiles;
	SiscomDatCom *SisDatCom;
	PerfilesSeguridadProt2 PerSegPro2;
	const char *chrPtrAplicacion;
private slots:
	void S_SeleccionoPerfil(QIconViewItem *);
signals:
	void SignalPerfil(PerfilSeguridadProt2 *);
};

#endif
