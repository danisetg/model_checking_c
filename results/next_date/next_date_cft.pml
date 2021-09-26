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
bool isLeap;
int day;
int tomorrowYear;
int tomorrowMonth;
int tomorrowDay;
int year;
int month;
#define c_11 (month == 1)
#define c_12 (month == 3)
#define c_13 (month == 5)
#define c_14 (month == 7)
#define c_15 (month == 8)
#define c_16 (month == 10)
#define d_1 (((((c_11 || c_12) || c_13) || c_14) || c_15) || c_16)
#define c_21 (day < 31)
#define d_2 c_21
#define c_31 (day == 31)
#define d_3 c_31
#define if3 main@if_3
#define if2 main@if_2
#define c_41 (month == 4)
#define c_42 (month == 6)
#define c_43 (month == 9)
#define c_44 (month == 11)
#define d_4 (((c_41 || c_42) || c_43) || c_44)
#define c_51 (day < 30)
#define d_5 c_51
#define c_61 (day == 30)
#define d_6 c_61
#define if6 main@if_6
#define if5 main@if_5
#define c_71 (month == 12)
#define d_7 c_71
#define c_81 (day < 31)
#define d_8 c_81
#define c_91 (day == 31)
#define d_9 c_91
#define if9 main@if_9
#define if8 main@if_8
#define c_101 (month == 2)
#define d_10 c_101
#define c_111 (day < 28)
#define d_11 c_111
#define c_121 (day == 28)
#define d_12 c_121
#define c_131 isLeap
#define d_13 c_131
#define if13 main@if_13
#define c_141 (day == 29)
#define d_14 c_141
#define c_151 isLeap
#define d_15 c_151
#define if15 main@if_15
#define if14 main@if_14
#define if12 main@if_12
#define if11 main@if_11
#define if10 main@if_10
#define if7 main@if_7
#define if4 main@if_4
#define if1 main@if_1
#define final main@end
proctype main(chan in_main){
	int temp0;
	chan ret_input = [0] of { int };
	printf("Enter date in the form MM DD YYYY ");

	run input(ret_input, 1, 12);
	ret_input ? month;
	run input(ret_input, 1, 31);
	ret_input ? day;
	run input(ret_input, 2000, 2021);
	ret_input ? year;

	tomorrowMonth = month;
	tomorrowYear = year;
	isLeap = (((year % 4) == 0) && (((year % 100) != 0) || ((year % 400) == 0)));
	if_1:	if
		::((((((month == 1) || (month == 3)) || (month == 5)) || (month == 7)) || (month == 8)) || (month == 10)) ->
			if_2:			if
				::(day < 31) ->
					tomorrowDay = (day + 1);
				::else ->
					if_3:					if
						::(day == 31) ->
							tomorrowDay = 1;
							tomorrowMonth = (month + 1);
						::else ->
							printf("Invalid Input Date ");

					fi;
			fi;
		::else ->
			if_4:			if
				::((((month == 4) || (month == 6)) || (month == 9)) || (month == 11)) ->
					if_5:					if
						::(day < 30) ->
							tomorrowDay = (day + 1);
						::else ->
							if_6:							if
								::(day == 30) ->
									tomorrowDay = 1;
									tomorrowMonth = (month + 1);
								::else ->
									printf("Invalid Input Date ");

							fi;
					fi;
				::else ->
					if_7:					if
						::(month == 12) ->
							if_8:							if
								::(day < 31) ->
									tomorrowDay = (day + 1);
								::else ->
									if_9:									if
										::(day == 31) ->
											tomorrowDay = 1;
											tomorrowMonth = 1;
											tomorrowYear = (year + 1);
										::else ->
											printf("Invalid Input Date ");

									fi;
							fi;
						::else ->
							if_10:							if
								::(month == 2) ->
									if_11:									if
										::(day < 28) ->
											tomorrowDay = (day + 1);
										::else ->
											if_12:											if
												::(day == 28) ->
													if_13:													if
														::isLeap ->
															tomorrowDay = 29;
														::else ->
															tomorrowDay = 1;
															tomorrowMonth = 3;
													fi;
												::else ->
													if_14:													if
														::(day == 29) ->
															if_15:															if
																::isLeap ->
																	tomorrowDay = 1;
																	tomorrowMonth = 3;
																::else ->
																	printf("Cannot have Feb .%d ",day);

															fi;
														::else ->
															printf("Invalid Input Date ");

													fi;
											fi;
									fi;
								::else -> skip;
							fi;
					fi;
			fi;
	fi;
	printf("date is %d %d %d ",tomorrowMonth,tomorrowDay,tomorrowYear);

	in_main ! 0;
	goto end;
	end: printf("End of main");
}
init {
	chan ret_main = [0] of { bit };
	run main(ret_main);
	ret_main ? 0;
}