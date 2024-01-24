--
-- PostgreSQL database dump
--

SET client_encoding = 'SQL_ASCII';
SET standard_conforming_strings = off;
SET check_function_bodies = false;
SET client_min_messages = warning;
SET escape_string_warning = off;

--
-- Name: SCHEMA public; Type: COMMENT; Schema: -; Owner: postgres824
--

COMMENT ON SCHEMA public IS 'Standard public schema';


SET search_path = public, pg_catalog;

SET default_tablespace = '';

SET default_with_oids = false;

--
-- Name: aplicaciones; Type: TABLE; Schema: public; Owner: hgarduno; Tablespace: 
--

CREATE TABLE aplicaciones (
    idaplicacion integer NOT NULL,
    nmbaplicacion character varying(50),
    dscaplicacion character varying(256),
    dirarchivosqt character varying(256)
);


ALTER TABLE public.aplicaciones OWNER TO hgarduno;

--
-- Name: catmediocomunicacion; Type: TABLE; Schema: public; Owner: hgarduno; Tablespace: 
--

CREATE TABLE catmediocomunicacion (
    idmedio integer,
    medio character varying(50) NOT NULL
);


ALTER TABLE public.catmediocomunicacion OWNER TO hgarduno;

--
-- Name: cattipopersona; Type: TABLE; Schema: public; Owner: hgarduno; Tablespace: 
--

CREATE TABLE cattipopersona (
    idtipopersona integer NOT NULL,
    tipopersona character varying(50)
);


ALTER TABLE public.cattipopersona OWNER TO hgarduno;

--
-- Name: clientesfisica; Type: TABLE; Schema: public; Owner: hgarduno; Tablespace: 
--

CREATE TABLE clientesfisica (
    idpersona integer
);


ALTER TABLE public.clientesfisica OWNER TO hgarduno;

--
-- Name: clientesmoral; Type: TABLE; Schema: public; Owner: hgarduno; Tablespace: 
--

CREATE TABLE clientesmoral (
    idempresa integer
);


ALTER TABLE public.clientesmoral OWNER TO hgarduno;

--
-- Name: compras; Type: TABLE; Schema: public; Owner: hgarduno; Tablespace: 
--

CREATE TABLE compras (
    idcompra integer,
    idproducto integer,
    cantidad numeric(10,2),
    preciocompra numeric(10,2),
    factura character varying(50),
    idempresa integer,
    idcontacto integer,
    idformapago integer,
    fecha timestamp without time zone,
    idexpendio integer
);


ALTER TABLE public.compras OWNER TO hgarduno;

--
-- Name: comunicacionpersona; Type: TABLE; Schema: public; Owner: hgarduno; Tablespace: 
--

CREATE TABLE comunicacionpersona (
    idpersona integer NOT NULL,
    idmedio integer NOT NULL,
    dato character varying(50) NOT NULL,
    descripcion character varying(100)
);


ALTER TABLE public.comunicacionpersona OWNER TO hgarduno;

--
-- Name: contactosempresa; Type: TABLE; Schema: public; Owner: hgarduno; Tablespace: 
--

CREATE TABLE contactosempresa (
    idempresa integer,
    idpersona integer
);


ALTER TABLE public.contactosempresa OWNER TO hgarduno;

--
-- Name: detalledevolucion; Type: TABLE; Schema: public; Owner: hgarduno; Tablespace: 
--

CREATE TABLE detalledevolucion (
    iddevolucion integer,
    idproducto integer,
    cantidad numeric(10,2),
    precio numeric(10,2),
    importe numeric(10,2)
);


ALTER TABLE public.detalledevolucion OWNER TO hgarduno;

--
-- Name: detalleventa; Type: TABLE; Schema: public; Owner: hgarduno; Tablespace: 
--

CREATE TABLE detalleventa (
    idventa integer,
    idproducto integer,
    cantidad numeric(10,2),
    idprecio integer,
    total numeric(10,2)
);


ALTER TABLE public.detalleventa OWNER TO hgarduno;

--
-- Name: devoluciones; Type: TABLE; Schema: public; Owner: hgarduno; Tablespace: 
--

CREATE TABLE devoluciones (
    iddevolucion integer,
    idventa integer,
    total numeric(10,2),
    fecha timestamp without time zone,
    motivo text
);


ALTER TABLE public.devoluciones OWNER TO hgarduno;

--
-- Name: direcciones; Type: TABLE; Schema: public; Owner: hgarduno; Tablespace: 
--

CREATE TABLE direcciones (
    calle character varying(50),
    numero character varying(10),
    referencias character varying(250),
    idasentamiento integer,
    idpersona integer
);


ALTER TABLE public.direcciones OWNER TO hgarduno;

--
-- Name: empresanormalizada; Type: TABLE; Schema: public; Owner: hgarduno; Tablespace: 
--

CREATE TABLE empresanormalizada (
    idempresa integer,
    razonsocial character varying(256)
);


ALTER TABLE public.empresanormalizada OWNER TO hgarduno;

--
-- Name: empresas; Type: TABLE; Schema: public; Owner: hgarduno; Tablespace: 
--

CREATE TABLE empresas (
    idempresa integer,
    razonsocial character varying(256) NOT NULL
);


ALTER TABLE public.empresas OWNER TO hgarduno;

--
-- Name: expendios; Type: TABLE; Schema: public; Owner: hgarduno; Tablespace: 
--

CREATE TABLE expendios (
    idexpendio integer,
    puerto integer NOT NULL,
    dirip character varying(25) NOT NULL
);


ALTER TABLE public.expendios OWNER TO hgarduno;

--
-- Name: familia; Type: TABLE; Schema: public; Owner: hgarduno; Tablespace: 
--

CREATE TABLE familia (
    idfamilia integer,
    familia character varying(50) NOT NULL,
    dsc text
);


ALTER TABLE public.familia OWNER TO hgarduno;

