#include <stdio.h>
#include <stdlib.h>
#include <string.h>
unsigned char data[8];
void send_data(unsigned char *data, int len) {
  printf("[Sent data]\n");
  for (int i=0; i < len; i++) {
    printf("%2x ", data[i]);
  }
  printf("\n");
}

unsigned char* bar() {
  // Array data[8] is deallocated immediately on function return as it falls
  // out of scope.  It is deallocated with the bar()'s stack frame.
  int i;
  for (i = 1; i < 9; i++){
    data[i-1] = i;
  }
  return data;
}

int main() {
  unsigned char *data = bar();
  // At this point, data becomes a dangling pointer!
  send_data(data, 8);
  return 0;
}
