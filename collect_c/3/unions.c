/* A union is a variable that may hold (at different times) objects of
 * different types and sizes
 */

union u_tag {
    int ival;
    float fval;
    char *sval;
} u;

struct {
    char *name;
    int flags;
    int utype;
    union {
        int ival;
        float fval;
        char *sval;
    } u;
} symtab [5];
