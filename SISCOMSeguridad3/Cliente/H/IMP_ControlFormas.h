#ifndef __CQSISCONTROLFORMAS_H__
#define __CQSISCONTROLFORMAS_H__
#include <UIC_H_ControlFormas.h>

#include <GeneralBibliotecaSeguridad3.h>
#include <qiconview.h>
#include <qlistview.h>
class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QIconView;
class QIconViewItem;
class CSISCOMDatComunicaciones;
class CQSisMOperaciones;
class CQSisIconViewContF:public QIconViewItem
{
	public:
	     CQSisIconViewContF(QSiscomObjetosSeguridad *,QIconView *);	
	     void MuestraControles();
	private:
	     QSiscomObjetosSeguridad *QSisObjSeguridad;
};
class CQSisListViewItemFormas:public QListViewItem
{
	public:
		CQSisListViewItemFormas(QSiscomObjetosSeguridad *,
					QListView *,
					QString );
	private:
	     QSiscomObjetosSeguridad *QSisObjSeguridad;

};
class CQSisListViewItemConXForma:public QListViewItem
{
	public:
		CQSisListViewItemConXForma(QSiscomObjetosQT *,
					   QListViewItem *,
					   QString );
	private:
		QSiscomObjetosQT *QSisObjQT;

};
class CQSisListViewItemPropiedadesObj:public QListViewItem
{
	public:
		CQSisListViewItemPropiedadesObj(QSiscomPropiedadesBD *,
					        QListViewItem *,
						QString );
	private:
		QSiscomPropiedadesBD *QSisPropObjBD;

};
class CQSisListViewItemValorPropiedad:public QListViewItem
{
	public:
		CQSisListViewItemValorPropiedad(QSiscomPropiedadesBD *,
						QListViewItem *,
						QString );
		QSiscomPropiedadesBD *ObtenPropiedades();
	private:
		QSiscomPropiedadesBD *QSisPropObjBD;
		const char *chrPtrNmbClase;
};
typedef QPtrList<QSiscomObjetosSeguridad> QSiscomListaObjSeguridad;
class CQSisControlFormas : public ControlFormas
{
    Q_OBJECT

public:
    CQSisControlFormas(QStringList ,
		       CSISCOMDatComunicaciones *,
		       QString , QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    CQSisControlFormas(QSiscomListaContXForma  ,
		       CSISCOMDatComunicaciones *,
		       QString , QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~CQSisControlFormas();
	QSiscomListaObjSeguridad ObtenObjetos();
private:	
	QStringList QSLArchivos;
	CSISCOMDatComunicaciones *CSisDatCom;
	QPtrList<QSiscomObjetosSeguridad> QPLObjetos;
	QString QSAplicacion;
	CQSisMOperaciones *CQSMOperaciones;
	const char *chrPtrFormaAAnexarOE;
private:
	void showEvent(QShowEvent *);
	void focusInEvent(QFocusEvent *);
	void mouseReleaseEvent(QMouseEvent *);
	void ConectaSlots();
	void CargaArchivo(QString );
	void CargaArchivos();
	void MuestraFormas();
	void ColocaControlesXForma(CQSisListViewItemFormas *,QSiscomObjetosSeguridad *);
	void ColocaPropiedadesXObjeto(CQSisListViewItemConXForma *,QSiscomObjetosQT *);
	void AnexaControlesEnTiempoDeEjecucion(const char *,QSiscomListaObjQ );
	void CapturaDatoPropiedad(QSiscomPropiedadesBD *,QListViewItem *);
	void CapturaIcono(QSiscomPropiedadesBD *,QListViewItem *);
public slots:
	void SlotSeleccionoItem(QListViewItem *,const QPoint &,int );
	void SlotMenuOperaciones(QListViewItem *,const QPoint &,int );
	void SlotAnexarObjetos();
};

#endif 
