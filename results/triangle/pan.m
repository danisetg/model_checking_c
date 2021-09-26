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
	case 3: /* STATE 1 - triangle_dft.pml.nvr:5 - [((main._p==d_c_v7))] (0:0:0 - 1) */
		
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
		if (!((((int)((P1 *)Pptr(f_pid(1)))->_p)==2)))
			continue;
		_m = 3; goto P999; /* 0 */
	case 4: /* STATE 9 - triangle_dft.pml.nvr:11 - [(((main._p==end)&&(main._p==u_c_v17)))] (0:0:0 - 1) */
		
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
		if (!(((((int)((P1 *)Pptr(f_pid(1)))->_p)==35)&&(((int)((P1 *)Pptr(f_pid(1)))->_p)==25))))
			continue;
		_m = 3; goto P999; /* 0 */
	case 5: /* STATE 11 - triangle_dft.pml.nvr:12 - [((main._p==u_c_v17))] (0:0:0 - 1) */
		
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
		if (!((((int)((P1 *)Pptr(f_pid(1)))->_p)==25)))
			continue;
		_m = 3; goto P999; /* 0 */
	case 6: /* STATE 13 - triangle_dft.pml.nvr:13 - [(!((main._p==d_c_v7)))] (0:0:0 - 1) */
		
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
		if (!( !((((int)((P1 *)Pptr(f_pid(1)))->_p)==2))))
			continue;
		_m = 3; goto P999; /* 0 */
	case 7: /* STATE 17 - triangle_dft.pml.nvr:17 - [((main._p==d_c_v7))] (0:0:0 - 1) */
		
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
		if (!((((int)((P1 *)Pptr(f_pid(1)))->_p)==2)))
			continue;
		_m = 3; goto P999; /* 0 */
	case 8: /* STATE 23 - triangle_dft.pml.nvr:22 - [((main._p==end))] (0:0:0 - 1) */
		
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
		if (!((((int)((P1 *)Pptr(f_pid(1)))->_p)==35)))
			continue;
		_m = 3; goto P999; /* 0 */
	case 9: /* STATE 29 - triangle_dft.pml.nvr:27 - [(((main._p==end)&&(main._p==d_c_v7)))] (0:0:0 - 1) */
		
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
		if (!(((((int)((P1 *)Pptr(f_pid(1)))->_p)==35)&&(((int)((P1 *)Pptr(f_pid(1)))->_p)==2))))
			continue;
		_m = 3; goto P999; /* 0 */
	case 10: /* STATE 31 - triangle_dft.pml.nvr:28 - [((main._p==end))] (0:0:0 - 1) */
		
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
		if (!((((int)((P1 *)Pptr(f_pid(1)))->_p)==35)))
			continue;
		_m = 3; goto P999; /* 0 */
	case 11: /* STATE 33 - triangle_dft.pml.nvr:29 - [((main._p==d_c_v7))] (0:0:0 - 1) */
		
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
		if (!((((int)((P1 *)Pptr(f_pid(1)))->_p)==2)))
			continue;
		_m = 3; goto P999; /* 0 */
	case 12: /* STATE 39 - triangle_dft.pml.nvr:34 - [(((main._p==end)&&(main._p==u_c_v17)))] (0:0:0 - 1) */
		
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
		if (!(((((int)((P1 *)Pptr(f_pid(1)))->_p)==35)&&(((int)((P1 *)Pptr(f_pid(1)))->_p)==25))))
			continue;
		_m = 3; goto P999; /* 0 */
	case 13: /* STATE 41 - triangle_dft.pml.nvr:35 - [((main._p==u_c_v17))] (0:0:0 - 1) */
		
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
		if (!((((int)((P1 *)Pptr(f_pid(1)))->_p)==25)))
			continue;
		_m = 3; goto P999; /* 0 */
	case 14: /* STATE 43 - triangle_dft.pml.nvr:36 - [(!((main._p==d_c_v7)))] (0:0:0 - 1) */
		
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
		if (!( !((((int)((P1 *)Pptr(f_pid(1)))->_p)==2))))
			continue;
		_m = 3; goto P999; /* 0 */
	case 15: /* STATE 47 - triangle_dft.pml.nvr:40 - [((((main._p==end)&&(main._p==d_c_v7))&&(main._p==u_c_v17)))] (0:0:0 - 1) */
		
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
		if (!((((((int)((P1 *)Pptr(f_pid(1)))->_p)==35)&&(((int)((P1 *)Pptr(f_pid(1)))->_p)==2))&&(((int)((P1 *)Pptr(f_pid(1)))->_p)==25))))
			continue;
		_m = 3; goto P999; /* 0 */
	case 16: /* STATE 49 - triangle_dft.pml.nvr:41 - [(((main._p==end)&&(main._p==u_c_v17)))] (0:0:0 - 1) */
		
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
		if (!(((((int)((P1 *)Pptr(f_pid(1)))->_p)==35)&&(((int)((P1 *)Pptr(f_pid(1)))->_p)==25))))
			continue;
		_m = 3; goto P999; /* 0 */
	case 17: /* STATE 51 - triangle_dft.pml.nvr:42 - [(((main._p==d_c_v7)&&(main._p==u_c_v17)))] (0:0:0 - 1) */
		
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
		if (!(((((int)((P1 *)Pptr(f_pid(1)))->_p)==2)&&(((int)((P1 *)Pptr(f_pid(1)))->_p)==25))))
			continue;
		_m = 3; goto P999; /* 0 */
	case 18: /* STATE 53 - triangle_dft.pml.nvr:43 - [((main._p==u_c_v17))] (0:0:0 - 1) */
		
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
		if (!((((int)((P1 *)Pptr(f_pid(1)))->_p)==25)))
			continue;
		_m = 3; goto P999; /* 0 */
	case 19: /* STATE 55 - triangle_dft.pml.nvr:44 - [(!((main._p==d_c_v7)))] (0:0:0 - 1) */
		
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
		if (!( !((((int)((P1 *)Pptr(f_pid(1)))->_p)==2))))
			continue;
		_m = 3; goto P999; /* 0 */
	case 20: /* STATE 60 - triangle_dft.pml.nvr:48 - [-end-] (0:0:0 - 1) */
		
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
	case 21: /* STATE 1 - triangle_dft.pml:84 - [(run main(ret_main))] (0:0:0 - 1) */
		IfNotBlocked
		reached[2][1] = 1;
		if (!(addproc(1, ((P2 *)this)->_3_ret_main, 0, 0)))
			continue;
		_m = 3; goto P999; /* 0 */
	case 22: /* STATE 2 - triangle_dft.pml:85 - [ret_main?0] (0:0:0 - 1) */
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
	case 23: /* STATE 3 - triangle_dft.pml:86 - [-end-] (0:0:0 - 1) */
		IfNotBlocked
		reached[2][3] = 1;
		if (!delproc(1, II)) continue;
		_m = 3; goto P999; /* 0 */

		 /* PROC main */
	case 24: /* STATE 1 - triangle_dft.pml:37 - [printf('Enter 3integers which are sides of a triangle ')] (0:0:0 - 1) */
		IfNotBlocked
		reached[1][1] = 1;
		Printf("Enter 3integers which are sides of a triangle ");
		_m = 3; goto P999; /* 0 */
	case 25: /* STATE 2 - triangle_dft.pml:39 - [(run input(ret_input,1,10))] (0:0:0 - 1) */
		IfNotBlocked
		reached[1][2] = 1;
		if (!(addproc(0, ((P1 *)this)->_2_ret_input, 1, 10)))
			continue;
		_m = 3; goto P999; /* 0 */
	case 26: /* STATE 3 - triangle_dft.pml:40 - [ret_input?a] (0:0:1 - 1) */
		reached[1][3] = 1;
		if (boq != ((P1 *)this)->_2_ret_input) continue;
		if (q_len(((P1 *)this)->_2_ret_input) == 0) continue;

		XX=1;
		(trpt+1)->bup.oval = ((P1 *)this)->_2_a;
		;
		((P1 *)this)->_2_a = qrecv(((P1 *)this)->_2_ret_input, XX-1, 0, 1);
