class CWave : public CObject
{
// �������������
public:
	CWave();
	virtual ~CWave();
// ����
public:
	BOOL 	Open(CString waveFileName);	// ����һ�������ļ������豸
	void 	Close();			// �ر��豸
	void 	Stop();				// ֹͣ����
	BOOL 	Play(CWnd *pWnd);	// ���Ų��򴰿�pWnd����MCI_NOTIFY��Ϣ
// ���ݳ�Ա
protected:
	WORD 	m_wDeviceID;		// ���ڱ����豸��ʶ
	BOOL 	m_bOpened;			// �豸�򿪱�־
};
