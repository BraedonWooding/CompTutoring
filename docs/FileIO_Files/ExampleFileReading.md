# File Reading in C

File reading in C is luckily very simple so this will just show a ton of detailed examples.

I recommend running the examples and answering the questions.  If you just read the answers without thinking about it you won't get the most out of this.  I'll put the answers in an answer spoiler using the same code so the context makes sense.

Any exercise marked with '*' is highly recommended for the assignment.

ALL THE FILES ARE [HERE](https://github.com/BraedonWooding/CompTutoring/tree/master/docs/FileIO_Files)

> You only need fscanf(..., "%s", ...) for the assignment

## Introduction / General Overview of what we know so far

There are 3 streams that are defaulted in C

- stdin; input from terminal
- stdout; output to terminal
- stderr; output to terminal (but used for errors).

You can pipe in / out data like `./executable < in > out`

There are a few common functions;

- `scanf` read from stdin using a format + args
- `printf` output to stdout using a format + args

## Example 1) Scanf for words '*'

Before we go into file IO let's read some text 'word' by 'word'.

> My definition of word here is a sequence of ascii characters separated by whitespace.

Scanf does 99% of the work for us (yay) so we just have to write a simple project.

In this case I read in a sequence of words from terminal printing them out line by line in reverse.

```c
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_BUF_SIZE (1000)

struct node_t {
    struct node_t *next;
    char *text;
};

struct node_t *new_node(char *text) {
    // Q) What does sizeof(*node) do?
    struct node_t *node = malloc(sizeof(*node));
    node->next = NULL;

    // Q) +1 why?
    node->text = malloc(strlen(text) + 1);
    // strcpy(dest, src)
    strcpy(node->text, text);
    // we need to copy text here
    // Q) ^^ why?
    // Extension Q) Is there an either better and safer way to do this copy

    return node;
}

int main(void) {
    // Q) Can I do this recursively?  Any downside?

    // this is a very easy way to make a lazy stack
    struct node_t *head = NULL;

    // Q) Why +1?
    // Q) Why can we use a local array... when do we have to do malloc?
    char buffer[MAX_BUF_SIZE + 1];

    while (scanf("%s", buffer) == 1) {
        // This is all it takes to add a new item to the stack
        struct node_t *new = new_node(buffer);
        new->next = head;
        head = new;
    }

    printf("\n\n== And now each word in reverse ==\n\n");

    // print out in reverse and free
    for (struct node_t *cur = head; cur != NULL;) {
        printf("%s\n", cur->text);

        struct node_t *tmp = cur->next;
        free(cur->text);
        free(cur);
        cur = tmp;
    }

    return 0;
}
```

<details>
<summary>Answers to questions</summary>
<p>

```c
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_BUF_SIZE (1000)

struct node_t {
    struct node_t *next;
    char *text;
};

struct node_t *new_node(char *text) {
    // Q) What does sizeof(*node) do?
    // A) It looks at the type of *node which is just struct node_t
    //    then calculates the sizeof it which in this case is 16 bytes (2 pointers)
    struct node_t *node = malloc(sizeof(*node));
    node->next = NULL;

    // Q) +1 why?
    // A) To include the \0
    node->text = malloc(strlen(text) + 1);
    // strcpy(dest, src)
    strcpy(node->text, text);
    // we need to copy text here
    // Q) ^^ why?
    // A) Because 'text' points to the same original buffer called 'buffer' in
    //    main, so if we don't copy them then they'll all still point to the
    //    same buffer meaning they all have the same value meaning we lose
    //    the other words
    // Confusion? Run the example1_nosave.c in the directory
    // Extension Q) Is there an either better and safer way to do this copy
    // A) The problem is if 'text' isn't terminated with \0 (in this case/assignment
    //    it always is so don't worry but in the real world it's harder to
    //    know this for certain) then strcpy may just go past the original size
    //    of the array.
    //    The answer is to always allocate the max size of the string (100 + 1)
    //    then use strncpy (which effectively has a maximum size to copy)

    return node;
}

int main(void) {
    // Q) Can I do this recursively?  Any downside?
    // A) Yes, I've got it written in example1_rec.c.
    //    Downside is stackoverflow you can run it with 10,000 integers (1.in)

    // this is a very easy way to make a lazy stack
    struct node_t *head = NULL;

    // Q) Why +1?
    // A) \0
    // Q) Why can we use a local array... when do we have to do malloc?
    // A) Because the array only lasts the duration of the function!
    //    malloc is needed if we need to return an array or it somehow extends
    //    past the end of the function
    char buffer[MAX_BUF_SIZE + 1];

    while (scanf("%s", buffer) == 1) {
        // This is all it takes to add a new item to the stack
        struct node_t *new = new_node(buffer);
        new->next = head;
        head = new;
    }

    printf("\n\n== And now each word in reverse ==\n\n");

    // print out in reverse and free
    for (struct node_t *cur = head; cur != NULL;) {
        printf("%s\n", cur->text);

        struct node_t *tmp = cur->next;
        free(cur->text);
        free(cur);
        cur = tmp;
    }

    return 0;
}
```

</p></details>

<details>
<summary>Recursive Answer (for fun)</summary>

```c
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_BUF_SIZE (1000)

// Each recursive call is going to require 1000bytes (about 1kb)
// meaning that you can stack overflow pretty easily...
// in this case I was lazy an generated a file of 10,000 numbers (each number
// is counted as a separate word) that is going to use up 10 MB of memory
// this ends up segfaulting.  However it will work on the malloc examples.
void print_words_backwards() {
    char buffer[MAX_BUF_SIZE + 1];

    if (scanf("%s", buffer) == 1) {
        print_words_backwards();
        printf("%s\n", buffer);
    } else {
        printf("\n\n== And now each word in reverse ==\n\n");
    }
}

int main(void) {
    print_words_backwards();

    return 0;
}
```

</details>

## Example 2) Reading and printing words from a file (*)

How do we open a file?  `fopen(filename, filemode)`!

Filemode is also a string that contains details on what you intend to do to the file the options are;

- `r` meaning 'read', you can only read the file (i.e. fscanf, fgets, ...) you can't write to the file (fprintf, fputs, ...) this is like stdin
    - You'll use this for the assignment and here.
- `w` meaning 'write', you can only write to the file this is like stdout
- `r+` or `w+` (same thing) this allows you to read and write
- ... many more that I won't go through

Filename is just a string holding the name of the file including extension (including path but in the assignment you'll run it in the same directory as the file so just the name is fine).

i.e. `FILE *collection = fopen("collections.txt", "r");`

It returns a file pointer which is of type `FILE *` (the reason why it's `FILE` instead of like `File` or `file` is most likely because it used to be a #define at some point)

`fscanf` is the next magical function here.  The first argument is always a file pointer, then it's just like a normal scanf.  It will just do scanf on the file, consecutive scanfs know where in the file you are (if you use the same file pointer).

So a very simple way to print out all the words in a file is;

> This isn't in reverse though!  You could use a list or recursion if you wanted in reverse!  In the assignment you don't want it to be reversed though...

```c
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_BUF_SIZE (1000)

int main(void) {
    char word[MAX_BUF_SIZE + 1];

    FILE *word_list = fopen("1.in", "r");
    while (fscanf(word_list, "%s", word) == 1) {
        printf("%s\n", word);
    }

    return 0;
}
```

One last thought I want to leave is please me good to your variable names, a lot of people struggle to do File IO in this assignment because they use bad variable names and get confused about which buffer is which.  You'll notice that I renamed the variables to be much more specific in the example and this is highly intentional.
