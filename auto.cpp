#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

#define __CPP11__
using namespace std;



void displayVector(std::vector<int> v) 
{
#ifndef __CPP11__
	for (int i = 0; i < 11; i++)
	{
		cout << i << endl;
	}

	for (std::vector<int>::iterator itr = v.begin(); itr != v.end(); itr++)
	{
		cout << *itr << endl;
	}

#else
	//use auto in for loop
	cout << "Auto with for loop" << endl;
	for (auto i = 0; i < 5; i++)
	{
		cout << i << endl;
	}

	//auto with range based for loop
	cout << "Auto with range based for loop" << endl;
	for (auto itr : v)
		cout << itr << endl;

	//auto with for loop & stl container
	cout << "Auto with for loop & stl contaner" << endl;
	for (auto itr = v.begin(); itr != v.end(); itr++)
	{
		cout << *itr << endl;
	}

	//for_each & lambda algorithm with auto key word
	cout << "Auto with for_each and lambda" << endl;
	for_each(v.begin(), v.end(), [](auto itr) {
		itr += 10;
		cout << itr << endl;
	});

	//Lambda with auto 
	cout << "Auto with simple lambda" << endl;
	auto lam_val = [](int x) { return x + 5; };
	cout << "lambda with auto value : " << lam_val(55) << endl;
#endif
}


/*---------- Template Bsed Function with Auto ------------*/
#ifndef __CPP11__
template<typename U, typename V>
int add(U u, V v)
{
	cout << "function with int return type arguments : " << typeid(u).name() << " ," << typeid(v).name() << endl;
	return (u + v);
}

template<typename U, typename V>
double add1(U u, V v)
{
	cout << "function with double return and type arguments : " << typeid(u).name() << " ," << typeid(v).name() << endl;
	return (u + v);
}
template<typename U, typename V>
long add1(U u, V v)
{
	cout << "function with long return and type arguments : " << typeid(u).name() << " ," << typeid(v).name() << endl;
	return (u + v);
}
#else

template<typename U, typename V>
auto add(U u, V v) -> decltype(u+v)
{
	cout << "function with auto return type and type arguments : " << typeid(u).name() << " ," << typeid(v).name() << endl;
	return (u + v);
}
#endif
