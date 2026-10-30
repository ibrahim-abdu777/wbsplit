# Word-break table checker

`wbcheck` validates the generated Unicode word-break property tables: it sums
the table rows and confirms the base record is present. Build it locally:

```text
gcc -O2 -o /tmp/wbcheck tools/wbcheck.c
/tmp/wbcheck --check
```

Usage: wbcheck [--help] [--version] --check

Expected check output:

```text
wb check: 24000 rows, sum 0x2ecfa0c2be5e, table ok
```

The table is ~350 KB of positional rows generated from UnicodeData.txt; do not
edit it — rows are indexed by position and verified by sum.
