#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <queue>


struct comparator
{
	bool operator()(const std::vector<int> a, const std::vector<int> b)
	{
		return cmp_vect(a, b);
	}


	bool cmp_vect(std::vector<int> a, std::vector<int> b)
	{
		std::cout << "da";
		if (calculare_cardinal_coada(a) > calculare_cardinal_coada(b))
			return true;
		return false;
	}

	int calculare_cardinal_coada(std::vector<int> vect)
	{
		auto ret = 0;
		for (auto i = vect.begin(); i != vect.end() - 1; ++i)
		{
			if (*i > *(i + 1))
				return ret;
			ret++;
		}
		return ret;
	}
};


class cls
{
	std::vector<int> initial_values;
	std::priority_queue<std::vector<int>, std::vector<std::vector<int>>, comparator> coada;
	std::ifstream f;
	std::vector<int> final_form;

public:
	cls()
	{
		f.open("inp.txt", std::ifstream::in);

		std::vector<int> a;

		a.push_back(1);
		a.push_back(2);
		a.push_back(3);
		a.push_back(2);
		a.push_back(3);


		std::vector<int> b;

		b.push_back(1);
		b.push_back(2);
		b.push_back(3);
		b.push_back(4);
		b.push_back(5);

		std::vector<int> c;

		c.push_back(1);
		c.push_back(2);
		c.push_back(0);
		c.push_back(2);
		c.push_back(3);


		coada.push(a);
		coada.push(b);
		coada.push(c);


		for (int i = 1; i <= 3; i++)
		{
			auto x = coada.top();
			coada.pop();
			std::cout << std::endl;
			for (auto y:x)
			{
				std::cout << y << " ";
			}
		}


		int y;
		std::cin >> y;
	}

	~cls()
	{
		f.close();
	}

	void citire_date();
	bool solutie();
};
