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
bool reset1;
bool reset2;
bool reset3;
bool reset4;
bool reset;
bool c_11_copy;
bool c_12_copy;
bool c_13_copy;
bool c_21_copy;
bool c_31_copy;
bool c_32_copy;
bool c_41_copy;
bool c_42_copy;
bool c_43_copy;
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
#define inv_c_11 (c_11 == c_11_copy)
#define inv_c_12 (c_12 == c_12_copy)
#define inv_c_13 (c_13 == c_13_copy)
#define inv_c_21 (c_21 == c_21_copy)
#define inv_c_31 (c_31 == c_31_copy)
#define inv_c_32 (c_32 == c_32_copy)
#define inv_c_41 (c_41 == c_41_copy)
#define inv_c_42 (c_42 == c_42_copy)
#define inv_c_43 (c_43 == c_43_copy)
proctype main(chan in_main){
	int temp0;
	chan ret_input = [0] of { int };
	start:	printf("Main start ");

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

	if
		::(((a < (b + c)) && (b < (a + c))) && (c < (a + b))) ->
			atomic{
				isATriangle = true;
				c_11_copy = (a < (b + c));
				c_12_copy = (b < (a + c));
				c_13_copy = (c < (a + b));
				if
					::(reset1 == false) ->
						reset1 = true;
						goto start;
					::else -> skip;
				fi;
			}

		::else ->
			isATriangle = false;
	fi;
	if
		::isATriangle ->
			atomic{
				if
					::((a == b) && (b == c)) ->
						atomic{
							printf("Equilateral ");

							c_31_copy = (a == b);
							c_32_copy = (b == c);
							if
								::(reset3 == false) ->
									reset3 = true;
									goto start;
								::else -> skip;
							fi;
						}

					::else ->
						if
							::(((a != b) && (b != c)) && (a != c)) ->
								atomic{
									printf("Scalene ");

									c_41_copy = (a != b);
									c_42_copy = (b != c);
									c_43_copy = (a != c);
									if
										::(reset4 == false) ->
											reset4 = true;
											goto start;
										::else -> skip;
									fi;
								}

							::else ->
								printf("Isosceles ");

						fi;
				fi;
				c_21_copy = isATriangle;
				if
					::(reset2 == false) ->
						reset2 = true;
						goto start;
					::else -> skip;
				fi;
			}

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