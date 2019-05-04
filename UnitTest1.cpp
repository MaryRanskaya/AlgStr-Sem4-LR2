#include "pch.h"
#include "cassert"
#include "CppUnitTest.h"
#include "../project_2/Map_class.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest_Int_Int)
	{
	private:
		Map<int, int> IntKeyMap;
	public:
		
		TEST_METHOD(insert_InEmptyMap)
		{
			IntKeyMap.insert(1,10);

			Assert::IsTrue(IntKeyMap.find(10)->data == 1 && IntKeyMap.find(10)->color == black);
		}

		TEST_METHOD(insert_OneNodeInMap)
		{
			IntKeyMap.insert(1, 10);
			IntKeyMap.insert(2, 9);

			Assert::IsTrue(IntKeyMap.find(9)->parent == IntKeyMap.find(10) && IntKeyMap.find(9)->color == red);
		}

		TEST_METHOD(find_OneNodeInMap)
		{
			IntKeyMap.insert(15, 89);

			Assert::IsTrue(IntKeyMap.find(89)->data == 15 && IntKeyMap.find(89)->color == black);
		}

		TEST_METHOD(find_SeveralNodes)
		{
			IntKeyMap.insert(15, 89);
			IntKeyMap.insert(16, 79);
			IntKeyMap.insert(17, 69);
			IntKeyMap.insert(18, 59);

			Assert::IsTrue(IntKeyMap.find(59)->data == 18);
		}

		TEST_METHOD(remove_root)
		{
			IntKeyMap.insert(15, 80);

			IntKeyMap.remove(80);

			Assert::IsTrue(IntKeyMap.GetRoot() == nullptr);
		}

		TEST_METHOD(remove_has2leaves)
		{
			IntKeyMap.insert(15, 80);
			IntKeyMap.insert(16, 10);

			IntKeyMap.remove(10);

			Assert::IsTrue(IntKeyMap.GetRoot() == IntKeyMap.find(80) && IntKeyMap.find(80)->left == nullptr && IntKeyMap.find(80)->right == nullptr);
		}

		TEST_METHOD(remove_OneChild_OneLeaf)
		{
			IntKeyMap.insert(1, 11);
			IntKeyMap.insert(2, 2);
			IntKeyMap.insert(3, 14);
			IntKeyMap.insert(4, 15);
			IntKeyMap.insert(5, 1);
			IntKeyMap.insert(6, 7);

			IntKeyMap.remove(14);

			Assert::IsTrue(IntKeyMap.GetRoot() == IntKeyMap.find(11) && IntKeyMap.find(11)->left == IntKeyMap.find(2) && IntKeyMap.find(11)->right == IntKeyMap.find(15));
		}

	};

	TEST_CLASS(UnitTest_Char_Char)
	{
	private:
		Map<char, char> CharKeyMap;
	public:

		TEST_METHOD(insert_InEmptyMap)
		{
			CharKeyMap.insert('a','k');

			Assert::IsTrue(CharKeyMap.find('k')->data == 'a' && CharKeyMap.find('k')->color == black);
		}

		TEST_METHOD(insert_OneNodeInMap)
		{
			CharKeyMap.insert('a', 'k');
			CharKeyMap.insert('b', 'q');

			Assert::IsTrue(CharKeyMap.find('q')->parent == CharKeyMap.find('k') && CharKeyMap.find('q')->color == red);
		}

		TEST_METHOD(find_OneNodeInMap)
		{
			CharKeyMap.insert('e', '9');

			Assert::IsTrue(CharKeyMap.find('9')->data == 'e' && CharKeyMap.find('9')->color == black);
		}

		TEST_METHOD(find_SeveralNodes)
		{
			CharKeyMap.insert('0', 'v');
			CharKeyMap.insert('9', 'u');
			CharKeyMap.insert('8', 'y');
			CharKeyMap.insert('7', 't');

			Assert::IsTrue(CharKeyMap.find('y')->data == '8');
		}
	};

	TEST_CLASS(UnitTest_Float_Char)
	{
	private:
		Map<float, char> CharKeyFlDataMap;
	public:

		TEST_METHOD(insert_InEmptyMap)
		{
			CharKeyFlDataMap.insert(1.89, 'a');

			Assert::IsTrue(CharKeyFlDataMap.find('a')->data == (float)1.89 && CharKeyFlDataMap.find('a')->color == black);
		}

		TEST_METHOD(insert_OneNodeInMap)
		{
			CharKeyFlDataMap.insert(1.89, 'b');
			CharKeyFlDataMap.insert(2.78, 'c');

			Assert::IsTrue(CharKeyFlDataMap.find('c')->parent == CharKeyFlDataMap.find('b') && CharKeyFlDataMap.find('c')->color == red);
		}

	    TEST_METHOD(find_OneNodeInMap)
		{
			CharKeyFlDataMap.insert(15.678, '1');

			Assert::IsTrue(CharKeyFlDataMap.find('1')->data == (float)15.678 && CharKeyFlDataMap.find('1')->color == black);
		}

	    TEST_METHOD(find_SeveralNodes)
		{
			CharKeyFlDataMap.insert(15.1, '1');
			CharKeyFlDataMap.insert(16.2, '3');

			Assert::IsTrue(CharKeyFlDataMap.find('3')->data == (float)16.2);
		}

		TEST_METHOD(remove_root)
		{
			CharKeyFlDataMap.insert(15.895, '+');

			CharKeyFlDataMap.remove('+');

			Assert::IsTrue(CharKeyFlDataMap.GetRoot() == nullptr);
		}

	   	TEST_METHOD(remove_has2leaves)
		{
			CharKeyFlDataMap.insert(15.667, 'v');
			CharKeyFlDataMap.insert(16.773, 'w');

			CharKeyFlDataMap.remove('w');

			Assert::IsTrue(CharKeyFlDataMap.GetRoot() == CharKeyFlDataMap.find('v') && CharKeyFlDataMap.find('v')->left == nullptr && CharKeyFlDataMap.find('v')->right == nullptr);
		}
	};
}
