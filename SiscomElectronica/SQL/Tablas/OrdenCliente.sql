create table OrdenCliente(
		IdVenta	integer,
		IdPersona	integer references Personas(IdPersona));

-- Viernes 6 de Enero del 2017 
-- Se agrega el manejo de los datos de la informacion del apartado


create table Apartado(
		IdVenta integer,--references ImporteOrden(IdVenta),
		ACuenta numeric(10,2),
		PorPagar numeric(10,2),
		FechaEntrega timestamp without time zone);

-- Miercoles 11 de Enero 2017
-- Para manejar la informacion de las cotizaciones 
-- se crea la siguiente tabla, ahorita solo se ha identificado
-- la descripcion de la cotizacion como campo ..

create table Cotizacion(
		IdVenta integer,
		Descripcion text);


-- Martes 24 de Enero 2017 
-- Informacion del pedido.

create table DatosPedido(
		IdVenta integer,
		FechaEntrega timestamp without time zone,
		SePagaCon numeric(10,2),
		Cambio numeric(10,2),
		Observaciones text);
