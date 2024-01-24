create table PedidoCliente(idVenta integer unique,
			   idEstado integer);

create table EstadosPedidoCliente(idVenta integer references PedidoCliente(IdVenta),
				  idEstado integer references EstadosPedido(idedopedido),
				  Fecha timestamp without time zone,
				  primary key(idVenta,idEstado));
			   
