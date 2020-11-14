#include "stdafx.h"
#include "MYMSMQ.h"
#include "agsMSMQ.h"

MYMSMQ::MYMSMQ()
{
	m_sLabel = "";
	m_sServer = ".";
	m_sPath = "queue_9528001";
	CreatePrivateMQ(m_sPath);
}
MYMSMQ::MYMSMQ(CString queue)
{
	m_sLabel = "";
	m_sServer = ".";
	m_sPath = queue;
	if (queue == "") {
		m_sPath = "queue_9528002";
	}
	CreatePrivateMQ(m_sPath);
}

MYMSMQ::~MYMSMQ()
{
}
bool MYMSMQ::CreatePrivateMQ(CString path)
{
	agsMSMQ mque;	
	//CWaitCursor wait;
	if (!mque.CreatePrivateQ(m_sServer, m_sPath, m_sLabel))
	{
		printf("%s\n",mque.getErrorMsg());
		return false;
	}

	printf("%s\n", "Create Private Queue succesfully");
	return true;
}
bool MYMSMQ::SendPriavateMQ(CString msg)
{
	agsMSMQ mque;	
	CWaitCursor wait;
	if (!mque.SendPrivateQ(m_sServer, m_sPath, "", msg))
	{
		printf("%s\n", mque.getErrorMsg());
		return false;
	}

	printf("%s\n", "Send Private Message succesfully");
	return true;
}
bool MYMSMQ::RecgvPriavateMQ(CString& message)
{
	agsMSMQ mque;
	int current;
	MQmsg msg;
	HRESULT hr;
	//CWaitCursor wait;//w---
	if (!mque.PrepareGetMessage(m_sServer, m_sPath, 1))
	{
		printf("%s\n", mque.getErrorMsg());
		return false;
	}
	msg = mque.getMessageQ();

	hr = mque.getMSMQmsg();
	msg = mque.getMessageQ();
	
	message=msg.msg;


	if (!mque.closeMSMQ())
	{
		printf("%s\n", mque.getErrorMsg());
		return false;
	}

	if (hr != 0)
	{
		printf("%s\n", "No message in Message Queue");
	}
	else
	{
		CString mseg;
		mseg.Format("Get message(s) from private queue successfully");
		printf("%s\n", mseg);
	}
	return true;
	
}
bool MYMSMQ::RecgvPriavateMQAll(vector<CString>& msglist)
{
	agsMSMQ mque;
	int current;
	MQmsg msg;
	HRESULT hr;	
	CWaitCursor wait;	
	if (!mque.PrepareGetMessage(m_sServer, m_sPath, 1))
	{
		printf("%s\n", mque.getErrorMsg());
		return false;
	}
	msg = mque.getMessageQ();
	do
	{
		hr = mque.getMSMQmsg();
		if (hr != 0) break;
		msg = mque.getMessageQ();	
		
		msglist.push_back(msg.msg);

	} while (hr == 0);

	if (!mque.closeMSMQ())
	{
		printf("%s\n", mque.getErrorMsg());
		return false;
	}

	if (mque.getTotalMessage() == 0)
	{
		printf("%s\n", "No message in Message Queue");
	}
	else
	{
		CString mseg;
		mseg.Format("Get %d message(s) from private queue successfully", mque.getTotalMessage());
		printf("%s\n", mseg);
	}
	return true;
}