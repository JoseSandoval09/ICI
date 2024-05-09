-- phpMyAdmin SQL Dump
-- version 5.2.1
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Generation Time: Jun 14, 2023 at 09:19 PM
-- Server version: 10.4.28-MariaDB
-- PHP Version: 8.1.17

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `little`
--

-- --------------------------------------------------------

--
-- Table structure for table `pacientes`
--

CREATE TABLE `pacientes` (
  `ID` int(8) NOT NULL,
  `namebebe` text NOT NULL,
  `datebday` date NOT NULL,
  `namedad` text NOT NULL,
  `tel` int(11) NOT NULL,
  `dire` varchar(50) NOT NULL,
  `alerg` tinyint(4) NOT NULL,
  `alergW` text NOT NULL,
  `medicT` tinyint(4) NOT NULL,
  `medicTW` text NOT NULL,
  `center` tinyint(4) NOT NULL,
  `centerW` text NOT NULL,
  `acenter` tinyint(4) NOT NULL,
  `obje` int(4) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `pacientes`
--

INSERT INTO `pacientes` (`ID`, `namebebe`, `datebday`, `namedad`, `tel`, `dire`, `alerg`, `alergW`, `medicT`, `medicTW`, `center`, `centerW`, `acenter`, `obje`) VALUES
(3, 'Ximena Rivera', '2023-06-03', 'Rocio Delgadillo', 2147483647, ' Avenida la paz 102', 2, 'Nada', 2, 'Ninguno', 2, 'Ninguno', 0, 3),
(4, 'José Luis Sandoval', '2023-06-03', 'José Sandoval', 2147483647, ' Colonia el Dorado', 1, 'Abispas', 1, 'Fisioterapia', 1, 'StarMedica', 1, 1),
(5, 'Stephany Rivera', '2023-06-03', 'Monica Rivera', 0, ' Reserva San Cristobal', 1, 'Coco', 1, 'Fisioterapia', 1, 'ISSTE', 1, 1),
(6, 'Jose Israel', '2023-06-03', 'Jose Rivera', 1234567, ' Tulipanes 209', 2, 'Nada', 2, 'Ninguno', 2, 'Ninguno', 2, 1);

--
-- Indexes for dumped tables
--

--
-- Indexes for table `pacientes`
--
ALTER TABLE `pacientes`
  ADD PRIMARY KEY (`ID`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `pacientes`
--
ALTER TABLE `pacientes`
  MODIFY `ID` int(8) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=7;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
