#ifndef TERMB_H
#define TERMB_H

/**
*	@file		termb.h
*	@brief		身份证阅读器身份证阅读接口函数
*	@author		scar chen
*	@date		2015-06-29
*	@version	2.0
*	@par	版权：
*				ZKTeco
*	@par	历史版本
*
*	@note		
*
*/

#ifndef ZKAPI
#define ZKAPI __stdcall
#endif

#ifndef ZKINTERFACE
#ifndef _USRDLL 
#ifdef _LIB
#define ZKINTERFACE
#else
#define ZKINTERFACE __declspec(dllimport)
#endif
#else	//_ZKDLL
#define ZKINTERFACE
#endif	//_ZKDLL
#endif


#ifdef __cplusplus
extern "C"
{
#endif


	/**
	*	@brief	连接身份证阅读器
	*	@param	:
	*	参数说明如下表
	*	name			|	type		|	param direction		|	description of param
	*	----------------|---------------|-----------------------|------------------------
	*	iPort			|	int			|	[in]				|	端口号（说明见下表）
	*	@return
	*	返回值说明如下：
	*	value			|	description of value
	*	----------------|-------------------------------
	*	>0				|	成功返回端口号
	*	0				|	失败
	*	@note 
	*	端口号说明如下：
	*	value			|	description of value
	*	----------------|-------------------------------
	*	1~16			|	串口设备
	*	1001~1016		|	USB设备
	*/
	ZKINTERFACE int ZKAPI InitComm(int Port);

	/**
	*	@brief	自动搜索身份证阅读器并连接身份证阅读器
	*	@param	:
	*		无
	*	@return
	*	返回值说明如下：
	*	value			|	description of value
	*	----------------|-------------------------------
	*	>0				|	成功返回端口号
	*	0				|	失败
	*	@note	
	*/
	ZKINTERFACE int ZKAPI InitCommExt();



	/**
	*	@brief	断开与身份证阅读器连接
	*	@param	:
	*		无
	*	@return
	*	返回值说明如下：
	*	value			|	description of value
	*	----------------|-------------------------------
	*	1				|	成功
	*	0				|	失败
	*	@note 
	*/
	ZKINTERFACE int ZKAPI CloseComm();
	
	
	
	/**
	*	@brief	卡认证，本函数用于读卡器和卡片之间的合法身份确认
	*	@param	:
	*		无
	*	@return
	*	返回值说明如下：
	*	value			|	description of value
	*	----------------|-------------------------------
	*	1				|	成功
	*	-1				|	寻卡失败
	*	-2				|	选卡失败
	*	0				|	其他错误
	*	@note 
	*		前置条件：InitComm/InitCommExt 调用成功
	*/
	ZKINTERFACE int ZKAPI Authenticate();


	/**
	*	@brief	读卡操作,信息文件存储在dll所在下
	*	@param	:
	*	参数说明如下表
	*	name			|	type		|	param direction		|	description of param
	*	----------------|---------------|-----------------------|------------------------
	*	Active			|	int			|	[in]				|	见下表
	*	@return
	*	返回值说明如下：
	*	value			|	description of value
	*	----------------|-------------------------------
	*	1				|	成功（二代证读取成功）
	*	2				|	成功（永居证读取成功）
	*	3				|   成功（港澳台居住证读取成功）
	*	-11				|	无效参数
	*	-101			|	写入文件失败，二代证可以调用接口获取文字信息(如getName)
	*	0				|	其他错误
	*	@note 
	*		前置条件：Authenticate 调用成功\n
	*	参数详细说明如下:
	*	value			|	description of value
	*	----------------|-------------------------------
	*	1				|	读基本信息，形成文字信息文件WZ.TXT、相片文件XP.WLT、ZP.BMP，如果有指纹信息形成指纹信息文件FP.DAT
	*	2				|	只读文字信息，形成文字信息文件WZ.TXT和相片文件XP.WLT
	*	3				|	读最新住址信息，形成最新住址文件NEWADD.TXT
	*/
	ZKINTERFACE int ZKAPI Read_Content(int Active);


	/**
	*	@brief	读卡操作,信息文件存储在dll所在下（同Read_Content，解决JNA调用问题）
	*	@param	:
	*	参数说明如下表
	*	name			|	type		|	param direction		|	description of param
	*	----------------|---------------|-----------------------|------------------------
	*	Active			|	int			|	[in]				|	见下表
	*	@return
	*	返回值说明如下：
	*	value			|	description of value
	*	----------------|-------------------------------
	*	1				|	成功（二代证读取成功）
	*	2				|	成功（永居证读取成功）
	*	3				|   成功（港澳台居住证读取成功）
	*	-11				|	无效参数
	*	-101			|	写入文件失败，可以调用接口获取文字信息(如getName)
	*	0				|	其他错误
	*	@note 
	*		前置条件：Authenticate 调用成功\n
	*	参数详细说明如下:
	*	value			|	description of value
	*	----------------|-------------------------------
	*	1				|	读基本信息，形成文字信息文件WZ.TXT、相片文件XP.WLT、ZP.BMP，如果有指纹信息形成指纹信息文件FP.DAT
	*	2				|	只读文字信息，形成文字信息文件WZ.TXT和相片文件XP.WLT
	*	3				|	读最新住址信息，形成最新住址文件NEWADD.TXT
	*/
	ZKINTERFACE int ZKAPI ReadContent(int Active);


	/**
	*	@brief	获取SAM模块编号
	*	@param	:
	*	参数说明如下表
	*	name			|	type		|	param direction		|	description of param
	*	----------------|---------------|-----------------------|------------------------
	*	SAMID			|	char*		|	[out]				|	SAM模块编号
	*	@return
	*	返回值说明如下：
	*	value			|	description of value
	*	----------------|-------------------------------
	*	1				|	成功
	*	0				|	失败
	*	@note 
	*		前置条件：InitComm/InitCommExt 调用成功
	*/
	ZKINTERFACE int ZKAPI GetSAMID(char *SAMID);

	/**
	*	@brief	获取SAM模块编号（10位编号）
	*	@param	:
	*	参数说明如下表
	*	name			|	type		|	param direction		|	description of param
	*	----------------|---------------|-----------------------|------------------------
	*	SAMID			|	char*		|	[out]				|	SAM模块编号
	*	@return
	*	返回值说明如下：
	*	value			|	description of value
	*	----------------|-------------------------------
	*	1				|	成功
	*	0				|	失败
	*	@note 
	*		前置条件：InitComm/InitCommExt 调用成功
	*/
	ZKINTERFACE int ZKAPI GetSAMIDEx(char *SAMID);



	/**
	*	@brief	解析身份证照片
	*	@param	:
	*	参数说明如下表
	*	name			|	type		|	param direction		|	description of param
	*	----------------|---------------|-----------------------|------------------------
	*	pszPath			|	char*		|	[in]				|	xp.wlt图片文件全路径
	*	@return
	*	返回值说明如下：
	*	value			|	description of value
	*	----------------|-------------------------------
	*	1				|	成功
	*	0				|	失败
	*	@note 
	*		前置条件：Read_Content 调用成功
	*/
	ZKINTERFACE int ZKAPI GetBmpPhoto(const char* pszPath);

	/**
	*	@brief	解析身份证照片
	*	@param	:
	*		无
	*	@return
	*	返回值说明如下：
	*	value			|	description of value
	*	----------------|-------------------------------
	*	1				|	成功
	*	0				|	失败
	*	@note 
	*		前置条件：Read_Content 调用成功
	*/
	ZKINTERFACE int ZKAPI GetBmpPhotoExt();
	

	/**
	*	@brief	重置Sam模块
	*	@param	:
	*		无
	*	@return
	*	返回值说明如下：
	*	value			|	description of value
	*	----------------|-------------------------------
	*	1				|	成功
	*	0				|	失败
	*	@note 
	*	前置条件：InitComm/InitCommExt 调用成功
	*/
	ZKINTERFACE int ZKAPI Reset_SAM();

	/**
	*	@brief	获取SAM模块状态
	*	@param	:
	*		无
	*	@return
	*	返回值说明如下：
	*	value			|	description of value
	*	----------------|-------------------------------
	*	1				|	状态正常
	*	0				|	状态异常
	*	@note 
	*	前置条件：InitComm/InitCommExt 调用成功
	*/
	ZKINTERFACE int ZKAPI GetSAMStatus();


	/**
	*	@brief	解析身份证信息
	*	@param	:
	*	参数说明如下表
	*	name			|	type		|	param direction		|	description of param
	*	----------------|---------------|-----------------------|------------------------
	*	index			|	int			|	[in]				|	类型
	*	value			|	char*		|	[out]				|	返回值
	*		无
	*	@return
	*	返回值说明如下：
	*	value			|	description of value
	*	----------------|-------------------------------
	*	1				|	成功
	*	0				|	失败
	*	@note 
	*	前置条件：Read_Content 调用成功\n
	*	详细参数说明如下：
	*	value			|	description of value
	*	----------------|-------------------------------
	*	index(0)		|	获取姓名
	*	index(1)		|	获取性别
	*	index(2)		|	获取民族
	*	index(3)		|	获取出生日期(YYYYMMDD)
	*	index(4)		|	获取地址
	*	index(5)		|	获取身份证号
	*	index(6)		|	签发机关
	*	index(7)		|	有效期起始日期(YYYYMMDD)
	*	index(8)		|	有效期截止日期(YYYYMMDD)
	*	index(101)		|	英文名
	*	index(102)		|	中文名
	*	index(103)		|	通行证号
	*	index(104)		|	签证次数
	*	index(105)		|	证件类型
	*	@note 
	*		具体字段是否各类证件支持，参考getXXX说明
	*/
	ZKINTERFACE int ZKAPI GetCardInfo(int index, char *value);



	/******
	*	@brief	设置生成文件临时目录
	*	@param	:
	*	参数说明如下表
	*	name			|	type		|	param direction		|	description of param
	*	----------------|---------------|-----------------------|------------------------
	*	path			|	char*		|	[in]				|	生成图片临时目录
	*	@return
	*		无
	*	@note 
	*		未设置默认为本dll所在目录
	*		设置为NULL时将不保存本地文件；图片数据可以调用获取Base64字符串
	*/
	ZKINTERFACE void ZKAPI SetTempDir(char *path);



	/**
	*	@brief	获取文件生成临时目录
	*	@param	:
	*	参数说明如下表
	*	name			|	type		|	param direction		|	description of param
	*	----------------|---------------|-----------------------|------------------------
	*	path			|	char*		|	[out]				|	生成图片临时目录
	*	cbPath			|	int			|	[in]				|	分配缓冲区长度(建议260Bytes)
	*	@return
	*		无
	*	@note 
	*		未设置返回当前dll所在目录路径
	*/
	ZKINTERFACE void ZKAPI GetTempDir(char *path, int cbPath);


	/******
	*	@brief	设置jpg头像全路径名
	*	@param	:
	*	参数说明如下表
	*	name			|	type		|	param direction		|	description of param
	*	----------------|---------------|-----------------------|------------------------
	*	path			|	char*		|	[in]				|	生成jpg图像文件全路径名
	*	@return
	*		无
	*	@note 
	*		未设置默认为本dll所在目录的zp.jpg
	*/
	ZKINTERFACE void ZKAPI SetPhotoJPGPathName(char *path);



	/******
	*	@brief	获取jpg头像全路径名
	*	@param	:
	*	参数说明如下表
	*	name			|	type		|	param direction		|	description of param
	*	----------------|---------------|-----------------------|------------------------
	*	path			|	char*		|	[out]				|	生成图片jpg文件全路径
	*	cbPath			|	int			|	[in]				|	分配缓冲区长度(建议260Bytes)
	*	@return
	*		无
	*	@note 
	*		未设置返回本dll所在目录的zp.jpg的全路径
	*/
	ZKINTERFACE void ZKAPI GetPhotoJPGPathName(char *path, int cbPath);
	



	//value

	/*
		名称：getName
		描述：获取姓名
		参数：
			data,姓名
			cbData,data缓冲区大小
		返回：
			无
		前提：Read_Content 调用成功
	*/

	/**
	*	@brief	获取姓名
	*	@param	:
	*	参数说明如下表
	*	name			|	type		|	param direction		|	description of param
	*	----------------|---------------|-----------------------|------------------------
	*	path			|	char*		|	[out]				|	返回值
	*	cbPath			|	int			|	[in]				|	分配缓冲区长度(建议64Bytes)
	*	@return
	*		无
	*	@note 
	*		前提：Read_Content 调用成功	\r\n
	*		永居证姓名格式英文名/中文名组合;港澳台居住证同二代证
	*/
	ZKINTERFACE void ZKAPI getName(char *data, int cbData);


	/**
	*	@brief	获取性别
	*	@param	:
	*	参数说明如下表
	*	name			|	type		|	param direction		|	description of param
	*	----------------|---------------|-----------------------|------------------------
	*	path			|	char*		|	[out]				|	返回值
	*	cbPath			|	int			|	[in]				|	分配缓冲区长度(建议64Bytes)
	*	@return
	*		无
	*	@note 
	*		前提：Read_Content 调用成功	\r\n
	*		永居证、港澳台居住证同二代证
	*/
	ZKINTERFACE void ZKAPI getSex(char *data, int cbData);

	/**
	*	@brief	获取性别代码
	*	@param	:
	*		无
	*	@return
	*		性别代码
	*	@note 
	*		前提：Read_Content 调用成功	\r\n
	*		永居证、港澳台居住证同二代证
	*/
	ZKINTERFACE int	 ZKAPI getSexCode();

	/**
	*	@brief	获取民族
	*	@param	:
	*	参数说明如下表
	*	name			|	type		|	param direction		|	description of param
	*	----------------|---------------|-----------------------|------------------------
	*	path			|	char*		|	[out]				|	返回值
	*	cbPath			|	int			|	[in]				|	分配缓冲区长度(建议64Bytes)
	*	@return
	*		无
	*	@note 
	*		前提：Read_Content 调用成功	\r\n
	*		永居证:国家/国家编码；港澳台居住证同二代证
	*/
	ZKINTERFACE void  ZKAPI getNation(char *data, int cbData);

	/**
	*	@brief	获取民族代码
	*	@param	:
	*		无
	*	@return
	*		民族代码
	*	@note 
	*		前提：Read_Content 调用成功	\r\n
	*		永居证、港澳台居住证无此项
	*/
	ZKINTERFACE int ZKAPI getNationCode();

	/**
	*	@brief	获取生日(YYYYMMDD)
	*	@param	:
	*	参数说明如下表
	*	name			|	type		|	param direction		|	description of param
	*	----------------|---------------|-----------------------|------------------------
	*	path			|	char*		|	[out]				|	返回值
	*	cbPath			|	int			|	[in]				|	分配缓冲区长度(建议64Bytes)
	*	@return
	*		无
	*	@note 
	*		前提：Read_Content 调用成功	\r\n
	*		永居证、港澳台居住证同二代证
	*/
	ZKINTERFACE void ZKAPI getBirthdate(char *data, int cbData);

	/*
		名称：getBirthYear
		描述：获取出生年
		参数：
			无
		返回：
			出生年
		前提：Read_Content 调用成功
	*/
	ZKINTERFACE int ZKAPI getBirthYear();

	/*
		名称：getBirthMon
		描述：获取出生月
		参数：
			无
		返回：
			出生月
		前提：Read_Content 调用成功
	*/
	ZKINTERFACE int ZKAPI getBirthMon();

	/*
		名称：getBirthDay
		描述：获取出生日
		参数：
			无
		返回：
			出生日
		前提：Read_Content 调用成功
	*/
	ZKINTERFACE int ZKAPI getBirthDay();

	/**
	*	@brief	获取地址
	*	@param	:
	*	参数说明如下表
	*	name			|	type		|	param direction		|	description of param
	*	----------------|---------------|-----------------------|------------------------
	*	path			|	char*		|	[out]				|	返回值
	*	cbPath			|	int			|	[in]				|	分配缓冲区长度(建议64Bytes)
	*	@return
	*		无
	*	@note 
	*		前提：Read_Content 调用成功	\r\n
	*		永居证无地址项；港澳台居住证同二代证
	*/
	ZKINTERFACE void ZKAPI getAddress(char *data, int cbData);

	/**
	*	@brief	获取身份证号
	*	@param	:
	*	参数说明如下表
	*	name			|	type		|	param direction		|	description of param
	*	----------------|---------------|-----------------------|------------------------
	*	path			|	char*		|	[out]				|	返回值
	*	cbPath			|	int			|	[in]				|	分配缓冲区长度(建议64Bytes)
	*	@return
	*		无
	*	@note 
	*		前提：Read_Content 调用成功		\r\n
	*		永居证/港澳台居住证证件号
	*/
	ZKINTERFACE void ZKAPI getIDNum(char *data, int cbData);

	/**
	*	@brief	获取签发机关
	*	@param	:
	*	参数说明如下表
	*	name			|	type		|	param direction		|	description of param
	*	----------------|---------------|-----------------------|------------------------
	*	path			|	char*		|	[out]				|	返回值
	*	cbPath			|	int			|	[in]				|	分配缓冲区长度(建议64Bytes)
	*	@return
	*		无
	*	@note 
	*		前提：Read_Content 调用成功		\r\n
	*		永居证为签发机关代码；港澳台居住证同二代证
	*/
	ZKINTERFACE void ZKAPI getIssue(char *data, int cbData);

	/**
	*	@brief	获取有效期起始日期(YYYYMMDD)
	*	@param	:
	*	参数说明如下表
	*	name			|	type		|	param direction		|	description of param
	*	----------------|---------------|-----------------------|------------------------
	*	path			|	char*		|	[out]				|	返回值
	*	cbPath			|	int			|	[in]				|	分配缓冲区长度(建议64Bytes)
	*	@return
	*		无
	*	@note 
	*		前提：Read_Content 调用成功		\r\n
	*		永居证、港澳台居住证同二代证
	*/
	ZKINTERFACE void ZKAPI getEffectedDate(char *data, int cbData);

	/**
	*	@brief	获取有效期截止日期(YYYYMMDD)
	*	@param	:
	*	参数说明如下表
	*	name			|	type		|	param direction		|	description of param
	*	----------------|---------------|-----------------------|------------------------
	*	path			|	char*		|	[out]				|	返回值
	*	cbPath			|	int			|	[in]				|	分配缓冲区长度(建议64Bytes)
	*	@return
	*		无
	*	@note 
	*		前提：Read_Content 调用成功		\r\n
	*		永居证、港澳台居住证同二代证
	*/
	ZKINTERFACE void ZKAPI getExpiredDate(char *data, int cbData);


	/**
	*	@brief	获取英文文名
	*	@param	:
	*	参数说明如下表
	*	name			|	type		|	param direction		|	description of param
	*	----------------|---------------|-----------------------|------------------------
	*	path			|	char*		|	[out]				|	返回值
	*	cbPath			|	int			|	[in]				|	分配缓冲区长度(建议64Bytes)
	*	@return
	*		无
	*	@note 
	*		前提：Read_Content 调用成功		\r\n
	*		永居证独有此项
	*/
	ZKINTERFACE void ZKAPI getEnName(char *data, int cbData);

	/**
	*	@brief	获取中文名
	*	@param	:
	*	参数说明如下表
	*	name			|	type		|	param direction		|	description of param
	*	----------------|---------------|-----------------------|------------------------
	*	path			|	char*		|	[out]				|	返回值
	*	cbPath			|	int			|	[in]				|	分配缓冲区长度(建议64Bytes)
	*	@return
	*		无
	*	@note 
	*		前提：Read_Content 调用成功		\r\n
	*		永居证独有此项
	*/
	ZKINTERFACE void ZKAPI getCnName(char *data, int cbData);

	/**
	*	@brief	获取通行证号
	*	@param	:
	*	参数说明如下表
	*	name			|	type		|	param direction		|	description of param
	*	----------------|---------------|-----------------------|------------------------
	*	path			|	char*		|	[out]				|	返回值
	*	cbPath			|	int			|	[in]				|	分配缓冲区长度(建议64Bytes)
	*	@return
	*		无
	*	@note 
	*		前提：Read_Content 调用成功		\r\n
	*		港澳台居住证独有此项
	*/
	ZKINTERFACE void ZKAPI getPassNum(char *data, int cbData);


	/**
	*	@brief	获取签证次数
	*	@param	:
	*		无
	*	@return
	*		签证次数
	*	@note 
	*		前提：Read_Content 调用成功	\r\n
	*		港澳台居住证独有此项
	*/
	ZKINTERFACE int ZKAPI getVisaTimes();


	/**
	*	@brief	获取BMP头像Base64编码
	*	@param	:
	*	参数说明如下表
	*	name			|	type		|	param direction		|	description of param
	*	----------------|---------------|-----------------------|------------------------
	*	path			|	char*		|	[out]				|	返回值
	*	cbPath			|	int			|	[in]				|	分配缓冲区长度(建议256*1024Bytes)
	*	@return
	*		无
	*	@note 
	*		前提：GetBmpPhoto/GetBmpPhotoExt 调用成功	
	*/
	ZKINTERFACE void ZKAPI getBMPPhotoBase64(char *data, int cbData);

	/**
	*	@brief	获取JPG头像Base64编码
	*	@param	:
	*	参数说明如下表
	*	name			|	type		|	param direction		|	description of param
	*	----------------|---------------|-----------------------|------------------------
	*	path			|	char*		|	[out]				|	返回值
	*	cbPath			|	int			|	[in]				|	分配缓冲区长度(建议256*1024Bytes)
	*	@return
	*		无
	*	@note 
	*		前提：GetBmpPhoto/GetBmpPhotoExt 调用成功	
	*/
	ZKINTERFACE void ZKAPI getJPGPhotoBase64(char *data, int cbData);


	/**
	*	@brief	获取指纹数据base64编码字符串
	*	@param	:
	*	参数说明如下表
	*	name			|	type		|	param direction		|	description of param
	*	----------------|---------------|-----------------------|------------------------
	*	path			|	char*		|	[out]				|	返回值
	*	cbPath			|	int			|	[in]				|	分配缓冲区长度(建议256*1024Bytes)
	*	@return
	*		无
	*	@note 
	*		前提：Read_Content 调用成功	
	*/
	ZKINTERFACE void ZKAPI getFPDataBase64(char *data, int cbData);


	/**
	*	@brief	解析居民身份证文字信息
	*	@param	:
	*	参数说明如下表
	*	name			|	type		|	param direction		|	description of param
	*	----------------|---------------|-----------------------|------------------------
	*	pcCHMsg			|	char*		|	[out]				|	请预分配至少192字节，结构体参考补充文档
	*	@return
	*		无
	*	@note 
	*		前提：Read_Content返回1
	*/
	ZKINTERFACE void ZKAPI DecodeIDBaseMsg(char * pcCHMsg);

	/**
	*	@brief	解析永居证文字信息
	*	@param	:
	*	参数说明如下表
	*	name			|	type		|	param direction		|	description of param
	*	----------------|---------------|-----------------------|------------------------
	*	pcCHMsg			|	char*		|	[out]				|	请预分配至少152字节，结构体参考补充文档
	*	@return
	*		无
	*	@note 
	*		前提：Read_Content返回2
	*/
	ZKINTERFACE void ZKAPI DecodeGCBaseMsg(char * pcCHMsg);


	/******
	*	@brief	获取证件类型
	*	@param	:
	*		无
	*	@return
	*	返回值说明如下：
	*	value			|	description of value
	*	----------------|-------------------------------
	*	1				|	二代证
	*	2				|	永居证
	*	3				|   港澳台居住证
	*	@note 
	*	前置条件：Read_Content 调用成功
	*/
	ZKINTERFACE int	 ZKAPI getCardType();



	ZKINTERFACE int ZKAPI ExportCardImageV();
	ZKINTERFACE int ZKAPI ExportCardImageH();
	ZKINTERFACE int ZKAPI ExportCardImageF();
	ZKINTERFACE int ZKAPI ExportCardImageB();
	ZKINTERFACE void ZKAPI getJPGCardBase64V(char *data, int cbData);
	ZKINTERFACE void ZKAPI getJPGCardBase64H(char *data, int cbData);
	ZKINTERFACE void ZKAPI getJPGCardBase64F(char *data, int cbData);
	ZKINTERFACE void ZKAPI getJPGCardBase64B(char *data, int cbData);
	ZKINTERFACE void ZKAPI SetTransparentThreshold(unsigned char R, unsigned char G, unsigned char B);
	ZKINTERFACE void ZKAPI SetCardJPGPathNameV(char *path);
	ZKINTERFACE void ZKAPI GetCardJPGPathNameV(char *path, int cbpath);
	ZKINTERFACE void ZKAPI SetCardJPGPathNameH(char *path);
	ZKINTERFACE void ZKAPI GetCardJPGPathNameH(char *path, int cbpath);
#ifdef __cplusplus
}
#endif

#endif