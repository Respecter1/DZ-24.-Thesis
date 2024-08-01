#include <iostream>
#include <string>
#include "BinaryTree.h"



template <typename T>
void ShowValue(const T& value)
{
	std::cout << value << " ";
}

template <typename T>
void Show(const BinaryTree<T>& tree)
{
	std::cout << "Tree elements: ";
	tree.DoForAllElements(ShowValue<T>);
	std::cout << std::endl;
}

class Sum
{
public:

	static void Add(double value)
	{
		sum += value;
	}
	static double sum;
};

double Sum::sum = 0.0;

int main()
{
#pragma region Constructors
	{
		std::cout << "--- Constructors ---\n";

		BinaryTree<int> tree1;							// default constructor
		Show(tree1);

		BinaryTree<int> tree2{ 10,1,8,2,8,3 };			// std::initializer_list constructor
		Show(tree2);

		BinaryTree<int> tree3(tree2);					// copy constructor
		Show(tree3);

		BinaryTree<int> tree4(std::move(tree3));		// move constructor
		Show(tree4);
		Show(tree3);
	}
#pragma endregion

#pragma region Operators =
	{
		std::cout << "\n --- Operators = --- \n";

		BinaryTree<int> tree1{ 1,2,3,4,5 };
		BinaryTree<int> tree2{ 10,20,30 };

		Show(tree1);
		Show(tree2);

		tree2 = tree1; // copy assigment operator

		Show(tree1);
		Show(tree2);

		BinaryTree<int> tree3{ 11,22,33,44,55 };
		BinaryTree<int> tree4{ 100,200,300 };

		tree4 = std::move(tree3); // move assiment operator

		Show(tree3);
		Show(tree4);
	}
#pragma endregion

#pragma region MyRegion
	//Methods:
	//{
	//	std::cout << "\n --- Methods --- \n";

	//	BinaryTree<double> tree1{ 1.1,2.2,3.3,4.4,5.5 };

	//	if (!tree1.IsEmpty())// Method #1
	//	{
	//		std::cout << "Tree #1 isn't empty.\n";
	//	}

	//	std::cout << "Size of Tree #1 = " << tree1.Size() << std::endl; // Method #2

	//	tree1.Clear(); // Method #3

	//	if (tree1.IsEmpty())
	//	{
	//		std::cout << "Tree #1 is empty now.\n";
	//	}

	//	tree1.Insert(10.5);// method #4
	//	tree1.Insert(2.8);
	//	tree1.Insert(1.2);
	//	tree1.Insert(3.6);
	//	tree1.Insert(7.8);


	//	std::cout << "Tree #1 elements: ";
	//	tree1.DoForAllElements(ShowValue<double>);// method #5

	//	const double* foundValue = tree1.Find(2.8);// method #6
	//	if (foundValue != nullptr)
	//	{
	//		std::cout << "\nTree #1 has " << *foundValue << std::endl;
	//	}

	//	tree1.Delete(32.1); // method #7
	//	tree1.Delete(2.8);

	//	std::cout << "Tree #1 elements: ";
	//	tree1.DoForAllElements(ShowValue<double>);

	//	
	//}
#pragma endregion

#pragma region задача як знайти суму
	std::cout << "\n\n";
	/*
		через глобальну змінну можна та функцію
	tree1.DoForAllElements(Add);

	std::cout << "\nSum = ";
	std::cout << sum << std::endl;*/
	BinaryTree<int> tree2{ 10,1,8,2,8,3 };
	Show(tree2);

	tree2.DoForAllElements(Sum::Add);
	std::cout << "\nSum = ";
	std::cout << Sum::sum << std::endl;

	// ще можно викртись через лямбда функції 
	double sum1 = 0.0;
	tree2.DoForAllElements([&sum1](int value) {sum1 += value; });
	std::cout << "\nSum = ";
	std::cout << sum1 << std::endl;

	// ще можно викртись через лямбда функції + auto
	auto function = [&sum1](int value) {sum1 += value; };
	tree2.DoForAllElements(function);
	std::cout << "\nSum = ";
	std::cout << sum1 << std::endl;
#pragma endregion

}