proctype input(chan in_input; int min; int max) {
	atomic {
		int value = min;
		do
			::value < max -> value++;
			::break;
		od;
		in_input ! value;
	}
}
typedef node {
	int value;
}
node node_mem[9];
int node_valid[9];
proctype main(chan in_main){
	int temp0;
	int temp1;
	int new;
	run (ret_, node);
	ret_ ? temp0;
	new = temp0;
	node_mem[new].value = 5;
	run (ret_, new);
	ret_ ? temp1;
	temp1;
	in_main ! 0;
	goto end;
	end: printf("End of main");
}
init {
	chan ret_main = [0] of { bit };
	run main(ret_main);
	ret_main ? 0;
}