/*!
@file
Forward declares `boost::hana::integral_constant`.

@copyright Louis Dionne 2013-2017
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
 */

#ifndef BOOST_HANA_FWD_INTEGRAL_CONSTANT_HPP
#define BOOST_HANA_FWD_INTEGRAL_CONSTANT_HPP

#include <boost/hana/config.hpp>
#include <boost/hana/detail/integral_constant.hpp>

#include <cstddef>
#include <cstdint>


BOOST_HANA_NAMESPACE_BEGIN
    //! Creates an `integral_constant` holding the given compile-time value.
    //! @relates hana::integral_constant
    //!
    //! Specifically, `integral_c<T, v>` is a `hana::integral_constant`
    //! holding the compile-time value `v` of an integral type `T`.
    //!
    //!
    //! @tparam T
    //! The type of the value to hold in the `integral_constant`.
    //! It must be an integral type.
    //!
    //! @tparam v
    //! The integral value to hold in the `integral_constant`.
    //!
    //!
    //! Example
    //! -------
    //! @snippet example/integral_constant.cpp integral_c
    template <typename T, T v>
    BOOST_HANA_INLINE_VARIABLE constexpr integral_constant<T, v> integral_c{};


#define BOOST_HANA_INTEGRAL_CONSTANT_SHORTHAND(val_ty, param, ty, var) \
    //! @relates hana::integral_constant                               \
    template <val_ty param>                                            \
    using ty = integral_constant<val_ty, param>;                       \
                                                                       \
    //! @relates hana::integral_constant                               \
    template <val_ty param>                                            \
    BOOST_HANA_INLINE_VARIABLE constexpr ty<param> var{};              \
    /**/

    BOOST_HANA_INTEGRAL_CONSTANT_SHORTHAND(               bool, b,          bool_,         bool_c)

    //! @relates hana::integral_constant
    using true_ = bool_<true>;

    //! @relates hana::integral_constant
    BOOST_HANA_INLINE_VARIABLE constexpr true_ true_c{};

    //! @relates hana::integral_constant
    using false_ = bool_<false>;

    //! @relates hana::integral_constant
    BOOST_HANA_INLINE_VARIABLE constexpr false_ false_c{};

    BOOST_HANA_INTEGRAL_CONSTANT_SHORTHAND(               char, c,          char_,         char_c)
#ifndef BOOST_HANA_LEAN_AND_MEAN
    BOOST_HANA_INTEGRAL_CONSTANT_SHORTHAND(   signed      char, i,          schar,        schar_c)
#endif
    BOOST_HANA_INTEGRAL_CONSTANT_SHORTHAND( unsigned      char, i,          uchar,        uchar_c)
    BOOST_HANA_INTEGRAL_CONSTANT_SHORTHAND(              short, i,         short_,        short_c)
    BOOST_HANA_INTEGRAL_CONSTANT_SHORTHAND( unsigned     short, i,        ushort_,       ushort_c)
    BOOST_HANA_INTEGRAL_CONSTANT_SHORTHAND(                int, i,           int_,          int_c)
    BOOST_HANA_INTEGRAL_CONSTANT_SHORTHAND( unsigned       int, i,           uint,         uint_c)
    BOOST_HANA_INTEGRAL_CONSTANT_SHORTHAND(               long, i,          long_,         long_c)
    BOOST_HANA_INTEGRAL_CONSTANT_SHORTHAND( unsigned      long, i,          ulong,        ulong_c)
    BOOST_HANA_INTEGRAL_CONSTANT_SHORTHAND(          long long, i,          llong,        llong_c)
    BOOST_HANA_INTEGRAL_CONSTANT_SHORTHAND( unsigned long long, i,         ullong,       ullong_c)
    BOOST_HANA_INTEGRAL_CONSTANT_SHORTHAND(        std::size_t, i,         size_t,         size_c)
    BOOST_HANA_INTEGRAL_CONSTANT_SHORTHAND(     std::ptrdiff_t, i,      ptrdiff_t,      ptrdiff_c)

    // stackoverflow.com/a/59553656
#   if !defined(BOOST_HANA_SILENCE_FIXED_WIDTH_INTEGER_ABSENCE_WARNING)
#       if !defined(   INT8_MAX) || \
           !defined(  UINT8_MAX) || \
           !defined(  INT16_MAX) || \
           !defined( UINT16_MAX) || \
           !defined(  INT32_MAX) || \
           !defined( UINT32_MAX) || \
           !defined(  INT64_MAX) || \
           !defined( UINT64_MAX) || \
           !defined( INTPTR_MAX) || \
           !defined(UINTPTR_MAX)
#           warning The compiler you are using does not support one or more of the common        \
                    fixed-width integer types (int8_t etc.). Corresponding names 'hana::*_t' and \
                    'hana::*_c' will not be defined. To silence this warning, define the macro   \
                    BOOST_HANA_SILENCE_FIXED_WIDTH_INTEGER_ABSENCE_WARNING before including any  \
                    Boost.Hana header files.
#       endif
#   endif

#   ifdef    INT8_MAX
    BOOST_HANA_INTEGRAL_CONSTANT_SHORTHAND(        std::int8_t, i,         int8_t,         int8_c)
#   endif
#   ifdef   UINT8_MAX
    BOOST_HANA_INTEGRAL_CONSTANT_SHORTHAND(       std::uint8_t, i,        uint8_t,        uint8_c)
