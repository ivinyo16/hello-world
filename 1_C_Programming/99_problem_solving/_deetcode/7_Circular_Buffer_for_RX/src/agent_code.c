/* Standard libraries */
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

enum { BUFFER_SIZE = 16 };

static uint8_t buffer[BUFFER_SIZE];
static size_t head;
static size_t tail;
static size_t count;

int buf_push(uint8_t data)
{
    if (count == BUFFER_SIZE) {
        return -1;
    }

    buffer[head] = data;
    head = (head + 1U) % BUFFER_SIZE;
    count++;
    return 0;
}

int buf_pop(void)
{
    if (count == 0U) {
        return -1;
    }

    const uint8_t data = buffer[tail];
    tail = (tail + 1U) % BUFFER_SIZE;
    count--;
    return (int)data;
}

int main(void)
{
    for (uint8_t data = 1U; data <= 3U; data++) {
        if (buf_push(data) != 0) {
            return EXIT_FAILURE;
        }
    }

    printf("Output: [");
    for (int expected = 1; expected <= 3; expected++) {
        const int value = buf_pop();
        if (value != expected) {
            return EXIT_FAILURE;
        }
        printf("%s%d", expected == 1 ? "" : ", ", value);
    }
    puts("]");

    if (buf_pop() != -1) {
        return EXIT_FAILURE;
    }

    for (uint8_t data = 0U; data < BUFFER_SIZE; data++) {
        if (buf_push(data) != 0) {
            return EXIT_FAILURE;
        }
    }
    if (buf_push(99U) != -1) {
        return EXIT_FAILURE;
    }

    for (uint8_t expected = 0U; expected < BUFFER_SIZE / 2U; expected++) {
        if (buf_pop() != expected) {
            return EXIT_FAILURE;
        }
    }
    for (uint8_t data = 16U; data < 24U; data++) {
        if (buf_push(data) != 0) {
            return EXIT_FAILURE;
        }
    }
    for (uint8_t expected = 8U; expected < 24U; expected++) {
        if (buf_pop() != expected) {
            return EXIT_FAILURE;
        }
    }
    if (buf_pop() != -1) {
        return EXIT_FAILURE;
    }

    puts("Full, empty, FIFO, and wraparound checks passed.");
    return EXIT_SUCCESS;
}