--
-- Name: famproducto; Type: TABLE; Schema: public; Owner: hgarduno; Tablespace: 
--

CREATE TABLE famproducto (
    idproducto integer,
    idfamilia integer
);


ALTER TABLE public.famproducto OWNER TO hgarduno;

--
-- Name: firmas; Type: TABLE; Schema: public; Owner: hgarduno; Tablespace: 
--

CREATE TABLE firmas (
    idusuario integer,
    firma character varying(30) NOT NULL,
    "password" character varying(30) NOT NULL,
    edofirma integer
);


ALTER TABLE public.firmas OWNER TO hgarduno;

--
-- Name: formapago; Type: TABLE; Schema: public; Owner: hgarduno; Tablespace: 
--

CREATE TABLE formapago (
    idformapago integer,
    nombre character varying(50),
    diassigpago integer
);


ALTER TABLE public.formapago OWNER TO hgarduno;

--
-- Name: inventario; Type: TABLE; Schema: public; Owner: hgarduno; Tablespace: 
--

CREATE TABLE inventario (
    idexpendio integer NOT NULL,
    idproducto integer NOT NULL,
    existencia numeric(10,2),
    existenciamin numeric(10,2)
);


ALTER TABLE public.inventario OWNER TO hgarduno;

--
-- Name: objeto; Type: TABLE; Schema: public; Owner: hgarduno; Tablespace: 
--

CREATE TABLE objeto (
    idobjeto integer NOT NULL,
    nmbclase character varying(30)
);


ALTER TABLE public.objeto OWNER TO hgarduno;

--
-- Name: objetosxpantalla; Type: TABLE; Schema: public; Owner: hgarduno; Tablespace: 
--

CREATE TABLE objetosxpantalla (
    idpantalla integer,
    idobjeto integer,
    idperfil integer,
    idpropiedad integer,
    valorpropiedad character varying(256)
);


ALTER TABLE public.objetosxpantalla OWNER TO hgarduno;

--
-- Name: pantalla; Type: TABLE; Schema: public; Owner: hgarduno; Tablespace: 
--

CREATE TABLE pantalla (
    idpantalla integer NOT NULL,
    idaplicacion integer,
    nmbclase character varying(30),
    archivo character varying(30)
);


ALTER TABLE public.pantalla OWNER TO hgarduno;

--
-- Name: paquetes; Type: TABLE; Schema: public; Owner: hgarduno; Tablespace: 
--

CREATE TABLE paquetes (
    idpaquete integer,
    clave character varying(25) NOT NULL,
    descripcion text,
    precio numeric(10,2)
);


ALTER TABLE public.paquetes OWNER TO hgarduno;

--
-- Name: perfiles; Type: TABLE; Schema: public; Owner: hgarduno; Tablespace: 
--

CREATE TABLE perfiles (
    idperfil integer,
    idaplicacion integer NOT NULL,
    nmbperfil character varying(30) NOT NULL,
    dscperfil character varying(128)
);


ALTER TABLE public.perfiles OWNER TO hgarduno;

--
-- Name: personanormalizada; Type: TABLE; Schema: public; Owner: hgarduno; Tablespace: 
--

CREATE TABLE personanormalizada (
    idpersona integer,
    nombre character varying(25),
    apaterno character varying(25),
    amaterno character varying(25)
);


ALTER TABLE public.personanormalizada OWNER TO hgarduno;

--
-- Name: personas; Type: TABLE; Schema: public; Owner: hgarduno; Tablespace: 
--

CREATE TABLE personas (
    idpersona integer,
    nombre character varying(25) NOT NULL,
    apaterno character varying(25) NOT NULL,
    amaterno character varying(25) NOT NULL
);


ALTER TABLE public.personas OWNER TO hgarduno;

--
-- Name: precios; Type: TABLE; Schema: public; Owner: hgarduno; Tablespace: 
--

CREATE TABLE precios (
    idprecio integer,
    nombre character varying(25) NOT NULL,
    dsc text
);


ALTER TABLE public.precios OWNER TO hgarduno;

--
-- Name: preciosproducto; Type: TABLE; Schema: public; Owner: hgarduno; Tablespace: 
--

CREATE TABLE preciosproducto (
    idproducto integer NOT NULL,
    idprecio integer NOT NULL,
    precio numeric(10,2)
);


ALTER TABLE public.preciosproducto OWNER TO hgarduno;

--
-- Name: producto; Type: TABLE; Schema: public; Owner: hgarduno; Tablespace: 
--

CREATE TABLE producto (
    idproducto integer,
    clave character varying(50) NOT NULL,
    dsc text
);


ALTER TABLE public.producto OWNER TO hgarduno;

--
-- Name: productoscotizando; Type: TABLE; Schema: public; Owner: hgarduno; Tablespace: 
--

CREATE TABLE productoscotizando (
    idproducto integer NOT NULL,
    idexpendio integer,
    cantidad numeric(10,2)
);


ALTER TABLE public.productoscotizando OWNER TO hgarduno;

--
-- Name: productospaquete; Type: TABLE; Schema: public; Owner: hgarduno; Tablespace: 
--

CREATE TABLE productospaquete (
    idpaquete integer NOT NULL,
    idproducto integer NOT NULL,
    cantidad numeric(10,2)
);


ALTER TABLE public.productospaquete OWNER TO hgarduno;

--
-- Name: propiedades; Type: TABLE; Schema: public; Owner: hgarduno; Tablespace: 
--

CREATE TABLE propiedades (
    idobjeto integer NOT NULL,
    idpropiedad integer NOT NULL,
    nmbpropiedad character varying(30)
);


ALTER TABLE public.propiedades OWNER TO hgarduno;

--
-- Name: proveedores; Type: TABLE; Schema: public; Owner: hgarduno; Tablespace: 
--

CREATE TABLE proveedores (
    idempresa integer
);


