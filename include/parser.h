#pragma once

#include "include/lexer.h"
#include "include/ast.h"
#include "include/logger.h"
#include <map>

static int CurTok;
// BinopPrecedence - This holds the precedence for each binary operator that is defined
static std::map<char, int> BinopPrecedence;
int getNextToken();
std::unique_ptr<ExprAST> ParseNumberExpr();
std::unique_ptr<ExprAST> ParseParenExpr();
std::unique_ptr<ExprAST> ParseIdentifierExpr();
std::unique_ptr<ExprAST> ParsePrimary();
int GetTokPrecedence();
std::unique_ptr<ExprAST> ParseExpression();
std::unique_ptr<ExprAST> ParseBinOpRHS(int ExprPrec, 
                                            std::unique_ptr<ExprAST> LHS);
std::unique_ptr<PrototypeAST> ParsePrototype();
std::unique_ptr<FunctionAST> ParseDefinition();
std::unique_ptr<PrototypeAST> ParseExtern();
std::unique_ptr<FunctionAST> ParseTopLevelExpr();
                            