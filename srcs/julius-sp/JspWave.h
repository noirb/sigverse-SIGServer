#ifndef _JSP_WAVE_H_
#define _JSP_WAVE_H_

namespace Jsp
{
	// ---------------------------------------------------
	// ---------------------------------------------------
	class Wave
	{
	public:
		// -----------------------------------------------
		// -----------------------------------------------
		Wave();

		// -----------------------------------------------
		// -----------------------------------------------
		~Wave();

		// -----------------------------------------------
		///
		// -----------------------------------------------
		bool loadFromFile(const char *waveFile);

		// -----------------------------------------------
		///
		// -----------------------------------------------
		char *getWaveDataPtr() { return m_pWaveData; }

		// -----------------------------------------------
		///
		// -----------------------------------------------
		int getWaveDataLen() { return m_dataLen; }

	private:
		char *m_pWaveData;
		int m_dataLen;

		void _free();
	};
};

#endif

