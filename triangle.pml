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
	bool c1;
	bool isATriangle;
	bool c3;
	bool c2;
	int a;
	int c;
	int b;
	do
		::true ->
			printf("Enter 3integers which are sides of a triangle ");

			run input(ret_input, 1, 10);
			ret_input ? a;
			run input(ret_input, 1, 10);
			ret_input ? b;
			run input(ret_input, 1, 10);
			ret_input ? c;

			c1 = ((1 <= a) && (a <= 200));
			c2 = ((1 <= b) && (b <= 200));
			c3 = ((1 <= c) && (c <= 200));
			if
				::(!c1) ->
					printf("Value of a is not in the range of permitted values ");

				::else -> skip;
			fi;
			if
				::(!c2) ->
					printf("Value of b is not in the range of permitted values ");

				::else -> skip;
			fi;
			if
				::(!c3) ->
					printf("Value of c is not in the range of permitted values ");

				::else -> skip;
			fi;
			if
				::!(!((c1 && c2) && c3)) -> break;
			fi;
	od;
	printf("Side A is %d ",a);

	printf("Side B is %d ",b);

	printf("Side C is %d ",c);

	if
		::(((a < (b + c)) && (b < (a + c))) && (c < (a + b))) ->
			isATriangle = true;
		::else ->
			isATriangle = false;
	fi;
	if
		::isATriangle ->
			if
				::((a == b) && (b == c)) ->
					printf("Equilateral ");

				::else ->
					if
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