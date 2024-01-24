#ifndef __CQSISWIDGETPEDIDOEXPENDIO_H__
#define __CQSISWIDGETPEDIDOEXPENDIO_H__
#include <qtable.h>


class CQSisWidgetPedidoExpendio:public QTable
{
Q_OBJECT
	public:
		CQSisWidgetPedidoExpendio(QWidget *pQWParent,
					  const char *pchrPtrName);
};

#endif
