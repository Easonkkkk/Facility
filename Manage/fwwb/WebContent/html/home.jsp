<%@ page language="java" import="java.sql.*" import="com.conn.*" contentType="text/html; charset=utf-8"
    pageEncoding="utf-8"%>
<!DOCTYPE html>
<html>
<head>
  <meta charset="utf-8">
<link href="../bootstrap/css/bootstrap.min.css" rel="stylesheet">
<link rel="stylesheet" type="text/css" href="../css/home.css">
<link rel="stylesheet" type="text/css" href="../css/shared.css">
<script src="https://oss.maxcdn.com/libs/html5shiv/3.7.0/html5shiv.js"></script>
</head>
<body>
<div class="container-fluid1" style="height: 100%;width: 100%;">   
<div class="container-fluid" style="background:white;height: 8%">
    <div class="point point-primary point-lg"> </div> 
    <h4>首页&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</h4>
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

<div class="front" style="background:white;height: 40%;width: 98%;">
<h4 class="title">设备使用情况</h4>
  <div class="imgs">
    <div class="fronta" > 
      <div class="using">
        <img class="imagf" src="../img/使用.png" >
        <span class="num">70</span>
        <h3 class="front_h3">使用中</h3>
      </div>
    </div>
    <div class="fronta" >
      <div class="good">
        <img class="imagf" src="../img/正常.png" >
        <span class="num">35</span>
        <h3 class="front_h3">空闲中</h3>
      </div>
    </div>
    <div class="fronta" > 
      <div class="bad">
        <img class="imagf" src="../img/异常.png" >
        <span class="num">3</span>
        <h3 class="front_h3">异 常</h3>
      </div>
    </div>
  </div>
</div>

<div class="bottom" style="height: 48%;width: 100%;">
  <div class="bottomleft" style="background:white;height: 100%;width: 50%;">
    <div class="bottomlefttop">
      <span>最新公告</span>  
      <a href="" class="more">更多 >></a>
    </div>   
    <div class="bottomleftbottom">
      <table class="notice">
        <tr>
          <td>2021.01.07</td>
          <td class="notice_content"><a href="#" class="notice_content_link">仓库将于2021年1月20日开始年度的设备检查，请大家做好准备。</td>
        </tr>
        <tr>
          <td>2021.02.15</td>
          <td class="notice_content"><a href="#" class="notice_content_link">仓库3新进设备12台，请大家注意查看。</td>
        </tr>
        <tr>
          <td>2020.03.10</td>
          <td class="notice_content"><a href="#" class="notice_content_link">仓库将于2021年3月15日清空报废设备，请大家做好准备。</td>
        </tr>
        <tr>
          <td>2020.04.12</td>
          <td class="notice_content"><a href="#" class="notice_content_link">仓库将于2021年4月15日记录各仓库新设备需求，请大家做好准备。</td>
        </tr>
      </table>
    </div>
  </div>
  <div class="bottomright" style="background:white;height: 100%;width: 50%;">   
    <div class="bottomrighttop">
      <span>周设备流量</span>
    </div>
    <div class="bottomrightbottom" style="height: 90%;">
      <div id="container" style="height: 98%;"></div>
    </div>
  </div>
</div>
</div>


<script src="https://code.jquery.com/jquery.js"></script>
<script src="../bootstrap/js/jquery.min.js"></script>
  <script src="https://cdn.staticfile.org/popper.js/1.15.0/umd/popper.min.js"></script>
  <script src="..bootstrap/js/bootstrap.min.js"></script>

 <script type="text/javascript" src="https://cdn.jsdelivr.net/npm/echarts@5/dist/echarts.min.js"></script><!-- 图表的 -->

 <script type="text/javascript">
var dom = document.getElementById("container");
var myChart = echarts.init(dom);
var app = {};

var option;



option = {
    xAxis: {
        type: 'category',
        data: ['Mon', 'Tue', 'Wed', 'Thu', 'Fri', 'Sat', 'Sun']
    },
    yAxis: {
        type: 'value'
    },
    series: [{
        data: [120, 200, 150, 80, 70, 110, 130],
        type: 'bar',
        showBackground: true,
        backgroundStyle: {
            color: 'rgba(180, 180, 180, 0.2)'
        }
    }]
};

if (option && typeof option === 'object') {
    myChart.setOption(option);
}

</script>
</body>
</html>