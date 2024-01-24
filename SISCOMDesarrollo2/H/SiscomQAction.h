#ifndef __SISCOMQACTION_H__
#define __SISCOMQACTION_H__

#include <qaction.h>

class SiscomDatCom;
class SiscomQAction:public QAction
{
Q_OBJECT
public:
	SiscomQAction(QObject *pQOParent,const char *pchrPtrNombre,void *pvidPtrIconos);
	void SiscomMuestraIcono();
	void NombreClase(const char *pchrPtrNmbClase);
	void Texto(const char *pchrPtrTexto);
	void Icono(const char *pchrPtrIcono);
	void Funcion(const char *pchrPtrFuncion);
	void Modulo(const char *pchrPtrModulo);
	void Argumentos(char **pchrPtrArgumentos);
	void Comunicaciones(SiscomDatCom *pSisDatCom);

	void ObtenTexto(char *pchrPtrTexto);
	void ObtenIcono(char *pchrPtrIcono);
	void ObtenModulo(char *pchrPtrModulo);
	void ObtenFuncion(char *pchrPtrFuncion);
private:
	void *SiscomObtenFuncionIcono();
private:
	char chrArrNmbClase[256];
	char chrArrTexto[256];
	char chrArrIcono[256];
	char chrArrModulo[256];
	char chrArrFuncion[256];

	char **chrPtrArgumentos;
	SiscomDatCom *SisDatCom;
	void *vidPtrIconos;
signals:
	void SignalSelecciono(SiscomQAction *);
public slots:
	void SlotSelecciono();
};
#endif
