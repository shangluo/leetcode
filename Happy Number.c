bool isHappy(int n) {

	bool isHappyNumber = false;

	int num = n;
	while (true)
	{
		int result = 0;
		while (num)
		{
			result += (num % 10) * (num % 10);
			num /= 10;
		}

		if (result == 1)
		{
			isHappyNumber = true;
			break;
		}

		if (result == 4)
		{
			break;
		}

		num = result;
	}

	return isHappyNumber;
}
