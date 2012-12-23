#pragma once

#include <iostream>

#include "Macros.h"
#include "MagpieString.h"
#include "Memory.h"

namespace magpie
{
  // The different types of Tokens that make up Magpie source code.
  enum TokenType
  {
    // Punctuators.
    TOKEN_LEFT_PAREN,
    TOKEN_RIGHT_PAREN,
    TOKEN_LEFT_BRACKET,
    TOKEN_RIGHT_BRACKET,
    TOKEN_LEFT_BRACE,
    TOKEN_RIGHT_BRACE,
    TOKEN_COMMA,
    TOKEN_DOT,
    TOKEN_DOTDOT,
    TOKEN_DOTDOTDOT,
    TOKEN_EQ,
    TOKEN_EQEQ,
    TOKEN_NEQ,
    
    // Infix operators. There is a different token type for each precedence.
    // The starting character determines the token type.
    TOKEN_COMPARE_OP, // < >
    TOKEN_TERM_OP,    // + -
    TOKEN_PRODUCT_OP, // * / %
    
    // Keywords.
    TOKEN_AND,
    TOKEN_ASYNC,
    TOKEN_BREAK,
    TOKEN_CASE,
    TOKEN_CATCH,
    TOKEN_DEF,
    TOKEN_DEFCLASS,
    TOKEN_DO,
    TOKEN_END,
    TOKEN_ELSE,
    TOKEN_FALSE,
    TOKEN_FN,
    TOKEN_FOR,
    TOKEN_IF,
    TOKEN_IMPORT,
    TOKEN_IN,
    TOKEN_IS,
    TOKEN_MATCH,
    TOKEN_NOT,
    TOKEN_NOTHING,
    TOKEN_OR,
    TOKEN_RETURN,
    TOKEN_THEN,
    TOKEN_THROW,
    TOKEN_TRUE,
    TOKEN_VAL,
    TOKEN_VAR,
    TOKEN_WHILE,
    TOKEN_XOR,

    TOKEN_FIELD,
    TOKEN_NAME,
    TOKEN_NUMBER,
    TOKEN_STRING,

    TOKEN_LINE,
    TOKEN_ERROR,
    TOKEN_EOF,
    
    TOKEN_NUM_TYPES
  };

  // A file containing Magpie source code.
  class SourceFile : public Managed
  {
  public:
    SourceFile(gc<String> path, gc<String> source);

    gc<String> path() { return path_; }
    gc<String> source() { return source_; }

    int length() const { return source_->length(); }

    gc<String> substring(int start, int end) const
    {
      return source_->substring(start, end);
    }
    
    char operator[](int pos) const { return (*source_)[pos]; }

    // Gets the line of code at the given 1-based line index.
    gc<String> getLine(int line);

    virtual void reach();

  private:
    gc<String> path_;
    gc<String> source_;
  };

  // A span of source code associated with some Token or AST.
  class SourcePos : public Managed
  {
  public:
    SourcePos(gc<SourceFile> file, int startLine, int startCol,
              int endLine, int endCol);
    
    gc<SourceFile> file() const { return file_; }
    int startLine() const { return startLine_; }
    int startCol() const { return startCol_; }
    int endLine() const { return endLine_; }
    int endCol() const { return endCol_; }
    
    gc<SourcePos> spanTo(gc<SourcePos> end) const;

    virtual void reach();

  private:
    // The source file containing this position.
    gc<SourceFile> file_;
    
    int startLine_;
    int startCol_;
    int endLine_;
    int endCol_;
  };
  
  // A single meaningful Token of source code. Generated by the Lexer, and
  // consumed by the Parser.
  class Token : public Managed
  {
  public:
    Token(TokenType type, gc<String> text, gc<SourcePos> pos);
    
    static const char* typeString(TokenType type);
    
    TokenType      type() const { return type_; }
    gc<String>     text() const { return text_; }
    gc<SourcePos>  pos()  const { return pos_; }
    
    // Gets whether this token is of the given type.
    bool is(TokenType type) const { return type_ == type; }
    
    virtual void reach();
    virtual void trace(std::ostream& out) const;
    
  private:
    TokenType     type_;
    gc<String>    text_;
    gc<SourcePos> pos_;
  };
}

