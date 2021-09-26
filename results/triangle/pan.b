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
		unrecv(((P1 *)this)->_2_ret_input, XX-1, 0, ((P1 *)this)->_2_a, 1);
		((P1 *)this)->_2_a = trpt->bup.oval;
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
		unrecv(((P1 *)this)->_2_ret_input, XX-1, 0, ((P1 *)this)->_2_b, 1);
		((P1 *)this)->_2_b = trpt->bup.oval;
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
		unrecv(((P1 *)this)->_2_ret_input, XX-1, 0, ((P1 *)this)->_2_c, 1);
		((P1 *)this)->_2_c = trpt->bup.oval;
		;
		;
		goto R999;
;
		;
		;
		;
		;
		;
		;
		;
		
	case 35: /* STATE 12 */
		;
		((P1 *)this)->_2_isATriangle = trpt->bup.oval;
		;
		goto R999;

	case 36: /* STATE 14 */
		;
		((P1 *)this)->_2_isATriangle = trpt->bup.oval;
		;
		goto R999;

	case 37: /* STATE 17 */
		;
	/* 0 */	((P1 *)this)->_2_isATriangle = trpt->bup.oval;
		;
		;
		goto R999;

	case 38: /* STATE 18 */
		;
	/* 2 */	((P1 *)this)->_2_c = trpt->bup.ovals[2];
	/* 1 */	((P1 *)this)->_2_b = trpt->bup.ovals[1];
	/* 0 */	((P1 *)this)->_2_a = trpt->bup.ovals[0];
		;
		;
		ungrab_ints(trpt->bup.ovals, 3);
		goto R999;

	case 39: /* STATE 21 */
		;
	/* 2 */	((P1 *)this)->_2_c = trpt->bup.ovals[2];
	/* 1 */	((P1 *)this)->_2_b = trpt->bup.ovals[1];
	/* 0 */	((P1 *)this)->_2_a = trpt->bup.ovals[0];
		;
		;
		ungrab_ints(trpt->bup.ovals, 3);
		goto R999;
;
		;
		;
		;
		
	case 42: /* STATE 33 */
		;
		_m = unsend(((P1 *)this)->in_main);
		;
		goto R999;
;
		;
		
	case 44: /* STATE 36 */
		;
		p_restor(II);
		;
		;
		goto R999;

		 /* PROC input */

	case 45: /* STATE 2 */
		;
		((P0 *)this)->_1_1_value = trpt->bup.oval;
		;
		goto R999;

	case 46: /* STATE 7 */
		;
		_m = unsend(((P0 *)this)->in_input);
		;
		goto R999;

	case 47: /* STATE 9 */
		;
		p_restor(II);
		;
		;
		goto R999;
	}

