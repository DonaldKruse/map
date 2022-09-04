#include "map.h"
#include <stdio.h>
#include <stdlib.h>

typedef map_t(int) map_int_t;
typedef map_t(char*) map_str_t;

int main() {
	//int ret = 0;

	//map_int_t *map = malloc(sizeof(*map));
	//if (map == NULL) {
	//	ret = 1;
	//	goto quit;
	//}

	//const int value = 12;
	//const char key[] = "mykey";

	//map_init_reserve(map, 16);
	//map_set(map, key, value);
	//int *value_get = map_get(map, key);

	//if (value_get == NULL) {
	//	ret = 2;
	//	goto quit;
	//}

	//if (*value_get != value) {
	//	ret = 3;
	//}

    int ret;
	map_str_t *strmap = malloc(sizeof(*strmap));
	if (strmap == NULL) {
		ret = 1;
		goto quit;
	}

    char* keys[] = {"cd", "fg", "bg", "quit", "setenv", "getenv", "alias"};
    char* values[] = {"foo", "bar", "baz", "qux", "qix", "bep", "bop", "zop"};
    const int nKvs = sizeof(keys)/sizeof(keys[0]);



    map_init_reserve(strmap, 32);
    int i;
    for (i = 0; i < nKvs; i++) {
        map_set(strmap, keys[i], values[i]);
    }

    map_print(strmap);

    char** val = NULL;
    for (i = 0; i < nKvs; i++) {
        val = map_get(strmap, keys[i]);
        printf("get val: `%s`\n", *val);
    }

    
    //char** retval = map_get(strmap, key);
    //printf("map ret: %s\n", *retval);
    goto quit;

    

quit:
    map_deinit(strmap);
	free(strmap);

	return ret;
}
