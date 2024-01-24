#ifndef __IMP_FAMILIAS_H__
#define __IMP_FAMILIAS_H__

#include <UIC_H_Familias.h>
#include <Familias.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QLineEdit;
class QTable;
class QPushButton;
class SiscomDatCom;
class QFamilias : public FamiliasQ
{
    Q_OBJECT

public:
    QFamilias(SiscomDatCom *,
    		char **,
    	      QWidget* parent = 0,
	      const char* name = 0,
	      WFlags fl = 0 );
    ~QFamilias();
private:
	SiscomDatCom *SisDatCom;
	char **chrPtrArgumentos;
	Familias FFamilias;
private:
	void ConsultaFamilias();
	void ConectaSlots();
	void closeEvent(QCloseEvent *);
private slots:
	void S_Anexar();
	void S_Registrar();
	void S_CambiaDatosFamilia(int,int,int,const QPoint &);
	
signals:
	void SignalTerminar(QWidget *);
};

extern "C" QFamilias *InstanciaFamilias(void *,char **,void *,const char *,int);
#endif 
