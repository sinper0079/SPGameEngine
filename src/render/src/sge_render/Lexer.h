#pragma once

#include "Render_Common.h"

namespace sge {


	enum class TokenType {
		None,
		Identifier,
		Operator,
		Number,
		String
	};
	struct Token {
		TokenType type;
		String value;

		void Reset() { type = TokenType::None, value.clear(); }
	};
 struct Lexer: public NonCopyable {


	bool _HandleIdentifier();
	bool _HandleNumber();
	bool _HandleString();
	bool _HandleOperator();
	bool NextChar();
	bool NextToken();
	bool IsAlpha(char ch);
	bool IsDigit(char ch);
	void _TrimSpace();

	Token _Token;
	char _Ch; 
	char* _Cur;
	size_t _Line = 0;
	size_t _Col= 0;
};




const char* LexerTokenTypeName(TokenType t);


}


