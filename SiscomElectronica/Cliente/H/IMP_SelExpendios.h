#ifndef __IMP_SELEXPENDIOS_H__
#define __IMP_SELEXPENDIOS_H__

#include <UIC_H_SelExpendios.h>
#include <qiconview.h>
#include <EmpresasN.h>
class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QIconView;
class QIconViewItem;
class SiscomDatCom;
class QIconViewItem;
class EmpresaN;
class QSelExpendios : public SelExpendios
{
    Q_OBJECT

public:
    QSelExpendios(SiscomDatCom *,
    		  QWidget* parent = 0,
		  const char* name = 0,
		  bool modal = FALSE,
		  WFlags fl = 0 );
    ~QSelExpendios();
    EmpresaN *ObtenExpendio();
private:
	void ExpendiosDisponibles();
	void ConectaSlots();
private:
	SiscomDatCom *SisDatCom;
	EmpresaN *Expendio;
	EmpresasN Expendios;
private slots:
	void S_SeleccionoExpendio(QIconViewItem *);
};

class QIconVExpendio:public QIconViewItem
{
public:
	QIconVExpendio(EmpresaN *,QIconView *);
	EmpresaN *ObtenExpendio();
private:
	EmpresaN *Empresa;
};
#endif 
