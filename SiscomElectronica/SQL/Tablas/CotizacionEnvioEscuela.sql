create table CotizacionEnvioEscuela(IdVenta integer references Cotizacion(IdVenta),
			     	    IdEscuela integer references Escuelas(IdEscuela),
				    Hora time,
				    PagaCon numeric(10,3));

