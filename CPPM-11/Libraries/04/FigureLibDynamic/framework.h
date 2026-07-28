#ifndef FRAMEWORK_H
#define FRAMEWORK_H

#ifdef FIGURELIBDYNAMIC_EXPORTS
#define FIGURE_API __declspec(dllexport)
#else
#define FIGURE_API __declspec(dllimport)
#endif // FIGURELIBDYNAMIC_EXPORTS

#endif // !FRAMEWORK_H

