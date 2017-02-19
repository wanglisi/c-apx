//////////////////////////////////////////////////////////////////////////////
// INCLUDES
//////////////////////////////////////////////////////////////////////////////
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include <malloc.h>
#include <errno.h>
#include "CuTest.h"
#include "apx_nodeData.h"
#ifdef MEM_LEAK_CHECK
#include "CMemLeak.h"
#endif


//////////////////////////////////////////////////////////////////////////////
// CONSTANTS AND DATA TYPES
//////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////
// LOCAL FUNCTION PROTOTYPES
//////////////////////////////////////////////////////////////////////////////
static void test_apx_nodeData_newEmpty(CuTest* tc);

//////////////////////////////////////////////////////////////////////////////
// GLOBAL VARIABLES
//////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////
// LOCAL VARIABLES
//////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////
// GLOBAL FUNCTIONS
//////////////////////////////////////////////////////////////////////////////


CuSuite* testSuite_apx_nodeData(void)
{
   CuSuite* suite = CuSuiteNew();

   SUITE_ADD_TEST(suite, test_apx_nodeData_newEmpty);

   return suite;
}

//////////////////////////////////////////////////////////////////////////////
// LOCAL FUNCTIONS
//////////////////////////////////////////////////////////////////////////////

static void test_apx_nodeData_newEmpty(CuTest* tc)
{
   apx_nodeData_t *nodeData;
   const char *name="TestNode1";
   //create nodeData with no name, weakref=false
   nodeData = apx_nodeData_newRemote(0,false);
   CuAssertPtrNotNull(tc, nodeData);
   CuAssertPtrEquals(tc, 0, (void*) nodeData->name);
   apx_nodeData_delete(nodeData);

   //create nodeData with name, weakref=false
   nodeData = apx_nodeData_newRemote(name,false);
   CuAssertPtrNotNull(tc, nodeData);
   CuAssertPtrNotNull(tc, nodeData->name);
   CuAssert(tc, "expected copy of string",nodeData->name != name);
   CuAssertStrEquals(tc, name, nodeData->name);
   apx_nodeData_delete(nodeData);

   //create nodeData with name, weakref=true
   nodeData = apx_nodeData_newRemote(name, true);
   CuAssertPtrNotNull(tc, nodeData);
   CuAssertPtrNotNull(tc, nodeData->name);
   CuAssert(tc, "did not expected copy of string",nodeData->name == name);
   apx_nodeData_delete(nodeData);

}

