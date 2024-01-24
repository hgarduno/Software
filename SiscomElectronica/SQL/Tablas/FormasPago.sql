create table Transferencia(IdVenta integer references importeorden(IdVenta),
			   IdTransferencia integer unique);

create table PagoTarjeta(IdVenta integer references importeorden(IdVenta),
		         IdPagoTarjeta integer unique,
			 ConsecutivoTerminal integer ,
			 Descripcion text);
			    
