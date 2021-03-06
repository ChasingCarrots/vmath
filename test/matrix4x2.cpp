#include <boost/test/test_case_template.hpp>
#include <boost/test/unit_test.hpp>

#include <array>
#include <stdexcept>
#include <vmath/core/matrix.hpp>
#include "type_lists.hpp"

BOOST_AUTO_TEST_SUITE(matrix4x2)

BOOST_AUTO_TEST_CASE_TEMPLATE(size, T, float_types) {
	BOOST_CHECK(sizeof(vmath::core::Matrix<T, 4, 2>) == 2 * 4 * sizeof(T));
}

BOOST_AUTO_TEST_CASE_TEMPLATE(create, T, float_types) {
	// default constructor
	vmath::core::Matrix<T, 4, 2> M_default;
	BOOST_CHECK_SMALL(M_default[0][0], static_cast<T>(1e-7));
	BOOST_CHECK_SMALL(M_default[0][1], static_cast<T>(1e-7));
	BOOST_CHECK_SMALL(M_default[0][2], static_cast<T>(1e-7));
	BOOST_CHECK_SMALL(M_default[0][3], static_cast<T>(1e-7));
	BOOST_CHECK_SMALL(M_default[1][0], static_cast<T>(1e-7));
	BOOST_CHECK_SMALL(M_default[1][1], static_cast<T>(1e-7));
	BOOST_CHECK_SMALL(M_default[1][2], static_cast<T>(1e-7));
	BOOST_CHECK_SMALL(M_default[1][3], static_cast<T>(1e-7));
	// parameterized constructor
	std::array<vmath::core::Vector<T, 4>, 2> data = {{
			vmath::core::Vector<T, 4>(static_cast<T>(1.0), static_cast<T>(2.0), static_cast<T>(3.0), static_cast<T>(4.0)),
			vmath::core::Vector<T, 4>(static_cast<T>(5.0), static_cast<T>(6.0), static_cast<T>(7.0), static_cast<T>(8.0))
		}};
	vmath::core::Matrix<T, 4, 2> M_param(data);
	BOOST_CHECK_CLOSE(M_param[0][0], static_cast<T>(1.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_param[0][1], static_cast<T>(2.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_param[0][2], static_cast<T>(3.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_param[0][3], static_cast<T>(4.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_param[1][0], static_cast<T>(5.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_param[1][1], static_cast<T>(6.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_param[1][2], static_cast<T>(7.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_param[1][3], static_cast<T>(8.0), 1e-4f);
	// parameterized constructor
	vmath::core::Vector<T, 4> col1(static_cast<T>(1.0), static_cast<T>(2.0), static_cast<T>(3.0), static_cast<T>(4.0));
	vmath::core::Vector<T, 4> col2(static_cast<T>(5.0), static_cast<T>(6.0), static_cast<T>(7.0), static_cast<T>(8.0));
	vmath::core::Matrix<T, 4, 2> M_param2(col1, col2);
	BOOST_CHECK_CLOSE(M_param2[0][0], static_cast<T>(1.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_param2[0][1], static_cast<T>(2.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_param2[0][2], static_cast<T>(3.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_param2[0][3], static_cast<T>(4.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_param2[1][0], static_cast<T>(5.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_param2[1][1], static_cast<T>(6.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_param2[1][2], static_cast<T>(7.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_param2[1][3], static_cast<T>(8.0), 1e-4f);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(copy, T, float_types) {
	vmath::core::Matrix<T, 4, 2> M;
	M[0][0] = static_cast<T>(1.0);
	M[0][1] = static_cast<T>(2.0);
	M[0][2] = static_cast<T>(3.0);
	M[0][3] = static_cast<T>(4.0);
	M[1][0] = static_cast<T>(5.0);
	M[1][1] = static_cast<T>(6.0);
	M[1][2] = static_cast<T>(7.0);
	M[1][3] = static_cast<T>(8.0);
	vmath::core::Matrix<T, 4, 2> M_copy(M);
	BOOST_CHECK_CLOSE(M_copy[0][0], static_cast<T>(1.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_copy[0][1], static_cast<T>(2.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_copy[0][2], static_cast<T>(3.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_copy[0][3], static_cast<T>(4.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_copy[1][0], static_cast<T>(5.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_copy[1][1], static_cast<T>(6.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_copy[1][2], static_cast<T>(7.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_copy[1][3], static_cast<T>(8.0), 1e-4f);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(move, T, float_types) {
	vmath::core::Matrix<T, 4, 2> M;
	M[0][0] = static_cast<T>(1.0);
	M[0][1] = static_cast<T>(2.0);
	M[0][2] = static_cast<T>(3.0);
	M[0][3] = static_cast<T>(4.0);
	M[1][0] = static_cast<T>(5.0);
	M[1][1] = static_cast<T>(6.0);
	M[1][2] = static_cast<T>(7.0);
	M[1][3] = static_cast<T>(8.0);
	vmath::core::Matrix<T, 4, 2> M_move(std::move(M));
	BOOST_CHECK_CLOSE(M_move[0][0], static_cast<T>(1.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_move[0][1], static_cast<T>(2.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_move[0][2], static_cast<T>(3.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_move[0][3], static_cast<T>(4.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_move[1][0], static_cast<T>(5.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_move[1][1], static_cast<T>(6.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_move[1][2], static_cast<T>(7.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_move[1][3], static_cast<T>(8.0), 1e-4f);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(members, T, float_types) {
	vmath::core::Matrix<T, 4, 2> M;
	M[0] = vmath::core::Vector<T, 4>(static_cast<T>(1.0), static_cast<T>(2.0), static_cast<T>(3.0), static_cast<T>(4.0));
	M[1] = vmath::core::Vector<T, 4>(static_cast<T>(5.0), static_cast<T>(6.0), static_cast<T>(7.0), static_cast<T>(8.0));
	BOOST_CHECK_CLOSE(M[0][0], static_cast<T>(1.0), 1e-4f);
	BOOST_CHECK_CLOSE(M[0][1], static_cast<T>(2.0), 1e-4f);
	BOOST_CHECK_CLOSE(M[0][2], static_cast<T>(3.0), 1e-4f);
	BOOST_CHECK_CLOSE(M[0][3], static_cast<T>(4.0), 1e-4f);
	BOOST_CHECK_CLOSE(M[1][0], static_cast<T>(5.0), 1e-4f);
	BOOST_CHECK_CLOSE(M[1][1], static_cast<T>(6.0), 1e-4f);
	BOOST_CHECK_CLOSE(M[1][2], static_cast<T>(7.0), 1e-4f);
	BOOST_CHECK_CLOSE(M[1][3], static_cast<T>(8.0), 1e-4f);
	// invalid index
	BOOST_CHECK_THROW(M[2], std::out_of_range);
	BOOST_CHECK_THROW((M[2] = vmath::core::Vector<T, 4>()), std::out_of_range);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(assign_op, T, float_types) {
	vmath::core::Matrix<T, 4, 2> M;
	M[0][0] = static_cast<T>(1.0);
	M[0][1] = static_cast<T>(2.0);
	M[0][2] = static_cast<T>(3.0);
	M[0][3] = static_cast<T>(4.0);
	M[1][0] = static_cast<T>(5.0);
	M[1][1] = static_cast<T>(6.0);
	M[1][2] = static_cast<T>(7.0);
	M[1][3] = static_cast<T>(8.0);
	vmath::core::Matrix<T, 4, 2> M_assign;
	M_assign = M;
	BOOST_CHECK_CLOSE(M_assign[0][0], static_cast<T>(1.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_assign[0][1], static_cast<T>(2.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_assign[0][2], static_cast<T>(3.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_assign[0][3], static_cast<T>(4.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_assign[1][0], static_cast<T>(5.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_assign[1][1], static_cast<T>(6.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_assign[1][2], static_cast<T>(7.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_assign[1][3], static_cast<T>(8.0), 1e-4f);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(negate_op, T, float_types) {
	vmath::core::Matrix<T, 4, 2> M;
	M[0][0] = static_cast<T>(1.0);
	M[0][1] = static_cast<T>(2.0);
	M[0][2] = static_cast<T>(3.0);
	M[0][3] = static_cast<T>(4.0);
	M[1][0] = static_cast<T>(5.0);
	M[1][1] = static_cast<T>(6.0);
	M[1][2] = static_cast<T>(7.0);
	M[1][3] = static_cast<T>(8.0);
	vmath::core::Matrix<T, 4, 2> M_neg;
	M_neg = -M;
	BOOST_CHECK_CLOSE(M_neg[0][0], static_cast<T>(-1.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_neg[0][1], static_cast<T>(-2.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_neg[0][2], static_cast<T>(-3.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_neg[0][3], static_cast<T>(-4.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_neg[1][0], static_cast<T>(-5.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_neg[1][1], static_cast<T>(-6.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_neg[1][2], static_cast<T>(-7.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_neg[1][3], static_cast<T>(-8.0), 1e-4f);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(matrix_add_op, T, float_types) {
	vmath::core::Matrix<T, 4, 2> M1;
	M1[0][0] = static_cast<T>(1.0);
	M1[0][1] = static_cast<T>(2.0);
	M1[0][2] = static_cast<T>(3.0);
	M1[0][3] = static_cast<T>(4.0);
	M1[1][0] = static_cast<T>(5.0);
	M1[1][1] = static_cast<T>(6.0);
	M1[1][2] = static_cast<T>(7.0);
	M1[1][3] = static_cast<T>(8.0);
	vmath::core::Matrix<T, 4, 2> M2;
	M2[0][0] = static_cast<T>(8.0);
	M2[0][1] = static_cast<T>(7.0);
	M2[0][2] = static_cast<T>(6.0);
	M2[0][3] = static_cast<T>(5.0);
	M2[1][0] = static_cast<T>(4.0);
	M2[1][1] = static_cast<T>(3.0);
	M2[1][2] = static_cast<T>(2.0);
	M2[1][3] = static_cast<T>(1.0);
	vmath::core::Matrix<T, 4, 2> M_add;
	M_add = M1 + M2;
	BOOST_CHECK_CLOSE(M_add[0][0], static_cast<T>(9.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_add[0][1], static_cast<T>(9.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_add[0][2], static_cast<T>(9.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_add[0][3], static_cast<T>(9.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_add[1][0], static_cast<T>(9.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_add[1][1], static_cast<T>(9.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_add[1][2], static_cast<T>(9.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_add[1][3], static_cast<T>(9.0), 1e-4f);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(matrix_add_eq_op, T, float_types) {
	vmath::core::Matrix<T, 4, 2> M1;
	M1[0][0] = static_cast<T>(1.0);
	M1[0][1] = static_cast<T>(2.0);
	M1[0][2] = static_cast<T>(3.0);
	M1[0][3] = static_cast<T>(4.0);
	M1[1][0] = static_cast<T>(5.0);
	M1[1][1] = static_cast<T>(6.0);
	M1[1][2] = static_cast<T>(7.0);
	M1[1][3] = static_cast<T>(8.0);
	vmath::core::Matrix<T, 4, 2> M2;
	M2[0][0] = static_cast<T>(8.0);
	M2[0][1] = static_cast<T>(7.0);
	M2[0][2] = static_cast<T>(6.0);
	M2[0][3] = static_cast<T>(5.0);
	M2[1][0] = static_cast<T>(4.0);
	M2[1][1] = static_cast<T>(3.0);
	M2[1][2] = static_cast<T>(2.0);
	M2[1][3] = static_cast<T>(1.0);
	vmath::core::Matrix<T, 4, 2> M_add = M1;
	M_add += M2;
	BOOST_CHECK_CLOSE(M_add[0][0], static_cast<T>(9.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_add[0][1], static_cast<T>(9.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_add[0][2], static_cast<T>(9.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_add[0][3], static_cast<T>(9.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_add[1][0], static_cast<T>(9.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_add[1][1], static_cast<T>(9.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_add[1][2], static_cast<T>(9.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_add[1][3], static_cast<T>(9.0), 1e-4f);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(matrix_sub_op, T, float_types) {
	vmath::core::Matrix<T, 4, 2> M1;
	M1[0][0] = static_cast<T>(1.0);
	M1[0][1] = static_cast<T>(2.0);
	M1[0][2] = static_cast<T>(3.0);
	M1[0][3] = static_cast<T>(4.0);
	M1[1][0] = static_cast<T>(5.0);
	M1[1][1] = static_cast<T>(6.0);
	M1[1][2] = static_cast<T>(7.0);
	M1[1][3] = static_cast<T>(8.0);
	vmath::core::Matrix<T, 4, 2> M2;
	M2[0][0] = static_cast<T>(8.0);
	M2[0][1] = static_cast<T>(7.0);
	M2[0][2] = static_cast<T>(6.0);
	M2[0][3] = static_cast<T>(5.0);
	M2[1][0] = static_cast<T>(4.0);
	M2[1][1] = static_cast<T>(3.0);
	M2[1][2] = static_cast<T>(2.0);
	M2[1][3] = static_cast<T>(1.0);
	vmath::core::Matrix<T, 4, 2> M_sub;
	M_sub = M1 - M2;
	BOOST_CHECK_CLOSE(M_sub[0][0], static_cast<T>(-7.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_sub[0][1], static_cast<T>(-5.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_sub[0][2], static_cast<T>(-3.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_sub[0][3], static_cast<T>(-1.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_sub[1][0], static_cast<T>(1.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_sub[1][1], static_cast<T>(3.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_sub[1][2], static_cast<T>(5.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_sub[1][3], static_cast<T>(7.0), 1e-4f);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(matrix_sub_eq_op, T, float_types) {
	vmath::core::Matrix<T, 4, 2> M1;
	M1[0][0] = static_cast<T>(1.0);
	M1[0][1] = static_cast<T>(2.0);
	M1[0][2] = static_cast<T>(3.0);
	M1[0][3] = static_cast<T>(4.0);
	M1[1][0] = static_cast<T>(5.0);
	M1[1][1] = static_cast<T>(6.0);
	M1[1][2] = static_cast<T>(7.0);
	M1[1][3] = static_cast<T>(8.0);
	vmath::core::Matrix<T, 4, 2> M2;
	M2[0][0] = static_cast<T>(8.0);
	M2[0][1] = static_cast<T>(7.0);
	M2[0][2] = static_cast<T>(6.0);
	M2[0][3] = static_cast<T>(5.0);
	M2[1][0] = static_cast<T>(4.0);
	M2[1][1] = static_cast<T>(3.0);
	M2[1][2] = static_cast<T>(2.0);
	M2[1][3] = static_cast<T>(1.0);
	vmath::core::Matrix<T, 4, 2> M_sub = M1;
	M_sub -= M2;
	BOOST_CHECK_CLOSE(M_sub[0][0], static_cast<T>(-7.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_sub[0][1], static_cast<T>(-5.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_sub[0][2], static_cast<T>(-3.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_sub[0][3], static_cast<T>(-1.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_sub[1][0], static_cast<T>(1.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_sub[1][1], static_cast<T>(3.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_sub[1][2], static_cast<T>(5.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_sub[1][3], static_cast<T>(7.0), 1e-4f);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(matrix_mult_op, T, float_types) {
	vmath::core::Matrix<T, 4, 2> M;
	M[0][0] = static_cast<T>(1.0);
	M[0][1] = static_cast<T>(2.0);
	M[0][2] = static_cast<T>(3.0);
	M[0][3] = static_cast<T>(4.0);
	M[1][0] = static_cast<T>(5.0);
	M[1][1] = static_cast<T>(6.0);
	M[1][2] = static_cast<T>(7.0);
	M[1][3] = static_cast<T>(8.0);
	vmath::core::Matrix<T, 2> M_2x2;
	M_2x2[0][0] = static_cast<T>(1.0);
	M_2x2[0][1] = static_cast<T>(2.0);
	M_2x2[1][0] = static_cast<T>(3.0);
	M_2x2[1][1] = static_cast<T>(4.0);
	vmath::core::Matrix<T, 2, 3> M_2x3;
	M_2x3[0][0] = static_cast<T>(1.0);
	M_2x3[0][1] = static_cast<T>(2.0);
	M_2x3[1][0] = static_cast<T>(3.0);
	M_2x3[1][1] = static_cast<T>(4.0);
	M_2x3[2][0] = static_cast<T>(5.0);
	M_2x3[2][1] = static_cast<T>(6.0);
	vmath::core::Matrix<T, 2, 4> M_2x4;
	M_2x4[0][0] = static_cast<T>(1.0);
	M_2x4[0][1] = static_cast<T>(2.0);
	M_2x4[1][0] = static_cast<T>(3.0);
	M_2x4[1][1] = static_cast<T>(4.0);
	M_2x4[2][0] = static_cast<T>(5.0);
	M_2x4[2][1] = static_cast<T>(6.0);
	M_2x4[3][0] = static_cast<T>(7.0);
	M_2x4[3][1] = static_cast<T>(8.0);
	vmath::core::Matrix<T, 4, 2> M_sum4x2;
	M_sum4x2 = M * M_2x2;
	BOOST_CHECK_CLOSE(M_sum4x2[0][0], static_cast<T>(11.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_sum4x2[0][1], static_cast<T>(14.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_sum4x2[0][2], static_cast<T>(17.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_sum4x2[0][3], static_cast<T>(20.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_sum4x2[1][0], static_cast<T>(23.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_sum4x2[1][1], static_cast<T>(30.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_sum4x2[1][2], static_cast<T>(37.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_sum4x2[1][3], static_cast<T>(44.0), 1e-4f);
	vmath::core::Matrix<T, 4, 3> M_sum4x3;
	M_sum4x3 = M * M_2x3;
	BOOST_CHECK_CLOSE(M_sum4x3[0][0], static_cast<T>(11.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_sum4x3[0][1], static_cast<T>(14.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_sum4x3[0][2], static_cast<T>(17.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_sum4x3[0][3], static_cast<T>(20.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_sum4x3[1][0], static_cast<T>(23.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_sum4x3[1][1], static_cast<T>(30.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_sum4x3[1][2], static_cast<T>(37.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_sum4x3[1][3], static_cast<T>(44.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_sum4x3[2][0], static_cast<T>(35.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_sum4x3[2][1], static_cast<T>(46.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_sum4x3[2][2], static_cast<T>(57.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_sum4x3[2][3], static_cast<T>(68.0), 1e-4f);
	vmath::core::Matrix<T, 4> M_sum4x4;
	M_sum4x4 = M * M_2x4;
	BOOST_CHECK_CLOSE(M_sum4x4[0][0], static_cast<T>(11.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_sum4x4[0][1], static_cast<T>(14.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_sum4x4[0][2], static_cast<T>(17.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_sum4x4[0][3], static_cast<T>(20.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_sum4x4[1][0], static_cast<T>(23.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_sum4x4[1][1], static_cast<T>(30.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_sum4x4[1][2], static_cast<T>(37.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_sum4x4[1][3], static_cast<T>(44.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_sum4x4[2][0], static_cast<T>(35.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_sum4x4[2][1], static_cast<T>(46.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_sum4x4[2][2], static_cast<T>(57.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_sum4x4[2][3], static_cast<T>(68.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_sum4x4[3][0], static_cast<T>(47.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_sum4x4[3][1], static_cast<T>(62.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_sum4x4[3][2], static_cast<T>(77.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_sum4x4[3][3], static_cast<T>(92.0), 1e-4f);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(scalar_mult_op, T, float_types) {
	vmath::core::Matrix<T, 4, 2> M;
	M[0][0] = static_cast<T>(1.0);
	M[0][1] = static_cast<T>(2.0);
	M[0][2] = static_cast<T>(3.0);
	M[0][3] = static_cast<T>(4.0);
	M[1][0] = static_cast<T>(5.0);
	M[1][1] = static_cast<T>(6.0);
	M[1][2] = static_cast<T>(7.0);
	M[1][3] = static_cast<T>(8.0);
	T s = static_cast<T>(2.0);
	vmath::core::Matrix<T, 4, 2> M_mult;
	M_mult = M * s;
	BOOST_CHECK_CLOSE(M_mult[0][0], static_cast<T>(2.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_mult[0][1], static_cast<T>(4.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_mult[0][2], static_cast<T>(6.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_mult[0][3], static_cast<T>(8.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_mult[1][0], static_cast<T>(10.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_mult[1][1], static_cast<T>(12.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_mult[1][2], static_cast<T>(14.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_mult[1][3], static_cast<T>(16.0), 1e-4f);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(scalar_mult_eq_op, T, float_types) {
	vmath::core::Matrix<T, 4, 2> M;
	M[0][0] = static_cast<T>(1.0);
	M[0][1] = static_cast<T>(2.0);
	M[0][2] = static_cast<T>(3.0);
	M[0][3] = static_cast<T>(4.0);
	M[1][0] = static_cast<T>(5.0);
	M[1][1] = static_cast<T>(6.0);
	M[1][2] = static_cast<T>(7.0);
	M[1][3] = static_cast<T>(8.0);
	T s = static_cast<T>(2.0);
	vmath::core::Matrix<T, 4, 2> M_mult = M;
	M_mult *= s;
	BOOST_CHECK_CLOSE(M_mult[0][0], static_cast<T>(2.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_mult[0][1], static_cast<T>(4.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_mult[0][2], static_cast<T>(6.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_mult[0][3], static_cast<T>(8.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_mult[1][0], static_cast<T>(10.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_mult[1][1], static_cast<T>(12.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_mult[1][2], static_cast<T>(14.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_mult[1][3], static_cast<T>(16.0), 1e-4f);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(scalar_div_op, T, float_types) {
	vmath::core::Matrix<T, 4, 2> M;
	M[0][0] = static_cast<T>(2.0);
	M[0][1] = static_cast<T>(4.0);
	M[0][2] = static_cast<T>(6.0);
	M[0][3] = static_cast<T>(8.0);
	M[1][0] = static_cast<T>(10.0);
	M[1][1] = static_cast<T>(12.0);
	M[1][2] = static_cast<T>(14.0);
	M[1][3] = static_cast<T>(16.0);
	T s = static_cast<T>(2.0);
	vmath::core::Matrix<T, 4, 2> M_div;
	M_div = M / s;
	BOOST_CHECK_CLOSE(M_div[0][0], static_cast<T>(1.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_div[0][1], static_cast<T>(2.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_div[0][2], static_cast<T>(3.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_div[0][3], static_cast<T>(4.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_div[1][0], static_cast<T>(5.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_div[1][1], static_cast<T>(6.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_div[1][2], static_cast<T>(7.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_div[1][3], static_cast<T>(8.0), 1e-4f);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(scalar_div_eq_op, T, float_types) {
	vmath::core::Matrix<T, 4, 2> M;
	M[0][0] = static_cast<T>(2.0);
	M[0][1] = static_cast<T>(4.0);
	M[0][2] = static_cast<T>(6.0);
	M[0][3] = static_cast<T>(8.0);
	M[1][0] = static_cast<T>(10.0);
	M[1][1] = static_cast<T>(12.0);
	M[1][2] = static_cast<T>(14.0);
	M[1][3] = static_cast<T>(16.0);
	T s = static_cast<T>(2.0);
	vmath::core::Matrix<T, 4, 2> M_div = M;
	M_div /= s;
	BOOST_CHECK_CLOSE(M_div[0][0], 1.0f, static_cast<T>(1e-4));
	BOOST_CHECK_CLOSE(M_div[0][1], 2.0f, static_cast<T>(1e-4));
	BOOST_CHECK_CLOSE(M_div[0][2], 3.0f, static_cast<T>(1e-4));
	BOOST_CHECK_CLOSE(M_div[0][3], 4.0f, static_cast<T>(1e-4));
	BOOST_CHECK_CLOSE(M_div[1][0], 5.0f, static_cast<T>(1e-4));
	BOOST_CHECK_CLOSE(M_div[1][1], 6.0f, static_cast<T>(1e-4));
	BOOST_CHECK_CLOSE(M_div[1][2], 7.0f, static_cast<T>(1e-4));
	BOOST_CHECK_CLOSE(M_div[1][3], 8.0f, static_cast<T>(1e-4));
}

BOOST_AUTO_TEST_CASE_TEMPLATE(transpose, T, float_types) {
	vmath::core::Matrix<T, 4, 2> M;
	M[0][0] = static_cast<T>(1.0);
	M[0][1] = static_cast<T>(2.0);
	M[0][2] = static_cast<T>(3.0);
	M[0][3] = static_cast<T>(4.0);
	M[1][0] = static_cast<T>(5.0);
	M[1][1] = static_cast<T>(6.0);
	M[1][2] = static_cast<T>(7.0);
	M[1][3] = static_cast<T>(8.0);
	vmath::core::Matrix<T, 2, 4> M_trans;
	M_trans = M.transpose();
	BOOST_CHECK_CLOSE(M_trans[0][0], static_cast<T>(1.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_trans[0][1], static_cast<T>(5.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_trans[1][0], static_cast<T>(2.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_trans[1][1], static_cast<T>(6.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_trans[2][0], static_cast<T>(3.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_trans[2][1], static_cast<T>(7.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_trans[3][0], static_cast<T>(4.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_trans[3][1], static_cast<T>(8.0), 1e-4f);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(equals, T, float_types) {
	vmath::core::Matrix<T, 4, 2> M1;
	M1[0][0] = static_cast<T>(1.0);
	M1[0][1] = static_cast<T>(2.0);
	M1[0][2] = static_cast<T>(3.0);
	M1[0][3] = static_cast<T>(4.0);
	M1[1][0] = static_cast<T>(5.0);
	M1[1][1] = static_cast<T>(6.0);
	M1[1][2] = static_cast<T>(7.0);
	M1[1][3] = static_cast<T>(8.0);
	vmath::core::Matrix<T, 4, 2> M2;
	M2[0][0] = static_cast<T>(1.0);
	M2[0][1] = static_cast<T>(2.0);
	M2[0][2] = static_cast<T>(3.0);
	M2[0][3] = static_cast<T>(4.0);
	M2[1][0] = static_cast<T>(5.0);
	M2[1][1] = static_cast<T>(6.0);
	M2[1][2] = static_cast<T>(7.0);
	M2[1][3] = static_cast<T>(8.0);
	vmath::core::Matrix<T, 4, 2> M3;
	M3[0][0] = static_cast<T>(8.0);
	M3[0][1] = static_cast<T>(7.0);
	M3[0][2] = static_cast<T>(6.0);
	M3[0][3] = static_cast<T>(5.0);
	M3[1][0] = static_cast<T>(4.0);
	M3[1][1] = static_cast<T>(3.0);
	M3[1][2] = static_cast<T>(2.0);
	M3[1][3] = static_cast<T>(1.0);
	BOOST_CHECK(M1.equals(M2));
	BOOST_CHECK(!M1.equals(M3));
	BOOST_CHECK(!M2.equals(M3));
}

BOOST_AUTO_TEST_CASE_TEMPLATE(equals_specify_ulp, T, float_types) {
	vmath::core::Matrix<T, 4, 2> M1;
	M1[0][0] = static_cast<T>(1.0);
	M1[0][1] = static_cast<T>(2.0);
	M1[0][2] = static_cast<T>(3.0);
	M1[0][3] = static_cast<T>(4.0);
	M1[1][0] = static_cast<T>(5.0);
	M1[1][1] = static_cast<T>(6.0);
	M1[1][2] = static_cast<T>(7.0);
	M1[1][3] = static_cast<T>(8.0);
	vmath::core::Matrix<T, 4, 2> M2;
	M2[0][0] = static_cast<T>(1.0);
	M2[0][1] = static_cast<T>(2.0);
	M2[0][2] = static_cast<T>(3.0);
	M2[0][3] = static_cast<T>(4.0);
	M2[1][0] = static_cast<T>(5.0);
	M2[1][1] = static_cast<T>(6.0);
	M2[1][2] = static_cast<T>(7.0);
	M2[1][3] = static_cast<T>(8.0);
	vmath::core::Matrix<T, 4, 2> M3;
	M3[0][0] = static_cast<T>(8.0);
	M3[0][1] = static_cast<T>(7.0);
	M3[0][2] = static_cast<T>(6.0);
	M3[0][3] = static_cast<T>(5.0);
	M3[1][0] = static_cast<T>(4.0);
	M3[1][1] = static_cast<T>(3.0);
	M3[1][2] = static_cast<T>(2.0);
	M3[1][3] = static_cast<T>(1.0);
	BOOST_CHECK(M1.equals(M2, 3));
	BOOST_CHECK(!M1.equals(M3, 3));
	BOOST_CHECK(!M2.equals(M3, 3));
}

BOOST_AUTO_TEST_CASE_TEMPLATE(equals_op, T, float_types) {
	vmath::core::Matrix<T, 4, 2> M1;
	M1[0][0] = static_cast<T>(1.0);
	M1[0][1] = static_cast<T>(2.0);
	M1[0][2] = static_cast<T>(3.0);
	M1[0][3] = static_cast<T>(4.0);
	M1[1][0] = static_cast<T>(5.0);
	M1[1][1] = static_cast<T>(6.0);
	M1[1][2] = static_cast<T>(7.0);
	M1[1][3] = static_cast<T>(8.0);
	vmath::core::Matrix<T, 4, 2> M2;
	M2[0][0] = static_cast<T>(1.0);
	M2[0][1] = static_cast<T>(2.0);
	M2[0][2] = static_cast<T>(3.0);
	M2[0][3] = static_cast<T>(4.0);
	M2[1][0] = static_cast<T>(5.0);
	M2[1][1] = static_cast<T>(6.0);
	M2[1][2] = static_cast<T>(7.0);
	M2[1][3] = static_cast<T>(8.0);
	vmath::core::Matrix<T, 4, 2> M3;
	M3[0][0] = static_cast<T>(8.0);
	M3[0][1] = static_cast<T>(7.0);
	M3[0][2] = static_cast<T>(6.0);
	M3[0][3] = static_cast<T>(5.0);
	M3[1][0] = static_cast<T>(4.0);
	M3[1][1] = static_cast<T>(3.0);
	M3[1][2] = static_cast<T>(2.0);
	M3[1][3] = static_cast<T>(1.0);
	BOOST_CHECK(M1 == M2);
	BOOST_CHECK(M1 != M3);
	BOOST_CHECK(M2 != M3);
}

BOOST_AUTO_TEST_SUITE_END()
