#ifndef MATH_CORE_SWIZZLE_SWIZZLE_HPP
#define MATH_CORE_SWIZZLE_SWIZZLE_HPP

#include <cstddef>
#include <type_traits>

namespace math {
namespace core {

#define MATH_CORE_SWIZZLE_ASSIGN_ERROR "swizzle on lhs of assignment cannot have repeat elements"

/**
 * @struct has_unique_elems
 * @tparam N Number of elements.
 * @tparam E1 Index of first element.
 * @tparam E2 Index of seconds element.
 * @tparam E3 Index of third element. Not required.
 * @tparam E4 Index of fourth element. Not required.
 */
template<std::size_t N, std::size_t E1, std::size_t E2, std::size_t E3=0, std::size_t E4=0>
struct swizzle_has_unique_elems : std::integral_constant<bool,
	E1 != E2 &&
	(N < 3 || (E1 != E3 && E2 != E3)) &&
	(N < 4 || (E1 != E4 && E2 != E4 && E3 != E4))> {};

/**
 * @class Swizzle
 * @tparam T Storage type.
 * @tparam N Storage size.
 */
template<typename T, std::size_t N>
class Swizzle {
protected:
	T values[N];
};

}
}

#endif