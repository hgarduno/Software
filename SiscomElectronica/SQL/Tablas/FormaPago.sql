create table PagoTransferencia(IdVenta integer references ImporteOrden(IdVenta),
			       Telefono varchar(12),
			       SeReflejo integer,
			       Observaciones text, primary key(IdVenta));

create table PagoTarjeta(IdVenta integer references ImporteOrden(IdVenta),
			 Observaciones text, primary key(IdVenta));
