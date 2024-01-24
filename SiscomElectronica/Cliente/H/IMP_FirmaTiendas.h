#ifndef __IMP_FIRMATIENDAS_H__
#define __IMP_FIRMATIENDAS_H__

#include <UIC_H_FirmaTiendas.h>

#include <qiconview.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QIconView;
class QIconViewItem;
class QPushButton;
class SiscomDatCom;
class EmpresaN;
class Persona;
class QApplication;
class QFirmaTiendas : public FirmaTiendas
{
    Q_OBJECT

public:
    QFirmaTiendas(QApplication *pQAPrincipal,
    		  QWidget* parent = 0,const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~QFirmaTiendas();
	SiscomDatCom *ObtenServidor();
	EmpresaN *ObtenExpendio();
	Persona *ObtenEmpleado();
private:
	void ConectaSlots();
	int CargaArchivo();
	void MuestraServidores();
	void AnexaServidor(const char *);
	void ConsultaExpendios();
	void ConsultaEmpleadosExpendio();
	void AlmacenaPerfil();
	void CargaPerfil();

private:
	char chrArrArchivo[1024];
	SiscomDatCom *SisDatCom;
	EmpresaN *Expendio;
	Persona *Empleado;
	int intArchivoServidores;
	QApplication *QAPrincipal;
	QWidget *QWParent;
	QFont QFLetra;
	int intModificoPerfil;
private slots:
	void S_AnexarServidor();
	void S_EliminarServidor();
	void S_Aceptar();
	void S_SeleccionoServidor(QIconViewItem *);
	void S_SeleccionoExpendio(QIconViewItem *);
	void S_SeleccionaEmpleado(QIconViewItem *);

	void S_SeleccionarLetra();
};


class QServidoresIconView:public QIconViewItem
{
public:
	QServidoresIconView(SiscomDatCom *,
			    QIconView *,
			    const char *);
	SiscomDatCom *ObtenServidor();
private:
	SiscomDatCom *SisDatCom;
};

class QEmpleadosExpendioIconView:public QIconViewItem
{
public:
	QEmpleadosExpendioIconView(Persona *,
				   QIconView *,
				   const char *);
	Persona *ObtenEmpleado();
private:
	Persona *Empleado;
};
#endif 
