
#ifndef __IMP_ACCESOSISCOMELECTRONICA_H__
#define __IMP_ACCESOSISCOMELECTRONICA_H__
#include <UIC_H_AccesoSiscomElectronica.h>
#include <SiscomRegistros4.h>
#include <qiconview.h>
class SiscomDatCom;
class EmpresaN;
class Persona;
class QApplication;
class SiscomRegistro3;
class CQSisExpendiosPorTipo:public SiscomRegistro4 
{
public:
	CQSisExpendiosPorTipo();
	void LeeArchivo(const char *);
	SiscomRegistro3Lst *Expendios(int pintTipoExpendio);
private:
	void AgregaTipoExpendio(const char *pchrPtrTipoExpendio);
	void AgregaExpendio(const char *pchrPtrLinea);
	SiscomRegistro3 *DatosExpendio(const char *pchrPtrLinea);
private:
	FILE *AbreArchivo(const char *);
};
class QAccesoSiscomElectronica:public AccesoSiscomElectronica
{
 Q_OBJECT
public:
	QAccesoSiscomElectronica(QApplication *,
			QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    bool pbModal=false,
	    WFlags pWFlags=0);
	~QAccesoSiscomElectronica();
	SiscomDatCom *Servidor();
	EmpresaN *ExpendioSeleccionado();
	SiscomRegistro3 *ExpendioRegistro3();
	Persona *EmpleadoFirmado();
	int Cancelo();
private:
	SiscomDatCom *SisDatCom;
	char **chrPtrArgumentos;
	CQSisExpendiosPorTipo CQSExpendios;
	EmpresaN *Expendio;
	Persona *Empleado;
	QApplication *QAPrincipal;
	QFont QFLetra;
	 QWidget *QWParent;
	 int intModificoPerfil;
	 int intCancelo;
private:
	void ConectaSlots();
	void IniciaVariables();
	void MuestraTiposExpendios();
	void MuestraServidores(int pintCuales);
	void MuestraExpendiosServidor(SiscomRegistro3 *pSisReg3Expendio);
	void MuestraEmpleadosExpendio(EmpresaN *pEmpresaN);
	void ConectandoIconView(const char *pchrPtrSlot);
	void ArchivoServidores(char *pchrPtrArchivo);
	void CargaPerfil();
	void AlmacenaPerfil();
	void reject();
private slots:
	void SlotTipoExpendio(QIconViewItem *pQIconViewItemDato);
	void SlotExpendio(QIconViewItem *pQIconViewItemExpendio);
	void SlotExpendioServidor(QIconViewItem *pQIconViewItemExpendioServidor);
	void SlotSeleccionaEmpleado(QIconViewItem *pQIconViewItempEmpleado);
	void SlotTipoLetra();
};

class QSisTipoExpendioIconViewItem:public QIconViewItem
{
public:	
	QSisTipoExpendioIconViewItem(SiscomRegistro3 *pSisReg3TipoExpendio,
				     int pintConsecutivo,
				     QIconView *pQIconViewDatos);
	int Consecutivo();
private:
	int intConsecutivo;
};
class QSisExpendioIconViewItem:public QIconViewItem
{
public:
	QSisExpendioIconViewItem(SiscomRegistro3 *pSisReg3Expendio,
				 QIconView *pQIconViewDatos);
	SiscomRegistro3 *Expendio();

private:
	SiscomRegistro3 *SisReg3Expendio;
};
#endif
