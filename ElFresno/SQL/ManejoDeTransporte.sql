create table Inspecciones(
			  idInspeccion integer,
			  NmbInspeccion varchar(126) primary key
			 );

create table DetalleInspeccion(
				idInspeccion integer,
				idActividad  integer,
				Actividad varchar(256)
			      );

create table VerificaInspeccion(idVehiculo integer,
			 	Fecha timestamp without time zone,
				idPersonaV integer);

create table DetalleVeficaInspeccion(
				      idVehiculo integer,
				      idActividad integer,
				      EdoVerificacion integer,
				      Comentario varchar(256),
			 	      Fecha timestamp without time zone,
				    );
				      
create table CaracterizaVehiculo(
				 idVehiculo integer,
				 Capacidad integer
				);
create table Manteninientos(
				idMantenimiento integer,
				NmbMantenimiento varchar(256),
				PeriodicidadT integer, -- En meses
				PeriodicidadK integer,
				);

create table DetalleMantenimiento(
				   idMantenimiento integer,
				   NmbActividad varchar(125),
				   Tiempo varchar(15),
				   Observaciones text
				 );
-------En el registro de productos se debera, contemplar una nueva
-------familia, la cual nos permitira llevar el inventario de las
-------refacciones que se utilizan en cada mantenimiento.
create table MaterialMantenimiento(
				   CveProducto varchar(50), 
				   Cantidad numeric(10,2)
				  );
				
create table SeriesRefacciones(CveProducto varchar(50),
			       idEmpresa integer,   --Proveedor
			       Serie varchar(256));
-- El campo de proveedor, indicara el lugar donde se realizara
-- el mantenimiento, el cual puede ser en planta o con un proveedor
-- externo.
create table ProgramacionMantenimientos(idVehiculo integer,
					Fecha timestamp without time zone,
					idMantenimiento integer,
					idProveedor integer);

--En Esta tabla se almacenaran los distintos servicios que se le deberan
--realizar a los vehiculos, estos servicios son diferentes a los mantenimientos
-- para esto se consideran las revistas, verificacion ecologia, pago de seguros
-- y todos aquellos procesos administrativos que se deberan hacer al vehiculo.

create table ServicioVehiculo(idServicio integer,
			      NmbServicio varchar(128),
			      Descripcion text,
			      PeriodicidadT integer , --En Meses
			      PeriodicidadK integer);
create table ServiciosVehiculos(
				idVehiculo integer,
				idServicio integer);
				

--	Para el control del combustible, se debera crear una familia que se llame
--	combustibles, y en ella se debera registrar las compras realizadas esto
--	se realizara mediante la pantalla de compras de productos, para lo que 
--	esta pantalla se debera modificar para que se puedan cargar los productos
--	solo de una familia determinada.

--	El proceso de registro de compras de combustible, lo realizara el adminis
--	trador, y el registro de la carga de combustible el chofer.

--	Para el proceso de carga de combustible se considerara ademas la lectura
--	del odomentro en kms, y al momento de realizar la siguiente carga se 
--	capturara la lectura que marque el odometro, con lo que se tendra el
--	numero de kms, que se trabajo, con la carga de gasolina.

	El procedimiento anterior se generalizara, para cualquier combustible, 
	y es mas para cualquier producto que se aplique al vehiculo, como
	puede ser el aceite, anticongelante, etc.




create table CargaCombustible(
			      idCarga integer,
			      CveProducto varchar(50),
			      Cantidad numeric(10,2),
			      idVehiculo integer,
			      idPersona integer, -- Chofer
			      FechaIniCarga timestamp without time zone,
			      FechaFinCarga timestamp without time zone,
			      NumeroNota varchar(50),
			      KMSInicio  numeric(10,2),
			      KMSFin     numeric(10,2)
			      );

create table ValeTaller(
			 idVale integer,
			 CveProducto varchar(50),
			 Cantidad numeric(10,2),
			 idResponsableTaller integer,
			 idPersona integer, -- A quien se presta
			 FechaSalida timestamp without time zone,
			 FechaEstimadaRegreso timestamp without time zone,
			 FechaRegreso timestamp without time zone,
			 Comentarios text
			 );

				 
--	Nota1.- Refacciones
--
--	Para el caso de las refacciones, se debera considerar el mismo proceso que
--	el de un producto, solo se clasificara en la familia de refacciones, ade-
--	mas se debera, desarrollar un modulo que permita revisar los numeros de 
--	serie de las refacciones, esto permitira, trabajar las refacciones como
--	un producto de la base de datos, pero en el momento que se requiere sa-
--	ber cual es el numero de serie de esa refaccion, se podra consultar

--	Nota2.- Refaccionaria
--
--	Para el control interno del la refaccionaria, y para integrarla a la 
--	gestion del sistema, en cuanto a compras y ventas debera registrar un
--	expendio que se llame Refaccionaria, el cual contendra todos los productos,
--	a refacciones, llantas, aceites y lubricantes.
	
--
--
--	Nota3.- Taller .
--
--	Para el caso del taller se debera registrar otro expendio, el cual 
--	tendra como productos, las herramientas

--	Nota4.- General
--
--	Para el caso del almacen y de la refaccionaria, los procesos de compras
--	quedaran integrados al proceso de compra de los expendios, pero se debera
--	bloquer el apartado de ventas desde el controlador de expendios.

--	Es importante considerar que ahora el tipo de expendio, y con esto las 
--	familias de productos que se podran controlar en cada expendio, para lo
--	que se tendra que desarrollar una interfaz para indicar las familias de
--	productos que se controlaran en cada expendio.
--
--	En el caso del taller se deberan definir operaciones como, salida de herramientas
--	y regreso de la herramienta, como sus respectivos controles.
--
--
--
--	Nota5.- Combustibles 

--	Para el caso de combustibles tambien se debera registrar un expendio, en el
--	cual las operaciones de compra son exactamente igual a cualquier producto, 
--	en este caso la informacion de este expendio se vera afectada por la
--	carga de combustible.
--	
--	Nota6.- Vale Taller
--
--	Para el caso del campo Comentarios, se debera actualizar,con los comentarios
--	cuando la herramienta sale del taller, y cuando la herramienta se regresa
--
