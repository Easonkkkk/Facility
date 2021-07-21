/*
Navicat MySQL Data Transfer

Source Server         : mzd
Source Server Version : 50617
Source Host           : localhost:3306
Source Database       : arcsoft_face_demo

Target Server Type    : MYSQL
Target Server Version : 50617
File Encoding         : 65001

Date: 2021-04-06 21:16:28
*/

SET FOREIGN_KEY_CHECKS=0;

-- ----------------------------
-- Table structure for `user_face_info`
-- ----------------------------
DROP TABLE IF EXISTS `user_face_info`;
CREATE TABLE `user_face_info` (
  `id` int(11) NOT NULL AUTO_INCREMENT COMMENT '主键',
  `group_id` int(11) DEFAULT NULL COMMENT '分组id',
  `face_id` varchar(31) DEFAULT NULL COMMENT '人脸唯一Id',
  `name` varchar(63) DEFAULT NULL COMMENT '名字',
  `age` int(3) DEFAULT NULL COMMENT '年纪',
  `email` varchar(255) DEFAULT NULL COMMENT '邮箱地址',
  `gender` smallint(1) DEFAULT NULL COMMENT '性别，1=男，2=女',
  `phone_number` varchar(11) DEFAULT NULL COMMENT '电话号码',
  `face_feature` blob COMMENT '人脸特征',
  `create_time` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP COMMENT '创建时间',
  `update_time` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP COMMENT '更新时间',
  `fpath` varchar(255) DEFAULT NULL COMMENT '照片路径',
  PRIMARY KEY (`id`) USING BTREE,
  KEY `GROUP_ID` (`group_id`) USING BTREE
) ENGINE=InnoDB AUTO_INCREMENT=7 DEFAULT CHARSET=utf8mb4 ROW_FORMAT=DYNAMIC;