#ifdef VAR_RANGES
		logval("main:a", ((P1 *)this)->_2_a);
#endif
		;
		
#ifdef HAS_CODE
		if (readtrail && gui) {
			char simtmp[32];
			sprintf(simvals, "%d?", ((P1 *)this)->_2_ret_input);
		sprintf(simtmp, "%d", ((P1 *)this)->_2_a); strcat(simvals, simtmp);		}
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
	case 27: /* STATE 4 - triangle_dft.pml:41 - [(run input(ret_input,1,10))] (0:0:0 - 1) */
		IfNotBlocked
		reached[1][4] = 1;
		if (!(addproc(0, ((P1 *)this)->_2_ret_input, 1, 10)))
			continue;
		_m = 3; goto P999; /* 0 */
	case 28: /* STATE 5 - triangle_dft.pml:42 - [ret_input?b] (0:0:1 - 1) */
		reached[1][5] = 1;
		if (boq != ((P1 *)this)->_2_ret_input) continue;
		if (q_len(((P1 *)this)->_2_ret_input) == 0) continue;

		XX=1;
		(trpt+1)->bup.oval = ((P1 *)this)->_2_b;
		;
		((P1 *)this)->_2_b = qrecv(((P1 *)this)->_2_ret_input, XX-1, 0, 1);
