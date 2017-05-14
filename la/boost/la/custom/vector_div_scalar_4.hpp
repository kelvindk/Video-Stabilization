//Copyright (c) 2009 Emil Dotchevski and Reverge Studios, Inc.

//Distributed under the Boost Software License, Version 1.0. (See accompanying
//file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_LA_CUSTOM_VECTOR_DIV_SCALAR_4_HPP_INCLUDED
#define BOOST_LA_CUSTOM_VECTOR_DIV_SCALAR_4_HPP_INCLUDED

//This file was generated by a program. Do not edit manually.

#include <boost/la/config.hpp>
#include <boost/la/deduce_vector.hpp>
#include <boost/utility/enable_if.hpp>

namespace
boost
    {
    namespace
    la
        {
        template <class A>
        BOOST_LA_INLINE_OPERATIONS
        typename lazy_enable_if_c<
            vector_traits<A>::dim==4,
            deduce_vector<A> >::type
        operator/( A const & a, typename vector_traits<A>::scalar_type b )
            {
            typedef typename deduce_vector<A>::type R;
            R r;
            vector_traits<R>::template w<0>(r)=vector_traits<A>::template r<0>(a)/b;
            vector_traits<R>::template w<1>(r)=vector_traits<A>::template r<1>(a)/b;
            vector_traits<R>::template w<2>(r)=vector_traits<A>::template r<2>(a)/b;
            vector_traits<R>::template w<3>(r)=vector_traits<A>::template r<3>(a)/b;
            return r;
            }

        namespace
        la_detail
            {
            template <int D>
            struct vector_div_scalar_defined;

            template <>
            struct
            vector_div_scalar_defined<4>
                {
                static bool const value=true;
                };
            }
        }
    }

#endif
