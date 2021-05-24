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
		
	case 7: /* STATE 20 */
		;
		p_restor(II);
		;
		;
		goto R999;

		 /* PROC :init: */

	case 8: /* STATE 1 */
		;
		;
		delproc(0, now._nr_pr-1);
		;
		goto R999;

	case 9: /* STATE 2 */
		;
		XX = 1;
		unrecv(((P2 *)this)->_3_ret_main, XX-1, 0, 0, 1);
		;
		;
		goto R999;

	case 10: /* STATE 3 */
		;
		p_restor(II);
		;
		;
		goto R999;

		 /* PROC main */
;
		;
		;
		
	case 12: /* STATE 2 */
		goto R999;

	case 13: /* STATE 4 */
		;
		;
		delproc(0, now._nr_pr-1);
		;
		goto R999;

	case 14: /* STATE 5 */
		;
		XX = 1;
		unrecv(((P1 *)this)->_2_ret_input, XX-1, 0, now.main_a, 1);
		now.main_a = trpt->bup.oval;
		;
		;
		goto R999;

	case 15: /* STATE 6 */
		;
		;
		delproc(0, now._nr_pr-1);
		;
		goto R999;

	case 16: /* STATE 7 */
		;
		XX = 1;
		unrecv(((P1 *)this)->_2_ret_input, XX-1, 0, now.main_b, 1);
		now.main_b = trpt->bup.oval;
		;
		;
		goto R999;

	case 17: /* STATE 8 */
		;
		;
		delproc(0, now._nr_pr-1);
		;
		goto R999;

	case 18: /* STATE 9 */
		;
		XX = 1;
		unrecv(((P1 *)this)->_2_ret_input, XX-1, 0, now.main_c, 1);
		now.main_c = trpt->bup.oval;
		;
		;
		goto R999;

	case 19: /* STATE 10 */
		;
		now.main_c1 = trpt->bup.oval;
		;
		goto R999;

	case 20: /* STATE 11 */
		;
		now.main_c2 = trpt->bup.oval;
		;
		goto R999;

	case 21: /* STATE 12 */
		;
		now.main_c3 = trpt->bup.oval;
		;
		goto R999;
;
		;
		
	case 23: /* STATE 15 */
		;
		main_condition_11_copy = trpt->bup.oval;
		;
		goto R999;

	case 24: /* STATE 17 */
		;
		now.reset = trpt->bup.oval;
		;
		goto R999;
;
		
	case 25: /* STATE 20 */
		goto R999;
;
		;
		
	case 27: /* STATE 30 */
		;
		main_condition_21_copy = trpt->bup.oval;
		;
		goto R999;

	case 28: /* STATE 32 */
		;
		now.reset = trpt->bup.oval;
		;
		goto R999;
;
		
	case 29: /* STATE 35 */
		goto R999;
;
		;
		
	case 31: /* STATE 45 */
		;
		main_condition_31_copy = trpt->bup.oval;
		;
		goto R999;

	case 32: /* STATE 47 */
		;
		now.reset = trpt->bup.oval;
		;
		goto R999;
;
		
	case 33: /* STATE 50 */
		goto R999;
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
		
	case 39: /* STATE 72 */
		;
		main_condition_43_copy = trpt->bup.ovals[3];
		main_condition_42_copy = trpt->bup.ovals[2];
		main_condition_41_copy = trpt->bup.ovals[1];
		now.main_isATriangle = trpt->bup.ovals[0];
		;
		ungrab_ints(trpt->bup.ovals, 4);
		goto R999;

	case 40: /* STATE 74 */
		;
		now.reset = trpt->bup.oval;
		;
		goto R999;
;
		
	case 41: /* STATE 77 */
		goto R999;

	case 42: /* STATE 82 */
		;
		now.main_isATriangle = trpt->bup.oval;
		;
		goto R999;
;
		;
		
	case 44: /* STATE 97 */
		;
		main_condition_51_copy = trpt->bup.oval;
		;
		goto R999;

	case 45: /* STATE 97 */
		;
		main_condition_51_copy = trpt->bup.oval;
		;
		goto R999;

	case 46: /* STATE 97 */
		;
		main_condition_51_copy = trpt->bup.oval;
		;
		goto R999;

	case 47: /* STATE 97 */
		;
		main_condition_51_copy = trpt->bup.oval;
		;
		goto R999;

	case 48: /* STATE 99 */
		;
		now.reset = trpt->bup.oval;
		;
		goto R999;
;
		
	case 49: /* STATE 102 */
		goto R999;
;
		;
		
	case 51: /* STATE 110 */
		;
		_m = unsend(((P1 *)this)->in_main);
		;
		goto R999;
;
		;
		
	case 53: /* STATE 113 */
		;
		p_restor(II);
		;
		;
		goto R999;

		 /* PROC input */

	case 54: /* STATE 2 */
		;
		((P0 *)this)->_1_1_value = trpt->bup.oval;
		;
		goto R999;

	case 55: /* STATE 7 */
		;
		_m = unsend(((P0 *)this)->in_input);
		;
		goto R999;

	case 56: /* STATE 9 */
		;
		p_restor(II);
		;
		;
		goto R999;
	}

