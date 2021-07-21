#ifndef HIDFUNC_H
#define HIDFUNC_H


/**
*	@file		hidfunc.h
*	@brief		身份证阅读器身份证语音接口函数
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
	*	@brief	语音提示
	*	@param	:
	*	参数说明如下表
	*	name			|	type		|	param direction		|	description of param
	*	----------------|---------------|-----------------------|------------------------
	*	nVoice			|	int			|	[in]				|	见下表
	*	@return
	*	返回值说明如下：
	*	value			|	description of value
	*	----------------|-------------------------------
	*	1				|	成功
	*	0				|	失败
	*	@note 
	*		仅适用于与带HID语音设备的身份证阅读器（如ID200）\n
	*	参数详细说明如下:
	*	value			|	description of value
	*	----------------|-------------------------------
	*	0				|	请放卡
	*	1				|	读卡成功
	*	2				|	读卡失败，请重新放卡
	*	3				|	读卡成功，请核验指纹
	*	4				|	核验成功
	*	5				|	核验失败，请重按手指
	*	6				|	写卡成功
	*	7				|	写卡失败
	*/
	ZKINTERFACE int ZKAPI HIDVoice(int nVoice);

#ifdef __cplusplus
}
#endif


#endif