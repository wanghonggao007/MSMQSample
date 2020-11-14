#pragma once
#include "MQObject.h"
class MYMSMQ :
	public MQObject
{
public:
	MYMSMQ();
	MYMSMQ(CString queue);
	virtual ~MYMSMQ();
	virtual bool CreatePrivateMQ(CString path) ;
	virtual bool SendPriavateMQ(CString msg) ;
	virtual bool RecgvPriavateMQ(CString& message);
	virtual bool RecgvPriavateMQAll(vector<CString>& msglist) ;
};

