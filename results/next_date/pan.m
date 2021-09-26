#define rand	pan_rand
#if defined(HAS_CODE) && defined(VERBOSE)
	cpu_printf("Pr: %d Tr: %d\n", II, t->forw);
#endif
	switch (t->forw) {
	default: Uerror("bad forward move");
	case 0:	/* if without executable clauses */
		continue;
	case 1: /* generic 'goto' or 'skip' */
		IfNotBlocked
		_m = 3; goto P999;
	case 2: /* generic 'else' */
		IfNotBlocked
		if (trpt->o_pm&1) continue;
		_m = 3; goto P999;

		 /* CLAIM never_0 */
	case 3: /* STATE 1 - next_date_dft.pml.nvr:5 - [((main._p==d_isLeap_v13))] (0:0:0 - 1) */
		
#if defined(VERI) && !defined(NP)
#if NCLAIMS>1
		{	static int reported1 = 0; int nn = (int) ((Pclaim *)this)->_n;
			if (verbose && !reported1)
			{	printf("depth %ld: Claim %s (%d), state %d (line %d)\n",
					depth, procname[spin_c_typ[nn]], nn, (int) ((Pclaim *)this)->_p, src_claim[ (int) ((Pclaim *)this)->_p ]);
				reported1 = 1;
				fflush(stdout);
		}	}
#else
{	static int reported1 = 0;
			if (verbose && !reported1)
			{	printf("depth %d: Claim, state %d (line %d)\n",
					(int) depth, (int) ((Pclaim *)this)->_p, src_claim[ (int) ((Pclaim *)this)->_p ]);
				reported1 = 1;
				fflush(stdout);
		}	}
#endif
#endif
		reached[3][1] = 1;
		if (!((((int)((P1 *)Pptr(f_pid(1)))->_p)==10)))
			continue;
		_m = 3; goto P999; /* 0 */
	case 4: /* STATE 9 - next_date_dft.pml.nvr:11 - [(((main._p==end)&&(main._p==u_isLeap_v45)))] (0:0:0 - 1) */
		
#if defined(VERI) && !defined(NP)
#if NCLAIMS>1
		{	static int reported9 = 0; int nn = (int) ((Pclaim *)this)->_n;
			if (verbose && !reported9)
			{	printf("depth %ld: Claim %s (%d), state %d (line %d)\n",
					depth, procname[spin_c_typ[nn]], nn, (int) ((Pclaim *)this)->_p, src_claim[ (int) ((Pclaim *)this)->_p ]);
				reported9 = 1;
				fflush(stdout);
		}	}
#else
{	static int reported9 = 0;
			if (verbose && !reported9)
			{	printf("depth %d: Claim, state %d (line %d)\n",
					(int) depth, (int) ((Pclaim *)this)->_p, src_claim[ (int) ((Pclaim *)this)->_p ]);
				reported9 = 1;
				fflush(stdout);
		}	}
#endif
#endif
		reached[3][9] = 1;
		if (!(((((int)((P1 *)Pptr(f_pid(1)))->_p)==96)&&(((int)((P1 *)Pptr(f_pid(1)))->_p)==73))))
			continue;
		_m = 3; goto P999; /* 0 */
	case 5: /* STATE 11 - next_date_dft.pml.nvr:12 - [((main._p==u_isLeap_v45))] (0:0:0 - 1) */
		
#if defined(VERI) && !defined(NP)
#if NCLAIMS>1
		{	static int reported11 = 0; int nn = (int) ((Pclaim *)this)->_n;
			if (verbose && !reported11)
			{	printf("depth %ld: Claim %s (%d), state %d (line %d)\n",
					depth, procname[spin_c_typ[nn]], nn, (int) ((Pclaim *)this)->_p, src_claim[ (int) ((Pclaim *)this)->_p ]);
				reported11 = 1;
				fflush(stdout);
		}	}
#else
{	static int reported11 = 0;
			if (verbose && !reported11)
			{	printf("depth %d: Claim, state %d (line %d)\n",
					(int) depth, (int) ((Pclaim *)this)->_p, src_claim[ (int) ((Pclaim *)this)->_p ]);
				reported11 = 1;
				fflush(stdout);
		}	}
#endif
#endif
		reached[3][11] = 1;
		if (!((((int)((P1 *)Pptr(f_pid(1)))->_p)==73)))
			continue;
		_m = 3; goto P999; /* 0 */
	case 6: /* STATE 13 - next_date_dft.pml.nvr:13 - [(!((main._p==d_isLeap_v13)))] (0:0:0 - 1) */
		
#if defined(VERI) && !defined(NP)
#if NCLAIMS>1
		{	static int reported13 = 0; int nn = (int) ((Pclaim *)this)->_n;
			if (verbose && !reported13)
			{	printf("depth %ld: Claim %s (%d), state %d (line %d)\n",
					depth, procname[spin_c_typ[nn]], nn, (int) ((Pclaim *)this)->_p, src_claim[ (int) ((Pclaim *)this)->_p ]);
				reported13 = 1;
				fflush(stdout);
		}	}
#else
{	static int reported13 = 0;
			if (verbose && !reported13)
			{	printf("depth %d: Claim, state %d (line %d)\n",
					(int) depth, (int) ((Pclaim *)this)->_p, src_claim[ (int) ((Pclaim *)this)->_p ]);
				reported13 = 1;
				fflush(stdout);
		}	}
#endif
#endif
		reached[3][13] = 1;
		if (!( !((((int)((P1 *)Pptr(f_pid(1)))->_p)==10))))
			continue;
		_m = 3; goto P999; /* 0 */
	case 7: /* STATE 17 - next_date_dft.pml.nvr:17 - [((main._p==d_isLeap_v13))] (0:0:0 - 1) */
		
#if defined(VERI) && !defined(NP)
#if NCLAIMS>1
		{	static int reported17 = 0; int nn = (int) ((Pclaim *)this)->_n;
			if (verbose && !reported17)
			{	printf("depth %ld: Claim %s (%d), state %d (line %d)\n",
					depth, procname[spin_c_typ[nn]], nn, (int) ((Pclaim *)this)->_p, src_claim[ (int) ((Pclaim *)this)->_p ]);
				reported17 = 1;
				fflush(stdout);
		}	}
#else
{	static int reported17 = 0;
			if (verbose && !reported17)
			{	printf("depth %d: Claim, state %d (line %d)\n",
					(int) depth, (int) ((Pclaim *)this)->_p, src_claim[ (int) ((Pclaim *)this)->_p ]);
				reported17 = 1;
				fflush(stdout);
		}	}
#endif
#endif
		reached[3][17] = 1;
		if (!((((int)((P1 *)Pptr(f_pid(1)))->_p)==10)))
			continue;
		_m = 3; goto P999; /* 0 */
	case 8: /* STATE 23 - next_date_dft.pml.nvr:22 - [((main._p==end))] (0:0:0 - 1) */
		
#if defined(VERI) && !defined(NP)
#if NCLAIMS>1
		{	static int reported23 = 0; int nn = (int) ((Pclaim *)this)->_n;
			if (verbose && !reported23)
			{	printf("depth %ld: Claim %s (%d), state %d (line %d)\n",
					depth, procname[spin_c_typ[nn]], nn, (int) ((Pclaim *)this)->_p, src_claim[ (int) ((Pclaim *)this)->_p ]);
				reported23 = 1;
				fflush(stdout);
		}	}
#else
{	static int reported23 = 0;
			if (verbose && !reported23)
			{	printf("depth %d: Claim, state %d (line %d)\n",
					(int) depth, (int) ((Pclaim *)this)->_p, src_claim[ (int) ((Pclaim *)this)->_p ]);
				reported23 = 1;
				fflush(stdout);
		}	}
#endif
#endif
		reached[3][23] = 1;
		if (!((((int)((P1 *)Pptr(f_pid(1)))->_p)==96)))
			continue;
		_m = 3; goto P999; /* 0 */
	case 9: /* STATE 29 - next_date_dft.pml.nvr:27 - [(((main._p==end)&&(main._p==d_isLeap_v13)))] (0:0:0 - 1) */
		
#if defined(VERI) && !defined(NP)
#if NCLAIMS>1
		{	static int reported29 = 0; int nn = (int) ((Pclaim *)this)->_n;
			if (verbose && !reported29)
			{	printf("depth %ld: Claim %s (%d), state %d (line %d)\n",
					depth, procname[spin_c_typ[nn]], nn, (int) ((Pclaim *)this)->_p, src_claim[ (int) ((Pclaim *)this)->_p ]);
				reported29 = 1;
				fflush(stdout);
		}	}
#else
{	static int reported29 = 0;
			if (verbose && !reported29)
			{	printf("depth %d: Claim, state %d (line %d)\n",
					(int) depth, (int) ((Pclaim *)this)->_p, src_claim[ (int) ((Pclaim *)this)->_p ]);
				reported29 = 1;
				fflush(stdout);
		}	}
#endif
#endif
		reached[3][29] = 1;
		if (!(((((int)((P1 *)Pptr(f_pid(1)))->_p)==96)&&(((int)((P1 *)Pptr(f_pid(1)))->_p)==10))))
			continue;
		_m = 3; goto P999; /* 0 */
	case 10: /* STATE 31 - next_date_dft.pml.nvr:28 - [((main._p==end))] (0:0:0 - 1) */
		
#if defined(VERI) && !defined(NP)
#if NCLAIMS>1
		{	static int reported31 = 0; int nn = (int) ((Pclaim *)this)->_n;
			if (verbose && !reported31)
			{	printf("depth %ld: Claim %s (%d), state %d (line %d)\n",
					depth, procname[spin_c_typ[nn]], nn, (int) ((Pclaim *)this)->_p, src_claim[ (int) ((Pclaim *)this)->_p ]);
				reported31 = 1;
				fflush(stdout);
		}	}
#else
{	static int reported31 = 0;
			if (verbose && !reported31)
			{	printf("depth %d: Claim, state %d (line %d)\n",
					(int) depth, (int) ((Pclaim *)this)->_p, src_claim[ (int) ((Pclaim *)this)->_p ]);
				reported31 = 1;
				fflush(stdout);
		}	}
#endif
#endif
		reached[3][31] = 1;
		if (!((((int)((P1 *)Pptr(f_pid(1)))->_p)==96)))
			continue;
		_m = 3; goto P999; /* 0 */
	case 11: /* STATE 33 - next_date_dft.pml.nvr:29 - [((main._p==d_isLeap_v13))] (0:0:0 - 1) */
		
#if defined(VERI) && !defined(NP)
#if NCLAIMS>1
		{	static int reported33 = 0; int nn = (int) ((Pclaim *)this)->_n;
			if (verbose && !reported33)
			{	printf("depth %ld: Claim %s (%d), state %d (line %d)\n",
					depth, procname[spin_c_typ[nn]], nn, (int) ((Pclaim *)this)->_p, src_claim[ (int) ((Pclaim *)this)->_p ]);
				reported33 = 1;
				fflush(stdout);
		}	}
#else
{	static int reported33 = 0;
			if (verbose && !reported33)
			{	printf("depth %d: Claim, state %d (line %d)\n",
					(int) depth, (int) ((Pclaim *)this)->_p, src_claim[ (int) ((Pclaim *)this)->_p ]);
				reported33 = 1;
				fflush(stdout);
		}	}
#endif
#endif
		reached[3][33] = 1;
		if (!((((int)((P1 *)Pptr(f_pid(1)))->_p)==10)))
			continue;
		_m = 3; goto P999; /* 0 */
	case 12: /* STATE 39 - next_date_dft.pml.nvr:34 - [(((main._p==end)&&(main._p==u_isLeap_v45)))] (0:0:0 - 1) */
		
#if defined(VERI) && !defined(NP)
#if NCLAIMS>1
		{	static int reported39 = 0; int nn = (int) ((Pclaim *)this)->_n;
			if (verbose && !reported39)
			{	printf("depth %ld: Claim %s (%d), state %d (line %d)\n",
					depth, procname[spin_c_typ[nn]], nn, (int) ((Pclaim *)this)->_p, src_claim[ (int) ((Pclaim *)this)->_p ]);
				reported39 = 1;
				fflush(stdout);
		}	}
#else
{	static int reported39 = 0;
			if (verbose && !reported39)
			{	printf("depth %d: Claim, state %d (line %d)\n",
					(int) depth, (int) ((Pclaim *)this)->_p, src_claim[ (int) ((Pclaim *)this)->_p ]);
				reported39 = 1;
				fflush(stdout);
		}	}
#endif
#endif
		reached[3][39] = 1;
		if (!(((((int)((P1 *)Pptr(f_pid(1)))->_p)==96)&&(((int)((P1 *)Pptr(f_pid(1)))->_p)==73))))
			continue;
		_m = 3; goto P999; /* 0 */
	case 13: /* STATE 41 - next_date_dft.pml.nvr:35 - [((main._p==u_isLeap_v45))] (0:0:0 - 1) */
		
#if defined(VERI) && !defined(NP)
#if NCLAIMS>1
		{	static int reported41 = 0; int nn = (int) ((Pclaim *)this)->_n;
			if (verbose && !reported41)
			{	printf("depth %ld: Claim %s (%d), state %d (line %d)\n",
					depth, procname[spin_c_typ[nn]], nn, (int) ((Pclaim *)this)->_p, src_claim[ (int) ((Pclaim *)this)->_p ]);
				reported41 = 1;
				fflush(stdout);
		}	}
#else
{	static int reported41 = 0;
			if (verbose && !reported41)
			{	printf("depth %d: Claim, state %d (line %d)\n",
					(int) depth, (int) ((Pclaim *)this)->_p, src_claim[ (int) ((Pclaim *)this)->_p ]);
				reported41 = 1;
				fflush(stdout);
		}	}
#endif
#endif
		reached[3][41] = 1;
		if (!((((int)((P1 *)Pptr(f_pid(1)))->_p)==73)))
			continue;
		_m = 3; goto P999; /* 0 */
	case 14: /* STATE 43 - next_date_dft.pml.nvr:36 - [(!((main._p==d_isLeap_v13)))] (0:0:0 - 1) */
		
#if defined(VERI) && !defined(NP)
#if NCLAIMS>1
		{	static int reported43 = 0; int nn = (int) ((Pclaim *)this)->_n;
			if (verbose && !reported43)
			{	printf("depth %ld: Claim %s (%d), state %d (line %d)\n",
					depth, procname[spin_c_typ[nn]], nn, (int) ((Pclaim *)this)->_p, src_claim[ (int) ((Pclaim *)this)->_p ]);
				reported43 = 1;
				fflush(stdout);
		}	}
#else
{	static int reported43 = 0;
			if (verbose && !reported43)
			{	printf("depth %d: Claim, state %d (line %d)\n",
					(int) depth, (int) ((Pclaim *)this)->_p, src_claim[ (int) ((Pclaim *)this)->_p ]);
				reported43 = 1;
				fflush(stdout);
		}	}
#endif
#endif
		reached[3][43] = 1;
		if (!( !((((int)((P1 *)Pptr(f_pid(1)))->_p)==10))))
			continue;
		_m = 3; goto P999; /* 0 */
	case 15: /* STATE 47 - next_date_dft.pml.nvr:40 - [((((main._p==end)&&(main._p==d_isLeap_v13))&&(main._p==u_isLeap_v45)))] (0:0:0 - 1) */
		
#if defined(VERI) && !defined(NP)
#if NCLAIMS>1
		{	static int reported47 = 0; int nn = (int) ((Pclaim *)this)->_n;
			if (verbose && !reported47)
			{	printf("depth %ld: Claim %s (%d), state %d (line %d)\n",
					depth, procname[spin_c_typ[nn]], nn, (int) ((Pclaim *)this)->_p, src_claim[ (int) ((Pclaim *)this)->_p ]);
				reported47 = 1;
				fflush(stdout);
		}	}
#else
{	static int reported47 = 0;
			if (verbose && !reported47)
			{	printf("depth %d: Claim, state %d (line %d)\n",
					(int) depth, (int) ((Pclaim *)this)->_p, src_claim[ (int) ((Pclaim *)this)->_p ]);
				reported47 = 1;
				fflush(stdout);
		}	}
#endif
#endif
		reached[3][47] = 1;
		if (!((((((int)((P1 *)Pptr(f_pid(1)))->_p)==96)&&(((int)((P1 *)Pptr(f_pid(1)))->_p)==10))&&(((int)((P1 *)Pptr(f_pid(1)))->_p)==73))))
			continue;
		_m = 3; goto P999; /* 0 */
	case 16: /* STATE 49 - next_date_dft.pml.nvr:41 - [(((main._p==end)&&(main._p==u_isLeap_v45)))] (0:0:0 - 1) */
		
#if defined(VERI) && !defined(NP)
#if NCLAIMS>1
		{	static int reported49 = 0; int nn = (int) ((Pclaim *)this)->_n;
			if (verbose && !reported49)
			{	printf("depth %ld: Claim %s (%d), state %d (line %d)\n",
					depth, procname[spin_c_typ[nn]], nn, (int) ((Pclaim *)this)->_p, src_claim[ (int) ((Pclaim *)this)->_p ]);
				reported49 = 1;
				fflush(stdout);
		}	}
#else
{	static int reported49 = 0;
			if (verbose && !reported49)
			{	printf("depth %d: Claim, state %d (line %d)\n",
					(int) depth, (int) ((Pclaim *)this)->_p, src_claim[ (int) ((Pclaim *)this)->_p ]);
				reported49 = 1;
				fflush(stdout);
		}	}
#endif
#endif
		reached[3][49] = 1;
		if (!(((((int)((P1 *)Pptr(f_pid(1)))->_p)==96)&&(((int)((P1 *)Pptr(f_pid(1)))->_p)==73))))
			continue;
		_m = 3; goto P999; /* 0 */
	case 17: /* STATE 51 - next_date_dft.pml.nvr:42 - [(((main._p==d_isLeap_v13)&&(main._p==u_isLeap_v45)))] (0:0:0 - 1) */
		
#if defined(VERI) && !defined(NP)
#if NCLAIMS>1
		{	static int reported51 = 0; int nn = (int) ((Pclaim *)this)->_n;
			if (verbose && !reported51)
			{	printf("depth %ld: Claim %s (%d), state %d (line %d)\n",
					depth, procname[spin_c_typ[nn]], nn, (int) ((Pclaim *)this)->_p, src_claim[ (int) ((Pclaim *)this)->_p ]);
				reported51 = 1;
				fflush(stdout);
		}	}
#else
{	static int reported51 = 0;
			if (verbose && !reported51)
			{	printf("depth %d: Claim, state %d (line %d)\n",
					(int) depth, (int) ((Pclaim *)this)->_p, src_claim[ (int) ((Pclaim *)this)->_p ]);
				reported51 = 1;
				fflush(stdout);
		}	}
#endif
#endif
		reached[3][51] = 1;
		if (!(((((int)((P1 *)Pptr(f_pid(1)))->_p)==10)&&(((int)((P1 *)Pptr(f_pid(1)))->_p)==73))))
			continue;
		_m = 3; goto P999; /* 0 */
	case 18: /* STATE 53 - next_date_dft.pml.nvr:43 - [((main._p==u_isLeap_v45))] (0:0:0 - 1) */
		
#if defined(VERI) && !defined(NP)
#if NCLAIMS>1
		{	static int reported53 = 0; int nn = (int) ((Pclaim *)this)->_n;
			if (verbose && !reported53)
			{	printf("depth %ld: Claim %s (%d), state %d (line %d)\n",
					depth, procname[spin_c_typ[nn]], nn, (int) ((Pclaim *)this)->_p, src_claim[ (int) ((Pclaim *)this)->_p ]);
				reported53 = 1;
				fflush(stdout);
		}	}
#else
{	static int reported53 = 0;
			if (verbose && !reported53)
			{	printf("depth %d: Claim, state %d (line %d)\n",
					(int) depth, (int) ((Pclaim *)this)->_p, src_claim[ (int) ((Pclaim *)this)->_p ]);
				reported53 = 1;
				fflush(stdout);
		}	}
#endif
#endif
		reached[3][53] = 1;
		if (!((((int)((P1 *)Pptr(f_pid(1)))->_p)==73)))
			continue;
		_m = 3; goto P999; /* 0 */
	case 19: /* STATE 55 - next_date_dft.pml.nvr:44 - [(!((main._p==d_isLeap_v13)))] (0:0:0 - 1) */
		
#if defined(VERI) && !defined(NP)
#if NCLAIMS>1
		{	static int reported55 = 0; int nn = (int) ((Pclaim *)this)->_n;
			if (verbose && !reported55)
			{	printf("depth %ld: Claim %s (%d), state %d (line %d)\n",
					depth, procname[spin_c_typ[nn]], nn, (int) ((Pclaim *)this)->_p, src_claim[ (int) ((Pclaim *)this)->_p ]);
				reported55 = 1;
				fflush(stdout);
		}	}
#else
{	static int reported55 = 0;
			if (verbose && !reported55)
			{	printf("depth %d: Claim, state %d (line %d)\n",
					(int) depth, (int) ((Pclaim *)this)->_p, src_claim[ (int) ((Pclaim *)this)->_p ]);
				reported55 = 1;
				fflush(stdout);
		}	}
#endif
#endif
		reached[3][55] = 1;
		if (!( !((((int)((P1 *)Pptr(f_pid(1)))->_p)==10))))
			continue;
		_m = 3; goto P999; /* 0 */
	case 20: /* STATE 60 - next_date_dft.pml.nvr:48 - [-end-] (0:0:0 - 1) */
		
#if defined(VERI) && !defined(NP)
#if NCLAIMS>1
		{	static int reported60 = 0; int nn = (int) ((Pclaim *)this)->_n;
			if (verbose && !reported60)
			{	printf("depth %ld: Claim %s (%d), state %d (line %d)\n",
					depth, procname[spin_c_typ[nn]], nn, (int) ((Pclaim *)this)->_p, src_claim[ (int) ((Pclaim *)this)->_p ]);
				reported60 = 1;
				fflush(stdout);
		}	}
#else
{	static int reported60 = 0;
			if (verbose && !reported60)
			{	printf("depth %d: Claim, state %d (line %d)\n",
					(int) depth, (int) ((Pclaim *)this)->_p, src_claim[ (int) ((Pclaim *)this)->_p ]);
				reported60 = 1;
				fflush(stdout);
		}	}
#endif
#endif
		reached[3][60] = 1;
		if (!delproc(1, II)) continue;
		_m = 3; goto P999; /* 0 */

		 /* PROC :init: */
	case 21: /* STATE 1 - next_date_dft.pml:179 - [(run main(ret_main))] (0:0:0 - 1) */
		IfNotBlocked
		reached[2][1] = 1;
		if (!(addproc(1, ((P2 *)this)->_3_ret_main, 0, 0)))
			continue;
		_m = 3; goto P999; /* 0 */
	case 22: /* STATE 2 - next_date_dft.pml:180 - [ret_main?0] (0:0:0 - 1) */
		reached[2][2] = 1;
		if (boq != ((P2 *)this)->_3_ret_main) continue;
		if (q_len(((P2 *)this)->_3_ret_main) == 0) continue;

		XX=1;
		if (0 != qrecv(((P2 *)this)->_3_ret_main, 0, 0, 0)) continue;
		if (q_flds[((Q0 *)qptr(((P2 *)this)->_3_ret_main-1))->_t] != 1)
			Uerror("wrong nr of msg fields in rcv");
		;
		qrecv(((P2 *)this)->_3_ret_main, XX-1, 0, 1);
		
#ifdef HAS_CODE
		if (readtrail && gui) {
			char simtmp[32];
			sprintf(simvals, "%d?", ((P2 *)this)->_3_ret_main);
		sprintf(simtmp, "%d", 0); strcat(simvals, simtmp);		}
#endif
		if (q_zero(((P2 *)this)->_3_ret_main))
		{	boq = -1;
#ifndef NOFAIR
			if (fairness
			&& !(trpt->o_pm&32)
			&& (now._a_t&2)
			&&  now._cnt[now._a_t&1] == II+2)
			{	now._cnt[now._a_t&1] -= 1;
#ifdef VERI
				if (II == 1)
					now._cnt[now._a_t&1] = 1;
#endif
#ifdef DEBUG
			printf("%3d: proc %d fairness ", depth, II);
			printf("Rule 2: --cnt to %d (%d)\n",
				now._cnt[now._a_t&1], now._a_t);
#endif
				trpt->o_pm |= (32|64);
			}
#endif

		};
		_m = 4; goto P999; /* 0 */
	case 23: /* STATE 3 - next_date_dft.pml:181 - [-end-] (0:0:0 - 1) */
		IfNotBlocked
		reached[2][3] = 1;
		if (!delproc(1, II)) continue;
		_m = 3; goto P999; /* 0 */

		 /* PROC main */
	case 24: /* STATE 1 - next_date_dft.pml:73 - [printf('Enter date in the form MM DD YYYY ')] (0:0:0 - 1) */
		IfNotBlocked
		reached[1][1] = 1;
		Printf("Enter date in the form MM DD YYYY ");
		_m = 3; goto P999; /* 0 */
	case 25: /* STATE 2 - next_date_dft.pml:75 - [(run input(ret_input,1,12))] (0:0:0 - 1) */
		IfNotBlocked
		reached[1][2] = 1;
		if (!(addproc(0, ((P1 *)this)->_2_ret_input, 1, 12)))
			continue;
		_m = 3; goto P999; /* 0 */
	case 26: /* STATE 3 - next_date_dft.pml:76 - [ret_input?month] (0:0:1 - 1) */
		reached[1][3] = 1;
		if (boq != ((P1 *)this)->_2_ret_input) continue;
		if (q_len(((P1 *)this)->_2_ret_input) == 0) continue;

		XX=1;
		(trpt+1)->bup.oval = ((P1 *)this)->_2_month;
		;
		((P1 *)this)->_2_month = qrecv(((P1 *)this)->_2_ret_input, XX-1, 0, 1);
#ifdef VAR_RANGES
		logval("main:month", ((P1 *)this)->_2_month);
#endif
		;
		
#ifdef HAS_CODE
		if (readtrail && gui) {
			char simtmp[32];
			sprintf(simvals, "%d?", ((P1 *)this)->_2_ret_input);
		sprintf(simtmp, "%d", ((P1 *)this)->_2_month); strcat(simvals, simtmp);		}
#endif
		if (q_zero(((P1 *)this)->_2_ret_input))
		{	boq = -1;
#ifndef NOFAIR
			if (fairness
			&& !(trpt->o_pm&32)
			&& (now._a_t&2)
			&&  now._cnt[now._a_t&1] == II+2)
			{	now._cnt[now._a_t&1] -= 1;
#ifdef VERI
				if (II == 1)
					now._cnt[now._a_t&1] = 1;
#endif
#ifdef DEBUG
			printf("%3d: proc %d fairness ", depth, II);
			printf("Rule 2: --cnt to %d (%d)\n",
				now._cnt[now._a_t&1], now._a_t);
#endif
				trpt->o_pm |= (32|64);
			}
#endif

		};
		_m = 4; goto P999; /* 0 */
	case 27: /* STATE 4 - next_date_dft.pml:77 - [(run input(ret_input,1,31))] (0:0:0 - 1) */
		IfNotBlocked
		reached[1][4] = 1;
		if (!(addproc(0, ((P1 *)this)->_2_ret_input, 1, 31)))
			continue;
		_m = 3; goto P999; /* 0 */
	case 28: /* STATE 5 - next_date_dft.pml:78 - [ret_input?day] (0:0:1 - 1) */
		reached[1][5] = 1;
		if (boq != ((P1 *)this)->_2_ret_input) continue;
		if (q_len(((P1 *)this)->_2_ret_input) == 0) continue;

		XX=1;
		(trpt+1)->bup.oval = ((P1 *)this)->_2_day;
		;
		((P1 *)this)->_2_day = qrecv(((P1 *)this)->_2_ret_input, XX-1, 0, 1);
#ifdef VAR_RANGES
		logval("main:day", ((P1 *)this)->_2_day);
#endif
		;
		
#ifdef HAS_CODE
		if (readtrail && gui) {
			char simtmp[32];
			sprintf(simvals, "%d?", ((P1 *)this)->_2_ret_input);
		sprintf(simtmp, "%d", ((P1 *)this)->_2_day); strcat(simvals, simtmp);		}
#endif
		if (q_zero(((P1 *)this)->_2_ret_input))
		{	boq = -1;
#ifndef NOFAIR
			if (fairness
			&& !(trpt->o_pm&32)
			&& (now._a_t&2)
			&&  now._cnt[now._a_t&1] == II+2)
			{	now._cnt[now._a_t&1] -= 1;
#ifdef VERI
				if (II == 1)
					now._cnt[now._a_t&1] = 1;
#endif
#ifdef DEBUG
			printf("%3d: proc %d fairness ", depth, II);
			printf("Rule 2: --cnt to %d (%d)\n",
				now._cnt[now._a_t&1], now._a_t);
#endif
				trpt->o_pm |= (32|64);
			}
#endif

		};
		_m = 4; goto P999; /* 0 */
	case 29: /* STATE 6 - next_date_dft.pml:79 - [(run input(ret_input,2000,2021))] (0:0:0 - 1) */
		IfNotBlocked
		reached[1][6] = 1;
		if (!(addproc(0, ((P1 *)this)->_2_ret_input, 2000, 2021)))
			continue;
		_m = 3; goto P999; /* 0 */
	case 30: /* STATE 7 - next_date_dft.pml:80 - [ret_input?year] (0:0:1 - 1) */
		reached[1][7] = 1;
		if (boq != ((P1 *)this)->_2_ret_input) continue;
		if (q_len(((P1 *)this)->_2_ret_input) == 0) continue;

		XX=1;
		(trpt+1)->bup.oval = ((P1 *)this)->_2_year;
		;
		((P1 *)this)->_2_year = qrecv(((P1 *)this)->_2_ret_input, XX-1, 0, 1);
#ifdef VAR_RANGES
		logval("main:year", ((P1 *)this)->_2_year);
#endif
		;
		
#ifdef HAS_CODE
		if (readtrail && gui) {
			char simtmp[32];
			sprintf(simvals, "%d?", ((P1 *)this)->_2_ret_input);
		sprintf(simtmp, "%d", ((P1 *)this)->_2_year); strcat(simvals, simtmp);		}
#endif
		if (q_zero(((P1 *)this)->_2_ret_input))
		{	boq = -1;
#ifndef NOFAIR
			if (fairness
			&& !(trpt->o_pm&32)
			&& (now._a_t&2)
			&&  now._cnt[now._a_t&1] == II+2)
			{	now._cnt[now._a_t&1] -= 1;
#ifdef VERI
				if (II == 1)
					now._cnt[now._a_t&1] = 1;
#endif
#ifdef DEBUG
			printf("%3d: proc %d fairness ", depth, II);
			printf("Rule 2: --cnt to %d (%d)\n",
				now._cnt[now._a_t&1], now._a_t);
#endif
				trpt->o_pm |= (32|64);
			}
#endif

		};
		_m = 4; goto P999; /* 0 */
	case 31: /* STATE 8 - next_date_dft.pml:82 - [tomorrowMonth = month] (0:0:1 - 1) */
		IfNotBlocked
		reached[1][8] = 1;
		(trpt+1)->bup.oval = ((P1 *)this)->_2_tomorrowMonth;
		((P1 *)this)->_2_tomorrowMonth = ((P1 *)this)->_2_month;
#ifdef VAR_RANGES
		logval("main:tomorrowMonth", ((P1 *)this)->_2_tomorrowMonth);
#endif
		;
		_m = 3; goto P999; /* 0 */
	case 32: /* STATE 9 - next_date_dft.pml:83 - [tomorrowYear = year] (0:0:1 - 1) */
		IfNotBlocked
		reached[1][9] = 1;
		(trpt+1)->bup.oval = ((P1 *)this)->_2_tomorrowYear;
		((P1 *)this)->_2_tomorrowYear = ((P1 *)this)->_2_year;
#ifdef VAR_RANGES
		logval("main:tomorrowYear", ((P1 *)this)->_2_tomorrowYear);
#endif
		;
		_m = 3; goto P999; /* 0 */
	case 33: /* STATE 10 - next_date_dft.pml:84 - [isLeap = (((year%4)==0)&&(((year%100)!=0)||((year%400)==0)))] (0:0:1 - 1) */
		IfNotBlocked
		reached[1][10] = 1;
		(trpt+1)->bup.oval = ((int)((P1 *)this)->_2_isLeap);
		((P1 *)this)->_2_isLeap = (((((P1 *)this)->_2_year%4)==0)&&(((((P1 *)this)->_2_year%100)!=0)||((((P1 *)this)->_2_year%400)==0)));
#ifdef VAR_RANGES
		logval("main:isLeap", ((int)((P1 *)this)->_2_isLeap));
#endif
		;
		_m = 3; goto P999; /* 0 */
	case 34: /* STATE 11 - next_date_dft.pml:86 - [(((((((month==1)||(month==3))||(month==5))||(month==7))||(month==8))||(month==10)))] (0:0:0 - 1) */
		IfNotBlocked
		reached[1][11] = 1;
		if (!(((((((((P1 *)this)->_2_month==1)||(((P1 *)this)->_2_month==3))||(((P1 *)this)->_2_month==5))||(((P1 *)this)->_2_month==7))||(((P1 *)this)->_2_month==8))||(((P1 *)this)->_2_month==10))))
			continue;
		_m = 3; goto P999; /* 0 */
	case 35: /* STATE 12 - next_date_dft.pml:88 - [((day<31))] (0:0:0 - 1) */
		IfNotBlocked
		reached[1][12] = 1;
		if (!((((P1 *)this)->_2_day<31)))
			continue;
		_m = 3; goto P999; /* 0 */
	case 36: /* STATE 13 - next_date_dft.pml:89 - [tomorrowDay = (day+1)] (0:0:1 - 1) */
		IfNotBlocked
		reached[1][13] = 1;
		(trpt+1)->bup.oval = ((P1 *)this)->_2_tomorrowDay;
		((P1 *)this)->_2_tomorrowDay = (((P1 *)this)->_2_day+1);
#ifdef VAR_RANGES
		logval("main:tomorrowDay", ((P1 *)this)->_2_tomorrowDay);
#endif
		;
		_m = 3; goto P999; /* 0 */
	case 37: /* STATE 15 - next_date_dft.pml:92 - [((day==31))] (0:0:1 - 1) */
		IfNotBlocked
		reached[1][15] = 1;
		if (!((((P1 *)this)->_2_day==31)))
			continue;
		/* dead 1: _2_day */  (trpt+1)->bup.oval = ((P1 *)this)->_2_day;
#ifdef HAS_CODE
		if (!readtrail)
#endif
			((P1 *)this)->_2_day = 0;
		_m = 3; goto P999; /* 0 */
	case 38: /* STATE 16 - next_date_dft.pml:93 - [tomorrowDay = 1] (0:0:1 - 1) */
		IfNotBlocked
		reached[1][16] = 1;
		(trpt+1)->bup.oval = ((P1 *)this)->_2_tomorrowDay;
		((P1 *)this)->_2_tomorrowDay = 1;
#ifdef VAR_RANGES
		logval("main:tomorrowDay", ((P1 *)this)->_2_tomorrowDay);
#endif
		;
		_m = 3; goto P999; /* 0 */
	case 39: /* STATE 17 - next_date_dft.pml:94 - [tomorrowMonth = (month+1)] (0:0:1 - 1) */
		IfNotBlocked
		reached[1][17] = 1;
		(trpt+1)->bup.oval = ((P1 *)this)->_2_tomorrowMonth;
		((P1 *)this)->_2_tomorrowMonth = (((P1 *)this)->_2_month+1);
#ifdef VAR_RANGES
		logval("main:tomorrowMonth", ((P1 *)this)->_2_tomorrowMonth);
#endif
		;
		_m = 3; goto P999; /* 0 */
	case 40: /* STATE 19 - next_date_dft.pml:96 - [printf('Invalid Input Date ')] (0:0:0 - 1) */
		IfNotBlocked
		reached[1][19] = 1;
		Printf("Invalid Input Date ");
		_m = 3; goto P999; /* 0 */
	case 41: /* STATE 25 - next_date_dft.pml:102 - [(((((month==4)||(month==6))||(month==9))||(month==11)))] (0:0:0 - 1) */
		IfNotBlocked
		reached[1][25] = 1;
		if (!(((((((P1 *)this)->_2_month==4)||(((P1 *)this)->_2_month==6))||(((P1 *)this)->_2_month==9))||(((P1 *)this)->_2_month==11))))
			continue;
		_m = 3; goto P999; /* 0 */
	case 42: /* STATE 26 - next_date_dft.pml:104 - [((day<30))] (0:0:0 - 1) */
		IfNotBlocked
		reached[1][26] = 1;
		if (!((((P1 *)this)->_2_day<30)))
			continue;
		_m = 3; goto P999; /* 0 */
	case 43: /* STATE 27 - next_date_dft.pml:105 - [tomorrowDay = (day+1)] (0:0:1 - 1) */
		IfNotBlocked
		reached[1][27] = 1;
		(trpt+1)->bup.oval = ((P1 *)this)->_2_tomorrowDay;
		((P1 *)this)->_2_tomorrowDay = (((P1 *)this)->_2_day+1);
#ifdef VAR_RANGES
		logval("main:tomorrowDay", ((P1 *)this)->_2_tomorrowDay);
#endif
		;
		_m = 3; goto P999; /* 0 */
	case 44: /* STATE 29 - next_date_dft.pml:108 - [((day==30))] (0:0:1 - 1) */
		IfNotBlocked
		reached[1][29] = 1;
		if (!((((P1 *)this)->_2_day==30)))
			continue;
		/* dead 1: _2_day */  (trpt+1)->bup.oval = ((P1 *)this)->_2_day;
#ifdef HAS_CODE
		if (!readtrail)
#endif
			((P1 *)this)->_2_day = 0;
		_m = 3; goto P999; /* 0 */
	case 45: /* STATE 30 - next_date_dft.pml:109 - [tomorrowDay = 1] (0:0:1 - 1) */
		IfNotBlocked
		reached[1][30] = 1;
		(trpt+1)->bup.oval = ((P1 *)this)->_2_tomorrowDay;
		((P1 *)this)->_2_tomorrowDay = 1;
#ifdef VAR_RANGES
		logval("main:tomorrowDay", ((P1 *)this)->_2_tomorrowDay);
#endif
		;
		_m = 3; goto P999; /* 0 */
	case 46: /* STATE 31 - next_date_dft.pml:110 - [tomorrowMonth = (month+1)] (0:0:1 - 1) */
		IfNotBlocked
		reached[1][31] = 1;
		(trpt+1)->bup.oval = ((P1 *)this)->_2_tomorrowMonth;
		((P1 *)this)->_2_tomorrowMonth = (((P1 *)this)->_2_month+1);
#ifdef VAR_RANGES
		logval("main:tomorrowMonth", ((P1 *)this)->_2_tomorrowMonth);
#endif
		;
		_m = 3; goto P999; /* 0 */
	case 47: /* STATE 33 - next_date_dft.pml:112 - [printf('Invalid Input Date ')] (0:0:0 - 1) */
		IfNotBlocked
		reached[1][33] = 1;
		Printf("Invalid Input Date ");
		_m = 3; goto P999; /* 0 */
	case 48: /* STATE 39 - next_date_dft.pml:118 - [((month==12))] (0:0:1 - 1) */
		IfNotBlocked
		reached[1][39] = 1;
		if (!((((P1 *)this)->_2_month==12)))
			continue;
		/* dead 1: _2_month */  (trpt+1)->bup.oval = ((P1 *)this)->_2_month;
#ifdef HAS_CODE
		if (!readtrail)
#endif
			((P1 *)this)->_2_month = 0;
		_m = 3; goto P999; /* 0 */
	case 49: /* STATE 40 - next_date_dft.pml:120 - [((day<31))] (0:0:0 - 1) */
		IfNotBlocked
		reached[1][40] = 1;
		if (!((((P1 *)this)->_2_day<31)))
			continue;
		_m = 3; goto P999; /* 0 */
	case 50: /* STATE 41 - next_date_dft.pml:121 - [tomorrowDay = (day+1)] (0:0:1 - 1) */
		IfNotBlocked
		reached[1][41] = 1;
		(trpt+1)->bup.oval = ((P1 *)this)->_2_tomorrowDay;
		((P1 *)this)->_2_tomorrowDay = (((P1 *)this)->_2_day+1);
#ifdef VAR_RANGES
		logval("main:tomorrowDay", ((P1 *)this)->_2_tomorrowDay);
#endif
		;
		_m = 3; goto P999; /* 0 */
	case 51: /* STATE 43 - next_date_dft.pml:124 - [((day==31))] (0:0:1 - 1) */
		IfNotBlocked
		reached[1][43] = 1;
		if (!((((P1 *)this)->_2_day==31)))
			continue;
		/* dead 1: _2_day */  (trpt+1)->bup.oval = ((P1 *)this)->_2_day;
#ifdef HAS_CODE
		if (!readtrail)
#endif
			((P1 *)this)->_2_day = 0;
		_m = 3; goto P999; /* 0 */
	case 52: /* STATE 44 - next_date_dft.pml:125 - [tomorrowDay = 1] (0:0:1 - 1) */
		IfNotBlocked
		reached[1][44] = 1;
		(trpt+1)->bup.oval = ((P1 *)this)->_2_tomorrowDay;
		((P1 *)this)->_2_tomorrowDay = 1;
#ifdef VAR_RANGES
		logval("main:tomorrowDay", ((P1 *)this)->_2_tomorrowDay);
#endif
		;
		_m = 3; goto P999; /* 0 */
	case 53: /* STATE 45 - next_date_dft.pml:126 - [tomorrowMonth = 1] (0:0:1 - 1) */
		IfNotBlocked
		reached[1][45] = 1;
		(trpt+1)->bup.oval = ((P1 *)this)->_2_tomorrowMonth;
		((P1 *)this)->_2_tomorrowMonth = 1;
#ifdef VAR_RANGES
		logval("main:tomorrowMonth", ((P1 *)this)->_2_tomorrowMonth);
#endif
		;
		_m = 3; goto P999; /* 0 */
	case 54: /* STATE 46 - next_date_dft.pml:127 - [tomorrowYear = (year+1)] (0:0:1 - 1) */
		IfNotBlocked
		reached[1][46] = 1;
		(trpt+1)->bup.oval = ((P1 *)this)->_2_tomorrowYear;
		((P1 *)this)->_2_tomorrowYear = (((P1 *)this)->_2_year+1);
#ifdef VAR_RANGES
		logval("main:tomorrowYear", ((P1 *)this)->_2_tomorrowYear);
#endif
		;
		_m = 3; goto P999; /* 0 */
	case 55: /* STATE 48 - next_date_dft.pml:129 - [printf('Invalid Input Date ')] (0:0:0 - 1) */
		IfNotBlocked
		reached[1][48] = 1;
		Printf("Invalid Input Date ");
		_m = 3; goto P999; /* 0 */
	case 56: /* STATE 54 - next_date_dft.pml:135 - [((month==2))] (0:0:1 - 1) */
		IfNotBlocked
		reached[1][54] = 1;
		if (!((((P1 *)this)->_2_month==2)))
			continue;
		/* dead 1: _2_month */  (trpt+1)->bup.oval = ((P1 *)this)->_2_month;
#ifdef HAS_CODE
		if (!readtrail)
#endif
			((P1 *)this)->_2_month = 0;
		_m = 3; goto P999; /* 0 */
	case 57: /* STATE 55 - next_date_dft.pml:137 - [((day<28))] (0:0:0 - 1) */
		IfNotBlocked
		reached[1][55] = 1;
		if (!((((P1 *)this)->_2_day<28)))
			continue;
		_m = 3; goto P999; /* 0 */
	case 58: /* STATE 56 - next_date_dft.pml:138 - [tomorrowDay = (day+1)] (0:0:1 - 1) */
		IfNotBlocked
		reached[1][56] = 1;
		(trpt+1)->bup.oval = ((P1 *)this)->_2_tomorrowDay;
		((P1 *)this)->_2_tomorrowDay = (((P1 *)this)->_2_day+1);
#ifdef VAR_RANGES
		logval("main:tomorrowDay", ((P1 *)this)->_2_tomorrowDay);
#endif
		;
		_m = 3; goto P999; /* 0 */
	case 59: /* STATE 58 - next_date_dft.pml:141 - [((day==28))] (0:0:1 - 1) */
		IfNotBlocked
		reached[1][58] = 1;
		if (!((((P1 *)this)->_2_day==28)))
			continue;
		/* dead 1: _2_day */  (trpt+1)->bup.oval = ((P1 *)this)->_2_day;
#ifdef HAS_CODE
		if (!readtrail)
#endif
			((P1 *)this)->_2_day = 0;
		_m = 3; goto P999; /* 0 */
	case 60: /* STATE 59 - next_date_dft.pml:143 - [(isLeap)] (0:0:1 - 1) */
		IfNotBlocked
		reached[1][59] = 1;
		if (!(((int)((P1 *)this)->_2_isLeap)))
			continue;
		/* dead 1: _2_isLeap */  (trpt+1)->bup.oval = ((P1 *)this)->_2_isLeap;
#ifdef HAS_CODE
		if (!readtrail)
#endif
			((P1 *)this)->_2_isLeap = 0;
		_m = 3; goto P999; /* 0 */
	case 61: /* STATE 60 - next_date_dft.pml:144 - [tomorrowDay = 29] (0:0:1 - 1) */
		IfNotBlocked
		reached[1][60] = 1;
		(trpt+1)->bup.oval = ((P1 *)this)->_2_tomorrowDay;
		((P1 *)this)->_2_tomorrowDay = 29;
#ifdef VAR_RANGES
		logval("main:tomorrowDay", ((P1 *)this)->_2_tomorrowDay);
#endif
		;
		_m = 3; goto P999; /* 0 */
	case 62: /* STATE 62 - next_date_dft.pml:146 - [tomorrowDay = 1] (0:0:1 - 1) */
		IfNotBlocked
		reached[1][62] = 1;
		(trpt+1)->bup.oval = ((P1 *)this)->_2_tomorrowDay;
		((P1 *)this)->_2_tomorrowDay = 1;
#ifdef VAR_RANGES
		logval("main:tomorrowDay", ((P1 *)this)->_2_tomorrowDay);
#endif
		;
		_m = 3; goto P999; /* 0 */
	case 63: /* STATE 63 - next_date_dft.pml:147 - [tomorrowMonth = 3] (0:0:1 - 1) */
		IfNotBlocked
		reached[1][63] = 1;
		(trpt+1)->bup.oval = ((P1 *)this)->_2_tomorrowMonth;
		((P1 *)this)->_2_tomorrowMonth = 3;
#ifdef VAR_RANGES
		logval("main:tomorrowMonth", ((P1 *)this)->_2_tomorrowMonth);
#endif
		;
		_m = 3; goto P999; /* 0 */
	case 64: /* STATE 67 - next_date_dft.pml:151 - [((day==29))] (0:0:0 - 1) */
		IfNotBlocked
		reached[1][67] = 1;
		if (!((((P1 *)this)->_2_day==29)))
			continue;
		_m = 3; goto P999; /* 0 */
	case 65: /* STATE 68 - next_date_dft.pml:153 - [(isLeap)] (0:0:1 - 1) */
		IfNotBlocked
		reached[1][68] = 1;
		if (!(((int)((P1 *)this)->_2_isLeap)))
			continue;
		/* dead 1: _2_isLeap */  (trpt+1)->bup.oval = ((P1 *)this)->_2_isLeap;
#ifdef HAS_CODE
		if (!readtrail)
#endif
			((P1 *)this)->_2_isLeap = 0;
		_m = 3; goto P999; /* 0 */
	case 66: /* STATE 69 - next_date_dft.pml:154 - [tomorrowDay = 1] (0:0:1 - 1) */
		IfNotBlocked
		reached[1][69] = 1;
		(trpt+1)->bup.oval = ((P1 *)this)->_2_tomorrowDay;
		((P1 *)this)->_2_tomorrowDay = 1;
#ifdef VAR_RANGES
		logval("main:tomorrowDay", ((P1 *)this)->_2_tomorrowDay);
#endif
		;
		_m = 3; goto P999; /* 0 */
	case 67: /* STATE 70 - next_date_dft.pml:155 - [tomorrowMonth = 3] (0:0:1 - 1) */
		IfNotBlocked
		reached[1][70] = 1;
		(trpt+1)->bup.oval = ((P1 *)this)->_2_tomorrowMonth;
		((P1 *)this)->_2_tomorrowMonth = 3;
#ifdef VAR_RANGES
		logval("main:tomorrowMonth", ((P1 *)this)->_2_tomorrowMonth);
#endif
		;
		_m = 3; goto P999; /* 0 */
	case 68: /* STATE 72 - next_date_dft.pml:157 - [printf('Cannot have Feb .%d ',day)] (0:0:0 - 1) */
		IfNotBlocked
		reached[1][72] = 1;
		Printf("Cannot have Feb .%d ", ((P1 *)this)->_2_day);
		_m = 3; goto P999; /* 0 */
	case 69: /* STATE 76 - next_date_dft.pml:161 - [printf('Invalid Input Date ')] (0:0:0 - 1) */
		IfNotBlocked
		reached[1][76] = 1;
		Printf("Invalid Input Date ");
		_m = 3; goto P999; /* 0 */
	case 70: /* STATE 93 - next_date_dft.pml:171 - [printf('date is %d %d %d ',tomorrowMonth,tomorrowDay,tomorrowYear)] (0:0:0 - 31) */
		IfNotBlocked
		reached[1][93] = 1;
		Printf("date is %d %d %d ", ((P1 *)this)->_2_tomorrowMonth, ((P1 *)this)->_2_tomorrowDay, ((P1 *)this)->_2_tomorrowYear);
		_m = 3; goto P999; /* 0 */
	case 71: /* STATE 94 - next_date_dft.pml:173 - [in_main!0] (0:0:0 - 1) */
		IfNotBlocked
		reached[1][94] = 1;
		if (q_len(((P1 *)this)->in_main))
			continue;
#ifdef HAS_CODE
		if (readtrail && gui) {
			char simtmp[32];
			sprintf(simvals, "%d!", ((P1 *)this)->in_main);
		sprintf(simtmp, "%d", 0); strcat(simvals, simtmp);		}
#endif
		
		qsend(((P1 *)this)->in_main, 0, 0, 1);
		{ boq = ((P1 *)this)->in_main; };
		_m = 2; goto P999; /* 0 */
	case 72: /* STATE 96 - next_date_dft.pml:175 - [printf('End of main')] (0:0:0 - 2) */
		IfNotBlocked
		reached[1][96] = 1;
		Printf("End of main");
		_m = 3; goto P999; /* 0 */
	case 73: /* STATE 97 - next_date_dft.pml:176 - [-end-] (0:0:0 - 1) */
		IfNotBlocked
		reached[1][97] = 1;
		if (!delproc(1, II)) continue;
		_m = 3; goto P999; /* 0 */

		 /* PROC input */
	case 74: /* STATE 1 - next_date_dft.pml:5 - [((value<max))] (4:0:1 - 1) */
		IfNotBlocked
		reached[0][1] = 1;
		if (!((((P0 *)this)->_1_1_value<((P0 *)this)->max)))
			continue;
		/* merge: value = (value+1)(0, 2, 4) */
		reached[0][2] = 1;
		(trpt+1)->bup.oval = ((P0 *)this)->_1_1_value;
		((P0 *)this)->_1_1_value = (((P0 *)this)->_1_1_value+1);
#ifdef VAR_RANGES
		logval("input:value", ((P0 *)this)->_1_1_value);
#endif
		;
		/* merge: .(goto)(0, 5, 4) */
		reached[0][5] = 1;
		;
		_m = 3; goto P999; /* 2 */
	case 75: /* STATE 7 - next_date_dft.pml:8 - [in_input!value] (0:0:0 - 1) */
		IfNotBlocked
		reached[0][7] = 1;
		if (q_len(((P0 *)this)->in_input))
			continue;
#ifdef HAS_CODE
		if (readtrail && gui) {
			char simtmp[32];
			sprintf(simvals, "%d!", ((P0 *)this)->in_input);
		sprintf(simtmp, "%d", ((P0 *)this)->_1_1_value); strcat(simvals, simtmp);		}
#endif
		
		qsend(((P0 *)this)->in_input, 0, ((P0 *)this)->_1_1_value, 1);
		{ boq = ((P0 *)this)->in_input; };
		_m = 2; goto P999; /* 0 */
	case 76: /* STATE 9 - next_date_dft.pml:10 - [-end-] (0:0:0 - 1) */
		IfNotBlocked
		reached[0][9] = 1;
		if (!delproc(1, II)) continue;
		_m = 3; goto P999; /* 0 */
	case  _T5:	/* np_ */
		if (!((!(trpt->o_pm&4) && !(trpt->tau&128))))
			continue;
		/* else fall through */
	case  _T2:	/* true */
		_m = 3; goto P999;
#undef rand
	}

