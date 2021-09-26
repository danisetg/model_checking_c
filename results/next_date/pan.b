	switch (t->back) {
	default: Uerror("bad return move");
	case  0: goto R999; /* nothing to undo */

		 /* CLAIM never_0 */
;
		;
		;
		;
		;
		;
		;
		;
		;
		;
		;
		;
		;
		;
		;
		;
		;
		;
		;
		;
		;
		;
		;
		;
		;
		;
		;
		;
		;
		;
		;
		;
		;
		;
		
	case 20: /* STATE 60 */
		;
		p_restor(II);
		;
		;
		goto R999;

		 /* PROC :init: */

	case 21: /* STATE 1 */
		;
		;
		delproc(0, now._nr_pr-1);
		;
		goto R999;

	case 22: /* STATE 2 */
		;
		XX = 1;
		unrecv(((P2 *)this)->_3_ret_main, XX-1, 0, 0, 1);
		;
		;
		goto R999;

	case 23: /* STATE 3 */
		;
		p_restor(II);
		;
		;
		goto R999;

		 /* PROC main */
;
		;
		
	case 25: /* STATE 2 */
		;
		;
		delproc(0, now._nr_pr-1);
		;
		goto R999;

	case 26: /* STATE 3 */
		;
		XX = 1;
		unrecv(((P1 *)this)->_2_ret_input, XX-1, 0, ((P1 *)this)->_2_month, 1);
		((P1 *)this)->_2_month = trpt->bup.oval;
		;
		;
		goto R999;

	case 27: /* STATE 4 */
		;
		;
		delproc(0, now._nr_pr-1);
		;
		goto R999;

	case 28: /* STATE 5 */
		;
		XX = 1;
		unrecv(((P1 *)this)->_2_ret_input, XX-1, 0, ((P1 *)this)->_2_day, 1);
		((P1 *)this)->_2_day = trpt->bup.oval;
		;
		;
		goto R999;

	case 29: /* STATE 6 */
		;
		;
		delproc(0, now._nr_pr-1);
		;
		goto R999;

	case 30: /* STATE 7 */
		;
		XX = 1;
		unrecv(((P1 *)this)->_2_ret_input, XX-1, 0, ((P1 *)this)->_2_year, 1);
		((P1 *)this)->_2_year = trpt->bup.oval;
		;
		;
		goto R999;

	case 31: /* STATE 8 */
		;
		((P1 *)this)->_2_tomorrowMonth = trpt->bup.oval;
		;
		goto R999;

	case 32: /* STATE 9 */
		;
		((P1 *)this)->_2_tomorrowYear = trpt->bup.oval;
		;
		goto R999;

	case 33: /* STATE 10 */
		;
		((P1 *)this)->_2_isLeap = trpt->bup.oval;
		;
		goto R999;
;
		;
		;
		;
		
	case 36: /* STATE 13 */
		;
		((P1 *)this)->_2_tomorrowDay = trpt->bup.oval;
		;
		goto R999;

	case 37: /* STATE 15 */
		;
	/* 0 */	((P1 *)this)->_2_day = trpt->bup.oval;
		;
		;
		goto R999;

	case 38: /* STATE 16 */
		;
		((P1 *)this)->_2_tomorrowDay = trpt->bup.oval;
		;
		goto R999;

	case 39: /* STATE 17 */
		;
		((P1 *)this)->_2_tomorrowMonth = trpt->bup.oval;
		;
		goto R999;
;
		;
		;
		;
		;
		;
		
	case 43: /* STATE 27 */
		;
		((P1 *)this)->_2_tomorrowDay = trpt->bup.oval;
		;
		goto R999;

	case 44: /* STATE 29 */
		;
	/* 0 */	((P1 *)this)->_2_day = trpt->bup.oval;
		;
		;
		goto R999;

	case 45: /* STATE 30 */
		;
		((P1 *)this)->_2_tomorrowDay = trpt->bup.oval;
		;
		goto R999;

	case 46: /* STATE 31 */
		;
		((P1 *)this)->_2_tomorrowMonth = trpt->bup.oval;
		;
		goto R999;
;
		;
		
	case 48: /* STATE 39 */
		;
	/* 0 */	((P1 *)this)->_2_month = trpt->bup.oval;
		;
		;
		goto R999;
;
		;
		
	case 50: /* STATE 41 */
		;
		((P1 *)this)->_2_tomorrowDay = trpt->bup.oval;
		;
		goto R999;

	case 51: /* STATE 43 */
		;
	/* 0 */	((P1 *)this)->_2_day = trpt->bup.oval;
		;
		;
		goto R999;

	case 52: /* STATE 44 */
		;
		((P1 *)this)->_2_tomorrowDay = trpt->bup.oval;
		;
		goto R999;

	case 53: /* STATE 45 */
		;
		((P1 *)this)->_2_tomorrowMonth = trpt->bup.oval;
		;
		goto R999;

	case 54: /* STATE 46 */
		;
		((P1 *)this)->_2_tomorrowYear = trpt->bup.oval;
		;
		goto R999;
;
		;
		
	case 56: /* STATE 54 */
		;
	/* 0 */	((P1 *)this)->_2_month = trpt->bup.oval;
		;
		;
		goto R999;
;
		;
		
	case 58: /* STATE 56 */
		;
		((P1 *)this)->_2_tomorrowDay = trpt->bup.oval;
		;
		goto R999;

	case 59: /* STATE 58 */
		;
	/* 0 */	((P1 *)this)->_2_day = trpt->bup.oval;
		;
		;
		goto R999;

	case 60: /* STATE 59 */
		;
	/* 0 */	((P1 *)this)->_2_isLeap = trpt->bup.oval;
		;
		;
		goto R999;

	case 61: /* STATE 60 */
		;
		((P1 *)this)->_2_tomorrowDay = trpt->bup.oval;
		;
		goto R999;

	case 62: /* STATE 62 */
		;
		((P1 *)this)->_2_tomorrowDay = trpt->bup.oval;
		;
		goto R999;

	case 63: /* STATE 63 */
		;
		((P1 *)this)->_2_tomorrowMonth = trpt->bup.oval;
		;
		goto R999;
;
		;
		
	case 65: /* STATE 68 */
		;
	/* 0 */	((P1 *)this)->_2_isLeap = trpt->bup.oval;
		;
		;
		goto R999;

	case 66: /* STATE 69 */
		;
		((P1 *)this)->_2_tomorrowDay = trpt->bup.oval;
		;
		goto R999;

	case 67: /* STATE 70 */
		;
		((P1 *)this)->_2_tomorrowMonth = trpt->bup.oval;
		;
		goto R999;
;
		;
		;
		;
		;
		;
		
	case 71: /* STATE 94 */
		;
		_m = unsend(((P1 *)this)->in_main);
		;
		goto R999;
;
		;
		
	case 73: /* STATE 97 */
		;
		p_restor(II);
		;
		;
		goto R999;

		 /* PROC input */

	case 74: /* STATE 2 */
		;
		((P0 *)this)->_1_1_value = trpt->bup.oval;
		;
		goto R999;

	case 75: /* STATE 7 */
		;
		_m = unsend(((P0 *)this)->in_input);
		;
		goto R999;

	case 76: /* STATE 9 */
		;
		p_restor(II);
		;
		;
		goto R999;
	}

