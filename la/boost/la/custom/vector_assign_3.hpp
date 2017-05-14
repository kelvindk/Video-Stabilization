//Copyright (c) 2009 Emil Dotchevski and Reverge Studios, Inc.

//Distributed under the Boost Software License, Version 1.0. (See accompanying
//file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_LA_CUSTOM_VECTOR_ASSIGN_3_HPP_INCLUDED
#define BOOST_LA_CUSTOM_VECTOR_ASSIGN_3_HPP_INCLUDED

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
            vector_traits<A>::dim==3 && vector_traits<B>::dim==3,
            A &>::type
        assign( A & a, B const & b )
            {
            vector_traits<A>::template w<0>(a)=vector_traits<B>::template r<0>(b);
            vector_traits<A>::template w<1>(a)=vector_traits<B>::template r<1>(b);
            vector_traits<A>::template w<2>(a)=vector_traits<B>::template r<2>(b);
            return a;
            }

        namespace
        la_detail
            {
            template <int D>
            struct vector_assign_defined;

            template <>
            struct
            vector_assign_defined<3>
                {
                static bool const value=true;
                };
            }
        }
    }

#endif
