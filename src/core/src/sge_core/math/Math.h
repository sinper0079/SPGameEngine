#pragma once

namespace sge {
	// constexpr specifier declares that it is possible to evaluate the value of the function or variable at compile time.
namespace Math {
	template<class T> constexpr T ByteToK(const T& v) { return v / 1024; } 
	template<class T> constexpr T ByteToM(const T& v) { return v / (1024 * 1024); }
	template<class T> constexpr T ByteToG(const T& v) { return v / (1024 * 1024 * 1024); }

}

}