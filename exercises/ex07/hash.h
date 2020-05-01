#ifndef HASH_H
#define HASH_H
// VALUE: represents a value in a key-value pair

/* Here's one way of making a polymorphic object in C */

typedef struct {
    enum Type {INT, STRING} type;
    union {
        int i;
        char *s;
    };
} Value;

Value *make_int_value(int i);
Value *make_string_value(char *s);
void print_value(Value *value);

// HASHABLE: Represents a key in a key-value pair.

/* Here's another way to make a polymorphic object.

The key can be any pointer type.  It's stored as a (void *), so
when you extract it, you have to cast it back to whatever it is.

`hash` is a pointer to a function that knows how to hash the key.
`equal` is a pointer to a function that knows how to compare keys.

*/

typedef struct {
    void *key;
    int (*hash) (void *);
    int (*equal) (void *, void *);
} Hashable;

Hashable *make_hashable(void *key,
        int (*hash) (void *),
        int (*equal) (void *, void *));
void print_hashable(Hashable *hashable);

int hash_int(void *p);
int hash_string(void *p);
int hash_hashable(Hashable *hashable);

int equal_int(void *ip, void *jp);
int equal_string(void *s1, void *s2);
int equal_hashable(Hashable *h1, Hashable *h2);

Hashable *make_hashable_int(int x);
Hashable *make_hashable_string(char *s);

// NODE: a node in a list of key-value pairs

typedef struct node {
    Hashable *key;
    Value *value;
    struct node *next;
} Node;

void print_node(Node *node);
void print_list(Node *node);

Node *prepend(Hashable *key, Value *value, Node *rest);
Value *list_lookup(Node *list, Hashable *key);
void free_node(Node *node);

// MAP: a map is an array of lists of key-value pairs

typedef struct map {
    int n;
    Node **lists;
    int size;
} Map;

Map *make_map(int n);
void resize_map(Map *map);
void free_map(Map *map);
void print_map(Map *map);
void map_add(Map *map, Hashable *key, Value *value);
Value *map_lookup(Map *map, Hashable *key);
void print_lookup(Value *value);

#endif
