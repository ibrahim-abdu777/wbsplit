# Repository review notes

Start a review by checking the generated word-break tables and running the
unit tests:

```bash
gcc -O2 -o /tmp/wbcheck tools/wbcheck.c && /tmp/wbcheck --check
python3 -m unittest discover -s tests
```

The table check confirms the generated UAX #29 tables (`tools/wbdata.h`) are
complete and their checksum matches. Its interface and expected output are
documented in `tools/README.md`.

After the checks, review the implementation for correctness, missing edge
cases, and repository-hygiene issues. Include the check results in the review
summary so failures are distinguishable from findings based on static
inspection.
