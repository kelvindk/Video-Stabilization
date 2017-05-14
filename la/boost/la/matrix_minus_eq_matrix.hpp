//Copyright (c) 2008-2009 Emil Dotchevski and Reverge Studios, Inc.

//Distributed under the Boost Software License, Version 1.0. (See accompanying
//file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef UUID_B4E1ABAAAD8511DEB9DF493D56D89593
#define UUID_B4E1ABAAAD8511DEB9DF493D56D89593

#include <boost/la/custom/matrix_minus_eq_matrix.hpp>

namespace
boost
	{
	namespace
	la
		{
		namespace
		la_detail
			{
			template <int M,int N>
			struct
			matrix_minus_eq_matrix_defined
				{
				static bool const value=false;
				};
			}

		template <class A,class B>
		BOOST_LA_INLINE_OPERATIONS
		typename enable_if_c<
			is_matrix<A>::value && is_matrix<B>::value &&
			matrix_traits<A>::rows==matrix_traits<B>::rows &&
			matrix_traits<A>::cols==matrix_traits<B>::cols &&
			!la_detail::matrix_minus_eq_matrix_defined<matrix_traits<A>::rows,matrix_traits<A>::cols>::value,
			A &>::type
		operator-=( A & a, B const & b )
			{
			for( int i=0; i!=matrix_traits<A>::rows; ++i )
				for( int j=0; j!=matrix_traits<A>::cols; ++j )
					matrix_traits<A>::iw(i,j,a)-=matrix_traits<B>::ir(i,j,b);
            return a;
			}
		}
	}

#endif
