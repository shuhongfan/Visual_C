#include "stdafx.h"
#include "Wave.h"

CWave::CWave()					// �ڹ��캯�������һЩ��ʼ����
{
	m_bOpened = FALSE;			// �豸û�д�
	m_wDeviceID = 0;			// �豸��Ϊ0 
}

CWave::~CWave()					// ��������������ӹر��豸����
{
	Close();					// �ر��豸
}

BOOL CWave::Play(CWnd *pWnd)	// �ڴ����в����豸
{
	Stop();						// ֹͣ�����豸���豸��λ
	MCI_PLAY_PARMS playParms;	// ����һ�����Žṹ����
	playParms.dwCallback=(DWORD)pWnd->m_hWnd;
								// ���ûص����ھ��
	mciSendCommand (m_wDeviceID, MCI_SEEK, MCI_SEEK_TO_START, NULL);
								// ��λ���豸�Ŀ�ʼ
	if (mciSendCommand (m_wDeviceID, MCI_PLAY, MCI_NOTIFY,
  						(DWORD)(LPVOID) &playParms))
	/* �����豸����ص����ڷ���MCI_NOTIFY��Ϣ */
		return FALSE;
	else
		return TRUE;
}

void CWave::Stop()					// ֹͣ����
{
	mciSendCommand (m_wDeviceID, MCI_STOP, NULL, NULL);
}

void CWave::Close()				// �ر��豸
{
	m_bOpened = FALSE;
	if (m_wDeviceID)	
	{
		mciSendCommand (m_wDeviceID, MCI_STOP, MCI_WAIT, NULL);
		mciSendCommand (m_wDeviceID, MCI_CLOSE, NULL, NULL);
	}
	m_wDeviceID = 0;
}

BOOL CWave::Open(CString waveFileName)	// ���豸��������Ƶ�����ļ�
{
	if (m_bOpened) Close();					// ���豸�򿪣��ر���

	MCI_OPEN_PARMS openParms;
	openParms.lpstrDeviceType = "waveaudio";
	openParms.lpstrElementName = waveFileName;
	if (mciSendCommand (NULL, MCI_OPEN, 
		MCI_OPEN_ELEMENT | MCI_OPEN_TYPE|MCI_WAIT, 
		(DWORD)(LPVOID) &openParms))
		return FALSE;	
	// MCI_OPEN_ELEMENTָ����Ƶ�����ļ�������lpstrElementName�У�
	// MCI_OPEN_TYPEָ���豸���ͱ�����lpstrDeviceType��
	
	m_wDeviceID = openParms.wDeviceID;
	m_bOpened = TRUE;

	return TRUE;
}
