#include "FilterFactory.hpp"

#include "filters/Escape.hpp"
#include "filters/Size.hpp"
#include "filters/Date.hpp"
#include "filters/Downcase.hpp"
#include "filters/Upcase.hpp"
#include "filters/Capitalize.hpp"
#include "filters/Assign.hpp"
#include "filters/NumberFilter.hpp"
#include "filters/Default.hpp"
#include "filters/FloatFilter.hpp"
#include "filters/Lstrip.hpp"
#include "filters/NewlineToBr.hpp"
#include "filters/Prepend.hpp"
#include "filters/Remove.hpp"
#include "filters/RemoveFirst.hpp"
#include "filters/Replace.hpp"
#include "filters/ReplaceFirst.hpp"
#include "filters/Round.hpp"
#include "filters/Rstrip.hpp"
#include "filters/Slice.hpp"
#include "filters/Strip.hpp"
#include "filters/StripNewlines.hpp"
#include "filters/Truncate.hpp"
#include "filters/TruncateWords.hpp"
#include "filters/StripHtml.hpp"
#include "filters/UrlEncode.hpp"
#include "filters/Split.hpp"
#include "filters/Join.hpp"
#include "filters/Sort.hpp"
#include "filters/Reverse.hpp"
#include "filters/Uniq.hpp"

namespace liquidpp
{

std::shared_ptr<filters::Filter> FilterFactory::operator()(string_view name) const
{
   using namespace filters;

   if (name == "abs")
      return makeNumberFilter( [](auto d){ return std::abs(d); } );
   if (name == "append")
      return std::make_shared<Append>();
   if (name == "capitalize")
      return std::make_shared<Capitalize>();
   if (name == "ceil")
      return makeFloatFilter( [](double d){ return std::ceil(d); } );
   if (name == "date")
      return std::make_shared<Date>();
   if (name == "default")
      return std::make_shared<Default>();
   if (name == "divided_by")
      return makeNumberFilter1Arg( [](auto d, auto arg){ return d / arg; } );
   if (name == "downcase")
      return std::make_shared<Downcase>();
   if (name == "escape")
      return std::make_shared<Escape>();
   if (name == "escape_once")
      return std::make_shared<EscapeOnce>();
   if (name == "floor")
      return makeFloatFilter( [](double d){ return std::floor(d); } );
   if (name == "join")
      return std::make_shared<Join>();
   if (name == "lstrip")
      return std::make_shared<Lstrip>();
   // TODO: Filter: map
   if (name == "minus")
      return makeNumberFilter1Arg( [](auto d, auto arg){ return d - arg; } );
   if (name == "modulo")
      return makeNumberFilter1Arg( [](auto d, auto arg){ return fmod(d, arg); } );
   if (name == "newline_to_br")
      return std::make_shared<NewlineToBr>();
   if (name == "plus")
      return makeNumberFilter1Arg( [](auto d, auto arg){ return d + arg; } );
   if (name == "prepend")
      return std::make_shared<Prepend>();
   if (name == "remove")
      return std::make_shared<Remove>();
   if (name == "remove_first")
      return std::make_shared<RemoveFirst>();
   if (name == "replace")
      return std::make_shared<Replace>();
   if (name == "replace_first")
      return std::make_shared<ReplaceFirst>();
   if (name == "reverse")
      return std::make_shared<Reverse>();
   if (name == "round")
      return std::make_shared<Round>();
   if (name == "rstrip")
      return std::make_shared<Rstrip>();
   if (name == "size")
      return std::make_shared<Size>();
   if (name == "slice")
      return std::make_shared<Slice>();
   if (name == "sort")
      return std::make_shared<Sort>();
   if (name == "split")
      return std::make_shared<Split>();
   if (name == "strip")
      return std::make_shared<Strip>();
   if (name == "strip_html")
      return std::make_shared<StripHtml>();
   if (name == "strip_newlines")
      return std::make_shared<StripNewlines>();
   if (name == "times")
      return makeNumberFilter1Arg( [](auto d, auto arg){ return d * arg; } );
   if (name == "truncate")
      return std::make_shared<Truncate>();
   if (name == "truncatewords")
      return std::make_shared<TruncateWords>();
   if (name == "uniq")
      return std::make_shared<Uniq>();
   if (name == "upcase")
      return std::make_shared<Upcase>();
   if (name == "url_encode")
      return std::make_shared<UrlEncode>();

   return nullptr;
}

}