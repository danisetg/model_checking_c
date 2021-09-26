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
#define main_d_a_v7 main@d_a_v7
#define main_d_b_v7 main@d_b_v7
#define main_d_c_v7 main@d_c_v7
#define main_u_a_v8 main@u_a_v8
#define main_u_b_v9 main@u_b_v9
#define main_u_c_v10 main@u_c_v10
#define main_d_isATriangle_v12 main@d_isATriangle_v12
#define main_d_isATriangle_v13 main@d_isATriangle_v13
#define main_u_c_v11 main@u_c_v11
#define main_u_b_v11 main@u_b_v11
#define main_u_a_v11 main@u_a_v11
#define main_u_c_v17 main@u_c_v17
#define main_u_b_v17 main@u_b_v17
#define main_u_a_v17 main@u_a_v17
#define main_u_c_v15 main@u_c_v15
#define main_u_b_v15 main@u_b_v15
#define main_u_a_v15 main@u_a_v15
#define main_u_isATriangle_v14 main@u_isATriangle_v14
#define final main@end
proctype main(chan in_main){
	int temp0;
	chan ret_input = [0] of { int };
	bool isATriangle;
	int a;
	int c;
	int b;
	printf("Enter 3integers which are sides of a triangle ");

	d_c_v7:	d_b_v7:	d_a_v7:	run input(ret_input, 1, 10);
	ret_input ? a;
	run input(ret_input, 1, 10);
	ret_input ? b;
	run input(ret_input, 1, 10);
	ret_input ? c;

	u_a_v8:	printf("Side A is %d ",a);

	u_b_v9:	printf("Side B is %d ",b);

	u_c_v10:	printf("Side C is %d ",c);

	u_a_v11:	u_b_v11:	u_c_v11:	if
		::(((a < (b + c)) && (b < (a + c))) && (c < (a + b))) ->
			d_isATriangle_v12:			isATriangle = true;
		::else ->
			d_isATriangle_v13:			isATriangle = false;
	fi;
	u_isATriangle_v14:	if
		::isATriangle ->
			u_a_v15:			u_b_v15:			u_c_v15:			if
				::((a == b) && (b == c)) ->
					printf("Equilateral ");

				::else ->
					u_a_v17:					u_b_v17:					u_c_v17:					if
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