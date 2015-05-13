/*
 * Modified by Okamoto on 2011-03-31
 */

#ifndef Eval_h
#define Eval_h

#include <string>
#include <string.h>
#include <map>
#include <stdlib.h>

class Eval
{
public:
	class Exception
	{
	private:
		std::string m_eq;
	public:
		Exception(const char *eq) : m_eq(eq) {;}
		const char *equation() const { return m_eq.c_str(); }
	};
private:
	std::map<std::string, std::string> *m_dict;
public:
	Eval(std::map<std::string, std::string> *dict = 0) : m_dict(dict) {;}

	double eval(const char *);
	double operator()(const char *str) { return eval(str); }
};

#endif // Eval_h

