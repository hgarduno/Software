--
-- PostgreSQL database dump
--

SET client_encoding = 'SQL_ASCII';
SET check_function_bodies = false;
SET client_min_messages = warning;

--
-- Name: SCHEMA public; Type: COMMENT; Schema: -; Owner: postgres813
--

COMMENT ON SCHEMA public IS 'Standard public schema';


SET search_path = public, pg_catalog;

SET default_tablespace = '';

SET default_with_oids = false;

--
-- Name: apodos; Type: TABLE; Schema: public; Owner: hgarduno; Tablespace: 
--

CREATE TABLE apodos (
    idpersona integer NOT NULL,
    apodo character varying(25)
);


ALTER TABLE public.apodos OWNER TO hgarduno;

--
-- Name: compras; Type: TABLE; Schema: public; Owner: hgarduno; Tablespace: 
--

CREATE TABLE compras (
    fecha timestamp without time zone,
    cveproducto character varying(25),
    cantidad numeric(10,2),
    importe numeric(10,2),
    proveedor integer,
    conproveedor integer,
    respondable integer,
    idexpendio integer,
    formapago character varying(25),
    numfactura character varying(50),
    precio numeric(10,2)
);


ALTER TABLE public.compras OWNER TO hgarduno;

--
-- Name: contactos; Type: TABLE; Schema: public; Owner: hgarduno; Tablespace: 
--

CREATE TABLE contactos (
    idpersona integer,
    idempresa integer
);


ALTER TABLE public.contactos OWNER TO hgarduno;

--
-- Name: correos; Type: TABLE; Schema: public; Owner: hgarduno; Tablespace: 
--

CREATE TABLE correos (
    idpersona integer,
    idempresa integer,
    correo character varying(256)
);


ALTER TABLE public.correos OWNER TO hgarduno;

--
-- Name: cuentasporpagar; Type: TABLE; Schema: public; Owner: hgarduno; Tablespace: 
--

CREATE TABLE cuentasporpagar (
    numfactura character varying(50),
    fechapago timestamp without time zone,
    importe numeric(10,2)
);


ALTER TABLE public.cuentasporpagar OWNER TO hgarduno;

--
-- Name: detallepedido; Type: TABLE; Schema: public; Owner: hgarduno; Tablespace: 
--

CREATE TABLE detallepedido (
    numpedido integer,
    cveproducto character varying(25),
    cantidad numeric(10,2),
    importe numeric(10,2),
    nmbtipoprecio character varying(25)
);


ALTER TABLE public.detallepedido OWNER TO hgarduno;

--
-- Name: direcciones; Type: TABLE; Schema: public; Owner: hgarduno; Tablespace: 
--

CREATE TABLE direcciones (
    idpersona integer,
    idempresa integer,
    calle character varying(50),
    numero character varying(10),
    colonia character varying(40),
    cp integer,
    municipio character varying(50),
    estado character varying(25),
    referencias text
);


ALTER TABLE public.direcciones OWNER TO hgarduno;

--
-- Name: empresas; Type: TABLE; Schema: public; Owner: hgarduno; Tablespace: 
--

CREATE TABLE empresas (
    razonsocial character varying(50),
    idempresa integer NOT NULL,
    rfc character varying(25)
);


ALTER TABLE public.empresas OWNER TO hgarduno;

--
-- Name: estadodelpedido; Type: TABLE; Schema: public; Owner: hgarduno; Tablespace: 
--

CREATE TABLE estadodelpedido (
    numpedido integer,
    idedopedido integer,
    fechahoraedo timestamp without time zone
);


ALTER TABLE public.estadodelpedido OWNER TO hgarduno;

--
-- Name: estadospedido; Type: TABLE; Schema: public; Owner: hgarduno; Tablespace: 
--

CREATE TABLE estadospedido (
    idedopedido integer NOT NULL,
    dscedopedido character varying(50)
);


ALTER TABLE public.estadospedido OWNER TO hgarduno;

--
-- Name: existencias; Type: TABLE; Schema: public; Owner: hgarduno; Tablespace: 
--

CREATE TABLE existencias (
    cveproducto character varying(25),
    existencia numeric(10,2),
    idexpendio integer
);


ALTER TABLE public.existencias OWNER TO hgarduno;

