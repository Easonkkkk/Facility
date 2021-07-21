#ifndef HIDFUNC_H
#define HIDFUNC_H


/**
*	@file		hidfunc.h
*	@brief		���֤�Ķ������֤�����ӿں���
*	@author		scar chen
*	@date		2015-06-29
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


#ifdef __cplusplus
extern "C"
{
#endif


	/**
	*	@brief	������ʾ
	*	@param	:
	*	����˵�����±�
	*	name			|	type		|	param direction		|	description of param
	*	----------------|---------------|-----------------------|------------------------
	*	nVoice			|	int			|	[in]				|	���±�
	*	@return
	*	����ֵ˵�����£�
	*	value			|	description of value
	*	----------------|-------------------------------
	*	1				|	�ɹ�
	*	0				|	ʧ��
	*	@note 
	*		�����������HID�����豸�����֤�Ķ�������ID200��\n
	*	������ϸ˵������:
	*	value			|	description of value
	*	----------------|-------------------------------
	*	0				|	��ſ�
	*	1				|	�����ɹ�
	*	2				|	����ʧ�ܣ������·ſ�
	*	3				|	�����ɹ��������ָ��
	*	4				|	����ɹ�
	*	5				|	����ʧ�ܣ����ذ���ָ
	*	6				|	д���ɹ�
	*	7				|	д��ʧ��
	*/
	ZKINTERFACE int ZKAPI HIDVoice(int nVoice);

#ifdef __cplusplus
}
#endif


#endif