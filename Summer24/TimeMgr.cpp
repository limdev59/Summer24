#include "pch.h"
#include "TimeMgr.h"
#include "CCore.h"

TimeMgr::TimeMgr() 
	: curCount()
	, prevCount{}
	, preQuency{}
	, dDT(0.)
	, dAcc(0.)
	, iCallCount(0)
{
}
TimeMgr::~TimeMgr() {
}

void TimeMgr::Init()
{
	QueryPerformanceCounter(&prevCount);
	QueryPerformanceFrequency(&preQuency);
}

void TimeMgr::Update()
{
	QueryPerformanceCounter(&curCount);
	dDT = (double)(curCount.QuadPart - prevCount.QuadPart) / (double)(preQuency.QuadPart);

	prevCount = curCount;
#ifdef  _DEBUG
	if (dDT > (1. / 60.f))
		dDT = (1. / 60.f);
#endif //  _DEBUG

	
}

void TimeMgr::Render()
{
	++iCallCount;

	dAcc += dDT;

	if (dAcc >= 1.) {
		iFPS = iCallCount;
		dAcc = 0.;
		iCallCount = 0;
		wchar_t szBuffer[255] = {};
		swprintf_s(szBuffer, L"FPS : %d, DT : %f", iFPS, dAcc);
		SetWindowText(CCore::Instance()->GetMainHandle(), szBuffer);
	}
}
