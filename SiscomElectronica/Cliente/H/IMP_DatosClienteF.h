#ifndef __IMP_DATOSCLIENTEF_H__
#define __IMP_DATOSCLIENTEF_H__

#include <UIC_H_DatosClienteF.h>
#include <DatosClienteF.h>
class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QTable;
class QPushButton;
class SiscomDatCom;


class QDatosClienteF : public  DatosClienteF
{
    Q_OBJECT

public:
    QDatosClienteF(SiscomDatCom *,char **, QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~QDatosClienteF();
private:
	SiscomDatCom *SisDatCom;
	char **chrPtrArgumentos;
	DatosClienteFrec DatClienteFrec;
private:
	void IniciaVariables();
	void ConectaSlots();
	void ConsultaDatosRegistrados();
	void ModificaRegistros(const char *);
	void closeEvent(QCloseEvent *);
	
private slots:
	void S_PasaFocoLimSuperior();
	void S_PasaFocoDescuento();
	void S_PasaFocoAnexar();
	void S_PasaFocoNumDias();
	void S_Registrar();
	void S_Anexar();
	void S_Actualiza();
	void S_Eliminar();
signals:
	void SignalTerminar(QWidget *);
};
extern "C" QDatosClienteF *InstanciaDatosClienteF(void *,char **,void *,const char *,int);
#endif 
