/* $Id: Result.cpp,v 1.1.1.1 2011-03-25 02:18:50 okamoto Exp $ */ 
#include "Result.h"
#include "binary.h"

bool ResultEvent::set(int packetNum, int seq, char *data, int n)
{
	char *p = data;
	m_result = BINARY_GET_DATA_S_INCR(p, CommDataType);
	char *msg = BINARY_GET_STRING_INCR(p);
	if (msg) {
		m_errmsg = msg;
	}
	BINARY_FREE_STRING(msg);
	return true;
}



