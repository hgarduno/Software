#ifndef __IMP_EMPLEADOSEXPENDIO_H__
#define __IMP_EMPLEADOSEXPENDIO_H__

#include <UIC_H_EmpleadosExpendio.h>
#include <Personas.h>
#include <EmpresasN.h>
class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QTable;
class QIconView;
class QIconViewItem;
class QPushButton;
class SiscomDatCom;

class QEmpleadosExpendio : public  EmpleadosExpendio
{
    Q_OBJECT

public:
    QEmpleadosExpendio(SiscomDatCom *,
    		       char **,
    		       QWidget* parent = 0,
		       const char* name = 0,
		       WFlags fl = 0 );
    ~QEmpleadosExpendio();
private:
	void ConsultaUsuariosSeguridad3();
	void ConsultaExpendios();
	void ConectaSlots();
	int ObtenFirmaAValidar(char *);
	void closeEvent(QCloseEvent *);
private:
	SiscomDatCom *SisDatCom;
	Personas PPersonas;
	EmpresasN Expendios;
	EmpresaN *Expendio;
	Persona *PFirma;
private slots:
	void S_ValidaEmpleado();
	void S_AsignaEmpleado();
	void S_SeleccionoExpendio(QIconViewItem *);
signals:
	void SignalTerminar(QWidget *);
};

extern "C" QEmpleadosExpendio *InstanciaEmpleadosExpendio(
				void *,
				char **,
				void *,
				const char *,
				int );
		
#endif 
