#ifndef __IMP_QCONTROLFECHA_H__
#define __IMP_QCONTROLFECHA_H__

#include <qwidget.h>
#include <qwidgetplugin.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLineEdit;
class QHBoxLayout;



class QT_WIDGET_PLUGIN_EXPORT CQControlFecha : public QWidget
{
    Q_OBJECT

public:
    CQControlFecha( QWidget *parent = 0, const char *name = 0,WFlags fl=0);
    ~CQControlFecha();

	QString ObtenA_o();
	QString ObtenDia();
	QString ObtenMes();
	QString ObtenFecha();

	void PonFecha(const char *);	
	void ColocaFechaHoy();
	void setFocus();
private:
	void ConectaSlots();
	void IniciaVariables();

	QLineEdit *ColocaEditRegilla(const char *,int ,int,int ,int);
	void ObtenDatoFecha(const char *,int,char *);
	void AAAAMMDD(char *pchrPtrFecha);

private:
	int intNCAno;
	int intNCMes;
	int intNCDia;
	char chrArrMes[10];
	QLineEdit *QLEAno;
	QLineEdit *QLEDia;
	QLineEdit *QLEMes;
	QHBoxLayout *QHBRegilla;
private slots:
	void S_PasaFocoDia();
	void S_PasaFocoMes();
	void S_PasaFocoAno();
	void S_CambioElA_o(const QString &);
	void S_CambioElMes(const QString &);
	void S_CambioElDia(const QString &);
	void S_IntrodujoA_o();
signals:
	void Signal_EnterA_o();

};

#endif
