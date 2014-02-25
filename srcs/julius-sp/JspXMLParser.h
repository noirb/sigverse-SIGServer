#ifndef _JSP_XML_PARSER_H_
#define _JSP_XML_PARSER_H_

#include <xercesc/sax/HandlerBase.hpp>
#include <xercesc/framework/XMLFormatter.hpp>
#include <xercesc/parsers/SAXParser.hpp>
#include <string>
#include <vector>

// begin(add)(FIX20101029)
#include <xercesc/util/TransService.hpp>
// end(add)

XERCES_CPP_NAMESPACE_USE

namespace Jsp {

	/////////////////////////////////////////////////////////
	//
	//	MemoryText
	//

	class MemoryText {
	public:
		// ----------------------------------------------------
		// ----------------------------------------------------
		MemoryText();

		// ----------------------------------------------------
		// ----------------------------------------------------
		~MemoryText();

		// ----------------------------------------------------
		// ----------------------------------------------------
		void clear();

		// ----------------------------------------------------
		// ----------------------------------------------------
		void addXMLBeginStatement();

		// ----------------------------------------------------
		///
		// ----------------------------------------------------
		void addLine(const char *line);

		// ----------------------------------------------------
		///
		///
		// ----------------------------------------------------
		bool loadFromFile(const char *xmlFile);

		// ----------------------------------------------------
		// ----------------------------------------------------
		void makeMemoryImage();

		// ----------------------------------------------------
		///
		// ----------------------------------------------------
		char *getTextPtr() { return m_textBuf; }

		// ----------------------------------------------------
		///
		// ----------------------------------------------------
		int getTextLength() { return m_textBuf ? strlen(m_textBuf) : 0; }

		// ----------------------------------------------------
		// ----------------------------------------------------
		void printText();

	private:
		std::vector<std::string> m_lines;
		char *m_textBuf;
		int m_textBufSize;

		// ----------------------------------------------------
		///
		///
		///
		///
		// ----------------------------------------------------
		int _countTotalTextSizeInByte();

		// ----------------------------------------------------
		// ----------------------------------------------------
		void _free();
	};

	/////////////////////////////////////////////////////////
	//
	//	XMLParser
	//

	class XMLParser {
	public:
		// ----------------------------------------------------
		// ----------------------------------------------------
		XMLParser();

		// ----------------------------------------------------
		// ----------------------------------------------------
		~XMLParser();

		// ----------------------------------------------------
		///
		///
		///
		// ----------------------------------------------------
		bool parse(const char *xmlFile, std::vector<std::string> &outTexts);

		// ----------------------------------------------------
		///
		///
		///
		// ----------------------------------------------------
		bool parse(Jsp::MemoryText &memText, std::vector<std::string> &outTexts);

	private:
		SAXParser *m_parser;
	};

	/////////////////////////////////////////////////////////
	//
	//	XMLParseHandler
	//
	///
	class XMLParseHandler : public HandlerBase, private XMLFormatTarget {
	public:
		// ----------------------------------------------------
		// ----------------------------------------------------
		XMLParseHandler(
			const char *const encodingName,
			const XMLFormatter::UnRepFlags unRepFlags);

		// ----------------------------------------------------
		// ----------------------------------------------------
		~XMLParseHandler();

		// ----------------------------------------------------
		/// @brief
		// ----------------------------------------------------
		void writeChars(
			const XMLByte *const toWrite,
			const unsigned int count,
			XMLFormatter *const) {}

		// ----------------------------------------------------
		// ----------------------------------------------------
		void setOutTexts(std::vector<std::string> *outTexts) {
			m_poutTexts = outTexts;
		}

		// ============================================================
		// ----------------------------------------------------
		///
		// ----------------------------------------------------
		void startDocument();

		// ----------------------------------------------------
		///
		// ----------------------------------------------------
		void startElement(const XMLCh *const name, AttributeList &attributes);

		// ----------------------------------------------------
		///
		// ----------------------------------------------------
		void endElement(const XMLCh *const name);

		// ----------------------------------------------------
		///
		// ----------------------------------------------------
		void endDocument();

		// ============================================================
		// ----------------------------------------------------
		///
		// ----------------------------------------------------
		void warning(const SAXParseException &excep);

		// ----------------------------------------------------
		///
		// ----------------------------------------------------
		void error(const SAXParseException &excep);

		// ----------------------------------------------------
		///
		// ----------------------------------------------------
		void fatalError(const SAXParseException &excep);

	private:
		XMLFormatter fFormatter;

		int m_indent;
		std::vector<std::string> *m_poutTexts;

		// begin(add)(FIX20101029)
		XMLTranscoder *fTranscoder;
		std::string transcode(const XMLCh* pxSrcString);
		// end(add)
	};
};

#endif

