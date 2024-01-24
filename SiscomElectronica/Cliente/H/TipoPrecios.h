#ifndef __TIPOPRECIOS_H__
#define __TIPOPRECIOS_H__
#include <SISCOMComunicaciones++.h>
#include <qptrlist.h>
#include <qwidget.h>

class QTextEdit;
class QComboBox;
class TipoPrecio:public SiscomInformacion
{
public:
	TipoPrecio(const char *,
		const char *);
private:
	void IniciaRegistro();

};

class TipoPrecios:public QPtrList<TipoPrecio>
{

	public:
		TipoPrecios();
	        TipoPrecios &operator<<(TipoPrecio *);
};

class OpTipoPrecios
{
public:
	OpTipoPrecios(SiscomDatCom *);
	void ConsultaTipoPrecios(TipoPrecios &);

private:
	SiscomDatCom *SisDatCom;
private:
	void GeneraTipoPrecios(const SiscomComunicaSrv*,TipoPrecios &);
};

class ManTipoPrecio:public QWidget
{
	Q_OBJECT
public:
	ManTipoPrecio(SiscomDatCom *,
		      QComboBox *,
		      QLineEdit *,
		      QTextEdit *,
		      QWidget *,
		      const char *);
	TipoPrecio *ObtenTipoPrecio(int);
private:
	SiscomDatCom *SisDatCom;
	QComboBox *QCBTipoPrecio;
	QLineEdit *QLECTipoPrecio;
	QTextEdit *QLEDescripcion;
	TipoPrecios TTipoPrecios;
private:
	void Consulta();
	void ConectaSlots();
private slots:

	void S_SeleccionoTipoPrecio();
signals:
	void SignalTipoPrecio(TipoPrecio *);

};
#endif
