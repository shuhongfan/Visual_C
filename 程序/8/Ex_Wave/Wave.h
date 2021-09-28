class CWave : public CObject
{
// 构造和析构函数
public:
	CWave();
	virtual ~CWave();
// 操作
public:
	BOOL 	Open(CString waveFileName);	// 调入一个波形文件并打开设备
	void 	Close();			// 关闭设备
	void 	Stop();				// 停止播放
	BOOL 	Play(CWnd *pWnd);	// 播放并向窗口pWnd发送MCI_NOTIFY消息
// 数据成员
protected:
	WORD 	m_wDeviceID;		// 用于保存设备标识
	BOOL 	m_bOpened;			// 设备打开标志
};
