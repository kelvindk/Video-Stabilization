//Copyright (c) 2008-2009 Emil Dotchevski and Reverge Studios, Inc.

//Distributed under the Boost Software License, Version 1.0. (See accompanying
//file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <boost/la/all.hpp>
using namespace boost::la;

namespace
n1
	{
	struct user_matrix1 { float a[3][3]; };
	struct user_matrix2 { float a[3][3]; };
	}

namespace
n2
	{
	struct user_matrix1 { float a[3][3]; };
	struct user_matrix2 { float a[3][3]; };
	}

namespace
boost
	{
	namespace
	la
		{
		template <>
		struct
		matrix_traits<n1::user_matrix1>
			{
			typedef float scalar_type;
			static int const rows=3;
			static int const cols=3;

			template <int R,int C>
			static inline scalar_type & w( n1::user_matrix1 & m ) { return m.a[R][C]; }

			template <int R,int C>
			static inline scalar_type r( n1::user_matrix1 const & m ) { return m.a[R][C]; }

			static inline scalar_type & iw( int r, int c, n1::user_matrix1 & m ) { return m.a[r][c]; }
			static inline scalar_type ir( int r, int c, n1::user_matrix1 const & m ) { return m.a[r][c]; }
			};

		template <>
		struct
		matrix_traits<n1::user_matrix2>
			{
			typedef float scalar_type;
			static int const rows=3;
			static int const cols=3;

			template <int R,int C>
			static inline scalar_type & w( n1::user_matrix2 & m ) { return m.a[R][C]; }

			template <int R,int C>
			static inline scalar_type r( n1::user_matrix2 const & m ) { return m.a[R][C]; }

			static inline scalar_type & iw( int r, int c, n1::user_matrix2 & m ) { return m.a[r][c]; }
			static inline scalar_type ir( int r, int c, n1::user_matrix2 const & m ) { return m.a[r][c]; }
			};

		template <>
		struct
		matrix_traits<n2::user_matrix1>
			{
			typedef float scalar_type;
			static int const rows=3;
			static int const cols=3;

			template <int R,int C>
			static inline scalar_type & w( n2::user_matrix1 & m ) { return m.a[R][C]; }

			template <int R,int C>
			static inline scalar_type r( n2::user_matrix1 const & m ) { return m.a[R][C]; }

			static inline scalar_type & iw( int r, int c, n2::user_matrix1 & m ) { return m.a[r][c]; }
			static inline scalar_type ir( int r, int c, n2::user_matrix1 const & m ) { return m.a[r][c]; }
			};

		template <>
		struct
		matrix_traits<n2::user_matrix2>
			{
			typedef float scalar_type;
			static int const rows=3;
			static int const cols=3;

			template <int R,int C>
			static inline scalar_type & w( n2::user_matrix2 & m ) { return m.a[R][C]; }

			template <int R,int C>
			static inline scalar_type r( n2::user_matrix2 const & m ) { return m.a[R][C]; }

			static inline scalar_type & iw( int r, int c, n2::user_matrix2 & m ) { return m.a[r][c]; }
			static inline scalar_type ir( int r, int c, n2::user_matrix2 const & m ) { return m.a[r][c]; }
			};

		template <>
		struct deduce_matrix2<n2::user_matrix1,n2::user_matrix2,3,3>
			{ typedef n2::user_matrix1 type; };

		template <>
		struct deduce_matrix2<n2::user_matrix2,n2::user_matrix1,3,3>
			{ typedef n2::user_matrix1 type; };
		}
	}

void
f()
	{
		{
		n1::user_matrix1 m1;
		n1::user_matrix2 m2;
		n1::user_matrix1 m = m1 * m2;
		}
		{
		n2::user_matrix1 m1;
		n2::user_matrix2 m2;
		n2::user_matrix1 m = m1 * m2;
		}
		{
		float m[3][3];
		(void) inverse(m);
		}
	}
