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
bool isATriangle;
int a;
int c;
int b;
#define c_11 (a < (b + c))
#define c_12 (b < (a + c))
#define c_13 (c < (a + b))
#define d_1 ((c_11 && c_12) && c_13)
#define if1 main@if_1
#define c_21 isATriangle
#define d_2 c_21
#define c_31 (a == b)
#define c_32 (b == c)
#define d_3 (c_31 && c_32)
#define c_41 (a != b)
#define c_42 (b != c)
#define c_43 (a != c)
#define d_4 ((c_41 && c_42) && c_43)
#define if4 main@if_4
#define if3 main@if_3
#define if2 main@if_2
#define final main@end
proctype main(chan in_main){
	int temp0;
	chan ret_input = [0] of { int };
	printf("Enter 3integers which are sides of a triangle ");

	run input(ret_input, 1, 10);
	ret_input ? a;
	run input(ret_input, 1, 10);
	ret_input ? b;
	run input(ret_input, 1, 10);
	ret_input ? c;

	printf("Side A is %d ",a);

	printf("Side B is %d ",b);

	printf("Side C is %d ",c);

	if_1:	if
		::(((a < (b + c)) && (b < (a + c))) && (c < (a + b))) ->
			isATriangle = true;
		::else ->
			isATriangle = false;
	fi;
	if_2:	if
		::isATriangle ->
			if_3:			if
				::((a == b) && (b == c)) ->
					printf("Equilateral ");

				::else ->
					if_4:					if
						::(((a != b) && (b != c)) && (a != c)) ->
							printf("Scalene ");

						::else ->
							printf("Isosceles ");

					fi;
			fi;
		::else ->
			printf("Not a Triangle ");

	fi;
	in_main ! 0;
	goto end;
	end: printf("End of main");
}
init {
	chan ret_main = [0] of { bit };
	run main(ret_main);
	ret_main ? 0;
}