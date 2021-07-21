<%@ page language="java" contentType="text/html; charset=utf-8"
import="java.sql.*" 
import="com.conn.*" 
import="java.util.Timer"
    pageEncoding="utf-8"%>
<!DOCTYPE html>
<html>
<head>
  <meta charset="utf-8">
<link href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/css/bootstrap.min.css" rel="stylesheet">
<link rel="stylesheet" type="text/css" href="../css/check.css">
<link rel="stylesheet" type="text/css" href="../css/shared.css">
<script src="https://oss.maxcdn.com/libs/html5shiv/3.7.0/html5shiv.js"></script>
</head>
<body>
<div class="container-fluid1" style="height: 100%;width: 100%;">   
<div class="container-fluid" style="background:white;height: 8%">
    <div class="point point-primary point-lg"> </div> 
    <h4>仓库盘点</h4>
  <div class="right1">
    <img class="imag3" src="../img/铃.png" >
    <img class="imag3" src="../img/问号.png" >  
    <img class="imag4" src="../img/用户.png" >
    <!-- <span class="dropdown-toggle" data-toggle="dropdown" ></span>
    <div class="dropdown-menu">
      <a class="dropdown-item" href="#">退出登陆</a>
    </div>    -->
  </div>
</div>

<div class="btns" style="height: 8%; margin: -1% 0% 1% 0%;">
  <div class="navbar-brand">
    <button type="button" class="btn btn-success btn-sm refresh"  onclick="refresh();">实时盘点</button>
  <input type="button" class="btn btn-danger btn-sm manual" value="手动盘点" onclick="document.getElementsByName('check_content')[0].src='check_manual.html'">

    <input type="button" class="btn btn-primary btn-sm history" value="盘点历史记录" onclick="document.getElementsByName('check_content')[0].src='check_history.html'">
    <input type="button" class="btn btn-primary btn-sm history" value="重点设备定位" onclick="document.getElementsByName('check_content')[0].src='check_position.html'">
  </div>
</div>
<iframe src="check_content.html" name="check_content" frameborder="0" style="height: 100%; width: 98%; margin: 1% 1% 0% 1%;"></iframe>

<script type="text/javascript">
   
function refresh(){

	window.location.reload(); 
	
}
</script>
</body>
<script src="../bootstrap/js/jquery.min.js"></script>
<script src="../bootstrap/js/bootstrap.min.js"></script>
</html>