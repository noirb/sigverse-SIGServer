/* $Id: ControllerCommand.h,v 1.1.1.1 2011-03-25 02:18:50 okamoto Exp $ */ 
#ifdef DEPRECATED

#ifndef ControllerCommand_h
#define ControllerCommand_h

#include "Encoder.h"

class Command;

BEGIN_NS_COMMDATA();

class ControllerCommand : public Encoder
{
private:
	enum { BUFSIZE = 1024, };
private:
	Command & m_cmd;
public:
	ControllerCommand(Command &cmd) : Encoder(COMM_CONTROLLER_COMMAND, BUFSIZE), m_cmd(cmd) {;}
	int packetNum() { return 1; }
	char *encode(int seq, int &sz);
};

END_NS_COMMDATA();

typedef CommData::ControllerCommand ControllerCommandEncoder;


#endif // ControllerCommand_h
 
#endif // DEPRECATED
