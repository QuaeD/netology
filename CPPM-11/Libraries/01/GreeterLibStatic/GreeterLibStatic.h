#ifndef GREETERLIBSTATIC_H
#define GREETERLIBSTATIC_H

#include <string>

namespace GreeterLibStatic {

	class Greeter {
	public:
		static std::string greet(const std::string& str_value);
	};
}

#endif // !GREETERLIBSTATIC_H
