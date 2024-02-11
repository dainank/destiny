# Destiny
> A program like _UNIX_'s _Fortune_ program with the following requirements:

1. Obtain number of entries.
2. Generate random val based on (1).
3. Fetch random item.
4. Output phrase.

## Various Notes
> On `src` code.
- Arrays decay to pointers to the first element in the array in `C`.
- You cannot pass `argv[]` without pointer since it would not know the size at compile time.
- `char *argv[]` standard decleration for receiving command-line arguments in `C`.
- `strftime()` can be used instead of `printf` to print strings with time vars.