ALTER TABLE public.proveedores OWNER TO hgarduno;

--
-- Name: tipopersona; Type: TABLE; Schema: public; Owner: hgarduno; Tablespace: 
--

CREATE TABLE tipopersona (
    idpersona integer,
    idtipopersona integer
);


ALTER TABLE public.tipopersona OWNER TO hgarduno;

--
-- Name: usuarios; Type: TABLE; Schema: public; Owner: hgarduno; Tablespace: 
--

CREATE TABLE usuarios (
    idusuario integer NOT NULL,
    idaplicacion integer,
    idperfil integer,
    nmbusuario character varying(30),
    apaterno character varying(30),
    amaterno character varying(30)
);


ALTER TABLE public.usuarios OWNER TO hgarduno;

--
-- Name: ventas; Type: TABLE; Schema: public; Owner: hgarduno; Tablespace: 
--

CREATE TABLE ventas (
    idventa integer,
    idexpendio integer,
    idformapago integer,
    tipocliente character varying(10),
    fecha timestamp without time zone,
    importe numeric(10,2),
    edoventa integer
);


ALTER TABLE public.ventas OWNER TO hgarduno;

--
-- Name: ventasfisicas; Type: TABLE; Schema: public; Owner: hgarduno; Tablespace: 
--

CREATE TABLE ventasfisicas (
    idventa integer,
    idpersona integer
);


ALTER TABLE public.ventasfisicas OWNER TO hgarduno;

--
-- Name: ventasmorales; Type: TABLE; Schema: public; Owner: hgarduno; Tablespace: 
--

CREATE TABLE ventasmorales (
    idventa integer,
    idempresa integer
);


ALTER TABLE public.ventasmorales OWNER TO hgarduno;

--
-- Data for Name: aplicaciones; Type: TABLE DATA; Schema: public; Owner: hgarduno
--

COPY aplicaciones (idaplicacion, nmbaplicacion, dscaplicacion, dirarchivosqt) FROM stdin;
1	SpeedWheels	SpeedWheels	/usr/local/hgarduno/SiscomTiendas4/Cliente/UI/
\.


--
-- Data for Name: catmediocomunicacion; Type: TABLE DATA; Schema: public; Owner: hgarduno
--

COPY catmediocomunicacion (idmedio, medio) FROM stdin;
1	Telefono
2	Correo Electronico
\.


--
-- Data for Name: cattipopersona; Type: TABLE DATA; Schema: public; Owner: hgarduno
--

COPY cattipopersona (idtipopersona, tipopersona) FROM stdin;
\.


--
-- Data for Name: clientesfisica; Type: TABLE DATA; Schema: public; Owner: hgarduno
--

COPY clientesfisica (idpersona) FROM stdin;
0
\.


--
-- Data for Name: clientesmoral; Type: TABLE DATA; Schema: public; Owner: hgarduno
--

COPY clientesmoral (idempresa) FROM stdin;
\.


--
-- Data for Name: compras; Type: TABLE DATA; Schema: public; Owner: hgarduno
--

COPY compras (idcompra, idproducto, cantidad, preciocompra, factura, idempresa, idcontacto, idformapago, fecha, idexpendio) FROM stdin;
\.


--
-- Data for Name: comunicacionpersona; Type: TABLE DATA; Schema: public; Owner: hgarduno
--

COPY comunicacionpersona (idpersona, idmedio, dato, descripcion) FROM stdin;
\.


--
-- Data for Name: contactosempresa; Type: TABLE DATA; Schema: public; Owner: hgarduno
--

COPY contactosempresa (idempresa, idpersona) FROM stdin;
\.


--
-- Data for Name: detalledevolucion; Type: TABLE DATA; Schema: public; Owner: hgarduno
--

COPY detalledevolucion (iddevolucion, idproducto, cantidad, precio, importe) FROM stdin;
\.


--
-- Data for Name: detalleventa; Type: TABLE DATA; Schema: public; Owner: hgarduno
--

COPY detalleventa (idventa, idproducto, cantidad, idprecio, total) FROM stdin;
\.


--
-- Data for Name: devoluciones; Type: TABLE DATA; Schema: public; Owner: hgarduno
--

COPY devoluciones (iddevolucion, idventa, total, fecha, motivo) FROM stdin;
\.


--
-- Data for Name: direcciones; Type: TABLE DATA; Schema: public; Owner: hgarduno
--

COPY direcciones (calle, numero, referencias, idasentamiento, idpersona) FROM stdin;
\.


--
-- Data for Name: empresanormalizada; Type: TABLE DATA; Schema: public; Owner: hgarduno
--

COPY empresanormalizada (idempresa, razonsocial) FROM stdin;
\.


--
-- Data for Name: empresas; Type: TABLE DATA; Schema: public; Owner: hgarduno
--

COPY empresas (idempresa, razonsocial) FROM stdin;
0	Matriz
\.


--
-- Data for Name: expendios; Type: TABLE DATA; Schema: public; Owner: hgarduno
--

COPY expendios (idexpendio, puerto, dirip) FROM stdin;
0	2645	127.0.0.1
\.


--
-- Data for Name: familia; Type: TABLE DATA; Schema: public; Owner: hgarduno
--

COPY familia (idfamilia, familia, dsc) FROM stdin;
\.


--
-- Data for Name: famproducto; Type: TABLE DATA; Schema: public; Owner: hgarduno
--

COPY famproducto (idproducto, idfamilia) FROM stdin;
\.


--
-- Data for Name: firmas; Type: TABLE DATA; Schema: public; Owner: hgarduno
--

COPY firmas (idusuario, firma, "password", edofirma) FROM stdin;
1	hgarduno	heligardunoesquivel	\N
\.


--
-- Data for Name: formapago; Type: TABLE DATA; Schema: public; Owner: hgarduno
--

