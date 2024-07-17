#pragma once
class TimeMgr
{
	SINGLE(TimeMgr);
private:
	LARGE_INTEGER	curCount;	// ����ð�
	LARGE_INTEGER	prevCount;	// �����ð�
	LARGE_INTEGER	preQuency;	// ���� ī���Ͱ� �ʴ� ��� ����Ǿ��°� ����

	double			dDT;		// �� ������ ������ �ð� �� - �� �ð� �����ð� ���̸� �ý��� ���� ī���� ���ļ��� ������ ���
	double			dAcc;		// ���� ��� �ð� : 1�ʸ� �ʰ��ϸ� FPS����ϰ� �ʱ�ȭ
	UINT			iCallCount;	// UPDATE�� �Լ� ȣ�� �� 
	UINT			iFPS;		// ������ �ӵ� : 1�ʴ� UPDATE ȣ�� �� 

public:
	void			Init();
	void			Update();
	void			Render();
	double			GetDT() { return dDT; }
	double			GetfDT() { return (float)dDT; }


};

