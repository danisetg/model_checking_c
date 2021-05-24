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
	case 3: /* STATE 1 - triangle_mcdc.pml.nvr:5 - [((((main_a!=main_b)&&(main_b!=main_c))&&(main_a!=main_c)))] (0:0:0 - 1) */
		
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
		if (!((((now.main_a!=now.main_b)&&(now.main_b!=now.main_c))&&(now.main_a!=now.main_c))))
			continue;
		_m = 3; goto P999; /* 0 */
	case 4: /* STATE 7 - triangle_mcdc.pml.nvr:10 - [(((!((((main_a!=main_b)&&(main_b!=main_c))&&(main_a!=main_c)))&&!(((main_a!=main_c)==main_condition_73_copy)))&&reset))] (0:0:0 - 1) */
		
#if defined(VERI) && !defined(NP)
#if NCLAIMS>1
		{	static int reported7 = 0; int nn = (int) ((Pclaim *)this)->_n;
			if (verbose && !reported7)
			{	printf("depth %ld: Claim %s (%d), state %d (line %d)\n",
					depth, procname[spin_c_typ[nn]], nn, (int) ((Pclaim *)this)->_p, src_claim[ (int) ((Pclaim *)this)->_p ]);
				reported7 = 1;
				fflush(stdout);
		}	}
#else
{	static int reported7 = 0;
			if (verbose && !reported7)
			{	printf("depth %d: Claim, state %d (line %d)\n",
					(int) depth, (int) ((Pclaim *)this)->_p, src_claim[ (int) ((Pclaim *)this)->_p ]);
				reported7 = 1;
				fflush(stdout);
		}	}
#endif
#endif
		reached[3][7] = 1;
		if (!((( !((((now.main_a!=now.main_b)&&(now.main_b!=now.main_c))&&(now.main_a!=now.main_c)))&& !(((now.main_a!=now.main_c)==((int)now.main_condition_73_copy))))&&((int)now.reset))))
			continue;
		_m = 3; goto P999; /* 0 */
	case 5: /* STATE 9 - triangle_mcdc.pml.nvr:11 - [(reset)] (0:0:0 - 1) */
		
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
		if (!(((int)now.reset)))
			continue;
		_m = 3; goto P999; /* 0 */
	case 6: /* STATE 13 - triangle_mcdc.pml.nvr:15 - [((!((((main_a!=main_b)&&(main_b!=main_c))&&(main_a!=main_c)))&&!(((main_a!=main_c)==main_condition_73_copy))))] (0:0:0 - 1) */
		
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
		if (!(( !((((now.main_a!=now.main_b)&&(now.main_b!=now.main_c))&&(now.main_a!=now.main_c)))&& !(((now.main_a!=now.main_c)==((int)now.main_condition_73_copy))))))
			continue;
		_m = 3; goto P999; /* 0 */
	case 7: /* STATE 20 - triangle_mcdc.pml.nvr:20 - [-end-] (0:0:0 - 1) */
		
#if defined(VERI) && !defined(NP)
#if NCLAIMS>1
		{	static int reported20 = 0; int nn = (int) ((Pclaim *)this)->_n;
			if (verbose && !reported20)
			{	printf("depth %ld: Claim %s (%d), state %d (line %d)\n",
					depth, procname[spin_c_typ[nn]], nn, (int) ((Pclaim *)this)->_p, src_claim[ (int) ((Pclaim *)this)->_p ]);
				reported20 = 1;
				fflush(stdout);
		}	}
#else
{	static int reported20 = 0;
			if (verbose && !reported20)
			{	printf("depth %d: Claim, state %d (line %d)\n",
					(int) depth, (int) ((Pclaim *)this)->_p, src_claim[ (int) ((Pclaim *)this)->_p ]);
				reported20 = 1;
				fflush(stdout);
		}	}
