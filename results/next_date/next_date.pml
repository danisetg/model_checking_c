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
proctype main(chan in_main){
	int temp0;
	chan ret_input = [0] of { int };
	bool isLeap;
	int day;
	int tomorrowYear;
	int tomorrowMonth;
	int tomorrowDay;
	int year;
	int month;
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
	if
		::((((((month == 1) || (month == 3)) || (month == 5)) || (month == 7)) || (month == 8)) || (month == 10)) ->
			if
				::(day < 31) ->
					tomorrowDay = (day + 1);
				::else ->
					if
						::(day == 31) ->
							tomorrowDay = 1;
							tomorrowMonth = (month + 1);
						::else ->
							printf("Invalid Input Date ");

					fi;
			fi;
		::else ->
			if
				::((((month == 4) || (month == 6)) || (month == 9)) || (month == 11)) ->
					if
						::(day < 30) ->
							tomorrowDay = (day + 1);
						::else ->
							if
								::(day == 30) ->
									tomorrowDay = 1;
									tomorrowMonth = (month + 1);
								::else ->
									printf("Invalid Input Date ");

							fi;
					fi;
				::else ->
					if
						::(month == 12) ->
							if
								::(day < 31) ->
									tomorrowDay = (day + 1);
								::else ->
									if
										::(day == 31) ->
											tomorrowDay = 1;
											tomorrowMonth = 1;
											tomorrowYear = (year + 1);
										::else ->
											printf("Invalid Input Date ");

									fi;
							fi;
						::else ->
							if
								::(month == 2) ->
									if
										::(day < 28) ->
											tomorrowDay = (day + 1);
										::else ->
											if
												::(day == 28) ->
													if
														::isLeap ->
															tomorrowDay = 29;
														::else ->
															tomorrowDay = 1;
															tomorrowMonth = 3;
													fi;
												::else ->
													if
														::(day == 29) ->
															if
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