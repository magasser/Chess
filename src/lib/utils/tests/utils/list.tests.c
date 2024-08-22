#include <unity.h>

#include "utils/list.h"

void setUp() {}

void tearDown() {}

void calling_list_create_creates_valid_list() {
    List* sut = list_create(1);

    TEST_ASSERT_TRUE(sut->count == 0);
    TEST_ASSERT_TRUE(sut->capacity == 1);

    TEST_ASSERT_NOT_NULL(sut);

    list_destroy(sut);
}

void calling_list_add_adds_item_to_list() {
    List* sut = list_create(1);

    uint32_t i = 3;
    list_add(sut, &i);

    TEST_ASSERT_TRUE(sut->count == 1);
    TEST_ASSERT_TRUE(sut->capacity == 1);
    TEST_ASSERT_EQUAL_INT32(i, *((uint32_t*)list_get(sut, 0)));

    list_destroy(sut);
}

void calling_list_add_when_capacity_is_reached_adds_item_to_list() {
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

void calling_list_add_many_times_adds_all_items_to_list() {
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

void calling_list_remove_removes_item_from_list() {
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

void calling_list_index_of_finds_index_of_item_in_list() {
    List* sut = list_create(10);

    uint32_t items[10];
    for (int32_t i = 0; i < 10; i++) {
        items[i] = i;
        list_add(sut, &items[i]);
    }

    int32_t result = list_index_of(sut, &items[7]);

    TEST_ASSERT_EQUAL_INT32(7, result);

    list_destroy(sut);
}

void calling_list_index_of_when_item_is_not_in_list_return_negative_one() {
    List* sut = list_create(10);

    uint32_t items[10];
    for (int32_t i = 0; i < 10; i++) {
        items[i] = i;
        list_add(sut, &items[i]);
    }

    uint32_t not_in_list = 99;

    int32_t result = list_index_of(sut, &not_in_list);

    TEST_ASSERT_EQUAL_INT32(-1, result);

    list_destroy(sut);
}

static void test_foreach_func(void* value) {
    *(uint32_t*)value = 99;
}

void calling_list_foreach_invokes_action_for_each_item_in_list() {
    List* sut = list_create(10);

    uint32_t items[10];
    for (int32_t i = 0; i < 10; i++) {
        items[i] = i;
        list_add(sut, &items[i]);
    }

    list_foreach(sut, test_foreach_func);

    for (int32_t i = 0; i < sut->count; i++) {
        uint32_t* value = (uint32_t*)list_get(sut, i);
        TEST_ASSERT_EQUAL_INT32(99, *value);
    }

    list_destroy(sut);
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(calling_list_create_creates_valid_list);
    RUN_TEST(calling_list_add_adds_item_to_list);
    RUN_TEST(calling_list_add_when_capacity_is_reached_adds_item_to_list);
    RUN_TEST(calling_list_add_many_times_adds_all_items_to_list);
    RUN_TEST(calling_list_remove_removes_item_from_list);
    RUN_TEST(calling_list_index_of_finds_index_of_item_in_list);
    RUN_TEST(calling_list_index_of_when_item_is_not_in_list_return_negative_one);
    RUN_TEST(calling_list_foreach_invokes_action_for_each_item_in_list);
    return UNITY_END();
}