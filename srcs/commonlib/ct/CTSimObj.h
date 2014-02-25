/* $Id: CTSimObj.h,v 1.13 2011-09-22 06:39:25 okamoto Exp $ */
#ifndef CTSimObj_h
#define CTSimObj_h

#include "systemdef.h"
#include "ViewImage.h"
#include "ct/NSLookup.h"
#include "Service.h"

#include <string>
#include <vector>

/*
class Attribute;
class CTParts;
*/

class Text;
class RawSound;

class CTSimObj
{
	typedef std::string S;
public:
	typedef std::vector<std::string> EntityNameC;
private:
	SOCKET	m_sock;
	bool	m_close;
	NSLookup *m_ns;
	S	m_myname;
private:
	const char *myname() { return m_myname.c_str(); }
	NSLookup::Provider * lookupProvider(Service::Kind);
	bool	getAllObjectNames(EntityNameC &v);
public:
	CTSimObj(SOCKET sock, const char *myname) : m_sock(sock), m_close(false), m_ns(NULL),m_myname(myname) {}
	CTSimObj() : m_sock(-1), m_close(false), m_ns(NULL) {};
	~CTSimObj();
	bool connect(const char *hostname, int port, const char *agentName);

	//	Attribute * getAttr(const char *name);

	/*
	void setAttr(const char *name, bool);
	void setAttr(const char *name, int);
	void setAttr(const char *name, double);
	void setAttr(const char *name, const char *);

	CTParts *	getParts();
	*/


	void sendText(double t, const char *to,
			  const char *text);
	void sendText(double t, const char *to,
			  const char *text, double reachRadius);

	bool   detectEntities(EntityNameC &v, int id = 1);


	ViewImage * captureView(ColorBitType cbtype, ImageDataSize size, int id = 1);

	unsigned char distanceSensor(double start, double end, int id = 1);

	ViewImage *distanceSensorD(double start, double end, int id = 1, bool map = false);

	Text *		getText(RawSound &);

	void sendMessage(const char *to, int argc, char**argv);
	void broadcastMessage(int argc, char**arggv);

	// FIX20110401
	void sendSound(double t, const char *to, RawSound &sound);

	bool	getAllEntities(EntityNameC &v);

};

#endif // CTSimObj_h


