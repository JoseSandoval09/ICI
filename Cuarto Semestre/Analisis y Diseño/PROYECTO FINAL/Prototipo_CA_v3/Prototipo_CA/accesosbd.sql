-- phpMyAdmin SQL Dump
-- version 5.2.0
-- https://www.phpmyadmin.net/
--
-- Servidor: 127.0.0.1
-- Tiempo de generación: 12-06-2023 a las 22:03:54
-- Versión del servidor: 10.4.25-MariaDB
-- Versión de PHP: 8.1.10

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Base de datos: `accesosbd`
--

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `accesosemana`
--

CREATE TABLE `accesosemana` (
  `ID` int(11) NOT NULL,
  `DiaSemana` varchar(15) COLLATE utf8mb4_spanish_ci NOT NULL,
  `HoraInicio` varchar(10) COLLATE utf8mb4_spanish_ci NOT NULL,
  `HoraFin` varchar(10) COLLATE utf8mb4_spanish_ci NOT NULL,
  `FKIDGrupoPersona` int(11) NOT NULL,
  `FKIDGrupoPuerta` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_spanish_ci;

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `grupopersona`
--

CREATE TABLE `grupopersona` (
  `ID` int(11) NOT NULL,
  `Nombre` varchar(50) COLLATE utf8mb4_spanish_ci NOT NULL,
  `Descripcion` varchar(80) COLLATE utf8mb4_spanish_ci NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_spanish_ci;

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `grupopuerta`
--

CREATE TABLE `grupopuerta` (
  `ID` int(11) NOT NULL,
  `Nombre` int(50) NOT NULL,
  `Descripcion` int(80) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_spanish_ci;

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `persona`
--

CREATE TABLE `persona` (
  `ID` int(11) NOT NULL,
  `Nombre` varchar(80) COLLATE utf8mb4_spanish_ci NOT NULL,
  `Telefono` varchar(20) COLLATE utf8mb4_spanish_ci NOT NULL,
  `Correo` varchar(50) COLLATE utf8mb4_spanish_ci NOT NULL,
  `Contrasena` varchar(20) COLLATE utf8mb4_spanish_ci NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_spanish_ci;

--
-- Volcado de datos para la tabla `persona`
--

INSERT INTO `persona` (`ID`, `Nombre`, `Telefono`, `Correo`, `Contrasena`) VALUES
(4, 'Apolonio Sandoval', '123-123-1234', 'soyguapo@hotmail.com', 'tachasypericos2'),
(5, 'Taylor Swift', '131-313-1313', 'taytay@gmail.com', 'midnights1989');

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `personasengrupo`
--

CREATE TABLE `personasengrupo` (
  `ID` int(11) NOT NULL,
  `FKIDPersona` int(11) NOT NULL,
  `FKIDGrupoPersona` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_spanish_ci;

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `puerta`
--

CREATE TABLE `puerta` (
  `ID` int(11) NOT NULL,
  `Zona` varchar(50) COLLATE utf8mb4_spanish_ci NOT NULL,
  `Descripcion` varchar(80) COLLATE utf8mb4_spanish_ci NOT NULL,
  `FKIdGrupoPuerta` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_spanish_ci;

--
-- Volcado de datos para la tabla `puerta`
--

INSERT INTO `puerta` (`ID`, `Zona`, `Descripcion`, `FKIdGrupoPuerta`) VALUES
(2, 'Laboratorio', 'Se realizan pruebas de deteccion de fiebre de mono', 0),
(3, 'Compton', 'Straight out of Compton', 3);

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `semanatipo`
--

CREATE TABLE `semanatipo` (
  `ID` int(11) NOT NULL,
  `DiaSemana` varchar(15) COLLATE utf8mb4_spanish_ci NOT NULL,
  `HoraInicio` varchar(10) COLLATE utf8mb4_spanish_ci NOT NULL,
  `HoraFin` varchar(10) COLLATE utf8mb4_spanish_ci NOT NULL,
  `Descripcion` varchar(80) COLLATE utf8mb4_spanish_ci NOT NULL,
  `FKIDGrupoPersona` int(11) NOT NULL,
  `FKIDGrupoPuerta` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_spanish_ci;

--
-- Índices para tablas volcadas
--

--
-- Indices de la tabla `accesosemana`
--
ALTER TABLE `accesosemana`
  ADD PRIMARY KEY (`ID`);

--
-- Indices de la tabla `grupopersona`
--
ALTER TABLE `grupopersona`
  ADD PRIMARY KEY (`ID`);

--
-- Indices de la tabla `grupopuerta`
--
ALTER TABLE `grupopuerta`
  ADD PRIMARY KEY (`ID`);

--
-- Indices de la tabla `persona`
--
ALTER TABLE `persona`
  ADD PRIMARY KEY (`ID`);

--
-- Indices de la tabla `personasengrupo`
--
ALTER TABLE `personasengrupo`
  ADD PRIMARY KEY (`ID`);

--
-- Indices de la tabla `puerta`
--
ALTER TABLE `puerta`
  ADD PRIMARY KEY (`ID`);

--
-- Indices de la tabla `semanatipo`
--
ALTER TABLE `semanatipo`
  ADD PRIMARY KEY (`ID`);

--
-- AUTO_INCREMENT de las tablas volcadas
--

--
-- AUTO_INCREMENT de la tabla `accesosemana`
--
ALTER TABLE `accesosemana`
  MODIFY `ID` int(11) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT de la tabla `grupopersona`
--
ALTER TABLE `grupopersona`
  MODIFY `ID` int(11) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT de la tabla `grupopuerta`
--
ALTER TABLE `grupopuerta`
  MODIFY `ID` int(11) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT de la tabla `persona`
--
ALTER TABLE `persona`
  MODIFY `ID` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=6;

--
-- AUTO_INCREMENT de la tabla `personasengrupo`
--
ALTER TABLE `personasengrupo`
  MODIFY `ID` int(11) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT de la tabla `puerta`
--
ALTER TABLE `puerta`
  MODIFY `ID` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=4;

--
-- AUTO_INCREMENT de la tabla `semanatipo`
--
ALTER TABLE `semanatipo`
  MODIFY `ID` int(11) NOT NULL AUTO_INCREMENT;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
