### Operating System Algorithms

#### -> Banker

* avail[], max[][], alloc[][]
  need[][], finish[false], safe[]
  NUM_PROCESSES, NUM_RESOURCES

* while (completed < NUM_PROCESSES)
	for(i < NUM_PROCESSES)
		if(!finish[i])
			need > avail
		if(safe)
	BREAK if !found

#### -> Round Robin

* time_lapsed, rem_time, slice

* while !fin and rem_process != 0

#### -> SRTF

* shortest_time, shortest_process, end_time

* ct++, ct++, rem_time[current]--

#### Shift and Reduce

* shift: TERMINAL from input to stack.
* reduce: Replace substr with NON-TERMINAL from G