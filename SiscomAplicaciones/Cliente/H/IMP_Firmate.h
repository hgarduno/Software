
#ifndef __IMP_FIRMATE_H__
#define __IMP_FIRMATE_H__
#include <UIC_H_Firmate.h>
class SiscomDatCom;
class SisUsuarioSeg3;
class QFirmate:public Firmate
{
 Q_OBJECT
public:
	QFirmate(SiscomDatCom *,
 	    SisUsuarioSeg3 *,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    bool pbModal=false,
	    WFlags pWFlags=0);
	~QFirmate();
	int ValidacionPassword();
private:
	SiscomDatCom *SisDatCom;
	SisUsuarioSeg3 *SUsuarioSeg3;
	int intValidacionPassword;
	int intIntentos;
private:
	void ConectaSlots();
	void IniciaVariables();
	void MuestraUsuario();
	void closeEvent(QCloseEvent *);
	void ValidaFirma();
private slots:
	void SlotValidaFirma();
	void SlotPasaFocoAceptar();
	void SlotCancelar();
};
#endif