--
-- Name: familias; Type: TABLE; Schema: public; Owner: hgarduno; Tablespace: 
--

CREATE TABLE familias (
    idfamilia integer NOT NULL,
    nmbfamilia character varying(50),
    dscfamilia character varying(250)
);


ALTER TABLE public.familias OWNER TO hgarduno;

--
-- Name: firmas; Type: TABLE; Schema: public; Owner: hgarduno; Tablespace: 
--

CREATE TABLE firmas (
    firma character varying(25),
    idpersona integer
);


ALTER TABLE public.firmas OWNER TO hgarduno;

--
-- Name: formapago; Type: TABLE; Schema: public; Owner: hgarduno; Tablespace: 
--

CREATE TABLE formapago (
    numpedido integer,
    nmbtipoprecio character varying(25)
);


ALTER TABLE public.formapago OWNER TO hgarduno;

--
-- Name: importeorden; Type: TABLE; Schema: public; Owner: hgarduno; Tablespace: 
--

CREATE TABLE importeorden (
    idventa integer,
    importe numeric(10,2)
);


ALTER TABLE public.importeorden OWNER TO hgarduno;

--
-- Name: matriz; Type: TABLE; Schema: public; Owner: hgarduno; Tablespace: 
--

CREATE TABLE matriz (
    idempresa integer NOT NULL
);


ALTER TABLE public.matriz OWNER TO hgarduno;

--
-- Name: pedidos; Type: TABLE; Schema: public; Owner: hgarduno; Tablespace: 
--

CREATE TABLE pedidos (
    idcliente integer,
    idvendedor integer,
    idchofer integer,
    idautorizo integer,
    idempresa integer,
    idvehiculo integer,
    numpedido integer NOT NULL,
    fecharegistro timestamp without time zone,
    fechaentrega timestamp without time zone,
    importe numeric(10,2),
    formadepago character varying(50),
    idpersonarevisochofer integer,
    contactocliente character varying(125)
);


ALTER TABLE public.pedidos OWNER TO hgarduno;

--
-- Name: personas; Type: TABLE; Schema: public; Owner: hgarduno; Tablespace: 
--

CREATE TABLE personas (
    nombre character varying(25) NOT NULL,
    apaterno character varying(25) NOT NULL,
    amaterno character varying(25) NOT NULL,
    rfc character varying(25),
    idpersona integer,
    tipopersona integer
);


ALTER TABLE public.personas OWNER TO hgarduno;

--
-- Name: precios; Type: TABLE; Schema: public; Owner: hgarduno; Tablespace: 
--

CREATE TABLE precios (
    cveproducto character varying(25) NOT NULL,
    idpersona integer NOT NULL,
    idempresa integer,
    idprecio integer,
    precio numeric(10,2),
    nmbtipoprecio character varying(25) NOT NULL
);


ALTER TABLE public.precios OWNER TO hgarduno;

--
-- Name: productos; Type: TABLE; Schema: public; Owner: hgarduno; Tablespace: 
--

CREATE TABLE productos (
    cveproducto character varying(25) NOT NULL,
    dscproducto character varying(250),
    unidad integer,
    idfamilia integer
);


ALTER TABLE public.productos OWNER TO hgarduno;

--
-- Name: telefonos; Type: TABLE; Schema: public; Owner: hgarduno; Tablespace: 
--

CREATE TABLE telefonos (
    idpersona integer,
    idempresa integer,
    telefono character varying(100)
);


ALTER TABLE public.telefonos OWNER TO hgarduno;

--
-- Name: tipoprecio; Type: TABLE; Schema: public; Owner: hgarduno; Tablespace: 
--

CREATE TABLE tipoprecio (
    nmbtipoprecio character varying(25) NOT NULL,
    descripcion character varying(256),
    tipo character varying(10)
);


ALTER TABLE public.tipoprecio OWNER TO hgarduno;

--
-- Name: tipospersona; Type: TABLE; Schema: public; Owner: hgarduno; Tablespace: 
--

CREATE TABLE tipospersona (
    tipopersona integer NOT NULL,
    nmbtipopersona character varying(250),
    dsctipopersona character varying(250)
);


ALTER TABLE public.tipospersona OWNER TO hgarduno;

