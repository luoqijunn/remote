#pragma once

#include "CTool.h"
#include "CtrlBase.h"

class CButton : public CtrlBase
{
public:
	CButton(int x = 0, int y = 0, int w = 0, int h = 0, const char* content = nullptr);
	~CButton();
	
};

