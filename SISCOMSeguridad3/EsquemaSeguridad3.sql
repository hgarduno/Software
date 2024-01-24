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
-- Name: propiedades; Type: TABLE; Schema: public; Owner: hgarduno; Tablespace: 
--

CREATE TABLE propiedades (
    idobjeto integer NOT NULL,
    idpropiedad integer NOT NULL,
    nmbpropiedad character varying(30)
);


ALTER TABLE public.propiedades OWNER TO hgarduno;

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
-- Name: aplicaciones_pkey; Type: CONSTRAINT; Schema: public; Owner: hgarduno; Tablespace: 
--

ALTER TABLE ONLY aplicaciones
    ADD CONSTRAINT aplicaciones_pkey PRIMARY KEY (idaplicacion);


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
-- Name: perfiles_pkey; Type: CONSTRAINT; Schema: public; Owner: hgarduno; Tablespace: 
--

ALTER TABLE ONLY perfiles
    ADD CONSTRAINT perfiles_pkey PRIMARY KEY (idaplicacion, nmbperfil);


--
-- Name: propiedades_pkey; Type: CONSTRAINT; Schema: public; Owner: hgarduno; Tablespace: 
--

ALTER TABLE ONLY propiedades
    ADD CONSTRAINT propiedades_pkey PRIMARY KEY (idobjeto, idpropiedad);


--
-- Name: usuarios_pkey; Type: CONSTRAINT; Schema: public; Owner: hgarduno; Tablespace: 
--

ALTER TABLE ONLY usuarios
    ADD CONSTRAINT usuarios_pkey PRIMARY KEY (idusuario);


--
-- Name: firmas_idusuario_fkey; Type: FK CONSTRAINT; Schema: public; Owner: hgarduno
--

ALTER TABLE ONLY firmas
    ADD CONSTRAINT firmas_idusuario_fkey FOREIGN KEY (idusuario) REFERENCES usuarios(idusuario);


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
-- Name: propiedades_idobjeto_fkey; Type: FK CONSTRAINT; Schema: public; Owner: hgarduno
--

ALTER TABLE ONLY propiedades
    ADD CONSTRAINT propiedades_idobjeto_fkey FOREIGN KEY (idobjeto) REFERENCES objeto(idobjeto);


--
-- Name: usuarios_idaplicacion_fkey; Type: FK CONSTRAINT; Schema: public; Owner: hgarduno
--

ALTER TABLE ONLY usuarios
    ADD CONSTRAINT usuarios_idaplicacion_fkey FOREIGN KEY (idaplicacion) REFERENCES aplicaciones(idaplicacion);


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