#endif
#endif
		reached[3][20] = 1;
		if (!delproc(1, II)) continue;
		_m = 3; goto P999; /* 0 */

		 /* PROC :init: */
	case 8: /* STATE 1 - triangle_mcdc.pml:194 - [(run main(ret_main))] (0:0:0 - 1) */
		IfNotBlocked
		reached[2][1] = 1;
		if (!(addproc(1, ((P2 *)this)->_3_ret_main, 0, 0)))
			continue;
		_m = 3; goto P999; /* 0 */
	case 9: /* STATE 2 - triangle_mcdc.pml:195 - [ret_main?0] (0:0:0 - 1) */
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
	case 10: /* STATE 3 - triangle_mcdc.pml:196 - [-end-] (0:0:0 - 1) */
		IfNotBlocked
		reached[2][3] = 1;
		if (!delproc(1, II)) continue;
		_m = 3; goto P999; /* 0 */

		 /* PROC main */
	case 11: /* STATE 1 - triangle_mcdc.pml:66 - [printf('Main start ')] (0:0:0 - 1) */
		IfNotBlocked
		reached[1][1] = 1;
		Printf("Main start ");
		_m = 3; goto P999; /* 0 */
	case 12: /* STATE 2 - triangle_mcdc.pml:69 - [(1)] (4:0:0 - 1) */
		IfNotBlocked
		reached[1][2] = 1;
		if (!(1))
			continue;
		/* merge: printf('Enter 3integers which are sides of a triangle ')(0, 3, 4) */
		reached[1][3] = 1;
		Printf("Enter 3integers which are sides of a triangle ");
		_m = 3; goto P999; /* 1 */
	case 13: /* STATE 4 - triangle_mcdc.pml:72 - [(run input(ret_input,1,10))] (0:0:0 - 1) */
		IfNotBlocked
		reached[1][4] = 1;
		if (!(addproc(0, ((P1 *)this)->_2_ret_input, 1, 10)))
			continue;
		_m = 3; goto P999; /* 0 */
	case 14: /* STATE 5 - triangle_mcdc.pml:73 - [ret_input?main_a] (0:0:1 - 1) */
		reached[1][5] = 1;
		if (boq != ((P1 *)this)->_2_ret_input) continue;
		if (q_len(((P1 *)this)->_2_ret_input) == 0) continue;

		XX=1;
		(trpt+1)->bup.oval = now.main_a;
		;
		now.main_a = qrecv(((P1 *)this)->_2_ret_input, XX-1, 0, 1);
#ifdef VAR_RANGES
		logval("main_a", now.main_a);
#endif
		;
		
#ifdef HAS_CODE
		if (readtrail && gui) {
			char simtmp[32];
			sprintf(simvals, "%d?", ((P1 *)this)->_2_ret_input);
		sprintf(simtmp, "%d", now.main_a); strcat(simvals, simtmp);		}
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
	case 15: /* STATE 6 - triangle_mcdc.pml:74 - [(run input(ret_input,1,10))] (0:0:0 - 1) */
		IfNotBlocked
		reached[1][6] = 1;
		if (!(addproc(0, ((P1 *)this)->_2_ret_input, 1, 10)))
			continue;
		_m = 3; goto P999; /* 0 */
	case 16: /* STATE 7 - triangle_mcdc.pml:75 - [ret_input?main_b] (0:0:1 - 1) */
		reached[1][7] = 1;
		if (boq != ((P1 *)this)->_2_ret_input) continue;
		if (q_len(((P1 *)this)->_2_ret_input) == 0) continue;

		XX=1;
		(trpt+1)->bup.oval = now.main_b;
		;
		now.main_b = qrecv(((P1 *)this)->_2_ret_input, XX-1, 0, 1);
#ifdef VAR_RANGES
		logval("main_b", now.main_b);
#endif
		;
		
