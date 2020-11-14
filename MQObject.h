#pragma once
using namespace std;
#include "vector"
#include "afxwin.h"
class MQObject
{
public:
	MQObject();
	virtual ~MQObject();
	virtual bool CreatePrivateMQ(CString path) = 0;
	virtual bool SendPriavateMQ(CString msg) = 0;
	virtual bool RecgvPriavateMQAll(vector<CString>& msglist) = 0;
	virtual bool RecgvPriavateMQ(CString& message) = 0;
protected:
	
	CString	m_sLabel;
	CString	m_sPath;	
	CString	m_sServer;
};

