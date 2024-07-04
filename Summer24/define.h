#include "pch.h"

#define SINGLE(type) public: \
				static type* Instance() \
				{\
				static type mgr;\
				return &mgr;\
				}\
				private:\
				type();\
				~type();\
