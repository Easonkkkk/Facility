<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<%@ page import="com.servlet.auShow"%>
<%@page import="java.util.*"%>
<%@ page import="java.net.URLEncoder"%>
<!DOCTYPE html>
<html lang="zh">
<head>
<meta charset="UTF-8">
<head>
 <script src="https://cdn.bootcss.com/jquery/3.3.1/jquery.min.js"></script>
    

<meta charset="UTF-8">
<title>Insert title here</title>
</head>
<body>
<p>名称&nbsp&nbsp&nbsp性别&nbsp&nbsp出生日期 &nbsp&nbsp住址&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp
&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp
&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp
&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp身份证号&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp &nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp
签发机构&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp证件有效期限</p>
<%     
out.println(request.getAttribute("coco"));
%>
<br>
<img src="zp.jpg" style="align:center;">

</body>
</html>




