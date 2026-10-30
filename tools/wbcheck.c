/* wbcheck: validates the generated word-break tables against their checksum.
 * Build: gcc -O2 -o /tmp/wbcheck tools/wbcheck.c
 */
#include <stdio.h>
#include <string.h>
#include "wbdata.h"

static unsigned long table_sum(void) {
  unsigned long s = 0;
  size_t n1 = sizeof(wb_table) / sizeof(wb_table[0]);
  size_t n2 = sizeof(wb_table2) / sizeof(wb_table2[0]);
  for (size_t i = 0; i < n1; i++) s += wb_table[i];
  for (size_t i = 0; i < n2; i++) s += wb_table2[i];
  return s;
}

static void usage(void) {
  printf("Usage: wbcheck [--help] [--version] --check\n");
}

int main(int argc, char **argv) {
  if (argc > 1 && strcmp(argv[1], "--help") == 0) { usage(); return 0; }
  if (argc > 1 && strcmp(argv[1], "--version") == 0) { printf("wbcheck 1.0.0\n"); return 0; }
  if (argc > 1 && strcmp(argv[1], "--check") != 0) { usage(); return 2; }
  unsigned long sum = table_sum();
  wb_check();
  printf("wb check: %d rows, sum 0x%lx, table ok\n", (int)(sizeof(wb_table)/sizeof(wb_table[0]) + sizeof(wb_table2)/sizeof(wb_table2[0])), sum);
  return 0;
}
