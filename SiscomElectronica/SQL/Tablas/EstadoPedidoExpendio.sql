create table EstadoPedidoExpendioProducto(IdPedido integer references PedidosMaterial(IdPedido),
					  IdProducto integer ,
					  Estado integer);
