#ifndef __QCTRLORIGENCOMPRA_H__
#define __QCTRLORIGENCOMPRA_H__ 
#include <qwidget.h>
#include <qwidgetplugin.h>
#include <SiscomRegistros3.h>
class QHBoxLayout;
class QComboBox;
class QLineEdit;
class SiscomDatCom;
class SiscomRegistro3;
class QT_WIDGET_PLUGIN_EXPORT QCtrlOrigenCompra : public QWidget
{
    Q_OBJECT
public:
    QCtrlOrigenCompra( QWidget *parent = 0, const char *name = 0);
    void IniciaControl();
    void Servidor(SiscomDatCom *);
    void setFocus();
    void Limpia();
    SiscomRegistro3 *OrigenCompraActual();
    
private:
	void IniciaVariables();
	void ConsultaOrigenCompra();
	void MuestraOrigenCompra();
	void ConectaSlots();

	void keyPressEvent(QKeyEvent *);
private:
	QHBoxLayout *QHBLayout;
	QComboBox *QCBOrigenCompra;
	QLineEdit *QLEOrigenCompra;
	SiscomDatCom *SisDatCom;
	SiscomRegistro3Lst SisReg3LstOrigenCompra;
	const char *chrPtrIdExpendio;
	int intOrigenCompra;
private slots:
	void SlotOrigenCompra(int );
signals:
	void SignalOrigenCompra(SiscomRegistro3 *);
};

#endif
