#ifndef __QBARCODE_H__
#define __QBARCODE_H__

#include <qwidget.h>
#include <qpixmap.h>
#include <qimage.h>
#include <qlabel.h>

//Definiciones del formato 128B
#define inicioCodigo    104
#define finCodigo       106

#define PIXEL_BLANCO    0
#define PIXEL_NEGRO     1

class QBarCode : public QWidget
{
    Q_OBJECT
public:
    QBarCode( QWidget *parent = 0, const char *name = 0);
    QPixmap generaCodeBar128B(const char *, int, int);
    QPixmap generaCodeBar128BImprimir(const char *, int, int);
private:
    void ConectaSlots();
    void IniciaVariables();
private:
    QLabel *code;
public slots:
    void SlotMuestraCode(const QString &);
};

#endif
