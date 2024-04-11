/****************************************************************************
** Form interface generated from reading ui file 'UI/CapturaObservacionPedidoProducto.ui'
**
** Created: Wed Apr 10 20:52:30 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef CAPTURAOBSERVACIONPEDIDOPRODUCTO_H
#define CAPTURAOBSERVACIONPEDIDOPRODUCTO_H

#include <qvariant.h>
#include <qdialog.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QTextEdit;
class QPushButton;

class CapturaObservacionPedidoProducto : public QDialog
{
    Q_OBJECT

public:
    CapturaObservacionPedidoProducto( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~CapturaObservacionPedidoProducto();

    QLabel* textLabel1;
    QTextEdit* QTEObservaciones;
    QPushButton* QPBAceptar;
    QPushButton* QPBCancelar;

protected:
    QGridLayout* CapturaObservacionPedidoProductoLayout;
    QVBoxLayout* layout10;

protected slots:
    virtual void languageChange();

};

#endif // CAPTURAOBSERVACIONPEDIDOPRODUCTO_H
