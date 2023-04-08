#include "include/parser.h"

static int getNextToken() {
    return CurTok = gettok();
}

// numberexpr ::= number
static std::unique_ptr<ExprAST> ParseNumberExpr() {
    auto Result = std::make_unique<NumberExprAST>(NumVal);
    getNextToken();     // consume the number
    return std::move(Result);
}