#include "unity.h"
#include "contactmanagementsystem.h"
/* Required by the unity test framework */
void setUp(){}
/* Required by the unity test framework */
void tearDown(){}


void test_ADD_CONTACT(void)
	{
  		TEST_ASSERT(ADD_CONTACT("bandari",123,"hyd","b.m@gmailcom"));
	}
void test_VIEW_CONTACT(void)
{
    TEST_ASSERT(VIEW_CONTACT("bandari",123,"hyd","b.m@gmailcom"));
}
void test_SEARCH_CONTACT(void)
{
    TEST_ASSERT(SEARCH_CONTACT("bandari",123,"hyd","b.m@gmailcom"));
}
void test_EDIT_CONTACT(void)
{
    TEST_ASSERT(EDIT_CONTACT("bandari",123,"hyd","b.m@gmailcom"));
}
void test_DELETE_CONTACT(void)
{
    TEST_ASSERT(DELETE_CONTACT("manushnabandari",123,"hyd","b.m@gmailcom"));
}
int test_main(void)
{
/* Initiate the Unity Test Framework */
  UNITY_BEGIN();

/* Run Test functions */
  RUN_TEST(test_ADD_CONTACT);
  RUN_TEST(test_VIEW_CONTACT);
  RUN_TEST(test_SEARCH_CONTACT);
  RUN_TEST(test_EDIT_CONTACT);
  RUN_TEST(test_DELETE_CONTACT);

  /* Close the Unity Test Framework */
  return UNITY_END();
}
