*This activity has been created as part of the 42 curriculum by ahalifa*

# Get Next Line

## Description
The goal of this project is to implement a function that reads a file line by line.

## Usage
Compile the program with a custom buffer size:
```bash
cc get_next_line.c get_next_line_utils.c -D BUFFER_SIZE=number -o your_program
```
*You choose the number of the BUFFER_SIZE*  
Then read your file:
```bash
./your_program your_file.txt
```

## Resources
- [read() man page](https://man7.org/linux/man-pages/man2/read.2.html)
- [Reading a file in C](https://stackoverflow.com/questions/68144753/using-read-for-reading-a-file-in-c)
- [Valgrind quick start](https://valgrind.org/docs/manual/quick-start.html)

## How it works

### `ft_read_line`
Reads from `fd` into a buffer and appends each chunk to `stash` until a `\n` is found or EOF is reached.

```c
char    *ft_read_line(int fd, char *stash)
```

| Step | Code | Explanation |
|------|------|-------------|
| Security check | `if (BUFFER_SIZE <= 0 \| fd < 0)` | Validates the buffer size and file descriptor before doing anything |
| Buffer allocation | `buf = malloc(BUFFER_SIZE + 1)` | Allocates the read buffer on the heap to avoid stack overflow |
| Stash init | `if (!stash) stash = ft_strdup("")` | Initializes stash on the first call |
| Read loop | `while (!ft_strchr(stash, '\n') && bufread > 0)` | Keeps reading until a `\n` is found in stash or EOF is reached |
| Read | `bufread = read(fd, buf, BUFFER_SIZE)` | Reads up to `BUFFER_SIZE` bytes from the file |
| Error handling | `if (bufread < 0) return (ft_free_all(&stash, buf))` | Frees everything and returns `NULL` on read error |
| Append | `temp = stash; stash = ft_strjoin(temp, buf); free(temp)` | Appends the buffer to stash. `temp` keeps the old address so it can be freed without losing the new stash |