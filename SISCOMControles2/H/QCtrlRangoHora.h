#ifndef __QCTRLRANGOHORA_H__
#define __QCTRLRANGOHORA_H__

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

class QT_WIDGET_PLUGIN_EXPORT QCtrlRangoHora : public QWidget
{
    Q_OBJECT

public:
    QCtrlRangoHora( QWidget *parent = 0, const char *name = 0,WFlags fl=0);
    ~QCtrlRangoHora();

	QString ObtenA_o();
	QString ObtenDia();
	QString ObtenMes();
	QString ObtenRangoHora();

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
	QLineEdit *QLEHora;
	QLineEdit *QLEMinuto;

	QLineEdit *QLEHoraFin;
	QLineEdit *QLEMinutoFin;

	QHBoxLayout *QHBRegilla;
private slots:
	void S_PasaFocoMinuto();
	void S_PasaFocoHoraFin();
	void S_PasaFocoMinutoFin();
	void S_CapturoRangoHora();
signals:
	void SignalCapturoRangoHora(char *pchrPtrHoraInicio,
				    char *pchrPtrHoraFin);

};

#endif
