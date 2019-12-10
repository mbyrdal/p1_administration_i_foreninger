#include "include.h"

CuSuite *StrUtilGetSuite();

void run_all_tests(void){
    CuString *output = CuStringNew();
    CuSuite *suite = CuSuiteNew();

    CuSuiteAddSuite(suite, (CuSuite *) strcmp_lower_get_suite());
    CuSuiteRun(suite);
    CuSuiteSummary(suite, output);
    CuSuiteDetails(suite, output);
    printf("%s\n", output->buffer);
}
