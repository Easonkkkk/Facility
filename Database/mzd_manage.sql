/*
Navicat MySQL Data Transfer

Source Server         : mzd
Source Server Version : 50617
Source Host           : localhost:3306
Source Database       : mzd_manage

Target Server Type    : MYSQL
Target Server Version : 50617
File Encoding         : 65001

Date: 2021-04-21 22:51:11
*/

SET FOREIGN_KEY_CHECKS=0;

-- ----------------------------
-- Table structure for `admin`
-- ----------------------------
DROP TABLE IF EXISTS `admin`;
CREATE TABLE `admin` (
  `admin_id` varchar(100) CHARACTER SET utf8 COLLATE utf8_bin NOT NULL,
  `admin_name` varchar(100) CHARACTER SET utf8 COLLATE utf8_bin NOT NULL,
  `admin_depart` varchar(100) NOT NULL,
  `admin_phone` int(20) NOT NULL,
  `admin_email` varchar(100) NOT NULL,
  `admin_warehouse` varchar(100) NOT NULL,
  PRIMARY KEY (`admin_id`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- ----------------------------
-- Records of admin
-- ----------------------------
INSERT INTO `admin` VALUES ('1', 'mzd', '1', '11', '11', '100');

-- ----------------------------
-- Table structure for `borrow`
-- ----------------------------
DROP TABLE IF EXISTS `borrow`;
CREATE TABLE `borrow` (
  `user_id` varchar(100) CHARACTER SET utf8 COLLATE utf8_bin NOT NULL,
  `equitment_id` varchar(100) CHARACTER SET utf8 COLLATE utf8_bin NOT NULL,
  `borrow_time` varchar(20) CHARACTER SET utf8 COLLATE utf8_bin NOT NULL,
  `borrow_account` varchar(20) CHARACTER SET utf8 COLLATE utf8_bin NOT NULL,
  PRIMARY KEY (`user_id`,`equitment_id`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- ----------------------------
-- Records of borrow
-- ----------------------------
INSERT INTO `borrow` VALUES ('A00123', '1902', '2020-3-23', 'A00123');
INSERT INTO `borrow` VALUES ('A00345', '1901', '2020-4-2', 'A00345');

-- ----------------------------
-- Table structure for `equipment`
-- ----------------------------
DROP TABLE IF EXISTS `equipment`;
CREATE TABLE `equipment` (
  `equipment_id` varchar(100) CHARACTER SET utf8 COLLATE utf8_bin NOT NULL,
  `equipment_name` varchar(20) CHARACTER SET utf8 COLLATE utf8_bin NOT NULL,
  `equipment_img` varchar(100) CHARACTER SET utf8 COLLATE utf8_bin NOT NULL DEFAULT '1',
  `equipment_label` varchar(10) CHARACTER SET utf8 COLLATE utf8_bin NOT NULL DEFAULT '',
  `equipment_model` varchar(20) CHARACTER SET utf8 COLLATE utf8_bin NOT NULL,
  `equipment_state` varchar(20) CHARACTER SET utf8 COLLATE utf8_bin NOT NULL DEFAULT '0',
  `equipment_position` varchar(30) CHARACTER SET utf8 COLLATE utf8_bin NOT NULL,
  `equipment_intro` varchar(500) CHARACTER SET utf8 COLLATE utf8_bin DEFAULT NULL,
  `eqiuipment_damage` varchar(100) CHARACTER SET utf8 COLLATE utf8_bin NOT NULL DEFAULT '0',
  `equipment_depart` varchar(100) CHARACTER SET utf8 COLLATE utf8_bin NOT NULL,
  `equipment_rfid` varchar(100) CHARACTER SET utf8 COLLATE utf8_bin NOT NULL,
  `equipment_EPC` varchar(100) CHARACTER SET utf8 COLLATE utf8_bin NOT NULL,
  PRIMARY KEY (`equipment_id`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- ----------------------------
-- Records of equipment
-- ----------------------------
INSERT INTO `equipment` VALUES ('1091', '指针式万用表', '123', '1', 'MF-47', '已出库', '10-18-3', '设备丢失', '1', '生产部', '10001001', '');
INSERT INTO `equipment` VALUES ('1902', '梳式文本订书机', '123', '1', 'GD52000B', '已出库', '10-19-1', '0', '0', '生产部', '10001002', '');
INSERT INTO `equipment` VALUES ('1903', '齐心加厚订书机', '123', '1', 'B3061', '未出库', '10-19-3', '0', '0', '生产部', '10001003', '');
INSERT INTO `equipment` VALUES ('1906', '高精度电流互感器', '123', '1', 'CTA60', '未出库', '10-20-4', '0', '0', '生产部', '10002001', '');
INSERT INTO `equipment` VALUES ('1907', '多功能控制板', '123', '1', 'GMX-2K', '未出库', '10-21-1', '0', '0', '生产部', '10002002', '');
INSERT INTO `equipment` VALUES ('2000', '手机1', '1', '重点设备', 'TX-1001', '0', '11-06-4', null, '0', 'production', '10000299', '');
INSERT INTO `equipment` VALUES ('2097', '建材烟密度测试仪', '123', '0', 'JCY-3', '未出库', '2-10-3', '0', '0', '生产部', '10002003', '');

-- ----------------------------
-- Table structure for `key_equipment`
-- ----------------------------
DROP TABLE IF EXISTS `key_equipment`;
CREATE TABLE `key_equipment` (
  `equipment_id` varchar(100) CHARACTER SET utf8 COLLATE utf8_bin NOT NULL,
  `equipment_name` varchar(20) CHARACTER SET utf8 COLLATE utf8_bin NOT NULL,
  `equipment_img` varchar(100) CHARACTER SET utf8 COLLATE utf8_bin NOT NULL,
  `equipment_label` varchar(10) CHARACTER SET utf8 COLLATE utf8_bin NOT NULL,
  `equipment_model` varchar(20) CHARACTER SET utf8 COLLATE utf8_bin NOT NULL,
  `equipment_state` varchar(20) CHARACTER SET utf8 COLLATE utf8_bin NOT NULL,
  `equipment_position` varchar(30) CHARACTER SET utf8 COLLATE utf8_bin NOT NULL,
  `equipment_intro` varchar(500) CHARACTER SET utf8 COLLATE utf8_bin NOT NULL,
  `equipment_damage` varchar(100) CHARACTER SET utf8 COLLATE utf8_bin NOT NULL,
  `equipment_EPC` varchar(100) NOT NULL,
  PRIMARY KEY (`equipment_id`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- ----------------------------
-- Records of key_equipment
-- ----------------------------
INSERT INTO `key_equipment` VALUES ('1902', '梳式文本订书机', '123', '重要设备', 'GD52000B', '已出库', '10-19-1', '0', '0', '123456789012');
INSERT INTO `key_equipment` VALUES ('1903', '齐心加厚订书机', '123', '重要设备', 'B3061', '未出库', '10-19-3', '0', '0', '213451234512');
INSERT INTO `key_equipment` VALUES ('1906', '高精度电流互感器', '123', '重要设备', 'CTA60', '未出库', '10-20-4', '0', '0', '321453235512');
INSERT INTO `key_equipment` VALUES ('1907', '多功能控制板', '123', '重要设备', 'GMX-2K', '未出库', '10-21-1', '0', '0', '325462312421');
INSERT INTO `key_equipment` VALUES ('2097', '建材烟密度测试仪', '123', '重要设备', 'JCY-3', '未出库', '2-10-3', '0', '0', '562355423135');
INSERT INTO `key_equipment` VALUES ('991', '指针式万用表', '123', '重要设备', 'MF-47', '已出库', '10-18-3', '仓库门口检测到该设备', '1', '245614212451');

-- ----------------------------
-- Table structure for `rt_check`
-- ----------------------------
DROP TABLE IF EXISTS `rt_check`;
CREATE TABLE `rt_check` (
  `check_id` varchar(100) CHARACTER SET utf8 COLLATE utf8_bin NOT NULL,
  `equitment_id` varchar(100) CHARACTER SET utf8 COLLATE utf8_bin NOT NULL,
  `abnormal_info` varchar(100) CHARACTER SET utf8 COLLATE utf8_bin NOT NULL,
  `check_time` varchar(100) CHARACTER SET utf8 COLLATE utf8_bin NOT NULL,
  PRIMARY KEY (`check_id`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- ----------------------------
-- Records of rt_check
-- ----------------------------
INSERT INTO `rt_check` VALUES ('1', '1091', '设备离开检测范围', '2020/4/12/16:30');
INSERT INTO `rt_check` VALUES ('2', '1902', '设备信号弱', '2020/4/2/16:30');
INSERT INTO `rt_check` VALUES ('3', '1903', '设备位置错误', '2020/4/2/16:30');
INSERT INTO `rt_check` VALUES ('4', '1906', '设备位置错误', '2020/4/15/22:41');

-- ----------------------------
-- Table structure for `user`
-- ----------------------------
DROP TABLE IF EXISTS `user`;
CREATE TABLE `user` (
  `user_id` varchar(100) CHARACTER SET utf8 COLLATE utf8_bin NOT NULL,
  `user_name` varchar(100) CHARACTER SET utf8 COLLATE utf8_bin NOT NULL,
  `user_level` varchar(100) CHARACTER SET utf8 COLLATE utf8_bin NOT NULL,
  `user_department` varchar(100) CHARACTER SET utf8 COLLATE utf8_bin DEFAULT NULL,
  `user_phone` int(20) NOT NULL,
  `user_email` varchar(100) CHARACTER SET utf8 COLLATE utf8_bin NOT NULL,
  `user_position` varchar(100) CHARACTER SET utf8 COLLATE utf8_bin NOT NULL,
  `user_password` varchar(100) CHARACTER SET utf8 COLLATE utf8_bin NOT NULL,
  PRIMARY KEY (`user_id`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- ----------------------------
-- Records of user
-- ----------------------------

-- ----------------------------
-- Table structure for `warehouse`
-- ----------------------------
DROP TABLE IF EXISTS `warehouse`;
CREATE TABLE `warehouse` (
  `warehouse_id` varchar(100) CHARACTER SET utf8 COLLATE utf8_bin NOT NULL,
  PRIMARY KEY (`warehouse_id`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- ----------------------------
-- Records of warehouse
-- ----------------------------
