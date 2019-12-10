/* p1 coding style
 * snake_case
 * tab / indent == 4 spaces
 * INGEN end of line comments.
 */

#include <stdio.h>

#define CAPS_AND_UNDERSCORE 200

void prototype(int arg1, char *arg2);

struct struct_example{
  /*code*/
};
typedef struct struct_example struct_example;

int variable_name;

if (variable_name == 3){ /* space after if */
    /*code*/
} else if (condition_2){
    /*code*/
} else{
    /*code*/
}

switch (/* expression */){
    case /* case1 */: case /*case 2*/:
        /*code */
        break;
    case /*case 3*/:
        /*code*/
        break;
    default:
        /*code*/
}

for (i = 0; i < max; i++){ /*space after for*/
    /*code*/
}

while (i++, condition){
    /*code*/
}


void function_name(int arg1, char *arg2){
    /*code*/
}
