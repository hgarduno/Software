create table Transferencias(IdTransferencia integer unique,
		    IdTienda integer references Tiendas(IdTienda),
		    IdAlmacenista integer references Almacenistas(IdAlmacenista),
		    FechaHora timestamp without time zone);

create table TransporteTransferencia(IdTransferencia integer references Transferencias(IdTransferencia),
			    IdChofer integer references Choferes(IdChofer),
			    IdCamion integer references Camiones(IdCamion));

create table DetalleTransferencia(IdTransferencia integer references Transferencias(IdTransferencia),
			    	  IdProducto integer references Productos(IdProducto),
			    	  cantidad integer,
				  EsStock integer);

create table EstadoTransferencia(IdTransferencia integer references Transferencias(IdTransferencia),
                IdEstado integer,
                FechaHora timestamp without time zone);

create table ObservacionTransferencia(IdTransferencia integer references Transferencias(IdTransferencia),
                observacion varchar(128));

create table ObservacionProductos(IdTransferencia integer references Transferencias(IdTransferencia),
                IdProducto integer references Productos(IdProducto),
                observacion varchar(128));

create table DetalleTransferenciaDevolucion(IdTransferencia integer references Transferencias(IdTransferencia),
			    IdProducto integer references Productos(IdProducto),
			    cantidad integer);


create table ProductoStock(IdProducto integer  unique references productos(idproducto));