-- ----------------------------
-- Records of user_face_info
-- ----------------------------
INSERT INTO `user_face_info` VALUES ('1', '101', 'jwwjjoe950', '嗷嗷', null, null, null, null, 0x0080FA440000A0411536CC3C2FF30C3D33B06A3C5B749ABD6376883D13A3193D2CB3BEBDBE62A6BBB99219BD40BC56BD3E2ED7BC5B79773D29A70F3E2D71EF3C5625CF3C64F877BC6EEB03BD107B0D3D0FEE56BD6D00663D5248B43B3682CBBDFBE14FBC5735B539AA6EF23CDAFF9A3DA0B2D3B91C42C2BD13187EBC94C7093EB9D593BCABE4A4BB7F6EF13C3E68C93D4A6709BECEC7C3BCD40109BDCBEA4DBD75C6D43DCAD3213C2941843D0088BABDDC697B3D0E110CBD79508D3CD445BA3CEEDB063ECC7F0FBD1760A3BB099F033C5A5B343CD1D1C0BDCE149A3C16BECB3C22A95ABC74FA47BC816436BDD27F08BD51B3A33D147B813D336F97B7AFF9793D891A00BC37B9CB3B70E7A33CF426C23D67B5E53C01C2D0BD32A8293D71F631BD0322C9BA212E28BBB21284BD3FB399BD344FF1BC5EEC003DFD0FE33DDA38FABC4D043BBDBBBA6EBDF9DFAFBD677B8B3D82234ABD710ABABD178DC53C1CF9E83D7754FCBCC9CC323D3DD590BA0B5C32BD1D4D363CB0A9453DA15745BDA2294B3C7C1591BDD1F7FABD3F5E54BC129FB8BD2918CD3CE054D23CACB4ECBC8FCFB8BDB2C8253D7A2830BC36DC0FBD263AE4BDA59C533D1D7D2B3D51DB08BED0B5B53DB704203D7A0DB1BB6163A03C39D28B3C938B76BD593C5BBD5695A43B7EC2BE3DE4EB0D3B7CD2B5BD87C0573D492EE3BC52CEDF3DF4B7EC3DF725C73D33A086B9D507543D65D0913C839393BDC5CA9EBDCFB1023EE23B04BE66B7943D4380A2BC8C27BF3CAAF21C3DB7991FBEC0379C3D1269CB3D9289E6BD8346C53B22264EBDEA4FDC3D1639EC3C31159B3D746F3F3DF94CB63D762C7B3C5D88DABC57801C3CA5AD963D4D9ECF3C5ED3363DB9BDC13CA5F32EBC5D58533D8B87473CE786C7BC6F1AECBC24A0103DEDAF86BD83956B3D9CCFC0BCE69C663DEB2E9EBDD160CCBC6AA8FFBC9D2D23BDFC7FA73D8A5A543D3D2DBB3CDCAF2ABD3AC1DABCE77B833D015AA13CAB5462BDC0FD0F3DF6C478BA77719ABC1C0D213EC13EE3BD70DC21BD943B8DBB43C9C4BD1D2439BDE5415A3B060B3ABB79C1B2BDB371203DCCC291BD81A2F23D431B99BB41C9013CCDC5CBBC5308D0BB10CF44BDC38D913BD28BD1BDA70BEC3D9DAD333C0BB1F1BCA9AD553D42D2303D1C82B93C1E0B523DDD919E3D9B73AFBD3768073DA9F2FB3DAB8EC03C6F628D3BF3A4973DE2454C3D569E2EBD7B1194BD5B8F8E3A1CEE02BD0C050FBD130921BEB30182396EB47BBD574D08BC84AA0F3C0DADB5BDE792F03D8B3601BEEC6534BE721A65BDD3FFAE3B217B09BDD002223DD281C03D5767223D2938B83D13AD453DA74C943D9D2C49BDDF529EBCC3B2223DB179D0BCA1F06B3D4149553D5215AABCA3AB67BD85BC973D2C8A7D3DE2D240BD506DBE3DE97CC1BD71A70C3D71FF8C3DF5BECABDA987CC3D206E8EBC8526453D8DC7D0BC, '2021-04-01 21:57:27', '2021-04-01 21:57:27', null);
INSERT INTO `user_face_info` VALUES ('2', '101', 'uf471nvgx6', '屠依婷', null, null, null, null, 0x0080FA440000A0415AF19FBC7EFDF4BD6215FD3BBEDAD5BCAD4CCDBDC2DE9F3DEEA40FBB2FA1A9BDB85154BEE8AAC03B073CD3BDF1027E3D06174F3D368EC7BCD0B7CF3DA489293AE719593DF962163D46B6D2BC30E89C3D3C7908BD5B1E0ABD6CA733BDA52F73BD5963463D73465FBD276D1CBDD98A15BC121C0BBDA04C2CBD9D8404BD85469D3DEFF2F6BC78F166BC4704D2BDABB4E33C7EF1133C5B1CDABDA02503BC2BF1CE3DA067433DCB13C1BD9A61FABCB869C13C48953D3DD42818BE2E3DD43D12212FBC503FEC3C2E75E3BAAAD6CD3D6E1D5D3D4D45393C27673C3C637D893C89ECE8BCF9883CBDFC71D7BD675CE63C0B47703C5637B13CC0542ABDE81DC43DD447A0BC3652A0BDD882FDBDEBBCCFBD44FEC0BC329E513DBEB61B3D8AC488BD9B93B53D8F0FAF3C9E186CBD3EA010BD442FDB3C2DAE4F3D29C5073CAF5608BE3EDCF33CF2B0AC3D2DAF81BD112CB23DA343A2BA85489F3D0ECD523DF7DA02BE00E984BB0348583DFBEFC33DE6E2B6BCCA993B3C8502D63B3ED45D3D6E88C8BD71AB2B3C9CE391BDDF35113CA47990BDF81264BC294D8E3CA22A2EBC286583BCF0F3D5BA65FCBD3DE6EC7D3D818C883D0D006C3DBD4701BD4894A8BDEEA4073D0A05BA3C871297BD53D706BEAE2AA43D19E004BED94A523DDF53613C5766063CA80D89BCFC734EBCBE3ABF3CA2E16DBCF21EB5390B3F80BD2C1996BA27FB43BB913F87BCAAA4AEBBB7AEFB3D0BC0BD3D03BB263E1AFEF8BCF53F843DEF0A783BC30A83BBF0DB00BC709990BD9183FB3C2ADE813D7E1EC43CB6CB783D3B3F6ABD8872C6BDE69DE43DDB59BBBDE0EEB9BD8187B83DEBC1B63D58EA203DACC732BD725B7F3CF8E8523D0FB827BD888AF6BC4AA6D63DFC1932BDB5914ABE4501D5BC6320CEBC2C484A3D49D877BDD462EE3C48A0113DB703CE3D14949F3D32FF873D869B9F3D2455F2BC0E58273E018AD43C66D5D73D2D8B8C3CBBF2953CFD15A4BC463750BD84EEF23BC2F40C3C00C714BD983E00BE5CC88DBCFA52BBBC805CBFBD1991D03D70223EBDB4E0ED3C88D8E9BC8C2E2ABC63EE12BE7235F7BC8A1BA33CD653F8BC6457233DBB2CB3BA4E0FE53B914C0B3C337D603D35C033BD05AA8DBDED0A253D47E7C1BDB23F04BE1A0132BD91A9123DF33A9B3DD22645BD00CAB7BC6F020F3E60C4C13DE39077BDA07325BD0B4DEC3C90A16DBDC36FB73DB3BC403D0CF3E03BCE36173D3850AABD6D7BD13D1461C83D641C0E3D1FCCF03C2E698CBBE17B29BCF03B9DBD392460BDC1E723BD22B9CBBC7FEB853D4E300A3D5C5372BDEBDD883D7F7289BDC998773D4656C3BC36B7303C1AE80F3AD45606BD966E923BC6A26EBD4C211ABD4E44EE3C32FDF73BD71A98BD7A56AD3D1F787EBDD5EF65BC679CEBBD3417DABD1DD71EBDCAEB9E3D53708B3D7764C6BCC5CC823D6BEDD6BCF5A80C3D, '2021-04-01 22:02:19', '2021-04-01 22:02:19', null);
INSERT INTO `user_face_info` VALUES ('3', '101', 'fhekwyvceg', '嗷嗷嗷', null, null, null, null, 0x0080FA440000A04117A9A73D328B273DD3EBBF3A1BC721BD2E5FAB3CE3272BBD0FB3B63C9BF0213D1E030BBC9D704F3E57E1BE3C317FC33DCFA6883D2ABC07BE209CA8BDE0EE5A3C9E6AB53CD56F3D3D1ACD833CB43AC63B66FDC2BD37D812BEEEFCB4BC1C1A3C3DBD7371BC3C06D83B7F10693C27073FBC8371153C8FC0B53D450331BD860EA53DE042CE3CA902D03DB52685BD42E310BD31F4653C7A4E2FBD0A588A3BA242D53CB9A96D3B37A3F9BCDAB8083E5BD48F3DB59EFE3CD40C68BD4985AE3DEF6F4B3D2D59A0BD454E023ECCA4DEBC602C923B0E9A20BD7AA8CFBCD5B6C9BDF2F4773BDE6C7EBB1316123E84490B3C8F19D63D4741CDBDB568D0BC8CCCFCBC73662D3C8C65B1BD44158C3CBB7160BD10293A3D202F76BD3552843DAA02BABC96FAF9BD2A35A5BC479F01BDEC4758BC7020533D517EBF3CA02925BD2B34E6BBDD26263D2D2B953D1E3EEDBD4743B63C0024FA3C89A859BDC39F0ABEDEB90D3D0FC08C3D9C4D483B2105A33D0B98E3BDF645813A91F1FDBC46898A3DB3CF07BDEB8B14BD2190ECBD5B8FADBD5F1ABE3C078DA5BDEF8C04BD9B9C1ABB81CAB3BCDF9C8ABD6A876FBD80E9CE3B4E7D063EC5AE65BDC11F8BBD5C6C1EBCAA1D0C3BECCFBE3CA409ED3BCE3AA1BDCC65273DF21C29BD65A41E3DD4383EBC4CBD9D3DB53673BD27AC36BEBB4C7A3C665EA0BDD578F83C6044313C626FB3BD4EB9AABC199E9F3C5D0A6F3DC4F1FD3BD27DB33DC34FE2BD4CD0E43D8A09873D4EF88D3C526DF63C2C61F0BC5618C9BCC0D536BDEF838639CDD8C63D4DC290BD22D985BCC1F71FBD93E1C1BDA0038EBD1B54EEBB4610313D2EA1103BFC92C0BC3C050EBEB79137BD6BC71F3D179DE7BB8ED3A03C17C5093DAF9EA8BBDA71AABC74AE963AA7157FBD262BBABD5A5313BCD928793D1083AE3C3543ED3B84A2513CEE9A8DBD5C96AF3D6DBCCB3CAC0D0CBD1F72B2BD0A390D3E20A4CDB99A1FB4BD51A545BC2D1A7F3D95715F3D43369BBC5EDFB3BC8172A8BDF63C75BD9F79EABD6AA5813C5C3B9E3D4130E0BC9CB078BD1CD1023DE43A693DDD82A8BD9480CD3DA79894BD52DE0C3D1560FD3C171B35BB861E6D3C53417F3C49C9C0BC7115283DCAA8803D505679BB5B0A59BD2FFE7ABD711A5A3D3FAF843C82AF093CEE09AF3DCAE15B3CD10512BDD7D82C3DE008BFBD9BD1263EC367333D9671C1BD1B991EBD1E2AA53B7F17703D1AA00ABD55E7943DE455CEBD461E5F3DDEB02FBE633C083D101F07BD03D66ABDAD93FF3BE176923D6EBD633D337E34BEF4C3B5BCFF1EBD3DED223BBD243CF2BBBF6FC6BDA64595BD6FEA073DE7E8C03DB459253CC318E6BC511B02BC7187933CAEF2AF3D8F48ABBC45DCD8BD99006FBDB2740DBD29801A3A5445B6BDA75897BC813AB5BC34A4FFBC61211ABD7C4EAABD3BBD283D2032D5BD261A30BE15A4A1BD, '2021-04-01 22:03:53', '2021-04-01 22:03:53', null);
INSERT INTO `user_face_info` VALUES ('6', '101', 'tqoa5j0v7f', '吱吱吱吱', null, null, null, null, 0x0080FA440000A0415AF19FBC7EFDF4BD6215FD3BBEDAD5BCAD4CCDBDC2DE9F3DEEA40FBB2FA1A9BDB85154BEE8AAC03B073CD3BDF1027E3D06174F3D368EC7BCD0B7CF3DA489293AE719593DF962163D46B6D2BC30E89C3D3C7908BD5B1E0ABD6CA733BDA52F73BD5963463D73465FBD276D1CBDD98A15BC121C0BBDA04C2CBD9D8404BD85469D3DEFF2F6BC78F166BC4704D2BDABB4E33C7EF1133C5B1CDABDA02503BC2BF1CE3DA067433DCB13C1BD9A61FABCB869C13C48953D3DD42818BE2E3DD43D12212FBC503FEC3C2E75E3BAAAD6CD3D6E1D5D3D4D45393C27673C3C637D893C89ECE8BCF9883CBDFC71D7BD675CE63C0B47703C5637B13CC0542ABDE81DC43DD447A0BC3652A0BDD882FDBDEBBCCFBD44FEC0BC329E513DBEB61B3D8AC488BD9B93B53D8F0FAF3C9E186CBD3EA010BD442FDB3C2DAE4F3D29C5073CAF5608BE3EDCF33CF2B0AC3D2DAF81BD112CB23DA343A2BA85489F3D0ECD523DF7DA02BE00E984BB0348583DFBEFC33DE6E2B6BCCA993B3C8502D63B3ED45D3D6E88C8BD71AB2B3C9CE391BDDF35113CA47990BDF81264BC294D8E3CA22A2EBC286583BCF0F3D5BA65FCBD3DE6EC7D3D818C883D0D006C3DBD4701BD4894A8BDEEA4073D0A05BA3C871297BD53D706BEAE2AA43D19E004BED94A523DDF53613C5766063CA80D89BCFC734EBCBE3ABF3CA2E16DBCF21EB5390B3F80BD2C1996BA27FB43BB913F87BCAAA4AEBBB7AEFB3D0BC0BD3D03BB263E1AFEF8BCF53F843DEF0A783BC30A83BBF0DB00BC709990BD9183FB3C2ADE813D7E1EC43CB6CB783D3B3F6ABD8872C6BDE69DE43DDB59BBBDE0EEB9BD8187B83DEBC1B63D58EA203DACC732BD725B7F3CF8E8523D0FB827BD888AF6BC4AA6D63DFC1932BDB5914ABE4501D5BC6320CEBC2C484A3D49D877BDD462EE3C48A0113DB703CE3D14949F3D32FF873D869B9F3D2455F2BC0E58273E018AD43C66D5D73D2D8B8C3CBBF2953CFD15A4BC463750BD84EEF23BC2F40C3C00C714BD983E00BE5CC88DBCFA52BBBC805CBFBD1991D03D70223EBDB4E0ED3C88D8E9BC8C2E2ABC63EE12BE7235F7BC8A1BA33CD653F8BC6457233DBB2CB3BA4E0FE53B914C0B3C337D603D35C033BD05AA8DBDED0A253D47E7C1BDB23F04BE1A0132BD91A9123DF33A9B3DD22645BD00CAB7BC6F020F3E60C4C13DE39077BDA07325BD0B4DEC3C90A16DBDC36FB73DB3BC403D0CF3E03BCE36173D3850AABD6D7BD13D1461C83D641C0E3D1FCCF03C2E698CBBE17B29BCF03B9DBD392460BDC1E723BD22B9CBBC7FEB853D4E300A3D5C5372BDEBDD883D7F7289BDC998773D4656C3BC36B7303C1AE80F3AD45606BD966E923BC6A26EBD4C211ABD4E44EE3C32FDF73BD71A98BD7A56AD3D1F787EBDD5EF65BC679CEBBD3417DABD1DD71EBDCAEB9E3D53708B3D7764C6BCC5CC823D6BEDD6BCF5A80C3D, '2021-04-01 22:23:32', '2021-04-01 22:23:32', null);