#ifdef VAR_RANGES
		logval("main:b", ((P1 *)this)->_2_b);
#endif
		;
		
#ifdef HAS_CODE
		if (readtrail && gui) {
			char simtmp[32];
			sprintf(simvals, "%d?", ((P1 *)this)->_2_ret_input);
		sprintf(simtmp, "%d", ((P1 *)this)->_2_b); strcat(simvals, simtmp);		}
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
	case 29: /* STATE 6 - triangle_dft.pml:43 - [(run input(ret_input,1,10))] (0:0:0 - 1) */
		IfNotBlocked
		reached[1][6] = 1;
		if (!(addproc(0, ((P1 *)this)->_2_ret_input, 1, 10)))
			continue;
		_m = 3; goto P999; /* 0 */
	case 30: /* STATE 7 - triangle_dft.pml:44 - [ret_input?c] (0:0:1 - 1) */
		reached[1][7] = 1;
		if (boq != ((P1 *)this)->_2_ret_input) continue;
		if (q_len(((P1 *)this)->_2_ret_input) == 0) continue;

		XX=1;
		(trpt+1)->bup.oval = ((P1 *)this)->_2_c;
		;
		((P1 *)this)->_2_c = qrecv(((P1 *)this)->_2_ret_input, XX-1, 0, 1);
#ifdef VAR_RANGES
		logval("main:c", ((P1 *)this)->_2_c);
#endif
		;
		
