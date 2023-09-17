-- phpMyAdmin SQL Dump
-- version 4.5.1
-- http://www.phpmyadmin.net
--
-- Client :  localhost:3306
-- Généré le :  Mar 26 Janvier 2016 à 20:28
-- Version du serveur :  10.0.22-MariaDB-0+deb8u1
-- Version de PHP :  5.6.14

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Base de données :  `TIMER_2015`
--

-- --------------------------------------------------------

--
-- Structure de la table `timercheckpoints`
--

CREATE TABLE `timercheckpoints` (
  `id` int(11) NOT NULL,
  `steamid` varchar(32) CHARACTER SET utf8 DEFAULT NULL,
  `name` varchar(32) CHARACTER SET utf8 DEFAULT NULL,
  `map` varchar(150) CHARACTER SET utf8 DEFAULT NULL,
  `level` int(10) DEFAULT NULL,
  `levelname` varchar(60) CHARACTER SET utf8 DEFAULT NULL,
  `time` float DEFAULT NULL,
  `track` int(11) DEFAULT NULL,
  `style` int(11) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Structure de la table `timercheckpoints_wr`
--

CREATE TABLE `timercheckpoints_wr` (
  `id` int(11) NOT NULL,
  `steamid` varchar(32) CHARACTER SET utf8 DEFAULT NULL,
  `name` varchar(32) CHARACTER SET utf8 DEFAULT NULL,
  `map` varchar(150) CHARACTER SET utf8 DEFAULT NULL,
  `level` int(10) DEFAULT NULL,
  `levelname` varchar(60) CHARACTER SET utf8 DEFAULT NULL,
  `time` float DEFAULT NULL,
  `track` int(11) DEFAULT NULL,
  `style` int(11) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Index pour les tables exportées
--

--
-- Index pour la table `timercheckpoints`
--
ALTER TABLE `timercheckpoints`
  ADD PRIMARY KEY (`id`);

--
-- Index pour la table `timercheckpoints_wr`
--
ALTER TABLE `timercheckpoints_wr`
  ADD PRIMARY KEY (`id`);

--
-- AUTO_INCREMENT pour les tables exportées
--

--
-- AUTO_INCREMENT pour la table `timercheckpoints`
--
ALTER TABLE `timercheckpoints`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=201;
--
-- AUTO_INCREMENT pour la table `timercheckpoints_wr`
--
ALTER TABLE `timercheckpoints_wr`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=24;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
