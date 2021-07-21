<%@ page language="java" import="java.sql.*" 
import="com.conn.*" 
contentType="text/html; charset=utf-8" 
    pageEncoding="utf-8" %>
<!DOCTYPE html>
<html>
<head>
	<meta charset="utf-8">
	<meta http-Equiv="Cache-Control" Content="no-cache" />
	<meta http-Equiv="Pragma" Content="no-cache" />
	<meta http-Equiv="Expires" Content="0" />
	<link href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/css/bootstrap.min.css" rel="stylesheet">
	<link rel="stylesheet" type="text/css" href="/fwwb/css/manage.css">
	<script src="https://oss.maxcdn.com/libs/html5shiv/3.7.0/html5shiv.js"></script>
	
</head>
<body>
	<div class="front" style="background:white;height: 100%;width: 98%;">
	  <div class="filter">
	　　

	　　<select name="eqtag">
	  　　<option value="alleqtag">全部设备标记</option>
	  　　<option value="common">普通设备</option>
	  　　<option value="vital">重要设备</option>
	　　</select>

	　　<select name="lendingstatus">
	  　　<option value="alllendingstatus">全部借出状态</option>
	  　　<option value="led">已出库</option>
	  　　<option value="tolend">未出库</option>
	　　</select>

	　　<select name="department">
	  　　<option value="alldepartment">全部所属部门</option>
	  　　<option value="production">生产部</option>
	  　　<option value="research">研发部</option>
	　　</select>
	  
	    <input type="text" name="num" placeholder="请输入编号">
	    <input type="text" name="eqname" placeholder="请输入名称">

	    <button type="button" class="btn btn-primary btn-sm" style="margin: 0% 0% 0% 5%">筛选设备</button>

	  </div>

	  <table class="tb">
	    <tr class="tr">
	      <td class="ckbox"></td>
	      <td>编号</td>
	      <td>名称</td>
	      <td>型号</td>
	      <td>借出状态</td>
	      <td>设备状态</td>
	      <td>设备标记</td>
	      <td>所属部门</td>
	      <td>位置</td>
	      <td>修改信息</td>
	    </tr>
	    <%	
	    	int i=0;
	    	Connection conn=null;
			conn = Conn.getConn();
            Statement stmt = conn.createStatement();
            String sql = "select * from equipment";
            ResultSet rs = stmt.executeQuery(sql);
            if(rs!=null){
           	 	while(rs.next()){
           	 		i++;
		%>
		<tr class="tr">
		<!--  <td class="ckbox"><input type="checkbox" name="selected" value=<%=i%>></td>-->
		<% 	out.print("<td class='ckbox'><input type='checkbox' id='selected' name='selected' value="+i+"></td>");
			out.print("<td>"+rs.getString(1)+"</td>");
			out.print("<td class='eqname'>"+rs.getString(2)+"</td>");
			out.print("<td>"+rs.getString(5)+"</td>");
			if(rs.getString(6).equals("1")){
				out.print("<td>"+"已出库"+"</td>");
			}
			else{
				out.print("<td>"+"未出库"+"</td>");
			}
			if(rs.getString(9).equals("1")){
				out.print("<td>"+"正常"+"</td>");
			}
			else{
				out.print("<td>"+"故障"+"</td>");
			}
			if(rs.getString(4).equals("1")){
				out.print("<td>"+"常规设备"+"</td>");
			}
			else{
				out.print("<td>"+"重要设备"+"</td>");
			}
			out.print("<td>"+"生产部"+"</td>");
			out.print("<td>"+rs.getString(7)+"</td>");
			
			
           	 	
            
		%>
		<td><a data-toggle="modal" data-target="#myModal" onclick="value('<%=rs.getString(1) %>','<%=rs.getString(2) %>','<%=rs.getString(5) %>','<%=rs.getString(6) %>','<%=rs.getString(9) %>','<%=rs.getString(4) %>','<%=rs.getString(10) %>','<%=rs.getString(7) %>','<%=rs.getString(11) %>')">修改信息</a></td>

		<%} 
		
		}
		%>
		</tr>
	    
	    
	  </table>
	</div>
	<div class="modal fade" id="myModal" tabindex="-1" role="dialog" aria-labelledby="myModalLabel" aria-hidden="true">
    <div class="modal-dialog" style="width:45%;height: 90%;">
      <div class="modal-header">
        <button type="button" class="close" data-dismiss="modal" aria-hidden="true">&times;</button>
        <h4 class="modal-title" id="myModalLabel">修改信息</h4>
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
</body>
<script>
$("#myModal").modal("hide");
function value(ID,name,model,state,damage,label,depart,position,rfid){
	$("#equipment_id").val(ID);
	$("#equipment_name").val(name);
	$("#equipment_model").val(model);
	if(label=="1"){
		$("#equipment_label").val("common");
	}
	else{
		$("#equipment_label").val("vital");
	}
	$("#department").val(depart);
	$("#equipment_rfid").val(rfid);
	$("#equipment_position").val(position);
	
	//$("#myModal").modal("show");
}
</script>
<script src="/fwwb/bootstrap/js/jquery.min.js"></script>
<script src="/fwwb/bootstrap/js/bootstrap.min.js"></script>
</html>