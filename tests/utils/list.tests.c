#include <unity.h>

#include "utils/list.h"

void setUp() {}

void tearDown() {}

void can_create_list() {
    List* sut = list_create(1);

    TEST_ASSERT_TRUE(sut->count == 0);
    TEST_ASSERT_TRUE(sut->capacity == 1);

    TEST_ASSERT_NOT_NULL(sut);

    list_destroy(sut);
}

void can_add_one_item_to_list() {
    List* sut = list_create(1);

    uint32_t i = 3;
    list_add(sut, &i);

    TEST_ASSERT_TRUE(sut->count == 1);
    TEST_ASSERT_TRUE(sut->capacity == 1);
    TEST_ASSERT_EQUAL_INT32(i, *((uint32_t*)list_get(sut, 0)));

    list_destroy(sut);
}

void can_add_one_more_item_than_capacity_to_list() {
    List* sut = list_create(1);

    uint32_t i1 = 3;
    uint32_t i2 = 4;
    list_add(sut, &i1);

    TEST_ASSERT_TRUE(sut->count == 1);
    TEST_ASSERT_TRUE(sut->capacity == 1);
    TEST_ASSERT_EQUAL_INT32(i1, *((uint32_t*)list_get(sut, 0)));

    list_add(sut, &i2);

    TEST_ASSERT_TRUE(sut->count == 2);
    TEST_ASSERT_TRUE(sut->capacity == 2);
    TEST_ASSERT_EQUAL_INT32(i1, *((uint32_t*)list_get(sut, 0)));
    TEST_ASSERT_EQUAL_INT32(i2, *((uint32_t*)list_get(sut, 1)));

    list_destroy(sut);
}

void can_add_many_items_to_list() {
    List* sut = list_create(0);

    int32_t items[1000];
    for (int32_t i = 0; i < 1000; i++) {
        items[i] = i;

        list_add(sut, &items[i]);

        TEST_ASSERT_TRUE(sut->count == (i + 1));
        TEST_ASSERT_TRUE(sut->capacity >= sut->count);
        TEST_ASSERT_EQUAL_INT32(i, *((uint32_t*)list_get(sut, i)));
    }

    list_destroy(sut);
}

void can_remove_item_from_list() {
    List* sut = list_create(1);

    uint32_t i1 = 3;
    uint32_t i2 = 4;
    list_add(sut, &i1);
    list_add(sut, &i2);

    TEST_ASSERT_TRUE(sut->count == 2);
    TEST_ASSERT_EQUAL_INT32(i1, *((uint32_t*)list_get(sut, 0)));
    TEST_ASSERT_EQUAL_INT32(i2, *((uint32_t*)list_get(sut, 1)));

    list_remove(sut, &i1);

    TEST_ASSERT_TRUE(sut->count == 1);
    TEST_ASSERT_EQUAL_INT32(i2, *((uint32_t*)list_get(sut, 0)));

    list_destroy(sut);
}


int main(void) {
    UNITY_BEGIN();
    RUN_TEST(can_create_list);
    RUN_TEST(can_add_one_item_to_list);
    RUN_TEST(can_add_one_more_item_than_capacity_to_list);
    RUN_TEST(can_add_many_items_to_list);
    RUN_TEST(can_remove_item_from_list);
    return UNITY_END();
}