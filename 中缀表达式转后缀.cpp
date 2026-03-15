//#include<iostream>
//#include<string>
//#include<stack>
//using namespace std;
//
//
//bool Priority(char ch, char topch)
//{
//	if ((ch == '*' || ch == '/') && (topch == '+' || topch == '-'))
//		return true;
//	if (topch == '(' && ch != ')')
//		return true;
//	return false;
//}
//
//string MiddleToEndExpr(string exper)
//{
//	string result;
//	stack<char> s;
//	for (char ch : exper)
//	{
//		if (ch >= '0' && ch <= '9')
//		{
//			result.push_back(ch);
//		}
//		else
//		{
//
//
//			while (1)
//			{
//				if (s.empty() || ch == '(')
//				{
//					s.push(ch);
//					break;
//				}
//				char topch = s.top();
//				if (Priority(ch, topch))
//				{
//					s.push(ch);
//					break;
//				}
//				else
//				{
//					s.pop();
//
//					if (topch == '(')
//						break;
//					result.push_back(topch);
//				}
//			}
//
//
//		}
//
//	}
//	while (!s.empty())
//	{
//		result.push_back(s.top());
//		s.pop();
//
//	}
//	return result;
//}
//
//int main()
//{
//	//cout << MiddleToEndExpr("(1+2)*(3+4)") << endl;
//	cout << MiddleToEndExpr("2+(4+6)/2+6/3") << endl;
//
//}