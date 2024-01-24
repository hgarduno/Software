#ifndef __IMP_BUSCAEMPRESAS_H__
#define __IMP_BUSCAEMPRESAS_H__

#include <UIC_H_BuscaEmpresas.h>
#include <CQSiscomCom.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QComboBox;
class QPushButton;
class QLineEdit;
class CSISCOMDatComunicaciones;
class CQSeleccionaProveedor;
class Empresa;

class QBuscaEmpresas : public BuscaEmpresas
{
    Q_OBJECT

public:
    QBuscaEmpresas(CSISCOMDatComunicaciones *, QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~QBuscaEmpresas();
SISCOMGlobales::BTN_Captura ObtenSeleccion();
Empresa *ObtenEmpresa();
private:
CSISCOMDatComunicaciones *CSisDatCom;
CQSeleccionaProveedor *CQSProveedor;
QLineEdit *QLECRazonSocial;
Empresa *E_EmpresaSel;
SISCOMGlobales::BTN_Captura Opcion;
private:
	void ConectaSlots();
	void IniciaVariables();
private slots:
	void S_SeleccionoEmpresa(Empresa *);
	void S_Aceptar();
	void S_Cancelar();
};

#endif 