--
-- Name: unidades; Type: TABLE; Schema: public; Owner: hgarduno; Tablespace: 
--

CREATE TABLE unidades (
    unidad integer NOT NULL,
    nmbunidad character varying(25),
    abreviatura character varying(10)
);


ALTER TABLE public.unidades OWNER TO hgarduno;

--
-- Name: vehiculos; Type: TABLE; Schema: public; Owner: hgarduno; Tablespace: 
--

CREATE TABLE vehiculos (
    idvehiculo integer NOT NULL,
    placas character varying(25),
    dscvehiculo character varying(50)
);


ALTER TABLE public.vehiculos OWNER TO hgarduno;

--
-- Name: ventas; Type: TABLE; Schema: public; Owner: hgarduno; Tablespace: 
--

CREATE TABLE ventas (
    idexpendio integer,
    idventa integer,
    fechahora timestamp without time zone,
    cveproducto character varying(25),
    cantidad numeric(10,2),
    importe numeric(10,2),
    precio numeric(10,2),
    vendedor integer,
    cliente integer
);


ALTER TABLE public.ventas OWNER TO hgarduno;

--
-- Name: empresas_pkey; Type: CONSTRAINT; Schema: public; Owner: hgarduno; Tablespace: 
--

ALTER TABLE ONLY empresas
    ADD CONSTRAINT empresas_pkey PRIMARY KEY (idempresa);


--
-- Name: estadospedido_pkey; Type: CONSTRAINT; Schema: public; Owner: hgarduno; Tablespace: 
--

ALTER TABLE ONLY estadospedido
    ADD CONSTRAINT estadospedido_pkey PRIMARY KEY (idedopedido);


--
-- Name: familias_pkey; Type: CONSTRAINT; Schema: public; Owner: hgarduno; Tablespace: 
--

ALTER TABLE ONLY familias
    ADD CONSTRAINT familias_pkey PRIMARY KEY (idfamilia);


--
-- Name: matriz_pkey; Type: CONSTRAINT; Schema: public; Owner: hgarduno; Tablespace: 
--

ALTER TABLE ONLY matriz
    ADD CONSTRAINT matriz_pkey PRIMARY KEY (idempresa);


--
-- Name: no_rep; Type: CONSTRAINT; Schema: public; Owner: hgarduno; Tablespace: 
--

ALTER TABLE ONLY apodos
    ADD CONSTRAINT no_rep PRIMARY KEY (idpersona);


--
-- Name: pedido; Type: CONSTRAINT; Schema: public; Owner: hgarduno; Tablespace: 
--

ALTER TABLE ONLY estadodelpedido
    ADD CONSTRAINT pedido UNIQUE (numpedido, idedopedido);


--
-- Name: pedidos_pkey; Type: CONSTRAINT; Schema: public; Owner: hgarduno; Tablespace: 
--

ALTER TABLE ONLY pedidos
    ADD CONSTRAINT pedidos_pkey PRIMARY KEY (numpedido);


--
-- Name: personas_pkey; Type: CONSTRAINT; Schema: public; Owner: hgarduno; Tablespace: 
--

ALTER TABLE ONLY personas
    ADD CONSTRAINT personas_pkey PRIMARY KEY (nombre, apaterno, amaterno);


--
-- Name: precios_pkey; Type: CONSTRAINT; Schema: public; Owner: hgarduno; Tablespace: 
--

ALTER TABLE ONLY precios
    ADD CONSTRAINT precios_pkey PRIMARY KEY (cveproducto, nmbtipoprecio, idpersona);


--
-- Name: productos_pkey; Type: CONSTRAINT; Schema: public; Owner: hgarduno; Tablespace: 
--

ALTER TABLE ONLY productos
    ADD CONSTRAINT productos_pkey PRIMARY KEY (cveproducto);


--
-- Name: ss_d; Type: CONSTRAINT; Schema: public; Owner: hgarduno; Tablespace: 
--

ALTER TABLE ONLY existencias
    ADD CONSTRAINT ss_d UNIQUE (cveproducto, idexpendio);


--
-- Name: tipoprecio_pkey; Type: CONSTRAINT; Schema: public; Owner: hgarduno; Tablespace: 
--

