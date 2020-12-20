#include "pch.h"
#include "CppUnitTest.h"
#include "D:\Прога 3 сем лабы\Лаба 3\лаба 3\Heap.cpp"
//#include "D:\Прога 3 сем лабы\Лаба 3\лаба 3\Heap.h"
#include "D:\Прога 3 сем лабы\Лаба 3\лаба 3\LinkedList.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(Insert)
		{
			Heap bh;
			bh.insert(1);
			bh.insert(0);
			bh.insert(2);
			Assert::AreEqual(bh.contains(0), true);
			Assert::AreEqual(bh.contains(1), true);
			Assert::AreEqual(bh.contains(2), true);
		}

		TEST_METHOD(Contains1)
		{
			Heap bh;
			bh.insert(1);
			bh.insert(0);
			bh.insert(2);
			Assert::AreEqual(bh.contains(0), true);
		}

		TEST_METHOD(Contains2)
		{
			Heap bh;
			bh.insert(1);
			bh.insert(0);
			bh.insert(2);
			Assert::AreEqual(bh.contains(4), false);
		}

		TEST_METHOD(Contains3)
		{
			Heap bh;
			Assert::AreEqual(bh.contains(0), false);
		}

		TEST_METHOD(Remove1)
		{
			Heap bh;
			bh.insert(1);
			bh.insert(0);
			bh.insert(2);
			bh.remove(0);
			Assert::AreEqual(bh.contains(0), false);
		}

		TEST_METHOD(Remove2)
		{
			Heap bh;
			try
			{
				bh.remove(0);
			}
			catch (const char* exception)
			{
				Assert::AreEqual(exception, "There is no such element");
			}
		}

		TEST_METHOD(BFT_iterator1)
		{
			Heap bh;
			bh.insert(1);
			bh.insert(0);
			bh.insert(2);
			bh.insert(4);
			bh.insert(3);
			Iterator* it = bh.create_bft_iterator();
			for (int i = 0; i < 5; i++) {
				Assert::AreEqual(it->next(), bh.heap[i]);
			}
		}

		TEST_METHOD(BFT_iterator2)
		{
			Heap bh;
			Iterator* it = bh.create_bft_iterator();
			try
			{
				it->has_next();
			}
			catch (const char* exception)
			{
				Assert::AreEqual(exception, "No more elements");
			}
		}

		TEST_METHOD(DFT_iterator1)
		{
			Heap bh;
			bh.insert(1);
			bh.insert(0);
			bh.insert(2);
			bh.insert(4);
			bh.insert(3);
			int check[5] = {0, 1, 4, 3, 2};
			Iterator* it = bh.create_dft_iterator();
			for (int i = 0; i < 5; i++) {
				Assert::AreEqual(it->next(), check[i]);
			}
		}

		TEST_METHOD(DFT_iterator2)
		{
			Heap bh;
			Iterator* it = bh.create_dft_iterator();
			try
			{
				it->has_next();
			}
			catch (const char* exception)
			{
				Assert::AreEqual(exception, "No more elements");
			}
		}
	};
}
