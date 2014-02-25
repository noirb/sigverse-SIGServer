/* $Id: SimCtrl.h,v 1.1.1.1 2011-03-25 02:18:50 okamoto Exp $ */ 
#ifndef SimCtrl_h
#define SimCtrl_h

#include "Encoder.h"

namespace CommData {

class SimCtrlRequest : public Encoder
{
	enum { BUFSIZE = COMM_DATA_HEADER_MAX_SIZE + sizeof(SimCtrlCmdType) + COMM_DATA_FOOTER_SIZE };
private:
	SimCtrlCmdType m_command;
	
public:
	SimCtrlRequest(SimCtrlCmdType c) : Encoder(COMM_REQUEST_SIM_CTRL, BUFSIZE), m_command(c) {;}
private:
	int packetNum() { return 1; }
	char *encode(int seq, int &);
};

} // namespace

typedef CommData::SimCtrlRequest CommRequestSimCtrlEncoder;

#endif // SimCtrl_h
 

