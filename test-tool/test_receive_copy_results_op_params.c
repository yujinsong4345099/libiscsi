/*
   Copyright (c) 2015 SanDisk Corp.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, see <http://www.gnu.org/licenses/>.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdlib.h>

#include <CUnit/CUnit.h>

#include "iscsi.h"
#include "scsi-lowlevel.h"
#include "iscsi-test-cu.h"

void
test_receive_copy_results_op_params(void)
{
	int ret;
	struct scsi_task *op_task;
	struct scsi_copy_results_op_params *opp;

	logging(LOG_VERBOSE, LOG_BLANK_LINE);
	logging(LOG_VERBOSE, "Test RECEIVE COPY RESULTS, OPERATING PARAMS");

	ret = receive_copy_results(&op_task, sd, SCSI_COPY_RESULTS_OP_PARAMS, 0,
			(void **)&opp, EXPECT_STATUS_GOOD);
	if (ret == -2) {
		CU_PASS("[SKIPPED] RECEIVE_COPY_RESULT is not implemented.");
		goto out;
	}
	CU_ASSERT_EQUAL(ret, 0);

	logging(LOG_NORMAL,
			"max_target_desc=%d, max_seg_desc=%d",
			opp->max_target_desc_count,
			opp->max_segment_desc_count);

out:
	scsi_free_scsi_task(op_task);
}