#   endif
#   ifdef   INT16_MAX
    BOOST_HANA_INTEGRAL_CONSTANT_SHORTHAND(       std::int16_t, i,        int16_t,        int16_c)
#   endif
#   ifdef  UINT16_MAX
    BOOST_HANA_INTEGRAL_CONSTANT_SHORTHAND(      std::uint16_t, i,       uint16_t,       uint16_c)
#   endif
#   ifdef   INT32_MAX
    BOOST_HANA_INTEGRAL_CONSTANT_SHORTHAND(       std::int32_t, i,        int32_t,        int32_c)
#   endif
#   ifdef  UINT32_MAX
    BOOST_HANA_INTEGRAL_CONSTANT_SHORTHAND(      std::uint32_t, i,       uint32_t,       uint32_c)
#   endif
#   ifdef   INT64_MAX
    BOOST_HANA_INTEGRAL_CONSTANT_SHORTHAND(       std::int64_t, i,        int64_t,        int64_c)
#   endif
#   ifdef  UINT64_MAX
    BOOST_HANA_INTEGRAL_CONSTANT_SHORTHAND(      std::uint64_t, i,       uint64_t,       uint64_c)
#   endif
#   ifdef  INTPTR_MAX
    BOOST_HANA_INTEGRAL_CONSTANT_SHORTHAND(      std::intptr_t, i,       intptr_t,       intptr_c)
#   endif
#   ifdef UINTPTR_MAX
    BOOST_HANA_INTEGRAL_CONSTANT_SHORTHAND(     std::uintptr_t, i,      uintptr_t,      uintptr_c)
#   endif

#   ifndef BOOST_HANA_LEAN_AND_MEAN
    BOOST_HANA_INTEGRAL_CONSTANT_SHORTHAND(      std::intmax_t, i,       intmax_t,       intmax_c)
    BOOST_HANA_INTEGRAL_CONSTANT_SHORTHAND(     std::uintmax_t, i,      uintmax_t,      uintmax_c)
    BOOST_HANA_INTEGRAL_CONSTANT_SHORTHAND(   std::int_fast8_t, i,    int_fast8_t,    int_fast8_c)
    BOOST_HANA_INTEGRAL_CONSTANT_SHORTHAND(  std::uint_fast8_t, i,   uint_fast8_t,   uint_fast8_c)
    BOOST_HANA_INTEGRAL_CONSTANT_SHORTHAND(  std::int_fast16_t, i,   int_fast16_t,   int_fast16_c)
    BOOST_HANA_INTEGRAL_CONSTANT_SHORTHAND( std::uint_fast16_t, i,  uint_fast16_t,  uint_fast16_c)
    BOOST_HANA_INTEGRAL_CONSTANT_SHORTHAND(  std::int_fast32_t, i,   int_fast32_t,   int_fast32_c)
    BOOST_HANA_INTEGRAL_CONSTANT_SHORTHAND( std::uint_fast32_t, i,  uint_fast32_t,  uint_fast32_c)
    BOOST_HANA_INTEGRAL_CONSTANT_SHORTHAND(  std::int_fast64_t, i,   int_fast64_t,   int_fast64_c)
    BOOST_HANA_INTEGRAL_CONSTANT_SHORTHAND( std::uint_fast64_t, i,  uint_fast64_t,  uint_fast64_c)
    BOOST_HANA_INTEGRAL_CONSTANT_SHORTHAND(  std::int_least8_t, i,   int_least8_t,   int_least8_c)
    BOOST_HANA_INTEGRAL_CONSTANT_SHORTHAND( std::uint_least8_t, i,  uint_least8_t,  uint_least8_c)
    BOOST_HANA_INTEGRAL_CONSTANT_SHORTHAND( std::int_least16_t, i,  int_least16_t,  int_least16_c)
    BOOST_HANA_INTEGRAL_CONSTANT_SHORTHAND(std::uint_least16_t, i, uint_least16_t, uint_least16_c)
    BOOST_HANA_INTEGRAL_CONSTANT_SHORTHAND( std::int_least32_t, i,  int_least32_t,  int_least32_c)
    BOOST_HANA_INTEGRAL_CONSTANT_SHORTHAND(std::uint_least32_t, i, uint_least32_t, uint_least32_c)
    BOOST_HANA_INTEGRAL_CONSTANT_SHORTHAND( std::int_least64_t, i,  int_least64_t,  int_least64_c)
    BOOST_HANA_INTEGRAL_CONSTANT_SHORTHAND(std::uint_least64_t, i, uint_least64_t, uint_least64_c)
#   endif

#undef BOOST_HANA_INTEGRAL_CONSTANT_SHORTHAND


    namespace literals {
        //! Creates a `hana::integral_constant` from a literal.
        //! @relatesalso boost::hana::integral_constant
        //!
        //! The literal is parsed at compile-time and the result is returned
        //! as a `llong<...>`.
        //!
        //! @note
        //! We use `llong<...>` instead of `ullong<...>` because using an
        //! unsigned type leads to unexpected behavior when doing stuff like
        //! `-1_c`. If we used an unsigned type, `-1_c` would be something
        //! like `ullong<-1>` which is actually `ullong<something huge>`.
        //!
        //!
        //! Example
        //! -------
        //! @snippet example/integral_constant.cpp literals
        template <char ...c>
        constexpr auto operator"" _c();
    }
BOOST_HANA_NAMESPACE_END

#endif // !BOOST_HANA_FWD_INTEGRAL_CONSTANT_HPP
