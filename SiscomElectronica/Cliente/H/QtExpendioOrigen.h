#ifndef __QTEXPENDIO0RIGEN_H__
#define __QTEXPENDIOORIGEN_H__
#include <UIC_H_ExpendioOrigen.h>



class SiscomRegistro3;
class SiscomDatCom;
class zEmpresa;
class QtExpendioOrigen:public ExpendioOrigen
{
Q_OBJECT
public:
	QtExpendioOrigen(SiscomDatCom *,char **,QWidget *,const char *,bool,WFlags);
	SiscomDatCom *Conexion();
	char **Argumentos();
	zEmpresa *Expendio();

private:
	SiscomDatCom *SisDatCom;
	char **chrPtrArgumentos;
	zEmpresa *zEmExpendio;


private:
	void IniciaControles();
	void IniciaVariables();
	void ConectaSlots();
	void Expendio(zEmpresa *);
private slots:
	void SlotExpendio(SiscomRegistro3 *);
	void SlotAceptar();

};

#endif
