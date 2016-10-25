#pragma once

#include "Filter.hpp"
#include "../Expression.hpp"

namespace liquidpp
{
namespace filters
{

struct Sort : public Filter
{
   virtual Value operator()(Context& c, Value&& val) const override final
   {
      if (!val.isRange())
         return std::move(val);

      auto& vals = val.range().inlineValues();
      std::sort(vals.begin(), vals.end());

      return std::move(val);
   }
};

}
}