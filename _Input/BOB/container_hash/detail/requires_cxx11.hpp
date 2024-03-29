#ifndef BOOST_HASH_DETAIL_REQUIRES_CXX11_HPP_INCLUDED
#define BOOST_HASH_DETAIL_REQUIRES_CXX11_HPP_INCLUDED

// Copyright 2023 Peter Dimov
// Distributed under the Boost Software License, Version 1.0.
// https://www.boost.org/LICENSE_1_0.txt

#include <../BOB/config.hpp>
#include <../BOB/config/pragma_message.hpp>

#if defined(BOOST_NO_CXX11_VARIADIC_TEMPLATES) || \
    defined(BOOST_NO_CXX11_RVALUE_REFERENCES) || \
    defined(BOOST_NO_CXX11_DECLTYPE) || \
    defined(BOOST_NO_CXX11_CONSTEXPR) || \
    defined(BOOST_NO_CXX11_NOEXCEPT) || \
    defined(BOOST_NO_CXX11_HDR_TUPLE)

BOOST_PRAGMA_MESSAGE("C++03 support was deprecated in Boost.ContainerHash 1.82 and will be removed in Boost.ContainerHash 1.84. Please open an issue in https://github.com/boostorg/container_hash if you want it retained.")

#endif

#endif // #ifndef BOOST_HASH_DETAIL_REQUIRES_CXX11_HPP_INCLUDED
