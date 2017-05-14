//Copyright (c) 2009 Emil Dotchevski and Reverge Studios, Inc.

//Distributed under the Boost Software License, Version 1.0. (See accompanying
//file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_LA_CUSTOM_VECTOR_DOT_4_HPP_INCLUDED
#define BOOST_LA_CUSTOM_VECTOR_DOT_4_HPP_INCLUDED

//This file was generated by a program. Do not edit manually.

#include <boost/la/config.hpp>
#include <boost/la/vector_traits.hpp>
#include <boost/la/deduce_scalar.hpp>
#include <boost/utility/enable_if.hpp>

namespace
boost
    {
    namespace
    la
        {
        template <class A,class B>
        BOOST_LA_INLINE_OPERATIONS
        typename lazy_enable_if_c<
            vector_traits<A>::dim==4 && vector_traits<B>::dim==4,
            deduce_scalar<typename vector_traits<A>::scalar_type,typename vector_traits<B>::scalar_type> >::type
        dot( A const & a, B const & b )
            {
            typedef typename vector_traits<A>::scalar_type Ta;
            typedef typename vector_traits<B>::scalar_type Tb;
            typedef typename deduce_scalar<Ta,Tb>::type Tr;
            Ta const a0=vector_traits<A>::template r<0>(a);
            Ta const a1=vector_traits<A>::template r<1>(a);
            Ta const a2=vector_traits<A>::template r<2>(a);
            Ta const a3=vector_traits<A>::template r<3>(a);
            Tb const b0=vector_traits<B>::template r<0>(b);
            Tb const b1=vector_traits<B>::template r<1>(b);
            Tb const b2=vector_traits<B>::template r<2>(b);
            Tb const b3=vector_traits<B>::template r<3>(b);
            Tr const dot=a0*b0+a1*b1+a2*b2+a3*b3;
            return dot;
            }

        namespace
        la_detail
            {
            template <int D>
            struct vector_dot_defined;

            template <>
            struct
            vector_dot_defined<4>
                {
                static bool const value=true;
                };
            }
        }
    }

#endif
