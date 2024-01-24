
#ifndef __IMP_CLIENTES_H__
#define __IMP_CLIENTES_H__
#include <UIC_H_Clientes.h>
#include <Personas.h>
#include <Direcciones.h>
#include <MediosComunicacion.h>
class SiscomDatCom;
class QClientes:public Clientes
{
 Q_OBJECT
public:
	QClientes(SiscomDatCom *,
	    char **,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    WFlags pWFlags=0);
	~QClientes();
private:
	SiscomDatCom *SisDatCom;
	char **chrPtrArgumentos;
	QLineEdit *QLECEstados;
	Persona *PCliente;
	Direcciones DCliente;
	MediosComunicacion MCCliente;
	int intDireccionActual;
	QListViewItem *QLVITelefono;
private:
	void ConectaSlots();
	void IniciaVariables();
	void MuestraDireccion(Direccion *);
	void closeEvent(QCloseEvent *);
private slots:
	void S_PasaFocoAPaterno();
	void S_PasaFocoAMaterno();
	void S_PasaFocoRFC();
	void S_PasaFocoCalle();
	void S_PasaFocoNo();
	void S_PasaFocoCP();
	void S_PasaFocoColonia();
	void S_PasaFocoMunicipio();
	void S_PasaFocoEstado();
	void S_PasaFocoTelefono();
	void S_PasaFocoDescripcion();
	void S_PasaFocoAnexarTelefono();
	void S_CambioPestana(QWidget *);
	void S_AnexarDireccion();
	void S_SiguienteDireccion();
	void S_DireccionAnterior();
	void S_ModificarDireccion();
	void S_EliminarDireccion();
	void S_AnexarTelefono();
	void S_SeleccionaTelefono(QListViewItem *);
	void S_EliminaTelefono();
signals:
	void SignalTerminar(QWidget *);
};
extern "C" QClientes *InstanciaClientes(void *,char **,void *,const char *,int);
#endif
