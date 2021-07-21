<!DOCTYPE html>
<html>
<head>
    <meta charset="utf-8">
	<link rel="stylesheet" href="css/home1.css">
	<link href="bootstrap-3.3.7-dist/css/bootstrap.min.css" rel="stylesheet">

	<title>自助机</title>
</head>
<body style="background-image: url(./img/bkgd.jpg)">
	<div class="container1">
		<div class="bg"></div>
		<div class="container4">
			<img class="img1" src="img/13.png">
			<img class="img2" src="img/寻迹设备管理.png">
		</div>
		<p class="p1">欢迎使用寻迹设备自助借用机</p>
		<p class="p2">温馨提示：请将设备放在柜台上进行识别</p>
		<div class="out">
			<div class="out1"></div>
			<div class="out2"></div>
			<div class="out3"></div>
			<button class="btn3" data-toggle="modal" data-target="#myModal">扫描设备</button>
		</div>
	</div>

	<div class="modal fade" id="myModal" tabindex="-1" role="dialog" aria-labelledby="myModalLabel" aria-hidden="true">
		<div class="modal-dialog" style="width:80%;height:500px;">
			<div class="modal-header" style="border-bottom: none;padding-bottom: 0;">
				<button type="button" class="close" data-dismiss="modal" aria-hidden="true">&times;</button>
				<h4 class="modal-title" id="myModalLabel" style="margin-top: 1.5%;">设备信息</h4>
			</div>
			<div class="modal-body" style="padding-top: 0;padding-bottom: 0;">
				<!--1-->
				<div class="frame">


					<div class="container2">
						<img class="img3" src="img/齐心加厚订书机.jpg">
						<table class="table1">
							<tr>
								<td class="title1" style="margin-top: 7%;">设备名称</td>
								<td class="text1" style="margin-top: 7%;">齐心加厚订书机</td>
							</tr>
							<tr>
								<td class="title1" style="margin-top: 7%;">设备编号</td>
								<td class="text1" style="margin-top: 7%;">1093</td>
							</tr>
							<tr>
								<td class="title1" style="margin-top: 7%;">设备型号</td>
								<td class="text1" style="margin-top: 7%;">B3061</td>
							</tr>
							<tr>
								<td class="title1" style="margin-top: 7%;">设备标记</td>
								<td class="text1" style="margin-top: 7%;">常规设备</td>
							</tr>
							<tr>
								<td style="margin-top: 7%;"></td>
							</tr>
							<tr>
								<td class="title1" style="margin-top: 7%;">设备位置</td>
								<td class="text1" style="margin-top: 7%;">10-19-3</td>
							</tr>
							<tr>
								<td class="title1" style="margin-top: 7%;">所属部门</td>
								<td class="text1" style="margin-top: 7%;">生产部</td>
							</tr>
							<tr>
								<td class="title1" style="margin-top: 7%;">设备状态</td>
								<td class="text1" style="margin-top: 7%;">正常</td>
							</tr>
							<tr>
								<td class="title1" style="margin-top: 7%;">借出状态</td>
								<td class="text1" style="margin-top: 7%;">未出库</td>
							</tr>
						</table>
						<div class="container3">
							<button type="button" class="btn1" data-toggle="modal" data-target="#myModal1">内部人员借设备</button>
							<button type="button" class="btn2" data-toggle="modal" data-target="#myModal2">外部人员代借设备</button>
						</div>
					</div>


				</div>
				<!--1-->

			</div>
		</div>
	</div>

	<div class="modal fade" id="myModal1" tabindex="-1" role="dialog" aria-labelledby="myModalLabel" aria-hidden="true">
		<div class="modal-dialog" style="width:80%;height:500px;">
			<div class="modal-header" style="border-bottom: none;padding-bottom: 0;">
				<button type="button" class="close" data-dismiss="modal" aria-hidden="true">&times;</button>
				<p class="p3">人脸核验</p>
			</div>
			<div class="modal-body" style="display: flex;justify-content: center;padding-top: 0;padding-bottom: 0;">
				<img class="img4">
			</div>
		</div>
	</div>

	<div class="modal fade" id="myModal2" tabindex="-1" role="dialog" aria-labelledby="myModalLabel" aria-hidden="true">
		<div class="modal-dialog" style="width:80%;height:500px;">
			<div class="modal-header" style="border-bottom: none;">
				<button type="button" class="close" data-dismiss="modal" aria-hidden="true">&times;</button>
				<div class="title4">
					<p class="p4">人脸核验</p>
					<p class="p7">身份验证</p>
				</div>
			</div>
			<div class="modal-body" style="padding-top: 0;padding-bottom: 0;">
				<!--1-->
				<div class="container2">
					<img class="img5">
					<div class="container8">
						<table class="table2">
							<tr>
								<td class="title2" style="margin-bottom: 2%;">姓名</td>
								<td class="text2" style="margin-bottom: 2%;"><input type="text" name="name" value="陈亮亮"/></td>
							</tr>
							<tr>
								<td class="title2" style="margin-bottom: 2%;">性别</td>
								<td class="text2" style="margin-bottom: 2%;"><input type="text" name="sex" value="男"></td>
							</tr>
							<tr>
								<td class="title2" style="margin-bottom: 2%;">证件号码</td>
								<td class="text2" style="margin-bottom: 2%;"><input type="text" name="num" value="330010200103051222"/></td>
							</tr>
							<tr>
								<td class="title2" style="margin-bottom: 2%;">有效期限</td>
								<td class="text2" style="margin-bottom: 2%;"><input type="text" name="time" value="20160718-20210718"/></td>
							</tr>
						</table>
						<div class="container7">
							<p class="p8">借出时间</p>
							<p class="p5">2021/04/08 15:20</p>
						</div>
						<button type="button" class="btn4" data-toggle="modal" data-target="#myModal3">确认借出</button>
						<div class="p6">
							<p>温馨提示：①请将身份证放置在读卡器上</p>
							<p style="text-indent:5em">②请将正脸对准摄像头</p>
						</div>
					</div>
				</div>
				<!--1-->

			</div>
		</div>
	</div>

	<div class="modal fade" id="myModal3" tabindex="-1" role="dialog" aria-labelledby="myModalLabel" aria-hidden="true">
		<div class="modal-dialog" style="width:80%;height:500px;">
			<div class="modal-header" style="border-bottom: none;background-color: #596B7F">
				<button type="button" class="close" data-dismiss="modal" aria-hidden="true">&times;</button>
				<!-- <div class="title4">
					<p class="p4">设备信息</p>
					<p class="p7">身份验证</p>
				</div> -->
				<!-- <div class="title5">
					<p class="p9">身份证号</p>
					<p class="p9">身份验证</p>
				</div> -->
				<table class="table3">
					<tr>
						<td class="title3" style="margin-bottom: 2%;">证件号码：</td>
						<td class="text3" style="margin-bottom: 2%;"><input type="text" name="name" value="330010200103051222"/></td>
						<td class="title3" style="margin-bottom: 2%;">姓名：</td>
						<td class="text3" style="margin-bottom: 2%;"><input type="text" name="name" value="陈亮亮"/></td>
					</tr>
				</table>
			</div>
			<p>请核对借出设备信息：</p>
			<div class="modal-body" style="padding-top: 0;padding-bottom: 0;">
				<!--1-->
				<div class="container2">
					<img class="img6">
					<div class="container8">
						<table class="table4">
							<tr>
								<td class="title4" style="margin-top: 7%;">设备名称</td>
								<td class="text4" style="margin-top: 7%;">齐心加厚订书机</td>
							</tr>
							<tr>
								<td class="title4" style="margin-top: 7%;">设备编号</td>
								<td class="text4" style="margin-top: 7%;">1093</td>
							</tr>
						</table>
						<div class="container7">
							<p class="p8">借出时间</p>
							<p class="p5">2021/04/08 15:20</p>
						</div>
						<button type="button" class="btn4">确认借出</button>
						<button type="button" class="btn4">取消</button>
					</div>
				</div>
				<!--1-->

			</div>
		</div>
	</div>
