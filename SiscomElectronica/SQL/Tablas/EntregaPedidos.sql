create table PuntosEntrega(IdPuntoEntrega integer primary key,
			   Nombre varchar(128) unique);

----
---   Tipo Entrega  
---    0 -> Punto de entrega Siscom 
---    1 -> Direccion del cliente
---    
--- Nombre Se inserta el punto de Entrega SISCOM o nulo si es la 
--- direccion del cliente
--- IdDireccion , es el identificador en tipo persona, de la tabla de 
--- direcciones 

create table DireccionEntrega(IdVenta integer primary key references pedidoCliente(idventa),
			      IdDireccion integer,
			      Nombre varchar(128),
			      TipoEntrega integer);


create table HorarioPuntoEntrega(IdHorario integer primary key,
				 IdPuntoEntrega integer 
				 references PuntosEntrega(IdPuntoEntrega),
				Hora time , unique(IdPuntoEntrega,Hora));


create table PedidoHorarioPuntoEntrega(
				idVenta integer ,
				IdPuntoVenta integer references PuntosEntrega(IdPuntoEntrega),
				IdHorario integer references HorarioPuntoEntrega(IdHorario));

create table AccionEstadoPedido(IdEdoPedido integer references estadospedido(IdEdoPedido),
				Accion varchar(128));
				       

