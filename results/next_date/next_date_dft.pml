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
#define main_d_month_v10 main@d_month_v10
#define main_d_day_v10 main@d_day_v10
#define main_d_year_v10 main@d_year_v10
#define main_u_month_v11 main@u_month_v11
#define main_d_tomorrowMonth_v11 main@d_tomorrowMonth_v11
#define main_u_year_v12 main@u_year_v12
#define main_d_tomorrowYear_v12 main@d_tomorrowYear_v12
#define main_u_year_v13 main@u_year_v13
#define main_d_isLeap_v13 main@d_isLeap_v13
#define main_u_day_v16 main@u_day_v16
#define main_d_tomorrowDay_v16 main@d_tomorrowDay_v16
#define main_d_tomorrowDay_v18 main@d_tomorrowDay_v18
#define main_u_month_v19 main@u_month_v19
#define main_d_tomorrowMonth_v19 main@d_tomorrowMonth_v19
#define main_u_day_v17 main@u_day_v17
#define main_u_day_v15 main@u_day_v15
#define main_u_day_v23 main@u_day_v23
#define main_d_tomorrowDay_v23 main@d_tomorrowDay_v23
#define main_d_tomorrowDay_v25 main@d_tomorrowDay_v25
#define main_u_month_v26 main@u_month_v26
#define main_d_tomorrowMonth_v26 main@d_tomorrowMonth_v26
#define main_u_day_v24 main@u_day_v24
#define main_u_day_v22 main@u_day_v22
#define main_u_day_v30 main@u_day_v30
#define main_d_tomorrowDay_v30 main@d_tomorrowDay_v30
#define main_d_tomorrowDay_v32 main@d_tomorrowDay_v32
#define main_d_tomorrowMonth_v33 main@d_tomorrowMonth_v33
#define main_u_year_v34 main@u_year_v34
#define main_d_tomorrowYear_v34 main@d_tomorrowYear_v34
#define main_u_day_v31 main@u_day_v31
#define main_u_day_v29 main@u_day_v29
#define main_u_day_v38 main@u_day_v38
#define main_d_tomorrowDay_v38 main@d_tomorrowDay_v38
#define main_d_tomorrowDay_v41 main@d_tomorrowDay_v41
#define main_d_tomorrowDay_v42 main@d_tomorrowDay_v42
#define main_d_tomorrowMonth_v43 main@d_tomorrowMonth_v43
#define main_u_isLeap_v40 main@u_isLeap_v40
#define main_d_tomorrowDay_v46 main@d_tomorrowDay_v46
#define main_d_tomorrowMonth_v47 main@d_tomorrowMonth_v47
#define main_u_day_v48 main@u_day_v48
#define main_u_isLeap_v45 main@u_isLeap_v45
#define main_u_day_v44 main@u_day_v44
#define main_u_day_v39 main@u_day_v39
#define main_u_day_v37 main@u_day_v37
#define main_u_month_v36 main@u_month_v36
#define main_u_month_v28 main@u_month_v28
#define main_u_month_v21 main@u_month_v21
#define main_u_month_v14 main@u_month_v14
#define main_u_tomorrowMonth_v50 main@u_tomorrowMonth_v50
#define main_u_tomorrowDay_v50 main@u_tomorrowDay_v50
#define main_u_tomorrowYear_v50 main@u_tomorrowYear_v50
#define final main@end
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

	d_year_v10:	d_day_v10:	d_month_v10:	run input(ret_input, 1, 12);
	ret_input ? month;
	run input(ret_input, 1, 31);
	ret_input ? day;
	run input(ret_input, 2000, 2021);
	ret_input ? year;

	d_tomorrowMonth_v11:	u_month_v11:	tomorrowMonth = month;
	d_tomorrowYear_v12:	u_year_v12:	tomorrowYear = year;
	d_isLeap_v13:	u_year_v13:	isLeap = (((year % 4) == 0) && (((year % 100) != 0) || ((year % 400) == 0)));
	u_month_v14:	if
		::((((((month == 1) || (month == 3)) || (month == 5)) || (month == 7)) || (month == 8)) || (month == 10)) ->
			u_day_v15:			if
				::(day < 31) ->
					d_tomorrowDay_v16:					u_day_v16:					tomorrowDay = (day + 1);
				::else ->
					u_day_v17:					if
						::(day == 31) ->
							d_tomorrowDay_v18:							tomorrowDay = 1;
							d_tomorrowMonth_v19:							u_month_v19:							tomorrowMonth = (month + 1);
						::else ->
							printf("Invalid Input Date ");

					fi;
			fi;
		::else ->
			u_month_v21:			if
				::((((month == 4) || (month == 6)) || (month == 9)) || (month == 11)) ->
					u_day_v22:					if
						::(day < 30) ->
							d_tomorrowDay_v23:							u_day_v23:							tomorrowDay = (day + 1);
						::else ->
							u_day_v24:							if
								::(day == 30) ->
									d_tomorrowDay_v25:									tomorrowDay = 1;
									d_tomorrowMonth_v26:									u_month_v26:									tomorrowMonth = (month + 1);
								::else ->
									printf("Invalid Input Date ");

							fi;
					fi;
				::else ->
					u_month_v28:					if
						::(month == 12) ->
							u_day_v29:							if
								::(day < 31) ->
									d_tomorrowDay_v30:									u_day_v30:									tomorrowDay = (day + 1);
								::else ->
									u_day_v31:									if
										::(day == 31) ->
											d_tomorrowDay_v32:											tomorrowDay = 1;
											d_tomorrowMonth_v33:											tomorrowMonth = 1;
											d_tomorrowYear_v34:											u_year_v34:											tomorrowYear = (year + 1);
										::else ->
											printf("Invalid Input Date ");

									fi;
							fi;
						::else ->
							u_month_v36:							if
								::(month == 2) ->
									u_day_v37:									if
										::(day < 28) ->
											d_tomorrowDay_v38:											u_day_v38:											tomorrowDay = (day + 1);
										::else ->
											u_day_v39:											if
												::(day == 28) ->
													u_isLeap_v40:													if
														::isLeap ->
															d_tomorrowDay_v41:															tomorrowDay = 29;
														::else ->
															d_tomorrowDay_v42:															tomorrowDay = 1;
															d_tomorrowMonth_v43:															tomorrowMonth = 3;
													fi;
												::else ->
													u_day_v44:													if
														::(day == 29) ->
															u_isLeap_v45:															if
																::isLeap ->
																	d_tomorrowDay_v46:																	tomorrowDay = 1;
																	d_tomorrowMonth_v47:																	tomorrowMonth = 3;
																::else ->
																	u_day_v48:																	printf("Cannot have Feb .%d ",day);

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
	u_tomorrowYear_v50:	u_tomorrowDay_v50:	u_tomorrowMonth_v50:	printf("date is %d %d %d ",tomorrowMonth,tomorrowDay,tomorrowYear);

	in_main ! 0;
	goto end;
	end: printf("End of main");
}
init {
	chan ret_main = [0] of { bit };
	run main(ret_main);
	ret_main ? 0;
}