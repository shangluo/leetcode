// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
	bool isFirstBadVersion(int n)
	{
		return n == 1 && isBadVersion(n) || !isBadVersion(n - 1) && isBadVersion(n);
	}

	int firstBadVersion(int n) {
		unsigned int low = 1;
		unsigned int high = n;
		int first = 1;
		while (low <= high)
		{
			int mid = (low + high) / 2;
			if (isFirstBadVersion(mid))
			{
				first = mid;
				break;
			}
			else if (isBadVersion(mid))
			{
				high = mid;
			}
			else
			{
				low = mid + 1;
			}
		}

		return first;
	}
};