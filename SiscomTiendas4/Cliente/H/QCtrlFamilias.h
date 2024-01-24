#ifndef __QCTRLFAMILIAS_H__
#define __QCTRLFAMILIAS_H__ 
#include <qwidget.h>
#include <qwidgetplugin.h>

#include <CQSisFamilias.h>

class QHBoxLayout;
class QComboBox;
class QLineEdit;
class CQSisFamilia;
class SiscomDatCom;

class QT_WIDGET_PLUGIN_EXPORT QCtrlFamilias : public QWidget
{
    Q_OBJECT
public:
    QCtrlFamilias( QWidget *parent = 0, const char *name = 0);
    void IniciaControl();
    void PonServidor(SiscomDatCom *);
    void setFocus();
    void Limpia();
    void PonFamiliaActual(CQSisFamilia *);
    
private:
	void IniciaVariables();
	void ConsultaFamilias();
	void MuestraFamilias();
	void ConectaSlots();
private:
	QHBoxLayout *QHBLayout;
	QComboBox *QCBFamilias;
	QLineEdit *QLEFamilias;
	SiscomDatCom *SisDatCom;
	CQSisLstFamilia CQSLFamilias;
private slots:
	void SlotFamilia(int);
	void SlotCambiandoFamilia(const QString &);
signals:
	void SignalFamilia(CQSisFamilia *);
	void SignalCambiandoFamilia();
};

#endif