</body>
<script src="jquery/jquery-3.3.1.min.js"></script>
<script src="bootstrap-3.3.7-dist/js/bootstrap.min.js"></script>
<script>
function getMedia() {
        $("#mainDiv").empty();
        let videoComp = " <video id='video' width='500px' height='668px' autoplay='autoplay' style='margin-top: 20px'></video><canvas id='canvas' width='500px' height='668px' style='display: none'></canvas>";
        $("#mainDiv").append(videoComp);

        let constraints = {
            video: {width: 500, height: 668},
            audio: true
        };
        //获得video摄像头区域
        let video = document.getElementById("video");
        //这里介绍新的方法，返回一个 Promise对象
        // 这个Promise对象返回成功后的回调函数带一个 MediaStream 对象作为其参数
        // then()是Promise对象里的方法
        // then()方法是异步执行，当then()前的方法执行完后再执行then()内部的程序
        // 避免数据没有获取到
        let promise = navigator.mediaDevices.getUserMedia(constraints);
        promise.then(function (MediaStream) {
            video.srcObject = MediaStream;
            video.play();
        });

        // var t1 = window.setTimeout(function() {
        //     takePhoto();
        // },2000)
    }
    //拍照事件
    function takePhoto() {
        let mainComp = $("#mainDiv");
        if(mainComp.has('video').length)
        {
            let userNameInput = $("#userName").val();
            if(userNameInput == "")
            {
                alert("姓名不能为空!");
                return false;
            }
            //获得Canvas对象
            let video = document.getElementById("video");
            let canvas = document.getElementById("canvas");
            let ctx = canvas.getContext('2d');
            ctx.drawImage(video, 0, 0, 500, 668);

            var formData = new FormData();
            var base64File = canvas.toDataURL();
            console.log(base64File);
            var userName = $("#userName").val();
            formData.append("file", base64File);
            formData.append("name", userName);
            formData.append("groupId", "101");
            $.ajax({
                type: "post",
                url: "/faceAdd",
                data: formData,
                contentType: false,
                processData: false,
                async: false,
                success: function (text) {
                    var res = JSON.stringify(text)
                    if (text.code == 0) {
                        alert("注册成功")
                    } else {
                        alert(text.message)
                    }
                },
                error: function (error) {
                    alert(JSON.stringify(error))
                }
            });
        }
        else{
            var formData = new FormData();
            let userName = $("#userName").val();
            formData.append("groupId", "101");
            var file = $("#file0")[0].files[0];
            var reader = new FileReader();
            reader.readAsDataURL(file);
            reader.onload = function () {
            var base64 = reader.result;
            formData.append("file", base64);
            formData.append("name",userName);
                $.ajax({
                    type: "post",
                    url: "/faceAdd",
                    data: formData,
                    contentType: false,
                    processData: false,
                    async: false,
                    success: function (text) {
                        var res = JSON.stringify(text)
                        if (text.code == 0) {
                            alert("注册成功")
                        } else {
                            alert(text.message)
                        }
                    },
                    error: function (error) {
                        alert(JSON.stringify(error))
                    }
                });
                location.reload();
            }
        }

    }

    function imageRecog() {
        let imageInput = " <h2>点击图片区域上传文件</h2><input style='display: none' type='file'  name='file0' id='file0' multiple='multiple' /><br><img src='images/shibie.jpg' id='img0' onclick='toChooseFile()' style='width: 102px;height: 126px;'>";
        $("#mainDiv").empty();
        $("#mainDiv").append(imageInput);
    }

    function toChooseFile()
    {
        $("#file0").trigger('click');
    }
    $(document).on("change","#file0",function(){
        var objUrl = getObjectURL(this.files[0]) ;//获取文件信息
        console.log("objUrl = "+objUrl);
        if (objUrl) {
            $("#img0").attr("src", objUrl);
        }
    });

    function getObjectURL(file) {
        var url = null;
        if (window.createObjectURL!=undefined) {
            url = window.createObjectURL(file) ;
        } else if (window.URL!=undefined) { // mozilla(firefox)
            url = window.URL.createObjectURL(file) ;
        } else if (window.webkitURL!=undefined) { // webkit or chrome
            url = window.webkitURL.createObjectURL(file) ;
        }
        return url ;
    }


</script>
</html>
