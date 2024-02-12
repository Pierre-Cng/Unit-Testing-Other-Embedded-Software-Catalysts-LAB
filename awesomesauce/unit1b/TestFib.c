#include "unity.h"
#include "Fib.h"
#include <limits.h>

#define DIMENSION_OF(a) (sizeof(a)/sizeof(a[0]))

void test_element0_should_return1(void)
{
    TEST_ASSERT_EQUAL_INT(1, Fibonacci_GetElement(0));
}

void test_element1_should_return1(void)
{
    TEST_ASSERT_EQUAL_INT(1, Fibonacci_GetElement(1));
}

void test_element2_should_return2(void)
{
    TEST_ASSERT_EQUAL_INT(2, Fibonacci_GetElement(2));
}

void test_part_of_the_sequence(void)
{
    int expected[] = {1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144};
    int i;
    for (i=0; i < DIMENSION_OF(expected); i++){
        TEST_ASSERT_EQUAL_INT(expected[i], Fibonacci_GetElement(i));
    }
}

void test_that_negative_elements_return0(void)
{
    TEST_ASSERT_EQUAL_INT(0, Fibonacci_GetElement(-1));
    TEST_ASSERT_EQUAL_INT(0, Fibonacci_GetElement(-3));
    TEST_ASSERT_EQUAL_INT(0, Fibonacci_GetElement(-555));
    TEST_ASSERT_EQUAL_INT(0, Fibonacci_GetElement(INT_MIN));
}

void test_that_overrun_values_return0(void)
{
    const int first_bad_element = 46;
    const int last_good_element = first_bad_element - 1;
    int last_good_value = Fibonacci_GetElement(last_good_element);
    TEST_ASSERT_EQUAL_INT_MESSAGE(4, sizeof(int), 
        "Constant first_bad_element and FIB_MAX_ELEMENT must be changed");
    TEST_ASSERT_MESSAGE(last_good_value > 1, "This value should not have been a rollover");
    TEST_ASSERT_EQUAL_INT(0, Fibonacci_GetElement(first_bad_element));
    TEST_ASSERT_EQUAL_INT(0, Fibonacci_GetElement(INT_MAX));
}

void test_seq_element0_should_return0(void)
{
    TEST_ASSERT_EQUAL_INT(0, Fibonacci_IsInSequence(0));
}

void test_seq_element1_should_return1(void)
{
    TEST_ASSERT_EQUAL_INT(1, Fibonacci_IsInSequence(1));
}

void test_seq_element2_should_return1(void)
{
    TEST_ASSERT_EQUAL_INT(1, Fibonacci_IsInSequence(2));
}

void test_seq_part_of_the_sequence(void)
{
    int expected[] = {1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144};
    int i;
    for (i=0; i < DIMENSION_OF(expected); i++){
        TEST_ASSERT_EQUAL_INT(1, Fibonacci_IsInSequence(expected[i]));
    }
}

void test_seq_that_negative_elements_return0(void)
{
    TEST_ASSERT_EQUAL_INT(0, Fibonacci_IsInSequence(-1));
    TEST_ASSERT_EQUAL_INT(0, Fibonacci_IsInSequence(-3));
    TEST_ASSERT_EQUAL_INT(0, Fibonacci_IsInSequence(-555));
    TEST_ASSERT_EQUAL_INT(0, Fibonacci_IsInSequence(INT_MIN));
}

void test_seq_that_overrun_values_return0(void)
{
    const int first_bad_element = 46;
    int first_bad_value = Fibonacci_GetElement(first_bad_element);
    const int last_good_element = first_bad_element - 1;
    int last_good_value = Fibonacci_GetElement(last_good_element);

    TEST_ASSERT_EQUAL_INT(1, Fibonacci_IsInSequence(last_good_value));
    TEST_ASSERT_EQUAL_INT(0, Fibonacci_IsInSequence(first_bad_value));
}

int main(void) {
    UNITY_BEGIN();

    RUN_TEST(test_element0_should_return1);
    RUN_TEST(test_element1_should_return1);
    RUN_TEST(test_element2_should_return2);
    RUN_TEST(test_part_of_the_sequence);
    RUN_TEST(test_that_negative_elements_return0);
    RUN_TEST(test_that_overrun_values_return0);

    RUN_TEST(test_seq_element0_should_return0);
    RUN_TEST(test_seq_element1_should_return1);
    RUN_TEST(test_seq_element2_should_return1);
    RUN_TEST(test_seq_part_of_the_sequence);
    RUN_TEST(test_seq_that_negative_elements_return0);
    RUN_TEST(test_seq_that_overrun_values_return0);

    return UNITY_END();
}
