<%@ page language="java" import="java.sql.*" import="com.conn.*" 
import="mzd.server.*"
contentType="text/html; charset=utf-8"
    pageEncoding="utf-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<meta http-Equiv="Cache-Control" Content="no-cache" />
<meta http-Equiv="Pragma" Content="no-cache" />
<meta http-Equiv="Expires" Content="0" />
<link href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/css/bootstrap.min.css" rel="stylesheet">
<link rel="stylesheet" type="text/css" href="../css/home.css">
<link rel="stylesheet" type="text/css" href="../css/shared.css">
<script src="https://oss.maxcdn.com/libs/html5shiv/3.7.0/html5shiv.js"></script>
<!-- <script src="https://oss.maxcdn.com/libs/respond.js/1.3.0/respond.min.js"></script> -->

<title>寻迹</title>
</head>
<body>

<div class="container" style="width:17%;float:left">    
    <div class="row">
        <div class="span8">
            <ul class="nav nav-pills nav-stacked">
                <li class="active"><img class="imag1" src="../img/13.png"><img src="../img/寻迹设备管理.png" style="width: 70%"></li>
                <li><a href="home.jsp" target="content" class="nav_a"><img class="imag2" src="../img/首页.png" >首页</a></li>
                <li><a href="check.jsp" target="content" class="nav_a"><img class="imag2" src="../img/仓库盘点.png" >仓库盘点</a></li>
                <li><a href="manage.jsp" target="content" class="nav_a"><img class="imag2" src="../img/设备管理.png" >设备管理</a></li>
                <li><a href="warning.jsp" target="content" class="nav_a"><img class="imag2" src="../img/异常处理.png" >异常处理<span class="bad" id="bad" name="bad" style="margin-top:20%;">&nbsp;&nbsp;&nbsp;&nbsp;③</span></a></li>
            </ul>
        </div>
    </div>      
</div>

<iframe src="home.jsp" id="content" name="content" frameborder="0" scrolling="auto" style="height: 100%; width: 83%;"></iframe>

</body>
</html>