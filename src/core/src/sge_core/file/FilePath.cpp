#include "FilePath.h"

namespace sge {

String FilePath::getDir(StrView path) {
	auto* end = path.end(); // should be pointer 
	auto* begin = path.begin();

	if (end == nullptr) return String();
	auto* p = end - 1; // non 0 content end
	for (; p >= begin; p--) { 
		if (*p == '/' || *p == '\\') { // when detect first "/" / "\\"return to remove filename
			return String(begin, p);
		}
	}

	return String();
}

}