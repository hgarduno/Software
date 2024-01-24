create table PedidosMaterial(IdPedido integer unique,
		      	     Fecha	timestamp without time zone,
			     Observaciones	text,
			     IdExpendio	integer );
create table DetallePedidoMaterial(IdPedido integer references PedidosMaterial(IdPedido),
				   Cantidad	integer,
				   CveProducto	varchar(50),
				   Observacion	text);   

create table EstadoPedidoMaterial(IdEstado integer unique,
				  Descripcion varchar(50));
-- Falta la tabla, para los estados del pedido 


create table EstadosPedidoMaterial(IdEstado integer references EstadoPedidoMaterial(IdEstado),
				   IdPedido integer references PedidosMaterial(IdPedido),
				   Fecha timestamp without time zone);


create table UltimoEstadoPedido(IdPedido integer references PedidosMaterial(IdPedido),
				IdEstado  integer references EstadoPedidoMaterial(idEstado),
				primary key(IdPedido,IdEstado));

insert into EstadoPedidoMaterial values(0,'Registrado');
insert into EstadoPedidoMaterial values(1,'Enviado a Matriz');
insert into EstadoPedidoMaterial values(2,'Revisando Matriz');
insert into EstadoPedidoMaterial values(3,'Enviado de la Matriz al Expendio');


