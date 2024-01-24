#ifndef __IMP_UNIDADES_H__
#define __IMP_UNIDADES_H__

#include <UIC_H_Unidades.h>
#include <Unidades.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QPushButton;
class QTable;
class QLabel;
class QLineEdit;
class CSISCOMDatComunicaciones;
class CQSeleccionaUnidades;
class SiscomDatCom;

class QUnidades : public Unidades
{
    Q_OBJECT

public:
    QUnidades(CSISCOMDatComunicaciones *,
	      QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~QUnidades();
private:
	CSISCOMDatComunicaciones *CSisDatCom;
	SiscomDatCom *SDatCom;
	CQUnidades CQ_Unidades;
private:
	void IniciaVariables();
	void ConectaSlots();
	void ConsultaUnidades();
private slots:
	void S_PasaFocoAbreviatura();
	void S_PasaFocoAnexar();
	void S_Anexar();	
	void S_Registrar();
	void S_SeleccionaUnidad(int,int,int,const QPoint &);
	void S_ModificaUnidad(int,int,int,const QPoint &);
};
extern "C" QUnidades *InstanciaUnidades(void *,void *,const char *,int );
#endif 
