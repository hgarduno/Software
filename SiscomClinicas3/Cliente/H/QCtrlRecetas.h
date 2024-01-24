#ifndef __QCTRLRECETA_H__
#define __QCTRLRECETA_H__
#include <qwidget.h>
#include <qwidgetplugin.h>
#include <qiconview.h>
#include <CQSisRecetas.h>


class QHBoxLayout;
class QTabWidget;
class QSisReceta;
class SiscomDatCom;
class CQSisConsulta;

class QT_WIDGET_PLUGIN_EXPORT QCtrlRecetas: public QWidget
{
    Q_OBJECT
public:
    QCtrlRecetas( QWidget *parent = 0, const char *name = 0);
    void IniciaControl();
    void PonServidor(SiscomDatCom *);
    void Consulta(CQSisConsulta *);
    void setFocus();
    void OtroFolio();
    int Recetas();
    static int HayRecetas(SiscomDatCom *,const char *);
    
private:
	void IniciaVariables();
	void ConsultaRecetas();
	void MuestraRecetas();
	void ConectaSlots();
	void CargaRecetaVacia();
	QSisReceta *CreaReceta();
	QSisReceta *CreaReceta(CQSisReceta *);
private:
	QHBoxLayout *QHBLayout;
	SiscomDatCom *SisDatCom;
	CQSisLstReceta  CQSLReceta;
	QTabWidget *QTWRecetas;
	CQSisConsulta *CQSConsulta;
	int intNumWidgets;

private slots:
	void SlotCambiaFolio(const QString &,int);
	void SlotRegistroReceta(QSisReceta *);
signals:
	void SignalRegistroReceta(QSisReceta *);
};

#endif

