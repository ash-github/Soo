#include "API.h"
#include "Parser.h"
#include <sstream>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
//string תint
int API::String2Int(string str)
{
	int number = atoi(str.c_str());
	return number;
}
//int תstring
string API::Int2String(int number)
{
	stringstream ss;
	string str;
	ss << number;
	ss >> str;
	return str;
}
//string תfloat
float API::String2Float(string str)
{
	float number = atof(str.c_str());
}
//stringn תchar *
char* API::String2CharPlus(string str)
{
	char * Char = new char[str.size()];
	strcpy(Char, str.data());
	return Char;
}
//Token ת Data_Type
Data_Type API::Token2Type(Token token)
{
	if (token.Token_GetText() == "int")
		return Int;
	if (token.Token_GetText() == "char")
		return Char;
	if (token.Token_GetText() == "float")
		return Float;
	if (token.Token_GetText() == "void")
		return Void;
	if (token.Token_GetText() == "string")
		return String;
}



//��ѯ�����Ƿ����
bool API::API_VariableFind(string variablename)
{
	bool Find = false;
	for (auto i = API::Instance().Pra_Variable.begin(); i != API::Instance().Pra_Variable.end(); i++)
	{
		if (variablename == i->variable_name)
		{
			Find = true;
			break;
		}
	}
	return Find;
}
//��ӭ����
void API::API_Welcome()
{
	string command;
	cout << "       Welcome to Soo       " << endl;
	cout << "            by:Leviathan1995" << endl;
	cout << "File or Input: f or i       " << endl;
	cout << "Please select:              " << endl;
	cin >> command;
	if (command == "f")
		API_ReadFile();
	else
		API_ShellInput();
}

//���ļ��ж�ȡ����
void API::API_ReadFile()
{
	int LineNumber = 0;
	Token token;
	ifstream Infile("code.txt");
	string Line;
	while (getline(Infile, Line))
	{
		LineNumber++;
		Lexer::Lexer_Instance().Lexer_Readline(Line, LineNumber);
	}
	Queue = Lexer::Lexer_Instance().Lexer_ReturnQueue();
	API::Instance().API_Parser(Queue);
}

//�����﷨����
void API::API_Parser(queue<Token> Queue)
{
	Parser::Parser_Instance().Parsering(Queue);
}