@@ startup.s * Created on: Jun 12, 2022 * Author: momen amr

.global reset

reset:
	ldr sp, =stack_top
	bl main
stop:	
	b stop