/************************************************************************
 * NASA Docket No. GSC-18,447-1, and identified as “CFS CFDP (CF)
 * Application version 3.0.0”
 *
 * Copyright (c) 2019 United States Government as represented by the
 * Administrator of the National Aeronautics and Space Administration.
 * All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License"); you may
 * not use this file except in compliance with the License. You may obtain
 * a copy of the License at http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 ************************************************************************/

/**
 * @file
 *  @brief The CF Application command handling stubs file
 *
 *  All ground commands are processed in this file. All supporting functions
 *  necessary to process the commands are also here.
 */

#include "cf_test_utils.h"
#include "cf_app.h"

#include <string.h>

/* UT includes */
#include "uttest.h"
#include "utstubs.h"

/*----------------------------------------------------------------
 *
 * Function: UT_DefaultHandler_CF_ProcessGroundCommand
 *
 * For compatibility with other tests, this has a mechanism to save its
 * arguments to a test-provided context capture buffer.
 *
 *-----------------------------------------------------------------*/
void UT_DefaultHandler_CF_ProcessGroundCommand(void *UserObj, UT_EntryKey_t FuncKey, const UT_StubContext_t *Context)
{
    CFE_SB_Buffer_t **ctxt = UT_CF_GetContextBuffer(FuncKey, CFE_SB_Buffer_t *);

    if (ctxt)
    {
        *ctxt = UT_Hook_GetArgValueByName(Context, "msg", CFE_SB_Buffer_t *);
    }
}
