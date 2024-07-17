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

enum class GROUP_TYPE {
	DEFAULT,
	PLAYER,
	MISSILE,
	MONSTER,

	END = 32,
};

enum class SCENE_TYPE {
	TOOL,
	START,
	STAGE_1,
	STAGE_2,

	END
};