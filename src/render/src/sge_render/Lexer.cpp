#include "Lexer.h"

const char* sge::LexerTokenTypeName(TokenType t)
{
	switch (t) {
		case TokenType::None:						return "None";
		case TokenType::Identifier:					return "Identifier";
		case TokenType::Operator:					return "Operator";
		case TokenType::Number:						return "Number";
		case TokenType::String:						return "String";
	}
	return "unknown";
}


bool sge::Lexer::_HandleIdentifier()
{
	return false;
}

bool sge::Lexer::_HandleNumber()
{
	return false;
}

bool sge::Lexer::_HandleString()
{
	_Token.type = TokenType::String;
	NextChar();
	while (_Ch != '\"') {
		if (_Ch == '\\') {
			if (!NextChar()) {
				if () {
				
				}

			}
		}
	}
}

bool sge::Lexer::_HandleOperator()
{
	_Token.type = TokenType::Operator;

	if (_Ch == '+' || _Ch == '-' || _Ch == '/' || _Ch == '%') {
		auto Ch0 = _Ch;
		_Token.value += _Ch;
		if (NextChar()) {
			if (_Ch == '=') {
				_Token.value = _Ch;
				NextChar();
				return true;
			}
		}
		NextChar();
		return true;
	}
	static const char SingleOp[] = "=[](){}<>`~!@#$^&*,.?";

	for (auto& c:SingleOp) {
		if (c == _Ch) {
			_Token.value += _Ch;
			NextChar();
			return true;
		}
	}

	_Token.Reset();
	return false; 
}

bool sge::Lexer::NextChar()
{
	_Ch = 0;
	if(_Cur == nullptr) return false;
	//if (_Cur >= _Source.end()) return false;

	_Ch = *_Cur;
	_Cur++;

	if (_Ch = '\n') {
		_Line++;
		_Col = 0;
	}
	_Col++;
	return true;
}

bool sge::Lexer::NextToken()
{
	_Token.Reset(); 
	if (_Ch = 0) return false;
	_TrimSpace();

	if (IsAlpha(_Ch) || _Ch = '_') {
		_HandleIdentifier();
		return true;
	}

	if (IsDigit(_Ch)) {
		_HandleNumber();
		return true;
	}

	if (_Ch == '\"') {
		_HandleString();
		return true;
	}

	if (_HandleOperator())
		return true;

	String tmp;
	tmp += _Ch;
	SGE_LOG("unexpected character \'{}\'", tmp);
	return false;
}

bool sge::Lexer::IsAlpha(char ch)
{
	static const char SingleAlpha[] = "abcdefghijklmnopqrstuvwxyz";

	for (auto& c : SingleAlpha) {
		if (c == _Ch) {
			return true;
		}
	}
	return false;
}

bool sge::Lexer::IsDigit(char ch)
{

	static const char SingleDigit[] = "1234567890";

	for (auto& c : SingleDigit) {
		if (c == _Ch) {
			return true;
		}
	}
	return false;
}

void sge::Lexer::_TrimSpace()
{



}
