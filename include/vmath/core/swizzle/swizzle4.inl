#ifndef VMATH_CORE_SWIZZLE_SWIZZLE4_INL
#define VMATH_CORE_SWIZZLE_SWIZZLE4_INL

#include <vmath/core/swizzle/swizzle4.hpp>

#include <vmath/core/vector.hpp>

namespace vmath {
namespace core {

template<typename T, std::size_t N, std::size_t E1, std::size_t E2, std::size_t E3, std::size_t E4>
Swizzle4<T, N, E1, E2, E3, E4>::operator Vector<T, 4>() {
	return Vector<T, 4>(this->data[E1], this->data[E2], this->data[E3], this->data[E4]);
}

}
}

#endif
