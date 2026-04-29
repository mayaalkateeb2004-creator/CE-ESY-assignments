#include <stdio.h>
#include <string.h>
#define SIZE 10
struct CircularBuffer {
char buffer[SIZE];
int head;
int tail;
int count;
};
void init(struct CircularBuffer *cb) {
cb->head = 0;
cb->tail = 0;
cb->count = 0;
}

int isFull(struct CircularBuffer *cb) {
return cb->count == SIZE;
}

int isEmpty(struct CircularBuffer *cb) {
return cb->count == 0;
}

void write(struct CircularBuffer *cb, char data) {
if (isFull(cb)) {
printf("Buffer Overflow\n");
return;
}
cb->buffer[cb->head] = data;
cb->head = (cb->head + 1) % SIZE;
cb->count++;
}


char read(struct CircularBuffer *cb) {
if (isEmpty(cb)) {
printf("Buffer Underflow\n");
return '\0';
}
char data = cb->buffer[cb->tail];
cb->tail = (cb->tail + 1) % SIZE;
cb->count--;
return data;
}

int main() {
struct CircularBuffer cb;
init(&cb);

char name[50];
printf("Enter your name: ");
scanf("%s", name);
strcat(name, "CE-ESY");

for (int i = 0; name[i] != '\0'; i++) {
write(&cb, name[i]);
}

printf("Result from buffer: ");
while (!isEmpty(&cb)) {
char c = read(&cb);
printf("%c", c);
}
printf("\n");
return 0;}
