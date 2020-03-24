#include "Node.h"

Node::Node()
{
}

Node::~Node()
{
}

StartNode::StartNode(ProgramNode* pn)
{
	mPn = pn;
}

void StartNode::Interpret()
{
	mPn->Interpret();
}

StartNode::~StartNode()
{
	delete mPn;
	MSG("StartNode Deleting");
}

ProgramNode::ProgramNode(BlockNode* bn)
{
	//MSG("ProgramNode Created");
	mBn = bn;
}

void ProgramNode::Interpret()
{
	mBn->Interpret();
}

ProgramNode::~ProgramNode()
{
	delete mBn;
	MSG("ProgramNode Deleting");
}

StatementNode::StatementNode()
{
	//MSG("StatementNode Created");
}

void StatementNode::Interpret()
{
}

StatementNode::~StatementNode()
{
}

BlockNode::BlockNode(StatementGroupNode* sgn)
{
	mSgn = sgn;
}

void BlockNode::Interpret()
{
	mSgn->Interpret();
}

BlockNode::~BlockNode()
{
	delete mSgn;
	MSG("BlockNode Deleting");
}

void StatementGroupNode::AddStatement(StatementNode* sn)
{
	stl.push_back(sn);
}

StatementGroupNode::StatementGroupNode()
{
}

void StatementGroupNode::Interpret()
{
	for (int i = 0; i < stl.size(); i++)
	{
		stl[i]->Interpret();
	}
}

StatementGroupNode::~StatementGroupNode()
{
	for (int i = 0; i < stl.size(); i++)
	{
		delete stl[i];
	}
	MSG("StatementGroupNOde deleting");
}

AssignmentStatementNode::AssignmentStatementNode(IdentifierNode* in, ExpressionNode* en)
{
	mIn = in;
	mEn = en;
}

AssignmentStatementNode::~AssignmentStatementNode()
{
	delete mIn;
	delete mEn;
	MSG("AssignmentNode Deleting");
}

void AssignmentStatementNode::Interpret()
{
	int eval = mEn->Evaluate();
	mIn->SetValue(eval);
}

IntegerNode::IntegerNode(int n)
{
	mInteger = n;
}

int IntegerNode::Evaluate()
{
	return mInteger;
}

IdentifierNode::IdentifierNode(string label, SymbolTableClass* table)
{
	mLabel = label;
	mtable = table;
}

void IdentifierNode::DeclareVariable()
{
	mtable->AddEntry(mLabel);
}

void IdentifierNode::SetValue(int v)
{
	mtable->SetValue(mLabel, v);
}

int IdentifierNode::GetIndex()
{
	int index = mtable->GetIndex(mLabel);
	return index;
}

int IdentifierNode::Evaluate()
{
	int value = mtable->GetValue(mLabel);
	return value;
}

DeclarationStateNode::DeclarationStateNode(IdentifierNode* in)
{
	mIn = in;
}

DeclarationStateNode::~DeclarationStateNode()
{
	delete mIn;
	MSG("DeclarationNode Deleting");
}

void DeclarationStateNode::Interpret()
{
	mIn->DeclareVariable();
}

CoutStatementNode::CoutStatementNode(ExpressionNode* en)
{
	mEn = en;
}

CoutStatementNode::~CoutStatementNode()
{
	delete mEn;
	MSG("CoutNode Deleting");
}

void CoutStatementNode::Interpret()
{
	int eval = mEn->Evaluate();
	cout << eval << "\r" << endl;
}

ExpressionNode::ExpressionNode()
{
}

ExpressionNode::~ExpressionNode()
{
	MSG("ExpressionNode Deleting");
}

BinaryOperatorNode::BinaryOperatorNode(ExpressionNode* lhs, ExpressionNode* rhs)
{
	mLhs = lhs;
	mRhs = rhs;
}

BinaryOperatorNode::~BinaryOperatorNode()
{
	delete mLhs;
	delete mRhs;
	MSG("BinaryOperatorNode Deleting");
}

PlusNode::PlusNode(ExpressionNode* left, ExpressionNode* right)
	: BinaryOperatorNode(left, right)
{
}

int PlusNode::Evaluate()
{
	return mLhs->Evaluate() + mRhs->Evaluate();
}

MinusNode::MinusNode(ExpressionNode* left, ExpressionNode* right)
	: BinaryOperatorNode(left, right)
{
}

int MinusNode::Evaluate()
{
	return mLhs->Evaluate() + mRhs->Evaluate();
}

TimesNode::TimesNode(ExpressionNode* left, ExpressionNode* right)
	: BinaryOperatorNode(left, right)
{
}

int TimesNode::Evaluate()
{
	return mLhs->Evaluate() * mRhs->Evaluate();
}

DivideNode::DivideNode(ExpressionNode* left, ExpressionNode* right)
	: BinaryOperatorNode(left, right) {
}

int DivideNode::Evaluate()
{
	return mLhs->Evaluate() / mRhs->Evaluate();
}

LessNode::LessNode(ExpressionNode* left, ExpressionNode* right)
	: BinaryOperatorNode(left, right) {
}

int LessNode::Evaluate()
{
	if (mLhs->Evaluate() < mRhs->Evaluate())
		return 1;
	else {
		return 0;
	}
}

LessEqualNode::LessEqualNode(ExpressionNode* left, ExpressionNode* right)
	: BinaryOperatorNode(left, right) {
}

int LessEqualNode::Evaluate()
{
	if (mLhs->Evaluate() <= mRhs->Evaluate())
		return 1;
	else {
		return 0;
	}
}

GreaterNode::GreaterNode(ExpressionNode* left, ExpressionNode* right)
	: BinaryOperatorNode(left, right) {
}

int GreaterNode::Evaluate()
{
	if (mLhs->Evaluate() > mRhs->Evaluate())
		return 1;
	return 0;
}

GreaterEqualNode::GreaterEqualNode(ExpressionNode* left, ExpressionNode* right)
	: BinaryOperatorNode(left, right) {
}

int GreaterEqualNode::Evaluate()
{
	if (mLhs->Evaluate() >= mRhs->Evaluate())
		return 1;
	return 0;
}

EqualNode::EqualNode(ExpressionNode* left, ExpressionNode* right)
	: BinaryOperatorNode(left, right){
}

int EqualNode::Evaluate()
{
	if (mLhs->Evaluate() == mRhs->Evaluate())
		return 1;
	return 0;
}

NotEqualNode::NotEqualNode(ExpressionNode* left, ExpressionNode* right)
	: BinaryOperatorNode(left, right) {
}

int NotEqualNode::Evaluate()
{
	if (mLhs->Evaluate() != mRhs->Evaluate())
		return 1;
	return 0;
}

IfStatementNode::IfStatementNode(ExpressionNode* en, StatementNode* sn)
{
	mExpression = en;
	mStatement = sn;
}

IfStatementNode::~IfStatementNode()
{
	delete mExpression;
	delete mStatement;
}

void IfStatementNode::Interpret()
{
	if (mExpression->Evaluate()) {
		mStatement->Interpret();
	}
}

WhileStatementNode::WhileStatementNode(ExpressionNode* en, StatementNode* sn)
{
	mExpression = en;
	mStatement = sn;
}

WhileStatementNode::~WhileStatementNode()
{
	delete mExpression;
	delete mStatement;
}

void WhileStatementNode::Interpret()
{
	while (mExpression->Evaluate()) {
		mStatement->Interpret();
	}
}
