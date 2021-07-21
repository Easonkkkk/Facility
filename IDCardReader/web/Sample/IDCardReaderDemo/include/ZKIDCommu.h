#ifndef ZKIDCOMMU_H
#define ZKIDCOMMU_H

/**
*	@file		ZKIDCommu.h
*	@brief		身份证阅读器读写接口(串口/HID)
*	@author		scar chen
*	@date		2016-11-01
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

/**
	*	@brief	打开设备
	*	@param	:
	*	参数说明如下表
	*	name			|	type		|	param direction		|	description of param
	*	----------------|---------------|-----------------------|------------------------
	*	iPort			|	int			|	[in]				|	见下表
	*	@return
	*	返回值说明如下：
	*	value			|	description of value
	*	----------------|-------------------------------
	*	1				|	成功
	*	0				|	失败
	*	@note 
	*		ID310	\n
	*	参数详细说明如下:
	*	value			|	description of value
	*	----------------|-------------------------------
	*	1~16			|	串口
	*	11001			|	HID(暂未支持)
	*/
ZKINTERFACE int ZKIDCOMMU_Open(int iPort);


/**
	*	@brief	关闭设备
	*	@param	:
	*	参数说明如下表
	*	name			|	type		|	param direction		|	description of param
	*	----------------|---------------|-----------------------|------------------------
	*	iPort			|	int			|	[in]				|	见下表
	*	@return
	*	返回值说明如下：
	*	value			|	description of value
	*	----------------|-------------------------------
	*	1				|	成功
	*	0				|	失败
	*	@note 
	*		ID310	\n
	*	参数详细说明如下:
	*	value			|	description of value
	*	----------------|-------------------------------
	*	1~16			|	串口
	*	11001			|	HID(暂未支持)
	*/
ZKINTERFACE int ZKIDCOMMU_Close(int iPort);

/**
	*	@brief	通过串口/HID发送数据
	*	@param	:
	*	参数说明如下表
	*	name			|	type		|	param direction		|	description of param
	*	----------------|---------------|-----------------------|------------------------
	*	iPort			|	int			|	[in]				|	见下表
	*   data			| unsigned char*|   [in]				|   发送数据
	*	cbData			|	int			|   [in]				|   数据长度
	*	@return
	*	返回值说明如下：
	*	value			|	description of value
	*	----------------|-------------------------------
	*	1				|	成功
	*	0				|	失败
	*	@note 
	*		ID310	\n
	*	参数详细说明如下:
	*	value			|	description of value
	*	----------------|-------------------------------
	*	1~16			|	串口
	*	11001			|	HID(暂未支持)
	*/
ZKINTERFACE int ZKIDCOMMU_SendBuffer(int iPort, unsigned char* data, int cbData);

/**
	*	@brief	从串口/HID读取数据
	*	@param	:
	*	参数说明如下表
	*	name			|	type		|	param direction		|	description of param
	*	----------------|---------------|-----------------------|------------------------
	*	iPort			|	int			|	[in]				|	见下表
	*   data			| unsigned char*|   [in]				|   发送数据
	*	cbData			|	int			|   [in]				|   数据长度
	*	@return
	*	返回值说明如下：
	*	value			|	description of value
	*	----------------|-------------------------------
	*	1				|	成功
	*	0				|	失败
	*	@note 
	*		ID310	\n
	*	参数详细说明如下:
	*	value			|	description of value
	*	----------------|-------------------------------
	*	1~16			|	串口
	*	11001			|	HID(暂未支持)
	*/

ZKINTERFACE int ZKIDCOMMU_RecvBuffer(int iPort, unsigned char* data, int cbData);


#endif