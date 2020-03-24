#include "Scanner.h"
#include "Symbol.h"
#include "Node.h"
#include <iostream>
#include "Parser.h"

int main() {
	ScannerClass scanner = ScannerClass("data.txt");
	SymbolTableClass st;
	ParserClass pc = ParserClass(&scanner, &st);
	StartNode* sn = pc.Start();
	sn->Interpret();
	delete sn;

	/*while (true){
		TokenClass tc = scanner.PeekNextToken();
		TokenClass tc2 = scanner.GetNextToken();
		tc.CheckReserved();
		std::cout<< scanner.GetLineNumber() << " "<< tc << "\n" << endl;
		if (tc.GetTokenType() == ENDFILE_TOKEN)
			break;
		}*/
	
	///*while (true)*/ {
	//	TokenClass tc = scanner.PeekNextToken();
	//	TokenClass tc2 = scanner.GetNextToken();
	//	tc.CheckReserved();
	//	std::cout<< scanner.GetLineNumber() << " "<< tc << "\n" << endl;
	//	if (tc.GetTokenType() == ENDFILE_TOKEN)
	//		break;
	//}

	/*SymbolTableClass st;
	IntegerNode* intN35 = new IntegerNode(35);
	IntegerNode* intN50 = new IntegerNode(50);
	IntegerNode* intN352 = new IntegerNode(35);
	IntegerNode* intN502 = new IntegerNode(50);
	IdentifierNode* sum = new IdentifierNode("sum", &st);
	IdentifierNode* product = new IdentifierNode("product", &st);
	IdentifierNode* difference = new IdentifierNode("difference", &st);
	PlusNode* sumvalue = new PlusNode(intN35, intN50);
	MinusNode* diffvalue = new MinusNode(intN352, intN502);
	TimesNode* productvalue = new TimesNode(intN35, intN50);
	AssignmentStatementNode* sumassignment = new AssignmentStatementNode(sum, sumvalue);
	AssignmentStatementNode* productassignment = new AssignmentStatementNode(difference, diffvalue);
	StatementGroupNode* sgn = new StatementGroupNode();
	sgn->AddStatement(sumassignment);
	sgn->AddStatement(productassignment);
	BlockNode* bn = new BlockNode(sgn);
	ProgramNode* pn = new ProgramNode(bn);
	StartNode* sn = new StartNode(pn);
	delete sn;*/

	
	//st.AddEntry("sum");
	//st.SetValue("sum", 10);
	//st.AddEntry("prod");
	//st.SetValue("prod", 100);
	////cout << st.GetValue("div")<< endl;
	//cout << st.GetValue("sum") << endl;
	//cout << st.GetValue("prod") << endl;
	//cout << st.GetIndex("sum") << endl;

	//IntegerNode* a = new IntegerNode(4);
	//IntegerNode* b = new IntegerNode(5);
	//LessEqualNode* less = new LessEqualNode(a, b);
	//cout << less->Evaluate() << endl;
	//delete less;
	return 0;
}

