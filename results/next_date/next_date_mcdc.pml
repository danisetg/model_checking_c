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
bool reset1;
bool reset2;
bool reset3;
bool reset4;
bool reset5;
bool reset6;
bool reset7;
bool reset8;
bool reset9;
bool reset10;
bool reset11;
bool reset12;
bool reset13;
bool reset14;
bool reset15;
bool reset;
bool c_11_copy;
bool c_12_copy;
bool c_13_copy;
bool c_14_copy;
bool c_15_copy;
bool c_16_copy;
bool c_21_copy;
bool c_31_copy;
bool c_41_copy;
bool c_42_copy;
bool c_43_copy;
bool c_44_copy;
bool c_51_copy;
bool c_61_copy;
bool c_71_copy;
bool c_81_copy;
bool c_91_copy;
bool c_101_copy;
bool c_111_copy;
bool c_121_copy;
bool c_131_copy;
bool c_141_copy;
bool c_151_copy;
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
#define inv_c_11 (c_11 == c_11_copy)
#define inv_c_12 (c_12 == c_12_copy)
#define inv_c_13 (c_13 == c_13_copy)
#define inv_c_14 (c_14 == c_14_copy)
#define inv_c_15 (c_15 == c_15_copy)
#define inv_c_16 (c_16 == c_16_copy)
#define inv_c_21 (c_21 == c_21_copy)
#define inv_c_31 (c_31 == c_31_copy)
#define inv_c_41 (c_41 == c_41_copy)
#define inv_c_42 (c_42 == c_42_copy)
#define inv_c_43 (c_43 == c_43_copy)
#define inv_c_44 (c_44 == c_44_copy)
#define inv_c_51 (c_51 == c_51_copy)
#define inv_c_61 (c_61 == c_61_copy)
#define inv_c_71 (c_71 == c_71_copy)
#define inv_c_81 (c_81 == c_81_copy)
#define inv_c_91 (c_91 == c_91_copy)
#define inv_c_101 (c_101 == c_101_copy)
#define inv_c_111 (c_111 == c_111_copy)
#define inv_c_121 (c_121 == c_121_copy)
#define inv_c_131 (c_131 == c_131_copy)
#define inv_c_141 (c_141 == c_141_copy)
#define inv_c_151 (c_151 == c_151_copy)
proctype main(chan in_main){
	int temp0;
	chan ret_input = [0] of { int };
	start:	printf("Main start ");

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
			atomic{
				if
					::(day < 31) ->
						atomic{
							tomorrowDay = (day + 1);
							c_21_copy = (day < 31);
							if
								::(reset2 == false) ->
									reset2 = true;
									goto start;
								::else -> skip;
							fi;
						}

					::else ->
						if
							::(day == 31) ->
								atomic{
									tomorrowDay = 1;
									tomorrowMonth = (month + 1);
									c_31_copy = (day == 31);
									if
										::(reset3 == false) ->
											reset3 = true;
											goto start;
										::else -> skip;
									fi;
								}

							::else ->
								printf("Invalid Input Date ");

						fi;
				fi;
				c_11_copy = (month == 1);
				c_12_copy = (month == 3);
				c_13_copy = (month == 5);
				c_14_copy = (month == 7);
				c_15_copy = (month == 8);
				c_16_copy = (month == 10);
				c_101_copy = (month == 2);
				c_111_copy = (day < 28);
				c_121_copy = (day == 28);
				c_131_copy = isLeap;
				c_141_copy = (day == 29);
				c_151_copy = isLeap;
				if
					::(reset1 == false) ->
						reset1 = true;
						goto start;
					::else -> skip;
				fi;
			}

		::else ->
			if
				::((((month == 4) || (month == 6)) || (month == 9)) || (month == 11)) ->
					atomic{
						if
							::(day < 30) ->
								atomic{
									tomorrowDay = (day + 1);
									c_51_copy = (day < 30);
									if
										::(reset5 == false) ->
											reset5 = true;
											goto start;
										::else -> skip;
									fi;
								}

							::else ->
								if
									::(day == 30) ->
										atomic{
											tomorrowDay = 1;
											tomorrowMonth = (month + 1);
											c_61_copy = (day == 30);
											if
												::(reset6 == false) ->
													reset6 = true;
													goto start;
												::else -> skip;
											fi;
										}

									::else ->
										printf("Invalid Input Date ");

								fi;
						fi;
						c_41_copy = (month == 4);
						c_42_copy = (month == 6);
						c_43_copy = (month == 9);
						c_44_copy = (month == 11);
						if
							::(reset4 == false) ->
								reset4 = true;
								goto start;
							::else -> skip;
						fi;
					}

				::else ->
					if
						::(month == 12) ->
							atomic{
								if
									::(day < 31) ->
										atomic{
											tomorrowDay = (day + 1);
											c_81_copy = (day < 31);
											if
												::(reset8 == false) ->
													reset8 = true;
													goto start;
												::else -> skip;
											fi;
										}

									::else ->
										if
											::(day == 31) ->
												atomic{
													tomorrowDay = 1;
													tomorrowMonth = 1;
													tomorrowYear = (year + 1);
													c_91_copy = (day == 31);
													if
														::(reset9 == false) ->
															reset9 = true;
															goto start;
														::else -> skip;
													fi;
												}

											::else ->
												printf("Invalid Input Date ");

										fi;
								fi;
								c_71_copy = (month == 12);
								if
									::(reset7 == false) ->
										reset7 = true;
										goto start;
									::else -> skip;
								fi;
							}

						::else ->
							if
								::(month == 2) ->
									atomic{
										if
											::(day < 28) ->
												atomic{
													tomorrowDay = (day + 1);
													c_11_copy = (month == 1);
													c_111_copy = (day < 28);
													if
														::(reset11 == false) ->
															reset11 = true;
															goto start;
														::else -> skip;
													fi;
												}

											::else ->
												if
													::(day == 28) ->
														atomic{
															if
																::isLeap ->
																	atomic{
																		tomorrowDay = 29;
																		c_13_copy = (month == 5);
																		c_131_copy = isLeap;
																		if
																			::(reset13 == false) ->
																				reset13 = true;
																				goto start;
																			::else -> skip;
																		fi;
																	}

																::else ->
																	tomorrowDay = 1;
																	tomorrowMonth = 3;
															fi;
															c_12_copy = (month == 3);
															c_121_copy = (day == 28);
															if
																::(reset12 == false) ->
																	reset12 = true;
																	goto start;
																::else -> skip;
															fi;
														}

													::else ->
														if
															::(day == 29) ->
																atomic{
																	if
																		::isLeap ->
																			atomic{
																				tomorrowDay = 1;
																				tomorrowMonth = 3;
																				c_15_copy = (month == 8);
																				c_151_copy = isLeap;
																				if
																					::(reset15 == false) ->
																						reset15 = true;
																						goto start;
																					::else -> skip;
																				fi;
																			}

																		::else ->
																			printf("Cannot have Feb .%d ",day);

																	fi;
																	c_14_copy = (month == 7);
																	c_141_copy = (day == 29);
																	if
																		::(reset14 == false) ->
																			reset14 = true;
																			goto start;
																		::else -> skip;
																	fi;
																}

															::else ->
																printf("Invalid Input Date ");

														fi;
												fi;
										fi;
										c_101_copy = (month == 2);
										if
											::(reset10 == false) ->
												reset10 = true;
												goto start;
											::else -> skip;
										fi;
									}

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