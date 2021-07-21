<%@ page language="java" import="java.sql.*" 
import="com.conn.*" 
import="mzd.server.*"
contentType="text/html; charset=utf-8"
    pageEncoding="utf-8"%>
<!DOCTYPE html>
<html>
<head>
  <meta charset="utf-8">
<link href="/fwwb/bootstrap/css/bootstrap.min.css" rel="stylesheet">
<link rel="stylesheet" type="text/css" href="/fwwb/css/manage.css">
<link rel="stylesheet" type="text/css" href="/fwwb/css/shared.css">
<script src="https://oss.maxcdn.com/libs/html5shiv/3.7.0/html5shiv.js"></script>
</head>

<body>
<div class="container-fluid1" style="height: 100%;width: 100%;">   
<div class="container-fluid" style="background:white;height: 8%">
    <div class="point point-primary point-lg"> </div> 
    <h4>设备管理</h4>
  <div class="right1">
    <img class="imag3" src="/fwwb/img/铃.png" >
    <img class="imag3" src="/fwwb/img/问号.png" >  
    <img class="imag4" src="/fwwb/img/用户.png" >
    <!-- <span class="dropdown-toggle" data-toggle="dropdown" ></span>
    <div class="dropdown-menu">
      <a class="dropdown-item" href="#">退出登陆</a>
    </div>    -->
  </div>
</div>

<div class="btns" style="height: 8%; margin: -1% 0% 1% 0%;">
  <div class="navbar-brand">
    <!-- <input type="button" class="btn btn-success btn-sm" value="新增设备" onclick="document.getElementsByName('manage_content')[0].src='manage_eqadd.html'"> -->
    <button class="btn btn-success btn-sm" data-toggle="modal" data-target="#myModal">新增设备</button>
    <input type="button" class="btn btn-danger btn-sm" value="删除设备" onclick="delete_equipment()">
    <input type="button" class="btn btn-primary btn-sm" value="查询历史轨迹" onclick="document.getElementsByName('manage_content')[0].src='manage_eqtra.html'">
  </div>
</div>

<iframe src="/fwwb/html/manage_content.jsp" name="manage_content" id="manage_content" frameborder="0" style="height: 100%; width: 98%; margin: 1% 1% 0% 1%;"></iframe>



<div class="modal fade" id="myModal" tabindex="-1" role="dialog" aria-labelledby="myModalLabel" aria-hidden="true">
    <div class="modal-dialog" style="width:45%;height: 80%;">
      <div class="modal-header">
        <button type="button" class="close" data-dismiss="modal" aria-hidden="true">&times;</button>
        <h4 class="modal-title" id="myModalLabel">新增设备</h4>
      </div>
      <div class="modal-body">
        <!--1-->
        <div class="frame">
        <form action="<%=request.getContextPath()%>/equipmentServer" method="post" target="content">
          <table class="eqadd_tb">
            <tr>
              <td>设备编号：</td><td><input type="text" name="equipment_id" id="equipment_id" value="" placeholder=""></td>
            </tr>
            <tr>
              <td>设备名称：</td><td><input type="text" name="equipment_name" id="equipment_name" value="" placeholder=""></td>
            </tr>
            <tr>
              <td>设备型号：</td><td><input type="text" name="equipment_model" id="equipment_model" value="" placeholder=""></td>
            </tr>
            <tr>
              <td>设备标记：</td>
              <td>
                <select name="equipment_label" id="equipment_label">
              　　<option value="alleqtag">设备标记</option>
              　　<option value="common">普通设备</option>
              　　<option value="vital">重要设备</option>
            　　</select>
              </td>
            </tr>
            <tr>
              <td>所属部门：</td>
              <td>
                <select name="department" id="department">
              　　<option value="alldepartment">所属部门</option>
              　　<option value="production">生产部</option>
              　　<option value="research">研发部</option>
            　　</select>
              </td>
            </tr>
            <tr>
              <td>RFID：</td><td><input type="text" name="equipment_rfid" id="equipment_rfid" value="" placeholder=""></td>
            </tr>
            <tr>
              <td>位置：</td><td><input type="text" name="equipment_position" id="equipment_position" value="" placeholder=""></td>
            </tr>
          </table>
          <input type="submit" class="btn btn-primary" style="margin: 5% 0% 0% 35%; width: 30%;" value="确认">
          </form>
        </div>
        <!--1-->
        
      </div>    
    </div>
  </div>
</div>
</body>
<script>

function delete_equipment(){
	//var x=$("#manage_content").contents().find("#selected").value;
	//console.log(parent.window.document.getElementById("selected").value);
	var _iframe = document.getElementById('manage_content').contentWindow;
	var select =_iframe.document.getElementById('selected');
	console.log(select.value);
	for(int i=1;i<0;i++){
		if(select.value==i && select.checked=="true"){
			<% out.print(1);%>
		}
	}
	

}

</script>
<script src="/fwwb/bootstrap/js/jquery.min.js"></script>
<script src="/fwwb/bootstrap/js/bootstrap.min.js"></script>
</html>