COPY formapago (idformapago, nombre, diassigpago) FROM stdin;
1	Contado	0
2	Credito 15 Dias	15
3	Credito 30 Dias	30
4	Credito 45 Dias	30
5	Credito 60 Dias	60
\.


--
-- Data for Name: inventario; Type: TABLE DATA; Schema: public; Owner: hgarduno
--

COPY inventario (idexpendio, idproducto, existencia, existenciamin) FROM stdin;
\.


--
-- Data for Name: objeto; Type: TABLE DATA; Schema: public; Owner: hgarduno
--

COPY objeto (idobjeto, nmbclase) FROM stdin;
1	QComboBox
2	QLineEdit
3	QLabel
4	QTable
5	QPushButton
6	QAction
7	Entero
8	QIconView
9	QIconViewItem
\.


--
-- Data for Name: objetosxpantalla; Type: TABLE DATA; Schema: public; Owner: hgarduno
--

COPY objetosxpantalla (idpantalla, idobjeto, idperfil, idpropiedad, valorpropiedad) FROM stdin;
\.


--
-- Data for Name: pantalla; Type: TABLE DATA; Schema: public; Owner: hgarduno
--

COPY pantalla (idpantalla, idaplicacion, nmbclase, archivo) FROM stdin;
\.


--
-- Data for Name: paquetes; Type: TABLE DATA; Schema: public; Owner: hgarduno
--

COPY paquetes (idpaquete, clave, descripcion, precio) FROM stdin;
\.


--
-- Data for Name: perfiles; Type: TABLE DATA; Schema: public; Owner: hgarduno
--

COPY perfiles (idperfil, idaplicacion, nmbperfil, dscperfil) FROM stdin;
1	1	Programador	Programador
\.


--
-- Data for Name: personanormalizada; Type: TABLE DATA; Schema: public; Owner: hgarduno
--

COPY personanormalizada (idpersona, nombre, apaterno, amaterno) FROM stdin;
\.


--
-- Data for Name: personas; Type: TABLE DATA; Schema: public; Owner: hgarduno
--

COPY personas (idpersona, nombre, apaterno, amaterno) FROM stdin;
1	Heli	Garduno	Esquivel
0	Publico	General	
\.


--
-- Data for Name: precios; Type: TABLE DATA; Schema: public; Owner: hgarduno
--

COPY precios (idprecio, nombre, dsc) FROM stdin;
\.


--
-- Data for Name: preciosproducto; Type: TABLE DATA; Schema: public; Owner: hgarduno
--

COPY preciosproducto (idproducto, idprecio, precio) FROM stdin;
\.


--
-- Data for Name: producto; Type: TABLE DATA; Schema: public; Owner: hgarduno
--

COPY producto (idproducto, clave, dsc) FROM stdin;
\.


--
-- Data for Name: productoscotizando; Type: TABLE DATA; Schema: public; Owner: hgarduno
--

COPY productoscotizando (idproducto, idexpendio, cantidad) FROM stdin;
\.


--
-- Data for Name: productospaquete; Type: TABLE DATA; Schema: public; Owner: hgarduno
--

COPY productospaquete (idpaquete, idproducto, cantidad) FROM stdin;
\.


--
-- Data for Name: propiedades; Type: TABLE DATA; Schema: public; Owner: hgarduno
--

COPY propiedades (idobjeto, idpropiedad, nmbpropiedad) FROM stdin;
1	0	IniciaControl
1	1	name
1	2	enabled
1	3	font
2	0	IniciaControl
2	1	name
2	2	enabled
2	3	readOnly
2	4	font
3	0	IniciaControl
3	1	name
3	2	text
3	3	font
4	0	IniciaControl
4	1	name
4	2	readOnly
4	3	font
5	0	IniciaControl
5	1	name
5	2	text
5	3	iconSet
5	4	enabled
5	5	font
6	0	IniciaControl
6	1	name
6	2	text
6	3	enabled
6	4	visible
6	5	iconSet
6	6	font
7	0	IniciaControl
7	1	name
7	2	Valor
8	0	IniciaControl
8	1	name
8	2	font
9	0	IniciaControl
9	1	name
9	2	font
\.


--
-- Data for Name: proveedores; Type: TABLE DATA; Schema: public; Owner: hgarduno
--

COPY proveedores (idempresa) FROM stdin;
\.


--
-- Data for Name: tipopersona; Type: TABLE DATA; Schema: public; Owner: hgarduno
--

COPY tipopersona (idpersona, idtipopersona) FROM stdin;
\.


--
-- Data for Name: usuarios; Type: TABLE DATA; Schema: public; Owner: hgarduno
--

COPY usuarios (idusuario, idaplicacion, idperfil, nmbusuario, apaterno, amaterno) FROM stdin;
1	1	1	Heli	Garduno	Esquivel
\.


--
-- Data for Name: ventas; Type: TABLE DATA; Schema: public; Owner: hgarduno
--

COPY ventas (idventa, idexpendio, idformapago, tipocliente, fecha, importe, edoventa) FROM stdin;
\.


--
-- Data for Name: ventasfisicas; Type: TABLE DATA; Schema: public; Owner: hgarduno
--

COPY ventasfisicas (idventa, idpersona) FROM stdin;
\.


--
-- Data for Name: ventasmorales; Type: TABLE DATA; Schema: public; Owner: hgarduno
--

COPY ventasmorales (idventa, idempresa) FROM stdin;
\.


--
-- Name: aplicaciones_pkey; Type: CONSTRAINT; Schema: public; Owner: hgarduno; Tablespace: 
--

ALTER TABLE ONLY aplicaciones
    ADD CONSTRAINT aplicaciones_pkey PRIMARY KEY (idaplicacion);


--
-- Name: catmediocomunicacion_idmedio_key; Type: CONSTRAINT; Schema: public; Owner: hgarduno; Tablespace: 
--

