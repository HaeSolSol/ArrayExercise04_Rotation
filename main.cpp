#include <iostream>

int block1[3][3]
{
	{0, 1, 0},
	{0, 1, 1},
	{0, 1, 0}
};

int block2[3][3]{};
bool input;

void ShowBlock()
{
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			std::cout << block1[i][j] << " ";
		}
		std::cout << "\n";
	}
	std::cout << "\n";
}

void Question()
{
	std::cout << "Command (Left 0, Right 1) : ";
	std::cin >> input;
	std::cout << "\n";
}

void TurnLeft()
{
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			block2[i][j] = block1[j][2 - i];
		}
	}
}

void TurnRight()
{
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			block2[i][j] = block1[2 - j][i];
		}
	}
}

void Block2toBlock1()
{
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			block1[i][j] = block2[i][j];
		}
	}
}

int main()
{
	while (true)
	{
		enum Turn
		{
			L = 0,
			R = 1
		};

		ShowBlock();
		Question();

		switch (input)
		{
		case L:
			TurnLeft();
			Block2toBlock1();
			break;
		case R:
			TurnRight();
			Block2toBlock1();
			break;
		}
	}
}