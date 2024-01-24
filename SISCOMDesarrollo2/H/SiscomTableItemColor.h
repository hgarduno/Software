#ifndef __SISCOMTABLEITEMCOLOR_H__
#define __SISCOMTABLEITEMCOLOR_H__
#include <qtable.h>

class SiscomTableItemColor:public QTableItem
{
public:
	SiscomTableItemColor(QTable *,
				const QColor &, 
				EditType ,
				const QString &);
	void paint(QPainter *,const QColorGroup &,const QRect &,bool );
private:
	const QColor QCColor;
};
#endif
