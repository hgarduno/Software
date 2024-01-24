#include <SiscomTableItemColor.h>

SiscomTableItemColor::SiscomTableItemColor(QTable *pQTable,
				   const QColor &pQCColor,
				   EditType pQEType,
				   const QString &pQTexto):
	  QTableItem(pQTable,pQEType,pQTexto),
	  QCColor(pQCColor)
{

}

void SiscomTableItemColor::paint(QPainter *pQPainter,
			     const QColorGroup &pQCGDato,
			     const QRect &pQRArea,
			     bool pbSelect)
{
	QColorGroup g(pQCGDato);
	g.setColor(QColorGroup::Base,QCColor);
	QTableItem::paint(pQPainter,
			  g,
			  pQRArea,
			  pbSelect);
}
