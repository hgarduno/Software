#include <CQSisWidgetPedidoExpendio.h>
/* Queretaro a 18 de Noviembre del 2015 
 * Se iba a utilizar esto, para mostrar 
 * los pedidos por expendio, al final 
 * solo se colocara el filtro de fecha 
 * todo esto, para no alterar el flujo que
 * ya se tenia
 */
CQSisWidgetPedidoExpendio::CQSisWidgetPedidoExpendio(QWidget *pQWParent,
						     const char *pchrPtrName):
						    QTable(pQWParent,pchrPtrName)
{
 setNumCols(3);
 setNumRows(10);
}
