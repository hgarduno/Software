#ifndef __IMP_CTREXPENDIOS_H__
#define __IMP_CTREXPENDIOS_H__

#include <UIC_H_CtrExpendios.h>
#include <EmpresasN.h>
#include <qworkspace.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QIconView;
class QIconViewItem;
class QPushButton;
class SiscomDatCom;
class EmpresaN;
class SISCOMVentanaPrincipal;
class QEspacioExpendios;
class QCtrExpendios : public CtrExpendios
{
    Q_OBJECT

public:
    QCtrExpendios(SiscomDatCom *,
    		  char **,
		  QWidget* parent = 0,
		  const char* name = 0,
		  WFlags fl = 0 );
    ~QCtrExpendios();
private:
	SiscomDatCom *SisDatCom;
	char **chrPtrArgumentos;
	EmpresasN Expendios;
	EmpresaN *Expendio;
	SISCOMVentanaPrincipal *SISCOMVenPrincipal;
	QWidgetList QWLVentanas;
	QWidget *QWParent;
	QEspacioExpendios *QEExpendios;
private:
	void ExpendiosDisponibles();
	void ConectaSlots();
	void CreaEspacioExpendio();
	int VerificaCreacionEspacio();
	void closeEvent(QCloseEvent *);
private slots:
	void S_SeleccionoExpendio(QIconViewItem *);
	void S_CreaEspacioExpendioActual();
signals:
	void SignalTerminar(QWidget *);
};


extern "C" QCtrExpendios *InstanciaCtrExpendios(void *,
						char **,
						void *,
						const char *,
						int );

#endif 
