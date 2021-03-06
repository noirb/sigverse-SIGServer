/* $Id: RecvText.h,v 1.1.1.1 2011-03-25 02:18:50 okamoto Exp $ */ 
#ifndef CommController_RecvText_h
#define CommController_RecvText_h

#include <string>

#include <sigverse/commonlib/Encode.h>
#include <sigverse/commonlib/comm/controller/Controller.h>


class RecvTextEvent : public ControllerEvent
{
private:
	std::string m_caller;
	std::string m_text;
	Encode      m_encode;
public:
	bool set(int packetNum, int seq, char *data, int n);
	const char * getCaller() { return m_caller.c_str(); }
	const char * getText()   { return m_text.c_str(); }
	Encode       getEncode() { return m_encode; }
};


#endif // CommController_RecvText_h
 

