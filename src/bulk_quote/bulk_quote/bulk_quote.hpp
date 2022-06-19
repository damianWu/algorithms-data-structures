// Copyright [2022] <DamianWu>

#ifndef SRC_BULK_QUOTE_BULK_QUOTE_BULK_QUOTE_HPP_
#define SRC_BULK_QUOTE_BULK_QUOTE_BULK_QUOTE_HPP_

// #include <string>

#include <corecrt.h>

#include <cstdint>

#include "quote/quote.hpp"

namespace quote {
class Quote;
}

namespace bulk_quote {

using quote::Quote;

class BulkQuote : public Quote {
    using Quote::Quote;

 public:
    double net_price(uint32_t) const override;

 private:
};

inline double BulkQuote::net_price(const uint32_t n) const {
    return n * price_;
}

}  // namespace bulk_quote

#endif  // SRC_BULK_QUOTE_BULK_QUOTE_BULK_QUOTE_HPP_
