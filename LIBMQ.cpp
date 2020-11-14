
#include "stdafx.h"
#include "LIBMQ.h"
//MYMSMQ g_mq;
extern "C" __declspec(dllexport) bool  __stdcall SendMQMsg(CStringA msg, int number)
{
	if (number==0) {
		MYMSMQ mq;
		mq.SendPriavateMQ(msg);
		return true;
	}
	if (number == 1) {
		MYMSMQ mq("");
		mq.SendPriavateMQ(msg);
		return true;
	}
}


extern "C" __declspec(dllexport) bool  __stdcall RecvMQMsg(CStringA& msg, int number)
{
	if (number == 0) {
		MYMSMQ mq;
		mq.RecgvPriavateMQ(msg);
	}
	if (number == 1) {
		MYMSMQ mq("");
		mq.RecgvPriavateMQ(msg);
	}
	return true;
}