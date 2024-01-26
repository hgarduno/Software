#ifndef __QTBASEMEDIDAS_H__
#define __QTBASEMEDIDAS_H__
#include <qwidget.h>

class QPainter;
class QFont;
class zSiscomRegistro;
class zSiscomRegistros;
class zImpresion;
class QtBaseMedidas
{
public:
	QtBaseMedidas(QWidget *pQWParent,
		      const char *pchrPtrName);
	void Letra(const QFont &pQFLetra);
	void Painter(QPainter *);
	void InicializaMedidas();
	void MargenX(int pintMargenX);
	void MargenY(int pintMargenY);
	int MMx(int pintX);
	int MMy(int pintX);	
	int MM(int pintMMx);
	int Texto(int pintX,
		   int pintY,
		   int pintEspacioDisponibleX,
		   int pintEspacioDisponibleY,
		   const char *pchrPtrTexto);
	int Texto(zSiscomRegistro *pzSisRegInfoTexto,zImpresion *pzImpresion);
	int Texto(int pintDesplazamientoY,
		   zSiscomRegistros *pzSisRegCampos,
		   zSiscomRegistro *pzSisRegRegistro);
	int TextoXY(int pintDesplazamientoX,
		     int pintDesplazamientoY,
		   zSiscomRegistros *pzSisRegCampos,
		   zSiscomRegistro *pzSisRegRegistro);
	/* Busca en pzSisRegsPosiciones , en el campo pchrPtrCampo,
	 * el dato pchrPtrDato, para sacar la posicion y escribir ahi pchrPtrCadena
	 */
	int Texto(int pintDesplazamiento,
		   zSiscomRegistros *pzSisRegsPosiciones,
		   const char *pchrPtrCampo,
		   const char *pchrPtrDato,
		   const char *pchrPtrCadena);
	void NumeroPagina(int *pintPtrY);
	int SePoneNumeroPagina(int pintY);
		   
	~QtBaseMedidas();
private:
	void TextoConUnCaracterMenos(char *pchrPtrTexto);
	int EsDispositivoExterno();
private:
	QPaintDeviceMetrics *QPaintDeviceMedidas;
	QPainter *QPainterDibuja;
	QFont QFLetra;
	int intMargenX;
	int intMargenY;
	int intPaginas;

};


#endif 
