<%@ page language="java" contentType="text/html; charset=utf-8"
import="java.sql.*" 
import="com.conn.*"
    pageEncoding="utf-8"%>
<!DOCTYPE html>
<html>
<head>
  <meta charset="utf-8">
<link href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/css/bootstrap.min.css" rel="stylesheet">
<link rel="stylesheet" type="text/css" href="../css/warning.css">
<link rel="stylesheet" type="text/css" href="../css/shared.css">
<script src="https://oss.maxcdn.com/libs/html5shiv/3.7.0/html5shiv.js"></script>
</head>
<body>
<div class="container-fluid1" style="height: 100%;width: 100%;">   
<div class="container-fluid" style="background:white;height: 8%">
    <div class="point point-primary point-lg"> </div> 
    <h4>异常处理</h4>
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
    <button type="button" class="btn btn-success btn-sm" onclick="window.location.reload();" >刷新</button>
    <button type="button" class="btn btn-danger btn-sm"  >设置</button>
    <button type="button" class="btn btn-primary btn-sm" >查看详情</button>
  </div>
</div>


<div class="front" style="background:white;height: 100%;width: 98%;">

  <table class="tb">
    <tr class="tr">
      <td>编号</td>
      <td>名称</td>
      <td>位置</td>
      <td class="warn">异常详情</td>
      <td class="time">报警时间</td>
      <td>已读/未读</td>
      <td>报警短信</td>
    </tr>
    <%	Connection conn=null;
			conn = Conn.getConn();
            Statement stmt = conn.createStatement();
            String sql = "select * from rt_check";
            ResultSet rs = stmt.executeQuery(sql);
            if(rs!=null){
           	 	while(rs.next()){
		%>
		<tr class="tr">
		<%
		out.print("<td>"+rs.getString(2)+"</td>");
		String equipment_id=rs.getString(2);
		Connection conn2 = Conn.getConn();
		
		Statement stmt1 = conn.createStatement();
		String sql1 = "select equipment_name,equipment_position from equipment where equipment_id=?";
		PreparedStatement pStmt=conn2.prepareStatement(sql1);
		pStmt.setString(1,equipment_id);
		ResultSet rs1 = pStmt.executeQuery();
		if(rs1!=null){
			while(rs1.next()){
			out.print("<td class='eqname'><a href='#' class='eqdetail'>"+rs1.getString(1)+"</a></td>");
			out.print("<td>"+rs1.getString(2)+"</td>");
			}
		}
		conn2.close();
		out.print("<td class='warn'>"+rs.getString(3)+"</td>");
		out.print("<td class='time'>"+rs.getString(4)+"</td>");
		out.print("<td>"+"<a href='#' class='toread'>未读</a>"+"</td>");
		out.print("<td>"+"已发送"+"</td>");
           	 	}
            }
		%>
		
		
		</tr>    
  </table>
</div>

</body>
</html>