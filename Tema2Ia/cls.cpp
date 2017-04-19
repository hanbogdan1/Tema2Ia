#include "cls.h"

void cls::citire_date()
{
	int x;

	while (f >> x)
	{
		initial_values.push_back(x);
	}

	final_form.assign(initial_values.begin(), initial_values.end());
	sort(final_form.begin(), final_form.end());
}


bool cls::solutie()
{
	return final_form == initial_values;
}
