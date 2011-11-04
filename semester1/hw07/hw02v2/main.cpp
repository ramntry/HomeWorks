#include <cstdio>
#include "wordcounter.v2.h"

int main(void)
{
    WordBST * tree = new WordBST;
    unsigned int i = 0;
    for (; i < sizeof(WordBST); i++)
        ((char *) tree)[i] = '*';
    tree->next = NULL;
    tree->top = 0;

    append(tree, "i");
    handle(tree, "am");
    handle(tree, "programming");
    handle(tree, "am");

    FILE *in = fopen("in", "r");
    int counter = 0;
    char buf[2048];
    buf[0] = '\0';
    if (in)
    {
        while (fscanf(in, "%s", buf) != EOF && (handle(tree, buf) != -1))
            counter++;
    }
    printWordBST(tree);
    printf("\n%d words readed from \"in\" (stop word is \"%s\")\n", counter, buf);

    return 0;
}
