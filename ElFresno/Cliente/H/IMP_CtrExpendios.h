#ifndef __IMP_CTREXPENDIOS_H__
#define __IMP_CTREXPENDIOS_H__

#include <UIC_H_CtrExpendios.h>
#include <qiconview.h>
#include <Empresas.h>
#include <GeneralBibliotecaSeguridad3.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QPushButton;
class QIconView;
class QIconViewItem;
class CSISCOMDatComunicaciones;
class Empresa;
class QRegistraExpendios;
class SiscomDatCom;

class QCtrExpendios : public CtrExpendios,
		      private QSiscomSeguridad3
{
    Q_OBJECT

public:
    QCtrExpendios(CSISCOMDatComunicaciones *, QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~QCtrExpendios();
private:
    CSISCOMDatComunicaciones *CSisDatCom;
    QRegistraExpendios *QRExpendios;
    QWidget *QWParent;
    CQEmpresas CQ_Empresas;
    Empresa *E_Expendio;
    Empresa *E_Matriz;
    SiscomDatCom *SisDatCom;

private:
	void ConectaSlots();
	void ConsultaExpendios();
	void ConsultaMatriz();
	int ValidaSeleccionExpendio();
private slots:
	void S_RegistraExpendio();
	void S_RegistroElExpendio();
	void S_RegistraCompraDelExpendio();
	void S_SeleccionoExpendio(QIconViewItem *);
	void S_IniciaVentasExpendio();
	void S_MarcaMatriz();
	void S_Actualizar();
	void S_VentasExpendio();
	void S_FijaFechaCorte();
	void S_VentasFechaCorte();
};
class QIconViewItemExpendio:public QIconViewItem
{
public:
	QIconViewItemExpendio(Empresa *,QIconView *);
	Empresa *ObtenEmpresa();
private:
	Empresa *E_Empresa;
private:
	void MuestraDatosGenerales();

};
extern "C" QCtrExpendios *InstanciaCtrExpendios(void *,void *,const char *,int);
#endif 