ALTER TABLE ONLY tipoprecio
    ADD CONSTRAINT tipoprecio_pkey PRIMARY KEY (nmbtipoprecio);


--
-- Name: tipospersona_pkey; Type: CONSTRAINT; Schema: public; Owner: hgarduno; Tablespace: 
--

ALTER TABLE ONLY tipospersona
    ADD CONSTRAINT tipospersona_pkey PRIMARY KEY (tipopersona);


--
-- Name: unidades_pkey; Type: CONSTRAINT; Schema: public; Owner: hgarduno; Tablespace: 
--

ALTER TABLE ONLY unidades
    ADD CONSTRAINT unidades_pkey PRIMARY KEY (unidad);


--
-- Name: vehiculos_pkey; Type: CONSTRAINT; Schema: public; Owner: hgarduno; Tablespace: 
--

ALTER TABLE ONLY vehiculos
    ADD CONSTRAINT vehiculos_pkey PRIMARY KEY (idvehiculo);


--
-- Name: compras_cveproducto_fkey; Type: FK CONSTRAINT; Schema: public; Owner: hgarduno
--

ALTER TABLE ONLY compras
    ADD CONSTRAINT compras_cveproducto_fkey FOREIGN KEY (cveproducto) REFERENCES productos(cveproducto);


--
-- Name: detallepedido_cveproducto_fkey; Type: FK CONSTRAINT; Schema: public; Owner: hgarduno
--

ALTER TABLE ONLY detallepedido
    ADD CONSTRAINT detallepedido_cveproducto_fkey FOREIGN KEY (cveproducto) REFERENCES productos(cveproducto);


--
-- Name: matriz_idempresa_fkey; Type: FK CONSTRAINT; Schema: public; Owner: hgarduno
--

ALTER TABLE ONLY matriz
    ADD CONSTRAINT matriz_idempresa_fkey FOREIGN KEY (idempresa) REFERENCES empresas(idempresa);


--
-- Name: personas_tipopersona_fkey; Type: FK CONSTRAINT; Schema: public; Owner: hgarduno
--

ALTER TABLE ONLY personas
    ADD CONSTRAINT personas_tipopersona_fkey FOREIGN KEY (tipopersona) REFERENCES tipospersona(tipopersona);


--
-- Name: precios_cveproducto_fkey; Type: FK CONSTRAINT; Schema: public; Owner: hgarduno
--

ALTER TABLE ONLY precios
    ADD CONSTRAINT precios_cveproducto_fkey FOREIGN KEY (cveproducto) REFERENCES productos(cveproducto);


--
-- Name: precios_nmbtipoprecio_fkey; Type: FK CONSTRAINT; Schema: public; Owner: hgarduno
--

ALTER TABLE ONLY precios
    ADD CONSTRAINT precios_nmbtipoprecio_fkey FOREIGN KEY (nmbtipoprecio) REFERENCES tipoprecio(nmbtipoprecio);


--
-- Name: productos_idfamilia_fkey; Type: FK CONSTRAINT; Schema: public; Owner: hgarduno
--

ALTER TABLE ONLY productos
    ADD CONSTRAINT productos_idfamilia_fkey FOREIGN KEY (idfamilia) REFERENCES familias(idfamilia);


--
-- Name: productos_unidad_fkey; Type: FK CONSTRAINT; Schema: public; Owner: hgarduno
--

ALTER TABLE ONLY productos
    ADD CONSTRAINT productos_unidad_fkey FOREIGN KEY (unidad) REFERENCES unidades(unidad);


--
-- Name: ventas_idexpendio_fkey; Type: FK CONSTRAINT; Schema: public; Owner: hgarduno
--

ALTER TABLE ONLY ventas
    ADD CONSTRAINT ventas_idexpendio_fkey FOREIGN KEY (idexpendio) REFERENCES empresas(idempresa);


--
-- Name: public; Type: ACL; Schema: -; Owner: postgres813
--

REVOKE ALL ON SCHEMA public FROM PUBLIC;
REVOKE ALL ON SCHEMA public FROM postgres813;
GRANT ALL ON SCHEMA public TO postgres813;
GRANT ALL ON SCHEMA public TO PUBLIC;


--
-- PostgreSQL database dump complete
--

