#include "CX3DParserUtil.h"
#include "CX3DParser.h"
#include <stdio.h>

std::string CX3DParserUtil::extractFileBaseName(const char *pathName)
{
	char buf[1024];
	int len;
	int i, iLastSlash, iPeriod;

	if (!pathName) return "";

	len = strlen(pathName);
	iLastSlash = -1;
	iPeriod = len;
	for (i=len-1; i>=0; i--)
	{
		char c = pathName[i];
		if ((iLastSlash == -1) && (c == '/')) iLastSlash = i;
		if ((iPeriod == len) && (c == '.')) iPeriod = i;
	}

	// Extraction target is from pathName[iLastSlash+1] to pathName[iPeriod-1]
	int nCopy = iPeriod - iLastSlash - 1;
#ifdef WIN32
	strncpy_s(buf, 1024, pathName+iLastSlash+1, nCopy);
#else
	strncpy(buf, pathName+iLastSlash+1, nCopy);
#endif
	buf[nCopy] = '\0';

	return buf;
}

