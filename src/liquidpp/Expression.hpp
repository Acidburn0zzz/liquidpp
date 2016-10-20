#pragma once

#include "ValueConverter.hpp"

namespace liquidpp {

class Context;

struct Expression {
   enum class Operator {
      Equal,
      NotEqual,
      Less,
      LessEqual,
      Greater,
      GreaterEqual,
      Contains,
      And,
      Or
   };

   static boost::optional<Operator> toOperator(string_view str);

   struct VariableName {
      string_view name;

      bool operator==(const VariableName& other) const
      {
         return name == other.name;
      }
   };

   using Token = boost::variant<Operator, Value, VariableName>;

   static bool matches(const Value& left, Operator operator_, const Value& right);
   static std::vector<string_view> splitTokens(string_view sequence);
   static Token toToken(string_view tokenStr);
   static Expression fromSequence(string_view sequence);
   static Value value(const Context& c, const Token& t);
   static bool isInteger(string_view sv);
   static bool isFloat(string_view sv);

   Value operator()(Context& c) const;

   std::vector<Token> tokens;
};
}