#ifdef HAS_CODE
		if (readtrail && gui) {
			char simtmp[32];
			sprintf(simvals, "%d?", ((P1 *)this)->_2_ret_input);
		sprintf(simtmp, "%d", ((P1 *)this)->_2_c); strcat(simvals, simtmp);		}
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
	case 31: /* STATE 8 - triangle_dft.pml:46 - [printf('Side A is %d ',a)] (0:0:0 - 1) */
		IfNotBlocked
		reached[1][8] = 1;
		Printf("Side A is %d ", ((P1 *)this)->_2_a);
		_m = 3; goto P999; /* 0 */
	case 32: /* STATE 9 - triangle_dft.pml:48 - [printf('Side B is %d ',b)] (0:0:0 - 1) */
		IfNotBlocked
		reached[1][9] = 1;
		Printf("Side B is %d ", ((P1 *)this)->_2_b);
		_m = 3; goto P999; /* 0 */
	case 33: /* STATE 10 - triangle_dft.pml:50 - [printf('Side C is %d ',c)] (0:0:0 - 1) */
		IfNotBlocked
		reached[1][10] = 1;
		Printf("Side C is %d ", ((P1 *)this)->_2_c);
		_m = 3; goto P999; /* 0 */
	case 34: /* STATE 11 - triangle_dft.pml:53 - [((((a<(b+c))&&(b<(a+c)))&&(c<(a+b))))] (0:0:0 - 1) */
		IfNotBlocked
		reached[1][11] = 1;
		if (!((((((P1 *)this)->_2_a<(((P1 *)this)->_2_b+((P1 *)this)->_2_c))&&(((P1 *)this)->_2_b<(((P1 *)this)->_2_a+((P1 *)this)->_2_c)))&&(((P1 *)this)->_2_c<(((P1 *)this)->_2_a+((P1 *)this)->_2_b)))))
			continue;
		_m = 3; goto P999; /* 0 */
	case 35: /* STATE 12 - triangle_dft.pml:54 - [isATriangle = 1] (0:0:1 - 1) */
		IfNotBlocked
		reached[1][12] = 1;
		(trpt+1)->bup.oval = ((int)((P1 *)this)->_2_isATriangle);
		((P1 *)this)->_2_isATriangle = 1;
#ifdef VAR_RANGES
		logval("main:isATriangle", ((int)((P1 *)this)->_2_isATriangle));
#endif
		;
		_m = 3; goto P999; /* 0 */
	case 36: /* STATE 14 - triangle_dft.pml:56 - [isATriangle = 0] (0:0:1 - 1) */
		IfNotBlocked
		reached[1][14] = 1;
		(trpt+1)->bup.oval = ((int)((P1 *)this)->_2_isATriangle);
		((P1 *)this)->_2_isATriangle = 0;
#ifdef VAR_RANGES
		logval("main:isATriangle", ((int)((P1 *)this)->_2_isATriangle));
#endif
		;
		_m = 3; goto P999; /* 0 */
	case 37: /* STATE 17 - triangle_dft.pml:59 - [(isATriangle)] (0:0:1 - 1) */
		IfNotBlocked
		reached[1][17] = 1;
		if (!(((int)((P1 *)this)->_2_isATriangle)))
			continue;
		/* dead 1: _2_isATriangle */  (trpt+1)->bup.oval = ((P1 *)this)->_2_isATriangle;
#ifdef HAS_CODE
		if (!readtrail)
#endif
			((P1 *)this)->_2_isATriangle = 0;
		_m = 3; goto P999; /* 0 */
	case 38: /* STATE 18 - triangle_dft.pml:61 - [(((a==b)&&(b==c)))] (33:0:3 - 1) */
		IfNotBlocked
		reached[1][18] = 1;
		if (!(((((P1 *)this)->_2_a==((P1 *)this)->_2_b)&&(((P1 *)this)->_2_b==((P1 *)this)->_2_c))))
			continue;
		/* dead 1: _2_a */  (trpt+1)->bup.ovals = grab_ints(3);
		(trpt+1)->bup.ovals[0] = ((P1 *)this)->_2_a;
#ifdef HAS_CODE
		if (!readtrail)
#endif
			((P1 *)this)->_2_a = 0;
		/* dead 1: _2_b */  (trpt+1)->bup.ovals[1] = ((P1 *)this)->_2_b;
#ifdef HAS_CODE
		if (!readtrail)
#endif
			((P1 *)this)->_2_b = 0;
		/* dead 1: _2_c */  (trpt+1)->bup.ovals[2] = ((P1 *)this)->_2_c;
