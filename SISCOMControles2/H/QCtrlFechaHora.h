#ifndef __QCTRLFECHAHORA_H__
#define __QCTRLFECHAHORA_H__

#include <qwidget.h>
#include <qwidgetplugin.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLineEdit;
class QHBoxLayout;
/*!
 *
 * Control Qt 3 que se encuentra en  $(QTDIR)/plugins/designer/libControlFechaDesarrollo2.so <br>
 */


class QT_WIDGET_PLUGIN_EXPORT QCtrlFechaHora : public QWidget
{
    Q_OBJECT

public:
    QCtrlFechaHora( QWidget *parent = 0, const char *name = 0,WFlags fl=0);
    ~QCtrlFechaHora();

	QString ObtenA_o();
	QString ObtenDia();
	QString ObtenMes();
	QString ObtenFechaHora();

	void PonFecha(const char *);	
	void ColocaFechaHoy();
	void setFocus();


private:
	void ConectaSlots();
	void IniciaVariables();

	QLineEdit *ColocaEditRegilla(const char *,int ,int,int ,int);
	void ObtenDatoFecha(const char *,int,char *);

private:
	int intNCAno;
	int intNCMes;
	int intNCDia;
	char chrArrMes[10];
	QLineEdit *QLEAno;
	QLineEdit *QLEDia;
	QLineEdit *QLEMes;
	QLineEdit *QLEHora;
	QLineEdit *QLEMinuto;
	QHBoxLayout *QHBRegilla;
private slots:
	void S_PasaFocoDia();
	void S_PasaFocoMes();
	void S_PasaFocoAno();
	void S_PasaFocoHora();
	void S_PasaFocoMinuto();
	void S_CambioElA_o(const QString &);
	void S_CambioElMes(const QString &);
	void S_CambioElDia(const QString &);
	void S_EnterMinuto();
signals:
	void Signal_EnterMinuto();

};

#endif