ALTER TABLE ONLY catmediocomunicacion
    ADD CONSTRAINT catmediocomunicacion_idmedio_key UNIQUE (idmedio);


--
-- Name: catmediocomunicacion_pkey; Type: CONSTRAINT; Schema: public; Owner: hgarduno; Tablespace: 
--

ALTER TABLE ONLY catmediocomunicacion
    ADD CONSTRAINT catmediocomunicacion_pkey PRIMARY KEY (medio);


--
-- Name: cattipopersona_pkey; Type: CONSTRAINT; Schema: public; Owner: hgarduno; Tablespace: 
--

ALTER TABLE ONLY cattipopersona
    ADD CONSTRAINT cattipopersona_pkey PRIMARY KEY (idtipopersona);


--
-- Name: comunicacionpersona_pkey; Type: CONSTRAINT; Schema: public; Owner: hgarduno; Tablespace: 
--

ALTER TABLE ONLY comunicacionpersona
    ADD CONSTRAINT comunicacionpersona_pkey PRIMARY KEY (idpersona, idmedio, dato);


--
-- Name: contactosempresa_idpersona_key; Type: CONSTRAINT; Schema: public; Owner: hgarduno; Tablespace: 
--

ALTER TABLE ONLY contactosempresa
    ADD CONSTRAINT contactosempresa_idpersona_key UNIQUE (idpersona);


--
-- Name: devoluciones_iddevolucion_key; Type: CONSTRAINT; Schema: public; Owner: hgarduno; Tablespace: 
--

ALTER TABLE ONLY devoluciones
    ADD CONSTRAINT devoluciones_iddevolucion_key UNIQUE (iddevolucion);


--
-- Name: empresas_idempresa_key; Type: CONSTRAINT; Schema: public; Owner: hgarduno; Tablespace: 
--

ALTER TABLE ONLY empresas
    ADD CONSTRAINT empresas_idempresa_key UNIQUE (idempresa);


--
-- Name: empresas_pkey; Type: CONSTRAINT; Schema: public; Owner: hgarduno; Tablespace: 
--

ALTER TABLE ONLY empresas
    ADD CONSTRAINT empresas_pkey PRIMARY KEY (razonsocial);


--
-- Name: expendios_idexpendio_key; Type: CONSTRAINT; Schema: public; Owner: hgarduno; Tablespace: 
--

ALTER TABLE ONLY expendios
    ADD CONSTRAINT expendios_idexpendio_key UNIQUE (idexpendio);


--
-- Name: expendios_pkey; Type: CONSTRAINT; Schema: public; Owner: hgarduno; Tablespace: 
--

ALTER TABLE ONLY expendios
    ADD CONSTRAINT expendios_pkey PRIMARY KEY (puerto, dirip);


--
-- Name: familia_idfamilia_key; Type: CONSTRAINT; Schema: public; Owner: hgarduno; Tablespace: 
--

ALTER TABLE ONLY familia
    ADD CONSTRAINT familia_idfamilia_key UNIQUE (idfamilia);


--
-- Name: familia_pkey; Type: CONSTRAINT; Schema: public; Owner: hgarduno; Tablespace: 
--

ALTER TABLE ONLY familia
    ADD CONSTRAINT familia_pkey PRIMARY KEY (familia);


--
-- Name: formapago_idformapago_key; Type: CONSTRAINT; Schema: public; Owner: hgarduno; Tablespace: 
--

ALTER TABLE ONLY formapago
    ADD CONSTRAINT formapago_idformapago_key UNIQUE (idformapago);


--
-- Name: inventario_pkey; Type: CONSTRAINT; Schema: public; Owner: hgarduno; Tablespace: 
--

ALTER TABLE ONLY inventario
    ADD CONSTRAINT inventario_pkey PRIMARY KEY (idexpendio, idproducto);


--
-- Name: objeto_pkey; Type: CONSTRAINT; Schema: public; Owner: hgarduno; Tablespace: 
--

ALTER TABLE ONLY objeto
    ADD CONSTRAINT objeto_pkey PRIMARY KEY (idobjeto);


--
-- Name: pantalla_pkey; Type: CONSTRAINT; Schema: public; Owner: hgarduno; Tablespace: 
--

ALTER TABLE ONLY pantalla
    ADD CONSTRAINT pantalla_pkey PRIMARY KEY (idpantalla);


--
-- Name: paquetes_idpaquete_key; Type: CONSTRAINT; Schema: public; Owner: hgarduno; Tablespace: 
--

ALTER TABLE ONLY paquetes
    ADD CONSTRAINT paquetes_idpaquete_key UNIQUE (idpaquete);


--
-- Name: paquetes_pkey; Type: CONSTRAINT; Schema: public; Owner: hgarduno; Tablespace: 
--

ALTER TABLE ONLY paquetes
    ADD CONSTRAINT paquetes_pkey PRIMARY KEY (clave);


--
-- Name: perfiles_pkey; Type: CONSTRAINT; Schema: public; Owner: hgarduno; Tablespace: 
--

ALTER TABLE ONLY perfiles
    ADD CONSTRAINT perfiles_pkey PRIMARY KEY (idaplicacion, nmbperfil);


--
-- Name: personanormalizada_nombre_key; Type: CONSTRAINT; Schema: public; Owner: hgarduno; Tablespace: 
--

ALTER TABLE ONLY personanormalizada
    ADD CONSTRAINT personanormalizada_nombre_key UNIQUE (nombre, apaterno, amaterno);


--
-- Name: personas_idpersona_key; Type: CONSTRAINT; Schema: public; Owner: hgarduno; Tablespace: 
--

ALTER TABLE ONLY personas
    ADD CONSTRAINT personas_idpersona_key UNIQUE (idpersona);


--
-- Name: personas_pkey; Type: CONSTRAINT; Schema: public; Owner: hgarduno; Tablespace: 
--

