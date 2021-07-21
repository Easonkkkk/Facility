<%@ page contentType="text/html; charset=UTF-8" pageEncoding="UTF-8"%>
<%@ page import="java.sql.ResultSet"%>
<%@ page import="java.sql.PreparedStatement"%>
<%@ page import="java.sql.DriverManager"%>
<%@ page import="java.sql.Connection"%>
<!DOCTYPE html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8">
<meta http-equiv="Content-Language" content="en-us">
<title>Test Print</title>
</head>
	<%
    String driverStr = "com.mysql.jdbc.Driver";
    String connStr = "jdbc:mysql://localhost:3306/mzd_manager?characterEncoding=UTF-8";
    Class.forName(driverStr);
    Connection conn = DriverManager.getConnection(connStr, "root", "");
    String sql = "Select * from equipment where equipment_damage=?";
    PreparedStatement sta = conn.prepareStatement(sql);
    sta.setInt(1, 1);
    ResultSet rs = sta.executeQuery();
%>
<%for (int i = 0; rs.next(); i++) {%>

	<%=rs.getString("equipment_id")%>
	<%=rs.getString("equipment_name")%>
	<%=rs.getString("equipment_intro")%>
	<%=rs.getString("equipment_position")%>

<script language="javascript">

 function init(){
  //document.all.printport.CommPort = "1";
  //document.all.printport.PortOpen = true;
                document.all.printport.PortOpen = true;
 }

 var sleep = function(time) {
    var startTime = new Date().getTime() + parseInt(time, 10);
    while(new Date().getTime() < startTime) {}
};



 function doPrint(printmsg){  
    
  //document.all.printport.Output = printmsg;
   //document.all.printport.Output = "\r\n";
   document.all.printport.Output="+++";
   sleep(500); // 延时函数，单位ms

document.all.printport.Output="a";
sleep(500); // 延时函数，单位ms
document.all.printport.Output="AT+DSTNUM=\""+"13386530218"+"\"\r\n";
sleep(500); // 延时函数，单位ms
document.all.printport.Output="AT+WKMOD=\"SMS\"\r\n";
sleep(500); // 延时函数，单位ms
document.all.printport.Output="AT+ENTM\r\n"; //进入短信数据透传
sleep(500); // 延时函数，单位ms

//后面跟要送的短信内容 
var id="<%=rs.getString("equipment_id")%>"
var name="<%=rs.getString("equipment_name")%>"
var position="<%=rs.getString("equipment_position")%>"
var intro="<%=rs.getString("equipment_intro")%>"
var str="异常!!:"+intro+"\n"+"设备:"+name+"\n"+"编号:"+id+"\n"+"位置:"+position;
document.all.printport.Output=str;

 }
 function pageEnd(){  
  document.all.printport.PortOpen = false;
 }
 
</script>
<body  onload='init();' onunload='pageEnd();'>
<form method="POST" action="--WEBBOT-SELF--">
 <p><textarea rows="21" name="S1" cols="86"></textarea></p>
 <p><input type="button" value="Print" name="B1" onclick='doPrint(document.all.S1.value);'></p>
 <p><object id="printport" classid="clsid:648A5600-2C6E-101B-82B6-000000000014" style="display:none">
  <PARAM   NAME="CommPort"   VALUE="5"/> 
     <PARAM   NAME="DataBits"   VALUE="8"/> 
     <PARAM   NAME="StopBits"   VALUE="1"/> 
     <PARAM   NAME="BaudRate"   VALUE="115200"/> 
     <PARAM   NAME="Settings"   VALUE="115200,N,8,1"/>     
 
     <PARAM   NAME="RTSEnable"   VALUE="1"/> 
     <PARAM   NAME="DTREnable"   VALUE="1"/> 
     <PARAM   NAME="Handshaking"   VALUE="0"/> 
     <PARAM   NAME="NullDiscard"   VALUE="0"/> 
     <PARAM   NAME="ParityReplace"   VALUE="?"/>
 
     <PARAM   NAME="EOFEnable"   VALUE="0"/>       
     <PARAM   NAME="InputMode"   VALUE="0"/>    
     <PARAM   NAME="InBufferSize"   VALUE="1024"/>       
     <PARAM   NAME="InputLen"   VALUE="0"/>     
     <PARAM   NAME="OutBufferSize"   VALUE="512"/> 
     
     <PARAM   NAME="SThreshold"   VALUE="0"/> 
     <PARAM   NAME="RThreshold"   VALUE="1"/> 
 
 </object></p>

</form>
	<%
    }
    rs.close();
    //关闭结果集
    sta.close();
    //关闭语句对象
    conn.close();
    //关闭连接
%>
</body>
</html>