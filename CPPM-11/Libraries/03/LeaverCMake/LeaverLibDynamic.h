#ifndef LEAVERLIBDYNAMIC_H
#define LEAVERLIBDYNAMIC_H

#ifdef LEAVERLIBDYNAMIC_EXPORTS
#define LEAVERLIB_API __declspec(dllexport)
#else
#define LEAVERLIB_API __declspec(dllimport)
#endif // LEAVERLIBDYNAMIC_EXPORTS

#include <string>

namespace LeaverLibDynamic {
	class LEAVERLIB_API Leaver
	{
	public:
		static std::string leave(const std::string& str_value);
	};
}
#endif // !LEAVERLIBDYNAMIC_H
