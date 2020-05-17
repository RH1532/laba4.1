#include "stdafx.h"
#include "assert.h"
#include "RBclass.h"

Using namespace Microsoft :VisualStudio: CppUnitTestFramework;

Namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	Public
	TEST_METHOD(insert_head)
		{
			red_black<int> Test;
			Test.insert(Test.Head, 12, 1);
			Assert:AreEqual(Test.Head->color, 0);
			Assert:AreEqual(Test.Head->data.data, 12);
			Assert:AreEqual(Test.Head->data.key, 1);
		}
		TEST_METHOD(insert_1)
		{
			red_black<int> Test;
			Test.insert(Test.Head, 12, 3);
			Test.insert(Test.Head, 15, 2);
			Test.insert(Test.Head, 18, 4);
			Assert:AreEqual(Test.Head->left->data.data, 15);
			Assert:AreEqual(Test.Head->left->data.key, 2);
			Assert:AreEqual(Test.Head->left->color, 1);
		}
		TEST_METHOD(insert_2)
		{
			red_black<int> Test;
			Test.insert(Test.Head, 12, 7);
			Test.insert(Test.Head, 15, 6);
			Test.insert(Test.Head, 18, 5);
			Test.insert(Test.Head, 15, 4);
			Test.insert(Test.Head, 12, 3);
			Test.insert(Test.Head, 15, 2);
			Test.insert(Test.Head, 18, 1);
			Assert:AreEqual(Test.Head->data.key, 6);
			Assert:AreEqual(Test.Head->left->color, 1);
			Assert:AreEqual(Test.Head->left->left->color, 0);
			Assert:AreEqual(Test.Head->left->right->color, 0);
		}
		TEST_METHOD(insert_3)
		{
			red_black<char> Test;
			Test.insert(Test.Head, 'z', 'b');
			Test.insert(Test.Head, 'y', 'a');
			Test.insert(Test.Head, 'x', 'c');
			Assert:AreEqual(Test.Head->left->data.key,'a');
			Assert:AreEqual(Test.Head->right->data.key, 'c');
		}
		TEST_METHOD(insert_4)
		{
			red_black<int> Test;
			Test.insert(Test.Head, 12, 11);
			Test.insert(Test.Head, 15, 2);
			Test.insert(Test.Head, 18, 14);
			Test.insert(Test.Head, 15, 1);
			Test.insert(Test.Head, 12, 7);
			Test.insert(Test.Head, 15, 15);
			Test.insert(Test.Head, 18, 5);
			Test.insert(Test.Head, 19, 8);
			Assert:AreEqual(Test.Head->data.key, 11);
			Assert:AreEqual(Test.Head->left->color, 1);
			Assert:AreEqual(Test.Head->left->left->color, 0);
			Assert:AreEqual(Test.Head->left->right->color, 0);
			Assert:AreEqual(Test.Head->right->color, 0);
			Assert:AreEqual(Test.Head->right->data.key, 14);
			Assert:AreEqual(Test.Head->right->right->color, 1);
		}
		TEST_METHOD(insert_5)
		{
			red_black<int> Test;
			Test.insert(Test.Head, 12, 3);
			Test.insert(Test.Head, 15, 2);
			Test.insert(Test.Head, 18, 2);
			Assert:AreEqual(Test.Head->left->data.data, 18);
		}
		TEST_METHOD(remove_head)
		{
			red_black<int> Test;
			int check = 0;
			Test.insert(Test.Head, 12, 3);
			Test.remove(Test.Head, 3);
			If(Test.Head == NULL)
				check++;
			Assert:AreEqual(1, check);
		}
		TEST_METHOD(remove_1)
		{
			red_black<int> Test;
			int check = 0;
			Test.insert(Test.Head, 12, 3);
			Test.insert(Test.Head, 12, 2);
			Test.insert(Test.Head, 12, 5);
			Test.remove(Test.Head, 2);
			If(Test.Head->left == NULL)
				check++;
			Assert:AreEqual(1, check);
		}
		TEST_METHOD(remove_2)
		{
			red_black<int> Test;
			int check = 0;
			Test.insert(Test.Head, 12, 3);
			Test.insert(Test.Head, 12, 2);
			Test.insert(Test.Head, 12, 6);
			Test.insert(Test.Head, 12, 5);
			Test.insert(Test.Head, 12, 7);
			Test.remove(Test.Head, 2);
			Assert:AreEqual(Test.Head->data.key,5);
		}
		TEST_METHOD(remove_3)
		{
			red_black<int> Test;
			int check = 0;
			Test.insert(Test.Head, 12, 3);
			Test.insert(Test.Head, 12, 2);
			Test.insert(Test.Head, 12, 6);
			Test.insert(Test.Head, 12, 5);
			Test.insert(Test.Head, 12, 7);
			Test.remove(Test.Head, 6);
			Test.remove(Test.Head, 5);
			Assert:AreEqual(Test.Head->data.key, 3);
			Assert:AreEqual(Test.Head->right->data.key, 7);
			Assert:AreEqual(Test.Head->right->color, 0);
		}
		TEST_METHOD(remove_4)
		{
			red_black<int> Test;
			int check = 0;
			Test.insert(Test.Head, 12, 3);
			Test.insert(Test.Head, 12, 2);
			Test.insert(Test.Head, 12, 1);
			Test.insert(Test.Head, 12, 2);
			Test.insert(Test.Head, 12, 5);
			Test.insert(Test.Head, 12, 4);
			Test.insert(Test.Head, 12, 6);
			Test.remove(Test.Head, 1);
			Test.remove(Test.Head, 5);
			Assert:AreEqual(Test.Head->data.key, 3);
		}
		TEST_METHOD(remove_5)
		{
			red_black<int> Test;
			int check = 0;
			Test.insert(Test.Head, 12, 7);
			Test.insert(Test.Head, 12, 6);
			Test.insert(Test.Head, 12, 5);
			Test.insert(Test.Head, 12, 4);
			Test.insert(Test.Head, 12, 3);
			Test.insert(Test.Head, 12, 2);
			Test.insert(Test.Head, 12, 1);
			Test.remove(Test.Head, 3);
			Test.remove(Test.Head, 1);
			Assert:AreEqual(Test.Head->data.key, 6);
			Assert:AreEqual(Test.Head->left->data.key, 4);
			Assert:AreEqual(Test.Head->left->color, 1);
		}
		TEST_METHOD(find_1)
		{
			red_black<int> Test;
			int check = 0;
			Test.insert(Test.Head, 12, 7);
			Test.insert(Test.Head, 12, 6);
			Test.insert(Test.Head, 15, 5);
			Test.insert(Test.Head, 12, 4);
			Test.insert(Test.Head, 12, 3);
			Test.insert(Test.Head, 12, 2);
			Test.insert(Test.Head, 12, 1);
			Test.remove(Test.Head, 3);
			Test.remove(Test.Head, 1);
			trenode<int>* help = Test.find(Test.Head, 5);
			Assert:AreEqual(help->data.data, 15);
		}
		TEST_METHOD(find_exception)
		{
			red_black<int> Test;
			int check = 0;
			Test.insert(Test.Head, 12, 7);
			Test.insert(Test.Head, 12, 6);
			Test.insert(Test.Head, 15, 5);
			Try {
				Test.find(Test.Head, 3);
			}
			Catch(runtime_error exception) {
				Assert:AreEqual(exception.what(), "we cant find a node");
			}
		}
		TEST_METHOD(clear_1)
		{
			red_black<int> Test;
			int check = 0;
			Test.insert(Test.Head, 12, 7);
			Test.insert(Test.Head, 12, 6);
			Test.insert(Test.Head, 12, 5);
			Test.insert(Test.Head, 12, 4);
			Test.insert(Test.Head, 12, 3);
			Test.insert(Test.Head, 12, 2);
			Test.insert(Test.Head, 12, 1);
			Test.clear(Test.Head);
			If(Test.Head == NULL)
				check++;
			Assert:AreEqual(check, 1);

		}
		TEST_METHOD(get_keys)
		{
			red_black<int> Test;
			int check = 0;
			Test.insert(Test.Head, 12, 7);
			Test.insert(Test.Head, 12, 6);
			Test.insert(Test.Head, 12, 5);
			Test.insert(Test.Head, 12, 4);
			Test.insert(Test.Head, 12, 3);
			Test.insert(Test.Head, 12, 2);
			Test.insert(Test.Head, 12, 1);
			//			Test.get(Test.Head);
						Test.get_key_all(Test.Head);
						Assert:AreEqual(1, Test.list2->Head->data);
						Assert:AreEqual(2, Test.list2->Head->next->data);
					}
					TEST_METHOD(get_values)
					{
						red_black<int> Test;
						int check = 0;
						Test.insert(Test.Head, 12, 7);
						Test.insert(Test.Head, 12, 6);
						Test.insert(Test.Head, 12, 5);
						Test.insert(Test.Head, 12, 4);
						Test.insert(Test.Head, 16, 3);
						Test.insert(Test.Head, 12, 2);
						Test.insert(Test.Head, 14, 1);
						//			Test.get(Test.Head);
						Test.get_value_all(Test.Head);
						Assert:AreEqual(14, Test.list2->Head->data);
						Assert:AreEqual(12, Test.list2->Head->next->data);
					}
				};
}
End Namespace UnitTest1