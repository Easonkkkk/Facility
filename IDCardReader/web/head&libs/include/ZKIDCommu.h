#ifndef ZKIDCOMMU_H
#define ZKIDCOMMU_H

/**
*	@file		ZKIDCommu.h
*	@brief		���֤�Ķ�����д�ӿ�(����/HID)
*	@author		scar chen
*	@date		2016-11-01
*	@version	2.0
*	@par	��Ȩ��
*				ZKTeco
*	@par	��ʷ�汾
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
	*	@brief	���豸
	*	@param	:
	*	����˵�����±�
	*	name			|	type		|	param direction		|	description of param
	*	----------------|---------------|-----------------------|------------------------
	*	iPort			|	int			|	[in]				|	���±�
	*	@return
	*	����ֵ˵�����£�
	*	value			|	description of value
	*	----------------|-------------------------------
	*	1				|	�ɹ�
	*	0				|	ʧ��
	*	@note 
	*		ID310	\n
	*	������ϸ˵������:
	*	value			|	description of value
	*	----------------|-------------------------------
	*	1~16			|	����
	*	11001			|	HID(��δ֧��)
	*/
ZKINTERFACE int ZKIDCOMMU_Open(int iPort);


/**
	*	@brief	�ر��豸
	*	@param	:
	*	����˵�����±�
	*	name			|	type		|	param direction		|	description of param
	*	----------------|---------------|-----------------------|------------------------
	*	iPort			|	int			|	[in]				|	���±�
	*	@return
	*	����ֵ˵�����£�
	*	value			|	description of value
	*	----------------|-------------------------------
	*	1				|	�ɹ�
	*	0				|	ʧ��
	*	@note 
	*		ID310	\n
	*	������ϸ˵������:
	*	value			|	description of value
	*	----------------|-------------------------------
	*	1~16			|	����
	*	11001			|	HID(��δ֧��)
	*/
ZKINTERFACE int ZKIDCOMMU_Close(int iPort);

/**
	*	@brief	ͨ������/HID��������
	*	@param	:
	*	����˵�����±�
	*	name			|	type		|	param direction		|	description of param
	*	----------------|---------------|-----------------------|------------------------
	*	iPort			|	int			|	[in]				|	���±�
	*   data			| unsigned char*|   [in]				|   ��������
	*	cbData			|	int			|   [in]				|   ���ݳ���
	*	@return
	*	����ֵ˵�����£�
	*	value			|	description of value
	*	----------------|-------------------------------
	*	1				|	�ɹ�
	*	0				|	ʧ��
	*	@note 
	*		ID310	\n
	*	������ϸ˵������:
	*	value			|	description of value
	*	----------------|-------------------------------
	*	1~16			|	����
	*	11001			|	HID(��δ֧��)
	*/
ZKINTERFACE int ZKIDCOMMU_SendBuffer(int iPort, unsigned char* data, int cbData);

/**
	*	@brief	�Ӵ���/HID��ȡ����
	*	@param	:
	*	����˵�����±�
	*	name			|	type		|	param direction		|	description of param
	*	----------------|---------------|-----------------------|------------------------
	*	iPort			|	int			|	[in]				|	���±�
	*   data			| unsigned char*|   [in]				|   ��������
	*	cbData			|	int			|   [in]				|   ���ݳ���
	*	@return
	*	����ֵ˵�����£�
	*	value			|	description of value
	*	----------------|-------------------------------
	*	1				|	�ɹ�
	*	0				|	ʧ��
	*	@note 
	*		ID310	\n
	*	������ϸ˵������:
	*	value			|	description of value
	*	----------------|-------------------------------
	*	1~16			|	����
	*	11001			|	HID(��δ֧��)
	*/

ZKINTERFACE int ZKIDCOMMU_RecvBuffer(int iPort, unsigned char* data, int cbData);


#endif