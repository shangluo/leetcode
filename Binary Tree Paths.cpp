class Solution {
public:
	string simplifyPath(string path) {
		deque<string> pathStack;

		string subPath;
		int prev = 0;
		while (true)
		{
			auto index = path.find("/", prev);
			if (index > 0)
			{
				subPath = path.substr(prev, index - prev);

				if (subPath == "..")
				{
					if (!pathStack.empty())
					{
						pathStack.pop_back();
					}
				}
				else if (!subPath.empty() && subPath != ".")
				{
					pathStack.push_back(subPath);
				}
			}

			if (index == string::npos)
			{
				break;
			}

			prev = index + 1;
		}

		// convert stack to path
		string simplifiedPath;
		
		if (pathStack.empty())
		{
		    return "/";
		}

		for (auto &str : pathStack)
		{
			simplifiedPath += '/';
			simplifiedPath += str;
		}


		return simplifiedPath;
	}
};