#ifdef HAS_CODE
		if (readtrail && gui) {
			char simtmp[32];
			sprintf(simvals, "%d?", ((P1 *)this)->_2_ret_input);
		sprintf(simtmp, "%d", now.main_b); strcat(simvals, simtmp);		}
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
	case 17: /* STATE 8 - triangle_mcdc.pml:76 - [(run input(ret_input,1,10))] (0:0:0 - 1) */
		IfNotBlocked
		reached[1][8] = 1;
		if (!(addproc(0, ((P1 *)this)->_2_ret_input, 1, 10)))
			continue;
		_m = 3; goto P999; /* 0 */
	case 18: /* STATE 9 - triangle_mcdc.pml:77 - [ret_input?main_c] (0:0:1 - 1) */
		reached[1][9] = 1;
		if (boq != ((P1 *)this)->_2_ret_input) continue;
		if (q_len(((P1 *)this)->_2_ret_input) == 0) continue;

		XX=1;
		(trpt+1)->bup.oval = now.main_c;
		;
		now.main_c = qrecv(((P1 *)this)->_2_ret_input, XX-1, 0, 1);
#ifdef VAR_RANGES
		logval("main_c", now.main_c);
#endif
		;
		
#ifdef HAS_CODE
		if (readtrail && gui) {
			char simtmp[32];
			sprintf(simvals, "%d?", ((P1 *)this)->_2_ret_input);
		sprintf(simtmp, "%d", now.main_c); strcat(simvals, simtmp);		}
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
	case 19: /* STATE 10 - triangle_mcdc.pml:79 - [main_c1 = ((1<=main_a)&&(main_a<=200))] (0:0:1 - 1) */
		IfNotBlocked
		reached[1][10] = 1;
		(trpt+1)->bup.oval = ((int)now.main_c1);
		now.main_c1 = ((1<=now.main_a)&&(now.main_a<=200));
#ifdef VAR_RANGES
		logval("main_c1", ((int)now.main_c1));
#endif
		;
		_m = 3; goto P999; /* 0 */
	case 20: /* STATE 11 - triangle_mcdc.pml:80 - [main_c2 = ((1<=main_b)&&(main_b<=200))] (0:0:1 - 1) */
		IfNotBlocked
		reached[1][11] = 1;
		(trpt+1)->bup.oval = ((int)now.main_c2);
		now.main_c2 = ((1<=now.main_b)&&(now.main_b<=200));
#ifdef VAR_RANGES
		logval("main_c2", ((int)now.main_c2));
#endif
		;
		_m = 3; goto P999; /* 0 */
	case 21: /* STATE 12 - triangle_mcdc.pml:81 - [main_c3 = ((1<=main_c)&&(main_c<=200))] (0:0:1 - 1) */
		IfNotBlocked
		reached[1][12] = 1;
		(trpt+1)->bup.oval = ((int)now.main_c3);
		now.main_c3 = ((1<=now.main_c)&&(now.main_c<=200));
#ifdef VAR_RANGES
		logval("main_c3", ((int)now.main_c3));
#endif
		;
		_m = 3; goto P999; /* 0 */
	case 22: /* STATE 13 - triangle_mcdc.pml:83 - [(!(main_c1))] (0:0:0 - 1) */
		IfNotBlocked
		reached[1][13] = 1;
		if (!( !(((int)now.main_c1))))
			continue;
		_m = 3; goto P999; /* 0 */
	case 23: /* STATE 14 - triangle_mcdc.pml:85 - [printf('Value of a is not in the range of permitted values ')] (0:21:1 - 1) */
		IfNotBlocked
		reached[1][14] = 1;
		Printf("Value of a is not in the range of permitted values ");
		/* merge: main_condition_11_copy = !(main_c1)(21, 15, 21) */
		reached[1][15] = 1;
		(trpt+1)->bup.oval = ((int)main_condition_11_copy);
		main_condition_11_copy =  !(((int)now.main_c1));
#ifdef VAR_RANGES
		logval("main_condition_11_copy", ((int)main_condition_11_copy));
#endif
		;
		_m = 3; goto P999; /* 1 */
	case 24: /* STATE 16 - triangle_mcdc.pml:89 - [((reset==0))] (1:0:1 - 1) */
		IfNotBlocked
		reached[1][16] = 1;
		if (!((((int)now.reset)==0)))
			continue;
		/* merge: reset = 1(1, 17, 1) */
		reached[1][17] = 1;
		(trpt+1)->bup.oval = ((int)now.reset);
		now.reset = 1;
#ifdef VAR_RANGES
		logval("reset", ((int)now.reset));
