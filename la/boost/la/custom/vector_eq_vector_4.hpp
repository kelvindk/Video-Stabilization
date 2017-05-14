//Copyright (c) 2009 Emil Dotchevski and Reverge Studios, Inc.

//Distributed under the Boost Software License, Version 1.0. (See accompanying
//file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_LA_CUSTOM_VECTOR_EQ_VECTOR_4_HPP_INCLUDED
#define BOOST_LA_CUSTOM_VECTOR_EQ_VECTOR_4_HPP_INCLUDED

//This file was generated by a program. Do not edit manually.

#include <boost/la/config.hpp>
#include <boost/la/vector_traits.hpp>
#include <boost/utility/enable_if.hpp>

namespace
boost
    {
    namespace
    la
        {
        template <class A,class B>
        BOOST_LA_INLINE_OPERATIONS
        typename enable_if_c<
            vector_traits<A>::dim==4 && vector_traits<B>::dim==4,
        bool>::type
        operator==( A const & a, B const & b )
            {
            return
                vector_traits<A>::template r<0>(a)==vector_traits<B>::template r<0>(b) &&
                vector_traits<A>::template r<1>(a)==vector_traits<B>::template r<1>(b) &&
                vector_traits<A>::template r<2>(a)==vector_traits<B>::template r<2>(b) &&
                vector_traits<A>::template r<3>(a)==vector_traits<B>::template r<3>(b);
            }

        namespace
        la_detail
            {
            template <int D>
            struct vector_eq_vector_defined;

            template <>
            struct
            vector_eq_vector_defined<4>
                {
                static bool const value=true;
                };
            }
        }
    }

#endif
