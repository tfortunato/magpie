#pragma once

#include "Macros.h"
#include "Token.h"

namespace magpie
{
  class Memory;

  class Lexer
  {
  public:
    Lexer(gc<String> fileName, gc<String> source)
    : fileName_(fileName),
      source_(source),
      pos_(0),
      start_(0),
      skipNewline_(true),
      startRow_(1),
      startCol_(1),
      currentRow_(1),
      currentCol_(1)
    {}

    // Lexes and returns the next full Token read from the source. Handles
    // eliding newlines that should ignored.
    temp<Token> readToken();

  private:
    // Reads a single token without and newline processing.
    temp<Token> readRawToken();
    
    bool isDone() const;

    bool isWhitespace(char c) const;
    bool isNameStart(char c) const;
    bool isName(char c) const;
    bool isDigit(char c) const;

    char peek(int ahead = 0) const;

    char advance();

    temp<Token> makeToken(TokenType type);
    temp<Token> makeToken(TokenType type, gc<String> text);
    temp<Token> error(gc<String> message);
    
    void skipLineComment();
    void skipBlockComment();

    temp<Token> readName();
    temp<Token> readNumber();
    temp<Token> readString();

    gc<String> fileName_;
    gc<String> source_;
    int     pos_;
    int     start_;
    bool    skipNewline_;
    int     startRow_;
    int     startCol_;
    int     currentRow_;
    int     currentCol_;
    
    NO_COPY(Lexer);
  };
}
