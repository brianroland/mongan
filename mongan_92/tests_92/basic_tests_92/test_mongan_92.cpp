

#include "gtest/gtest.h"
#include "producer_consumer.h"

TEST(test_hello_world, test_hello_world) {
    printf("\ntest_hello_world: beg\n");
    printf("test_hello_world: end\n");
}

TEST(test_buffer_0, test_buffer) {
    printf("\ntest_buffer_0: beg\n");
    IntBuffer * b = new IntBuffer(8);
    int i_in = 10;
    int index_in = b->put(i_in);
    int i_out = b->get(index_in);
    ASSERT_EQ(i_out, i_in);

    int i_in_1 = 11;
    int i_out_1 = b->get(b->put(i_in_1));
    ASSERT_EQ(i_out_1, i_in_1);

    delete b;
    printf("test_buffer_0: end\n");
}


TEST(test_producer_consumer_0, test_producer_consumer) {
    printf("\ntest_producer_consumer_0: beg\n");
    IntBuffer * b = new IntBuffer();

    int index_0 = produce(b);
    consume(b, index_0);

    int index_1 = produce(b);
    consume(b, index_1);

    delete b;
    printf("test_producer_consumer_0: end\n");
}