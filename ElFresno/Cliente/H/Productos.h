#ifndef __PRODUCTOS_H__
#define __PRODUCTOS_H__
#include <Unidades.h>
#include <Familias.h>
#include <Precios.h>
#include <qobject.h>
class CSISCOMDatComunicaciones;
class CQOGenericaServidorSiscom;
class QLineEdit;
class QComboBox;

class Producto
{
public:
	Producto(const char *,const char *);
	void PonClave(const char *);
	void PonDescripcion(const char *);
	void PonEdoRegistro(const char *);
	void PonUnidad(Unidad *);
	void PonFamilia(Familia *);
	void PonPrecio(int,const char *);
	void PonPrecio(int,Precio *);
	void AnexaPrecio(Precio *);
	void AnexaPrecio(int,Precio *);
	void AnexaPrecios(const CQPrecios &);
	const char *ObtenClave();
	const char *ObtenDescripcion();
	const char *ObtenEdoRegistro();
	const CQPrecios &ObtenPrecios();
	Unidad *ObtenUnidad();
	Familia *ObtenFamilia();
	CQPrecios CQ_Precios;

private:
	Unidad *U_Producto;
	Familia *F_Producto;
	const char *chrPtrClave;
	const char *chrPtrDescripcion;
	const char *chrPtrEdoRegistro;

};

class CQProductos:public QPtrList<Producto>
{
public:
	CQProductos();

};
class CQCtrProductos
{
public:
	enum CtrProductos
	{
		Registrar,
		ConsultarClavesYDescripciones
	};
	CQCtrProductos(CSISCOMDatComunicaciones *,
			CtrProductos ,
			CQProductos *);
	CQCtrProductos(CSISCOMDatComunicaciones *,
			CtrProductos ,
			CQProductos *,
			const char *);
private:
        CQOGenericaServidorSiscom *CQOGSvrSiscom;
        CSISCOMDatComunicaciones *CSisDatCom;
        QStringList QSLRegistro;
        int intNumParametros;
        const char *chrPtrFormato;
	const char *chrPtrFamilia;
private:
	void RegistrarProductos(CQProductos *);
	void ConsultaLasClavesYDescripciones(CQProductos *);
	void AsignaRespuestaProductos(CQProductos *);
};

class CQSeleccionaProducto:public QObject
{
Q_OBJECT

public:
	CQSeleccionaProducto(CSISCOMDatComunicaciones *,
			     QWidget *,
			     const char *,
			     QLineEdit *,
			     QLineEdit *,
			     QLineEdit *,
			     QComboBox *);
	CQSeleccionaProducto(CSISCOMDatComunicaciones *,
			     QWidget *,
			     const char *,
			     QLineEdit *,
			     QLineEdit *,
			     QLineEdit *,
			     QComboBox *,
			     const char *);

private:
	void ConectaSlots();
	void LlenaComboProductos();
	void LlenaComboProductos(const char *);
	void MuestraInformacion(int);
private:
	QLineEdit *QLECProductos;
	QLineEdit *QLEDescripcion;
	QLineEdit *QLEAbreviatura;
	QComboBox *QCBProductos;
	CSISCOMDatComunicaciones *CSisDatCom;
	CQProductos CQ_Productos;
private slots:
	void S_SeleccionandoProducto(int );
	void S_SeleccionoProducto();
	void S_SeleccionoProducto(int);
signals:
	void Signal_SProducto(Producto *);
};
#endif
