create table TicketImpreso(
		idCaja integer references cajas(idCaja),
		idVenta integer unique,
		Fecha timestamp without time zone);
create table TicketImpresoHistorial(
		idVenta integer references TicketImpreso(IdVenta),
		fecha timestamp without time zone,
		Cantidad numeric(10,2),
		CveProducto varchar(25) references productos(cveproducto),
		Precio numeric(10,2),
		Importe numeric(10,2));
create table TicketImpresoTotal(
		idVenta integer references TicketImpreso(idVenta),
		Total numeric(10,2),
		primary key(idVenta));
