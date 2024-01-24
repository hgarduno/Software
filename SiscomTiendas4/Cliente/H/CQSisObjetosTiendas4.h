#ifndef __CQSISOBJETOSTIENDAS4_H__
#define __CQSISOBJETOSTIENDAS4_H__
class CQSisEmpresa;
class CQSisContacto;
class CQSisFormaPago;
class CQSisProducto;
class CQSisFamilia;
class CQSisCompra;
class CQSisCliente;
class CQSisRepVenta;
class CQSisOrden;
class CQSisPrecio;
class CQSisContacto;
class CQSisPedido;
class CQSisProdCotiza;
class CQSisLstProdCotiza;
class CQSisLstPedido;
class SiscomRegistrosPro2;
class ObjetosTiendas4
{
public:
	ObjetosTiendas4();
static  CQSisEmpresa *Empresa(SiscomRegistrosPro2 *);
static  CQSisContacto *Contacto(CQSisEmpresa *,SiscomRegistrosPro2 *);
static  CQSisFormaPago *FormaPago(SiscomRegistrosPro2 *);
static	CQSisProducto *Producto(SiscomRegistrosPro2 *);
static	CQSisCompra *Compra(SiscomRegistrosPro2 *);
static  CQSisCliente *Cliente(SiscomRegistrosPro2 *);
static  CQSisRepVenta *ReporteVenta(SiscomRegistrosPro2 *);
static  CQSisOrden *Orden(SiscomRegistrosPro2 *);
static  CQSisPrecio *Precio(SiscomRegistrosPro2 *);
static  CQSisContacto *Contacto(SiscomRegistrosPro2 *);
static  CQSisProdCotiza *ProdCotiza(SiscomRegistrosPro2 *);
static  void ProdsCotiza(SiscomRegistrosPro2 *,CQSisLstProdCotiza *);

static CQSisPedido *Pedido(SiscomRegistrosPro2 *);
static void Pedidos(SiscomRegistrosPro2 *,CQSisLstPedido *);


};


#endif
