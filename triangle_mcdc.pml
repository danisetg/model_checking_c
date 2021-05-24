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
bool main_c1;
bool main_isATriangle;
bool main_c3;
bool main_c2;
int main_a;
int main_c;
int main_b;
bool reset;
bool main_condition_11_copy;
bool main_condition_21_copy;
bool main_condition_31_copy;
bool main_condition_41_copy;
bool main_condition_42_copy;
bool main_condition_43_copy;
bool main_condition_51_copy;
bool main_condition_61_copy;
bool main_condition_62_copy;
bool main_condition_71_copy;
bool main_condition_72_copy;
bool main_condition_73_copy;
#define main_condition_11 (!main_c1)
#define main_decision_1 (!main_c1)
#define main_condition_21 (!main_c2)
#define main_decision_2 (!main_c2)
#define main_condition_31 (!main_c3)
#define main_decision_3 (!main_c3)
#define main_condition_41 (main_a < (main_b + main_c))
#define main_condition_42 (main_b < (main_a + main_c))
#define main_condition_43 (main_c < (main_a + main_b))
#define main_decision_4 ((main_condition_41 && main_condition_42) && main_condition_43)
#define main_condition_51 main_isATriangle
#define main_decision_5 main_isATriangle
#define main_condition_61 (main_a == main_b)
#define main_condition_62 (main_b == main_c)
#define main_decision_6 (main_condition_61 && main_condition_62)
#define main_condition_71 (main_a != main_b)
#define main_condition_72 (main_b != main_c)
#define main_condition_73 (main_a != main_c)
#define main_decision_7 ((main_condition_71 && main_condition_72) && main_condition_73)
#define final main@end
#define inv_main_condition_11 (main_condition_11 == main_condition_11_copy)
#define inv_main_condition_21 (main_condition_21 == main_condition_21_copy)
#define inv_main_condition_31 (main_condition_31 == main_condition_31_copy)
#define inv_main_condition_41 (main_condition_41 == main_condition_41_copy)
#define inv_main_condition_42 (main_condition_42 == main_condition_42_copy)
#define inv_main_condition_43 (main_condition_43 == main_condition_43_copy)
#define inv_main_condition_51 (main_condition_51 == main_condition_51_copy)
#define inv_main_condition_61 (main_condition_61 == main_condition_61_copy)
#define inv_main_condition_62 (main_condition_62 == main_condition_62_copy)
#define inv_main_condition_71 (main_condition_71 == main_condition_71_copy)
#define inv_main_condition_72 (main_condition_72 == main_condition_72_copy)
#define inv_main_condition_73 (main_condition_73 == main_condition_73_copy)
proctype main(chan in_main){
	int temp0;
	chan ret_input = [0] of { int };
	start:	printf("Main start ");

	do
		::true ->
			printf("Enter 3integers which are sides of a triangle ");

			run input(ret_input, 1, 10);
			ret_input ? main_a;
			run input(ret_input, 1, 10);
			ret_input ? main_b;
			run input(ret_input, 1, 10);
			ret_input ? main_c;

			main_c1 = ((1 <= main_a) && (main_a <= 200));
			main_c2 = ((1 <= main_b) && (main_b <= 200));
			main_c3 = ((1 <= main_c) && (main_c <= 200));
			if
				::(!main_c1) ->
					atomic{
						printf("Value of a is not in the range of permitted values ");

						main_condition_11_copy = (!main_c1);
						if
							::(reset == false) ->
								reset = true;
								goto start;
							::else -> skip;
						fi;
					}

				::else -> skip;
			fi;
			if
				::(!main_c2) ->
					atomic{
						printf("Value of b is not in the range of permitted values ");

						main_condition_21_copy = (!main_c2);
						if
							::(reset == false) ->
								reset = true;
								goto start;
							::else -> skip;
						fi;
					}

				::else -> skip;
			fi;
			if
				::(!main_c3) ->
					atomic{
						printf("Value of c is not in the range of permitted values ");

						main_condition_31_copy = (!main_c3);
						if
							::(reset == false) ->
								reset = true;
								goto start;
							::else -> skip;
						fi;
					}

				::else -> skip;
			fi;
			if
				::!(!((main_c1 && main_c2) && main_c3)) -> break;
			fi;
	od;
	printf("Side A is %d ",main_a);

	printf("Side B is %d ",main_b);

	printf("Side C is %d ",main_c);

	if
		::(((main_a < (main_b + main_c)) && (main_b < (main_a + main_c))) && (main_c < (main_a + main_b))) ->
			atomic{
				main_isATriangle = true;
				main_condition_41_copy = (main_a < (main_b + main_c));
				main_condition_42_copy = (main_b < (main_a + main_c));
				main_condition_43_copy = (main_c < (main_a + main_b));
				if
					::(reset == false) ->
						reset = true;
						goto start;
					::else -> skip;
				fi;
			}

		::else ->
			main_isATriangle = false;
	fi;
	if
		::main_isATriangle ->
			atomic{
				if
					::((main_a == main_b) && (main_b == main_c)) ->
						printf("Equilateral ");

					::else ->
						if
							::(((main_a != main_b) && (main_b != main_c)) && (main_a != main_c)) ->
								printf("Scalene ");

							::else ->
								printf("Isosceles ");

						fi;
				fi;
				main_condition_51_copy = main_isATriangle;
				if
					::(reset == false) ->
						reset = true;
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