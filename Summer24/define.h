#include "pch.h"

#define SINGLE(type) public:\
					static type* Instance()\
					{\
					static type mgr;\
					return &mgr;\
					}\
					private:\
					type();\
					~type();

#define fDT TimeMgr::Instance()->GetfDT()
#define DT TimeMgr::Instance()->GetDT()