#endif
		;
		/* merge: goto start(1, 18, 1) */
		reached[1][18] = 1;
		;
		_m = 3; goto P999; /* 2 */
	case 25: /* STATE 20 - triangle_mcdc.pml:92 - [(1)] (41:0:0 - 1) */
		IfNotBlocked
		reached[1][20] = 1;
		if (!(1))
			continue;
		/* merge: .(goto)(0, 22, 41) */
		reached[1][22] = 1;
		;
		/* merge: .(goto)(0, 27, 41) */
		reached[1][27] = 1;
		;
		_m = 3; goto P999; /* 2 */
	case 26: /* STATE 28 - triangle_mcdc.pml:99 - [(!(main_c2))] (0:0:0 - 1) */
		IfNotBlocked
		reached[1][28] = 1;
		if (!( !(((int)now.main_c2))))
			continue;
		_m = 3; goto P999; /* 0 */
	case 27: /* STATE 29 - triangle_mcdc.pml:101 - [printf('Value of b is not in the range of permitted values ')] (0:36:1 - 1) */
		IfNotBlocked
		reached[1][29] = 1;
		Printf("Value of b is not in the range of permitted values ");
		/* merge: main_condition_21_copy = !(main_c2)(36, 30, 36) */
		reached[1][30] = 1;
		(trpt+1)->bup.oval = ((int)main_condition_21_copy);
		main_condition_21_copy =  !(((int)now.main_c2));
#ifdef VAR_RANGES
		logval("main_condition_21_copy", ((int)main_condition_21_copy));
#endif
		;
		_m = 3; goto P999; /* 1 */
	case 28: /* STATE 31 - triangle_mcdc.pml:105 - [((reset==0))] (1:0:1 - 1) */
		IfNotBlocked
		reached[1][31] = 1;
		if (!((((int)now.reset)==0)))
			continue;
		/* merge: reset = 1(1, 32, 1) */
		reached[1][32] = 1;
		(trpt+1)->bup.oval = ((int)now.reset);
		now.reset = 1;
#ifdef VAR_RANGES
		logval("reset", ((int)now.reset));
#endif
		;
		/* merge: goto start(1, 33, 1) */
		reached[1][33] = 1;
		;
		_m = 3; goto P999; /* 2 */
	case 29: /* STATE 35 - triangle_mcdc.pml:108 - [(1)] (56:0:0 - 1) */
		IfNotBlocked
		reached[1][35] = 1;
		if (!(1))
			continue;
		/* merge: .(goto)(0, 37, 56) */
		reached[1][37] = 1;
		;
		/* merge: .(goto)(0, 42, 56) */
		reached[1][42] = 1;
		;
		_m = 3; goto P999; /* 2 */
	case 30: /* STATE 43 - triangle_mcdc.pml:115 - [(!(main_c3))] (0:0:0 - 1) */
		IfNotBlocked
		reached[1][43] = 1;
		if (!( !(((int)now.main_c3))))
			continue;
		_m = 3; goto P999; /* 0 */
	case 31: /* STATE 44 - triangle_mcdc.pml:117 - [printf('Value of c is not in the range of permitted values ')] (0:51:1 - 1) */
		IfNotBlocked
		reached[1][44] = 1;
		Printf("Value of c is not in the range of permitted values ");
		/* merge: main_condition_31_copy = !(main_c3)(51, 45, 51) */
		reached[1][45] = 1;
		(trpt+1)->bup.oval = ((int)main_condition_31_copy);
		main_condition_31_copy =  !(((int)now.main_c3));
#ifdef VAR_RANGES
		logval("main_condition_31_copy", ((int)main_condition_31_copy));
#endif
		;
		_m = 3; goto P999; /* 1 */
	case 32: /* STATE 46 - triangle_mcdc.pml:121 - [((reset==0))] (1:0:1 - 1) */
		IfNotBlocked
		reached[1][46] = 1;
		if (!((((int)now.reset)==0)))
			continue;
		/* merge: reset = 1(1, 47, 1) */
		reached[1][47] = 1;
		(trpt+1)->bup.oval = ((int)now.reset);
		now.reset = 1;
