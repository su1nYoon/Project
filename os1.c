#include <stdio.h>
#include <stdbool.h>

#define BUFFER_SIZE 10

typedef struct {
    int value;  
} item;

item buffer[BUFFER_SIZE];
int in = 0;
int out = 0;

int main(void)
{
    item next_produced;
    item next_consumed;

    /* 생산자 */
    while (true) {
        /* produce an item in next_produced */
        next_produced.value = 1;  

        while (((in + 1) % BUFFER_SIZE) == out)
            ;  /* buffer full → busy wait */

        buffer[in] = next_produced;
        in = (in + 1) % BUFFER_SIZE;
    }

    /* 소비자 */
    while (true) {
        while (in == out)
            ;  /* buffer empty → busy wait */

        next_consumed = buffer[out];
        out = (out + 1) % BUFFER_SIZE;

        /* consume */
        printf("consumed: %d\n", next_consumed.value);
    }

    return 0;
}