ALTER TABLE ONLY personas
    ADD CONSTRAINT personas_pkey PRIMARY KEY (nombre, apaterno, amaterno);


--
-- Name: precios_idprecio_key; Type: CONSTRAINT; Schema: public; Owner: hgarduno; Tablespace: 
--

ALTER TABLE ONLY precios
    ADD CONSTRAINT precios_idprecio_key UNIQUE (idprecio);


--
-- Name: precios_pkey; Type: CONSTRAINT; Schema: public; Owner: hgarduno; Tablespace: 
--

ALTER TABLE ONLY precios
    ADD CONSTRAINT precios_pkey PRIMARY KEY (nombre);


--
-- Name: preciosproducto_pkey; Type: CONSTRAINT; Schema: public; Owner: hgarduno; Tablespace: 
--

ALTER TABLE ONLY preciosproducto
    ADD CONSTRAINT preciosproducto_pkey PRIMARY KEY (idproducto, idprecio);


--
-- Name: producto_idproducto_key; Type: CONSTRAINT; Schema: public; Owner: hgarduno; Tablespace: 
--

ALTER TABLE ONLY producto
    ADD CONSTRAINT producto_idproducto_key UNIQUE (idproducto);


--
-- Name: producto_pkey; Type: CONSTRAINT; Schema: public; Owner: hgarduno; Tablespace: 
--

ALTER TABLE ONLY producto
    ADD CONSTRAINT producto_pkey PRIMARY KEY (clave);


--
-- Name: productoscotizando_pkey; Type: CONSTRAINT; Schema: public; Owner: hgarduno; Tablespace: 
--

ALTER TABLE ONLY productoscotizando
    ADD CONSTRAINT productoscotizando_pkey PRIMARY KEY (idproducto);


--
-- Name: productospaquete_pkey; Type: CONSTRAINT; Schema: public; Owner: hgarduno; Tablespace: 
--

ALTER TABLE ONLY productospaquete
    ADD CONSTRAINT productospaquete_pkey PRIMARY KEY (idpaquete, idproducto);


--
-- Name: propiedades_pkey; Type: CONSTRAINT; Schema: public; Owner: hgarduno; Tablespace: 
--

ALTER TABLE ONLY propiedades
    ADD CONSTRAINT propiedades_pkey PRIMARY KEY (idobjeto, idpropiedad);


--
-- Name: proveedores_idempresa_key; Type: CONSTRAINT; Schema: public; Owner: hgarduno; Tablespace: 
--

ALTER TABLE ONLY proveedores
    ADD CONSTRAINT proveedores_idempresa_key UNIQUE (idempresa);


--
-- Name: usuarios_pkey; Type: CONSTRAINT; Schema: public; Owner: hgarduno; Tablespace: 
--

ALTER TABLE ONLY usuarios
    ADD CONSTRAINT usuarios_pkey PRIMARY KEY (idusuario);


--
-- Name: ventas_idventa_key; Type: CONSTRAINT; Schema: public; Owner: hgarduno; Tablespace: 
--

ALTER TABLE ONLY ventas
    ADD CONSTRAINT ventas_idventa_key UNIQUE (idventa);


--
-- Name: clientesfisica_idpersona_fkey; Type: FK CONSTRAINT; Schema: public; Owner: hgarduno
--

ALTER TABLE ONLY clientesfisica
    ADD CONSTRAINT clientesfisica_idpersona_fkey FOREIGN KEY (idpersona) REFERENCES personas(idpersona);


--
-- Name: clientesmoral_idempresa_fkey; Type: FK CONSTRAINT; Schema: public; Owner: hgarduno
--

ALTER TABLE ONLY clientesmoral
    ADD CONSTRAINT clientesmoral_idempresa_fkey FOREIGN KEY (idempresa) REFERENCES empresas(idempresa);


--
-- Name: compras_idcontacto_fkey; Type: FK CONSTRAINT; Schema: public; Owner: hgarduno
--

ALTER TABLE ONLY compras
    ADD CONSTRAINT compras_idcontacto_fkey FOREIGN KEY (idcontacto) REFERENCES contactosempresa(idpersona);


--
-- Name: compras_idempresa_fkey; Type: FK CONSTRAINT; Schema: public; Owner: hgarduno
--

ALTER TABLE ONLY compras
    ADD CONSTRAINT compras_idempresa_fkey FOREIGN KEY (idempresa) REFERENCES proveedores(idempresa);


--
-- Name: compras_idexpendio_fkey; Type: FK CONSTRAINT; Schema: public; Owner: hgarduno
--

ALTER TABLE ONLY compras
    ADD CONSTRAINT compras_idexpendio_fkey FOREIGN KEY (idexpendio) REFERENCES expendios(idexpendio);


--
-- Name: compras_idformapago_fkey; Type: FK CONSTRAINT; Schema: public; Owner: hgarduno
--

ALTER TABLE ONLY compras
    ADD CONSTRAINT compras_idformapago_fkey FOREIGN KEY (idformapago) REFERENCES formapago(idformapago);


--
-- Name: compras_idproducto_fkey; Type: FK CONSTRAINT; Schema: public; Owner: hgarduno
--

ALTER TABLE ONLY compras
    ADD CONSTRAINT compras_idproducto_fkey FOREIGN KEY (idproducto) REFERENCES producto(idproducto);


--
-- Name: comunicacionpersona_idmedio_fkey; Type: FK CONSTRAINT; Schema: public; Owner: hgarduno
--

ALTER TABLE ONLY comunicacionpersona
    ADD CONSTRAINT comunicacionpersona_idmedio_fkey FOREIGN KEY (idmedio) REFERENCES catmediocomunicacion(idmedio);


--
-- Name: comunicacionpersona_idpersona_fkey; Type: FK CONSTRAINT; Schema: public; Owner: hgarduno
--