#ifdef VAR_RANGES
		logval("reset", ((int)now.reset));
#endif
		;
		/* merge: goto start(1, 48, 1) */
		reached[1][48] = 1;
		;
		_m = 3; goto P999; /* 2 */
	case 33: /* STATE 50 - triangle_mcdc.pml:124 - [(1)] (60:0:0 - 1) */
		IfNotBlocked
		reached[1][50] = 1;
		if (!(1))
			continue;
		/* merge: .(goto)(0, 52, 60) */
		reached[1][52] = 1;
		;
		/* merge: .(goto)(0, 57, 60) */
		reached[1][57] = 1;
		;
		_m = 3; goto P999; /* 2 */
	case 34: /* STATE 58 - triangle_mcdc.pml:131 - [(!(!(((main_c1&&main_c2)&&main_c3))))] (0:0:0 - 1) */
		IfNotBlocked
		reached[1][58] = 1;
		if (!( !( !(((((int)now.main_c1)&&((int)now.main_c2))&&((int)now.main_c3))))))
			continue;
		_m = 3; goto P999; /* 0 */
	case 35: /* STATE 65 - triangle_mcdc.pml:134 - [printf('Side A is %d ',main_a)] (0:0:0 - 3) */
		IfNotBlocked
		reached[1][65] = 1;
		Printf("Side A is %d ", now.main_a);
		_m = 3; goto P999; /* 0 */
	case 36: /* STATE 66 - triangle_mcdc.pml:136 - [printf('Side B is %d ',main_b)] (0:0:0 - 1) */
		IfNotBlocked
		reached[1][66] = 1;
		Printf("Side B is %d ", now.main_b);
		_m = 3; goto P999; /* 0 */
	case 37: /* STATE 67 - triangle_mcdc.pml:138 - [printf('Side C is %d ',main_c)] (0:0:0 - 1) */
		IfNotBlocked
		reached[1][67] = 1;
		Printf("Side C is %d ", now.main_c);
		_m = 3; goto P999; /* 0 */
	case 38: /* STATE 68 - triangle_mcdc.pml:141 - [((((main_a<(main_b+main_c))&&(main_b<(main_a+main_c)))&&(main_c<(main_a+main_b))))] (0:0:0 - 1) */
		IfNotBlocked
		reached[1][68] = 1;
		if (!((((now.main_a<(now.main_b+now.main_c))&&(now.main_b<(now.main_a+now.main_c)))&&(now.main_c<(now.main_a+now.main_b)))))
			continue;
		_m = 3; goto P999; /* 0 */
	case 39: /* STATE 69 - triangle_mcdc.pml:143 - [main_isATriangle = 1] (0:78:4 - 1) */
		IfNotBlocked
		reached[1][69] = 1;
		(trpt+1)->bup.ovals = grab_ints(4);
		(trpt+1)->bup.ovals[0] = ((int)now.main_isATriangle);
		now.main_isATriangle = 1;
#ifdef VAR_RANGES
		logval("main_isATriangle", ((int)now.main_isATriangle));
#endif
		;
		/* merge: main_condition_41_copy = (main_a<(main_b+main_c))(78, 70, 78) */
		reached[1][70] = 1;
		(trpt+1)->bup.ovals[1] = ((int)main_condition_41_copy);
		main_condition_41_copy = (now.main_a<(now.main_b+now.main_c));
#ifdef VAR_RANGES
		logval("main_condition_41_copy", ((int)main_condition_41_copy));
#endif
		;
		/* merge: main_condition_42_copy = (main_b<(main_a+main_c))(78, 71, 78) */
		reached[1][71] = 1;
		(trpt+1)->bup.ovals[2] = ((int)main_condition_42_copy);
		main_condition_42_copy = (now.main_b<(now.main_a+now.main_c));
#ifdef VAR_RANGES
		logval("main_condition_42_copy", ((int)main_condition_42_copy));
#endif
		;
		/* merge: main_condition_43_copy = (main_c<(main_a+main_b))(78, 72, 78) */
		reached[1][72] = 1;
		(trpt+1)->bup.ovals[3] = ((int)main_condition_43_copy);
		main_condition_43_copy = (now.main_c<(now.main_a+now.main_b));
