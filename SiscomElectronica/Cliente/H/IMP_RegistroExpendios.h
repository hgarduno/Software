#ifndef __IMP_REGISTROEXPENDIOS_H__
#define __IMP_REGISTROEXPENDIOS_H__

#include <UIC_H_RegistroExpendios.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QPushButton;
class QLabel;
class QComboBox;
class QLineEdit;
class SiscomDatCom;
class QRegistroExpendios : public RegistroExpendios
{
    Q_OBJECT

public:
    QRegistroExpendios(SiscomDatCom *,
    			char **,
			QWidget* parent = 0,
			const char* name = 0,
			WFlags fl = 0 );
    ~QRegistroExpendios();
private:
	SiscomDatCom *SisDatCom;
	char **chrPtrArgumentos;
private:
	void ConectaSlots();
	void closeEvent(QCloseEvent *);
private slots:
	void S_IniciaExpendio();
signals:
	void SignalTerminar(QWidget *);
};

extern "C" QRegistroExpendios *InstanciaRegistroExpendios(void *,
							  char **,
							  void *,
							  const char *,
							  int );
#endif 
