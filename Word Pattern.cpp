vector<string> split_str(string const &str)
{	
	istringstream iss{ str };
	vector<string> v;
	string substr;
	while (getline(iss, substr, ' '))
	{
		v.push_back(substr);
	}

	return v;
}


class Solution {
public:
	bool wordPattern(string pattern, string str) {
		unordered_map<char, string> dict;
		auto v = split_str(str);
		bool ret = false;

		if (pattern.length() != v.size())
		{
			return false;
		}

		for (auto i = 0U; i < pattern.length(); ++i)
		{
			char ch = pattern[i];
			auto itr = dict.find(ch);
			if (itr == dict.end())
			{
				//
				auto itr2 = find_if(dict.begin(), dict.end(), [&](unordered_map<char, string>::value_type const &t)
				{
					return t.second == v[i];
				});
				if (itr2 != dict.end())
				{
					return false;
				}

				dict[ch] = v[i];
			}
			else
			{
				if (dict[ch] != v[i])
				{
					return false;
				}
			}
		}

		return true;
	}
};