#ifndef MFFUNC_H
#define MFFUNC_H

/**
*	@file		mffunc.h
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
	*	@brief ���÷��������к�
	*	@param	:
	*	����˵�����±�
	*	name			|	type		|	param direction		|	description of param
	*	----------------|---------------|-----------------------|------------------------
	*	iPort			|	int			|	[in]				|	���ں�
	*	data			|	char*		|	[in]				|	�豸���к�(HEX,ex FFFFFFFFFFFFFFFF)
	*	cbdata			|	int			|	[in]				|	���кų���(16���ַ�)
	*	@return
	*	����ֵ˵�����£�
	*	value			|	description of value
	*	----------------|-------------------------------
	*	1				|	�ɹ�
	*	0				|	ʧ��
	*	@note 
	*		���ӿڽ������ڴ��������ܵ����֤�Ķ���(��ID180)
	*/
	ZKINTERFACE int ZKAPI  IC_SetDevNum(int iPort, char *data, int cbdata);

	/**
	*	@brief ��ȡ���������к�
	*	@param	:
	*	����˵�����±�
	*	name			|	type		|	param direction		|	description of param
	*	----------------|---------------|-----------------------|------------------------
	*	iPort			|	int			|	[in]				|	���ں�
	*	data			|	char*		|	[out]				|	�����豸���к�(HEX,ex FFFFFFFFFFFFFFFF)
	*	cbdata			|	int			|	[in]				|	����������(17����β0)
	*	@return
	*	����ֵ˵�����£�
	*	value			|	description of value
	*	----------------|-------------------------------
	*	1				|	�ɹ�
	*	0				|	ʧ��
	*	@note 
	*		���ӿڽ������ڴ��������ܵ����֤�Ķ���(��ID180)
	*/
	ZKINTERFACE int ZKAPI  IC_GetDevNum(int iPort, char *data, int cbdata);

	/**
	*	@brief ���÷��������к�
	*	@param	:
	*	����˵�����±�
	*	name			|	type		|	param direction		|	description of param
	*	----------------|---------------|-----------------------|------------------------
	*	iPort			|	int			|	[in]				|	���ں�
	*	data			|	char*		|	[out]				|	�豸�汾��(HEX,ex FFFFFFFFFFFF)
	*	cbdata			|	int			|	[in]				|	����������(13����β0)
	*	@return
	*	����ֵ˵�����£�
	*	value			|	description of value
	*	----------------|-------------------------------
	*	1				|	�ɹ�
	*	0				|	ʧ��
	*	@note 
	*		���ӿڽ������ڴ��������ܵ����֤�Ķ���(��ID180)
	*/
	ZKINTERFACE int ZKAPI  IC_GetDevVersion(int iPort, char *data, int cbdata);

	/**
	*	@brief д����
	*	@param	:
	*	����˵�����±�
	*	name			|	type		|	param direction		|	description of param
	*	----------------|---------------|-----------------------|------------------------
	*	iPort			|	int			|	[in]				|	���ں�
	*	keyMode			|	int			|	[in]				|	0,keyA,1KeyB
	*	sector			|	int			|	[in]				|	������(0~15),����16����
	*	idx				|	int			|	[in]				|	������(0~2),ÿ��������4�飬��������Ϊ���ƿ��ֹ��д
	*	key				|	char*		|	[in]				|	������Կ(ex,FFFFFFFFFFFF)
	*	data			|	char*		|	[in]				|	����(16�ֽ�,32��16�����ַ�)
	*	cbdata			|	int			|	[in]				|	���ݳ���,32���ַ�
	*	snr				|	unsigned int|	[out]				|	����IC��������
	*	@return
	*	����ֵ˵�����£�
	*	value			|	description of value
	*	----------------|-------------------------------
	*	1				|	�ɹ�
	*	0				|	ʧ��
	*	@note 
	*		���ӿڽ������ڴ��������ܵ����֤�Ķ���(��ID180)
	*/
	ZKINTERFACE int ZKAPI  IC_WriteData(int iPort, int keyMode, int sector, int idx, char *key, char *data, int cbdata, unsigned int *snr);

	/**
	*	@brief ������
	*	@param	:
	*	����˵�����±�
	*	name			|	type		|	param direction		|	description of param
	*	----------------|---------------|-----------------------|------------------------
	*	iPort			|	int			|	[in]				|	���ں�
	*	keyMode			|	int			|	[in]				|	0,keyA,1KeyB
	*	sector			|	int			|	[in]				|	������(0~15),����16����
	*	idx				|	int			|	[in]				|	������(0~2),ÿ��������4�飬��������Ϊ���ƿ��ֹ��д
	*	key				|	char*		|	[in]				|	������Կ(ex,FFFFFFFFFFFF)
	*	data			|	char*		|	[out]				|	����(16�ֽ�,32��16�����ַ�)
	*	cbdata			|	int			|	[in]				|	����������,33����β0
	*	snr				| unsigned int* |	[out]				|	����IC��������
	*	@return
	*	����ֵ˵�����£�
	*	value			|	description of value
	*	----------------|-------------------------------
	*	1				|	�ɹ�
	*	0				|	ʧ��
	*	@note 
	*		���ӿڽ������ڴ��������ܵ����֤�Ķ���(��ID180)
	*/
	ZKINTERFACE int ZKAPI  IC_ReadData(int iPort, int keyMode, int sector, int idx, char *key, char *data, int cbdata, unsigned int *snr);

	/**
	*	@brief ��IC��������
	*	@param	:
	*	����˵�����±�
	*	name			|	type		|	param direction		|	description of param
	*	----------------|---------------|-----------------------|------------------------
	*	iPort			|	int			|	[in]				|	���ں�
	*	snr				| unsigned int* |	[out]				|	IC��������
	*	@return
	*	����ֵ˵�����£�
	*	value			|	description of value
	*	----------------|-------------------------------
	*	1				|	�ɹ�
	*	0				|	ʧ��
	*	@note 
	*		���ӿڽ������ڴ��������ܵ����֤�Ķ���(��ID180)
	*/
	ZKINTERFACE int ZKAPI  IC_GetICSnr(int iPort, unsigned int *snr);

	/**
	*	@brief �����֤������
	*	@param	:
	*	����˵�����±�
	*	name			|	type		|	param direction		|	description of param
	*	----------------|---------------|-----------------------|------------------------
	*	iPort			|	int			|	[in]				|	���ں�
	*	data			|	char*		|	[out]				|	���֤������64bit��ex,FFFFFFFFFFFFFFFF��
	*	cbdata			|	int			|	[in]				|	���������ȣ�17����β0��
	*	@return
	*	����ֵ˵�����£�
	*	value			|	description of value
	*	----------------|-------------------------------
	*	1				|	�ɹ�
	*	0				|	ʧ��
	*	@note 
	*		���ӿڽ������ڴ��������ܵ����֤�Ķ���(��ID180)
	*/
	ZKINTERFACE int ZKAPI  IC_GetIDSnr(int iPort, char *data, int cbdata);

	/**
	*	@brief ��ȡDN��
	*	@param	:
	*	����˵�����±�
	*	name			|	type		|	param direction		|	description of param
	*	----------------|---------------|-----------------------|------------------------
	*	iPort			|	int			|	[in]				|	���ں�
	*	data			|	char*		|	[out]				|	DN��16Bytes��ex,FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF��
	*	cbdata			|	int			|	[in]				|	���������ȣ���С33Bytes����β0��
	*	@return
	*	����ֵ˵�����£�
	*	value			|	description of value
	*	----------------|-------------------------------
	*	1				|	�ɹ�
	*	0				|	ʧ��
	*	@note 
	*		
	*/
	ZKINTERFACE int ZKAPI  IC_GetIDDNCode(int iPort, char *data, int cbdata);


	/**
	*	@brief �޸�IC����������
	*	@param	:
	*	����˵�����±�
	*	name			|	type		|	param direction		|	description of param
	*	----------------|---------------|-----------------------|------------------------
	*	iPort			|	int			|	[in]				|	���ں�
	*	keyMode			|	int			|	[in]				|	0,keyA,1KeyB
	*	nSector			|	int			|	[in]				|	������(0~15),����16����
	*	oldKey			|	char*		|	[in]				|	ԭʼ����(ex:FFFFFFFFFFFF) 12bytes hexstring
	*	newKey			|	char*		|	[in]				|	������(ex:FFFFFFFFFFFF)	12bytes hexstring
	*	@return
	*	����ֵ˵�����£�
	*	value			|	description of value
	*	----------------|-------------------------------
	*	1				|	�ɹ�
	*	0				|	ʧ��
	*	@note 
	*		���ӿڽ������ڴ��������ܵ����֤�Ķ���(��ID180)
	*/
	ZKINTERFACE int ZKAPI  IC_ChangeSectorKey(int iPort, int keyMode, int nSector, char *oldKey, char *newKey);


	/**
	*	@brief �����п�����
	*	@param	:
	*	����˵�����±�
	*	name			|	type		|	param direction		|	description of param
	*	----------------|---------------|-----------------------|------------------------
	*	iPort			|	int			|	[in]				|	���ں�
	*	data			|	char*		|	[out]				|	���п�����
	*	cbdata			|	int			|	[in]				|	����������
	*	@return
	*	����ֵ˵�����£�
	*	value			|	description of value
	*	----------------|-------------------------------
	*	>0				|	���ų���
	*	0				|	ʧ��
	*	@note 
	*		���ӿڽ������ڴ��������ܵ����֤�Ķ���(����֧�����п������豸)
	*/
	ZKINTERFACE int ZKAPI  IC_GetBankCardNum(int iPort, char *data, int cbdata);

#ifdef __cplusplus
}
#endif

#endif