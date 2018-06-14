#ifndef HELPER_HPP
#define HELPER_HPP

#include <string>

namespace nSymbols
{
	const char SPACE    = ' ';
	const char END_LINE = '\n';
}

namespace nConstants
{
	const unsigned int NUMBER_FACES = 6;

	const int STRING_IS_ABSENT      = -1;
}

namespace exceptions
{
	class InvalidPathOrFile
	{
	public:
		explicit InvalidPathOrFile(const std::string& title) : mException(title) {};

		inline std::string getException() const { return mException; };
	private:
		std::string mException;
	};
}
#endif // !HELPER_HPP