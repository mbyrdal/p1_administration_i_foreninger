#include "include.h"

CuSuite *StrUtilGetSuite();

void run_all_tests(void){
    CuString *output = CuStringNew();
    CuSuite *suite = CuSuiteNew();

    CuSuiteAddSuite(suite, (CuSuite *) user_wrote_no_get_suite());
    CuSuiteAddSuite(suite, (CuSuite *) is_yes_or_no_get_suite());
    CuSuiteRun(suite);
    CuSuiteSummary(suite, output);
    CuSuiteDetails(suite, output);
    printf("%s\n", output->buffer);
}
