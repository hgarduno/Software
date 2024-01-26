create table Clientes(IdCliente integer unique references Personas(IdPersona),
                ClaveCliente varchar(20) unique);
create table PersonaCliente(IdCliente integer references Personas(IdPersona),
                IdPersona integer references Personas(IdPersona));
create table TelefonoCliente(IdCliente integer references Clientes(IdCliente),
                IdTelefono integer references Telefonos(IdTelefono),
		primary key(IdCliente,IdTelefono));
create table DireccionesCliente(IdCliente integer references Clientes(IdCliente),
                IdDireccion integer references Direcciones(IdDireccion));
create table EstatusCliente(IdCliente integer references Clientes(IdCliente),
                IdEstatus integer references Estatus(IdEstatus));
create table Percepciones(IdPersona integer references Personas(IdPersona),
                Percepcion varchar(5));
create table Deducciones(IdPersona integer references Personas(IdPersona),
                Deduccion varchar(5));
create table PlazasCliente(IdPersona integer references Personas(IdPersona),
                Clave varchar(20));

create table DetalleDirecciones(
                IdDireccion integer references Direcciones(IdDireccion),
                IdTipoVivienda integer references TipoViviendas(IdTipoVivienda),
                TipoViviendaOtra varchar(20),
                IdTelefonoParticular integer references Telefonos(IdTelefono),
                IdTelefonoRecados integer references Telefonos(IdTelefono),
                IdTelefonoRecidir integer references Telefonos(IdTelefono),
                IdTelefonoCelular integer references Telefonos(IdTelefono),
                IdCorreo integer references Correos(IdCorreo));
create table EmpleoCliente(IdPersona integer references Personas(IdPersona),
                NombreEmpresa varchar(120),
                Antiguedad integer,
                Puesto varchar(50),
                GiroEmpresa varchar(30),
                NombreJefeDirecto varchar(120));
create table EmpleoDireccionesCliente(
                IdCliente integer references Clientes(IdCliente),
                IdDireccion integer references Direcciones(IdDireccion));
create table IngresoCliente(IdPersona integer references Personas(IdPersona),
                Sueldo float,
                IdFrecuenciaPago integer references FrecuenciaPagos(IdFrecuenciaPago),
                OtrosIngresos float,
                FuenteOtrosIngresos varchar(50),
                TotalIngresos float);

create table DatosComplementariosCliente(
                IdPersona integer references Personas(IdPersona),
                ProductosServicios varchar(120),
                OrigenRecursos varchar(50),
                DestinoRecursos varchar(50),
                MontoOperacion float,
                NumeroOperaciones integer,
                IdFrecuenciaTransaccional integer references FrecuenciaTransaccional(IdFrecuenciaTransaccional),
                PagosEfectivo integer,
                MotivoPagoEfectivo varchar(120),
                MontoPagoEfectivo float,
                CargoPublicoPrevio integer,
                IdCargoPublico integer references CargosPublicos(IdCargoPublico),
                TerceroBeneficiado integer,
                IdTercerosBeneficiados integer,
                TerceroAportador integer,
                IdTercerosAportadores integer,
                IdReferenciaPrimera integer references ReferenciaPersonal(IdReferencia),
                IdReferenciaSegunda integer references ReferenciaPersonal(IdReferencia),
                IdReferenciaTercera integer references ReferenciaPersonal(IdReferencia));







