
#ifndef __IMP_HISTORIALTRANSFERENCIAS_H__
#define __IMP_HISTORIALTRANSFERENCIAS_H__
#include <UIC_H_HistorialTransferencias.h>
#include <SiscomRegistros3.h>
class SiscomDatCom;
class EmpresaN;
class QHistorialTransferencias:public HistorialTransferencias
{
 Q_OBJECT
public:
	QHistorialTransferencias(SiscomDatCom *,
	    char **,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    WFlags pWFlags=0);
	~QHistorialTransferencias();
private:
	SiscomDatCom *SisDatCom;
	char **chrPtrArgumentos;
	SiscomRegistro3Lst SisReg3LstTransferencias;
	SiscomRegistro3 *SiscomRegProTransferencia;
	EmpresaN *EExpendio;
private:
	void ConectaSlots();
	void IniciaVariables();
	void Consultando();
	void Consulta();
	void Muestra();
	void closeEvent(QCloseEvent *);
	void ReEnviandoTransferencia();
private slots:
	void S_PasaFocoFechaFin();
	void S_PasaFocoEjecuta();
	void S_Consulta();
	void S_SeleccionaTransferencia(int,int,int ,const QPoint &);
	void S_ReEnviaTransferencia();
	void S_SeleccionaExpendio();
signals:
	void SignalTerminar(QWidget *);
};
extern "C" QHistorialTransferencias *InstanciaHistorialTransferencias(void *,char **,void *,const char *,int);
#endif