ALTER TABLE ONLY comunicacionpersona
    ADD CONSTRAINT comunicacionpersona_idpersona_fkey FOREIGN KEY (idpersona) REFERENCES personas(idpersona);


--
-- Name: contactosempresa_idempresa_fkey; Type: FK CONSTRAINT; Schema: public; Owner: hgarduno
--

ALTER TABLE ONLY contactosempresa
    ADD CONSTRAINT contactosempresa_idempresa_fkey FOREIGN KEY (idempresa) REFERENCES empresas(idempresa);


--
-- Name: contactosempresa_idpersona_fkey; Type: FK CONSTRAINT; Schema: public; Owner: hgarduno
--

ALTER TABLE ONLY contactosempresa
    ADD CONSTRAINT contactosempresa_idpersona_fkey FOREIGN KEY (idpersona) REFERENCES personas(idpersona);


--
-- Name: detalledevolucion_iddevolucion_fkey; Type: FK CONSTRAINT; Schema: public; Owner: hgarduno
--

ALTER TABLE ONLY detalledevolucion
    ADD CONSTRAINT detalledevolucion_iddevolucion_fkey FOREIGN KEY (iddevolucion) REFERENCES devoluciones(iddevolucion);


--
-- Name: detalledevolucion_idproducto_fkey; Type: FK CONSTRAINT; Schema: public; Owner: hgarduno
--

ALTER TABLE ONLY detalledevolucion
    ADD CONSTRAINT detalledevolucion_idproducto_fkey FOREIGN KEY (idproducto) REFERENCES producto(idproducto);


--
-- Name: detalleventa_idproducto_fkey; Type: FK CONSTRAINT; Schema: public; Owner: hgarduno
--

ALTER TABLE ONLY detalleventa
    ADD CONSTRAINT detalleventa_idproducto_fkey FOREIGN KEY (idproducto) REFERENCES producto(idproducto);


--
-- Name: detalleventa_idventa_fkey; Type: FK CONSTRAINT; Schema: public; Owner: hgarduno
--

ALTER TABLE ONLY detalleventa
    ADD CONSTRAINT detalleventa_idventa_fkey FOREIGN KEY (idventa) REFERENCES ventas(idventa);


--
-- Name: devoluciones_idventa_fkey; Type: FK CONSTRAINT; Schema: public; Owner: hgarduno
--

ALTER TABLE ONLY devoluciones
    ADD CONSTRAINT devoluciones_idventa_fkey FOREIGN KEY (idventa) REFERENCES ventas(idventa);


--
-- Name: empresanormalizada_idempresa_fkey; Type: FK CONSTRAINT; Schema: public; Owner: hgarduno
--

ALTER TABLE ONLY empresanormalizada
    ADD CONSTRAINT empresanormalizada_idempresa_fkey FOREIGN KEY (idempresa) REFERENCES empresas(idempresa);


--
-- Name: expendios_idexpendio_fkey; Type: FK CONSTRAINT; Schema: public; Owner: hgarduno
--

ALTER TABLE ONLY expendios
    ADD CONSTRAINT expendios_idexpendio_fkey FOREIGN KEY (idexpendio) REFERENCES empresas(idempresa);


--
-- Name: famproducto_idfamilia_fkey; Type: FK CONSTRAINT; Schema: public; Owner: hgarduno
--

ALTER TABLE ONLY famproducto
    ADD CONSTRAINT famproducto_idfamilia_fkey FOREIGN KEY (idfamilia) REFERENCES familia(idfamilia);


--
-- Name: famproducto_idproducto_fkey; Type: FK CONSTRAINT; Schema: public; Owner: hgarduno
--

ALTER TABLE ONLY famproducto
    ADD CONSTRAINT famproducto_idproducto_fkey FOREIGN KEY (idproducto) REFERENCES producto(idproducto);


--
-- Name: firmas_idusuario_fkey; Type: FK CONSTRAINT; Schema: public; Owner: hgarduno
--

ALTER TABLE ONLY firmas
    ADD CONSTRAINT firmas_idusuario_fkey FOREIGN KEY (idusuario) REFERENCES usuarios(idusuario);


--
-- Name: inventario_idexpendio_fkey; Type: FK CONSTRAINT; Schema: public; Owner: hgarduno
--

ALTER TABLE ONLY inventario
    ADD CONSTRAINT inventario_idexpendio_fkey FOREIGN KEY (idexpendio) REFERENCES expendios(idexpendio);


--
-- Name: inventario_idproducto_fkey; Type: FK CONSTRAINT; Schema: public; Owner: hgarduno
--

ALTER TABLE ONLY inventario
    ADD CONSTRAINT inventario_idproducto_fkey FOREIGN KEY (idproducto) REFERENCES producto(idproducto);


--
-- Name: objetosxpantalla_idobjeto_fkey; Type: FK CONSTRAINT; Schema: public; Owner: hgarduno
--

ALTER TABLE ONLY objetosxpantalla
    ADD CONSTRAINT objetosxpantalla_idobjeto_fkey FOREIGN KEY (idobjeto) REFERENCES objeto(idobjeto);


--
-- Name: objetosxpantalla_idpantalla_fkey; Type: FK CONSTRAINT; Schema: public; Owner: hgarduno
--

ALTER TABLE ONLY objetosxpantalla
    ADD CONSTRAINT objetosxpantalla_idpantalla_fkey FOREIGN KEY (idpantalla) REFERENCES pantalla(idpantalla);


--
-- Name: pantalla_idaplicacion_fkey; Type: FK CONSTRAINT; Schema: public; Owner: hgarduno
--

ALTER TABLE ONLY pantalla
    ADD CONSTRAINT pantalla_idaplicacion_fkey FOREIGN KEY (idaplicacion) REFERENCES aplicaciones(idaplicacion);


--
-- Name: perfiles_idaplicacion_fkey; Type: FK CONSTRAINT; Schema: public; Owner: hgarduno
--