#ifdef VAR_RANGES
		logval("main_condition_43_copy", ((int)main_condition_43_copy));
#endif
		;
		_m = 3; goto P999; /* 3 */
	case 40: /* STATE 73 - triangle_mcdc.pml:148 - [((reset==0))] (1:0:1 - 1) */
		IfNotBlocked
		reached[1][73] = 1;
		if (!((((int)now.reset)==0)))
			continue;
		/* merge: reset = 1(1, 74, 1) */
		reached[1][74] = 1;
		(trpt+1)->bup.oval = ((int)now.reset);
		now.reset = 1;
#ifdef VAR_RANGES
		logval("reset", ((int)now.reset));
#endif
		;
		/* merge: goto start(1, 75, 1) */
		reached[1][75] = 1;
		;
		_m = 3; goto P999; /* 2 */
	case 41: /* STATE 77 - triangle_mcdc.pml:151 - [(1)] (108:0:0 - 1) */
		IfNotBlocked
		reached[1][77] = 1;
		if (!(1))
			continue;
		/* merge: .(goto)(0, 79, 108) */
		reached[1][79] = 1;
		;
		/* merge: .(goto)(0, 84, 108) */
		reached[1][84] = 1;
		;
		_m = 3; goto P999; /* 2 */
	case 42: /* STATE 82 - triangle_mcdc.pml:156 - [main_isATriangle = 0] (0:0:1 - 1) */
		IfNotBlocked
		reached[1][82] = 1;
		(trpt+1)->bup.oval = ((int)now.main_isATriangle);
		now.main_isATriangle = 0;
#ifdef VAR_RANGES
		logval("main_isATriangle", ((int)now.main_isATriangle));
#endif
		;
		_m = 3; goto P999; /* 0 */
	case 43: /* STATE 85 - triangle_mcdc.pml:159 - [(main_isATriangle)] (0:0:0 - 1) */
		IfNotBlocked
		reached[1][85] = 1;
		if (!(((int)now.main_isATriangle)))
			continue;
		_m = 3; goto P999; /* 0 */
	case 44: /* STATE 86 - triangle_mcdc.pml:162 - [(((main_a==main_b)&&(main_b==main_c)))] (103:0:1 - 1) */
		IfNotBlocked
		reached[1][86] = 1;
		if (!(((now.main_a==now.main_b)&&(now.main_b==now.main_c))))
			continue;
		/* merge: printf('Equilateral ')(103, 87, 103) */
		reached[1][87] = 1;
		Printf("Equilateral ");
		/* merge: .(goto)(103, 96, 103) */
		reached[1][96] = 1;
		;
		/* merge: main_condition_51_copy = main_isATriangle(103, 97, 103) */
		reached[1][97] = 1;
		(trpt+1)->bup.oval = ((int)main_condition_51_copy);
		main_condition_51_copy = ((int)now.main_isATriangle);
#ifdef VAR_RANGES
		logval("main_condition_51_copy", ((int)main_condition_51_copy));
#endif
		;
		_m = 3; goto P999; /* 3 */
	case 45: /* STATE 89 - triangle_mcdc.pml:167 - [((((main_a!=main_b)&&(main_b!=main_c))&&(main_a!=main_c)))] (103:0:1 - 1) */
		IfNotBlocked
		reached[1][89] = 1;
		if (!((((now.main_a!=now.main_b)&&(now.main_b!=now.main_c))&&(now.main_a!=now.main_c))))
			continue;
		/* merge: printf('Scalene ')(103, 90, 103) */
		reached[1][90] = 1;
		Printf("Scalene ");
		/* merge: .(goto)(103, 94, 103) */
		reached[1][94] = 1;
		;
		/* merge: .(goto)(103, 96, 103) */
		reached[1][96] = 1;
		;
		/* merge: main_condition_51_copy = main_isATriangle(103, 97, 103) */
		reached[1][97] = 1;
		(trpt+1)->bup.oval = ((int)main_condition_51_copy);
		main_condition_51_copy = ((int)now.main_isATriangle);
