#ifndef __IMP_FAMILIAS_H__
#define __IMP_FAMILIAS_H__

#include <UIC_H_Familias.h>
#include <Familias.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QPushButton;
class QLabel;
class QLineEdit;
class QTable;
class CSISCOMDatComunicaciones;
class SiscomDatCom;


class QFamilias : public Familias
{
    Q_OBJECT

public:
    QFamilias(CSISCOMDatComunicaciones *, QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~QFamilias();
private:
	CSISCOMDatComunicaciones *CSisDatCom;
	CQFamilias CQ_Familias;
	SiscomDatCom *SDatCom;
private:
	void ConectaSlots();
	void IniciaVariables();
	void ConsultaLasFamilias();
private slots:
	void S_Anexar();
	void S_Registrar();
	void S_PasaFocoDscFamilia();
	void S_PasaFocoAnexar();
	void S_SeleccionaFamilia(int,int,int,const QPoint &);
	void S_MantenFamilia(int,int,int,const QPoint &);
	
};
extern "C" QFamilias *InstanciaFamilias(void *,void *,const char *,int);
#endif 
