#pragma once

#include <cstdint>

using uint_t = std::uint64_t;
using int_t = std::int64_t;

#define SQ(X) X * X

template<typename FP>
inline FP sq(FP val) { return SQ(val); }