#ifdef VAR_RANGES
		logval("main_condition_51_copy", ((int)main_condition_51_copy));
#endif
		;
		_m = 3; goto P999; /* 4 */
	case 46: /* STATE 92 - triangle_mcdc.pml:171 - [printf('Isosceles ')] (0:103:1 - 1) */
		IfNotBlocked
		reached[1][92] = 1;
		Printf("Isosceles ");
		/* merge: .(goto)(103, 94, 103) */
		reached[1][94] = 1;
		;
		/* merge: .(goto)(103, 96, 103) */
		reached[1][96] = 1;
		;
		/* merge: main_condition_51_copy = main_isATriangle(103, 97, 103) */
		reached[1][97] = 1;
		(trpt+1)->bup.oval = ((int)main_condition_51_copy);
		main_condition_51_copy = ((int)now.main_isATriangle);
#ifdef VAR_RANGES
		logval("main_condition_51_copy", ((int)main_condition_51_copy));
#endif
		;
		_m = 3; goto P999; /* 3 */
	case 47: /* STATE 97 - triangle_mcdc.pml:175 - [main_condition_51_copy = main_isATriangle] (0:103:1 - 5) */
		IfNotBlocked
		reached[1][97] = 1;
		(trpt+1)->bup.oval = ((int)main_condition_51_copy);
		main_condition_51_copy = ((int)now.main_isATriangle);
#ifdef VAR_RANGES
		logval("main_condition_51_copy", ((int)main_condition_51_copy));
#endif
		;
		_m = 3; goto P999; /* 0 */
	case 48: /* STATE 98 - triangle_mcdc.pml:177 - [((reset==0))] (1:0:1 - 1) */
		IfNotBlocked
		reached[1][98] = 1;
		if (!((((int)now.reset)==0)))
			continue;
		/* merge: reset = 1(1, 99, 1) */
		reached[1][99] = 1;
		(trpt+1)->bup.oval = ((int)now.reset);
		now.reset = 1;
#ifdef VAR_RANGES
		logval("reset", ((int)now.reset));
#endif
		;
		/* merge: goto start(1, 100, 1) */
		reached[1][100] = 1;
		;
		_m = 3; goto P999; /* 2 */
	case 49: /* STATE 102 - triangle_mcdc.pml:180 - [(1)] (110:0:0 - 1) */
		IfNotBlocked
		reached[1][102] = 1;
		if (!(1))
			continue;
		/* merge: .(goto)(0, 104, 110) */
		reached[1][104] = 1;
		;
		/* merge: .(goto)(0, 109, 110) */
		reached[1][109] = 1;
		;
		_m = 3; goto P999; /* 2 */
	case 50: /* STATE 107 - triangle_mcdc.pml:185 - [printf('Not a Triangle ')] (0:0:0 - 1) */
		IfNotBlocked
		reached[1][107] = 1;
		Printf("Not a Triangle ");
		_m = 3; goto P999; /* 0 */
	case 51: /* STATE 110 - triangle_mcdc.pml:188 - [in_main!0] (0:0:0 - 3) */
		IfNotBlocked
		reached[1][110] = 1;
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
	case 52: /* STATE 112 - triangle_mcdc.pml:190 - [printf('End of main')] (0:0:0 - 2) */
		IfNotBlocked
		reached[1][112] = 1;
		Printf("End of main");
		_m = 3; goto P999; /* 0 */
	case 53: /* STATE 113 - triangle_mcdc.pml:191 - [-end-] (0:0:0 - 1) */
		IfNotBlocked
		reached[1][113] = 1;
		if (!delproc(1, II)) continue;
		_m = 3; goto P999; /* 0 */

		 /* PROC input */
	case 54: /* STATE 1 - triangle_mcdc.pml:5 - [((value<max))] (4:0:1 - 1) */
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
	case 55: /* STATE 7 - triangle_mcdc.pml:8 - [in_input!value] (0:0:0 - 1) */
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
	case 56: /* STATE 9 - triangle_mcdc.pml:10 - [-end-] (0:0:0 - 1) */
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

