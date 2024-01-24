create table ApartadoEntregadoOtroDia(
			IdVenta integer references ImporteOrden(IdVenta) primary key,
			IdVentaPorEntregaOtroDia integer references ImporteOrden(IdVenta),
			fecha timestamp without time zone);
