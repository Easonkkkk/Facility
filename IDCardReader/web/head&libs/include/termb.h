#ifndef TERMB_H
#define TERMB_H

/**
*	@file		termb.h
*	@brief		���֤�Ķ������֤�Ķ��ӿں���
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
	*	@brief	�������֤�Ķ���
	*	@param	:
	*	����˵�����±�
	*	name			|	type		|	param direction		|	description of param
	*	----------------|---------------|-----------------------|------------------------
	*	iPort			|	int			|	[in]				|	�˿ںţ�˵�����±�
	*	@return
	*	����ֵ˵�����£�
	*	value			|	description of value
	*	----------------|-------------------------------
	*	>0				|	�ɹ����ض˿ں�
	*	0				|	ʧ��
	*	@note 
	*	�˿ں�˵�����£�
	*	value			|	description of value
	*	----------------|-------------------------------
	*	1~16			|	�����豸
	*	1001~1016		|	USB�豸
	*/
	ZKINTERFACE int ZKAPI InitComm(int Port);

	/**
	*	@brief	�Զ��������֤�Ķ������������֤�Ķ���
	*	@param	:
	*		��
	*	@return
	*	����ֵ˵�����£�
	*	value			|	description of value
	*	----------------|-------------------------------
	*	>0				|	�ɹ����ض˿ں�
	*	0				|	ʧ��
	*	@note	
	*/
	ZKINTERFACE int ZKAPI InitCommExt();



	/**
	*	@brief	�Ͽ������֤�Ķ�������
	*	@param	:
	*		��
	*	@return
	*	����ֵ˵�����£�
	*	value			|	description of value
	*	----------------|-------------------------------
	*	1				|	�ɹ�
	*	0				|	ʧ��
	*	@note 
	*/
	ZKINTERFACE int ZKAPI CloseComm();
	
	
	
	/**
	*	@brief	����֤�����������ڶ������Ϳ�Ƭ֮��ĺϷ����ȷ��
	*	@param	:
	*		��
	*	@return
	*	����ֵ˵�����£�
	*	value			|	description of value
	*	----------------|-------------------------------
	*	1				|	�ɹ�
	*	-1				|	Ѱ��ʧ��
	*	-2				|	ѡ��ʧ��
	*	0				|	��������
	*	@note 
	*		ǰ��������InitComm/InitCommExt ���óɹ�
	*/
	ZKINTERFACE int ZKAPI Authenticate();


	/**
	*	@brief	��������,��Ϣ�ļ��洢��dll������
	*	@param	:
	*	����˵�����±�
	*	name			|	type		|	param direction		|	description of param
	*	----------------|---------------|-----------------------|------------------------
	*	Active			|	int			|	[in]				|	���±�
	*	@return
	*	����ֵ˵�����£�
	*	value			|	description of value
	*	----------------|-------------------------------
	*	1				|	�ɹ�������֤��ȡ�ɹ���
	*	2				|	�ɹ�������֤��ȡ�ɹ���
	*	3				|   �ɹ����۰�̨��ס֤��ȡ�ɹ���
	*	-11				|	��Ч����
	*	-101			|	д���ļ�ʧ�ܣ�����֤���Ե��ýӿڻ�ȡ������Ϣ(��getName)
	*	0				|	��������
	*	@note 
	*		ǰ��������Authenticate ���óɹ�\n
	*	������ϸ˵������:
	*	value			|	description of value
	*	----------------|-------------------------------
	*	1				|	��������Ϣ���γ�������Ϣ�ļ�WZ.TXT����Ƭ�ļ�XP.WLT��ZP.BMP�������ָ����Ϣ�γ�ָ����Ϣ�ļ�FP.DAT
	*	2				|	ֻ��������Ϣ���γ�������Ϣ�ļ�WZ.TXT����Ƭ�ļ�XP.WLT
	*	3				|	������סַ��Ϣ���γ�����סַ�ļ�NEWADD.TXT
	*/
	ZKINTERFACE int ZKAPI Read_Content(int Active);


	/**
	*	@brief	��������,��Ϣ�ļ��洢��dll�����£�ͬRead_Content�����JNA�������⣩
	*	@param	:
	*	����˵�����±�
	*	name			|	type		|	param direction		|	description of param
	*	----------------|---------------|-----------------------|------------------------
	*	Active			|	int			|	[in]				|	���±�
	*	@return
	*	����ֵ˵�����£�
	*	value			|	description of value
	*	----------------|-------------------------------
	*	1				|	�ɹ�������֤��ȡ�ɹ���
	*	2				|	�ɹ�������֤��ȡ�ɹ���
	*	3				|   �ɹ����۰�̨��ס֤��ȡ�ɹ���
	*	-11				|	��Ч����
	*	-101			|	д���ļ�ʧ�ܣ����Ե��ýӿڻ�ȡ������Ϣ(��getName)
	*	0				|	��������
	*	@note 
	*		ǰ��������Authenticate ���óɹ�\n
	*	������ϸ˵������:
	*	value			|	description of value
	*	----------------|-------------------------------
	*	1				|	��������Ϣ���γ�������Ϣ�ļ�WZ.TXT����Ƭ�ļ�XP.WLT��ZP.BMP�������ָ����Ϣ�γ�ָ����Ϣ�ļ�FP.DAT
	*	2				|	ֻ��������Ϣ���γ�������Ϣ�ļ�WZ.TXT����Ƭ�ļ�XP.WLT
	*	3				|	������סַ��Ϣ���γ�����סַ�ļ�NEWADD.TXT
	*/
	ZKINTERFACE int ZKAPI ReadContent(int Active);


	/**
	*	@brief	��ȡSAMģ����
	*	@param	:
	*	����˵�����±�
	*	name			|	type		|	param direction		|	description of param
	*	----------------|---------------|-----------------------|------------------------
	*	SAMID			|	char*		|	[out]				|	SAMģ����
	*	@return
	*	����ֵ˵�����£�
	*	value			|	description of value
	*	----------------|-------------------------------
	*	1				|	�ɹ�
	*	0				|	ʧ��
	*	@note 
	*		ǰ��������InitComm/InitCommExt ���óɹ�
	*/
	ZKINTERFACE int ZKAPI GetSAMID(char *SAMID);

	/**
	*	@brief	��ȡSAMģ���ţ�10λ��ţ�
	*	@param	:
	*	����˵�����±�
	*	name			|	type		|	param direction		|	description of param
	*	----------------|---------------|-----------------------|------------------------
	*	SAMID			|	char*		|	[out]				|	SAMģ����
	*	@return
	*	����ֵ˵�����£�
	*	value			|	description of value
	*	----------------|-------------------------------
	*	1				|	�ɹ�
	*	0				|	ʧ��
	*	@note 
	*		ǰ��������InitComm/InitCommExt ���óɹ�
	*/
	ZKINTERFACE int ZKAPI GetSAMIDEx(char *SAMID);



	/**
	*	@brief	�������֤��Ƭ
	*	@param	:
	*	����˵�����±�
	*	name			|	type		|	param direction		|	description of param
	*	----------------|---------------|-----------------------|------------------------
	*	pszPath			|	char*		|	[in]				|	xp.wltͼƬ�ļ�ȫ·��
	*	@return
	*	����ֵ˵�����£�
	*	value			|	description of value
	*	----------------|-------------------------------
	*	1				|	�ɹ�
	*	0				|	ʧ��
	*	@note 
	*		ǰ��������Read_Content ���óɹ�
	*/
	ZKINTERFACE int ZKAPI GetBmpPhoto(const char* pszPath);

	/**
	*	@brief	�������֤��Ƭ
	*	@param	:
	*		��
	*	@return
	*	����ֵ˵�����£�
	*	value			|	description of value
	*	----------------|-------------------------------
	*	1				|	�ɹ�
	*	0				|	ʧ��
	*	@note 
	*		ǰ��������Read_Content ���óɹ�
	*/
	ZKINTERFACE int ZKAPI GetBmpPhotoExt();
	

	/**
	*	@brief	����Samģ��
	*	@param	:
	*		��
	*	@return
	*	����ֵ˵�����£�
	*	value			|	description of value
	*	----------------|-------------------------------
	*	1				|	�ɹ�
	*	0				|	ʧ��
	*	@note 
	*	ǰ��������InitComm/InitCommExt ���óɹ�
	*/
	ZKINTERFACE int ZKAPI Reset_SAM();

	/**
	*	@brief	��ȡSAMģ��״̬
	*	@param	:
	*		��
	*	@return
	*	����ֵ˵�����£�
	*	value			|	description of value
	*	----------------|-------------------------------
	*	1				|	״̬����
	*	0				|	״̬�쳣
	*	@note 
	*	ǰ��������InitComm/InitCommExt ���óɹ�
	*/
	ZKINTERFACE int ZKAPI GetSAMStatus();


	/**
	*	@brief	�������֤��Ϣ
	*	@param	:
	*	����˵�����±�
	*	name			|	type		|	param direction		|	description of param
	*	----------------|---------------|-----------------------|------------------------
	*	index			|	int			|	[in]				|	����
	*	value			|	char*		|	[out]				|	����ֵ
	*		��
	*	@return
	*	����ֵ˵�����£�
	*	value			|	description of value
	*	----------------|-------------------------------
	*	1				|	�ɹ�
	*	0				|	ʧ��
	*	@note 
	*	ǰ��������Read_Content ���óɹ�\n
	*	��ϸ����˵�����£�
	*	value			|	description of value
	*	----------------|-------------------------------
	*	index(0)		|	��ȡ����
	*	index(1)		|	��ȡ�Ա�
	*	index(2)		|	��ȡ����
	*	index(3)		|	��ȡ��������(YYYYMMDD)
	*	index(4)		|	��ȡ��ַ
	*	index(5)		|	��ȡ���֤��
	*	index(6)		|	ǩ������
	*	index(7)		|	��Ч����ʼ����(YYYYMMDD)
	*	index(8)		|	��Ч�ڽ�ֹ����(YYYYMMDD)
	*	index(101)		|	Ӣ����
	*	index(102)		|	������
	*	index(103)		|	ͨ��֤��
	*	index(104)		|	ǩ֤����
	*	index(105)		|	֤������
	*	@note 
	*		�����ֶ��Ƿ����֤��֧�֣��ο�getXXX˵��
	*/
	ZKINTERFACE int ZKAPI GetCardInfo(int index, char *value);



	/******
	*	@brief	���������ļ���ʱĿ¼
	*	@param	:
	*	����˵�����±�
	*	name			|	type		|	param direction		|	description of param
	*	----------------|---------------|-----------------------|------------------------
	*	path			|	char*		|	[in]				|	����ͼƬ��ʱĿ¼
	*	@return
	*		��
	*	@note 
	*		δ����Ĭ��Ϊ��dll����Ŀ¼
	*		����ΪNULLʱ�������汾���ļ���ͼƬ���ݿ��Ե��û�ȡBase64�ַ���
	*/
	ZKINTERFACE void ZKAPI SetTempDir(char *path);



	/**
	*	@brief	��ȡ�ļ�������ʱĿ¼
	*	@param	:
	*	����˵�����±�
	*	name			|	type		|	param direction		|	description of param
	*	----------------|---------------|-----------------------|------------------------
	*	path			|	char*		|	[out]				|	����ͼƬ��ʱĿ¼
	*	cbPath			|	int			|	[in]				|	���仺��������(����260Bytes)
	*	@return
	*		��
	*	@note 
	*		δ���÷��ص�ǰdll����Ŀ¼·��
	*/
	ZKINTERFACE void ZKAPI GetTempDir(char *path, int cbPath);


	/******
	*	@brief	����jpgͷ��ȫ·����
	*	@param	:
	*	����˵�����±�
	*	name			|	type		|	param direction		|	description of param
	*	----------------|---------------|-----------------------|------------------------
	*	path			|	char*		|	[in]				|	����jpgͼ���ļ�ȫ·����
	*	@return
	*		��
	*	@note 
	*		δ����Ĭ��Ϊ��dll����Ŀ¼��zp.jpg
	*/
	ZKINTERFACE void ZKAPI SetPhotoJPGPathName(char *path);



	/******
	*	@brief	��ȡjpgͷ��ȫ·����
	*	@param	:
	*	����˵�����±�
	*	name			|	type		|	param direction		|	description of param
	*	----------------|---------------|-----------------------|------------------------
	*	path			|	char*		|	[out]				|	����ͼƬjpg�ļ�ȫ·��
	*	cbPath			|	int			|	[in]				|	���仺��������(����260Bytes)
	*	@return
	*		��
	*	@note 
	*		δ���÷��ر�dll����Ŀ¼��zp.jpg��ȫ·��
	*/
	ZKINTERFACE void ZKAPI GetPhotoJPGPathName(char *path, int cbPath);
	



	//value

	/*
		���ƣ�getName
		��������ȡ����
		������
			data,����
			cbData,data��������С
		���أ�
			��
		ǰ�᣺Read_Content ���óɹ�
	*/

	/**
	*	@brief	��ȡ����
	*	@param	:
	*	����˵�����±�
	*	name			|	type		|	param direction		|	description of param
	*	----------------|---------------|-----------------------|------------------------
	*	path			|	char*		|	[out]				|	����ֵ
	*	cbPath			|	int			|	[in]				|	���仺��������(����64Bytes)
	*	@return
	*		��
	*	@note 
	*		ǰ�᣺Read_Content ���óɹ�	\r\n
	*		����֤������ʽӢ����/���������;�۰�̨��ס֤ͬ����֤
	*/
	ZKINTERFACE void ZKAPI getName(char *data, int cbData);


	/**
	*	@brief	��ȡ�Ա�
	*	@param	:
	*	����˵�����±�
	*	name			|	type		|	param direction		|	description of param
	*	----------------|---------------|-----------------------|------------------------
	*	path			|	char*		|	[out]				|	����ֵ
	*	cbPath			|	int			|	[in]				|	���仺��������(����64Bytes)
	*	@return
	*		��
	*	@note 
	*		ǰ�᣺Read_Content ���óɹ�	\r\n
	*		����֤���۰�̨��ס֤ͬ����֤
	*/
	ZKINTERFACE void ZKAPI getSex(char *data, int cbData);

	/**
	*	@brief	��ȡ�Ա����
	*	@param	:
	*		��
	*	@return
	*		�Ա����
	*	@note 
	*		ǰ�᣺Read_Content ���óɹ�	\r\n
	*		����֤���۰�̨��ס֤ͬ����֤
	*/
	ZKINTERFACE int	 ZKAPI getSexCode();

	/**
	*	@brief	��ȡ����
	*	@param	:
	*	����˵�����±�
	*	name			|	type		|	param direction		|	description of param
	*	----------------|---------------|-----------------------|------------------------
	*	path			|	char*		|	[out]				|	����ֵ
	*	cbPath			|	int			|	[in]				|	���仺��������(����64Bytes)
	*	@return
	*		��
	*	@note 
	*		ǰ�᣺Read_Content ���óɹ�	\r\n
	*		����֤:����/���ұ��룻�۰�̨��ס֤ͬ����֤
	*/
	ZKINTERFACE void  ZKAPI getNation(char *data, int cbData);

	/**
	*	@brief	��ȡ�������
	*	@param	:
	*		��
	*	@return
	*		�������
	*	@note 
	*		ǰ�᣺Read_Content ���óɹ�	\r\n
	*		����֤���۰�̨��ס֤�޴���
	*/
	ZKINTERFACE int ZKAPI getNationCode();

	/**
	*	@brief	��ȡ����(YYYYMMDD)
	*	@param	:
	*	����˵�����±�
	*	name			|	type		|	param direction		|	description of param
	*	----------------|---------------|-----------------------|------------------------
	*	path			|	char*		|	[out]				|	����ֵ
	*	cbPath			|	int			|	[in]				|	���仺��������(����64Bytes)
	*	@return
	*		��
	*	@note 
	*		ǰ�᣺Read_Content ���óɹ�	\r\n
	*		����֤���۰�̨��ס֤ͬ����֤
	*/
	ZKINTERFACE void ZKAPI getBirthdate(char *data, int cbData);

	/*
		���ƣ�getBirthYear
		��������ȡ������
		������
			��
		���أ�
			������
		ǰ�᣺Read_Content ���óɹ�
	*/
	ZKINTERFACE int ZKAPI getBirthYear();

	/*
		���ƣ�getBirthMon
		��������ȡ������
		������
			��
		���أ�
			������
		ǰ�᣺Read_Content ���óɹ�
	*/
	ZKINTERFACE int ZKAPI getBirthMon();

	/*
		���ƣ�getBirthDay
		��������ȡ������
		������
			��
		���أ�
			������
		ǰ�᣺Read_Content ���óɹ�
	*/
	ZKINTERFACE int ZKAPI getBirthDay();

	/**
	*	@brief	��ȡ��ַ
	*	@param	:
	*	����˵�����±�
	*	name			|	type		|	param direction		|	description of param
	*	----------------|---------------|-----------------------|------------------------
	*	path			|	char*		|	[out]				|	����ֵ
	*	cbPath			|	int			|	[in]				|	���仺��������(����64Bytes)
	*	@return
	*		��
	*	@note 
	*		ǰ�᣺Read_Content ���óɹ�	\r\n
	*		����֤�޵�ַ��۰�̨��ס֤ͬ����֤
	*/
	ZKINTERFACE void ZKAPI getAddress(char *data, int cbData);

	/**
	*	@brief	��ȡ���֤��
	*	@param	:
	*	����˵�����±�
	*	name			|	type		|	param direction		|	description of param
	*	----------------|---------------|-----------------------|------------------------
	*	path			|	char*		|	[out]				|	����ֵ
	*	cbPath			|	int			|	[in]				|	���仺��������(����64Bytes)
	*	@return
	*		��
	*	@note 
	*		ǰ�᣺Read_Content ���óɹ�		\r\n
	*		����֤/�۰�̨��ס֤֤����
	*/
	ZKINTERFACE void ZKAPI getIDNum(char *data, int cbData);

	/**
	*	@brief	��ȡǩ������
	*	@param	:
	*	����˵�����±�
	*	name			|	type		|	param direction		|	description of param
	*	----------------|---------------|-----------------------|------------------------
	*	path			|	char*		|	[out]				|	����ֵ
	*	cbPath			|	int			|	[in]				|	���仺��������(����64Bytes)
	*	@return
	*		��
	*	@note 
	*		ǰ�᣺Read_Content ���óɹ�		\r\n
	*		����֤Ϊǩ�����ش��룻�۰�̨��ס֤ͬ����֤
	*/
	ZKINTERFACE void ZKAPI getIssue(char *data, int cbData);

	/**
	*	@brief	��ȡ��Ч����ʼ����(YYYYMMDD)
	*	@param	:
	*	����˵�����±�
	*	name			|	type		|	param direction		|	description of param
	*	----------------|---------------|-----------------------|------------------------
	*	path			|	char*		|	[out]				|	����ֵ
	*	cbPath			|	int			|	[in]				|	���仺��������(����64Bytes)
	*	@return
	*		��
	*	@note 
	*		ǰ�᣺Read_Content ���óɹ�		\r\n
	*		����֤���۰�̨��ס֤ͬ����֤
	*/
	ZKINTERFACE void ZKAPI getEffectedDate(char *data, int cbData);

	/**
	*	@brief	��ȡ��Ч�ڽ�ֹ����(YYYYMMDD)
	*	@param	:
	*	����˵�����±�
	*	name			|	type		|	param direction		|	description of param
	*	----------------|---------------|-----------------------|------------------------
	*	path			|	char*		|	[out]				|	����ֵ
	*	cbPath			|	int			|	[in]				|	���仺��������(����64Bytes)
	*	@return
	*		��
	*	@note 
	*		ǰ�᣺Read_Content ���óɹ�		\r\n
	*		����֤���۰�̨��ס֤ͬ����֤
	*/
	ZKINTERFACE void ZKAPI getExpiredDate(char *data, int cbData);


	/**
	*	@brief	��ȡӢ������
	*	@param	:
	*	����˵�����±�
	*	name			|	type		|	param direction		|	description of param
	*	----------------|---------------|-----------------------|------------------------
	*	path			|	char*		|	[out]				|	����ֵ
	*	cbPath			|	int			|	[in]				|	���仺��������(����64Bytes)
	*	@return
	*		��
	*	@note 
	*		ǰ�᣺Read_Content ���óɹ�		\r\n
	*		����֤���д���
	*/
	ZKINTERFACE void ZKAPI getEnName(char *data, int cbData);

	/**
	*	@brief	��ȡ������
	*	@param	:
	*	����˵�����±�
	*	name			|	type		|	param direction		|	description of param
	*	----------------|---------------|-----------------------|------------------------
	*	path			|	char*		|	[out]				|	����ֵ
	*	cbPath			|	int			|	[in]				|	���仺��������(����64Bytes)
	*	@return
	*		��
	*	@note 
	*		ǰ�᣺Read_Content ���óɹ�		\r\n
	*		����֤���д���
	*/
	ZKINTERFACE void ZKAPI getCnName(char *data, int cbData);

	/**
	*	@brief	��ȡͨ��֤��
	*	@param	:
	*	����˵�����±�
	*	name			|	type		|	param direction		|	description of param
	*	----------------|---------------|-----------------------|------------------------
	*	path			|	char*		|	[out]				|	����ֵ
	*	cbPath			|	int			|	[in]				|	���仺��������(����64Bytes)
	*	@return
	*		��
	*	@note 
	*		ǰ�᣺Read_Content ���óɹ�		\r\n
	*		�۰�̨��ס֤���д���
	*/
	ZKINTERFACE void ZKAPI getPassNum(char *data, int cbData);


	/**
	*	@brief	��ȡǩ֤����
	*	@param	:
	*		��
	*	@return
	*		ǩ֤����
	*	@note 
	*		ǰ�᣺Read_Content ���óɹ�	\r\n
	*		�۰�̨��ס֤���д���
	*/
	ZKINTERFACE int ZKAPI getVisaTimes();


	/**
	*	@brief	��ȡBMPͷ��Base64����
	*	@param	:
	*	����˵�����±�
	*	name			|	type		|	param direction		|	description of param
	*	----------------|---------------|-----------------------|------------------------
	*	path			|	char*		|	[out]				|	����ֵ
	*	cbPath			|	int			|	[in]				|	���仺��������(����256*1024Bytes)
	*	@return
	*		��
	*	@note 
	*		ǰ�᣺GetBmpPhoto/GetBmpPhotoExt ���óɹ�	
	*/
	ZKINTERFACE void ZKAPI getBMPPhotoBase64(char *data, int cbData);

	/**
	*	@brief	��ȡJPGͷ��Base64����
	*	@param	:
	*	����˵�����±�
	*	name			|	type		|	param direction		|	description of param
	*	----------------|---------------|-----------------------|------------------------
	*	path			|	char*		|	[out]				|	����ֵ
	*	cbPath			|	int			|	[in]				|	���仺��������(����256*1024Bytes)
	*	@return
	*		��
	*	@note 
	*		ǰ�᣺GetBmpPhoto/GetBmpPhotoExt ���óɹ�	
	*/
	ZKINTERFACE void ZKAPI getJPGPhotoBase64(char *data, int cbData);


	/**
	*	@brief	��ȡָ������base64�����ַ���
	*	@param	:
	*	����˵�����±�
	*	name			|	type		|	param direction		|	description of param
	*	----------------|---------------|-----------------------|------------------------
	*	path			|	char*		|	[out]				|	����ֵ
	*	cbPath			|	int			|	[in]				|	���仺��������(����256*1024Bytes)
	*	@return
	*		��
	*	@note 
	*		ǰ�᣺Read_Content ���óɹ�	
	*/
	ZKINTERFACE void ZKAPI getFPDataBase64(char *data, int cbData);


	/**
	*	@brief	�����������֤������Ϣ
	*	@param	:
	*	����˵�����±�
	*	name			|	type		|	param direction		|	description of param
	*	----------------|---------------|-----------------------|------------------------
	*	pcCHMsg			|	char*		|	[out]				|	��Ԥ��������192�ֽڣ��ṹ��ο������ĵ�
	*	@return
	*		��
	*	@note 
	*		ǰ�᣺Read_Content����1
	*/
	ZKINTERFACE void ZKAPI DecodeIDBaseMsg(char * pcCHMsg);

	/**
	*	@brief	��������֤������Ϣ
	*	@param	:
	*	����˵�����±�
	*	name			|	type		|	param direction		|	description of param
	*	----------------|---------------|-----------------------|------------------------
	*	pcCHMsg			|	char*		|	[out]				|	��Ԥ��������152�ֽڣ��ṹ��ο������ĵ�
	*	@return
	*		��
	*	@note 
	*		ǰ�᣺Read_Content����2
	*/
	ZKINTERFACE void ZKAPI DecodeGCBaseMsg(char * pcCHMsg);


	/******
	*	@brief	��ȡ֤������
	*	@param	:
	*		��
	*	@return
	*	����ֵ˵�����£�
	*	value			|	description of value
	*	----------------|-------------------------------
	*	1				|	����֤
	*	2				|	����֤
	*	3				|   �۰�̨��ס֤
	*	@note 
	*	ǰ��������Read_Content ���óɹ�
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