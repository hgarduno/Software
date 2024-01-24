create table ImpresionesTicket(IdVenta integer references TicketImpreso(IdVenta),
				IdImpresion integer primary key,
			       fecha timestamp without time zone);
create table ImpresionTicketTotal(IdImpresion integer references ImpresionesTicket(IdImpresion),
				  Total numeric(10,2));
create table ImpresionTicketHistorial(IdImpresion integer references ImpresionesTicket(IdImpresion),
				      Cantidad numeric(10,2),
				      CveProducto varchar(30),
				      Precio numeric(10,2),
				      Importe numeric(10,2));

