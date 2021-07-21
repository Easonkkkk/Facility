#ifndef MFFUNC_H
#define MFFUNC_H

/**
*	@file		mffunc.h
*	@brief		身份证阅读器身份证发卡接口函数
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
	*	@brief 设置发卡器序列号
	*	@param	:
	*	参数说明如下表
	*	name			|	type		|	param direction		|	description of param
	*	----------------|---------------|-----------------------|------------------------
	*	iPort			|	int			|	[in]				|	串口号
	*	data			|	char*		|	[in]				|	设备序列号(HEX,ex FFFFFFFFFFFFFFFF)
	*	cbdata			|	int			|	[in]				|	序列号长度(16个字符)
	*	@return
	*	返回值说明如下：
	*	value			|	description of value
	*	----------------|-------------------------------
	*	1				|	成功
	*	0				|	失败
	*	@note 
	*		本接口仅适用于带发卡功能的身份证阅读器(如ID180)
	*/
	ZKINTERFACE int ZKAPI  IC_SetDevNum(int iPort, char *data, int cbdata);

	/**
	*	@brief 获取发卡器序列号
	*	@param	:
	*	参数说明如下表
	*	name			|	type		|	param direction		|	description of param
	*	----------------|---------------|-----------------------|------------------------
	*	iPort			|	int			|	[in]				|	串口号
	*	data			|	char*		|	[out]				|	返回设备序列号(HEX,ex FFFFFFFFFFFFFFFF)
	*	cbdata			|	int			|	[in]				|	缓冲区长度(17含截尾0)
	*	@return
	*	返回值说明如下：
	*	value			|	description of value
	*	----------------|-------------------------------
	*	1				|	成功
	*	0				|	失败
	*	@note 
	*		本接口仅适用于带发卡功能的身份证阅读器(如ID180)
	*/
	ZKINTERFACE int ZKAPI  IC_GetDevNum(int iPort, char *data, int cbdata);

	/**
	*	@brief 设置发卡器序列号
	*	@param	:
	*	参数说明如下表
	*	name			|	type		|	param direction		|	description of param
	*	----------------|---------------|-----------------------|------------------------
	*	iPort			|	int			|	[in]				|	串口号
	*	data			|	char*		|	[out]				|	设备版本号(HEX,ex FFFFFFFFFFFF)
	*	cbdata			|	int			|	[in]				|	缓冲区长度(13含截尾0)
	*	@return
	*	返回值说明如下：
	*	value			|	description of value
	*	----------------|-------------------------------
	*	1				|	成功
	*	0				|	失败
	*	@note 
	*		本接口仅适用于带发卡功能的身份证阅读器(如ID180)
	*/
	ZKINTERFACE int ZKAPI  IC_GetDevVersion(int iPort, char *data, int cbdata);

	/**
	*	@brief 写数据
	*	@param	:
	*	参数说明如下表
	*	name			|	type		|	param direction		|	description of param
	*	----------------|---------------|-----------------------|------------------------
	*	iPort			|	int			|	[in]				|	串口号
	*	keyMode			|	int			|	[in]				|	0,keyA,1KeyB
	*	sector			|	int			|	[in]				|	扇区号(0~15),共有16扇区
	*	idx				|	int			|	[in]				|	块索引(0~2),每个扇区有4块，第四扇区为控制块禁止读写
	*	key				|	char*		|	[in]				|	扇区密钥(ex,FFFFFFFFFFFF)
	*	data			|	char*		|	[in]				|	数据(16字节,32个16进制字符)
	*	cbdata			|	int			|	[in]				|	数据长度,32个字符
	*	snr				|	unsigned int|	[out]				|	返回IC卡物理卡号
	*	@return
	*	返回值说明如下：
	*	value			|	description of value
	*	----------------|-------------------------------
	*	1				|	成功
	*	0				|	失败
	*	@note 
	*		本接口仅适用于带发卡功能的身份证阅读器(如ID180)
	*/
	ZKINTERFACE int ZKAPI  IC_WriteData(int iPort, int keyMode, int sector, int idx, char *key, char *data, int cbdata, unsigned int *snr);

	/**
	*	@brief 读数据
	*	@param	:
	*	参数说明如下表
	*	name			|	type		|	param direction		|	description of param
	*	----------------|---------------|-----------------------|------------------------
	*	iPort			|	int			|	[in]				|	串口号
	*	keyMode			|	int			|	[in]				|	0,keyA,1KeyB
	*	sector			|	int			|	[in]				|	扇区号(0~15),共有16扇区
	*	idx				|	int			|	[in]				|	块索引(0~2),每个扇区有4块，第四扇区为控制块禁止读写
	*	key				|	char*		|	[in]				|	扇区密钥(ex,FFFFFFFFFFFF)
	*	data			|	char*		|	[out]				|	数据(16字节,32个16进制字符)
	*	cbdata			|	int			|	[in]				|	缓冲区长度,33含截尾0
	*	snr				| unsigned int* |	[out]				|	返回IC卡物理卡号
	*	@return
	*	返回值说明如下：
	*	value			|	description of value
	*	----------------|-------------------------------
	*	1				|	成功
	*	0				|	失败
	*	@note 
	*		本接口仅适用于带发卡功能的身份证阅读器(如ID180)
	*/
	ZKINTERFACE int ZKAPI  IC_ReadData(int iPort, int keyMode, int sector, int idx, char *key, char *data, int cbdata, unsigned int *snr);

	/**
	*	@brief 读IC卡物理卡号
	*	@param	:
	*	参数说明如下表
	*	name			|	type		|	param direction		|	description of param
	*	----------------|---------------|-----------------------|------------------------
	*	iPort			|	int			|	[in]				|	串口号
	*	snr				| unsigned int* |	[out]				|	IC卡物理卡号
	*	@return
	*	返回值说明如下：
	*	value			|	description of value
	*	----------------|-------------------------------
	*	1				|	成功
	*	0				|	失败
	*	@note 
	*		本接口仅适用于带发卡功能的身份证阅读器(如ID180)
	*/
	ZKINTERFACE int ZKAPI  IC_GetICSnr(int iPort, unsigned int *snr);

	/**
	*	@brief 读身份证物理卡号
	*	@param	:
	*	参数说明如下表
	*	name			|	type		|	param direction		|	description of param
	*	----------------|---------------|-----------------------|------------------------
	*	iPort			|	int			|	[in]				|	串口号
	*	data			|	char*		|	[out]				|	身份证物理卡号64bit（ex,FFFFFFFFFFFFFFFF）
	*	cbdata			|	int			|	[in]				|	缓冲区长度（17含截尾0）
	*	@return
	*	返回值说明如下：
	*	value			|	description of value
	*	----------------|-------------------------------
	*	1				|	成功
	*	0				|	失败
	*	@note 
	*		本接口仅适用于带发卡功能的身份证阅读器(如ID180)
	*/
	ZKINTERFACE int ZKAPI  IC_GetIDSnr(int iPort, char *data, int cbdata);

	/**
	*	@brief 读取DN码
	*	@param	:
	*	参数说明如下表
	*	name			|	type		|	param direction		|	description of param
	*	----------------|---------------|-----------------------|------------------------
	*	iPort			|	int			|	[in]				|	串口号
	*	data			|	char*		|	[out]				|	DN码16Bytes（ex,FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF）
	*	cbdata			|	int			|	[in]				|	缓冲区长度（最小33Bytes含截尾0）
	*	@return
	*	返回值说明如下：
	*	value			|	description of value
	*	----------------|-------------------------------
	*	1				|	成功
	*	0				|	失败
	*	@note 
	*		
	*/
	ZKINTERFACE int ZKAPI  IC_GetIDDNCode(int iPort, char *data, int cbdata);


	/**
	*	@brief 修改IC卡扇区密码
	*	@param	:
	*	参数说明如下表
	*	name			|	type		|	param direction		|	description of param
	*	----------------|---------------|-----------------------|------------------------
	*	iPort			|	int			|	[in]				|	串口号
	*	keyMode			|	int			|	[in]				|	0,keyA,1KeyB
	*	nSector			|	int			|	[in]				|	扇区号(0~15),共有16扇区
	*	oldKey			|	char*		|	[in]				|	原始密码(ex:FFFFFFFFFFFF) 12bytes hexstring
	*	newKey			|	char*		|	[in]				|	新密码(ex:FFFFFFFFFFFF)	12bytes hexstring
	*	@return
	*	返回值说明如下：
	*	value			|	description of value
	*	----------------|-------------------------------
	*	1				|	成功
	*	0				|	失败
	*	@note 
	*		本接口仅适用于带发卡功能的身份证阅读器(如ID180)
	*/
	ZKINTERFACE int ZKAPI  IC_ChangeSectorKey(int iPort, int keyMode, int nSector, char *oldKey, char *newKey);


	/**
	*	@brief 读银行卡卡号
	*	@param	:
	*	参数说明如下表
	*	name			|	type		|	param direction		|	description of param
	*	----------------|---------------|-----------------------|------------------------
	*	iPort			|	int			|	[in]				|	串口号
	*	data			|	char*		|	[out]				|	银行卡卡号
	*	cbdata			|	int			|	[in]				|	缓冲区长度
	*	@return
	*	返回值说明如下：
	*	value			|	description of value
	*	----------------|-------------------------------
	*	>0				|	卡号长度
	*	0				|	失败
	*	@note 
	*		本接口仅适用于带发卡功能的身份证阅读器(定制支持银行卡卡号设备)
	*/
	ZKINTERFACE int ZKAPI  IC_GetBankCardNum(int iPort, char *data, int cbdata);

#ifdef __cplusplus
}
#endif

#endif