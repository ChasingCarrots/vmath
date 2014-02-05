#ifndef MATH_CORE_SWIZZLE_SWIZZLE3_INL
#define MATH_CORE_SWIZZLE_SWIZZLE3_INL

#include "swizzle3.hpp"

#include "../vector.hpp"

using namespace math::core;

/**
 * Convert from a swizzle to a vector.
 * @return Converted vector.
 */
template<typename T, std::size_t N, std::size_t E1, std::size_t E2, std::size_t E3>
vector<T, 3> swizzle3<T, N, E1, E2, E3>::to_vector3(void) const {
	return vector<T, 3>(this->data[E1], this->data[E2], this->data[E3]);
}

/**
 * Implicityly convert from a swizzle to a vector.
 * @return Converted vector.
 */
template<typename T, std::size_t N, std::size_t E1, std::size_t E2, std::size_t E3>
swizzle3<T, N, E1, E2, E3>::operator vector<T, 3>(void) {
	return this->to_vector3();
}

/**
 * Set this swizzle (and the underlying vector) equal to a vector.
 * @param V vector to set equal to.
 * @return The modified vector.
 */
template<typename T, std::size_t N, std::size_t E1, std::size_t E2, std::size_t E3>
template<typename U, typename>
vector<T, 3>& swizzle3<T, N, E1, E2, E3>::operator=(const vector<T, 3>& V) {
	this->data[E1] = V.x;
	this->data[E2] = V.y;
	this->data[E3] = V.z;
	return *(vector<T, 3>*)this;
}

/**
 * Negate this swizzle.
 * @return The negated swizzle.
 */
template<typename T, std::size_t N, std::size_t E1, std::size_t E2, std::size_t E3>
vector<T, 3> swizzle3<T, N, E1, E2, E3>::operator-(void) const {
	return -this->to_vector3();
}

/**
 * Add a vector to this swizzle.
 * @param V vector to add.
 * @return The vector sum.
 */
template<typename T, std::size_t N, std::size_t E1, std::size_t E2, std::size_t E3>
vector<T, 3> swizzle3<T, N, E1, E2, E3>::operator+(const vector<T, 3>& V) const {
	return this->to_vector3() + V;
}

/**
 * Add a vector to this swizzle. Set this swizzle (and the underlying vector) to
 * the result.
 * @param V vector to add.
 * @return The modified vector.
 */
template<typename T, std::size_t N, std::size_t E1, std::size_t E2, std::size_t E3>
template<typename U, typename>
vector<T, 3>& swizzle3<T, N, E1, E2, E3>::operator+=(const vector<T, 3>& V) {
	return *this = *this + V;
}

/**
 * Add a vector to this swizzle.
 * @param V vector to add.
 * @return The vector difference.
 */
template<typename T, std::size_t N, std::size_t E1, std::size_t E2, std::size_t E3>
vector<T, 3> swizzle3<T, N, E1, E2, E3>::operator-(const vector<T, 3>& V) const {
	return this->to_vector3() - V;
}

/**
 * Subtract a vector from this swizzle. Set this swizzle (and the underlying
 * vector) to the result.
 * @param V vector to add.
 * @return The modified vector.
 */
template<typename T, std::size_t N, std::size_t E1, std::size_t E2, std::size_t E3>
template<typename U, typename>
vector<T, 3>& swizzle3<T, N, E1, E2, E3>::operator-=(const vector<T, 3>& V) {
	return *this = *this - V;
}

/**
 * Multiply this swizzle by a vector.
 * @param V vector to multiply by.
 * @return The vector product.
 */
template<typename T, std::size_t N, std::size_t E1, std::size_t E2, std::size_t E3>
vector<T, 3> swizzle3<T, N, E1, E2, E3>::operator*(const vector<T, 3>& V) const {
	return this->to_vector3() * V;
}

/**
 * Multiply this swizzle by a vector. Set this swizzle (and the underlying
 * vector) to the result.
 * @param V vector to multiply by.
 * @return The modified vector.
 */
template<typename T, std::size_t N, std::size_t E1, std::size_t E2, std::size_t E3>
template<typename U, typename>
vector<T, 3>& swizzle3<T, N, E1, E2, E3>::operator*=(const vector<T, 3>& V) {
	return *this = *this * V;
}

/**
 * Divide this swizzle be a vector.
 * @param V vector to divide by.
 * @return The vector quotient.
 */
template<typename T, std::size_t N, std::size_t E1, std::size_t E2, std::size_t E3>
vector<T, 3> swizzle3<T, N, E1, E2, E3>::operator/(const vector<T, 3>& V) const {
	return this->to_vector3() / V;
}

/**
 * Divide this swizzle by a vector. Set this swizzle (and the underlying vector)
 * to the result.
 * @param V vector to multiply by.
 * @return The modified vector (component-wise quotient).
 */
template<typename T, std::size_t N, std::size_t E1, std::size_t E2, std::size_t E3>
template<typename U, typename>
vector<T, 3>& swizzle3<T, N, E1, E2, E3>::operator/=(const vector<T, 3>& V) {
	return *this = *this / V;
}

/**
 * vector-scalar multiplication.
 * @param s Scalar to multiply by.
 * @return The vector-scalar product.
 */
template<typename T, std::size_t N, std::size_t E1, std::size_t E2, std::size_t E3>
vector<T, 3> swizzle3<T, N, E1, E2, E3>::operator*(const T& s) const {
	return this->to_vector3() * s;
}

/**
 * vector-scalar multiplication. Set this swizzle (and the underlying vector) to
 * the result.
 * @param s Scalar to multiply by.
 * @return The vector-scalar product.
 */
template<typename T, std::size_t N, std::size_t E1, std::size_t E2, std::size_t E3>
template<typename U, typename>
vector<T, 3>& swizzle3<T, N, E1, E2, E3>::operator*=(const T& s) {
	return *this = *this * s;
}

/**
 * vector-scalar division.
 * @param s Scalar to divide by.
 * @return The vector-scalar quotient.
 */
template<typename T, std::size_t N, std::size_t E1, std::size_t E2, std::size_t E3>
vector<T, 3> swizzle3<T, N, E1, E2, E3>::operator/(const T& s) const {
	return this->to_vector3() / s;
}

/**
 * vector-scalar division. Set this swizzle (and the underlying vector) to the
 * result.
 * @param s Scalar to divide by.
 * @return The vector-scalar quotient.
 */
template<typename T, std::size_t N, std::size_t E1, std::size_t E2, std::size_t E3>
template<typename U, typename>
vector<T, 3>& swizzle3<T, N, E1, E2, E3>::operator/=(const T& s) {
	return *this = *this / s;
}

/**
 * Check swizzle-vector equality.
 * @param V vector to check equality with.
 * @return True if they are equal, otherwise false.
 */
template<typename T, std::size_t N, std::size_t E1, std::size_t E2, std::size_t E3>
bool swizzle3<T, N, E1, E2, E3>::operator==(const vector<T, 3>& V) const {
	return this->vector3() == V;
}

/**
 * Check swizzle-vector inequality.
 * @param V vector to check inequality with.
 * @return False if they are equal, otherwise true.
 */
template<typename T, std::size_t N, std::size_t E1, std::size_t E2, std::size_t E3>
bool swizzle3<T, N, E1, E2, E3>::operator!=(const vector<T, 3>& V) const {
	return this->to_vector3() != V;
}

#endif
