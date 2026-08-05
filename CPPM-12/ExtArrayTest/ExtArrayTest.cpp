#include "CppUnitTest.h"
#include "extended_array.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ExtArrayTest {
	TEST_CLASS(ExtArrayTest) {
	public:
		TEST_METHOD(Mean) {
			ExtArray<int> v1{};
			Assert::AreEqual(v1.mean(), 0.0);
		}
		TEST_METHOD(MeanStartEnd) {
			ExtArray<int> v1{ 0, 1, 2, 3, 4, 5, 6, 7 };
			Assert::AreEqual(v1.mean(2, 5), 3.5);
			Assert::AreEqual(v1.mean(4, 4), 4.0);;
			Assert::ExpectException<std::invalid_argument>([&]() {v1.mean(5, 2); });
			Assert::ExpectException<std::invalid_argument>([&]() {v1.mean(-1, 5); });
			Assert::ExpectException<std::invalid_argument>([&]() {v1.mean(0, 0); });
			Assert::ExpectException<std::invalid_argument>([&]() {v1.mean(12, 13); });
			Assert::ExpectException<std::invalid_argument>([&]() {v1.mean(0, 13); });
		}
		TEST_METHOD(Median) {
			ExtArray<double> v1{};
			Assert::AreEqual(v1.median(), 0.0);
		}
		TEST_METHOD(Mode) {
			ExtArray<int> v1{};
			auto result = v1.mode();
			Assert::AreEqual(result.first, 0);
			Assert::AreEqual(result.second, 0);
		}
		TEST_METHOD(CheckSum) {
			ExtArray<int> v_empty{};
			ExtArray<int> v_int_empty{};
			ExtArray<bool> v_bool_empty{};
			ExtArray<double> v_double_empty{};
			ExtArray<int> v_int_wrong{0, 1, 2, 3, 0, 1};
			ExtArray<bool> v_bool{ 0, 1, 0, 1, 1, 1 };
			ExtArray<bool> v_int{0, 1, 0, 1, 1, 1 };
			ExtArray<double> v_double{0.0, 1.0, 0.0, 1.0, 1.0, 1.0};

			Assert::AreEqual(v_empty.checkSum(), 0);
			Assert::AreEqual(v_int_empty.checkSum(), 0);
			Assert::AreEqual(v_bool_empty.checkSum(), 0);
			Assert::AreEqual(v_bool.checkSum(), 4);
			Assert::AreEqual(v_int.checkSum(), 4);

			Assert::ExpectException<std::bad_typeid>([&]() {v_double_empty.checkSum(); });
			Assert::ExpectException<std::bad_typeid>([&]() {v_double.checkSum(); });
			
			Assert::ExpectException<std::logic_error>([&]() {v_int_wrong.checkSum(); });
		}
	};
}
