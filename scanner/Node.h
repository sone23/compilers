#pragma once
#ifndef _NODE_H_
#define _NODE_H_
#include <vector>
#include <string>
#include <string>
#include "Symbol.h"
#include "Debug.h"

class Node {
public:
	Node(); 
	virtual void Interpret() = 0;
	virtual ~Node();
};

class StatementNode :Node {
public:
	StatementNode();
	void Interpret();
	~StatementNode();

};

class StatementGroupNode :public Node {
public:
	void AddStatement(StatementNode* sn);
	StatementGroupNode();
	void Interpret();
	~StatementGroupNode();
	std::vector<StatementNode*> stl;
};



class BlockNode :public StatementNode {
public:
	BlockNode(StatementGroupNode* sgn);
	void Interpret();
	~BlockNode();
	StatementGroupNode* mSgn;

};

class ProgramNode :Node {
public:
	ProgramNode(BlockNode* bn);
	void Interpret();
	~ProgramNode();
	BlockNode* mBn;
};

class StartNode:Node {
public:
	StartNode(ProgramNode* pn);
	void Interpret();
	~StartNode();
	ProgramNode* mPn;
};

class ExpressionNode {
public:
	virtual int Evaluate() = 0;
	ExpressionNode();
	virtual ~ExpressionNode();
};

class IdentifierNode :public ExpressionNode {
public:
	string mLabel;
	SymbolTableClass* mtable;
	IdentifierNode(string label, SymbolTableClass* table);
	void DeclareVariable();
	void SetValue(int v);
	int GetIndex();
	int Evaluate();
};



class DeclarationStateNode :public StatementNode {
public:
	DeclarationStateNode(IdentifierNode* in);
	~DeclarationStateNode();
	void Interpret();
	IdentifierNode* mIn;
};

class AssignmentStatementNode:public StatementNode {
public:
	AssignmentStatementNode(IdentifierNode* in, ExpressionNode* en);
	~AssignmentStatementNode();
	void Interpret();
	IdentifierNode* mIn;
	ExpressionNode* mEn;
};

class CoutStatementNode :public StatementNode {
public:
	CoutStatementNode(ExpressionNode* en);
	~CoutStatementNode();
	void Interpret();
	ExpressionNode* mEn;
};



class IntegerNode:public ExpressionNode {
public:
	IntegerNode(int n);
	int Evaluate();
private:
	int mInteger;
};

class  BinaryOperatorNode:public ExpressionNode {
public:
	BinaryOperatorNode(ExpressionNode* mLhs, ExpressionNode* mRhs);
	~BinaryOperatorNode();
protected:
	ExpressionNode* mLhs;
	ExpressionNode* mRhs;

};

class PlusNode:public BinaryOperatorNode {
public:
	PlusNode(ExpressionNode* left, ExpressionNode* right);
	int Evaluate();
};

class MinusNode :public BinaryOperatorNode {
public:
	MinusNode(ExpressionNode* left, ExpressionNode* right);
	int Evaluate();
};

class TimesNode :public BinaryOperatorNode {
public:
	TimesNode(ExpressionNode* left, ExpressionNode* right);
	int Evaluate();
};

class DivideNode :public BinaryOperatorNode {
public:
	DivideNode(ExpressionNode* left, ExpressionNode* right);
	int Evaluate();
};

class LessNode : public BinaryOperatorNode {
public:
	LessNode(ExpressionNode* left, ExpressionNode* right);
	int Evaluate();
};

class LessEqualNode : public BinaryOperatorNode {
public:
	LessEqualNode(ExpressionNode* left, ExpressionNode* right);
	int Evaluate();
};

class GreaterNode : public BinaryOperatorNode {
public:
	GreaterNode(ExpressionNode* left, ExpressionNode* right);
	int Evaluate();
};

class GreaterEqualNode : public BinaryOperatorNode {
public:
	GreaterEqualNode(ExpressionNode* left, ExpressionNode* right);
	int Evaluate();
};

class EqualNode : public BinaryOperatorNode {
public:
	EqualNode(ExpressionNode* left, ExpressionNode* right);
	int Evaluate();
};

class NotEqualNode : public BinaryOperatorNode {
public:
	NotEqualNode(ExpressionNode* left, ExpressionNode* right);
	int Evaluate();
};

class AndNode : public BinaryOperatorNode {

};
class IfStatementNode : public StatementNode {
public:
	IfStatementNode(ExpressionNode* en, StatementNode* sn);
	~IfStatementNode();
	void Interpret();
	ExpressionNode* mExpression;
	StatementNode* mStatement;
};

class WhileStatementNode : public StatementNode {
public:
	WhileStatementNode(ExpressionNode* en, StatementNode* sn);
	~WhileStatementNode();
	void Interpret();
	ExpressionNode* mExpression;
	StatementNode* mStatement;
};

#endif

