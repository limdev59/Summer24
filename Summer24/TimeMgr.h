#pragma once
class TimeMgr
{
	SINGLE(TimeMgr);
private:
	LARGE_INTEGER	curCount;	// 현재시간
	LARGE_INTEGER	prevCount;	// 이전시간
	LARGE_INTEGER	preQuency;	// 성능 카운터가 초당 몇번 진행되었는가 저장

	double			dDT;		// 두 프레임 사이의 시간 값 - 현 시간 이전시간 차이를 시스템 성능 카운터 주파수로 나눠서 계산
	double			dAcc;		// 누적 경과 시간 : 1초를 초과하면 FPS계산하고 초기화
	UINT			iCallCount;	// UPDATE함 함수 호출 수 
	UINT			iFPS;		// 프레임 속도 : 1초당 UPDATE 호출 수 

public:
	void			Init();
	void			Update();
	void			Render();
	double			GetDT() { return dDT; }
	double			GetfDT() { return (float)dDT; }


};