ALTER TABLE ONLY perfiles
    ADD CONSTRAINT perfiles_idaplicacion_fkey FOREIGN KEY (idaplicacion) REFERENCES aplicaciones(idaplicacion);


--
-- Name: personanormalizada_idpersona_fkey; Type: FK CONSTRAINT; Schema: public; Owner: hgarduno
--

ALTER TABLE ONLY personanormalizada
    ADD CONSTRAINT personanormalizada_idpersona_fkey FOREIGN KEY (idpersona) REFERENCES personas(idpersona);


--
-- Name: preciosproducto_idprecio_fkey; Type: FK CONSTRAINT; Schema: public; Owner: hgarduno
--

ALTER TABLE ONLY preciosproducto
    ADD CONSTRAINT preciosproducto_idprecio_fkey FOREIGN KEY (idprecio) REFERENCES precios(idprecio);


--
-- Name: preciosproducto_idproducto_fkey; Type: FK CONSTRAINT; Schema: public; Owner: hgarduno
--

ALTER TABLE ONLY preciosproducto
    ADD CONSTRAINT preciosproducto_idproducto_fkey FOREIGN KEY (idproducto) REFERENCES producto(idproducto);


--
-- Name: productoscotizando_idexpendio_fkey; Type: FK CONSTRAINT; Schema: public; Owner: hgarduno
--

ALTER TABLE ONLY productoscotizando
    ADD CONSTRAINT productoscotizando_idexpendio_fkey FOREIGN KEY (idexpendio) REFERENCES expendios(idexpendio);


--
-- Name: productoscotizando_idproducto_fkey; Type: FK CONSTRAINT; Schema: public; Owner: hgarduno
--

ALTER TABLE ONLY productoscotizando
    ADD CONSTRAINT productoscotizando_idproducto_fkey FOREIGN KEY (idproducto) REFERENCES producto(idproducto);


--
-- Name: productospaquete_idpaquete_fkey; Type: FK CONSTRAINT; Schema: public; Owner: hgarduno
--

ALTER TABLE ONLY productospaquete
    ADD CONSTRAINT productospaquete_idpaquete_fkey FOREIGN KEY (idpaquete) REFERENCES paquetes(idpaquete);


--
-- Name: productospaquete_idproducto_fkey; Type: FK CONSTRAINT; Schema: public; Owner: hgarduno
--

ALTER TABLE ONLY productospaquete
    ADD CONSTRAINT productospaquete_idproducto_fkey FOREIGN KEY (idproducto) REFERENCES producto(idproducto);


--
-- Name: propiedades_idobjeto_fkey; Type: FK CONSTRAINT; Schema: public; Owner: hgarduno
--

ALTER TABLE ONLY propiedades
    ADD CONSTRAINT propiedades_idobjeto_fkey FOREIGN KEY (idobjeto) REFERENCES objeto(idobjeto);


--
-- Name: proveedores_idempresa_fkey; Type: FK CONSTRAINT; Schema: public; Owner: hgarduno
--

ALTER TABLE ONLY proveedores
    ADD CONSTRAINT proveedores_idempresa_fkey FOREIGN KEY (idempresa) REFERENCES empresas(idempresa);


--
-- Name: usuarios_idaplicacion_fkey; Type: FK CONSTRAINT; Schema: public; Owner: hgarduno
--

ALTER TABLE ONLY usuarios
    ADD CONSTRAINT usuarios_idaplicacion_fkey FOREIGN KEY (idaplicacion) REFERENCES aplicaciones(idaplicacion);


--
-- Name: ventas_idexpendio_fkey; Type: FK CONSTRAINT; Schema: public; Owner: hgarduno
--

ALTER TABLE ONLY ventas
    ADD CONSTRAINT ventas_idexpendio_fkey FOREIGN KEY (idexpendio) REFERENCES expendios(idexpendio);


--
-- Name: ventas_idformapago_fkey; Type: FK CONSTRAINT; Schema: public; Owner: hgarduno
--

ALTER TABLE ONLY ventas
    ADD CONSTRAINT ventas_idformapago_fkey FOREIGN KEY (idformapago) REFERENCES formapago(idformapago);


--
-- Name: ventasfisicas_idpersona_fkey; Type: FK CONSTRAINT; Schema: public; Owner: hgarduno
--

ALTER TABLE ONLY ventasfisicas
    ADD CONSTRAINT ventasfisicas_idpersona_fkey FOREIGN KEY (idpersona) REFERENCES personas(idpersona);


--
-- Name: ventasfisicas_idventa_fkey; Type: FK CONSTRAINT; Schema: public; Owner: hgarduno
--

ALTER TABLE ONLY ventasfisicas
    ADD CONSTRAINT ventasfisicas_idventa_fkey FOREIGN KEY (idventa) REFERENCES ventas(idventa);


--
-- Name: ventasmorales_idempresa_fkey; Type: FK CONSTRAINT; Schema: public; Owner: hgarduno
--

ALTER TABLE ONLY ventasmorales
    ADD CONSTRAINT ventasmorales_idempresa_fkey FOREIGN KEY (idempresa) REFERENCES empresas(idempresa);


--
-- Name: ventasmorales_idventa_fkey; Type: FK CONSTRAINT; Schema: public; Owner: hgarduno
--

ALTER TABLE ONLY ventasmorales
    ADD CONSTRAINT ventasmorales_idventa_fkey FOREIGN KEY (idventa) REFERENCES ventas(idventa);


--
-- Name: public; Type: ACL; Schema: -; Owner: postgres824
--

REVOKE ALL ON SCHEMA public FROM PUBLIC;
REVOKE ALL ON SCHEMA public FROM postgres824;
GRANT ALL ON SCHEMA public TO postgres824;
GRANT ALL ON SCHEMA public TO PUBLIC;


--
-- PostgreSQL database dump complete
--

