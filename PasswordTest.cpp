/**
 * Unit Tests for Password class
**/

#include <gtest/gtest.h>
#include "Password.h"

class PasswordTest : public ::testing::Test
{
	protected:
		PasswordTest(){} //constructor runs before each test
		virtual ~PasswordTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};

TEST(PasswordTest, space_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters(" ");
	ASSERT_EQ(0, actual);
}

TEST(PasswordTest, empty_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("");
	ASSERT_EQ(0, actual);
}

TEST(PasswordTest, single_letter_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("Z");
	ASSERT_EQ(1, actual);
}

TEST(PasswordTest, multi_letter_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("ZZZ");
	ASSERT_EQ(3, actual);
}

TEST(PasswordTest, single_number_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("1");
	ASSERT_EQ(1, actual);
}

TEST(PasswordTest, multi_number_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("111");
}

TEST(PasswordTest, long_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("zABCDEFG");
	ASSERT_EQ(1, actual);
}

TEST(PasswordTest, long_number_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("123456");
	ASSERT_EQ(1, actual);
}

TEST(PasswordTest, long_mixed_case_same_letter_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("zZABCDEFG");
	ASSERT_EQ(1, actual);
}

TEST(PasswordTest, multi_char_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("zzz");
	ASSERT_EQ(3, actual);
}

TEST(PasswordTest, long_multi_char_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("zzzABCDEFG");
	ASSERT_EQ(3, actual);
}

TEST(PasswordTest, empty_password_mixed_case)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("");
	ASSERT_EQ(false, actual);
}

TEST(PasswordTest, space_password_mixed_case)
{
	Password my_password;
	bool actual = my_password.has_mixed_case(" ");
	ASSERT_EQ(false, actual);
}

TEST(PasswordTest, same_case_single_letter_password)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("zzzzzz");
	ASSERT_EQ(false, actual);
}

TEST(PasswordTest, same_case_multi_letter_password)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("abcdefg");
	ASSERT_EQ(false, actual);
}

TEST(PasswordTest, mixed_case_single_letter_password)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("zZzZzZz");
	ASSERT_EQ(true, actual);
}

TEST(PasswordTest, mixed_case_multi_letter_password)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("aBcDeFg");
	ASSERT_EQ(true, actual);
}