#ifdef HAS_CODE
		if (!readtrail)
#endif
			((P1 *)this)->_2_c = 0;
		/* merge: printf('Equilateral ')(0, 19, 33) */
		reached[1][19] = 1;
		Printf("Equilateral ");
		/* merge: .(goto)(0, 28, 33) */
		reached[1][28] = 1;
		;
		/* merge: .(goto)(0, 32, 33) */
		reached[1][32] = 1;
		;
		_m = 3; goto P999; /* 3 */
	case 39: /* STATE 21 - triangle_dft.pml:66 - [((((a!=b)&&(b!=c))&&(a!=c)))] (33:0:3 - 1) */
		IfNotBlocked
		reached[1][21] = 1;
		if (!((((((P1 *)this)->_2_a!=((P1 *)this)->_2_b)&&(((P1 *)this)->_2_b!=((P1 *)this)->_2_c))&&(((P1 *)this)->_2_a!=((P1 *)this)->_2_c))))
			continue;
		/* dead 1: _2_a */  (trpt+1)->bup.ovals = grab_ints(3);
		(trpt+1)->bup.ovals[0] = ((P1 *)this)->_2_a;
#ifdef HAS_CODE
		if (!readtrail)
#endif
			((P1 *)this)->_2_a = 0;
		/* dead 1: _2_b */  (trpt+1)->bup.ovals[1] = ((P1 *)this)->_2_b;
#ifdef HAS_CODE
		if (!readtrail)
#endif
			((P1 *)this)->_2_b = 0;
		/* dead 1: _2_c */  (trpt+1)->bup.ovals[2] = ((P1 *)this)->_2_c;
#ifdef HAS_CODE
		if (!readtrail)
#endif
			((P1 *)this)->_2_c = 0;
		/* merge: printf('Scalene ')(0, 22, 33) */
		reached[1][22] = 1;
		Printf("Scalene ");
		/* merge: .(goto)(0, 26, 33) */
		reached[1][26] = 1;
		;
		/* merge: .(goto)(0, 28, 33) */
		reached[1][28] = 1;
		;
		/* merge: .(goto)(0, 32, 33) */
		reached[1][32] = 1;
		;
		_m = 3; goto P999; /* 4 */
	case 40: /* STATE 24 - triangle_dft.pml:70 - [printf('Isosceles ')] (0:0:0 - 1) */
		IfNotBlocked
		reached[1][24] = 1;
		Printf("Isosceles ");
		_m = 3; goto P999; /* 0 */
	case 41: /* STATE 30 - triangle_dft.pml:75 - [printf('Not a Triangle ')] (0:0:0 - 1) */
		IfNotBlocked
		reached[1][30] = 1;
		Printf("Not a Triangle ");
		_m = 3; goto P999; /* 0 */
	case 42: /* STATE 33 - triangle_dft.pml:78 - [in_main!0] (0:0:0 - 7) */
		IfNotBlocked
		reached[1][33] = 1;
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
	case 43: /* STATE 35 - triangle_dft.pml:80 - [printf('End of main')] (0:0:0 - 2) */
		IfNotBlocked
		reached[1][35] = 1;
		Printf("End of main");
		_m = 3; goto P999; /* 0 */
	case 44: /* STATE 36 - triangle_dft.pml:81 - [-end-] (0:0:0 - 1) */
		IfNotBlocked
		reached[1][36] = 1;
		if (!delproc(1, II)) continue;
		_m = 3; goto P999; /* 0 */

		 /* PROC input */
	case 45: /* STATE 1 - triangle_dft.pml:5 - [((value<max))] (4:0:1 - 1) */
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
	case 46: /* STATE 7 - triangle_dft.pml:8 - [in_input!value] (0:0:0 - 1) */
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
	case 47: /* STATE 9 - triangle_dft.pml:10 - [-end-] (0:0:0 - 1) */
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

