#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <strstream>
using namespace std;
string ERR_INFO = "404";
string INT_INFO = "/<int>";
string STR_INFO = "/<str>";
string PATH_INFO = "/<path>";
struct THE_STR_INFO
{
	string str;
	string type;
	vector<string> rules;
	int num_rules;
};

vector<THE_STR_INFO> str_rule;
vector<THE_STR_INFO> str_input;
void seperate_str(int i, vector<THE_STR_INFO> &inputinfo);
string match_str(int i);
bool isint(string &inputstr);
int convertStringToInt(const string &s);
string convertIntToString(const int val);

int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
	{
		THE_STR_INFO tmpinfo;
		str_rule.push_back(tmpinfo);
		cin >> str_rule.at(i).str >> str_rule.at(i).type;
		seperate_str(i, str_rule);
	}
	for (int i = 0; i < m; ++i)
	{
		THE_STR_INFO tmpinfo;
		str_input.push_back(tmpinfo);
		cin >> str_input.at(i).str;
		seperate_str(i, str_input);
	}
	string ans = "";
	for (int i = 0; i < m; ++i)
	{
		string tmpans = match_str(i);
		ans += tmpans;
	}
	cout << ans;
	//system("pause");
	return 0;
}
void seperate_str(int i, vector<THE_STR_INFO> &inputinfo)
{
	int loc = 0, preloc = 0;
	int num = 0;
	while (true)
	{
		++loc;
		if (loc >= inputinfo.at(i).str.size())
		{
			inputinfo.at(i).rules.push_back(inputinfo.at(i).str.substr(preloc, loc - preloc));
			++num;
			break;
		}
		if (inputinfo.at(i).str.at(loc) == '/')
		{
			inputinfo.at(i).rules.push_back(inputinfo.at(i).str.substr(preloc, loc - preloc));
			++num;
			preloc = loc;
		}
	}
	inputinfo.at(i).num_rules = num;
}
string match_str(int i)
{
	string ret_str = "";
	bool isOK = false;
	for (int n = 0; n < str_rule.size(); ++n)
	{
		if (str_rule.at(n).num_rules > str_input.at(i).num_rules)
			continue;
		bool tmpOK = true, ispath = false;
		ret_str = str_rule.at(n).type;
		for (int j = 0; j < str_rule.at(n).num_rules; ++j)
		{
			if (str_rule.at(n).rules.at(j) == INT_INFO)
			{
				string tmpstr = str_input.at(i).rules.at(j).substr(1, str_input.at(i).rules.at(j).size() - 1);
				bool tmpflag = isint(tmpstr);
				if (tmpflag == true)
				{
					int num = convertStringToInt(tmpstr);
					ret_str += (" " + convertIntToString(num));
				}
				else
				{
					tmpOK = false;
					break;
				}
			}
			else if (str_rule.at(n).rules.at(j) == STR_INFO)
				ret_str += (" " + str_input.at(i).rules.at(j).substr(1, str_input.at(i).rules.at(j).size() - 1));
			else if (str_rule.at(n).rules.at(j) == PATH_INFO)
			{
				ret_str += (" " + str_input.at(i).rules.at(j).substr(1, str_input.at(i).rules.at(j).size() - 1));
				for (int k = j + 1; k < str_input.at(i).num_rules; ++k)
					ret_str += str_input.at(i).rules.at(k);
				ispath = true;
				break;
			}
			else
			{
				if (str_rule.at(n).rules.at(j) == str_input.at(i).rules.at(j))
					continue;
				tmpOK = false;
				break;
			}
		}
		if ((str_input.at(i).num_rules != str_rule.at(n).num_rules) && (ispath == false))
			continue;
		if (tmpOK == true)
		{
			isOK = true;
			break;
		}
	}
	if (isOK == false)
		ret_str = ERR_INFO;
	return ret_str + "\n";
}
bool isint(string &inputstr)
{
	for (int i = 0; i < inputstr.size(); ++i)
		if (inputstr.at(i) < '0' || inputstr.at(i) > '9')
			return false;
	return true;
}
string convertIntToString(const int val)
{
	string s;
	strstream ss;
	ss << val;
	ss >> s;
	return s;
}
int convertStringToInt(const string &s)
{
	int val;
	std::strstream ss;
	ss << s;
	ss >> val;
	return val;
}