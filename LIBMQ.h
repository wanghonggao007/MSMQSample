#pragma once


#include "MYMSMQ.h"

extern "C" __declspec(dllexport) bool  __stdcall SendMQMsg(CString msg,int number);


extern "C" __declspec(dllexport) bool  __stdcall RecvMQMsg(CString& msg,int number);




