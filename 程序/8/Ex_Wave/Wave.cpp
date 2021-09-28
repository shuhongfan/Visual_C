#include "stdafx.h"
#include "Wave.h"

CWave::CWave()					// 在构造函数中添加一些初始代码
{
	m_bOpened = FALSE;			// 设备没有打开
	m_wDeviceID = 0;			// 设备号为0 
}

CWave::~CWave()					// 在析构函数中添加关闭设备代码
{
	Close();					// 关闭设备
}

BOOL CWave::Play(CWnd *pWnd)	// 在窗口中播放设备
{
	Stop();						// 停止播放设备，设备复位
	MCI_PLAY_PARMS playParms;	// 定义一个播放结构变量
	playParms.dwCallback=(DWORD)pWnd->m_hWnd;
								// 设置回调窗口句柄
	mciSendCommand (m_wDeviceID, MCI_SEEK, MCI_SEEK_TO_START, NULL);
								// 定位到设备的开始
	if (mciSendCommand (m_wDeviceID, MCI_PLAY, MCI_NOTIFY,
  						(DWORD)(LPVOID) &playParms))
	/* 播放设备并向回调窗口发送MCI_NOTIFY消息 */
		return FALSE;
	else
		return TRUE;
}

void CWave::Stop()					// 停止播放
{
	mciSendCommand (m_wDeviceID, MCI_STOP, NULL, NULL);
}

void CWave::Close()				// 关闭设备
{
	m_bOpened = FALSE;
	if (m_wDeviceID)	
	{
		mciSendCommand (m_wDeviceID, MCI_STOP, MCI_WAIT, NULL);
		mciSendCommand (m_wDeviceID, MCI_CLOSE, NULL, NULL);
	}
	m_wDeviceID = 0;
}

BOOL CWave::Open(CString waveFileName)	// 打开设备并调入音频波型文件
{
	if (m_bOpened) Close();					// 若设备打开，关闭它

	MCI_OPEN_PARMS openParms;
	openParms.lpstrDeviceType = "waveaudio";
	openParms.lpstrElementName = waveFileName;
	if (mciSendCommand (NULL, MCI_OPEN, 
		MCI_OPEN_ELEMENT | MCI_OPEN_TYPE|MCI_WAIT, 
		(DWORD)(LPVOID) &openParms))
		return FALSE;	
	// MCI_OPEN_ELEMENT指定音频波型文件保存在lpstrElementName中，
	// MCI_OPEN_TYPE指定设备类型保存在lpstrDeviceType中
	
	m_wDeviceID = openParms.wDeviceID;
	m_bOpened = TRUE;

	return TRUE;
}
